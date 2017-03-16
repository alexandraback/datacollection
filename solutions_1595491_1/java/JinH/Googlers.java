import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

/* Jin Hao Chong
 * Google Code Jam 2012 Qualification Round Question 2
 * In this program, I used the Java standard library of java.io;
 */
public class Googlers {
	public static void main(String args[]){
		BufferedReader in = null;
		BufferedWriter out = null;

		try{
			//input and output
			in = new BufferedReader(new FileReader("B-large.in"));
			out = new BufferedWriter(new FileWriter("Output.txt"));
			
			int totalround, round, total;
			String read, output;
			String[] split;
			int[] numbers;
			
			//get rounds
			read = in.readLine();
			round = Integer.parseInt(read);
			totalround = round;
			
			//Calculation
			while(round > 0){
				output = "Case #" + (totalround - round + 1) + ": ";
				read = in.readLine();
				split = read.split(" ");
				numbers = new int[split.length];
				
				for(int i = 0; i < split.length; i++){
					numbers[i] = Integer.parseInt(split[i]);
				}
				
				int noSurpriseScore = (numbers[2] * 3) - 2;
				int surpriseScore = noSurpriseScore - 2;				
				
				if(surpriseScore < 0){
					surpriseScore = 0;
				}
				
				if(noSurpriseScore < 1){
					total = numbers[0];
				}
				else{

					int noSurprise = 0;
					int surprise = 0;

					for(int i = 3; i < numbers.length; i++){
						if(numbers[i] >= numbers[2]){
							if(numbers[i] >= noSurpriseScore)
								noSurprise++;
							else if(numbers[i] >= surpriseScore)
								surprise++;
						}
					}

					if(surprise > numbers[1])
						surprise = numbers[1];

					total = noSurprise + surprise;

					if(total > numbers[0])
						total = numbers[0];
				}
				
				output += total;
				
				//write output to file
				out.write(output);
				if(round != 1) out.newLine();
				round--;
			}
			in.close();
			out.close();
		}catch(Exception e){
			System.err.print(e);
		}
	}
}
