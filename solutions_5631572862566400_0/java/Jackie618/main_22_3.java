import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;


public class main_22_3 {
	public int BFFs(int[] friends){
		int n = friends.length;
		int ans = 0;
		
		Map<Integer, Integer> bestfriend = new HashMap<Integer, Integer>();
		Map<Integer, HashSet<Integer>> bestfriend2 = new HashMap<Integer, HashSet<Integer>>();
		
		for(int i = 0; i < n; ++i){
			bestfriend.put(i + 1, friends[i]);
			if(bestfriend2.containsKey(friends[i])){
				HashSet<Integer> list = bestfriend2.get(friends[i]);
				list.add(i + 1);
				bestfriend2.put(friends[i], list);
			} else{
				HashSet<Integer> list = new HashSet<Integer>();
				list.add(i + 1);
				bestfriend2.put(friends[i], list);
			}
		}		
		
		for(int i = 0; i < n; ++i){
			Set<Integer> set = new HashSet<Integer>();
			int child = i + 1;
			int lastChild = i + 1;
			
			while(!set.contains(child) && set.size() < n){
				set.add(child);
				lastChild = child;
				child = bestfriend.get(child);
			}
			
			if(set.size() == n && child == i + 1){
				ans = Math.max(ans, set.size());
			} 
			else if(set.size() < n){
				int count = set.size();
				
//				if(bestfriend2.containsKey(i + 1)){
//					HashSet<Integer> list1 = bestfriend2.get(i + 1);
//					for(int num : list1){
//						if(!set.contains(num)){
//							set.add(num);
//							count++;
//							break;
//						}
//					}
//				}

				if (bestfriend2.containsKey(child)) {
					int t = bestfriend.get(lastChild);
					if (bestfriend.get(t) == lastChild) {
						HashSet<Integer> list2 = bestfriend2.get(lastChild);
						for (int num : list2) {
							if (!set.contains(num)) {
								set.add(num);
								count++;
								break;
							}
						}
					}
				}
								
				ans = Math.max(ans, count);
			}
		}
		
		return ans;
	}
	
	public static void main(String[] args) {
		main_22_3 m = new main_22_3();
		Scanner in = new Scanner(new BufferedReader(new InputStreamReader(
				System.in)));
		int t = in.nextInt(); // Scanner has functions to read ints, longs,
								// strings, chars, etc.
		for (int i = 1; i <= t; ++i) {
			int number = in.nextInt();
			int[] input = new int[number];
			for (int j = 0; j < number; j++) {
				input[j] = in.nextInt();
			}
			
			int ans = m.BFFs(input);
			
			System.out.print("Case #" + i + ": " + ans);
			System.out.println();
		}
	}
}
