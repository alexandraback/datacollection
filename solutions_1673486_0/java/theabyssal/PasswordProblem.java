import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Locale;
import java.util.Scanner;

public class PasswordProblem {
	
	public static void main(String[] args) throws IOException{
		
		String path = "C:\\Users\\Rapol Tongchenchitt\\Documents\\CodeJam\\";
		String year = "1A2012\\";
		
		String input = "A-small-attempt2.in"; String output = "A-small-attempt2.out";
		
		String inName = path+year+input;
		String outName = path+year+output;
		
		Scanner in = new Scanner(new FileInputStream(inName));
		BufferedWriter out = new BufferedWriter(new FileWriter(outName));
		
		int caseCount = in.nextInt(); int currentCase = 0;
		
		while(currentCase++ < caseCount){
			
			int typedCount = in.nextInt();
			int allCount = in.nextInt();
			
			double[] probArray = new double[typedCount];
			for(int i = 0; i < typedCount; i++){
				probArray[i] = in.nextDouble();
			}
			
			double probAllCorrect = 1;
			for(double d : probArray){
				probAllCorrect *= d;
			}
			double exKeepTyping = probAllCorrect*(allCount-typedCount+1) + (1-probAllCorrect)*(allCount-typedCount+1+allCount+1);
			double exQuitNow = (2 + allCount);
			
			double[] expected = new double[typedCount+1];
			expected[0] = exKeepTyping;
			expected[typedCount] = typedCount + allCount + 1;
			for(int i = 1; i < typedCount; i++){
				double tempEx = 1;
				for(int j = 0; j <= i; j++){
					tempEx *= probArray[j];
				}
				tempEx = tempEx*(i + (allCount-typedCount + 1) + 1) + (1-tempEx)*(i + (allCount-typedCount + 1) + 1 + allCount + 1);
				expected[i] = tempEx;
			}
			
			ArrayList<Double> dubList = new ArrayList<Double>();
			for(double d : expected){
				dubList.add(d);
			}
			dubList.add(exQuitNow);
			
			System.out.println(dubList);
			
			Collections.sort(dubList);
			
			double ans = dubList.get(0);
			
//			double value = Double.valueOf(String.format(Locale.US, "%1$.6f", ans));
			
			DecimalFormat roundFormatter = new DecimalFormat("0.00000");

			
			out.write("Case #" + currentCase + ": " + Double.parseDouble(roundFormatter.format(ans)));
			out.newLine();
		}
		
		out.close();
		
	}

}
