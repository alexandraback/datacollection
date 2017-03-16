import java.util.*;
import java.io.*;

public class C {
	static class Product {
		long amount;
		int type;
		
		Product(long a, int t) {amount = a; type=t;}
	}
	
	static class Solution {
		int i, j;
		long usedI, usedJ;
		
		public Solution(int i, int j, long usedI, long usedJ) {
			this.i=i; this.j=j; this.usedI = usedI; this.usedJ = usedJ;
		}
		
		public boolean equals(Object o) {
			Solution s = (Solution) o;
			return i==s.i && j==s.j&& usedI == s.usedI && usedJ == s.usedJ;
		}
		
		public int hashCode() {
			return (int)(i * 1000 + j + usedI + usedJ);
		}
	}
	
	public static int N, M;
	public static Product[] boxes, toys;
	public static HashMap<Solution, Long> map;
	
	public static long solve(int i, int j, long usedI, long usedJ) {	
		if (i >= N || j >=M) return 0;
		
		
		
		Solution s = new Solution(i, j, usedI, usedJ);
		if (map.containsKey(s)) return map.get(s);
		
		long ans = Math.max(solve(i+1,j,0,usedJ), solve(i, j+1, usedI, 0));
		
		if (toys[i].type == boxes[j].type) {
			long toy = toys[i].amount - usedI;
			long box = boxes[j].amount - usedJ;
			
			if (toy == box) {
				ans = Math.max(ans, toy + solve(i+1, j+1, 0,0));
			} else if (toy < box) {
				ans = Math.max(ans, toy + solve(i+1, j, 0, usedJ + toy));
			} else {
				ans = Math.max(ans, box + solve(i, j+1, usedI + box, 0));
			}
		}
		
		//System.out.println("Solve: "+i+" "+j+" "+usedI+" "+usedJ+": "+ans);
		if (usedI == 0 && usedJ == 0) {
			map.put(s, ans);
		}
		return ans;
	}
	
	public static void main(String[] args) throws Exception{
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		
		for(int caseNo = 1; caseNo <= T; caseNo++) {
			N = in.nextInt();
			M = in.nextInt();
			map = new HashMap<Solution, Long>();
			
			toys = new Product[N]; boxes = new Product[M];
			HashSet<Integer> types = new HashSet<Integer>();
						
			for(int i=0;i<N;i++) {
				toys[i] = new Product(in.nextLong(), in.nextInt());
				types.add(toys[i].type);
			}
			
			int cnt = 0;
			for(int i=0;i<M;i++) {
				long amnt = in.nextLong();
				int type = in.nextInt();
				
				if (types.contains(type)) {
					if (cnt - 1 >= 0 && boxes[cnt-1].type == type) {
						boxes[cnt-1].amount += amnt;
					} else {
						boxes[cnt++] = new Product(amnt, type);
					}
				}
			}
			M = cnt;
			
			System.out.println("Case #"+caseNo+": "+solve(0,0,0,0));
		}
	}
}