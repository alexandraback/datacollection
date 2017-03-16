import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;


public class GoodLuck {
	GoodLuck(){
		map = new HashMap<>();
		int M = 5;
		for(int i = 2; i<=M; i++){
			add(i, i);
			for(int j = i; j<=M; j++){
				add(i*j, i*10+j);
				for(int k = j; k<=M; k++)
					add(i*j*k, i*100+j*10+k);
			}
		}
		Scanner in = new Scanner(System.in);
		int tests = in.nextInt();
		for(int te = 1; te<=tests; te++){
			System.out.println("Case #"+te+":");
			int r, n, m, k;
			r = in.nextInt();
			n = in.nextInt();
			m = in.nextInt();
			k = in.nextInt();
			for(int c = 0; c<r; c++){
				HashSet<Integer> possible = new HashSet<>();
				for(int i = 0; i<k; i++){
					int p = in.nextInt();
					if(!map.containsKey(p))
						continue;
					for(int j: map.get(p))
						if(j <= maxN[n])
							possible.add(j);
				}
				String ans = "";
				for(int i: possible){
					String tmp = ans;
					while(i!=0){
						String v = ""+(char)((i%10)+'0');
						if(tmp.contains(v))
							tmp = tmp.replaceFirst(v, ".");
						else ans = ans+v;
						i /= 10;
					}
				}
				if(ans.length() == 0)
					ans = "2";
				ans = ans.substring(0, Math.min(ans.length(), n));
				while(ans.length() != n)
					ans = ans + ans.charAt(0);
				System.out.println(ans);
			}
		}
	}
	int[] maxN = {0, 9, 99, 999};
	HashMap<Integer, Set<Integer>> map;
	void add(int i, int v){
		if(!map.containsKey(i))
			map.put(i, new HashSet<Integer>());
		map.get(i).add(v);
	}
	public static void main(String[] args) throws FileNotFoundException {
		System.setIn(new FileInputStream(new File("good.in")));
		System.setOut(new PrintStream(new File("good.out")));
		new GoodLuck();
	}
}
