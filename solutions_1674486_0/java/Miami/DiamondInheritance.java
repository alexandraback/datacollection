import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class DiamondInheritance
{
	static BufferedReader br;
	static PrintWriter pw;
	
	public static void main(String args[])throws IOException
	{
		br = new BufferedReader(new FileReader("DiamondINPUT.in"));
		pw = new PrintWriter(new FileWriter("DiamondSol.txt"));
		
		int num = Integer.parseInt(br.readLine());
		
		for(int i=0; i<num; i++)
		{
			int numNodes = Integer.parseInt(br.readLine());			
			Node nodes[] = new Node[numNodes];
			
			initNodes(nodes);			
			
			pw.print("Case #" + (i+1) + ": ");
			
			try
			{
				for(int trial=0; trial<numNodes; trial++)
					isDiamond(nodes[trial], trial);
				
			} catch (Exception e)
			{
				//System.out.println("" + i + e.getMessage());
							
				pw.println("Yes");
				continue;
			}
			
			pw.println("No");
			
		}	
		
		pw.close();
		br.close();
	}
	
	private static void isDiamond(Node node, int trial)throws Exception
	{
			if(node.isVisited(trial))
				throw new Exception("Diamond");
			
			node.visitNode(trial);
			for(int i=0; i<node.neighbours.length; i++)
			{
				isDiamond(node.neighbours[i], trial);
			}
	}

	private static void initNodes(Node[] nodes) throws IOException
	{
		for(int j=0; j<nodes.length; j++)
		{
			nodes[j] = new Node(j);
			nodes[j].setNumNodesInGraph(nodes.length);
		}
		
		for(int j=0; j<nodes.length; j++)
		{
			String line = br.readLine();
			StringTokenizer tokens = new StringTokenizer(line);
			
			int numNeighbours = Integer.parseInt(tokens.nextToken());
			//nodes[j] = new Node(j, numNeighbours);
			
			nodes[j].setNumNeighbours(numNeighbours);
			
			nodes[j].initNeighbours(nodes, tokens);
		}
	}
}
