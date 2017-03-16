import java.io.File;
import java.io.FileWriter;
import java.util.Arrays;
import java.util.Scanner;


public class Round1BA {
	
	public static int getNumberMods(int size, int index, int[] motes, int numberMods) {
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
			FileWriter fileWriter = new FileWriter(new File("output.txt"));

			int numTestCases = fileReader.nextInt();
			for (int i=0; i<numTestCases; ++i) {
				int initialSize = fileReader.nextInt();
				int numMotes = fileReader.nextInt();
				int[] motes = new int[numMotes];
				for (int j=0; j<numMotes; ++j)
					motes[j] = fileReader.nextInt();
				int numChanges = 0;
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
