// Author: Alejandro Sotelo Arevalo
package round1;

import java.io.*;
import java.math.*;

public class A_Bullseye {
  // --------------------------------------------------------------------------------
  private static String ID="A";
  private static String NAME="large";
  private static String STAGE="round1";
  private static boolean STANDARD_OUTPUT=false;
  // --------------------------------------------------------------------------------
  private static BufferedReader reader=null;
  private static PrintStream output=null;
  // --------------------------------------------------------------------------------
  public static void main(String[] args) throws Throwable {
    try (BufferedReader bufferedReader=reader=new BufferedReader(new FileReader(new File("data/"+STAGE+"/"+ID+"-"+NAME+".in")))) {
      try (PrintStream printStream=output=STANDARD_OUTPUT?System.out:new PrintStream(new File("data/"+STAGE+"/"+ID+"-"+NAME+".out"))) {
        process();
      }
    }
  }
  // --------------------------------------------------------------------------------
  private static void process() throws Throwable {
    for (int c=1,T=Integer.parseInt(reader.readLine()); c<=T; c++) {
      String line[]=reader.readLine().split(" ");
      BigInteger r=new BigInteger(line[0]),t=new BigInteger(line[1]);
      BigInteger va=BigInteger.valueOf(2);
      BigInteger vb=r.multiply(BigInteger.valueOf(2)).subtract(BigInteger.ONE);
      BigInteger vc=t.multiply(BigInteger.valueOf(-1));
      BigInteger vz=sqrt(vb.pow(2).subtract(va.multiply(vc).multiply(BigInteger.valueOf(4))));
      output.println("Case #"+c+": "+vz.subtract(vb).divide(va.multiply(BigInteger.valueOf(2))));
    }
  }
  private static BigInteger sqrt(BigInteger n) { // n^(1/2)
    for (BigInteger x=n,y;; x=y) {
      y=x.add(n.divide(x)).shiftRight(1);
      if (y.compareTo(x)>=0) return x;
    }
  }
}
