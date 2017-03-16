import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Formatter;
import java.util.Locale;
import java.util.StringTokenizer;

public class CoinJam {

	static final int BOUND = 100000;
	
	static StringBuilder sb = new StringBuilder();
	static Formatter buf = new Formatter(sb, Locale.US);
	static int T;
	static int N, J;
	static ArrayList<String> list = new ArrayList<String>();
	static ArrayList<String> proof = new ArrayList<String>();
	static BigInteger[] primes;
	
	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("C-small.in"));
		System.setOut(new PrintStream("C-small.out"));
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		T = Integer.parseInt(in.readLine());
		StringTokenizer st;
		getPrimes();
		for (int c = 1; c <= T; c++) {
			st = new StringTokenizer(in.readLine());
			N = Integer.parseInt(st.nextToken());
			J = Integer.parseInt(st.nextToken());
			buf.format("Case #%d:\n", c);
			solve();
		}
		System.out.print(sb.toString());
	}
	
	static void solve(){
		char[] S = new char[N];
		BigInteger bn; 
		S[0]='1'; S[N-1]='1';
		int c = 0, cc;
		while (c<J){
			for (int i = 1; i < S.length-1; i++) 
				S[i]=(Math.random()<.5)?'1':'0';
			String SS = new String(S);
			cc = 0;
			for (int i = 2; i <=10; i++) {
				bn = new BigInteger(SS, i);
				if (!bn.isProbablePrime(100)){
					cc++;
				}
			}
			if (cc==9 && !list.contains(SS) && probar(SS)){
				list.add(SS);
				buf.format(SS);
				for (String SSS:proof) buf.format(" " + SSS);
				buf.format("\n");
				c++;
			}
		}
	}
	
	static boolean probar(String SS){
		proof.clear();
		for (int i = 2; i <= 10; i++) {
			BigInteger bn = new BigInteger(SS, i);
			for (int j = 0; j < primes.length; j++) {
				if (bn.mod(primes[j]).equals(BigInteger.ZERO)){
					proof.add(primes[j].toString());
					j=primes.length;
				}
			}
			if (proof.size()<i-1) return false;
		}
		return true;
	}
	
	static void getPrimes() {
		ArrayList<Integer> res = new ArrayList<Integer>();
		boolean[] arr = new boolean[BOUND + 1];
        arr[0] = arr[1] = true;
        for (int i = 0; i < arr.length; i++)
            if (!arr[i]) {
                res.add(i);
                for (int j = 2 * i; j < arr.length; j += i) arr[j] = true;
            }
        primes = new BigInteger[res.size()];
        for (int i = 0; i < res.size(); i++) {
			primes[i] = new BigInteger(res.get(i)+"");
		}
	}

}	