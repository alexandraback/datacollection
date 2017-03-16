import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class C {
	static class Scanner{
		BufferedReader br=null;
		StringTokenizer tk=null;
		public Scanner(){
			br=new BufferedReader(new InputStreamReader(System.in));
		}
		public String next() throws IOException{
			while(tk==null || !tk.hasMoreTokens())
				tk=new StringTokenizer(br.readLine());
			return tk.nextToken();
		}
		public int nextInt() throws NumberFormatException, IOException{
			return Integer.valueOf(next());
		}
		public long nextLong() throws NumberFormatException, IOException{
			return Long.valueOf(next());
		}
		public double nextDouble() throws NumberFormatException, IOException{
			return Double.valueOf(next());
		}
	}
	
	static LinkedList<Long> fns = new  LinkedList<Long>();
	
	static boolean ispalindrome(long n){
		char[] s= (n+"").toCharArray();
		int i = 0;
		int j = s.length - 1;
		while(i < j){
			if (s[i] != s[j])
				return false;
			i++;
			j--;
		}
		return true;
	}
	
	static void init(){
		for(long i = 1; i <= 10000000L; i++){
			if (ispalindrome(i)){
				long sq = i * i;
				if (ispalindrome(sq))
					fns.add(sq);
			}
		}
		//System.out.println(fns);
	}
	
	public static void main(String args[]) throws NumberFormatException, IOException{
		Scanner sc = new Scanner();
		init();
		int T = sc.nextInt();
		for(int c = 1; c <= T; c++){
			long A =sc.nextLong();
			long B = sc.nextLong();
			int count = 0;
			for(long e: fns)
				if (e>=A && e<=B)
					count++;
			System.out.printf("Case #%d: %d\n",c,count);
		}
	}
}
