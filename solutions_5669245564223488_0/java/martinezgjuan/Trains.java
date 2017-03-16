import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Trains {

	static final long mod = 1000000007L;
	
	public static boolean same(String s){
		if(s.length()<=1) return true;
		for(int i=1; i<s.length(); i++) 
			if(s.charAt(i)!=s.charAt(i-1))return false;
		return true;
	}
	
	public static long factorial(int n, long mod) {
		long result = 1;
		for (int i = 2; i <= n; i++)
			result = (result% mod * i % mod)%mod;
		return result % mod;
	}
	
	public static void main(String[] args) {
		FastScanner sc = new FastScanner(System.in);
		int cases = sc.nextInt();
		PrintWriter out = new PrintWriter(System.out);

		for(int cas = 1; cas<=cases; cas++){
			int n = sc.nextInt();
			String[] t = new String[n];
			for(int i=0; i<n; i++) t[i] = sc.next();
			Arrays.sort(t);
			
			long total = 1;
			
			ArrayList<String> fixed = new ArrayList<String>();
			
			long act = 1;
			String aux = t[0];
			
			for(int i=1; i<t.length; i++){
				if(t[i-1].charAt(0)==t[i].charAt(0) && same(t[i-1]) && same(t[i])){
					act++;
					aux+=t[i];
				} else {
					total = ((total%mod)*factorial((int)act, mod))%mod;
					fixed.add(new String(aux));
					aux = t[i];  
					act = 1;
				}
			}
			total = ((total%mod)*factorial((int)act, mod))%mod;
			if(aux.length()>0) fixed.add(new String(aux));
			
			ArrayList<String> last = new ArrayList<String>();
			
			
			while(true){
				int sizeA = fixed.size();
				last.add(fixed.get(0));

				for(int i=1; i<fixed.size(); i++){
					boolean added = false;
					for(int j=0; j<last.size(); j++){
						if(fixed.get(i).charAt(0) == last.get(j).charAt(last.get(j).length()-1)){
							last.set(j, last.get(j)+fixed.get(i));
							added = true;
							break;
						} else if (fixed.get(i).charAt(fixed.get(i).length()-1) == last.get(j).charAt(0)){
							last.set(j, fixed.get(i)+last.get(j));
							added = true;
							break;
						}
					}
					if(!added) last.add(fixed.get(i));
				}
				
				if( last.size()== sizeA){
					break;
				} else {
					fixed = last;
					last = new ArrayList<String>();
				}
			}
			
			
			StringBuilder sb = new StringBuilder();
			for(int i=0; i<last.size(); i++) sb.append(last.get(i));
			String all = sb.toString();
			boolean bad = false;
			
			int[] chars = new int[26];
			chars[all.charAt(0)-'a']++;
			
			for(int i=1; i<all.length(); i++){
				if(all.charAt(i)!=all.charAt(i-1)){
					if(chars[all.charAt(i)-'a']>0){
						bad = true;
						break;
					}
					chars[all.charAt(i)-'a']++;
				}
			}
			
			if (bad) {
				out.printf("Case #%d: 0\n",cas);
				continue;
			}
			
			int groups = last.size();			
						
			long num = factorial(groups, mod);
			long res = ((total%mod) * (num%mod))%mod;
			
			out.printf("Case #%d: %d\n",cas, res);
			
						
			
			
		}
		out.flush();
		out.close();
	}

	static class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		public FastScanner(InputStream f) {
			br = new BufferedReader(new InputStreamReader(f));
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
				String s = null;
				try {
					s = br.readLine();
				} catch (IOException e) {
					e.printStackTrace();
				}
				if (s == null)
					return null;
				st = new StringTokenizer(s);
			}
			return st.nextToken();
		}

		boolean hasMoreTokens() {
			while (st == null || !st.hasMoreTokens()) {
				String s = null;
				try {
					s = br.readLine();
				} catch (IOException e) {
					e.printStackTrace();
				}
				if (s == null)
					return false;
				st = new StringTokenizer(s);
			}
			return true;
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble(){
			return Double.parseDouble(next());
		}
	}

}
