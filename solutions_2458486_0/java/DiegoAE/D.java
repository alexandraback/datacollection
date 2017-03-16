import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.StringTokenizer;
import java.util.TreeMap;


public class D {
	
	static class Scanner{
		BufferedReader br=null;
		StringTokenizer tk=null;
		public Scanner(){
			br=new BufferedReader(new InputStreamReader(System.in));
		}
		public String next() throws IOException{
			while(tk==null || !tk.hasMoreTokens()){
				String cad = br.readLine();
				if (cad == null)
					return null;
				tk=new StringTokenizer(cad);
			}
			return tk.nextToken();
		}
		public int nextInt() throws NumberFormatException, IOException{
			return Integer.valueOf(next());
		}
	}
	
	static Boolean[] dp;
	static int[] siguiente;
	static int[] initk;
	static int N;
	static LinkedList<Integer>[] chest;
	static int[] type;
	
	static boolean dp(int mask){
		if (dp[mask] != null)
			return dp[mask];
		if (Integer.bitCount(mask) == N)
			return true;
		int[] tmp = Arrays.copyOf(initk, initk.length);
		for(int i = 0; i < N; i++){
			if ( ((mask>>i) & 1) == 1){
				tmp[type[i]]--;
				for(int e: chest[i])
					tmp[e]++;
			}
		}
		for(int i = 0; i < N; i++){
			if ( ((mask>>i) & 1) == 0){
				if (tmp[type[i]]<=0)
					continue;
				boolean result = dp(mask | (1<<i));
				if (result){
					dp[mask] = true;
					siguiente[mask] = i;
					return true;
				}
			}
		}
		dp[mask] = false;
		return false;		
	}

	
	
	static TreeMap<Integer,Integer> map = new TreeMap<Integer,Integer>();
	static int index;
	
	static int get(int a){
		if (map.containsKey(a))
			return map.get(a);
		map.put(a, index);
		index++;
		return index - 1;
	}
	
	public static void main(String args[]) throws NumberFormatException, IOException{
		Scanner sc = new Scanner();
		int T = sc.nextInt();
		for(int c = 1; c <= T; c++){
			index = 0;
			map.clear();
			int KI = sc.nextInt();
			N = sc.nextInt();
			initk = new int[40];
			chest = new LinkedList[N];
			type = new int[N];
			dp = new Boolean[1 << N];
			siguiente = new int[1 << N];
			Arrays.fill(initk, 0);
			Arrays.fill(type, 0);
			Arrays.fill(siguiente, -1);
			for(int i = 0; i < N; i++)
				chest[i] = new LinkedList<Integer>();
			for(int i = 0; i < KI; i++){
				int aux = get(sc.nextInt());
				initk[aux]++;
			}
			for(int i = 0; i < N; i++){
				type[i] = get(sc.nextInt());
				int aux = sc.nextInt();
				for(int j = 0; j < aux; j++)
					chest[i].add(get(sc.nextInt()));
			}
			//
			System.out.printf("Case #%d:",c);
			if (dp(0)){
				int mactual = 0;
				for(int i = 0; i < N; i++){
					System.out.printf(" %d", siguiente[mactual] + 1);
					mactual = mactual | (1 << siguiente[mactual]);
				}
				System.out.printf("\n");
			}
			else
				System.out.printf(" IMPOSSIBLE\n");
			
		}
	}

}
