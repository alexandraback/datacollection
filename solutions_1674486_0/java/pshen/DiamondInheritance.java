import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Scanner;


public class DiamondInheritance {
	public static void main(String[] args) throws IOException {
		Scanner fileScan = new Scanner(new File("A-small-attempt0.in"));
		BufferedWriter out = new BufferedWriter(new FileWriter("A-small-attempt0.out"));
		
		int n = Integer.parseInt(fileScan.nextLine());
		for (int i = 0; i < n; i++) {
			int numClasses = fileScan.nextInt();
			HashMap<Integer, LinkedList<Integer>> inherits = new HashMap<Integer, LinkedList<Integer>>();
			
			for (int j = 0; j < numClasses; j++) {
				int numInherits = fileScan.nextInt();
				
				if (numInherits > 0) {
					inherits.put(j + 1, new LinkedList<Integer>());
					for (int k = 0; k < numInherits; k++) {
						inherits.get(j + 1).add(fileScan.nextInt());	
					}
				}	
			}
			
			boolean flag = false;
			for (Integer key : inherits.keySet()) {
				if (inherits.get(key).size() > 1) {
					LinkedList<LinkedList <Integer>> paths = new LinkedList<LinkedList <Integer>>();
					for (Integer superclass : inherits.get(key)) {
						paths.add(DFS(superclass, inherits, new LinkedList<Integer>()));
					}
					
					for (LinkedList<Integer> path : paths) {
						for (Integer pathClass : path) {
							for (LinkedList<Integer> path2 : paths) {
								if (path2 != path && path2.contains(pathClass)) {
									flag = true;
								}
							}
						}
					}
				}
			}
			
			int temp = i + 1;
			if (flag) {	
				out.write("Case #" + temp + ": Yes" + "\n");
			}
			else {
				out.write("Case #" + temp + ": No" + "\n");
			}
		}
		
		out.close();
	}

	private static LinkedList<Integer> DFS(Integer superclass,
			HashMap<Integer, LinkedList<Integer>> inherits, LinkedList<Integer> path) {
		path.add(superclass);
		if (inherits.containsKey(superclass)) {
			for (Integer class1 : inherits.get(superclass)) {
				DFS(class1, inherits, path);
			}
		}
		
		return path;
	}	
}
