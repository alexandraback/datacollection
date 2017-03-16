package knucle.y2012.B;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

public class B {

	public static void main(String[] args) throws Exception {
		FileReader fr = new FileReader("b-small.in");
		BufferedReader br = new BufferedReader(fr);
		
		BufferedWriter bw = new BufferedWriter(new FileWriter("output.txt"));

		int currentCase = 1;
		int caseNum = Integer.parseInt(br.readLine());
		
		for(currentCase=1; currentCase<=caseNum; currentCase++){
			String line = br.readLine();
			
			String[] inputs = line.split(" ");
			
			int itemNum = Integer.parseInt(inputs[0]);
			int end = itemNum + 3;
			int suprisingNum = Integer.parseInt(inputs[1]);
			int minScore = Integer.parseInt(inputs[2]);
			
			int minTotalScore = Math.max(minScore*3 - 2, minScore);
			int minSuprisingTotalScore = Math.max(minScore*3 - 4, minScore);
			
			int qualifiedNum = 0;
			for(int i=3; i<end; i++){
				double totalScore = Double.parseDouble(inputs[i]);
				if(totalScore >= minTotalScore){
					qualifiedNum++;
				} else if(suprisingNum > 0 && totalScore >= minSuprisingTotalScore){
					qualifiedNum++;
					suprisingNum--;
				}
			}
			

			bw.write("Case #");
			bw.write(Integer.toString(currentCase));
			bw.write(": ");
			
			bw.write(Integer.toString(qualifiedNum));
			
			bw.write('\n');
		}
		
		br.close();
		bw.close();
	}

}
