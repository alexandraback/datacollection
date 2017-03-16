package codejam2014.round1B;

import java.io.BufferedReader;
import java.io.IOException;
import java.math.BigInteger;

public class B extends Round1B {
  
  public B(String inputName) {
    super(inputName);
  }
  
  private int A, B, K;
  
  @Override
  protected void setupCase(BufferedReader br) throws IOException { 
    String line = br.readLine();
    String[] splitted = line.split(" ");
        
    A = Integer.parseInt(splitted[0]);
    B = Integer.parseInt(splitted[1]);
    K = Integer.parseInt(splitted[2]);
  }
  
  private static int getWinningLotteryNumber(int first, int second){
    return first & second;
  }
  
  @Override
  protected String getCaseSolution() {
    int result = 0;
    
    for(int i=0; i<A; ++i){
      for(int j=0; j<B; ++j){
        int winning = getWinningLotteryNumber(i, j);
        if(winning<K){
          ++result;
        }
      }
    }
    
    return Integer.toString(result);
  }
}
