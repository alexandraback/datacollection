import java.io.*;
import java.util.*;

public class DiamondInheritance {
	private static int[] cnt;
	private static boolean find;

	public static void main(String[] args) {
		try {
			BufferedReader ifStream = new BufferedReader(new FileReader("in"));
			PrintWriter ofStream = new PrintWriter(new FileWriter("out"));
			int numCase = Integer.parseInt(ifStream.readLine());

			for (int i=1; i<=numCase; i++) {
				ofStream.println("Case #"+i+": "+computeAns(ifStream));
			}

			ifStream.close();
			ofStream.close();
		}
		catch (IOException e) {
			System.out.println("IOException.");
		}
	}

	private static String computeAns(BufferedReader ifStream) {
		try {
			int numNode = Integer.parseInt(ifStream.readLine());
			Node[] node = new Node[numNode];
			for (int i=0; i<numNode; i++) {
				StringTokenizer st = new StringTokenizer(ifStream.readLine(), " ", false);
				node[i] = new Node(Integer.parseInt(st.nextToken()));
				for (int j=0; j<node[i].numOutput; j++) {
					node[i].next[j] = Integer.parseInt(st.nextToken()) - 1;
				}
			}
			cnt = new int[numNode];

			for (int i=0; i<numNode; i++) {
				if (node[i].numOutput > 1) {
					for (int j=0; j<numNode; j++) {
						cnt[j] = 0;
					}
					find = false;
					trackDown(node, i);
					for (int j=0; j<numNode; j++) {
						if (cnt[j] > 1) {
							return "Yes";
						}
					}
				}
			}
			return "No";
		}
		catch (IOException e) {
			System.out.println("IOException.");
		}
		return "Error";
	}

	private static void trackDown(Node[] node, int i) {
		if (find == true) {
			return;
		}
		if (node[i].numOutput == 0) {
			cnt[i]++;
			if (cnt[i] > 1) {
				find = true;
			}
			return;
		}
		for (int j=0; j<node[i].numOutput; j++) {
			trackDown(node, node[i].next[j]);
		}
	}
}

class Node {
	int numOutput;
	int[] next;

	Node (int numOutput) {
		this.numOutput = numOutput;
		next = new int[numOutput];
	}
}
