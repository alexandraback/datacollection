import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.Formatter;
import java.util.Locale;

public class CountingSheep {

	static StringBuilder sb = new StringBuilder();
	static Formatter buf = new Formatter(sb, Locale.US);
	static int T;
	static long N;
	
	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("A-large.in"));
		System.setOut(new PrintStream("A-large.out"));
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		T = Integer.parseInt(in.readLine());
		for (int c = 1; c <= T; c++) {
			N = Long.parseLong(in.readLine());
			buf.format("Case #%d: ", c);
			solve();
		}
		System.out.print(sb.toString());
	}
	
	static void solve(){
		if (N==0){
			buf.format("INSOMNIA\n");
			return;
		}
		int c = 0;
		boolean[] v = new boolean[10];
		for (long K = 1; ; K++) {
			String S = ""+(N*K);
			char[] D = S.toCharArray();
			for (int i = 0; i < D.length; i++) v[D[i]-'0']=true;
			c = 0;
			for (int i = 0; i < 10; i++) if (v[i]) c++;
			if (c==10){
				buf.format(S+"\n");
				return;
			}
		}
	}
}	