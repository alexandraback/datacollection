package codeJam2012_1C;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class DiamondInheritance {
	private String FILE_NAME = "1C-A-small-attempt2";
	private Object[] directSuperClasses;
	private Object[] allSuperClasses;
	private boolean[] allSupersCalculated;
	
	@SuppressWarnings("unchecked")
	private String solve(Scanner sc) {
		int classCount = sc.nextInt();
		directSuperClasses =  new Object[classCount];
		allSuperClasses = new Object[classCount];
		allSupersCalculated = new boolean[classCount];
		
		//Find all direct super classes
		for (int i=0;i<classCount;i++) {
			int count = sc.nextInt();
			Set<Integer> directSupers = new HashSet<Integer>();
			Set<Integer> allSupers = new HashSet<Integer>();
			for (int j=0;j<count;j++) {
				int superClass = sc.nextInt(); 
				directSupers.add(superClass);
				allSupers.add(superClass);
			}
			directSuperClasses[i] = directSupers;
			allSuperClasses[i] = allSupers;
		}
		
		//Add inherited super classes
		for (int i=0;i<classCount;i++) {
			Set<Integer> mySuper = (Set<Integer>) allSuperClasses[i];
			Object[] supers = mySuper.toArray();
			for (Object superObject : supers)
				addSuperSuperClasses(mySuper, (Integer)superObject);
		}

		//Check for multiple inheritence
		boolean multiple = false;
		for (int i=0;i<classCount;i++) {
			Set<Integer> mySuper = (Set<Integer>) directSuperClasses[i];
			for (Integer superClass : mySuper) {
				multiple = multiple || checkMultiple(mySuper,superClass);
			}
		}
		
		return multiple ? "Yes": "No";
	}
	
	private boolean checkMultiple(Set<Integer> mySuper, Integer superClass) {
		Set<Integer> thisSuperSuper = (Set<Integer>)allSuperClasses[superClass-1];
		
		for (Integer superSuperClass : thisSuperSuper) {
			for (Integer otherSuper : mySuper) {
				if (otherSuper!=superClass) {
					if (thisSuperSuper.contains(otherSuper))
						return true;
					
					Set<Integer> otherSuperSuper = (Set<Integer>)allSuperClasses[otherSuper-1];
					if (otherSuperSuper.contains(superSuperClass))
						return true;
				}
			}
		}
		
		return false;
	}

	private void addSuperSuperClasses(Set<Integer> mySuper, int superClass) {
		Set<Integer> superSuper = (Set<Integer>) allSuperClasses[superClass-1];
		if (allSupersCalculated[superClass-1]) {
			for (Integer superClazz : superSuper)
				mySuper.add(superClazz);
		}
		else {
			Object[] supers = superSuper.toArray();
			for (Object superObject : supers) {
				addSuperSuperClasses(superSuper, (Integer)superObject);
				allSupersCalculated[superClass-1] = true;
				
				for (Integer superClazz : superSuper)
					mySuper.add(superClazz);
			}
		}
	}

	public void run() throws IOException {
		Scanner sc = new Scanner(new FileReader(FILE_NAME+".in"));
		PrintWriter pw = new PrintWriter(new FileWriter(FILE_NAME+".out"));
		
		int cases = Integer.valueOf(sc.nextLine());
		for (int i=1;i<=cases;i++) {
			String output = "Case #"+i+": "+solve(sc);
			pw.println(output);
			System.out.println(output);
		}
		
		pw.flush();
		pw.close();
		sc.close();
	}
	public static void main(String[] args) throws IOException {
		new DiamondInheritance().run();
	}
}
