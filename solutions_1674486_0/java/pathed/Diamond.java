package se.pathed.codejam.practice.diamond;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

public class Diamond {
	
	public BufferedReader getInputReader(String fileName) throws FileNotFoundException{
		String dataFolder = "C:\\Users\\Patrik\\workspaces\\codejam\\Practis\\data\\";
		File f = new File(dataFolder + fileName);
		FileReader fReader = new FileReader(f);
		BufferedReader reader = new BufferedReader(fReader);
		
		return reader;
	}
	
	public PrintWriter getOutputWriter(String fileName) throws FileNotFoundException{
		String dataFolder = "C:\\Users\\Patrik\\workspaces\\codejam\\Practis\\data\\";
		File outputFile = new File(dataFolder + fileName);
		if( outputFile.exists()) outputFile.delete();
		return new PrintWriter(outputFile);
	}
	
	public static void main(String[] args) throws IOException{
		new Diamond().run();
	}
	
	static class Node {
		int[] inheritsFrom;
	}
	
	static class Problem{
		Node[] classes;
	}
	
	Problem parseProblem() throws NumberFormatException, IOException{
		Problem p = new Problem();
		
		int count = Integer.parseInt(reader.readLine());
		p.classes = new Node[count];
		
		for( int i = 0; i < count; i++){
			String[] line = reader.readLine().split(" ");
			Node n = new Node();
			n.inheritsFrom = new int[Integer.parseInt(line[0])];
			for( int x = 1; x < line.length; x++){
				n.inheritsFrom[x-1] = Integer.parseInt(line[x]);
			}
			p.classes[i] = n;
		}
		return p;
	}
	
	BufferedReader reader;
	public void run() throws IOException {
		reader = getInputReader("A-small-attempt0.in");
		PrintWriter writer = getOutputWriter("out.txt");
		
		int pSet = Integer.parseInt(reader.readLine());
		
		for( int i = 0; i < pSet ; i++){
			Problem p = parseProblem();
			
			boolean res = solve(p);
			
			writer.println("Case #" + (i+1) +": " + (res ? "Yes" : "No"));
		}
		writer.flush();
		writer.close();
	}
	
	boolean[] visited;
	Problem currP;
	
	boolean solve(Problem p){
		visited = new boolean[p.classes.length];
		currP = p;
		for(int i = 0; i < p.classes.length; i++){
			if(check(p.classes[i])) return true;
		}
		return false;
	}

	private boolean check(Node node) {
		for( int i = 0; i < visited.length; i++){
			visited[i] = false;
		}
		
		for( int i = 0; i < node.inheritsFrom.length; i++){
			if(visit(node.inheritsFrom[i])) return true;
		}
		return false;
	}
	
	boolean visit(int i){
		i = i - 1;
		if(visited[i]) {
			return true;
		}
		visited[i] = true;
		
		Node n = currP.classes[i];
		for(int c = 0 ; c < n.inheritsFrom.length; c++){
			if(visit(n.inheritsFrom[c])) return true;
		}
		return false;
	}
}
