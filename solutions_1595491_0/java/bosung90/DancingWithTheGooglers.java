import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class DancingWithTheGooglers {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub

		int testCaseNumber;

		String input;
		BufferedReader in = new BufferedReader(new FileReader("B-small-attempt0.in"));
		input = in.readLine();

		testCaseNumber = Integer.parseInt(input.trim());

		int[] totalScoreArray = new int[testCaseNumber];

		for(int i=0; i<testCaseNumber; i++){
			input = in.readLine();
			String[] dataArrayString = input.split(" ");

			int[] dataArray = new int[dataArrayString.length];
			for(int z=0;z<dataArrayString.length; z++){
				dataArray[z] = Integer.parseInt(dataArrayString[z]);
			}


			int googlerNum = dataArray[0];
			int surprisingNum = dataArray[1];
			int minPeakScore = dataArray[2];

			int score = 0;
			int minNos;
			int minS;
			if(minPeakScore<=1){
				minNos = minPeakScore;
				minS = minPeakScore;
			}
			else{
				minNos = (minPeakScore*3)-2;
				minS = (minPeakScore*3)-4;
			}
			for(int j=3; j<googlerNum+3; j++){
				
				if(dataArray[j]>=minNos){
					score++;
				}
				else if(surprisingNum>0 && dataArray[j]>=minS){
					score++;
					surprisingNum--;
				}
			}
			System.out.println(score);
			totalScoreArray[i] = score;
		}


		in.close();

		FileWriter fstream = new FileWriter("B-small-attempt0.out");
		BufferedWriter out = new BufferedWriter(fstream);

		for(int i=1; i<=testCaseNumber;i++){
			String outLine = "Case #"+i+": "+totalScoreArray[i-1]+"\n";
			out.write(outLine);
		}
		out.close();
		System.out.println("File created successfully.");

	}

}

