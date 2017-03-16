import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;


/**
 * 
 * Google Code Jam 2012 Round 1A - Problem A. Password Problem
 * 
 * @author matlock
 *
 */
public class PasswordProblem {

	public static void main(String[] args) {
		PasswordProblem g = new PasswordProblem();
		g.goGo();
	}
	
	public void goGo() {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		
		try {
			int testCases = Integer.parseInt(in.readLine());
			
			for (int i = 1; i <= testCases; i++) {
				String anb = in.readLine();
				String[] anbArray = anb.split(" ", 2);
				int numCharsTyped = Integer.valueOf(anbArray[0]);
				int passwordLen = Integer.valueOf(anbArray[1]);
				String readProbability = in.readLine();
				String[] probStrArray = readProbability.split(" ", numCharsTyped);
				List<Double> probList = new ArrayList<Double>();
				for (String prob : probStrArray) {
					probList.add(Double.valueOf(prob));
				}
				
				double result = runTestCase(passwordLen, probList);
				DecimalFormat df = new DecimalFormat();
				df.setMinimumFractionDigits(6);
				
				System.out.println("Case #" + i + ": " + df.format(result).replace(",", ""));
			}
		} catch (IOException e) {
			System.out.println("Exception: " + e.getMessage());
		}
	}
	
	private double runTestCase(int passwordLen, List<Double> probList) {
		List<Double> keystrokeList = new ArrayList<Double>();
		keystrokeList.add(1 + (double)passwordLen + 1); // press enter
		// calculate keep typing
		double correctProb = probList.get(0);
		for (int k = 1; k < probList.size(); k++) {
			correctProb *= probList.get(k);
		}
		double wrongProb = 1.0d - correctProb;
		double calcKeepTyping = (correctProb * (passwordLen - probList.size() + 1))
				+ (wrongProb * (passwordLen - probList.size() + 1 + passwordLen + 1));
		keystrokeList.add(calcKeepTyping);
		
		// calculate backspace it all
		double backspaceAll = (double)probList.size() + (double)passwordLen + 1.0d;
		keystrokeList.add(backspaceAll);
		
		// calculate backspace each char
		for (int k = 1; k < probList.size(); k++) {
			int strokesCorrect = k + (passwordLen - (probList.size() - k)) + 1;
			int strokesWrong = strokesCorrect + passwordLen + 1;

			correctProb = probList.get(0);
			for (int n = 1; n < (probList.size() - k); n++) {
				correctProb *= probList.get(n);
			}
			wrongProb = 1.0d - correctProb;

			double calcBackspace = (correctProb * strokesCorrect) + (wrongProb * strokesWrong);
			keystrokeList.add(calcBackspace);
		}
		
		Collections.sort(keystrokeList);
		return keystrokeList.get(0);
	}
	
}
