import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.Collection;
import java.util.Collections;
import java.util.TreeMap;
import java.util.Vector;

class PalindromicSquares {
  private TreeMap<BigInteger, Integer> palindromeSquareMap;
  public PalindromicSquares() {
    this.palindromeSquareMap = new TreeMap<BigInteger, Integer>();
    this.generatePalindromicSquares();
	}
	
	private void generatePalindromicSquares() {
	  Vector<BigInteger> palindromeSquares = new Vector<BigInteger>();
	  palindromeSquares.add(new BigInteger("0"));
	  palindromeSquares.add(new BigInteger("1"));
	  palindromeSquares.add(new BigInteger("4"));
	  palindromeSquares.add(new BigInteger("9"));
	  
	  Vector<String> temp = new Vector<String>();
	  temp.add("0");
	  temp.add("1");
	  temp.add("2");
    
	  for (int noOfDigits = 3; noOfDigits < 53; noOfDigits += 2) {
	    int totalElements = temp.size();
	    for (int index = 0; index < totalElements; index++) {
	      String num = temp.elementAt(index);
	      String newNum = "1" + num + "1";
	      BigInteger b1 = new BigInteger(newNum);
	      BigInteger res = b1.multiply(b1);
	      if (this.isPalindrome(res.toString(10))) {
	        palindromeSquares.add(res);
	        temp.add(newNum);
	      }
	      temp.set(index, "0" + num + "0");
	      
	    }
	  }
	  
	  temp = new Vector<String>();
    temp.add("00");
    temp.add("11");
    temp.add("22");
    
    for (int index = 1; index < temp.size(); index++) {
      BigInteger b1 = new BigInteger(temp.elementAt(index));
      BigInteger res = b1.multiply(b1); 
      palindromeSquares.add(res);
    }
    
    for (int noOfDigits = 4; noOfDigits < 54; noOfDigits += 2) {
      int totalElements = temp.size();
      for (int index = 0; index < totalElements; index++) {
        String num = temp.elementAt(index);
        String newNum = "1" + num + "1";
        BigInteger b1 = new BigInteger(newNum);
        BigInteger res = b1.multiply(b1);
        if (this.isPalindrome(res.toString(10))) {
          palindromeSquares.add(res);
          temp.add(newNum);
        }
        temp.set(index, "0" + num + "0");
      }
    }
    
    temp = new Vector<String>();
    temp.add("0");
    temp.add("1");
    
    for (int noOfDigits = 3; noOfDigits < 53; noOfDigits += 2) {
      int totalElements = temp.size();
      for (int index = 0; index < totalElements; index++) {
        String num = temp.elementAt(index);
        String newNum = "2" + num + "2";
        BigInteger b1 = new BigInteger(newNum);
        BigInteger res = b1.multiply(b1);
        if (this.isPalindrome(res.toString(10))) {
          palindromeSquares.add(res);
        }
        temp.set(index, "0" + num + "0");
      }
    }
    
    temp = new Vector<String>();
    temp.add("00");
    
    for (int noOfDigits = 4; noOfDigits < 54; noOfDigits += 2) {
      int totalElements = temp.size();
      for (int index = 0; index < totalElements; index++) {
        String num = temp.elementAt(index);
        String newNum = "2" + num + "2";
        BigInteger b1 = new BigInteger(newNum);
        BigInteger res = b1.multiply(b1);
        if (this.isPalindrome(res.toString(10))) {
          palindromeSquares.add(res);
        }
        temp.set(index, "0" + num + "0");
      }
    }
    
    Collections.sort(palindromeSquares);
    for (int index = 0; index < palindromeSquares.size(); index++) {
      this.palindromeSquareMap.put(palindromeSquares.elementAt(index), new Integer(index));
    }
	}
	
	public int getLowerBound(BigInteger b1) {
	  return this.palindromeSquareMap.lowerEntry(b1).getValue().intValue();
	}
	
	private boolean isPalindrome(String st) {
	  for (int index = 0; index < st.length() / 2; index++) {
	    if (st.charAt(index) != st.charAt(st.length() - index - 1)) {
	      return false;
	    }
	  }
	  return true;
	}
}

public class Codejam3 {
	public static void main(String args[]) throws IOException {
		PalindromicSquares obj = new PalindromicSquares();
		
		InputStreamReader inputStreamReader = new InputStreamReader(System.in);
		BufferedReader bufferedReader = new BufferedReader(inputStreamReader);
		
		int testCases = Integer.parseInt(bufferedReader.readLine());
		
		for (int index = 1; index <= testCases; index++) {
		  String values[] = bufferedReader.readLine().split(" ");
		  BigInteger a = new BigInteger(values[0]);
		  BigInteger b = new BigInteger(values[1]);
		  b = b.add(new BigInteger("1"));
		  int res = obj.getLowerBound(b) - obj.getLowerBound(a);
		  System.out.println("Case #" + index + ": " + res);
		}
	}
}