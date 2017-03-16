import java.util.*;
import java.io.*;

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
      ArrayList<Long> list = new ArrayList<Long>();
      long x = 1, y = n, z = 1;
      x = x << (n-1);
      y = z << n;
      for(long i = x+1; i <= y-1; i++){
        String s = Long.toString(i, 2);
        //System.err.println(s);
        if(s.charAt(n-1) != '1') continue;
        boolean bol = true;
        list.clear();
        for(int b = 2; b <= 10; b++){
          long p = Long.parseLong(s, b);
          long res = isPrime(p);
          if(res == -1){
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
  
  static long isPrime (long p){
    if ( p % 2 == 0 || p < 1 ) return 2;
    
    long len = (long) Math.sqrt (p * 1.0);
    
    for ( long i = 3; i <= len; i += 2 ) if ( p % i == 0 ) return i;
    return -1;
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