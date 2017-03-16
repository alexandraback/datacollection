import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;


public class DiamondInheritance {
	public static void main(String[] args) throws IOException {
		Scanner input = new Scanner(new File(args[0]));
		FileWriter fw = new FileWriter(new File("files/diamondoutput.txt"));
		int tests = toInt(input.nextLine());
		GraphList graph;
		String[] line;
		boolean found;
		
		for (int test = 0; test < tests; test++) {
			graph = new GraphList(toInt(input.nextLine())+1);
			for (int i = 1; i < graph.numVs(); i++) {
				line = input.nextLine().split(" ");
				
				for (int c = 0; c < toInt(line[0]); c++) {
					graph.setEdge(i, toInt(line[c+1]), 1);
				}
			}
			
			fw.write("Case #"+(test+1)+": ");
			
			found = false;
			for (int i = 1; i < graph.numVs(); i++) {
				if (hasDiamond(graph,i)) {
					fw.write("Yes");
					found = true;
					break;
				}
			}
			if (!found)
				fw.write("No");
			
			if (test != tests - 1)
				fw.write("\n");
		}
		fw.close();
	}
	
	static boolean hasDiamond(GraphList graph,int start) {
		Queue<Integer> q = new LinkedList<Integer>();
		int u;
		q.add(start);
		graph.resetMarks();
		graph.setMark(start,1);
		
		while (!q.isEmpty()) {
			u = q.poll();
			for (int v = graph.firstN(u); v != graph.numVs(); v = graph.nextN(u, v)) {
				if (graph.getMark(v) == 1)
					return true;
				graph.setMark(v, 1);
				q.add(v);
			}
		}
		
		return false;
	}
	
	static int toInt(String s) {
		return Integer.parseInt(s);
	}
}
