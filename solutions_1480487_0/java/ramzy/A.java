import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;
import java.text.DecimalFormat;


public class A {

	public static void main(String[] args) throws Exception {
		BufferedReader input = new BufferedReader(new FileReader("src/A.in"));
		PrintWriter output = new PrintWriter("src/A.out");
		
		String line = input.readLine();
		int T = Integer.valueOf(line);
		for(int t = 1; t <= T; t++) {
			line = input.readLine();
			String[] stringArray = line.split(" ");
			int n = Integer.valueOf(stringArray[0]);
			int[] intArray = new int[n];
			double sum = 0;
			for(int i = 1; i < n+1; i++) {
				intArray[i-1] = Integer.valueOf(stringArray[i]);
				sum += intArray[i-1];
			}
		
			double[] result = new double[n];
			double needed = 2.0/n;
			
			for(int i =0; i < n; i++) {
				double per = ((double)intArray[i]) / sum;
				result[i] = needed - per;
			}
			
			
			String outputLine = "Case #" + t + ":";
			for(double num : result) {
				if(num < 0) {
					outputLine += " 0.000000";
				} else {
			        DecimalFormat df = new DecimalFormat("0.00000#");
					outputLine += " " + df.format(num*100);
				}				
			}
			output.println(outputLine);
			System.out.println(outputLine);
		}
		input.close();
		output.close();
	}
	
	static int[] intArray(String line) {
		String[] stringArray = line.split(" ");
		int[] intArray = new int[stringArray.length];
		for(int i = 0; i < stringArray.length; i++) {
			intArray[i] = Integer.valueOf(intArray[i]);
		}
		return intArray;
	}
}
