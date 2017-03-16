import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class diamond {
	
	public static void main(String[] args) throws IOException{
		
		String path = "C:\\Users\\Rapol Tongchenchitt\\Documents\\CodeJam\\";
		String year = "1C2012\\";
		
		String input = "A-small-attempt0.in"; String output = "A-small-attempt0.out";
		
		String inName = path+year+input;
		String outName = path+year+output;
		
		Scanner in = new Scanner(new FileInputStream(inName));
		BufferedWriter out = new BufferedWriter(new FileWriter(outName));
		
		int caseCount = in.nextInt(); int currentCase = 0;
		
		while(currentCase++ < caseCount){
			
			int nodeCount = in.nextInt();
			
			ArrayList<Node> nodeList = new ArrayList<Node>();
			nodeList.add(new Node(0));
			for(int i = 0; i < nodeCount; i++){
				nodeList.add(new Node(i+1));
			}
			
			System.out.println(nodeList);
			
			for(int i = 1; i <= nodeCount; i++){
				int ParentCount = in.nextInt();
				for(int j = 0; j < ParentCount; j++){
					int parentNow = in.nextInt();
					nodeList.get(parentNow).addChild(nodeList.get(i));
				}
			}
			
			int found = 0;
			
			for(Node n : nodeList){
				ArrayList<Node> temp = n.travel();
				for(int i = 0; i < temp.size() && found == 0; i++){
					for(int j = i+1; j < temp.size() && found == 0; j++){
						if(temp.get(i) == temp.get(j)){
							found = 1;
						}
					}
				}
			}
			
			String answer = (found == 0) ? "No" : "Yes";
			
			out.write("Case #" + currentCase + ": " + answer );
			out.newLine();
		}
		
		out.close();
		
	}

}

class Node {
	int mine;
	ArrayList<Node> childList;
	
	public Node(int value){
		mine = value;
		childList = new ArrayList<Node>();
	}
	
	public void addChild(Node from){
		childList.add(from);
	}
	
	public ArrayList<Node> travel(){
		ArrayList<Node> temp = new ArrayList<Node>();
		temp.add(this);
		for(Node n : childList){
			temp.addAll(n.travel());
		}
		return temp;
	}
	
	public String toString(){
		return "I'm " + mine;
	}
}
