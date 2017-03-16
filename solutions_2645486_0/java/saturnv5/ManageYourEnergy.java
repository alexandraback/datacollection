package round_1a;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

public class ManageYourEnergy {

	private static final File input = new File("round_1a/B-small.in");
	private static final File output = new File("round_1a/B-small.out");

	public static void main(String[] args) throws FileNotFoundException {
		Scanner scan = new Scanner(input);
		PrintStream out = new PrintStream(output);
		
		int cases = scan.nextInt();
		
		for(int cs = 1; cs <= cases; cs++){
			int maxEnergy = scan.nextInt();
			int regen = scan.nextInt();
			int[] acts = new int[scan.nextInt()];
			for(int i = 0; i<acts.length; i++)
				acts[i] = scan.nextInt();
			
			out.println("Case #" + cs + ": " + maxGain(maxEnergy, regen, acts));
		}

		scan.close();
		out.close();
	}
	
	static long maxGain(int maxEnergy, int regen, int[] acts){
		int[] energySpent = new int[acts.length];
		long totalGain = acts[0] * maxEnergy;
		energySpent[0] = maxEnergy;
		
		for(int i=1; i<acts.length; i++){
			int energy = regen;
			
			for(int j=i-1; j>=0; j--){
				if(acts[j] >= acts[i])
					break;
				int diff = maxEnergy - energy;
				if(diff == 0)
					break;
				if(energySpent[j] > diff){
					energySpent[j] -= diff;
					totalGain -= acts[j] * diff;
					energy = maxEnergy;
					break;
				} else{
					energy += energySpent[j];
					totalGain -= acts[j] * energySpent[j];
					energySpent[j] = 0;
				}
			}
			
			energySpent[i] = energy;
			totalGain += energy * acts[i];
		}
		
		return totalGain;
	}
}
