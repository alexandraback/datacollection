import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.math.BigDecimal;
import java.util.ArrayList;


public class Password {
	public static void main(String[] args) {
		Integer caseNum = 0;
		ArrayList<String> argList = new ArrayList<String>();
		String line=null;
		File inputFile = new File("PasswordData.txt");
		BufferedReader reader;
		try {
			reader = new BufferedReader(new FileReader(inputFile));
			while ((line=reader.readLine()) != null) {
				argList.add(line);
			}
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		caseNum = Integer.parseInt(argList.get(0));
		int lastCaseEnd = 0;
		for(int caseIndex=0; caseIndex < caseNum.intValue(); caseIndex++) {
			String input = argList.get(lastCaseEnd+1);
			String[] inputData = input.split(" ");
			int typedNum = Integer.parseInt(inputData[0]);
			int totalNum = Integer.parseInt(inputData[1]);
			String probRow = argList.get(lastCaseEnd+2);
			String[] probString = probRow.split(" ");
			double[] prob = new double[typedNum];
			for(int i=0; i < typedNum; i++) {
				prob[i] = Double.parseDouble(probString[i]);
				//System.out.println(mapData[row]);
			}
			lastCaseEnd = lastCaseEnd + 2;
			//BigDecimal.valueOf(calExpect(prob, typedNum, totalNum)).
			System.out.println("Case #" + (caseIndex+1) + ": " + BigDecimal.valueOf(calExpect(prob, typedNum, totalNum)).setScale(6, BigDecimal.ROUND_HALF_DOWN));
		}
	}
	
	public static double calExpect(double[] prob, int typedNum, int totalNum) {
		double optKeys = 0.0;
		double probOfAllCorrect = 1.0;
		int remainNum = totalNum - typedNum + 1;
		int retypeNum = totalNum + 1;
		for(int i = 0; i<prob.length; i++) {
			probOfAllCorrect = probOfAllCorrect * prob[i];
		}
		
		//case 1: keep typing
		optKeys = probOfAllCorrect * remainNum + (1.0 - probOfAllCorrect) * (remainNum + retypeNum);
		//System.out.println("back " + 0 + " : " + optKeys);
		
		//case 2: press backstrace
		for(int backNum = 1; backNum < typedNum + 1; backNum++) {
			double beforeBackIsCorrect = 1.0;
			for(int i = 0; i < prob.length - backNum; i++) {
				beforeBackIsCorrect = beforeBackIsCorrect * prob[i];
			}
			double expKeys = beforeBackIsCorrect * (backNum * 2 + remainNum) + (1.0 - beforeBackIsCorrect) * (backNum * 2 + remainNum + retypeNum);
			optKeys = (optKeys > expKeys) ? expKeys : optKeys;
			//System.out.println("back " + backNum + " : " + optKeys);
		}
		
		//case 3: press enter
		optKeys = (optKeys > (totalNum + 2)) ? (totalNum + 2) : optKeys;
		
		return optKeys;
		
	}
}
