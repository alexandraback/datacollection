import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;
import java.util.SortedSet;
import java.util.TreeSet;

public class Problem3 {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int lines = scan.nextInt();
		
		for (int l = 0 ; l < lines ; l++) {
			int num = scan.nextInt();
			
			long data[] = new long[num];
//			Set<Result> resultSet = new HashSet<Result>();
			Map<Long, SortedSet<Integer>> resultMap = new HashMap<Long, SortedSet<Integer>>();
			
			Set<SortedSet<Integer>> setList = new HashSet<SortedSet<Integer>>();
			for(int i = 0 ; i < num ; i++) {
				data[i] = scan.nextLong();
			}
			Arrays.sort(data);
			
			for(int i = 0 ; i < num ; i++) {
//				Result result = new Result(data[i]);
				SortedSet<Integer> addList = new TreeSet<Integer>();
				addList.add(i);
//				result.addList = addList;
			//	resultSet.add(result);
				setList.add(addList);
				resultMap.put(data[i], addList);
				
//				SortedSet<Integer> addList2 = new TreeSet<Integer>(addList);
//				setList.add(addList2);
			}
			
//			SortedSet<Integer> addList = new TreeSet<Integer>();
			boolean found = false;
			SortedSet<Integer> found1 = null;
			SortedSet<Integer> found2 = null;
		
			Set<SortedSet<Integer>> nextSet = new HashSet<SortedSet<Integer>>(setList);
			for(int addNum = 2 ; addNum <= num-1 && found == false; addNum++) {
				Set<SortedSet<Integer>> newNextSet = new HashSet<SortedSet<Integer>>();
				boolean allOverflowed = true;
				for(int i = 0 ; i < num && found == false; i++) {
					for(SortedSet<Integer> idxList : nextSet) {
						SortedSet<Integer> newSet = new TreeSet<Integer>(idxList);
						if(!newSet.contains(i)) 
						{
							newSet.add(i);
							long sum = 0;
							boolean overflowed = false;
							for(int dataNum : newSet) {
								if(sum <= Long.MAX_VALUE - data[dataNum]) {
								sum += data[dataNum];
								}
								else {
									overflowed = true;
									break;
								}
							}
							
							if(!overflowed) {
								allOverflowed = false;
								SortedSet<Integer> resultSet = resultMap.get(new Long(sum)); 
								if(resultSet != null && !resultSet.equals(newSet)) {
									found = true;
									found1 = newSet;
									found2 = resultSet;
								
									break;
								}
								else {
//									setList.add(newSet);
									newNextSet.add(newSet);
									resultMap.put(sum, newSet);
								}
							}
						}
					}
				}
				if(allOverflowed)
					break;
				nextSet = newNextSet;
			}
			
			System.out.println("Case #" + (l+1) + ":");
			if(found) {
				for(Integer i : found1) {
					System.out.print(data[i] + " ");
				}
				System.out.println();
				for(Integer i : found2) {
					System.out.print(data[i] + " ");
				}
				System.out.println();
			}
			else {
				System.out.println("Impossible");
			}
//			Set<Integer>

			
			
				
		}
	}
}