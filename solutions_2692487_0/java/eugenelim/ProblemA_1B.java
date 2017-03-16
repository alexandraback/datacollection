import java.io.*;
import java.util.*;

/*
 * Round 1B Problem A: Osmos
 */
public class ProblemA_1B {
	private static class Node {
		int size;
		int ops;
		int index;
		public Node(int size, int ops, int index) {
			this.size = size;
			this.ops = ops;
			this.index = index;
		}
	}
	public static int solve(int A, int[] other) {
		Arrays.sort(other);
		ArrayList<Node> nodes = new ArrayList<Node>();
		nodes.add(new Node(A, 0, 0));
		int min_ops = Integer.MAX_VALUE;
		while (!nodes.isEmpty()) {
			Node cur_node = nodes.get(0);
			int cur_size = cur_node.size;
			int cur_ops = cur_node.ops;
			int cur_index = cur_node.index;
				
			if (cur_index >= other.length) {
				if (cur_ops < min_ops) {
					min_ops = cur_ops;
				}
				nodes.remove(0);
				continue;
			}
				
			if (cur_size > other[cur_index]) {
				cur_node.size = cur_size + other[cur_index];
				cur_node.index++;
				nodes.set(0, cur_node);
			} else {
				if (other[cur_index] < 2 * cur_size - 1) {
					cur_node.ops++;
					cur_node.size = 2 * cur_size - 1 + other[cur_index];
					cur_node.index++;
					nodes.set(0, cur_node);
				} else {				
					// insert until able to eat
					int ex_ops = cur_ops;
					int ex_size = cur_size;
					boolean doAdd = true;
					while (ex_size <= other[cur_index]) {
						ex_size += ex_size - 1;
						ex_ops++;
						if (ex_size == cur_size) {
							doAdd = false;
							break;
						}
					}
					if (doAdd) {
						nodes.add(new Node(ex_size+other[cur_index], ex_ops, cur_index+1));
					}
					
					// delete
					cur_node.ops++;
					cur_node.index++;
					nodes.set(0, cur_node);
				}
			}
		}

		return min_ops;
	}
	
	public static void main(String[] args) {
		try {
			// Init Scanner / Writer
			String filename = "A-small-attempt1";
			Scanner sc = new Scanner(new File(filename + ".in"));
			BufferedWriter out = new BufferedWriter(new FileWriter(filename + ".out"));
			
			// Start reading file
			int T = sc.nextInt();
			for (int i=1; i<=T; i++) {
				sc.nextLine();
				int A = sc.nextInt();
				int N = sc.nextInt();
				int[] other = new int[N];
				sc.nextLine();
				for (int j=0; j<N; j++) {
					other[j] = sc.nextInt();
				}
				out.write("Case #");
				out.write(Integer.toString(i));
				out.write(": ");
				out.write(Integer.toString(solve(A, other)));
				out.write("\n");
			}
			out.close();
			sc.close();
		} catch (Exception e) {
			System.out.println(e);
		}
	}
}
