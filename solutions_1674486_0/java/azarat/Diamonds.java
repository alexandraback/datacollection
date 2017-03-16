import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Iterator;
import java.util.Scanner;

// taken from jgrapht: http://jgrapht.org/
import org.jgraph.graph.DefaultEdge;
import org.jgrapht.alg.KShortestPaths;
import org.jgrapht.graph.SimpleDirectedGraph;

public class Diamonds {

	public static int numClasses;
	public static void main(String args[]) throws IOException{
		long startTime = System.currentTimeMillis();
		// Setup the input
		File f1 = new File("A-small-attempt3.in");
		Scanner s1 = new Scanner(f1);

		PrintWriter out = new PrintWriter(new FileWriter("output.out"));

		int testCases = Integer.parseInt(s1.nextLine());

		for (int i = 0; i<testCases; i++){
			SimpleDirectedGraph<String, DefaultEdge> g;
			g = createStringGraph(s1);
			String verdict = "No";
			for (int q = 1; q<numClasses; q++){
				for (int w = 1; w<numClasses; w++){
					if (q!=w && verdict.equals("No")){
						KShortestPaths<String, DefaultEdge> paths = new KShortestPaths<String, DefaultEdge>(g,Integer.toString(q),2);
						if (paths.getPaths(Integer.toString(w)) != null){
							Iterator iterator = paths.getPaths(Integer.toString(w)).listIterator();
							//System.out.println("test");
							int number = 0;
							while(iterator.hasNext()){
								iterator.next();
								number++;
							}

							if (number >= 2){
								verdict = "Yes";
							}
						}
					}
				}
			}

			int testCase = i+1;
			out.println("Case #"+ testCase +": " + verdict);

		}

		s1.close();
		out.close();
		System.out.println((System.currentTimeMillis() - startTime)/1000);
	}

	private static SimpleDirectedGraph<String, DefaultEdge> createStringGraph(Scanner s1)
	{
		SimpleDirectedGraph<String, DefaultEdge> g =
				new SimpleDirectedGraph<String, DefaultEdge>(DefaultEdge.class);

		numClasses = s1.nextInt();
		// for each class
		for (int k = 1; k<= numClasses; k++){
			//System.out.println("add vertex: " + k);
			g.addVertex(Integer.toString(k));

		}
		for (int l = 1; l<= numClasses; l++){
			int numIn = s1.nextInt();
			for (int j = 0; j<numIn; j++){
				int x = s1.nextInt();
				g.addEdge(Integer.toString(l), Integer.toString(x));
			}
		}

		return g;
	}
}
