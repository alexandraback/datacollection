package knucle.y2012.Round1A.B;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class B {

	public static void main(String[] args) throws Exception {

		String path = "src/knucle/y2012/Round1A/B/";
//		String file = "sample";
		String file = "small";
		//String file = "large";
		
		FileReader fr = new FileReader(path + file + ".in");
		BufferedReader br = new BufferedReader(fr);
		
		PrintWriter pw = new PrintWriter(path + file + "-output.txt");

		int currentCase = 1;
		int caseNum = Integer.parseInt(br.readLine());
		
		for(currentCase=1; currentCase<=caseNum; currentCase++){
			String line = br.readLine();
			String[] inputs = line.split(" ");
			
			int levels = Integer.parseInt(inputs[0]);
			
			List<Item> items = new ArrayList<Item>(); 
			Map<Integer, List<Integer>> minStarRequiredCount = new HashMap<Integer, List<Integer>>(levels*2);
			Map<Integer, List<Integer>> maxStarRequiredCount = new HashMap<Integer, List<Integer>>(levels*2);
			for(int i=0; i<levels; i++){
				line = br.readLine();
				inputs = line.split(" ");
				
				Integer min = Integer.valueOf(inputs[0]);
				
				
				
				Integer max = Integer.valueOf(inputs[1]);
				List<Integer> v = maxStarRequiredCount.get(max);
				if(v == null){
					v = new ArrayList<Integer>();
				}
				v.add(i);
				maxStarRequiredCount.put(max, v);
				
				items.add(new Item(i, min, max));
			}
			
			Collections.sort(items);

			for (Item item : items) {
				Integer min = item.min;
				List<Integer> v = minStarRequiredCount.get(min);
				if(v == null){
					v = new ArrayList<Integer>();
				}
				v.add(item.no);
				minStarRequiredCount.put(min, v);
			}
			
			Integer result = solve(levels, minStarRequiredCount, maxStarRequiredCount);

			pw.write("Case #");
			pw.print(currentCase);
			pw.write(": ");
			pw.print(result == null ? "Too Bad" : result);
			pw.write('\n');
		}
		
		br.close();
		pw.close();
	}
	
	private static Integer solve(int levels, Map<Integer, List<Integer>> minStarRequiredCount, 
			Map<Integer, List<Integer>> maxStarRequiredCount)
	{
		int[] completed = new int[levels];
		int currentStar = 0;
		Integer tries = 0;
		int completedLevelCount = 0;
		
		List<Integer> minStarRequireds = new ArrayList<Integer>(minStarRequiredCount.keySet());
		Collections.sort(minStarRequireds);
		
		List<Integer> maxStarRequireds = new ArrayList<Integer>(maxStarRequiredCount.keySet());
		Collections.sort(maxStarRequireds);
		
		boolean passed;
		do {
			passed = false;
			while(maxStarRequireds.size() > 0){
				Integer starRequired = maxStarRequireds.get(0);
				
				if(starRequired <= currentStar){
					List<Integer> levelList = maxStarRequiredCount.get(starRequired);
					for (Integer level : levelList) {
						int completedStar = completed[level];
						if(completedStar == 0){
							currentStar += 2;
							tries++;
							completed[level] = 2;
							completedLevelCount++;
							passed = true;
						} else if(completedStar == 1){
							currentStar += 1;
							tries++;
							completed[level] = 2;
							completedLevelCount++;
							passed = true;
						}
					}
					maxStarRequireds = maxStarRequireds.subList(1,maxStarRequireds.size());
					
				} else {
					break;
				}
			}
			
			if(completedLevelCount == levels) break;
			
			boolean minPassed = false;
			while(minStarRequireds.size() > 0){
				Integer starRequired = minStarRequireds.get(0);
				
				if(starRequired <= currentStar){
					List<Integer> levelList = minStarRequiredCount.get(starRequired);
					boolean allChecked = true;
					for (Integer level : levelList) {
						int completedStar = completed[level];
						if(completedStar == 0){
							currentStar += 1;
							tries++;
							completed[level] = 1;
							allChecked = false;
							passed = true;
							minPassed = true;
							break;
						}
					}
					
					if(allChecked){
						minStarRequireds = minStarRequireds.subList(1,minStarRequireds.size());
					}
					
					if(minPassed){
						break;
					}
					
				} else {
					break;
				}
			}
			
			
		} while(passed);
		
		
		return passed ? tries : null;
	}
	
	public static class Item implements Comparable<Item>{
		int min;
		int max;
		int no;
		
		
		public Item(int no, int min, int max) {
			this.no = no;
			this.min = min;
			this.max = max;
		}


		@Override
		public int compareTo(Item o) {
			if(min > o.min) return 1;
			if(min < o.min) return -1;
			
			return (o.max - max);
		}
	}
}
