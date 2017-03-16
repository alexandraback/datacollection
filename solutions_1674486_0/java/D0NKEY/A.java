package com.googlecodejam.gcj2012.round1C;

import java.io.File;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class A {

//	public final static String INPUT_FILE_NAME = "test.in";
	public final static String INPUT_FILE_NAME = "A-small-attempt2.in";
//	public final static String INPUT_FILE_NAME = "A-large.in";
	
	public FileWriter outputWriter;
	public Scanner scanner;
	public String output = "";
	
	public void run() throws Exception {
		// Commons variables
		int testCaseNumber = 0;
		// Test start
		{
			int nbTests = Integer.parseInt(scanner.nextLine());
			
			for (testCaseNumber = 0; testCaseNumber < nbTests; testCaseNumber++) {
				int nbClasses = Integer.parseInt(scanner.nextLine());
				HashMap<Integer, Node> nodes = new HashMap<Integer, Node>(nbClasses);
				for (int i = 1; i <= nbClasses; i++) {
					Node node = nodes.get(i);
					if (node == null) {
						node = new Node();
						node.name = i;
						nodes.put(i, node);
					}
					String[] values = scanner.nextLine().split(" ");
					int nbSuperClasses = Integer.parseInt(values[0]);
					for (int sc = 0; sc < nbSuperClasses; sc++) {
						int superClassName = Integer.parseInt(values[sc+1]);
						Node superClass = nodes.get(superClassName);
						if (superClass == null) {
							superClass = new Node();
							superClass.name = superClassName;
							nodes.put(superClassName, superClass);
						}
						node.superNodes.add(superClass);
					}
				}
				boolean containsDiamond = false; 
				for (int i = 1; i <= nbClasses; i++) {
					Node node = nodes.get(i);
					if (node != null && node.explored == false) {
						containsDiamond = dfs(node, i);
					}
					if (containsDiamond) {
						break;
					}
				}
				output += "Case #" + (testCaseNumber+1) + ": " + (containsDiamond ? "Yes" : "No") + "\n";
			}
		}
	}
	
	public boolean dfs(Node node, int explorationNumber) {
		if (node.explored && node.explorationNumber == explorationNumber) {
			return true;
		} else {
			node.explored = true;
			node.explorationNumber = explorationNumber;
			boolean diamond = false;
			for (Node superClass : node.superNodes) {
				diamond = dfs(superClass, explorationNumber);
				if (diamond) {
					break;
				}
			}
			return diamond;
		}
	}
	
	public static class Node {
		public int name;
		public ArrayList<Node> superNodes = new ArrayList<Node>();
		public boolean explored = false;
		public int explorationNumber = 0;
	}
	
	/////////////////////////////////////////////////////////////////////////////////////////////////////
	
	public void init() throws Exception {
		File temp = new File("output/");
		if (!temp.exists()) {
			temp.mkdir();
		}
		// Output file
		outputWriter = new FileWriter("output/output.txt", false);
		// Input file
		scanner = new Scanner(new File("resources/" + INPUT_FILE_NAME));
	}

	public void stop() throws Exception {
		// Closing files
		outputWriter.write(output, 0, output.length());
		scanner.close();
		outputWriter.close();
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		A instance = new A();
		long start = System.currentTimeMillis();
		
		instance.init();
		instance.run();
		instance.stop();
		
		System.out.println("Finished in " + (System.currentTimeMillis() - start) + " ms");
	}
	
}
