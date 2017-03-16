import java.util.*;
import java.io.*;

public class Main{ 
  public static int index;
  public static void main(String[] args)throws Exception {
    InputReader in = new InputReader(System.in);
    PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
    int test = in.nextInt();
    int [] a = new int[10];
    for(int t = 1; t <= test; t++){
      Arrays.fill(a, 0);
      int n = in.nextInt();
      
      if( n == 0){
        pw.println("Case #"+t+": INSOMNIA");
        continue;
      }
      
      int c = 1;
      while(!check(a)){
        putToArray(n*c+"", a);
        c++;
      }
      pw.println("Case #"+t+": "+((c-1)*n));

    }
    pw.close();
  }
  
  static void putToArray(String s, int a[]){
    int len = s.length();
    for(int i = 0; i < len; i++){
      a[s.charAt(i)-48]++;
    }
  }
  
  static boolean check(int a[]){
    int len = 10;
    for(int i = 0; i < len; i++){
      if(a[i] == 0) return false;
    }
    return true;
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