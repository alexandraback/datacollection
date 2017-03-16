import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;

public class C {

	public static void main(String[] args) throws IOException {
		
		BufferedReader input = new BufferedReader(new FileReader("C:\\Users\\Wenjuan\\Desktop\\C.txt"));
		PrintWriter output = new PrintWriter(new FileWriter("C:\\Users\\Wenjuan\\Desktop\\answer.txt"));
		
		int T = Integer.parseInt(input.readLine());
		
		for (int t = 1; t <= T; t++) {
			System.out.println(t);
			int strings = Integer.parseInt(input.readLine());
			
			String[][] topics = new String[strings][2];
			
			for (int i = 0; i < strings; i++) {
				
				String[] nextLine = input.readLine().split(" ");
				topics[i][0] = nextLine[0];
				topics[i][1] = nextLine[1];
				
			}
			
			Node[] nodes = new Node[strings];
			
			for (int i = 0; i < nodes.length; i++) {
				
				nodes[i] = new Node(i);
				
			}
			
			for (int i = 0; i < topics.length; i++) {
				
				for (int j = i + 1; j < topics.length; j++) {
					
					if (topics[i][0].equals(topics[j][0])) {
						
						nodes[i].firstEdges.add(j);
						nodes[j].firstIndegree++;
						nodes[j].firstEdges.add(i);
						nodes[i].firstIndegree++;
						
					}
					
					if (topics[i][1].equals(topics[j][1])) {
						
						nodes[i].secondEdges.add(j);
						nodes[j].secondIndegree++;
						nodes[j].secondEdges.add(i);
						nodes[i].secondIndegree++;
						
					}
					
				}
				
			}
			
			ArrayList<Node> considering = new ArrayList<Node>();
			
			for (int i = 0; i < nodes.length; i++) {
				
				if (nodes[i].firstIndegree == 0 || nodes[i].secondIndegree == 0) {
					
					considering.add(nodes[i]);
					
				}
				
			}
			
			if (considering.size() == 0) {
				System.out.println("happened");
				for (int i = 0; i < nodes.length; i++) {
					
					if (!nodes[i].considered && (nodes[i].firstIndegree == 1 && nodes[i].secondIndegree == 0 || nodes[i].firstIndegree == 0 && nodes[i].secondIndegree == 1)) {
						
						considering.add(nodes[i]);
						break;
						
					}
					
				}
				
			}
			
			if (considering.size() == 0) {
				System.out.println("happened");
				for (int i = 0; i < nodes.length; i++) {
					
					if (!nodes[i].considered && nodes[i].firstIndegree <= 1 && nodes[i].secondIndegree <= 1) {
						
						considering.add(nodes[i]);
						break;
						
					}
					
				}
				
			}	
			
			if (considering.size() == 0) {
				System.out.println("happened");
				considering.add(nodes[0]);
				
			}
			
			int considered = considering.size();
			int faked = 0;
			
			while (considered < nodes.length) {
				
				for (int i = 0; i < considering.size(); i++) {
					
					considering.get(i).considered = true;
					
					for (Integer node : considering.get(i).firstEdges) {
						
						nodes[node].firstCount++;
						
					}
					
					for (Integer node : considering.get(i).secondEdges) {
						
						nodes[node].secondCount++;
						
					}
					
				}
				
				considering.clear();
				
				for (int i = 0; i < nodes.length; i++) {
					
					if (nodes[i].firstCount > 0 && nodes[i].secondCount > 0 && !nodes[i].considered) {
						
						faked++;
						considering.add(nodes[i]);
						
					}
					
				}
				
				if (considering.size() == 0 && considered < nodes.length) {
					System.out.println("again");
					for (int i = 0; i < nodes.length; i++) {
						
						if (!nodes[i].considered && nodes[i].firstCount == 0 && nodes[i].secondCount == 0) {
							
							considering.add(nodes[i]);
							break;
							
						}
						
					}
					
				}
				
				if (considering.size() == 0 && considered < nodes.length) {
					System.out.println("again");
					for (int i = 0; i < nodes.length; i++) {
						
						if (!nodes[i].considered && nodes[i].firstCount <= 1 && nodes[i].secondCount <= 1) {
							
							considering.add(nodes[i]);
							break;
							
						}
						
					}
					
				}
				
				if (considering.size() == 0 && considered < nodes.length) {
					System.out.println("again");
					for (int i = 0; i < nodes.length; i++) {
						
						if (!nodes[i].considered) {
							
							considering.add(nodes[i]);
							break;
							
						}
						
					}
					
				}
				
				considered += considering.size();
				
			}
			
			output.println("Case #" + t + ": " + faked);
			
		}
		
		input.close();
		output.close();
		
	}
	
	public static class Node {
		
		int id;
		ArrayList<Integer> firstEdges;
		ArrayList<Integer> secondEdges;
		int firstIndegree;
		int secondIndegree;
		int firstCount;
		int secondCount;
		boolean considered;
		
		public Node(int id) {
			
			this.id = id;
			firstEdges = new ArrayList<Integer>();
			secondEdges = new ArrayList<Integer>();
			firstIndegree = 0;
			secondIndegree = 0;
			firstCount = 0;
			secondCount = 0;
			considered = false;
			
		}
		
	}

}