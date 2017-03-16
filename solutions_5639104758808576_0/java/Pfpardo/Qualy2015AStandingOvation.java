import java.io.*;

public class Qualy2015AStandingOvation {

	enum ProblemType{SAMPLE,SMALL,LARGE};
	private static final double COOKIES_PER_SECOND = 2.0;
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		String roundPrefix = "Qualy2015";
		String problem = "A";
		ProblemType activeFile = ProblemType.SMALL;
		File file, outFile;
		String activeFileName;
		switch (activeFile) {
			case SAMPLE :
				activeFileName="sample";
				break;
			case SMALL:
				activeFileName="small-attempt0";
				break;
			case LARGE:
				activeFileName="large-practice";
				break;
			default:
				throw new RuntimeException("Problem type not supported");
		}
		 file = new File(String.format("files/%s/%s-%s.in",roundPrefix,problem,activeFileName));
		 outFile = new File(String.format("files/%s/%s-%s.out",roundPrefix,problem,activeFileName));
		

		 BufferedReader br = new BufferedReader(new FileReader(file));
		 BufferedWriter bw = new BufferedWriter(new FileWriter(outFile));
		 int testCases = Integer.parseInt(br.readLine());
		 
		 //Specific for the problem
		 String [] caseParameters; 
		 long result;
		 for(int t=1;t<=testCases;t++){
			 caseParameters = br.readLine().split(" ");
			 result = solveTestCase(Integer.parseInt(caseParameters[0]),caseParameters[1]);
			 StringBuilder caso = new StringBuilder();
			 caso.append("Case #");
			 caso.append(t);
			 caso.append(": ");
			 caso.append(result);
			 caso.append("\n");
			 bw.write(caso.toString());
		 }
		 br.close();
		 bw.close();

	}
	
	private static long solveTestCase(int sMax, String sIs){
		long sSum = 0;
		long requiredPeople = 0;
		for (int i = 0; i<=sMax;i++){
			sSum += Integer.parseInt(sIs.substring(i,i+1));
			if( (i+1) > sSum) {
				requiredPeople +=1;
				sSum +=1;
			}
		}
		return requiredPeople;
	}
}
