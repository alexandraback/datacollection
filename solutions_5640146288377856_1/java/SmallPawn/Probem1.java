package p1;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Probem1 {

	static final String INPUT_FILE = "D:/Tech/A-large.in";
	static final String OUTPUT_FILE = "D:/Tech/A-large.ou";
	static final double y = Math.log10(2.0);

	/**
	 * @param args
	 */
	public static void main(String[] args) {/*
		int[] r = {1, 1, 2, 1, 1, 1};
		int[] c = {4, 7, 5, 6, 10,10};
		int[] w = {2, 7, 1, 5, 5, 3};
		for (int i = 0; i < r.length; i++)
			System.out.println("" + r[i] +", " + c[i] + ", " + w[i] + ": " + minAttempt(r[i],c[i],w[i]));
		*/
		
		BufferedReader br = null;
		int testCaseCount;
		try {
			String sCurrentLine;
			br = new BufferedReader(new FileReader(INPUT_FILE));
			File file = new File(OUTPUT_FILE);
 			// if file doesn't exists, then create it
			if (!file.exists()) {
				file.createNewFile();
			}
 			FileWriter fw = new FileWriter(file.getAbsoluteFile());
			BufferedWriter bw = new BufferedWriter(fw);
			
			sCurrentLine = br.readLine();
			testCaseCount = Integer.parseInt(sCurrentLine);
			
			for (int i = 0; i < testCaseCount; i++)
			{
				sCurrentLine = br.readLine();
				String[] s = sCurrentLine.split(" ");
				int r = Integer.parseInt(s[0]);
				int c = Integer.parseInt(s[1]);
				int w = Integer.parseInt(s[2]);
				
				int count = minAttempt(r, c, w);
				bw.write("Case #" + (i+1) + ": " + count + "\r\n");
			}
			bw.close();
			
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			try {
				if (br != null)br.close();
			} catch (IOException ex) {
				ex.printStackTrace();
			}
		}
	}

	private static int minAttempt(int r, int c, int w)
	{
		int findFirstHit = r * (c / w);
		int remainingHits = w - 1;
		if (c%w != 0 && w > 1) remainingHits++;
		/*
		int remainder = c % w;
		int wrongAttemptsAfterFirstHit = 0;
		if (remainder != 0)
		{
			double x = Math.log10(1 + c % w);
			wrongAttemptsAfterFirstHit = (int)(x / y);
		}
		double z = Math.log10(w);
		int wrongAttemptsAlternative = (int) (z / y);
		if (c > w && wrongAttemptsAlternative > wrongAttemptsAfterFirstHit + 1)
		{
			wrongAttemptsAfterFirstHit = wrongAttemptsAlternative - 1;
		}
		
		return (findFirstHit + remainingHits + wrongAttemptsAfterFirstHit);
		*/
		return (findFirstHit + remainingHits);
	}
}
