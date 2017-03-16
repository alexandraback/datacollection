import java.util.*;
import java.io.*;
import java.math.*;

public class C{
	static HashMap<String, ArrayList<Integer>> map = new HashMap<String, ArrayList<Integer>>();
	static int N, M, K, R;
	
	static ArrayList<Integer> subset;
	static void generateSubset(String tmp, int idx, int cur) {
		if (idx == N) {
			subset.add(cur);
		} else {
			int val = (int)(tmp.charAt(idx)-'0');
			// not take
			generateSubset(tmp, idx+1, cur);
			// take
			generateSubset(tmp, idx+1, cur * val);
			
		}
	}
	
	static void generate(int idx, int num, String tmp) {
		if (idx == N) {
			subset = new ArrayList<Integer>();
			generateSubset(tmp, 0, 1);
			Collections.sort(subset);
			map.put(tmp, subset);
			//System.out.println(tmp+" "+subset);
		} else {
			while(num <= M) {
				generate(idx+1, num, tmp + num);
				++num;
			}
		}
	}
	
	public static void main(String[] args) throws Exception{
		Scanner in = new Scanner(System.in);
		
		int Tes = in.nextInt();
		
		for(int caseNo=1;caseNo<=Tes;caseNo++){
			R = in.nextInt();
			N = in.nextInt();
			M = in.nextInt();
			K = in.nextInt();
			
			System.out.println("Case #"+caseNo+":");
			
			generate(0, 2, "");
			
			for (int c=0;c<R;c++) {
				int[] sub = new int[K];
				for(int i=0;i<K;i++)sub[i]=in.nextInt();
				
				for(String key : map.keySet()) {
					boolean pos = true;
					ArrayList<Integer> list = map.get(key);
					for(int i=0;i<K;i++) {
						if (list.indexOf(sub[i]) < 0) {
							pos = false;
							break;
						}
					}
					
					if (pos) {
						System.out.println(key);
						break;
					}
				}
			}
		}
	}
}