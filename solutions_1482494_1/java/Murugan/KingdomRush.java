import java.io.*;
import java.util.*;


public class KingdomRush {
	
	public static TreeSet<Integer> findLevels(HashMap<Integer,HashSet<Integer>> levels, int points) {
		TreeSet<Integer> ret=new TreeSet<Integer>();
		
		Iterator it = levels.keySet().iterator();
		while(it.hasNext()) {
			int p = (Integer)it.next();
			if(p<=points) {
				HashSet hs = levels.get(p);
				if(hs!=null)
					ret.addAll(hs);
			}
		}
		
		return ret;
	}
	
	public static void main(String args[]) {
		try {
			String strFileName = args[0];
			BufferedReader bfReader = new BufferedReader(new FileReader(strFileName));
			long nTestCases = Integer.parseInt(bfReader.readLine());
			
			
			
			for(int testCaseCounter=0;testCaseCounter<nTestCases;testCaseCounter++) {
				int N = Integer.parseInt(bfReader.readLine());
				int A[][] = new int[N][2];
				
				HashMap<Integer,HashSet<Integer>> level1req = new HashMap<Integer,HashSet<Integer>>();
				HashMap<Integer,HashSet<Integer>> level2req = new HashMap<Integer,HashSet<Integer>>();
				
				TreeSet<Integer> level1unfinished = new TreeSet<Integer>();
				TreeSet<Integer> level2unfinished = new TreeSet<Integer>();
				TreeSet<Integer> level1completed = new TreeSet<Integer>();
				
				for(int counter = 0;counter<N;counter++) {
					StringTokenizer st = new StringTokenizer(bfReader.readLine());
					A[counter][0] = Integer.parseInt(st.nextToken());
					A[counter][1] = Integer.parseInt(st.nextToken());
					
					level1unfinished.add(counter);
					level2unfinished.add(counter);
					
					HashSet hs = level1req.get(A[counter][0]);
					if(hs==null) {
						hs = new HashSet<Integer>();
						hs.add(counter);
						level1req.put(A[counter][0], hs);
					}
					else {
						hs.add(counter);
					}
					
					hs = level2req.get(A[counter][1]);
					if(hs==null) {
						hs = new HashSet<Integer>();
						hs.add(counter);
						level2req.put(A[counter][1], hs);
					}
					else {
						hs.add(counter);
					}
				}
				
				int gameIteration=0;
				int points = 0;
				
				while(!level2unfinished.isEmpty()) {
					//find level 2 that could completed with earned points
					TreeSet<Integer> levels = findLevels(level2req, points);
					boolean exitFlag = true;
					int newpoints = 0;
					
					if(!levels.isEmpty()) {
						exitFlag=false;
						Iterator it = levels.iterator();
						
						while(it.hasNext()) {
							int lv = (Integer)it.next();
							if(level1completed.contains(lv)) {
								gameIteration++;
								newpoints += 1;
							}
							else {
								gameIteration++;
								newpoints += 2;
								
								//clear level 1
								HashSet<Integer> hs = level1req.get(A[lv][0]);
								hs.remove(lv);
								level1unfinished.remove(lv);
								level1completed.add(lv);
								
								if(hs.isEmpty()) {
									level1req.remove(A[lv][0]);
								}
							}
							
							//clear level 2
							HashSet<Integer> hs = level2req.get(A[lv][1]);
							hs.remove(lv);
							level2unfinished.remove(lv);
							if(hs.isEmpty()) {
								level2req.remove(A[lv][1]);
							}
						}
						points += newpoints;
						continue;
					}
					
					// find level1 that could be completed
					
					levels = findLevels(level1req, points);
					if(!levels.isEmpty()) {
						exitFlag=false;
						Iterator it = levels.iterator();
						int lv = (Integer)it.next();
						int lv1 = lv;
						int max = A[lv][1];
						
						while(it.hasNext()) {
							lv = (Integer)it.next();
							if(A[lv][1]>max) {
								max=A[lv][1];
								lv1=lv;
							}
						}
						
						//clear level 1
						HashSet<Integer> hs = level1req.get(A[lv1][0]);
						hs.remove(lv1);
						level1unfinished.remove(lv1);
						level1completed.add(lv1);
						
						if(hs.isEmpty()) {
							level1req.remove(A[lv1][0]);
						}
						
						points++;
						gameIteration++;
					}
					
					if(exitFlag) {
						gameIteration=0;
						break;
					}
				}
				
				if(gameIteration == 0)
					System.out.println("Case #" + (testCaseCounter+1) + ": " + "Too Bad");
				else
					System.out.println("Case #" + (testCaseCounter+1) + ": " + gameIteration);
			}
			
		}
		catch(FileNotFoundException e) {
			System.out.println(e.getMessage());
		}
		catch(IOException e) {
			System.out.println(e.getMessage());
			e.printStackTrace();
		}
	}
}
