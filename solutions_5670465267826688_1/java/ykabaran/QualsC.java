package googlecodejam2015;

import java.io.BufferedReader;
import java.io.IOException;
import java.math.BigInteger;

/**
 *
 * @author YILDIZ KABARAN
 */
public class QualsC implements GoogleCodeJam2015.Problem {
  
  private static final String YES = "YES";
  private static final String NO = "NO";
  
  private boolean isPossible;
  private int length;
  private BigInteger repeat;
  private char[] numbers;

  @Override
  public void setup(BufferedReader input) throws IOException {
    String[] args = input.readLine().split(" ");
    length = Integer.parseInt(args[0]);
    repeat = new BigInteger(args[1]);
    
    numbers = input.readLine().toCharArray();
  }
  
  private boolean[] iCache;
  private boolean[] kCache;
  
  private void buildICache(){
    int quadLength = length * 4;
    iCache = new boolean[quadLength];
    ComplexNumber num = new ComplexNumber('1');
    for(int i=0; i<quadLength; ++i){
      num.append(numbers[i % length]);
      iCache[i] = num.sameAs('i');
    }
  }
  
  private void buildKCache(){
    int quadLength = length * 4;
    kCache = new boolean[quadLength];
    ComplexNumber num = new ComplexNumber('1');
    for(int i=quadLength - 1; i>=0; --i){
      num.prepend(numbers[i % length]);
      kCache[i] = num.sameAs('k');
    }
  }
  
  private ComplexNumber getCombined(){
    ComplexNumber num = new ComplexNumber('1');
    for(int i=0; i<length; ++i){
      num.append(numbers[i]);
    }
    return num;    
  }
  
  @Override
  public void solve() {
    isPossible = false;
    
    buildICache();
    buildKCache();
    ComplexNumber combined = getCombined();
    
    int quadLength = length * 4;
    int iEndIndex = quadLength;
    int kStartIndex = 0;
    boolean canMeet = false;
    boolean hasMet = false;
    if(repeat.compareTo(new BigInteger("4")) <= 0){
      int maxLength = length * repeat.intValue();
      if(maxLength < 3){
        return;
      }
      canMeet = true;
      hasMet = true;
      iEndIndex = maxLength - 2;
      kStartIndex = quadLength - maxLength + 2;
    } else if(repeat.compareTo(new BigInteger("8")) <= 0){
      canMeet = true;
      hasMet = false;
    }
    
    for(int i=0; i<iEndIndex; ++i){
      if(canMeet && !hasMet){
        int iRepeats = (i + 1) / length;
        if(repeat.subtract(new BigInteger(Integer.toString(iRepeats))).compareTo(new BigInteger("4")) <= 0){
          ++kStartIndex;
          hasMet = true;
        }
      }
      if(!iCache[i]){
        if(hasMet){
          ++kStartIndex;
        }
        continue;
      }
      
      ComplexNumber numJ = new ComplexNumber('1');
      
      if(hasMet){
        numJ.append(numbers[(i+1)%length]);
      } else {
        int iRepeats = (i + 1) / length;
        int usedRepeats = iRepeats + 1;
        BigInteger exp = repeat.subtract(new BigInteger(Integer.toString(usedRepeats)));
        
        for(int j=(i+1)%length; j<length; ++j){
          numJ.append(numbers[j]);
        }

        ComplexNumber middleRepeats = new ComplexNumber(combined);
        middleRepeats.exponentiate(exp);
        numJ.append(middleRepeats);

        for(int j=0; j<kStartIndex%length; ++j){
          numJ.append(numbers[j]);
        }
      }
        
      for(int k=kStartIndex; k<quadLength; ++k){
        if(kCache[k] && numJ.sameAs('j')){
          isPossible = true;
          return;
        }
        numJ.append(numbers[k%length]);
      }
      if(hasMet){
        ++kStartIndex;
      }
    }
  }

  @Override
  public String getSolution() {
    return isPossible ? YES : NO;
  }
  
  
  private static class ComplexNumber {
    private boolean isNegative;
    private char value;
    
    public ComplexNumber(char c){
      value = c;
      isNegative = false;
    }
    
    public ComplexNumber(ComplexNumber other){
      value = other.value;
      isNegative = other.isNegative;
    }
    
    public boolean sameAs(char c){
      return !isNegative && value == c;
    }
    
    public void exponentiate(BigInteger exp){
      BigInteger modulus = exp.mod(new BigInteger("4"));
      int intExp = modulus.intValue();
      switch(intExp){
        case 0:
          this.value = '1';
          this.isNegative = false;
          break;
        case 1:
          break;
        case 2:
          append(this.value, this.isNegative);
          break;
        case 3:
          char orgValue = this.value;
          boolean orgNegative = this.isNegative;
          append(orgValue, orgNegative);
          append(orgValue, orgNegative);  
      }
    }
    
    public void prepend(char c){
      char temp = this.value;
      this.value = c;
      append(temp);
    }
    
    public void append(char c){
      append(c, false);
    }
    
    public void append(ComplexNumber num){
      append(num.value, num.isNegative);
    }
    
    private void append(char c, boolean negative){
      // merge negatives
      this.isNegative = this.isNegative ^ negative;
      
      if(c == '1'){
        // multiply by 1 does nothing
        return;
      }
      
      if(this.value == '1'){
        // just take the other value
        this.value = c;
        return;
      }
      
      if(this.value == c){
        // neither value is 1, so result is -1
        this.isNegative = !this.isNegative;
        this.value = '1';
        return;
      }
      
      if(this.value == 'i'){
        if(c == 'j'){
          // i * j = k
          this.value = 'k';
        } else {
          // i * k = -j
          this.value = 'j';
          this.isNegative = !this.isNegative;
        }
      } else if(this.value == 'j'){
        if(c == 'i'){
          // j * i = -k
          this.value = 'k';
          this.isNegative = !this.isNegative;
        } else {
          // j * k = i
          this.value = 'i';
        }
      } else {
        if(c == 'i'){
          // k * i = j
          this.value = 'j';
        } else {
          // k * j = -i
          this.value = 'i';
          this.isNegative = !this.isNegative;
        }
      }
    }
  }
}
