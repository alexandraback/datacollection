import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.Formatter;
import java.util.Locale;

public class Pancakes {

	static StringBuilder sb = new StringBuilder();
	static Formatter buf = new Formatter(sb, Locale.US);
	static int T;
	static char[] S;
	
	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("B-large.in"));
		System.setOut(new PrintStream("B-large.out"));
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		T = Integer.parseInt(in.readLine());
		for (int c = 1; c <= T; c++) {
			S = in.readLine().toCharArray();
			buf.format("Case #%d: ", c);
			solve();
		}
		System.out.print(sb.toString());
	}
	
	static void solve(){
		char sign = '-';
		int c = 0;
		for (int i = S.length -1; i >=0; i--) {
			if (S[i]==sign){
				c++;
				if (sign=='-') sign='+';
				else sign='-';
			}
		}
		buf.format("%d\n", c);
	}	
}	