import java.util.*;

public class A {
	private Node[] classes;

	public static void main(String[] args) {
		new A();
	}

	public A() {
		Scanner input = new Scanner(System.in);
		int numCases = input.nextInt();
		for (int n = 0; n < numCases; n++) {
			classes = new Node[input.nextInt()];
			for (int i = 0; i < classes.length; i++) {
				classes[i] = new Node();
				int[] inherits = new int[input.nextInt()];
				for (int j = 0; j < inherits.length; j++) {
					inherits[j] = input.nextInt() - 1;
				}
				classes[i].links = inherits;
			}
			boolean diamond = false;
			for (int i = 0; i < classes.length; i++) {
				for (int j = 0; j < classes.length; j++) {
					if (i == j) continue;
					int paths = classes[i].findPaths(j);
					if (paths >= 2) {
						diamond = true;
						break;
					}
				}
			}
			System.out.println("Case #" + (n+1) + ": " + (diamond ? "Yes" : "No"));
		}
	}

	class Node {
		public int[] links;

		public int findPaths(int j) {
			int paths = 0;
			for (int i = 0; i < links.length; i++) {
				if (links[i] == j) {
					paths++;
				} else if (classes[links[i]].links.length <= links.length) {
					paths += classes[links[i]].findPaths(j);
				}
			}
			return paths;
		}
	}
}
