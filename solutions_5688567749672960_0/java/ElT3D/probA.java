package round2b;

import googleJam.Pair;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Scanner;
import java.util.TreeMap;
import java.util.TreeSet;

public class probA {
	
	
	public static Long reverse(Long c) {
		return Long.parseLong(new StringBuffer(c.toString()).reverse().toString());
	}
	
	public static long getNext(Long c) {
		Long r = reverse(c);
		return (r > c) ? r : (c+1);
	}
	
	
	public static long getNext2(Long c) {
		
		
		
		
		
		return 0l;
	}
	
	
	public static long getPrevious(Long c) {
		Long r = reverse(c);
		
		
		if( (c % 10) == 0) {
			return c - 1;
		}
		else {
			return (r < c) ? r : (c-1);
		}
	}
	
	
	
	
	
	public static void main(String...args) {
		
		Scanner reader = new Scanner(System.in);
		int caseCount = Integer.parseInt(reader.nextLine());
		
		for(int caseId = 1; caseId <= caseCount; caseId++) {
			
			long N = Long.parseLong(reader.nextLine());
			
			
			
			List<Pair> P1 = new ArrayList<Pair>();
			List<Pair> P2 = new ArrayList<Pair>();
			
			HashSet<String> seen = new HashSet<String>();
			HashMap<Long, Long> bests = new HashMap<Long, Long>(); //v -> count
			TreeSet<Long> S = new TreeSet<Long>();
			
			
			Long Vi = 1l;
			Long counti = 1l;
			
			
			if(N > 10000) {
				Vi = 10000l;
				counti = 338l;
			}
			else if(N > 1000) {
				Vi = 1000l;
				counti = 138l;
			}
			else if(N > 100) {
				Vi = 100l;
				counti = 29l;
			}
			
			
			P1.add(new Pair(Vi, counti));
			
			while(P1.size() > 0 || P2.size() > 0) {
				
				Iterator it = P1.iterator();
				while(it.hasNext()) {
					
					Pair pair = (Pair) it.next();
					Long V = pair.x;
					Long count = pair.y;
					it.remove();
					
					if(V < N) {
					
						String signature = V.toString() + "_" + count.toString();
						
						if(bests.get(V) == null || bests.get(V) > count) {
							
							bests.put(V,count);
							
							if(seen.contains(signature) == false) {
								seen.add(signature);
								
//								System.out.println("Count: "+ count + ", "+ V);
								
								count = count + 1;
								Long newV = getNext(V);
								
								if( (newV - V) > 1) {
									P2.add(new Pair(newV, count));
								}
								
								P2.add(new Pair(V + 1, count));
							}
						}
					}
					else if(V == N) {
						
						S.add(count);

					}
				}
				
				it = P2.iterator();
				while(it.hasNext()) {
					
					Pair pair = (Pair) it.next();
					Long V = pair.x;
					Long count = pair.y;
					it.remove();
					
					if(V < N) {
					
						String signature = V.toString() + "_" + count.toString();
						
						if(bests.get(V) == null || bests.get(V) > count) {
							
							bests.put(V,count);
							if(seen.contains(signature) == false) {
								seen.add(signature);
								
								count = count + 1;
//								System.out.println("Count: "+ count + ", "+ V);
										
								Long newV = getNext(V);
								
								if( (newV - V) > 1) {
									P1.add(new Pair(newV, count));
								}
								
								P1.add(new Pair(V + 1, count));
							}
						}
					}
					else if(V == N) {
						
						S.add(count);

					}
				}
			}
			
			
			System.out.println("Case #" + caseId + ": " + S.first());
		}
		
		
	}
}
