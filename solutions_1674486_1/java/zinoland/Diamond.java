package source;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Diamond {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception{

		Scanner scan = new Scanner(new File("A-large.in"));
		BufferedWriter bw = new BufferedWriter(new FileWriter("A-large.out"));
		
		int testCases = new Integer(scan.nextLine());
		
		for(int i=0; i<testCases; i++){
			int clases = new Integer(scan.nextLine());
			String diamond = "No";
			
			List<Node> allNodes = new ArrayList<Node>();
			
			for(int l=1; l<=clases; l++){
				Node nodo = new Node(l);
				allNodes.add(nodo);
			}
			
			if(clases > 0){
				for(int j=0; j<clases; j++){
					String[] data = scan.nextLine().split(" ");				
					int numInheritance = new Integer(data[0]);
					Node actualNode = allNodes.get(j);
					
					if(numInheritance > 0){
						for(int m=1; m <= numInheritance; m++){
							int posParent = new Integer(data[m]);
							Node newParent = allNodes.get((posParent-1));
							actualNode.padres.add(newParent);
							newParent.hijos.add(actualNode);
						}
					}
				}
				
				List<Node> initials = new ArrayList<Node>();
				for(int p=0; p<allNodes.size(); p++){
					if(allNodes.get(p).hijos.size() == 0){
						initials.add(allNodes.get(p));
					}
				}
				
				for(int h=0; h<initials.size(); h++){
					List<Node> resultLi = new ArrayList<Node>();
					boolean res = obtenerResultado(initials.get(h), resultLi);
					if(res == true){
						diamond = "Yes";
						break;
					}
				}
			}
			
			System.out.println("Case #"+(i+1)+": "+diamond);
			bw.write("Case #"+(i+1)+": "+diamond+"\n");
		}
		bw.flush();
		bw.close();
	}
	
	public static boolean obtenerResultado(Node nodo, List<Node> pastNodes){
		boolean diamond = false;
		for(int i=0; i<nodo.padres.size() && diamond == false; i++){
			Node acParent = nodo.padres.get(i);
			if(pastNodes.contains(acParent)){
				diamond = true;
				break;
			}else{
				pastNodes.add(acParent);
				diamond = obtenerResultado(acParent, pastNodes);
			}
		}
		return diamond;
	}

}

class Node{
	public int name = 0;
	public List<Node> padres = new ArrayList<Node>();
	public List<Node> hijos = new ArrayList<Node>();

	public Node(int i){
		name = i;
	}
	@Override
	public boolean equals(Object o){
		return ((Node)o).name == this.name;
	}
}
