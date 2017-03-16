package round1c;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.StringTokenizer;

public class DiamondInheritance {

	/**
	 * @param args
	 */
	public static void main(String[] args) {

		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

		try { 
			int T = Integer.parseInt(in.readLine());
			for (int tc = 0; tc<T; tc++) {
				
				int N = Integer.parseInt(in.readLine());
				Map<Integer,List<Integer>> graph = new HashMap<Integer,List<Integer>>();
				
				for (int i=0;i<N;i++) { 
					StringTokenizer st = new StringTokenizer(in.readLine());
					int m = Integer.parseInt(st.nextToken());
					List<Integer> l = new ArrayList<Integer>();
					
					while (st.hasMoreTokens()) { 
						l.add(Integer.parseInt(st.nextToken())-1);
					}
					
					graph.put(i, l);
				}
				
				boolean v[] = new boolean[N]; 
				for (int i=0;i<N;i++) { 
					v[i] = false;
				}
				
				boolean found = false;
				for (int i=0;i<N;i++) { 
					if (v[i]) { 
						continue;
					}
					Map<Integer, Integer> c = new HashMap<Integer,Integer>(); 
					for (int j=0;j<N;j++) { 
						c.put(j, 0);
					}
					
					List<Integer> q = new ArrayList<Integer>(); 
					q.add(i); 
					
					while (q.size()>0) { 
						List<Integer> adj = graph.get(q.get(0));
						if (adj==null) { 
							continue;
						}
						for (int j=0;j<adj.size();j++) { 
							if (c.get(adj.get(j))>0) { 
								//found a loop
								found = true;
								break;
							} else { 
								q.add(adj.get(j));
								c.put(adj.get(j), 1);
							}
						}
						
						q.remove(0);
					}
					
					if (found) { 
						break;
					}
				}
				
				if (found) { 
					System.out.println("Case #" + (tc+1) + ": Yes");
				} else { 
					System.out.println("Case #" + (tc+1) + ": No");
				}
				
			}//Test case for ends
		}//main try ends
		catch (IOException e) {
			e.printStackTrace();
		}	

	}

}
