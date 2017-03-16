import java.io.*;
import java.math.BigInteger;
import java.util.*;

import static java.lang.Math.*;
import static java.util.Arrays.*;

public class C {
	
  static BigInteger LIM = bigIntSqRootFloor(new BigInteger("111111111111"));
  static BigInteger TWO = new BigInteger("2");
  static BigInteger THREE = new BigInteger("3");
  
  static ArrayList<BigInteger> primes = new ArrayList<BigInteger>();
  
  
  public static void main(String[] args) throws IOException {
    String        pb        = "C";
    Scanner       sc        = new Scanner(System.in);
    PrintWriter   out       = new PrintWriter(new File(pb+".out"));
		StringBuilder resultat  = new StringBuilder("");
		long time = System.currentTimeMillis();
		
		primes.add(TWO);
	  primes.add(THREE);
	  boolean iPrime;
	  	
		BigInteger sqrti;
    for (BigInteger i = new BigInteger("5"); i.compareTo(LIM)<=0 ; i=i.add(TWO))
    {
      sqrti = bigIntSqRootFloor(i);
      iPrime = true;
      for (int j = 0; j < primes.size() && primes.get(j).compareTo(sqrti)<=0; j++)
      {
        if(i.mod(primes.get(j)).compareTo(BigInteger.ZERO)==0){
          iPrime = false;
          break;
        }
      }
      if(iPrime)
      {  
        primes.add(i);
        if(primes.size()%10000==0)
          System.out.println(i+" "+primes.size());
      }
    }

		
		
		//TEST CASES----------------------------------------------------
		int TC = sc.nextInt();
    for (int tc = 1; tc <= TC; tc++) {
      if(tc!=1) resultat.append("\n");
      resultat.append("Case #"+tc+":\n");
    
      //READ----------------------------------------------------
      int N = sc.nextInt();
      int J = sc.nextInt();
      
      long f = (new BigInteger("10000000000000000000000000000001",2)).longValue();
      long t = (new BigInteger("11111111111111111111111111111111",2)).longValue();
      
      ArrayList<String> goods = new ArrayList<String>();
      int countFound = 0;
      
      for (long i = f; i <= t && countFound<J; i=i+1)
      {
        
//        if(countFound%10==0)
//          System.out.println("CountFound : "+i+" "+countFound);
        
        boolean good=true;
        
        String binar = Long.toString(i, 2);
        if(!binar.endsWith("1"))
          continue;
        for (int radix = 2; radix <= 10; radix++)
        {
          BigInteger z = new BigInteger(binar,radix);
          if(primes.contains(z)){
            good=false;
            break;
          }
        }
        if(good){
          String resp = binar; 
          
          for (int radix = 2; radix <= 10; radix++)
          {
            BigInteger z = new BigInteger(binar,radix);
            BigInteger d = findDivisor(z);
            if(d==null){
              resp=null;
              break;
            }
            resp+=" "+d;
          }
          
          if(resp!=null){
            goods.add(resp);
            countFound++;
          }
        }
      }
            

      StringBuffer res = new StringBuffer();
      for(String g: goods){
        res.append("\n"+g);
      }
      
      
      
						
      //PRINT--------------------------------------------------
			System.out.println(res.toString().trim());
			resultat.append(res.toString().trim());
			System.out.println("Finished testcase " + tc + ", time = " + (System.currentTimeMillis() - time));
		}
		
    //CLOSE----------------------------------------------------
		out.print(resultat);
		out.close(); sc.close();
	}
  
  private static BigInteger findDivisor(BigInteger z)
  {
    for (int j = 0; j < primes.size() && primes.get(j).compareTo(z)<0 ; j++)
    {
      if(z.mod(primes.get(j)).equals(BigInteger.ZERO)){
        return primes.get(j);
      }
    }
    return null;
  }

  public static BigInteger bigIntSqRootFloor(BigInteger x)
      throws IllegalArgumentException {
  if (x.compareTo(BigInteger.ZERO) < 0) {
      throw new IllegalArgumentException("Negative argument.");
  }
  // square roots of 0 and 1 are trivial and
  // y == 0 will cause a divide-by-zero exception
  if (x .equals(BigInteger.ZERO) || x.equals(BigInteger.ONE)) {
      return x;
  } // end if
  BigInteger two = BigInteger.valueOf(2L);
  BigInteger y;
  // starting with y = x / 2 avoids magnitude issues with x squared
  for (y = x.divide(two);
          y.compareTo(x.divide(y)) > 0;
          y = ((x.divide(y)).add(y)).divide(two));
  return y;
  }
}