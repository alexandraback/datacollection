package qualification;

import java.io.*;
import java.math.*;
import java.util.*;

public class C_FairAndSquare {
  // --------------------------------------------------------------------------------
  private static String ID="C";
  private static String NAME="large-1";
  private static String STAGE="qualification";
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
    BigInteger array[]=getNumbers();
    for (int c=1,T=Integer.parseInt(reader.readLine()); c<=T; c++) {
      String line[]=reader.readLine().trim().split(" +");
      BigInteger A=new BigInteger(line[0]),B=new BigInteger(line[1]).add(BigInteger.ONE);
      int indexA=Arrays.binarySearch(array,A);
      int indexB=Arrays.binarySearch(array,B);
      indexA=indexA>=0?indexA:-indexA-1;
      indexB=indexB>=0?indexB:-indexB-1;
      output.println("Case #"+c+": "+(indexB-indexA));
    }
  }
  private static BigInteger[] getNumbers() throws Throwable {
    File file=new File("C_FairAndSquare.txt");
    if (!file.exists()) generateFile(file);
    List<BigInteger> all=new ArrayList<>(1<<16);
    try (BufferedReader reader=new BufferedReader(new FileReader(file))) {
      for (String line; (line=reader.readLine())!=null;) {
        all.add(new BigInteger(line).pow(2));
      }
    }
    return all.toArray(new BigInteger[0]);
  }
  private static void generateFile(File file) throws Throwable {
    List<BigInteger> all=new ArrayList<>(1<<16);
    for (int i=0; i<4; i++) {
      check((""+i).toCharArray(),all);
    }
    for (int t=2; t<=50; t++) {
      int u=(t>>>1)-1,v=t>>>1;
      char array[]=new char[t];
      for (char mid:((t&1)==0?"?":"012").toCharArray()) {
        for (int x=0,xt=1<<u; x<xt; x++) {
          Arrays.fill(array,'0');
          array[0]=array[t-1]='1';
          if (mid!='?') array[v]=mid;
          for (int y=x,i=v-1,j=mid!='?'?v+1:v; y>0; y>>>=1,i--,j++) {
            array[j]=array[i]=(y&1)==1?'1':'0';
          }
          check(array,all);
        }
        Arrays.fill(array,'0');
        array[0]=array[t-1]='2';
        if (mid!='?') array[v]=mid;
        check(array,all);
      }
    }
    BigInteger[] array=all.toArray(new BigInteger[0]);
    Arrays.sort(array);
    try (BufferedWriter wri=new BufferedWriter(new FileWriter(file))) {
      for (BigInteger x:array)
        wri.write(x+"\r\n");
    }
  }
  // BigInteger::toString() is too slow for this purpose.
  private static void check(char[] array, List<BigInteger> all) {
    char[] p=pow(array);
    int i=0,j=p.length-1;
    while (i<j&&p[i]=='0') {
      i++;
    }
    for (; i<j; i++,j--) {
      if (p[i]!=p[j]) return;
    }
    all.add(new BigInteger(new String(array)));
  }
  private static char[] pow(char[] array) {
    int t=array.length,p=8,u=(t+p-1)/p,v=u<<1,digits[]=new int[u],mod=BigInteger.valueOf(10).pow(p).intValue();
    for (int i=t-1,k=u-1; i>=0; i-=p,k--) {
      int value=0;
      for (int j=Math.max(0,i-p+1); j<=i; j++) {
        value=value*10+array[j]-'0';
      }
      digits[k]=value;
    }
    long accum[]=new long[v],carry=0;
    for (int i=0; i<u; i++) {
      for (int j=0; j<u; j++) {
        accum[v-1-i-j]+=((long)digits[u-1-i])*digits[u-1-j];
      }
    }
    for (int i=v-1; i>=0; i--) {
      long value=accum[i]+carry;
      accum[i]=value%mod;
      carry=value/mod;
    }
    char[] result=new char[v*p];
    Arrays.fill(result,'0');
    for (int i=0; i<v; i++) {
      for (int j=(i+1)*p-1,value=(int)(accum[i]); value>0; value/=10,j--) {
        result[j]=(char)('0'+(value%10));
      }
    }
    return result;
  }
}
