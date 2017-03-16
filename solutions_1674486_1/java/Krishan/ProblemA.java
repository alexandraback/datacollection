package Round1C;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.StringTokenizer;

public class ProblemA {
	
	int numClasses;
	int[][] inheritsFrom;

	public ProblemA() throws IOException {
		BufferedWriter out = new BufferedWriter(new FileWriter(new File("out.txt")));
		Scanner scanner = new Scanner(new File("in.txt"));
		int T = Integer.parseInt(scanner.nextLine());
		
		for(int i=1;i<=T;i++) {
			numClasses = Integer.parseInt(scanner.nextLine());
			inheritsFrom = new int[numClasses][];
			
			for(int j=0;j<numClasses;j++) {
				StringTokenizer tokens = new StringTokenizer(scanner.nextLine());
				int numInherits = Integer.parseInt(tokens.nextToken());
				inheritsFrom[j] = new int[numInherits];
				
				for(int k=0;k<numInherits;k++) {
					inheritsFrom[j][k] = Integer.parseInt(tokens.nextToken()) - 1;
				}
			}
			
			boolean diamond = solve();
			
			String output = "Case #" + i + ": " + "No" + "\n";
			if(diamond)
				output = "Case #" + i + ": " + "Yes" + "\n";
			System.out.print(output);
			out.write(output);
		}
		out.close();
	}
	
	public boolean solve() {
		for(int i=0;i<numClasses;i++) {
			boolean[] visited = new boolean[numClasses];
			for(int j=0;j<numClasses;j++)
				visited[j] = false;
			
			Queue<Integer> queue = new LinkedList<Integer>();
			queue.add(i);
			
			while(!queue.isEmpty()) {
				int myClass = queue.poll();
				if(visited[myClass])
					return true;
				visited[myClass] = true;
				
				for(int j=0;j<inheritsFrom[myClass].length;j++) {
					queue.add(inheritsFrom[myClass][j]);
				}
			}
		}
		return false;
	}
	
	public static void main(String args[]) throws IOException {
		new ProblemA();
	}
}
