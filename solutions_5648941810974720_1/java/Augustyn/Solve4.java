import java.io.*;
import java.util.*;
import java.math.*;
public class Solve4 {

  public static void main(String[] args) {
	MyScanner scanner = new MyScanner();
	PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
    int t = scanner.nextInt();
	for(int j = 0; j < t; j++) {
	  String s = scanner.nextLine();
	  char[] tab = new char[30];
	  //String [] nrs = {'ZERO', 'ONE', 'TWO', 'THREE', 'FOUR', 'FIVE', 'SIX', 'SEVEN', 'EIGHT', 'NINE'};
	  HashMap<Character, Integer> map = new HashMap<Character, Integer>();
	  for(int i = 0; i < 30; i ++)
	    map.put((char) ('A' + i), 0);
      for(int i = 0; i < s.length(); i++) {
	    char c = s.charAt(i);
	    map.put(c, map.get(c) + 1);
	  }
	  int[] values = new int[10];
	  if(map.get('Z') != null) {
	    int nr = map.get('Z');
	    values[0] = nr;
		map.put('Z', map.get('Z') - nr);
		map.put('E', map.get('E') - nr);
		map.put('R', map.get('R') - nr);
		map.put('O', map.get('O') - nr);
	  }
	  if(map.get('X') != null) {
	    int nr = map.get('X');
	    values[6]= nr;
		map.put('X', map.get('X') - nr);
		map.put('I', map.get('I') - nr);
		map.put('S', map.get('S') - nr);
	  }
	  if(map.get('S') != null) {
	    int nr = map.get('S');
	    values[7]= nr;
		map.put('S', map.get('S'));
		map.put('E', map.get('E') - 2 * nr);
		map.put('V', map.get('V') - nr);
		map.put('N', map.get('N') - nr);
	  }
	  if(map.get('V') != null && map.get('V') > 0) {
	    int nr = map.get('V');
	    values[5]= nr;
		map.put('F', map.get('F') - nr);
		map.put('V', map.get('V') - nr);
		map.put('I', map.get('I') - nr);
		map.put('E', map.get('E') - nr);
	  }
	  if(map.get('F') != null && map.get('F') > 0) {
	    int nr = map.get('F');
	    values[4]= nr;
		map.put('F', map.get('F') - nr);
		map.put('U', map.get('U') - nr);
		map.put('O', map.get('O') - nr);
		map.put('R', map.get('R') - nr);
	  }
	  if(map.get('R') != null && map.get('R') > 0) {
	    int nr = map.get('R');
	    values[3]= nr;
		map.put('T', map.get('T') - nr);
		map.put('R', map.get('R') - nr);
		map.put('H', map.get('H') - nr);
		map.put('E', map.get('E') - 2 * nr);
	  }
	  
	  if(map.get('W') != null && map.get('W') > 0) {
	    int nr = map.get('W');
	    values[2]= nr;
		map.put('W', map.get('W') - nr);
		map.put('T', map.get('T') - nr);
		map.put('O', map.get('O') - nr);
	  }

	  if(map.get('O') != null && map.get('O') > 0) {
	    int nr = map.get('O');
	    values[1]= nr;
		map.put('O', map.get('O') - nr);
		map.put('E', map.get('E') - nr);
		map.put('N', map.get('N') - nr);
	  }
	  
	  if(map.get('G') != null && map.get('G') > 0) {
	    int nr = map.get('G');
	    values[8]= nr;
	  }
	  if(map.get('N') != null && map.get('N') > 0) {
	    int nr = map.get('N')/2;
	    values[9]= nr;
	  }
	  out.print("Case #" + (j + 1)+ ": ");
	  for(int i = 0; i < 10; i++){
	    while(values[i] > 0) {
		  out.print(i);
		  values[i]--;
		}
	  }
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
