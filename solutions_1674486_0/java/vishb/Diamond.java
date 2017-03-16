package c;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

public class Diamond {

	/**
	 * @param args
	 */
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		sc.nextLine();
		for (int _t = 0; _t < t; _t++) {
			int numClasses = sc.nextInt();
			
			Map<Integer, Set<Integer>> classHierarchy = new HashMap<Integer, Set<Integer>>();
			for (int i=0; i<numClasses; i++){
				
				Set<Integer> parentSet = new HashSet<Integer>();
				classHierarchy.put(i+1, parentSet);
				
				int numParents = sc.nextInt();
				
				for (int j=0; j<numParents; j++) {
					int parent = sc.nextInt();
					parentSet.add( parent );
				}
			}
			
			System.out.printf("Case #%d: ",_t+1);
			// flatten the hierarchy
			Map<Integer, Set<Integer>> flattenedHierarchy = new HashMap<Integer, Set<Integer>>();
			try {
				for (int i=0; i<numClasses; i++){
					Set<Integer> flattenedSet = flatten(i+1, classHierarchy.get(i+1), new HashSet<Integer>(), classHierarchy);
					flattenedHierarchy.put(i+1, flattenedSet);
					
				}
			} catch (DiamondException e) {
				System.out.println("Yes");
				continue;
			}
			System.out.println("No");
		}
	}

	private static Set<Integer> flatten(int classNum, Set<Integer> unflattenedParents, Set<Integer> flattenedHierarchy, Map<Integer, Set<Integer>> classHierarchy) {
		
		for (Integer parent : unflattenedParents) {
			if (flattenedHierarchy.contains(parent)){
				throw new DiamondException();
			}
			flattenedHierarchy.add(parent);
			if (classHierarchy.containsKey(parent)){
				flatten(parent, classHierarchy.get(parent), flattenedHierarchy, classHierarchy);
			}
		}
		
		return flattenedHierarchy;
	}

}
class DiamondException extends RuntimeException {}