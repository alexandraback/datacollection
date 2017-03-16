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
		perm(12, 2, "", 1);
		//System.out.println(map.get(2L<<12));
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
				HashSet<String> possible = new HashSet<>();
				for(int i = 0; i<k; i++){
					long p = in.nextLong();
					if(!map.containsKey(p))
						continue;
					for(String j: map.get(p))
						if(j.length() <= n)
							possible.add(j);
				}
				//System.out.println(possible);
				String ans = "";
				loop: for(String i: possible){
					String tmp = ans;
					String nAns = ans;
					for(Character ch: i.toCharArray()){
						if((ch-'0') > m)
							continue loop;
						String v = ""+ch;
						if(tmp.contains(v))
							tmp = tmp.replaceFirst(v, ".");
						else nAns = nAns+v;
					}
					ans = nAns;
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
	int M = 8;
	HashMap<Long, Set<String>> map;
	void add(long i, String v){
		if(!map.containsKey(i))
			map.put(i, new HashSet<String>());
		map.get(i).add(v);
	}
	void perm(int i, int prev, String build, long p){
		if(i == 0) return;
		for(int j = prev; j<=M; j++){
			add(p*j, build+j);
			perm(i-1, j, build+j, p*j);
		}
	}
	public static void main(String[] args) throws FileNotFoundException {
		System.setIn(new FileInputStream(new File("good.in")));
		System.setOut(new PrintStream(new File("good.out")));
		new GoodLuck();
	}
}
