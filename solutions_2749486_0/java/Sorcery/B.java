import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Scanner;

public class B {
	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(new FileReader("B-small-attempt0.in"));
		FileWriter fstream = new FileWriter("B-small-attempt0.out");
		BufferedWriter out = new BufferedWriter(fstream);
		int numCases = in.nextInt();
		in.nextLine();
		for (int i = 0; i < numCases; i++) {
			int X = in.nextInt(), Y = in.nextInt();
			in.nextLine();
			out.write("Case #" + String.valueOf(i + 1) + ": " + findPath(X, Y)
					+ "\n");
		}
		out.close();
		in.close();
	}

	public static String findPath(int desX, int desY) {
		ArrayList<Character> path = new ArrayList<Character>();
		for (int i = 1; i <= 500; i++) {
			//System.out.println(desX + " " + desY);
			int count = 1;
			HashSet<LinkedList<Integer>> visited = new HashSet<LinkedList<Integer>> ();
			path = new ArrayList<Character>();
			if (dfs(0, 0, desX, desY, count, path, visited, i)) {
				break;
			}
		}
		String result = "";
		for (char ch : path) {
			result += ch;
		}
		//System.out.println(result);
		return result;
	}

	public static boolean dfs(int curX, int curY, int desX, int desY,
			int count, ArrayList<Character> path, HashSet<LinkedList<Integer>> visited, int length) {
		LinkedList<Integer> list = new LinkedList<Integer> ();
		list.add(curX);
		list.add(curY);
		list.add(count);
		if (visited.contains(list)) {
			return false;
		} else {
			visited.add(list);
		}
		if (curX == desX && curY == desY) {
			return true;
		} else if (length == 0) {
			return false;
		}
		path.add('W');
		boolean r1 = dfs(curX - count, curY, desX, desY, count + 1, path, visited, length - 1);
		if (r1) {
			return true;
		}
		path.remove(path.size() - 1);
		path.add('E');
		boolean r2 = dfs(curX + count, curY, desX, desY, count + 1, path, visited, length - 1);
		if (r2) {
			return true;
		}
		path.remove(path.size() - 1);
		path.add('S');
		boolean r3 = dfs(curX, curY - count, desX, desY, count + 1, path, visited, length - 1);
		if (r3) {
			return true;
		}
		path.remove(path.size() - 1);
		path.add('N');
		boolean r4 = dfs(curX, curY + count, desX, desY, count + 1, path, visited, length - 1);
		if (r4) {
			return true;
		}
		path.remove(path.size() - 1);
		return false;
	}
}


