import java.io.File;
import java.io.FileInputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Scanner;

/*
3
1 4
1
1 0
1 2 1 3
2 0
3 1 2
3 3
1 1 1
1 0
1 0
1 0
1 1
2
1 1 1

 */


public class D {
	D() throws Exception{
		System.setIn(new FileInputStream(new File("D-small-attempt0.in")));
		System.setOut(new PrintStream(new File("D-small.out")));
		Scanner in = new Scanner(System.in);
		int tests = in.nextInt();
		for(int t = 1; t<=tests; t++){
			int k;
			k = in.nextInt();
			n = in.nextInt();
			init = new ArrayList<>();
			for(int i = 0; i<k; i++)
				init.add(in.nextInt()-1);
			req = new int[n];
			prize = new ArrayList[n];
			for(int i = 0; i<n; i++){
				prize[i] = new ArrayList<Integer>();
				req[i] = in.nextInt()-1;
				int keys = in.nextInt();
				for(int j = 0; j<keys; j++)
					prize[i].add(in.nextInt()-1);
			}
			seen = new boolean[1<<n];
			best = new int[1<<n];
			boolean possible = go(0);
			System.out.printf("Case #%d: ", t);
			if(possible){
				int start = 0;
				StringBuilder ans = new StringBuilder("");
				while(start != ((1<<n)-1)){
					ans.append((best[start]+1) + " ");
					start |= (1<<best[start]);
				}
				System.out.println(ans.toString().trim());
			}else System.out.println("IMPOSSIBLE");
			
		}
	}
	ArrayList<Integer> init;
	ArrayList<Integer>[] prize;
	int[] req;
	boolean[] seen;
	int[] best;
	int n;
	boolean go(int mask){
		if(mask == ((1<<n)-1)) return true;
		if(seen[mask]) return false;
		seen[mask] = true;
		int[] keys = new int[200];
		for(int i = 0; i<n; i++)
			if((mask&(1<<i)) != 0){
				keys[req[i]]--;
				for(int j: prize[i])
					keys[j]++;
			}
		for(int i: init)
			keys[i]++;
		for(int i = 0; i<n; i++)
			if((mask&(1<<i)) == 0 && keys[req[i]] > 0){
				if(go(mask|(1<<i))){
					best[mask] = i;
					return true;
				}
			}
		best[mask] = -1;
		return false;
	}
	public static void main(String[] args) throws Exception{
		new D();
	}
}
