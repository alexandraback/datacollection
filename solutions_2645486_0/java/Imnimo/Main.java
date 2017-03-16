import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;


public class Main {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner s = new Scanner(new File("input.txt"));
		int totalCases = Integer.parseInt(s.nextLine());
		for(int c = 1;c<=totalCases;c++) {
			String firstLine = s.nextLine();
			String secondLine = s.nextLine();
			String[] params = firstLine.split(" ");
			int max = Integer.parseInt(params[0]);
			int regain = Integer.parseInt(params[1]);
			int numActivities = Integer.parseInt(params[2]);
			String[] valStrings = secondLine.split(" ");
			int[] values = new int[numActivities];
			for(int i = 0;i<numActivities;i++) {
				values[i] = Integer.parseInt(valStrings[i]);
				
			}
			int best = solve(values,max,regain);
			System.out.println("Case #" + c + ": " + best);

		}
		
	}
	public static int solve(int[] values,int max, int regain) {
		int numActivities = values.length;
		int[][] gains = new int[numActivities][max+1];
		
		for(int i = numActivities-1;i>=0;i--) {
			for(int avail = 0;avail<=max;avail++) {
				if(i == numActivities-1) { 
					gains[i][avail] = values[i] * avail; 
				} else {
					int maxGain = 0;
					for(int spent = 0;spent<=avail;spent++) {
						int next = Math.min(avail-spent+regain,max);
						int gain = gains[i+1][next] + values[i]*spent;

						if(gain>maxGain) {
							maxGain = gain;
						}
					}

					gains[i][avail] = maxGain;
				}
				//System.out.println("If we arrive at activity " + i + " with " + avail + " left, we can get " + gains[i][avail]);
			}

		}
		int best = gains[0][max];

		return best;
	}
}
