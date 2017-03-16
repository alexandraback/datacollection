import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class ProblemB {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	
	public static void main(String[] args) throws Exception {
		
		Scanner s  = new Scanner(System.in);
		
		int T = s.nextInt();
		
		for (int caseNum=1; caseNum<=T; caseNum++) {
			
			int N = s.nextInt();
			
			int[][] sol = new int[2*N-1][N];
			for (int i=0; i<2*N-1; i++) {
				for (int j=0; j<N; j++) {
					sol[i][j] = s.nextInt();
				}
			}
			
			int min = 500000;
			
			Map<Integer, List<int[]>> map = new HashMap<>();
			for (int i=0; i<2*N-1; i++) {
				if (!map.containsKey(sol[i][0]))
					map.put(sol[i][0],new LinkedList<int[]>());
				
				map.get(sol[i][0]).add(sol[i]);
				
				if (sol[i][0]<min) min = sol[i][0];
			}
			
			if (map.get(min).size()==1) {
				min = 100000;
				Map<Integer, List<int[]>> old = map;
				map = new HashMap<>();
				for (int x : old.keySet()) {
					for (int[] ar : old.get(x)) {
						int[] newAr = new int[N];
						for (int k = 0; k<N; k++) {
							newAr[N-k-1] = 50000 - ar[k];
						}
						if (!map.containsKey(newAr[0])) {
							map.put(newAr[0], new LinkedList<>());
						}
						map.get(newAr[0]).add(newAr);
						if (newAr[0] < min) min = newAr[0];
					}
					
				}
			}
			
			int[][] m = new int[N][N];
			
			int[] cur = map.get(min).get(0);
			
			for (int i=0; i<N; i++) {
				m[i][0] = cur[i];
			}

			map.get(min).remove(0);
			
			int res = begin(N, map, m,0);
			
			if (res==-1 && !map.get(min).isEmpty()) {
				map.get(min).add(cur);
				cur = map.get(min).get(0);
				for (int i=0; i<N; i++) {
					m[i][0] = cur[i];
				}
				
				map.get(min).remove(0);
				
				res = begin(N, map, m, 0);
			}
			
			
			System.out.printf("Case #%d:", caseNum);
			if (res==-1) System.out.println("AAAAAAA");
			else {
				if (m[0][res]<=2500) {
					for (int i=0; i<N; i++) {
						System.out.printf(" %d", m[i][res]);
					}
				} else {
					for (int i=0; i<N; i++) {
						System.out.printf(" %d", 50000-m[N-i-1][res]);
					}
				}
				System.out.println();
			}
		}
	}
	
	private static int begin(int N, Map<Integer, List<int[]>> map, int[][] m, int i) {
		
		int noMatchIndex = -1;
		if (i%7==6 || i==N) {
			for (int x=1; x<N; x++) {
				boolean match = true;
				if (!map.containsKey(m[0][x]) || map.get(m[0][x]).isEmpty()) {
					match = false;
				} else {
					for (int r=0; r<i; r++) {
						if (map.get(m[0][x]).get(0)[r]!=m[r][x]) {
							match = false;
							break;
						}
					}
					if (!match && map.get(m[0][x]).size()==2) {
						match = true;
						for (int r=0; r<5; r++) {
							if (map.get(m[0][x]).get(1)[r]!=m[r][x]) {
								match = false;
								break;
							}
						}
					}
				}
				if (!match && noMatchIndex==-1){
					noMatchIndex = x;
				}
				else if (!match && noMatchIndex!=-1){
					return -1;
				}
			}
		}
		
		if (i==N) {
			return noMatchIndex;
		}
		
		if (!map.containsKey((m[i][0])) || map.get(m[i][0]).isEmpty()) {
			return -1;
		}
		
		int[] cur = map.get(m[i][0]).get(0);
		
		for (int j=0; j<N; j++) {
			m[i][j] = cur[j];
		}
		
		map.get(m[i][0]).remove(0);
		
		int res = begin(N, map, m, i+1);
		
		if (res==-1 && !map.get(m[i][0]).isEmpty()) {
			map.get(m[i][0]).add(cur);
			cur = map.get(m[i][0]).get(0);
			for (int j=0; j<N; j++) {
				m[i][j] = cur[j];
			}
			
			map.get(m[i][0]).remove(0);
			
			res = begin(N, map, m, i+1);
		}
		
		map.get(m[i][0]).add(cur);
		
		return res;
		
	}

}
