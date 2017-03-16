package codejam.round2C.problemA;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintStream;
import java.util.List;
import java.util.StringTokenizer;

public class ProblemA {
	public static void main(String[] args) throws Exception {
		BufferedReader reader = new BufferedReader(new FileReader("in.txt"));
		PrintStream out = new PrintStream("out.txt");
		int testCaseCount = Integer.parseInt(reader.readLine());
		for(int i=1;i<=testCaseCount;i++) {
			Graph g= new Graph();
			int nbClasses  = Integer.parseInt(reader.readLine());
			for(int classes=1;classes<=nbClasses;classes++) {
				Node node = g.getNode(classes);
				String line = reader.readLine();
				StringTokenizer tokenizer = new StringTokenizer(line);
				int othersCount = Integer.parseInt(tokenizer.nextToken());
				for(int others=1;others<=othersCount;others++) {
					node.inheritsFrom.add(g.getNode(Integer.parseInt(tokenizer.nextToken())));
				}
			}

			List<Node> allNodes = g.getAllNodes();
			String result = "No";
			out:for (Node node : allNodes) {
				for (Node innerNode : allNodes) {
					if(innerNode == node) {
						continue;
					}
					if(node.hasTwoPathsInheritingFrom(innerNode)) {
						result = "Yes";
						break out;
					}
				}
			}

			out.printf("Case #%s: %s\n", i, result);
		}

		reader.close();
		out.close();
	}

}
