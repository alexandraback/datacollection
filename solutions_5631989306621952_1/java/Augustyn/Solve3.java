import java.io.*;
import java.util.*;
public class Solve3 {

  public static void main(String[] args) {
	MyScanner scanner = new MyScanner();
	PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
	int n = scanner.nextInt();
    for(int i = 0; i < n; i++) {
	  String s = scanner.nextLine();
	  String a = "";
	  for(int j = 0; j < s.length(); j++) {
	    if ((a + s.charAt(j)).compareTo(s.charAt(j) + a) >= 0)
		  a = a + s.charAt(j);
		else
		  a = s.charAt(j) + a;
	  }
	  out.println("Case #" + (i+1) + ": " + a);
	}
	out.close();
  }
  
  public static class MyScanner {
      BufferedReader br;
      StringTokenizer st;
 
      public MyScanner() {
         br = new BufferedReader(new InputStreamReader(System.in));
      }
 
      String next() {
          while (st == null || !st.hasMoreElements()) {
              try {
                  st = new StringTokenizer(br.readLine());
              } catch (IOException e) {
                  e.printStackTrace();
              }
          }
          return st.nextToken();
      }
 
      int nextInt() {
          return Integer.parseInt(next());
      }
 
      long nextLong() {
          return Long.parseLong(next());
      }
 
      double nextDouble() {
          return Double.parseDouble(next());
      }
 
      String nextLine(){
          String str = "";
	  try {
	     str = br.readLine();
	  } catch (IOException e) {
	     e.printStackTrace();
	  }
	  return str;
      }

   }
}
