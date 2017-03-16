import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintStream;
import java.io.PrintWriter;

public class User {

	private static final String FILENAME = "A-large.in";
	private static final String OUTFILENAME = FILENAME.substring(0,FILENAME.lastIndexOf("."))+".out";
	public static String newline = System.getProperty("line.separator");

	public static void main(String[] args) throws Exception {
		
		PrintWriter out = new PrintWriter(new FileWriter(OUTFILENAME));
	//	PrintStream out = System.out;
		
		FileReader fr = null;
		try {
			fr = new FileReader(FILENAME);
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		BufferedReader input = new BufferedReader(fr);
		
		int T = Integer.parseInt(input.readLine());
		
		for (int t=1; t<=T; t++){
			String[] line = input.readLine().split(" ");
			int A = Integer.parseInt(line[0]);
			int B = Integer.parseInt(line[1]);
			
			float expEnter = (1+B+1);
			//System.out.println("Enter avg: "+expEnter);
			float optTries = expEnter;
			
			line = input.readLine().split(" ");
			float[] p = new float[B];
			int j=0;
			for (String s: line){
				p[j++]=Float.parseFloat(s);
			}
			
			float probAllCorrect = 1;
			for (int k=0; k<A; k++){
				probAllCorrect *= p[k];
			}
			//System.out.println("probAllCorrect: "+probAllCorrect);
			float expContinue = ((B-A+1)*probAllCorrect)+((B-A+1+B+1)*(1-probAllCorrect));
			//System.out.println("Continue avg: "+expContinue);
			optTries = Math.min(expContinue, optTries);
			

			
			float[] backSpaceWorked = new float[A+1];
			backSpaceWorked[0] = -1;
			for (int k=1; k<=A; k++){
				backSpaceWorked[k]=1;
				for (int l=0; l<A-k; l++){
					backSpaceWorked[k] *= (p[l]);
				}
			}
			
			float[] expBackSpace = new float[A+1];
			expBackSpace[0] = -1;
			for (int k=1; k<=A; k++){
				expBackSpace[k]= ((k+k+(B-A)+1)*backSpaceWorked[k])+((k+k+(B-A)+1+B+1)*(1-backSpaceWorked[k]));
			//	System.out.println("Backspaceworked for "+k+": "+backSpaceWorked[k]);
			//	System.out.println("Backspace avg for "+k+": "+expBackSpace[k]);
				optTries = Math.min(expBackSpace[k], optTries);
			}
			
			out.format("Case #%d: %.6f %n",t,optTries);
			
			
		}
		out.close();
		
	}
}
	