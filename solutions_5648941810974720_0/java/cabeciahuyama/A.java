import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.Formatter;
import java.util.Locale;

public class A {

	static StringBuilder sb = new StringBuilder();
	static Formatter buf = new Formatter(sb, Locale.US);
	static int T;
	static char[] s;
	
	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("A-small.in"));
		System.setOut(new PrintStream("A-small.out"));
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		T = Integer.parseInt(in.readLine());
		for (int c = 1; c <= T; c++) {
			s = in.readLine().toCharArray();
			buf.format("Case #%d: ", c);
			solve();
		}
		System.out.print(sb.toString());
	}

	static void solve(){
		int[] d = new int[10];
		d[0] = count('Z');
		del('Z', d[0]);	del('E', d[0]);	del('R', d[0]); del('O', d[0]);
		d[2] = count('W');
		del('T', d[2]);	del('W', d[2]);	del('O', d[2]);				
		d[4] = count('U');
		del('F', d[4]);	del('O', d[4]);	del('U', d[4]); del('R', d[4]);
		d[6] = count('X');
		del('S', d[6]);	del('I', d[6]);	del('X', d[6]);
		d[8] = count('G');
		del('E', d[8]);	del('I', d[8]);	del('G', d[8]); del('H', d[8]);	del('T', d[8]);
		
		d[3] = count('H');
		del('T', d[3]);	del('H', d[3]);	del('R', d[3]); del('E', d[3]);	del('E', d[3]);
		d[5] = count('F');
		del('F', d[5]);	del('I', d[5]);	del('V', d[5]); del('E', d[5]);	
		d[7] = count('S');
		del('S', d[7]);	del('E', d[7]);	del('V', d[7]); del('E', d[7]);	del('N', d[7]);	
		d[9] = count('I');
		del('N', d[9]);	del('I', d[9]);	del('N', d[9]); del('E', d[9]);		
		
		d[1] = count('O');
		
		StringBuilder num = new StringBuilder();
		for (int i = 0; i < d.length; i++) {
			for (int j = 0; j < d[i]; j++) {
				num.append((char)('0'+i));
			}
		}
		buf.format("%s", num.toString()+"\n");
	}
	
	static void del(char d, int n){
		for (int i = 0; n>0 && i < s.length; i++) {
			if (s[i]==d){
				s[i]='.';
				n--;
			}
		}
	}
	
	static int count(char d){
		int c = 0;
		for (int i = 0; i < s.length; i++) {
			if (s[i]==d) c++;
		}
		return c;	
	}
	
}


