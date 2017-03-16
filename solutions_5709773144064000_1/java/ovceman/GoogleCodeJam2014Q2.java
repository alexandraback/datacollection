import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigDecimal;
import java.util.ArrayList;


public class GoogleCodeJam2014Q2 {

	ArrayList<String> inputLines = new ArrayList<String>();
	ArrayList<String> outputLines = new ArrayList<String>();
	private static final String PATH ="/Users/koichisakumoto/Documents/GoogleCodeJam/";
	
	public static void main(String[] args) {
		GoogleCodeJam2014Q2 inst = new GoogleCodeJam2014Q2();
		inst.getLines(PATH + "Q2/B-large.in.txt");
		inst.solveProblem();
		inst.putLines(PATH + "Q2/answer2.txt");
	}

	private void solveProblem(){
		int currentLine = 0;
		int totalNum = Integer.parseInt(inputLines.get(currentLine++));
		
		for (int problemNum = 1; problemNum <= totalNum; problemNum++ ) {
			
			// input problem
			String[] cfx = inputLines.get(currentLine++).split(" ");
			final double c = Double.parseDouble(cfx[0]);
			final double f = Double.parseDouble(cfx[1]);
			final double x = Double.parseDouble(cfx[2]);

			// solve problem
			double min = x/2;
			final long limit = 100000000;
			double sum = 0;
			double tmp = 0.5;
			for (long n = 1; n < limit; n++){
				sum += c * tmp;
				tmp = 1 / (2 + n*f);
				double candidate = sum + x * tmp;
				if ( candidate < min ){
					min = candidate;
				}
			}

			// make answer
			BigDecimal bd = new BigDecimal(min);
			double answer = bd.setScale(7, BigDecimal.ROUND_HALF_UP).doubleValue();
			outputLines.add("Case #" + problemNum + ": " + answer);
		}
	}
	
	private void getLines(String fileName){
		try {
            FileReader in = new FileReader(fileName);
            BufferedReader br = new BufferedReader(in);
            String line;
            while ((line = br.readLine()) != null) {
            	inputLines.add(line);
            }
            br.close();
            in.close();
        } catch (IOException e) {
            System.out.println(e);
        }
	}
	
	private void putLines(String fileName){
		try {
			FileWriter out = new FileWriter(fileName); // new file
			BufferedWriter bw = new BufferedWriter(out);
            for ( String line : outputLines ){
            	bw.write(line + "\r\n");
            }
            bw.close();
            out.close();
        } catch (IOException e) {
            System.out.println(e);
        }
	}
	
}
