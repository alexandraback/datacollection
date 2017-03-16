import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedHashSet;
import java.util.LinkedList;
import java.util.Map;
import java.util.StringTokenizer;

public class Treasure {

	
	static Node[] nodes; 
	
	static boolean FOUND = false;
	static int TOTAL = 0;
	static ArrayList<Integer> SOL;
	
	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(
				new FileInputStream("treasure.in")));
		PrintWriter pw = new PrintWriter(new FileOutputStream("treasure.out"));
		
		int caseNum = Integer.parseInt(br.readLine());
		for (int CASE = 1;CASE <= caseNum;CASE++) {
			int k, n;
			StringTokenizer st = new StringTokenizer(br.readLine());
			k = Integer.parseInt(st.nextToken());
			n = Integer.parseInt(st.nextToken());

			LinkedList<Integer> solution = new LinkedList<Integer>();
			LinkedHashSet<Integer> not_yet = new LinkedHashSet<Integer>();
			int[] keys = new int[201];
			nodes = new Node[n+1];
			nodes[0] = new Node(0);
			st = new StringTokenizer(br.readLine());
			for (int i = 0;i < k;i++) {
				int key = Integer.parseInt(st.nextToken());
				keys[key]++;
				nodes[0].addKey(key);
			}

			
			for (int i = 1;i <= n;i++) {
				st = new StringTokenizer(br.readLine());
				nodes[i] = new Node(Integer.parseInt(st.nextToken()));
				int key_num = Integer.parseInt(st.nextToken());
				for (int j = 0;j < key_num;j++) {
					nodes[i].addKey(Integer.parseInt(st.nextToken()));
				}
				not_yet.add(i);
			}
			
			if (doSomething(solution, keys, not_yet)) {
				Iterator<Integer> itr = solution.iterator();
				pw.print("Case #" + CASE + ":");
				for (;itr.hasNext();) {
					pw.print(" " + itr.next());
				}
				pw.println();
			} else {
				pw.println("Case #" + CASE + ": IMPOSSIBLE");
			}				
			
				

		}
		pw.close();
		br.close();
	}
	
	
	
	
	static boolean doSomething(LinkedList<Integer> solution, int[] keys, LinkedHashSet<Integer> not_yet) {
		
		if (not_yet.isEmpty())
			return true;
		
		int t = -1;
		for (Integer intg : not_yet) {
			if (append(solution, keys, intg)) {
				t = intg;
				break;
			}
		}
		if (t != -1) {
			not_yet.remove(t);
			return doSomething(solution, keys, not_yet);
		}
		t = -1;
		for (Integer intg : not_yet) {
			if (appendLeft(solution, keys, intg)) {
				t = intg;
				break;
			}
		}
		if (t != -1) {
			not_yet.remove(t);
			return doSomething(solution, keys, not_yet);
		}
		return false;
	}
	
	
	static boolean append(LinkedList<Integer> solution, int[] keys, int node) {
		if (keys[nodes[node].type] > 0) {
			for (Integer intg : nodes[node].types.keySet()) {
				keys[intg]+= nodes[node].types.get(intg);
			}
			solution.addLast(node);
			keys[nodes[node].type]--;
			return true;
		}
		return false;
	}
	
	static boolean appendLeft(LinkedList<Integer> solution, int[] keys, int node) {
		if (nodes[0].types.get(nodes[node].type) == null)
			return false;
		
		int[] add_keys = new int[201];
		for (Integer intg : nodes[0].types.keySet()) {
			add_keys[intg]+= nodes[0].types.get(intg);
		}
		for (Integer intg : nodes[node].types.keySet()) {
			add_keys[intg]+= nodes[node].types.get(intg);
		}
		add_keys[nodes[node].type]--;
		for (Integer sol : solution) {
			if (add_keys[nodes[sol].type] <= 0)
				return false;
			add_keys[nodes[sol].type] --;
			for (Integer intg : nodes[sol].types.keySet()) {
				add_keys[intg]+= nodes[sol].types.get(intg);
			}	
		}
		keys[nodes[node].type]--;
		for (Integer intg : nodes[node].types.keySet()) {
			keys[intg]+= nodes[node].types.get(intg);
		}
		solution.addFirst(node);
		return true;
	}
	
	static class Node {
		int type;
		ArrayList<Integer> nb = new ArrayList<Integer>();
		Map<Integer, Integer> types = new HashMap<Integer, Integer>();
		Node(int type) {
			this.type = type;
		}
		
		void addKey(int key) {
			if (!types.containsKey(key)) {
				types.put(key, 1);
				return;
			}
			types.put(key, (int) types.get(key) + 1);
			
		}
		
	}

}
