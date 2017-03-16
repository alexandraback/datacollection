import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;


public class StandingOvation {

	public static void main(String[] args) throws Exception {
	       
		FileInputStream fstream = new FileInputStream("A-large.in");
		BufferedReader br = new BufferedReader(new InputStreamReader(fstream));

		PrintWriter writer = new PrintWriter("StandingOvation_result.txt", "UTF-8"); //result
		
		String strLine;
		strLine = br.readLine();
		int numCase = Integer.parseInt(strLine);
		
		for( int i = 0;i<numCase;i++){
			int sMax = 0;
			int[] numInLevel;
			strLine = br.readLine();
			String[] strArray = strLine.split(" ");
			sMax = Integer.parseInt(strArray[0]);
			numInLevel = new int[sMax+1];
			for(int j =0;j<=sMax;j++){
				numInLevel[j] = strArray[1].charAt(j)-'0';
			}
//			System.out.println(Arrays.toString(numInLevel));
			int result = worker(sMax, numInLevel);
			String result_str ="Case #"+(i+1)+": "+result; 
			writer.println(result_str);
			System.out.println(result_str);
		}
		

		//Close the input stream
		br.close();
		writer.close();
	}
	public static int worker(int sMax, int[] numInLevel){
		int result = 0;
		int sum = 0;
		
		int need = 0;
		for(int i = 0;i<sMax;i++){
			sum = sum + numInLevel[i];//people we have
			//for level i, we need i+1 people
			need = Math.max( (i+1) - sum , 0);
			result = result + need;
			sum = sum + need;
		}
		return result;
	}

}
