import java.util.LinkedList;
import java.util.Scanner;


public class DiamondInheritance {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		//number of case tests
		int test_cases;
		
		int n;
		boolean[][] classes;
		
		test_cases = scanner.nextInt();
		scanner.nextLine();
		
		for(int t=1; t<= test_cases; t++){
			n  = scanner.nextInt();
			scanner.nextLine();
			
			classes = new boolean[n][n];
			
			for (int i = 0; i < n; i++) {
				int m  = scanner.nextInt();
				
				for (int j = 0; j < m; j++) {
					int parent = scanner.nextInt();
					
					classes[i][parent-1] = true;
				}
				
				scanner.nextLine();
			}
			
			boolean found = false;
			outer: for (int i = 0; i < n; i++) {
				int[] visit_count = new int[n];
				boolean[] visited = new boolean[n];
				LinkedList<Integer> list = new LinkedList<Integer>();
				list.add(i);
				
				while(!list.isEmpty()){

					int actual = list.pop();

					visited[actual] = true;
					
				for (int j = 0; j < n; j++) {
					if(actual != j){
					if(classes[actual][j]){
						if(visit_count[j] > 0){
							found = true;
							break outer;
							}
						else{
							visit_count[j] ++;
							if(!visited[j])
								list.add(j);
						}
					}
					}
				}
				}
			}
			
			
			if(found)
				System.out.println("Case #" + t + ": Yes");
			else
				System.out.println("Case #" + t + ": No");
		}	
	}

}
