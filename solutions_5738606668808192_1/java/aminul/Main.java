import java.util.*;
import java.io.*;
import java.math.*;
public class Main{ 
  public static int index;
  public static void main(String[] args)throws Exception {
    InputReader in = new InputReader(System.in);
    PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
    int test = in.nextInt();
    for(int t = 1; t <= test; t++){
      pw.println("Case #"+t+":");
      int n = in.nextInt(), j = in.nextInt();
      int count = 0;
      ArrayList<BigInteger> list = new ArrayList<BigInteger>();
      long x = 1, y = n, z = 1;
      x = x << (n-1);
      y = z << n;
      for(long i = x+1; i <= y-1; i++){
        String s = Long.toString(i, 2);
        if(s.charAt(n-1) != '1') continue;
        boolean bol = true;
        list.clear();
        BigInteger str = new BigInteger(s);
        for(int b = 2; b <= 10; b++){
          
          BigInteger p = new BigInteger(s, b);
          //if(s.equals("1000000000000001")) System.err.println(p);
          BigInteger res = isBigPrime(p);
          if(res.equals(new BigInteger("-1"))){
            bol = false;
            break;
          }
          else{
            list.add(res);
          }
        }
        int size = list.size();
        if(bol && size == 9){
          count++;
          pw.print(s);
          for(int m = 0; m< size; m++){
            pw.print(" "+list.get(m));
          }
          pw.println();
        }
        if(count >= j) break;
      }
    }
    pw.close();
  }
  
  public static BigInteger isBigPrime(BigInteger number) {
//    if (!number.isProbablePrime(5))
//        return false;

    BigInteger two = new BigInteger("2");
    if (!two.equals(number) && BigInteger.ZERO.equals(number.mod(two)))
        return two;
    BigInteger big19 = new BigInteger("20");
    for (BigInteger i = new BigInteger("3"); i.compareTo(big19) < 1; i = i.add(two)) {
        if (BigInteger.ZERO.equals(number.mod(i)))
            return i;
    }
    return new BigInteger("-1");
}  
  
  
  static class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;
    
    public InputReader(InputStream stream) {
      reader = new BufferedReader(new InputStreamReader(stream));
      tokenizer = null;
    }
    
    public String next() {
      
      try {
        while (tokenizer == null || !tokenizer.hasMoreTokens())
          tokenizer = new StringTokenizer(reader.readLine());
      } catch (IOException e) {
        return null;
      }
      
      return tokenizer.nextToken();
    }
    
    public String nextLine() {
      String line = null;
      try {
        tokenizer = null;
        line =  reader.readLine();
      } catch (IOException e) {
        throw new RuntimeException(e);
      }
      return line;
    }
    
    public int nextInt() {
      return Integer.parseInt(next());
    }
    
    public double nextDouble() {
      return Double.parseDouble(next());
    }
    
    public long nextLong() {
      return Long.parseLong(next());
    }
    public boolean hasNext(){
      try {
        while (tokenizer == null || !tokenizer.hasMoreTokens())
          tokenizer = new StringTokenizer(reader.readLine());
      } 
      catch (Exception e) {
        return false;
      }
      
      return true; 
      
    }
  }
}