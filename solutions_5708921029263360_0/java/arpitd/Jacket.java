import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;

public class Jacket {

	public static void main(String[] args) throws NumberFormatException, IOException {
		
		FileInputStream file = new FileInputStream("D:\\Work\\Resources\\CodeJam2016\\Personal\\C-small-attempt0.in");
		InputStreamReader reader = new InputStreamReader(file);
		BufferedReader br = new BufferedReader(reader);
		String strLine = "";
		double numberOfTestCases = Double.parseDouble(br.readLine());
		for(int testCaseCounter = 1;testCaseCounter<=numberOfTestCases;testCaseCounter++){
			String output = "Case #" + testCaseCounter + ": ";
			String inputLine = br.readLine();
			int j = Integer.parseInt(inputLine.split(" ")[0]);
			int p = Integer.parseInt(inputLine.split(" ")[1]);
			int s = Integer.parseInt(inputLine.split(" ")[2]);
			int k = Integer.parseInt(inputLine.split(" ")[3]);
			int nativeResult = j * p * s;
			int modiResult = j * p * k;
			int possibleCases = getMin(nativeResult,modiResult);
			output = output + possibleCases;
			int outputCounter = 1;
			if(possibleCases == nativeResult){
				
				for (int x = 1;x<=j;x++){
					for(int y=1;y<=p;y++){
						for(int z=1;z<=s;z++){
							output = output + "\n" + x + " " + y + " " + z;
						}
					}
				}
			}
			else{
				for (int x = 1;x<=j;x++){
					for(int y=1;y<=p;y++){
						for(int z=1;z<=k;z++){
							output = output + "\n" + x + " " + y + " " + z;
						}
					}
				}
			}
			System.out.println(output);
		}
	}
	
	private static int getMin(int i , int j){
		if (i<j)
			return i;
		return j;
	}
}
