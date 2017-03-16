import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class GCJ_2015_Qual_A {
	public static void main(String[] args) throws Exception {
      int cases = readInt();
      for(int t = 1; t <= cases; ++t) {
         int max = readInt();
         String shy = readString();

         int add = 0;
         int total = 0;
         for(int i = 0; i <= max; ++i) {
            add = Math.max(add, i-total);
            total += Character.getNumericValue(shy.charAt(i));
         }

         System.out.println("Case #"+t+": "+add);
      }
	}
	
	static BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st = new StringTokenizer("");
	static String readString() throws Exception {
		while(!st.hasMoreTokens())
			st = new StringTokenizer(stdin.readLine());
		return st.nextToken();
	}
	static int readInt() throws Exception {
		return Integer.parseInt(readString());
	}
}
