import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.HashSet;
import java.util.Scanner;
import java.util.TreeSet;


public class Main {

	/**
	 * @param args
	 * @throws FileNotFoundException 
	 */
	public static Nodes[] nodes;
	public static HashSet<Integer> checkSet = new HashSet<Integer>();
	public static boolean found = false;
	public static void main(String[] args) throws FileNotFoundException {
		Scanner scanner = new Scanner(System.in);
		int numTestCases = Integer.valueOf(scanner.nextLine());
		for ( int i =0; i < numTestCases; i++ ) {
			found = false;
			System.out.printf("Case #%d: ", i+1);
			String line = scanner.nextLine();
			int N = Integer.valueOf(line);
			nodes = new Nodes[N];
			for ( int j =0 ; j < N; j++ ) {
				nodes[j] = new Nodes(j);
				line = scanner.nextLine();
				Scanner lineScanner = new Scanner(line);
				int numParents = lineScanner.nextInt();
				for ( int k =0; k < numParents; k++) {
					int currParent = lineScanner.nextInt()-1;
					nodes[j].parents.add(currParent);
				}
				lineScanner.close();
			}
			//Done reading.
			for ( int j =0 ; j < N; j++ ) {
				if (!nodes[j].hasParent() ) {
					continue;
				}
				checkSet.clear();
				dfs(nodes[j]);
				if ( found ) {
					System.out.println("Yes");
					break;
				}
			}
			if ( !found ) {
				System.out.println("No");
			}
		}
		scanner.close();
		
	}

	private static void dfs(Nodes node) {
		if ( found  ) {
			return;
		}
		if ( checkSet.contains(node.nodeNum)) {
			found = true;
			return;
		}
		checkSet.add(node.nodeNum);
		for ( Integer parent : node.parents) {
			dfs(nodes[parent]);
		}
	}
	
}



