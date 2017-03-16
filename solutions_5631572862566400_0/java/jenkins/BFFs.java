package round1A;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

import javax.swing.JFileChooser;

public class BFFs {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner input = chooseInput();
		PrintWriter output = new PrintWriter("Round1A_Part_C_Small.txt");
		process(input, output);
		output.close();
		System.out.println("done");
	}
	
	public static void process(Scanner input, PrintWriter out){
		int numTests = input.nextInt();
		for(int i=1; i<= numTests; i++){
			int biggest = count(input);
			out.printf("Case #%d: %d\n", i, biggest);
		}
	}
	
	static Map<Integer, Node> children;
	static boolean[] isStart;
	static int n;
	static int[] pathLengths;
	static int numSuperBFFs;
	static int[] endsInSuperBFF;
	
	public static int count(Scanner input){
		children = new HashMap<Integer, Node>();
		n = input.nextInt();
		isStart = new boolean[n];
		for(int i=0; i<isStart.length; i++){
			isStart[i] = true;
		}
		for(int i=0; i<n; i++){
			int bff = input.nextInt();
			Node child = new Node(i, bff-1);
			isStart[bff-1] = false;
			children.put(i, child);
		}
		findSuperBFFs();
		findPathLengths();
		
		return findMax();
	}
	
	public static int findMax(){
		int max = 0;
		for (int i=0; i<n; i++){
			if(pathLengths[i] > max){
				max = pathLengths[i];
			}
		}
		return max;
	}
	
	
	public static void findPathLengths(){
		pathLengths = new int[n];
		endsInSuperBFF = new int[n];
		for(int i=0; i<n; i++){
			pathLengths[i] = 0;
			endsInSuperBFF[i] = -1;
		}
		for(int i=0; i<n; i++){
			boolean[] visited = new boolean[n];
			for(int j=0; j<n; j++){
				visited[j] = false;
			}
			visited[i] = true;

			int pathLength = 1;
			Node current = children.get(i);
			while(!visited[current.BFF]){
				pathLength++;
				visited[current.BFF] = true;
				current = children.get(current.BFF);
			}
			if(children.get(current.BFF).BFF == current.ID){
				pathLengths[i] = pathLength;
				endsInSuperBFF[i] = current.ID;
				continue;
			}
			int cycleStart = current.BFF;
			Node cycle = children.get(current.BFF);
			int cycleLength = 1;
			while(cycle.BFF != cycleStart){
				cycle = children.get(cycle.BFF);
				cycleLength++;
			}
			pathLengths[i] = cycleLength;
		}
		int[] updatedLengths = new int[n];
		for(int i=0; i<n; i++){
			if(endsInSuperBFF[i] > -1){
				int add = 0;
				for(int j=0; j<n; j++){
					if(endsInSuperBFF[j] > -1 && endsInSuperBFF[j] != endsInSuperBFF[i]){
						add = Math.max(add, pathLengths[j]-2);
					}
				}
				add += 2*(numSuperBFFs -1);
				updatedLengths[i] = pathLengths[i] + add;
			}
			else {
				updatedLengths[i] = pathLengths[i];
			}
		}
		pathLengths = updatedLengths;
	}

	
	
	public static void findSuperBFFs(){
		boolean[] visited = new boolean[n];
		numSuperBFFs = 0;
		for(int i=0; i<n; i++){
			visited[i] = false;
		}
		for(int i=0; i<n; i++){
			if(!visited[i] && children.get(children.get(i).BFF).BFF == i){
				visited[i] = true;
				visited[children.get(i).BFF] = true;
				numSuperBFFs++;
			}
		}
	}
	
	private static class Node {
		public int ID;
		public int BFF;
		
		public Node (int id, int friend){
			ID = id;
			BFF = friend;
		}
		
		@Override
		public boolean equals(Object other){
			return ID == ((Node)other).ID;
		}
	}
	

	
	
	
	
	public static Scanner chooseInput() throws FileNotFoundException{
		JFileChooser fileChooser = new JFileChooser();
		int result = fileChooser.showOpenDialog(fileChooser);
		if(result == JFileChooser.APPROVE_OPTION){
			File selectedFile = fileChooser.getSelectedFile();
			Scanner ret = new Scanner(new FileReader(selectedFile));
			return ret;
		}
		return null;
	}
}
