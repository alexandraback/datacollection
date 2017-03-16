import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

class Algorithm{	
	Node[] nodes;
	boolean[] visited;
	boolean diamond;
	Scanner scan;
	
	public Algorithm(int lines, Scanner scan){
		this.scan = scan;
		nodes = new Node[lines + 1];
		visited = new boolean[lines + 1];
		diamond = false;
		for(int i = 1; i <= lines; i++){
			nodes[i] = new Node(i);
		}
		for(int i = 1; i <= lines; i++){
			int inheritCount = scan.nextInt();
			for(int j = 0; j < inheritCount; j++){
				nodes[i].addChild(nodes[scan.nextInt()]);
			}
		}
	}
	
	public String getOutput(){
		if(diamond){
			return "Yes";
		}
		else{
			return "No";
		}
	}

	public void solve(){
		for (Node i: nodes){
			for (int x = 0; x < visited.length; x++){
				visited[x] = false;
			}
			if(i != null){
				traverse(i);
				if(diamond == true){
					break;
				}
			}
		}
	}

	public void traverse(Node n){
		if (diamond == true){
			return;
		}
		if (visited[n.getId()] == true){
			diamond = true;
			return;
		}
		visited[n.getId()] = true;
		ArrayList<Node> links = n.getChildren();
		for (Node i: links){
			traverse(i);
		}
	}
}


class Node {
	ArrayList<Node> children;
	int id;
	boolean visited;
	Node(int id){
		this.id = id;
		children = new ArrayList<Node>();
		visited = false;
	}
	
	public int getId(){
		return id;
	}
	
	public int getLinks(){
		return children.size();
	}
	
	public ArrayList<Node> getChildren(){
		return children;
	}
	
	public void addChild(Node n){
		children.add(n);
	}
	
	public boolean getVisited(){
		return visited;
	}
	
	public void visit(){
		visited = true;
	}
	
	
}

public class Main {
	
	public static void main(String[] args) throws IOException{
		File inputFile = new File("input.txt");
		Scanner scan = new Scanner(inputFile);
		int loopCount = scan.nextInt();
		FileWriter outputFile = new FileWriter("output.txt");
		for(int i = 1; i <= loopCount; i++){
			Algorithm start = new Algorithm(scan.nextInt(), scan);
			start.solve();
			outputFile.write("Case #"+i+": " + start.getOutput());
			if(i < loopCount){
				outputFile.write("\r\n");
			}
		}
		outputFile.close();
	}
}
