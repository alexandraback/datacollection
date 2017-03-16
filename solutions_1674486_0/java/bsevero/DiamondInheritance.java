package bsevero.codejam.round1c;

import java.util.Map;

public class DiamondInheritance {
	
	private Map<Integer, DiagramClass> allClasses;

	public String findDiamondInheritance(Map<Integer, DiagramClass> allClasses) {
		this.allClasses = allClasses;
	
		int totalClasses = allClasses.size();
		
		//for each class
		for(int i = 1; i <= totalClasses; i++) {
			DiagramClass classD = allClasses.get(i);
			
			
			
			//for each other classes
			for(int j = 2; j <= totalClasses; j++) {
				if( i == j) {
					continue;
				}
				
				int totalPaths = 0;
				
				if(classD.getOriginalInheritances().containsKey(j)) {
					totalPaths++;
				}
				// for each parent				
				for(int parent: classD.getOriginalInheritances().keySet()) {
					boolean pathFound = findPath(allClasses.get(parent), j);
					if(pathFound) {
						totalPaths++;
						if(totalPaths == 2) {
							return "Yes";
						}
					}
				}
			}
		}
		
		return "No";
		
	}

	private boolean findPath(DiagramClass classD, int j) {

		if(!classD.getInheritances().containsKey(j)) {
		
			for(int parent : classD.getOriginalInheritances().keySet()) {
				DiagramClass parentClass = allClasses.get(parent);
				
				if(!parentClass.getInheritances().containsKey(j)) {
					findPath(parentClass, j);

				}
				
				if(parentClass.getInheritances().get(j)) {
					classD.getInheritances().put(j, true);
					return true;
				}
			}
			
			classD.getInheritances().put(j, false);
			return false;
		}
		
		return classD.getInheritances().get(j);
	}
	
}
