import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

public class DiamondInheritance {

	/**
	 * @param args
	 * @throws IOException
	 */
	public static ArrayList<int[]> create_list(int[][] graph, int j) {
		ArrayList<int[]> list = new ArrayList<int[]>();
		for (int k = 0; k < graph.length; k++) {

			if (graph[j][k] == 1) {
				int[] x = { j, k };
				list.add(x);
			}
		}
		return list;
	}

	public static boolean check(ArrayList<int[]> list) {
		for (int i = 1; i < list.size(); i++)
			if (list.get(0)[1] == list.get(i)[1])
				return true;
		return false;
	}

	public static boolean checksize(ArrayList<int[]> list, int[][] graph) {
		for (int i = 0; i < list.size(); i++) {
			for (int k = 0; k < graph.length; k++) {
				if (graph[list.get(i)[1]][k] == 1) {
					return true;
				}
			}
		}
		return false;
	}

	public static boolean test(ArrayList<int[]>list,int[][]graph){
		while (checksize(list, graph)){
			if (check(list))
				return true;
			int size_now=list.size();
			for (int k = 0; k < graph.length; k++) {
				if (graph[list.get(0)[1]][k] == 1) {
					int[] x = { list.get(0)[0], k };
					list.add(x);
				}
			}
			if (list.size()!=size_now)
				list.remove(0);
			else{
				list.add(list.remove(0));
			}
			
		}
		if (check(list))
			return true;
		return false;
	}

	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(new FileReader("A-Small-diamond.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
				"A-Small-diamond.out")));
		int n = in.nextInt();
		for (int i = 0; i < n; i++) {
			boolean ans = false;
			int size = in.nextInt();
			int[][] graph = new int[size][size];
			for (int j = 0; j < size; j++) {
				int col = in.nextInt();
				for (int k = 0; k < col; k++) {
					graph[j][in.nextInt() - 1] = 1;
				}
			}
			for (int j = 0; j < size; j++) {
				ArrayList<int[]> list = create_list(graph, j);
				if (test(list, graph)) {
					ans = true;
					break;
				}
			}
			out.println("Case #" + (i + 1) + ": " + (ans ? "Yes" : "No"));
		}
		out.close();
	}

}
