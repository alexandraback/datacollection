import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

public class PartElf {

	public static void main(String[] args) {
		Map<Integer, Double> caseInput = new HashMap<Integer, Double>();
		try {
			getInput(caseInput);
			for (int caseNo = 1; caseNo <= caseInput.size(); caseNo++) {
				solveCase(caseInput.get(caseNo), caseNo);
			}

		} catch (IOException e) {
			e.printStackTrace();
		}
		System.out.println();

	}


	private static void solveCase(Double double1, int caseNo) {

		int elfgeneration = noOfGen(double1, 40);
		
		if (elfgeneration == 0) {
			System.out.println("Case #" + caseNo + ": " + "impossible");
		} else {
			System.out.println("Case #" + caseNo + ": " + elfgeneration);
		}
	}


	private static int noOfGen(Double double1, int maxNoOfGen) {
		int elfgeneration =0;
		double test = double1;
		for(int i=0;i<maxNoOfGen;i++){
			if (test>=1){
				if (isValid(test, maxNoOfGen-i)){
					if (i==0){
						elfgeneration = 1;
					}else{
						elfgeneration = i;
					}
					break;
				}else{
					break;
				}
				
			}else{
				test = test*2;
			}
		}
		return elfgeneration;
	}

	private static boolean isValid(double test, int maxNoOfGen) {
		if(test == 1){
			return true;
		}
		double test2 = test-1;
		//return ((1/test2)%2 == 0) && (noOfGen(test2, maxNoOfGen) != 0);
		return (noOfGen(test2, maxNoOfGen) != 0);
	}


	private static void getInput(Map<Integer, Double> caseInput) throws IOException {

		BufferedReader reader = new BufferedReader(new FileReader(
				"F:\\sahil\\syncronized\\xory etc\\code jam\\A-small-attempt1.in"));
		String line = null;

		line = reader.readLine();
		int noOfCases = Integer.parseInt(line);
		int caseNumber = 1;

		while ((line = reader.readLine()) != null && caseNumber <= noOfCases) {
			String[] fraction  = line.toString().split("/");
			double value = Double.parseDouble(fraction[0])/Double.parseDouble(fraction[1]);
			caseInput.put(caseNumber, value);
			caseNumber++;
		}

		reader.close();
	}
}
