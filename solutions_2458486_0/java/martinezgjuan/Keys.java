import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;


public class Keys {

	static int[] can;
	static int[] nextOpen;
	static int[] lock;
	static int[][] keysIn;
	static int[] iniKeys;
	static int n;
	
	static int dp(int x){
		if(can[x]!=-1){
			return can[x];
		}
		
		boolean allOpened = true;
		
		for(int i =0; i<n; i++){
			boolean isClosed = (x&(1<<i))==0;
			
			if(isClosed)
				allOpened = false;
			
			if (isClosed && canOpen(i,x) ){ // Is closed
				if(dp(x | 1<<i) == 1){
					can[x] = 1;
					nextOpen[x] = i;
					return can[x];
				}
			}
		}
		
		if(allOpened) {
			can[x] = 1;
		} else {
			can[x] = -2;
		}
		
		return can[x];
	}
	
	
	
	static boolean canOpen(int chest, int conf){
		
		int needed = lock[chest];
		int keysAv = iniKeys[needed];
				
		for(int i =0; i<n; i++){
			if ((conf&(1<<i))!=0){ // Is open
				if(lock[i]==needed){ // Subtract the lock if the same key
					keysAv--;
				}
				keysAv+=keysIn[i][needed]; // Add the keys needed from the chest
			}
		}
		
		if (keysAv>0) 
			return true;
		else 
			return false;
	}
	
	static int[] build(){
		
		int mask = 0;
		
		int[] res = new int[n];
		
		for(int i=0; i<n; i++){
			res[i] = nextOpen[mask];
			mask |= 1<<nextOpen[mask];
		}
		
		return res;
	}
	
	public static void main(String[] args) {
		FastScanner sc = new FastScanner(System.in);
		
		int cases = sc.nextInt();
		
		for(int c = 0; c<cases; c++){
			
			int k = sc.nextInt();
			n = sc.nextInt();
			
			iniKeys  = new int[201];
			for(int i=0; i<k; i++){
				iniKeys[sc.nextInt()-1]++;
			}
			
			lock = new int[n];
			keysIn = new int[n][201];
			
			for(int i=0; i<n; i++){
				lock[i] = sc.nextInt()-1;
				int in = sc.nextInt();
				for(int j=0; j<in; j++){
					keysIn[i][sc.nextInt()-1]++;
				}
			}
			
			can = new int[1<<n];
			nextOpen = new int[1<<n];
			Arrays.fill(can, -1);
			Arrays.fill(nextOpen, -1);
			
				
			if(dp(0)==1){
				int res[] = build();
				String r = "";
				
				for (int i = 0; i < n; i++) {
					if (i != 0)
						r+=" ";
					r+=(res[i]+1);
				}
				
				System.out.printf("Case #%d: %s\n", c+1,r);
			} else{
				System.out.printf("Case #%d: IMPOSSIBLE\n", c+1);
			}
			
		}

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
