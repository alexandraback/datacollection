package round_1a;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

public class ManageYourEnergy {

	private static final File input = new File("round_1a/B-large.in");
	private static final File output = new File("round_1a/B-large.out");

	public static void main(String[] args) throws FileNotFoundException {
		Scanner scan = new Scanner(input);
		PrintStream out = new PrintStream(output);
		
		int cases = scan.nextInt();
		
		for(int cs = 1; cs <= cases; cs++){
			long maxEnergy = scan.nextLong();
			long regen = scan.nextLong();
			long[] acts = new long[scan.nextInt()];
			for(int i = 0; i<acts.length; i++)
				acts[i] = scan.nextInt();
			
			out.println("Case #" + cs + ": " + maxGain(maxEnergy, regen, acts));
		}

		scan.close();
		out.close();
	}
	
	static long maxGain(long maxEnergy, long regen, long[] acts){
		long[] energySpent = new long[acts.length];
		long totalGain = acts[0] * maxEnergy;
		energySpent[0] = maxEnergy;
		
		for(int i=1; i<acts.length; i++){
			long energy = regen;
			
			for(int j=i-1; j>=0; j--){
				if(acts[j] >= acts[i])
					break;
				long diff = maxEnergy - energy;
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
