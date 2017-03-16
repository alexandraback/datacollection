package knucle.y2012.Round1A.A;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;
import java.text.DecimalFormat;
import java.text.Format;

public class A {

	public static void main(String[] args) throws Exception {

		String path = "src/knucle/y2012/Round1A/A/";
//		String file = "sample";
		String file = "small";
		//String file = "large";
		
		FileReader fr = new FileReader(path + file + ".in");
		BufferedReader br = new BufferedReader(fr);
		
		PrintWriter pw = new PrintWriter(path + file + "-output.txt");

		int currentCase = 1;
		int caseNum = Integer.parseInt(br.readLine());
		DecimalFormat df = new DecimalFormat("#.000000");
		
		for(currentCase=1; currentCase<=caseNum; currentCase++){
			String line = br.readLine();
			String[] inputs = line.split(" ");
			
			int typed = Integer.parseInt(inputs[0]);
			int charNum = Integer.parseInt(inputs[1]);
			
			double[] changeOfCorrect = new double[typed];
			line = br.readLine();
			inputs = line.split(" ");
			
			for(int i=0; i<typed; i++){
				changeOfCorrect[i] = Double.parseDouble(inputs[i]);
			}
			
			
			double result = solve(typed, charNum, changeOfCorrect);

			pw.write("Case #");
			pw.print(currentCase);
			pw.write(": ");
			pw.print(df.format(result));
			
			pw.write('\n');
		}
		
		br.close();
		pw.close();
	}
	
	private static double solve(int typed, int charNum, double[] chanceOfCorrect){
		double bestExpected = Double.MAX_VALUE;
		int remaining = charNum - typed;
		
		for(int backed=0; backed<=typed; backed++){
			double correctChance = 1.0;
			
			int letterCount = typed - backed;
			for(int i=0; i<letterCount; i++){
				correctChance *= chanceOfCorrect[i];
			}
			
			double wrongChance = 1.0 - correctChance;
			
			int correctKeyStroke = remaining + backed + backed + 1;
			int wrongKeyStroke = remaining + backed + backed + charNum + 2;
			
			double expected = correctChance * correctKeyStroke + 
					wrongChance * wrongKeyStroke;
			
			bestExpected = Math.min(bestExpected, expected);
			
		}
		
		//Give up
		bestExpected = Math.min(bestExpected, 2+charNum);
		
		return bestExpected;
	}
	
}
