package contest;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class KingdomRush {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		
		try { 
			int T = Integer.parseInt(in.readLine());
			for (int tc = 0; tc<T; tc++) {
				
				int N = Integer.parseInt(in.readLine());
				
				int []l1 = new int[N]; 
				int []l2 = new int[N];
				
				for (int i=0;i<N;i++) { 
					StringTokenizer st = new StringTokenizer(in.readLine());
					l1[i] = Integer.parseInt(st.nextToken());
					l2[i] = Integer.parseInt(st.nextToken());
				}
				
				State s = new State(l1,l2); 
				boolean failed = false;
				while (!s.isDone()) { 
					if (s.doL2()) continue; 
					if (s.doL1()==false) {
						failed = true;
						break;
					}
				}
				
				if (failed) { 
					System.out.println("Case #"+(tc+1)+": Too Bad");
				}
				else { 
					System.out.println("Case #"+(tc+1)+": " + s.count);
				}
			}//Test case for ends
		}//main try ends
		catch (IOException e) {
			e.printStackTrace();
		}	

	}
	
	private static class State { 
		public int[] L1Stars;
		public int[] L2Stars; 
		public boolean[] L1Done; 
		public boolean[] L2Done;
		public int stars;
		public int count;
		
		public State(int[] l1, int[] l2) { 
			L1Stars = l1;
			L2Stars = l2;
			L1Done = new boolean[l1.length]; 
			L2Done = new boolean[l1.length];
			for (int i=0;i<L1Stars.length;i++) { 
				L1Done[i] = L2Done[i] = false;
			}
			
			stars = 0;
			count = 0;
		}
		
		public boolean isDone() {
			for (int i=0;i<L2Done.length;i++) { 
				if (!L2Done[i]) {
					return false;
				}
			}
			
			return true;
		}
		
		public boolean doL2() { 
			for (int i=0;i<L2Stars.length;i++) { 
				if (L2Done[i]==false && stars>=L2Stars[i]) { 
					L2Done[i] = true;
					stars = stars + (L1Done[i]?1:2);
					count++;
					return true;
				}
			}
			
			return false;
		}
		
		public boolean doL1() {
			
			int max = 0;
			int mi = -1; 
			boolean f = false;
			for (int i=0;i<L1Stars.length;i++) { 
				if (L1Done[i]==false && L2Done[i]==false && L1Stars[i]<=stars) { 
					if (L2Stars[i]>max) { 
						max = L2Stars[i];
						mi = i;
						f =  true;
					}
				}
			}
			
			if (f) { 
				L1Done[mi] = true; 
				stars++;
				count++;
			}
			
			return f;
		}
		
	}

}
