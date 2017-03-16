import java.io.IOException;
import java.io.BufferedReader;
import java.io.FileReader;
import java.util.StringTokenizer;
import java.util.Hashtable;
import java.util.Arrays;

class Triplet {
	public int first;
	public int second;
	public int third;
	
	public Triplet(int one, int two, int three) {
		first = one;
		second = two;
		third = three;
	}
	
	public boolean isSurprising() {
		if ((Math.abs(third - second) == 2) || (Math.abs(second - first) == 2)
				||(Math.abs(third - first) == 2)) {
			return true;
		} else {
			return false;
		}
	}
	
	public int getMax() {
		return Math.max(first, Math.max(second, third));
	}
	
	public String print() {
		return first + " " + second + " " + third;
	}
}

public class Dancers {
	
	private static Triplet getCombo1(int number) {
		int remainder = number % 3;
		if (remainder == 0) {
			return new Triplet(number/3,number/3, number/3);
		} else {
			int first = (number + (3 - remainder)) / 3;
			int second = first - 1;
			int third = number - first - second;
			return new Triplet(first, second, third);
		}
	}
	
	private static Triplet getCombo2(int number) {
		int remainder = number % 3;
		int first, second, third;
		if (remainder == 0) {
			first = (number / 3) + 1;
			second = first - 1;
			third = number - first - second;

		} else {
			first = (number - remainder) / 3;
			second = first - 1;
			third = number - first - second;
		}
		if (second < 0) {
			second++;
			first--;
		}
		if (third < 0) {
			first--;
			third++;
		}
		if (first < 0) { 
			first++; third--;
		}
		if (third - second > 2) {
			second++; third--;
		}
		if (first > 10) {
			first--; second++;
		}
		if (second > 10) {
			second --; third++;
		}
		if (third > 10) {
			third--;second++;
		}
		return new Triplet(first, second, third);
	}
	
	public static void main(String[] args) throws IOException{
		Triplet[] combo1 = new Triplet[31];
		Triplet[] combo2 = new Triplet[31];
		
		for (int i=0;i<=30;i++) {
			//System.out.print("i: " + i);
			combo1[i] = getCombo1(i);
			//System.out.println(" " + combo1[i] .print());
			//System.out.print("i: " + i);
			combo2[i] = getCombo2(i);
			//System.out.println(" " + combo2[i] .print());
		}
		if (args.length != 1) {
			System.out.println("Error: incorrect number of arguments.");
			System.out.println("Usage: Dancers <input-filename>");
		} else {
			BufferedReader inputStream = null;
			try {
				 inputStream = new BufferedReader(new FileReader(args[0]));
				 int totalCases = Integer.valueOf(inputStream.readLine()).intValue();
				 //System.out.println("Total number of cases is: "+totalCases);
				 for (int i=0;i<totalCases;i++) {
					int outputCount = 0;
					System.out.print("Case #"+(i+1)+": ");
					String numbersLine = inputStream.readLine();
					//System.out.println("Numbers line is: "+numbersLine);
					String[] theNumbers = numbersLine.split(" ");
					int numGooglers = Integer.valueOf(theNumbers[0]);
					//System.out.println("Number of googlers " + numGooglers);
					int numSurprises = Integer.valueOf(theNumbers[1]);
					//System.out.println("Number of surprises " + numSurprises);
					int bestReqd = Integer.valueOf(theNumbers[2]);
					//System.out.println("Best required " + bestReqd);
					int output = 0;
					for (int j=0;j<numGooglers; j++) {
						//System.out.println("Googler " + (j+1) + " score " + theNumbers[3+j]);
						Triplet googCombo1 = combo1[Integer.valueOf(theNumbers[3+j])];
						Triplet googCombo2 = combo2[Integer.valueOf(theNumbers[3+j])];
						//System.out.println("Max from googComb1 is " + googCombo1.getMax());
						//System.out.println("Max from googComb2 is " + googCombo2.getMax());
						if (googCombo1.getMax()>=bestReqd && !googCombo1.isSurprising()) {
							output++;
						} else if (googCombo2.getMax()>=bestReqd && !googCombo2.isSurprising()) {
							output++;
							break;
						} else if (googCombo2.getMax()>=bestReqd && googCombo2.isSurprising() && numSurprises>0) {
							output++;
							numSurprises--;
						}
					}
					//System.out.println("*** Answer is " + output + "****");
					System.out.println(output);
					//System.out.println("**********************************");
				 }
			} catch (IOException e) {
				System.out.println("Error in reading file");
			} finally {
				if (inputStream != null) {
					inputStream.close();
				}
			}
			
		}
	}
}