import java.io.*;
import java.util.*;
import java.math.*;
public class Solve4 {

  static String bestA = "";
  static String bestB = "";
  static long diff = Long.MAX_VALUE;
  static long A = Long.MAX_VALUE;
  static long B = Long.MAX_VALUE;
  static String a;
  static String b;
  public static void test(String strA, String strB) {
      long sA = Long.valueOf(strA);
	  long sB = Long.valueOf(strB);
  	  boolean isbetter = diff > Math.max(sA, sB) - Math.min(sA, sB);
	  boolean isEqual = diff == Math.max(sA, sB) - Math.min(sA, sB);
	  if(isbetter || 
	    (isEqual && sA < A) || (isEqual && sA == A && sB < B)) {
	    diff = Math.max(sA, sB) - Math.min(sA, sB);
		bestA = strA;
		bestB = strB;
		A = sA;
		B = sB;
	  }
  }
  public static String minString(String s, int nr) {
    if (nr == s.length()) {
	  return "";
	}
	if(s.charAt(nr) == '?') {
	  return '0' + minString(s, nr + 1);
	} else {
	  return s.charAt(nr) + minString(s, nr + 1);
	}
  }
  public static String maxString(String s, int nr) {
    if (nr == s.length()) {
	  return "";
	}
	if(s.charAt(nr) == '?') {
	  return '9' + maxString(s, nr + 1);
	} else {
	  return s.charAt(nr) + maxString(s, nr + 1);
	}
  }
  public static void solve(String strA, String strB, int nr) {
    if(nr == a.length()) {
		test(strA, strB);
	} else {
	  char c1 = a.charAt(nr);
	  char c2 = b.charAt(nr);
	  String minA = minString(a, nr + 1);
	  String minB = minString(b, nr + 1);
	  String maxA = maxString(a, nr + 1);
	  String maxB = maxString(b, nr + 1);
	  if(c1 == '?') {
	    if(c2 == '?') {
		  solve(strA + '0', strB + '0', nr + 1);
		  test(strA + '1' + minA, strB + '0' + maxB); 
		  test(strA + '0' + maxA, strB + '1' + minB); 
		} else {
		  solve(strA + c2, strB + c2, nr + 1);
		  if(c2 != '9')
		    test(strA + ((char)(c2+1)) + minA, strB + c2 + maxB); 
		  if(c2 != '0')
		    test(strA + ((char)(c2-1)) + maxA, strB + c2 + minB); 
		}
	  } else {
	    if(c2 == '?') {
		  solve(strA + c1, strB + c1, nr + 1);
		  if(c1 != '9')
		    test(strA + c1 + maxA, strB + ((char)(c1+1)) + minB); 
	  
		  if(c1 != '0')
		    test(strA + c1 + minA, strB + ((char)(c1-1)) + maxB); 
		} else {
		  if(c1 == c2) {
		    solve(strA + c1, strB + c2, nr + 1);
		  } else {
		    test(strA + c1 + minA, strB + c2 + maxB); 
		    test(strA + c1 + maxA, strB + c2 + minB); 
		  }
		}
	  }
	}
  }
  public static void main(String[] args) {
	MyScanner scanner = new MyScanner();
	PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
    int t = scanner.nextInt();
	for(int j = 0; j < t; j++) {
      String s = scanner.nextLine();
	  String [] tab = s.split(" ");
	  a = tab[0];
	  b = tab[1];
	  
	  bestA = "";
      bestB = "";
      diff = Long.MAX_VALUE;
      A = 0;
      B = 0;
      solve("", "", 0);
	  out.print("Case #" + (j + 1)+ ": " + bestA + " " + bestB);
	  out.println();
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
