package me.stapel.kai.google.codejam2012.round1c;

import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.SortedSet;
import java.util.TreeSet;
import java.util.Vector;

import me.stapel.kai.google.codejam2012.round1c.A.Node;

public class ProblemA {

	private static final String NL = System.getProperty("line.separator");

	public ProblemA() {
		// nothing to do here yet
	}
	
	public static void main(String[] args) {
		ProblemA problemA = new ProblemA();
		
		
		problemA.processFile("in/round1c/A-large.in", "out/round1c/A-large.txt");
		
	}

	private Object processFile(String inFileName, String outFileName) {
		Object obj = new Object();
		
		File inFile = new File(inFileName);
		File outFile = new File(outFileName);

		String line = "";
		
		int t = 1, m=0,tmp=0;
		int T = 0;
		
		SortedSet<Node> nodes = new TreeSet<Node>();

		OutputStreamWriter output;
		BufferedReader br;
		try {
			br = new BufferedReader(new FileReader(inFile));
			output = new OutputStreamWriter(new BufferedOutputStream(
					new FileOutputStream(outFile)), "8859_1");

			line = br.readLine();
			
			T = Integer.parseInt(line);
			
			// skipping first line
			line = br.readLine();

			while (line != null) {
				nodes = new TreeSet<Node>();
				
				String[] split = line.split(" ");

				
				int N = Integer.parseInt(split[0]);

				for(int i = 1; i<=N;i++) {
					Node nodeI = getNode(nodes, i);
					
					
					line = br.readLine();
					split = line.split(" ");
					m = Integer.parseInt(split[0]);
					for(int j = 0; j<m;j++) {
						tmp = Integer.parseInt(split[j+1]);
						Node n = getNode(nodes, tmp);
						
						nodeI.edges.add(n);
					}
				}
				
				boolean multiInheritance = calcInheritance(nodes);
				
				output.write("Case #" + t + ": " + (multiInheritance?"Yes":"No"));
				output.write(NL);
				System.out.print("Case #" + t + ": " + (multiInheritance?"Yes":"No"));
				System.out.print(NL);
				
				line = br.readLine();
				t++;
			}
			
			
			output.flush();
			output.close();

		} catch (FileNotFoundException e) {
			System.err.println("File " + inFile.getName() + " not found. Nothing processed.");
			e.printStackTrace();
		} catch (IOException e) {
			System.err.println("Error when reading file " + inFile.getName() + " or writing file " + outFile.getName() + ".");
			e.printStackTrace();
		}

		return obj;
	}
	
	private Node getNode(Set<Node> nodes, int tmp) {
		for (Node n : nodes) {
			if(n.name == tmp)
				return n;
		}
		Node n = new Node(tmp);
		nodes.add(n);
		return n;
	}

	private boolean calcInheritance(Set<Node> nodes) {
		int i=0,j=0;
		
		for (Node n : nodes) {
			if(n.edges.size() > 1) {
				Set<Node>[] paths = new Set[n.edges.size()];
				i = 0;
				for (Node p : n.edges) {
					paths[i] = new HashSet<Node>();
					paths[i] = calcPath(paths[i], p);
					i++;
				}

				
				for(j=0;j<n.edges.size();j++) {
					for (Node p : paths[j]) {
						for(i=1;i<n.edges.size();i++) {
							if(i!=j && paths[i].contains(p)) {
								return true;
							}
						}
					}
				}
			}
		}

		return false;
	}

	private void printPaths(int i, Node n, List<Node>[] paths) {
		System.out.print("Path from "+ n.name + ":");
		for (Node x : paths[i]) {
			System.out.print(" -> " + x.name);
		}
		System.out.println();
	}

	private Set<Node> calcPath(Set<Node> path, Node n) {

		if(!path.add(n)) {
			return path;
		}
		
		for (Node p : n.edges) {
			path = calcPath(path, p);
		}
		
		return path;
	}



}
