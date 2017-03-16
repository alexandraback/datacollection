import java.io.*;
import java.util.*;

/*
 * Round 1C Problem B: Pogo
 */
public class ProblemB_1C {
	public static class Node {
		int x;
		int y;
		String moves_so_far;
		
		public Node(int x, int y) {
			this.x = x;
			this.y = y;
			this.moves_so_far = "";
		}
		
		
	}
	
	public static String solve(int x, int y) {
		ArrayList<Node> lst = new ArrayList<Node>();
		ArrayList<Node> nxt = new ArrayList<Node>();
		HashMap<Integer, HashMap<Integer, Boolean>> visited = new HashMap<Integer, HashMap<Integer, Boolean>>(); 
		lst.add(new Node(0, 0));
		visited.put(0, new HashMap<Integer, Boolean>());
		visited.get(0).put(0, true);
		int cur_move = 1;
		while (!lst.isEmpty()) {
			Node cur = lst.remove(0);
			
			if (cur.x == x && cur.y == y) {
				return cur.moves_so_far;
			}
				
			int cur_x;
			int cur_y;
			boolean to_add;

			// N
			cur_x = cur.x;
			cur_y = cur.y + cur_move;
			to_add = false;
			if (visited.containsKey(cur_x)) {
				if (!visited.get(cur_x).containsKey(cur_y)) {
					visited.get(cur_x).put(cur_y, true);
					to_add = true;
				}
			} else {
				visited.put(cur_x, new HashMap<Integer, Boolean>());
				visited.get(cur_x).put(cur_y, true);
				to_add = true;
			}
			if (to_add) {
				Node nextnode = new Node(cur_x, cur_y);
				nextnode.moves_so_far = cur.moves_so_far + "N";
				nxt.add(nextnode);
			}
			
			// S
			cur_x = cur.x;
			cur_y = cur.y - cur_move;
			to_add = false;
			if (visited.containsKey(cur_x)) {
				if (!visited.get(cur_x).containsKey(cur_y)) {
					visited.get(cur_x).put(cur_y, true);
					to_add = true;
				}
			} else {
				visited.put(cur_x, new HashMap<Integer, Boolean>());
				visited.get(cur_x).put(cur_y, true);
				to_add = true;
			}
			if (to_add) {
				Node nextnode = new Node(cur_x, cur_y);
				nextnode.moves_so_far = cur.moves_so_far + "S";
				nxt.add(nextnode);
			}
			
			// E
			cur_x = cur.x + cur_move;
			cur_y = cur.y;
			to_add = false;
			if (visited.containsKey(cur_x)) {
				if (!visited.get(cur_x).containsKey(cur_y)) {
					visited.get(cur_x).put(cur_y, true);
					to_add = true;
				}
			} else {
				visited.put(cur_x, new HashMap<Integer, Boolean>());
				visited.get(cur_x).put(cur_y, true);
				to_add = true;
			}
			if (to_add) {
				Node nextnode = new Node(cur_x, cur_y);
				nextnode.moves_so_far = cur.moves_so_far + "E";
				nxt.add(nextnode);
			}
			
			// W
			cur_x = cur.x - cur_move;
			cur_y = cur.y;
			to_add = false;
			if (visited.containsKey(cur_x)) {
				if (!visited.get(cur_x).containsKey(cur_y)) {
					visited.get(cur_x).put(cur_y, true);
					to_add = true;
				}
			} else {
				visited.put(cur_x, new HashMap<Integer, Boolean>());
				visited.get(cur_x).put(cur_y, true);
				to_add = true;
			}
			if (to_add) {
				Node nextnode = new Node(cur_x, cur_y);
				nextnode.moves_so_far = cur.moves_so_far + "W";
				nxt.add(nextnode);
			}
			if (lst.isEmpty()) {
				cur_move++;
				lst = nxt;
				nxt = new ArrayList<Node>();
			}
		}
		return "";
	}
	
	public static void main(String[] args) {
		try {
			// Init Scanner / Writer
			String filename = "B-small-attempt0";
			Scanner sc = new Scanner(new File(filename + ".in"));
			BufferedWriter out = new BufferedWriter(new FileWriter(filename + ".out"));
			
			// Start reading file
			int T = sc.nextInt();
			for (int i=1; i<=T; i++) {
				sc.nextLine();
				int x = sc.nextInt();
				int y = sc.nextInt();
				out.write("Case #");
				out.write(Integer.toString(i));
				out.write(": ");
				out.write(solve(x, y));
				out.write("\n");
			}
			out.close();
			sc.close();
		} catch (Exception e) {
			System.out.println(e);
		}
	}

}
