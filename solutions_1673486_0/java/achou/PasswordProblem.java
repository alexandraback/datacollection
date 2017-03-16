import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;


public class PasswordProblem {

	public static void main(String[] args){
		double[] prob;
		prob= new double[3];
		prob[0] =  1;
		prob[1] = 0.9;
		prob[2] = 0.1;
		try{
			// Open the file that is the first 
			// command line parameter
			FileInputStream fstream = new FileInputStream(args[0]);
			// Get the object of DataInputStream
			DataInputStream in = new DataInputStream(fstream);
			BufferedReader br = new BufferedReader(new InputStreamReader(in));
			String strLine;
			//Read File Line By Line
			int numTest = Integer.parseInt(br.readLine());
			for(int i = 0; i < numTest; i ++){
				String str = br.readLine();
				String numbers[] = str.split(" ");
				String str2 = br.readLine();
				String probs[] = str2.split(" ");
				ArrayList<Double> probsDouble = new ArrayList<Double>();
				for(String s : probs){
					probsDouble.add(new Double(Double.parseDouble(s)));
				}
				double ans = calculatePasswordProbability(Integer.parseInt(numbers[0]),Integer.parseInt(numbers[1]), probsDouble);
				/*for(int index = 0; index < stringArray.length; index++){
					char c = (Character) hm.get(stringArray[index]);
					stringArray[index] = c;
				}
				String finalString = new String(stringArray);*/
				int x = i + 1;
				System.out.println("Case #" + x + ": " + ans);
				
			}
			//Close the input stream
			in.close();
		}catch (Exception e){//Catch exception if any
			System.err.println("Error: " + e.getMessage());
		}
		
	}
	
	
	public static double calculatePasswordProbability(int enteredLetters, int totalLetters, ArrayList<Double> probability){
		Object obj[] = probability.toArray();
		int remainingLetters = totalLetters - enteredLetters;
		int extraLetters = remainingLetters + 1 + totalLetters;
		/*ArrayList<Integer> probabilityList = new ArrayList<Integer>();
		for(int i = 0; i < enteredLetters; i ++){
			int p = 1;
			int k = 0;
			for (k = 0; k < i; k++){
				p= p*probability[k];
			}
			for(int l = k; l < enteredLetters; l++){
				p = p*(1-probability[k]);
			}
			System.out.println();
		}*/
		
		int enterRightAway = totalLetters + 2;
		//System.out.println("press enter immediately - " + enterRightAway);
		double min = enterRightAway;
		ArrayList<Integer> expectedList = new ArrayList<Integer>();
		int count = 0;
		for(int i = enteredLetters; i >1; i -- ){
			count++;
			double p =1;
			for(int k = 0; k < i - 1; k ++){
				p = p*(Double)obj[k];
			}
			if(count == enteredLetters){
				/*p = p*(remainingLetters + 1) + (1-p)*(remainingLetters + 2 + 2*count);
				System.out.println(p);*/
			}
			else{
				p = p*(remainingLetters + 1 + 2*(count)) + (1-p)*(remainingLetters + 2 + 2*(count) + totalLetters);
				if(p<min)
					min = p;
			}
			//System.out.println("pressing " + count + "back - " + p);
		}
		int allBack = enteredLetters*2 + remainingLetters + 1;
		if(allBack < min)
			min = allBack;
		//System.out.println("pressing " + enteredLetters + "back - " + allBack);
		double p = 1;
		for(int k = 0; k < enteredLetters; k ++){
			p = p*(Double)obj[k];
		}
		p = p*(remainingLetters + 1) + (1-p)*(remainingLetters + 2 + totalLetters);
		if(p<min)
			min = p;
		//System.out.println("continue typing - "  + p);
		return min;
	}
}
