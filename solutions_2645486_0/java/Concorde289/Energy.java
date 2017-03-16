import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class Energy {

	public static void main (String [] args) throws IOException{

		//Timing
		//long s = System.currentTimeMillis ();

		//Set up the reader and printer
		BufferedReader in = new BufferedReader (new FileReader ("IN.txt"));
		PrintWriter out = new PrintWriter (new BufferedWriter (new FileWriter ("OUT.txt")));
		int noCases = Integer.parseInt(in.readLine());
		
		//Solve the cases
		for (int caseNo = 1; caseNo <= noCases; caseNo++){
			String [] input = in.readLine().split(" ");
			noOfEnergy = Integer.parseInt(input[0]);
			regenAmount = Integer.parseInt(input[1]);
			noAct = Integer.parseInt(input[2]);
			String [] ints = in.readLine().split(" ");
			acts = new int [noAct];
			for (int i = 0; i < noAct; i++)
				acts[i] = Integer.parseInt(ints[i]);
			String answer = getAnswer();
			out.println(String.format("Case #%d: %s", caseNo, answer));
			out.flush();//So I can see how my program is doing
		}

		//Close the files
		in.close();
		out.close();

		//Timing
		//long e = System.currentTimeMillis();
		//System.out.println((e - s) / 1000.0);

		//Terminate the program
		System.exit(0);

	} //Main method
	
	static String getAnswer(){
		maxValue = 0;
		planDay(0, noOfEnergy, 0);
		return String.valueOf(maxValue);
	}
	static int maxValue;
	static int noOfEnergy;
	static int regenAmount;
	static int noAct;
	static int [] acts;
	
	static void planDay(int value, int currentEnergy, int pos)
	{
		if (pos == noAct){
			if (value > maxValue)
				maxValue = value;
			return;
		}
		for (int amount = 0; amount <= currentEnergy; amount++){
			int newEnergy = currentEnergy-amount+regenAmount;
			if (newEnergy > noOfEnergy)
				newEnergy = noOfEnergy;
			planDay(value+amount * acts[pos], newEnergy, pos+1);
		}
	}
}
