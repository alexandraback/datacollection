import java.util.*;
import java.io.*;

public class Main{ 
  public static int index;
  public static void main(String[] args)throws Exception {
    InputReader in = new InputReader(System.in);
    PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
    int test = in.nextInt();
    for(int t = 1; t <= test; t++){
      pw.print("Case #"+t+":");
      int k = in.nextInt(), c = in.nextInt(), s = in.nextInt();
      if(c == 1 && s != k){
        pw.println(" IMPOSSIBLE");
      }
      else if(c == 1 && s == k){
        for(int i = 1; i <= k; i++){
          pw.print(" "+i);
        }
        pw.println();
      }
      else if( s < (k+1)/2){
        pw.println(" IMPOSSIBLE");
      }
      
      else{
        int sum = k/2 + 1;
        s = (k+1)/2;
        for(int i = 1; i <= s; i++){
          pw.print(" "+sum);
          sum += (k+1);
        }
        pw.println();
      }
    }
    pw.close();
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