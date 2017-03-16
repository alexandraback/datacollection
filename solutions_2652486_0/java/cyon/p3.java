
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Set;
import java.util.StringTokenizer;

public class p3 {

	private static void debug(Object... args) {
		System.out.println(Arrays.deepToString(args));
	}

	private static final Map<List<Integer>, List<String>> mp = new HashMap<List<Integer>, List<String>>();
	
	private static String solve(BufferedReader br) throws Exception {
		StringBuilder sb=new StringBuilder("\n");
		StringTokenizer st = new StringTokenizer(br.readLine());
		int r=Integer.parseInt(st.nextToken());
		int n=Integer.parseInt(st.nextToken());
		int m=Integer.parseInt(st.nextToken());
		int k=Integer.parseInt(st.nextToken());
		prep(n,m,k);
		for(int i=0;i<r;i++) {
			st = new StringTokenizer(br.readLine());
			List<Integer> li = new ArrayList<Integer>();
			for(int j=0;j<k;j++) {
				li.add(Integer.parseInt(st.nextToken()));
			}
			Collections.sort(li);
			List<String> best = null;
			int bm = 0;
			for(Entry<List<Integer>, List<String>> e : mp.entrySet()) {
				int p1=0;
				int p2=0;
				int ma=0;
				while(p1 < e.getKey().size() && p2 < k) {
					if(e.getKey().get(p1).equals(li.get(p2))) {
						ma++;
						p1++;
						p2++;
					}
					else if(e.getKey().get(p1).compareTo(li.get(p2)) > 0) {
						p2++;
					}
					else {
						p1++;
					}
				}
				//debug(e.getKey(),li,ma,bm,best,e.getValue());
				if(ma > bm) {
					bm = ma;
					best = e.getValue();
				}
			}
			//debug(bm,best);
			sb.append(best.get((int)(Math.random()*best.size())));
			sb.append("\n");
		}
		sb.deleteCharAt(sb.length()-1);
		return sb.toString();
	}

	private static void prep(int n, int m,int k) {
		
		Set<List<Integer>> all = new HashSet<List<Integer>>();
		Set<Set<Integer>> subs = new HashSet<Set<Integer>>();
		
		for(int i=2;i<=m;i++) {
			for(int j=2;j<=m;j++) {
				for(int l=2;l<=m;l++) {
					List<Integer> li = new ArrayList<Integer>();
					li.add(i);
					li.add(j);
					li.add(l);
					all.add(li);
				}
			}
		}
		for(int i=2;i<=4;i++) {
			for(int j=2;j<=4;j++) {
				for(int l=2;l<=4;l++) {
					Set<Integer> s = new HashSet<Integer>();
					s.add(i-2);
					s.add(j-2);
					s.add(l-2);
					subs.add(s);
				}
			}
		}		
		subs.add(new HashSet<Integer>());
		//debug(subs);
		for (List<Integer> comb : all) {
			List<Integer> prods = new ArrayList<Integer>();
			for (Set<Integer> ss : subs) {
				int p = 1;
				for (Integer id : ss) {
					p *= comb.get(id);
				}
				prods.add(p);
			}
			Collections.sort(prods);
			StringBuilder combs = new StringBuilder();
			for(Integer cc : comb) {
				combs.append(cc);
			}
			if(mp.get(prods) == null) {
				mp.put(prods, new ArrayList<String>());
			}
			mp.get(prods).add(combs.toString());
		}
		//debug(mp);
	}



	public static void main(String[] rags) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out, true);
		int t = Integer.parseInt(br.readLine());
		for (int i = 1; i <= t; i++) {
			pw.println("Case #" + i + ": " + solve(br));
		}
	}
}
