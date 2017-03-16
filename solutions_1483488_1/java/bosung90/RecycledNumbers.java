import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashSet;


public class RecycledNumbers {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		int testCaseNumber;

		String input;
		BufferedReader in = new BufferedReader(new FileReader("C-large.in"));
		input = in.readLine();

		testCaseNumber = Integer.parseInt(input.trim());
		int[] totalAccountArray = new int[testCaseNumber];

		for(int i=0; i<testCaseNumber; i++){

			input = in.readLine();

			String[] inputArray = input.split(" ");
			int A = Integer.parseInt(inputArray[0]);
			int B = Integer.parseInt(inputArray[1]);

			int count = 0;

			HashSet<String> hashSet = new HashSet<String>();
			
			
			
			for(int j=A;j<=B; j++){
				
				String num = String.valueOf(j);
				for(int k=1; k<num.length(); k++){
					String firstHalf = num.substring(0, k);
					String lastHalf = num.substring(k,num.length());

					String flipped = lastHalf+firstHalf;
					
					int flippedNum = Integer.parseInt(flipped);
					if(j>=flippedNum)
						continue;
					
					if(flippedNum>=A && flippedNum<=B){
						if(hashSet.contains(num+flippedNum)){
							//System.out.println("DUPLICATE!!: " +num+flippedNum);
							continue;
						}
						//System.out.println("counted: "+"original: "+num+" Flipped: "+flippedNum);
						count++;
						hashSet.add(num+flippedNum);
					}

				}

			}
			System.out.println(count);
			totalAccountArray[i] = count;
		}
		in.close();

		FileWriter fstream = new FileWriter("C-large.out");
		BufferedWriter out = new BufferedWriter(fstream);

		for(int i=1; i<=testCaseNumber;i++){
			String outLine = "Case #"+i+": "+totalAccountArray[i-1]+"\n";
			out.write(outLine);
		}
		out.close();
		System.out.println("File created successfully.");

	}

}

