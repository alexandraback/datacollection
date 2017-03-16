import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.text.DecimalFormat;


public class TaskB {
	
	private BufferedReader br;
	private BufferedWriter bw;
	
	public static void main(String args[]) throws IOException {
		System.out.println("Task B");
		System.out.println(System.getProperty("user.dir"));
		//TaskB taskB = new TaskB("A-small-attempt0.in","out.txt");
		TaskB taskB = new TaskB("B-large.in","out.txt");
		
		
		try {
			
		    int numOfTestCases = taskB.readNumOfTestCases();
		    for (int i = 1; i <= numOfTestCases; i++) {
		    	double[] params = taskB.readCFX();
		    	double C = params[0];
		    	double F = params[1];
		    	double X = params[2];
		    	double result = taskB.process(C,F,X);
		    	DecimalFormat df = new DecimalFormat("#.#######");
		    	taskB.writeALine("Case #" + i+": " + df.format(result));
		    }

		     //   while (line != null) {
		     //   }
		}
		finally {
			taskB.closeRead();
		}
		        
	}
	
	public TaskB(String inputFile, String outputFile) throws IOException {
		
		br = new BufferedReader(new FileReader(inputFile));
		bw = new BufferedWriter(new FileWriter(outputFile));
	}
	
	public void closeRead() throws IOException{
		br.close();
		bw.close();
	}
	
	private int readNumOfTestCases() throws NumberFormatException, IOException{
		return Integer.valueOf(br.readLine());
	}
	
/*	private int readInput() throws NumberFormatException, IOException{
		return Integer.valueOf(br.readLine());
	}
*/	
	private double[] readCFX() throws IOException{
		double[] result = new double[3];
		String[] resultStr = br.readLine().split("\\s+");
		for (int j = 0; j < 3; j++) {
			result[j] = Double.valueOf(resultStr[j]);
		}
		return result;
	}
	
	private double process(double C, double F, double X){
		double rate = 2.0;
		double total=0;
		while (true){
			total += C/rate;
			double waitTime = (X-C)/rate;
			double buyTime = X/(rate + F);
			if (waitTime < buyTime) { //have result
				return total + waitTime;
			}
			else {
				rate += F;
			}
		}
		
		
		
	}
	
	private void writeALine(String str) throws IOException {
		bw.write(str);
		bw.newLine();
	}

}
