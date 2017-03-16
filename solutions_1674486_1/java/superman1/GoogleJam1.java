import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;

public class GoogleJam1 {

	class Graph {
		Graph(int n) {
			nodes = new Node[n];
			for (int i = 0; i < nodes.length; i++) {
				nodes[i] = new Node();
			}
		}

		Node[] nodes;

		public void clearvisit() {
			for (int i = 0; i < nodes.length; i++) {
				nodes[i].visited = false;
			}
		}
	}

	class Node {

		public void addnode(int n) {
			to.add(n);
		}

		// skip inbound and outboutcount to be less than 2
		public int inboundcount;
		public boolean visited;

		public String ToString() {
			Iterator<Integer> itr = to.iterator();
			String s = "";
			while (itr.hasNext()) {
				Integer element = itr.next();
				s = s + "," + element;
			}
			return s;
		}

		public List<Integer> to = new LinkedList<Integer>();

	}

	Graph graph;

	public GoogleJam1() {
		try {
			// Open the file that is the first
			// command line parameter
			FileInputStream fstream = new FileInputStream("A-large.in");
			// Get the object of DataInputStream
			DataInputStream in = new DataInputStream(fstream);
			BufferedReader br = new BufferedReader(new InputStreamReader(in));
			String strLine;
			int casenumber = -1;
			int curcase = 0;

			int pairnumber = -1;
			int curNode = 1;
			// Read File Line By Line
			while ((strLine = br.readLine()) != null) {
				// Print the content on the console
				if (casenumber == -1) {
					casenumber = Integer.parseInt(strLine);

				} else if (curcase < casenumber) {
					if (pairnumber == -1) {
						pairnumber = Integer.parseInt(strLine);
						graph = new Graph(pairnumber + 1);

						pairnumber--;
						curNode = 1;
					} else {
						pairnumber--;
						fill_pair(curNode++, strLine);
					}

					if (pairnumber == -1) {
						System.out.print("Case #" + ++curcase + ": ");
						if (this.calculate())
							System.out.println("Yes");
						else
							System.out.println("No");

					}
				}
			}
			in.close();
		} catch (Exception e) {// Catch exception if any
			System.err.println("Error: " + e.getMessage());
		}

	}

	private boolean calculate() {

		for (int i = 1; i < graph.nodes.length; i++) {
			graph.clearvisit();
			if (travs(graph.nodes[i]) == true)
				return true;
		}

		return false;
	}

	boolean travs(Node node) {
		node.visited = true;
		boolean ret = false;
		for (int i = 0; i < node.to.size(); i++) {
			// System.out.println("Checking node:" + node.to.get(i));
			if (graph.nodes[node.to.get(i)].visited || ret)
				return true;
			ret = travs(graph.nodes[node.to.get(i)]);
		}
		return ret;
	}

	public void fill_pair(int seq, String input) {
		String[] result = input.split("\\s");
		int N = Integer.parseInt(result[0]);

		for (int x = 1; x < result.length; x++) {
			int temp = Integer.parseInt(result[x]);
			graph.nodes[seq].addnode(temp);
			graph.nodes[temp].inboundcount++;
		}
		graph.nodes[seq].visited = false;
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		new GoogleJam1();

	}

}
