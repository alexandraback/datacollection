import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Asmall {
	
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
	
	static boolean isvowel(char a){
		return (a == 'a') || (a == 'e') || (a == 'i') || (a == 'o') || (a == 'u');
	}
	
	static boolean isconsonant(char a){
		return !isvowel(a);
	}
	
	static boolean test(char[] a, int left, int right,int N){
		
		int count = 0;
		for(int i = left; i <= right; i++){
			if (isvowel(a[i]))
				count = 0;
			else
				count++;
			if (count >= N)
				return true;
		}
		if (count >= N)
			return true;
		return false;
	}
	
	public static void main(String args[]) throws NumberFormatException, IOException{
		Scanner sc = new Scanner();
		int T = sc.nextInt();
		for(int c = 1; c <= T; c++){
			char[] a = sc.next().toCharArray();
			int N = sc.nextInt();
			int ans = 0;
			for(int i = 0; i < a.length; i++)
				for(int j = i; j < a.length; j++){
					if (test(a,i,j,N))
						ans++;
				}
			System.out.printf("Case #%d: %d\n",c,ans);
		}
	}

}
