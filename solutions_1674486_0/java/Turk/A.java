import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Iterator;


public class A {

public static void main(String[] args) {
		
		BufferedReader in;
		BufferedWriter out;
		int T, i;
		String line;
		
		try {
			in = new BufferedReader(new FileReader("input.in"));
			out = new BufferedWriter(new FileWriter("output.txt"));
		} catch (FileNotFoundException e) {
			System.out.println(e.getMessage());
			return;
		} catch (IOException e) {
			System.out.println(e.getMessage());
			return;
		}

		try {
			T = Integer.parseInt(in.readLine());

			for (i = 0; i < T; i++) {
				line = in.readLine();
				
				int N = Integer.parseInt(line);
				
				Node[] nodes = new Node[N];
				
				for (int j = 0; j < N; j++) nodes[j] = new Node();
				
				
				for (int j = 0; j < N; j++) {
				
					line = in.readLine();
				
					String[] data = line.split(" ");
					int M = Integer.parseInt(data[0]);
					for (int k = 0; k < M; k++) {
						System.out.println(M + "\t" + k);
						nodes[j].inherit.add(nodes[Integer.parseInt(data[k+1])-1]);
					}
					
				}
				
				
				String lineToWrite = "Case #" + (i+1) + ": ";
				
				lineToWrite += solve(nodes);
				
				out.write(lineToWrite + "\n");
				
			}
			in.close();
			out.close();
		} catch (IOException e) {
			System.out.println(e.getMessage());
			return;
		}
	}

	public static String solve(Node[] nodes) {
		for (int i = 0; i < nodes.length; i++) {
			for (int j = 0; j < nodes.length; j++) nodes[j].from = null;
			if (DFS(nodes, nodes[i])) return "Yes";
		}
		return "No";
	}
	
	public static boolean DFS(Node[] nodes, Node current) {
		Iterator<Node> myIt = current.inherit.iterator();
		while (myIt.hasNext()) {
			Node next = myIt.next();
			if (next.from == null) {
				next.from = current;
				if (DFS(nodes, next)) return true;
			} else if (next.from != current) return true;
		}
		return false;
	}
	
}
