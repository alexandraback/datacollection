package round2;

import java.util.*;

public class RankAndFile {
	public static void main(String[] args){		
		Scanner scanner = new Scanner(System.in);
		int testcases = Integer.parseInt(scanner.nextLine());
		for(int i=1; i<=testcases; i++){
			int N = Integer.parseInt(scanner.nextLine());
			List<List<Integer>> matrix = new ArrayList<List<Integer>>();
			
			for(int j=0; j<2*N-1; j++){
				String[] arr = scanner.nextLine().split(" ");
				List<Integer> list = new ArrayList<Integer>();
				for(int k=0; k<arr.length; k++){
					list.add(Integer.parseInt(arr[k]));
				}
				matrix.add(list);
			}
			
			System.out.print(String.format("Case #%d: ", i));
			rankFile(matrix, N);
		}
		scanner.close();
	}
	
	public static void rankFile(List<List<Integer>> matrix, int N){
		Set<Integer> set = new HashSet<Integer>();
		
		for(int i=0; i<matrix.size(); i++){
			for(int j=0; j<matrix.get(i).size(); j++){
				int num = matrix.get(i).get(j);
				if(set.contains(num)){
					set.remove(num);
				}else{
					set.add(num);
				}
				
			}
		}
		
		int[] arr = new int[N];
		int index = 0;
		for(int num : set){
			arr[index++] = num;
		}
		
		Arrays.sort(arr);
		
		for(int i=0; i<arr.length; i++){
			System.out.print(arr[i] + " ");
		}
		System.out.println();
		
	}
	
}
