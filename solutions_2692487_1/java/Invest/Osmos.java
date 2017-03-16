import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class Osmos {

	private int getMinMoves(int mote, int[] motes) {
		if (mote == 1) return motes.length;
		Arrays.sort(motes);
		
		int res = motes.length;
		for (int i = 0; i < motes.length; i++) {
			int curSize = mote;
			int tempRes = i;
			
			for (int j = 0; j < motes.length - i; j++) {
				while (motes[j] >= curSize) {
					curSize += curSize - 1;
					tempRes++;
				}
				curSize += motes[j];
			}
			
			res = Math.min(res, tempRes);
		}
		
		return res;
	}
	
	public static final String INPUT_FILE_PATH = "C://DiskD//CodeJamInput.txt";
	public static final String OUTPUT_FILE_PATH = "C://DiskD//CodeJamOutput.txt";

	public static void main(String[] args) {
		Scanner in = null;
		PrintWriter writer = null;
		try {
			System.out.println("start");

			in = new Scanner(new File(INPUT_FILE_PATH));
			writer = new PrintWriter(new FileWriter(OUTPUT_FILE_PATH));
			int testCount = in.nextInt();

			for (int i = 0; i < testCount; i++) {
				int mote = in.nextInt();
				int[] motes = new int[in.nextInt()];
				for (int j = 0; j < motes.length; j++) {
					motes[j] = in.nextInt();
				}
				
				System.out.println(i);
				writer.println("Case #" + (i + 1) + ": " + new Osmos().getMinMoves(mote, motes));
			}
			writer.flush();

			System.out.println("end");
		} catch (IOException ex) {
			ex.printStackTrace();
		} finally {
			if (in != null) in.close();
			if (writer != null) writer.close();
		}
	}

}
