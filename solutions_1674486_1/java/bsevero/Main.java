package bsevero.codejam.round1c;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Main {

	public static void main(String[] args) {
		String inputPath = args[0];
		String outputPath = args[1];
		
		List<String> inputLines = IOUtils.readFile(inputPath);
		//inputLines.remove(0);
		
		Map<Integer, String> casesResult = new HashMap<Integer, String>();
		
		
		
		int caseNum = 1;
		
		for(int line = 1; line < inputLines.size(); ) {
			int totalClasses = Integer.valueOf(inputLines.get(line));
			
			Map<Integer, DiagramClass> allClasses = new HashMap<Integer, DiagramClass>();
			
			for(int classNum = 1; classNum <= totalClasses; classNum++) {
				DiagramClass classD = new DiagramClass();
				classD.setStringInheritance(inputLines.get(line + classNum));
				classD.setNum(classNum);
				allClasses.put(classNum, classD);
			}
			
			String result = new DiamondInheritance().findDiamondInheritance(allClasses);
			casesResult.put(caseNum, result);
			
			line += 1 + totalClasses;
			caseNum++;
		}
		
		IOUtils.writeFile(outputPath, casesResult);
	}

}
