import java.io.File;
import java.io.FileWriter;
import java.util.Arrays;
import java.util.Scanner;


public class Round1BA {
	
	public static long getNumberMods(long size, int index, long[] motes, long numberMods) {
		while (index < motes.length) {
			while (index < motes.length && size > motes[index]) {
				size += motes[index];
				index++;
			}
			if (index < motes.length) {
				return numberMods + Math.min(getNumberMods(size, index+1, motes, 1), getNumberMods((size+size-1), index, motes, 1));
			}
		}
		return numberMods;
	}

	public static void main(String[] args) {
		try {
			Scanner fileReader = new Scanner(new File("A-small-attempt0.in"));
			FileWriter fileWriter = new FileWriter(new File("output2.txt"));

			long numTestCases = fileReader.nextInt();
			for (long i=0; i<numTestCases; ++i) {
				long initialSize = fileReader.nextInt();
				int numMotes = fileReader.nextInt();
				long[] motes = new long[numMotes];
				for (int j=0; j<numMotes; ++j)
					motes[j] = fileReader.nextInt();
				long numChanges = 0;
				if (initialSize == 1) {
					numChanges = numMotes;
				}
				else {
					Arrays.sort(motes);
					numChanges = getNumberMods(initialSize, 0, motes, 0);
				}
				System.out.println("Solved " + (i+1));
				fileWriter.write("Case #" + (i+1) + ": " + /* output goes here */numChanges + "\n");
			}
			fileWriter.flush();
			fileWriter.close();
		}
		catch (Exception e) {

		}
	}
}
