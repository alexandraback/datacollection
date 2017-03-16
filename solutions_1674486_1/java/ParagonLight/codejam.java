import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class codejam {

	/**
	 * @param args
	 */

	public class node {
		public int[] inherits = null;
		public int nodeid;

		public node(int nodeid, int[] inherits) {
			if (inherits != null) {
				// System.out.println("hello");
				this.inherits = inherits.clone();

			}
			this.nodeid = nodeid;
		}
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		codejam codejama = new codejam();
		BufferedReader br;
		try {
			br = new BufferedReader(new FileReader("input.txt"));
			PrintWriter pw = new PrintWriter(new File("output"));
			String line;
			String cases = br.readLine();
			int count = 1;
			while ((line = br.readLine()) != null) {
				int nodesNum = Integer.parseInt(line);
				ArrayList<codejam.node> nodes = new ArrayList<codejam.node>();
				for (int i = 0; i < nodesNum; i++) {
					codejam.node node;
					line = br.readLine();
					String strs[] = line.split(" ");
					if (Integer.parseInt(strs[0]) != 0) {
						int[] inherits = new int[Integer.parseInt(strs[0])];
						// System.out.println(line);
						for (int j = 1; j < strs.length; j++) {
							// System.out.println(strs[j]);
							inherits[j - 1] = Integer.parseInt(strs[j]);
						}
						for (int j = 0; j < inherits.length; j++) {
							System.out.println(inherits[j]);
						}
						node = codejama.new node(i + 1, inherits);
						// System.out.println("sss" + (i + 1));
					} else
						node = codejama.new node(i + 1, null);

					nodes.add(node);
				}
				int flag = 0;
				for (int i = 0; i < nodesNum; i++) {

					if (flag == 1)
						break;
					codejam.node start = nodes.get(i);
					System.out.println(start.nodeid);
					if (start.inherits != null) {
						System.out.println("start " + i);

						Map<Integer, Integer> path = new HashMap<Integer, Integer>();
						ArrayList<codejam.node> pathNode = new ArrayList<codejam.node>();
						if (start.inherits.length > 1) {
							for (int j = 0; j < start.inherits.length; j++) {
						//		System.out.println("start node:" +start.inherits[j]);
								path.put(start.inherits[j], start.inherits[j]);
							//	System.out.println(nodes.get(start.inherits[j] - 1).nodeid);
								pathNode.add(nodes.get(start.inherits[j] - 1));
							}
							while (flag == 0 && !pathNode.isEmpty()) {
								ArrayList<codejam.node> temp = new ArrayList<codejam.node>();
								for (int j = 0; j < pathNode.size(); j++) {

									codejam.node n = pathNode.get(j);
									System.out.println(n.nodeid);
									if (n.inherits != null) {
										for (int k = 0; k < n.inherits.length; k++) {
											if (path.containsKey(n.inherits[k])) {
												flag = 1;
												break;
											} else {
												path.put(n.inherits[k], n.inherits[k]);
												temp.add(nodes
														.get((n.inherits[k] - 1)));
												System.out.println(n.inherits[k] + " " + n.nodeid);
											}
										}
									}
								}
								pathNode.clear();
								pathNode = null;
								pathNode = temp;
							}
						}
					}

				}
				if (flag == 1)
					System.out.println("Case #" + count + ": Yes");

				if (flag == 0)
					System.out.println("Case #" + count + ": No");
				if (flag == 1)
					pw.write("Case #" + count + ": Yes\n");

				if (flag == 0)
					pw.write("Case #" + count + ": No\n");
				pw.flush();
				count++;
			}

		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}
}
