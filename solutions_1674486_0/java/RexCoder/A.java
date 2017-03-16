import java.util.*;
import java.io.*;

public class A {

	static Scanner scan;
	static PrintWriter pw;

	public static void main(String[] args) throws Exception {
		scan = new Scanner(System.in);
		pw = new PrintWriter(new File("output-A.txt"));	
		ArrayList<Node> nodeList = new ArrayList<Node>();
		int tc = scan.nextInt();
		int element = 0;
		int temp;
		for (int xx=1; xx<=tc; xx++) {
			nodeList.clear();
			nodeList.add(new Node(0));
			element = scan.nextInt();
			
			int target;
			for (int yy=1; yy<=element; yy++) {
				Node now = new Node(yy);
				nodeList.add(now);				
			}
			
			for (int yy=1; yy<=element; yy++) {
				target = scan.nextInt();
				for (int zz=0; zz<target; zz++) {
					temp = scan.nextInt();
					nodeList.get(yy).inhFrom.add(nodeList.get(temp));	
				}	
			}
			
			boolean valid = false;
			
			for (int yy=1; yy<=element; yy++) {
				valid = valid || Control(nodeList.get(yy));
			}
			
			/*for (int yy=1; yy<=element; yy++) {
				pw.println(nodeList.get(yy).toString());
			}*/
			pw.print("Case #"+xx+": ");
			pw.println((valid)?"Yes":"No");
		}
		pw.close();
	}
	static int[] visited = new int[10000];
	
	public static boolean Control(Node from) {
		Arrays.fill(visited, 0);
		DFS(from);
		// check //
		
		for (int n=0; n<visited.length; n++) {
			if (visited[n]>=2) {
				return true;
			}
		}
		return false;
	}
	
	public static void DFS(Node from) {
		
		ArrayList<Node> inhFrom = from.inhFrom;
		for (int n=0; n<inhFrom.size(); n++) {			
			visited[inhFrom.get(n).now]++;
			DFS(inhFrom.get(n));			
		}	
	}

}

class Node {
	Integer now;
	ArrayList<Node> inhFrom;
	public Node(Integer node) {
		inhFrom = new ArrayList<Node>(10);
		now = node;
	}
	
	public String toString() {
		String output = "Node ["+now+"] - ";
		for (int n=0; n<inhFrom.size(); n++) {
			output+=(inhFrom.get(n).now+" - ");
		}
		return output;
	}
}


