import java.util.*;
import java.io.*;

public class Main{ 
  public static int index;
  public static void main(String[] args)throws Exception {
    InputReader in = new InputReader(System.in);
    PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
    int test = in.nextInt();
    
    for(int t = 1; t <= test; t++){
     // Arrays.fill(a, 0);
      String s = in.next();
      int len = s.length();
      int [] a = new int[len];
      for(int i = 0; i< len; i++){
        if(s.charAt(i) == '+') a[i] = 1;
        else a[i] = 0;
      }
      int count = 0;
      for(int i = 0; i < len; i++){
        int idx = getDIffChar(a, i, len);
        if(idx == -1 && a[len-1] == 1) break;
        else if(idx == -1 && a[len-1] == 0){
          count++;
          flip(a, len, len);
        }
        else{
          count++;
          flip(a, idx, len);
        }
     //   System.err.println(count+" "+Arrays.toString(a));
      }
      pw.println("Case #"+t+": "+count);
    }
    
    pw.close();
  }
  static void flip(int[] a , int idx, int len){
    for(int i = 0; i < idx; i++){
      if(a[i] == 0) a[i] = 1;
      else a[i] = 0;
    }
  }
  
  static int getDIffChar(int[] a , int i, int len) {
    int temp = a[i++];
    for(; i < len; i++){
      if(a[i] != temp) return i;
    }
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