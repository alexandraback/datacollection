import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;

/* Jin Hao Chong
 * Google Code Jam 2012 Qualification Round Question 3
 * In this program, I used the Java standard library of java.io and java.util;
 */
public class RecycledNumbers {
	public static void main(String args[]){
		BufferedReader in = null;
		BufferedWriter out = null;

		try{
			//input and output
			in = new BufferedReader(new FileReader("C-large.in"));
			out = new BufferedWriter(new FileWriter("Output.txt"));
			
			int totalround, round, total, integerA, integerB;
			String read, output;
			String[] split;
			
			//get rounds
			read = in.readLine();
			round = Integer.parseInt(read);
			totalround = round;
			
			//Calculation
			while(round > 0){
				output = "Case #" + (totalround - round + 1) + ": ";
				read = in.readLine();
				split = read.split(" ");
								
				integerA = Integer.parseInt(split[0]);
				integerB = Integer.parseInt(split[1]);
				
				total = 0;
				
				//try every possibility
				for(int i = integerA; i < integerB; i++){
					String num = Integer.toString(i);
					ArrayList<Integer> array = new ArrayList<Integer>();
					//try to move digits from back to front
					for(int j = 1; j < num.length(); j++){
						String front = num.substring(0, j);
						String back = num.substring(j);
						back += front;
						int compare = Integer.parseInt(back);
						//check if the digit after moved falls in range
						if((!array.contains(compare)) && (compare > i) && (compare <= integerB)){
							array.add(compare);
							total++;
						}
					}
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
