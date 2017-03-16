import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.Stack;


public class BoredTSP {

	public static void main(String[] args) throws Exception{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int T =Integer.parseInt(in.readLine());
		for (int caso = 1; caso <=T; caso++) {
			String[] l = in.readLine().split(" ");
			int N = Integer.parseInt(l[0]);
			int M = Integer.parseInt(l[1]);
			String[] zip = new String[N+1];
			for (int i = 1; i <= N; i++) {
				zip[i] = in.readLine();
			}
			boolean[][] mat = new boolean[N+1][N+1];
			for (int i = 0; i < M; i++) {
				String[] s =  in.readLine().split(" ");
				int n1 = Integer.parseInt(s[0]);
				int n2 = Integer.parseInt(s[1]);
				mat[n1][n2]=true;
				mat[n2][n1]=true;
			}
			int[] perm = new int[N];
			for (int i = 0; i < N; i++) {
				perm[i]=i+1;
			}
			BigInteger ans = new BigInteger("99999999999999999999999999999999999999999999999999");
			while(true)
			{
				String act ="";
				for (int i = 0; i < N; i++) {
					act=act+zip[perm[i]];
				}
				boolean perdi = false;
				Stack<Integer> ret = new Stack<Integer>();
				ret.push(perm[0]);
				for (int i = 1; i < N && !perdi; i++) {
					if(mat[perm[i-1]][perm[i]])
					{
						ret.push(perm[i]);
					}
					else
					{
						while(!ret.isEmpty())
						{
							int retor = ret.pop().intValue();
							if(mat[retor][perm[i]])
							{
								ret.push(retor);
								ret.push(perm[i]);
								break;
							}
						}
						if(ret.isEmpty())
							perdi=true;
					}
				}
				if(!perdi)
				{
					BigInteger cur = new BigInteger(act);
					ans = ans.min(cur);
				}
				if(!next_permutation(perm))
					break;
			}
			System.out.println("Case #"+caso+": "+ans);
		}
	}
	
	static boolean next_permutation(int[] p) {
		  for (int a = p.length - 2; a >= 0; --a)
		    if (p[a] < p[a + 1])
		      for (int b = p.length - 1;; --b)
		        if (p[b] > p[a]) {
		          int t = p[a];
		          p[a] = p[b];
		          p[b] = t;
		          for (++a, b = p.length - 1; a < b; ++a, --b) {
		            t = p[a];
		            p[a] = p[b];
		            p[b] = t;
		          }
		          return true;
		        }
		  return false;
		}

}
