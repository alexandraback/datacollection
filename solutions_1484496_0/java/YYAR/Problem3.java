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
			
			int data[] = new int[num];
//			Set<Result> resultSet = new HashSet<Result>();
			Map<Integer, SortedSet<Integer>> resultMap = new HashMap<Integer, SortedSet<Integer>>();
			
			Set<SortedSet<Integer>> setList = new HashSet<SortedSet<Integer>>();
			for(int i = 0 ; i < num ; i++) {
				data[i] = scan.nextInt();
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
		
			for(int addNum = 2 ; addNum <= 19 && found == false; addNum++) {
				Set<SortedSet<Integer>> currentSet = new HashSet<SortedSet<Integer>>(setList);
				for(int i = 0 ; i < num && found == false; i++) {
					for(SortedSet<Integer> idxList : currentSet) {
						SortedSet<Integer> newSet = new TreeSet<Integer>(idxList);
						if(!newSet.contains(i)) 
						{
							newSet.add(i);
							int sum = 0;
							for(int dataNum : newSet) {
								sum += data[dataNum];
							}
							
							SortedSet<Integer> resultSet = resultMap.get(new Integer(sum)); 
							if(resultSet != null && !resultSet.equals(newSet)) {
								found = true;
								found1 = newSet;
								found2 = resultSet;
								
								break;
							}
							else {
								setList.add(newSet);
								resultMap.put(sum, newSet);
							}
						}
					}
				}
			}
			
			System.out.println("Case #" + (l+1) + ":");
			if(found) {
				for(Integer i : found1) {
					System.out.printf("%d ", data[i]);
				}
				System.out.println();
				for(Integer i : found2) {
					System.out.printf("%d ", data[i]);
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