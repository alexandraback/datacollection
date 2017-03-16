import java.io.*;
import java.net.URL;
import java.util.*;;


public class ManageYourEnergy {
	private static Scanner reader;
	private static BufferedWriter writer;
	
	public static void main(String[] args) throws IOException {
		reader = new Scanner(new File(new URL(FairAndSquare.class.
				getResource("."), "../input/test.in").getPath()));
		writer = new BufferedWriter(new FileWriter(new URL(FairAndSquare.class.
				getResource("."), "../output/test.out").getPath()));
		
		int numOfCases = reader.nextInt();
		reader.nextLine();
		for(int c = 1; c <= numOfCases; c++){
			long e = reader.nextLong();
			long r = reader.nextLong();
			int n = reader.nextInt();
			int[] act = new int[n];
			for(int i = 0; i < n; i++)
				act[i] = reader.nextInt();
			
			long maxGain = gain(e, r, 0, n - 1, e, 0, act);
			
			System.out.println("Case #" + c + ": " + maxGain);
			writer.write("Case #" + c + ": " + maxGain + "\n");
		}
		reader.close();
		writer.close();
	}
	
	public static long gain(long e, long r, int start, int end,
			long startWith, long endWith, int[] act){
		if(start > end)
			return 0;
		
		int maxIndex = start;
		for(int i = start + 1; i <= end; i++)
			if(act[i] > act[maxIndex])
				maxIndex = i;
		
		long eAtMax = Math.min(startWith + (maxIndex - start) * r, e);
		long regainToEnd = r * (end - maxIndex);
		long canConsume = regainToEnd < endWith ? Math.max(0, eAtMax - (endWith - regainToEnd)) : 
			eAtMax;
		long thisGain = canConsume * act[maxIndex];
		
		return thisGain + gain(e, r, start, maxIndex - 1, startWith, eAtMax - r, act) +
				gain(e, r, maxIndex + 1, end, eAtMax - canConsume + r, endWith, act);
		
	}

}
