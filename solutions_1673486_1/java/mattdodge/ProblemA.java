package round1a;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.text.DecimalFormat;

public class ProblemA {

	public ProblemA() {
		try {
			FileReader fr = new FileReader("A-large.in");
			BufferedReader br = new BufferedReader(fr);
			
			FileWriter fw = new FileWriter("A-large.out");
			BufferedWriter bw = new BufferedWriter(fw);
			
			int numCases = Integer.parseInt(br.readLine());
			System.out.println(numCases);
			String line = br.readLine();
			int caseNum = 1;
			while(line != null) {
				String[] nums = line.split(" ");
				String[] probs = br.readLine().split(" ");
				
				int typedSoFar = Integer.parseInt(nums[0]);
				int totalLength = Integer.parseInt(nums[1]);
				
				// press enter and type again and press enter again
				double minKeyStrokes = totalLength + 2;
				
				for(int backspaces = 0; backspaces <= typedSoFar; backspaces++) {
					double expectedStrokes = 0.0;
					
					if (backspaces * 2 + 2 > minKeyStrokes) {
						continue;
					}
					
					double probDidntMiss = 1;
					
					for (int i=0; i<typedSoFar-backspaces; i++) {
						double digitCorrectProb = Double.parseDouble(probs[i]);
						
						probDidntMiss *= digitCorrectProb;
					}
					
					// now we have the probabilty we backspaced but missed before
					
					// if we missed
					expectedStrokes += (1 - probDidntMiss) * 
							(backspaces + backspaces + totalLength + 2 + totalLength - typedSoFar);
					
					// if we got it!
					expectedStrokes += (probDidntMiss) * (backspaces + backspaces + 1 + totalLength - typedSoFar);
					
//					System.out.println("trying "+backspaces+ " backspaces");
//					System.out.println(probDidntMiss + " prob we didnt miss");
//					System.out.println(expectedStrokes + " expected strokes");
					
					minKeyStrokes = Math.min(minKeyStrokes, expectedStrokes);
				}
				
				DecimalFormat df = new DecimalFormat("#.000000");
				
				String output = "Case #"+caseNum + ": "+ df.format(minKeyStrokes);
				
				System.out.println(output);
				
				bw.append(output);
				if (caseNum != numCases)
					bw.newLine();
				
				line = br.readLine();
				caseNum++;
			}
			
			bw.flush();
			bw.close();
			br.close();
			
			
		} catch(Exception e) {
			e.printStackTrace();
		}
	}
	
	public static void main(String[] args) {
		new ProblemA();
	}

}
