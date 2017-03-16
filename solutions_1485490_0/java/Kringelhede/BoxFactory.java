package codeJam2012_1C;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class BoxFactory {
	private String FILE_NAME = "1C-C-small-attempt0";
	private long[] boxCounts;
	private long[] boxTypes;
	private long[] toyCounts;
	private long[] toyTypes;
	
	private long solve(Scanner sc) {
		int boxes = sc.nextInt();
		int toys = sc.nextInt();
		
		boxCounts = new long[boxes];
		boxTypes = new long[boxes];
		for (int i=0;i<boxes;i++) {
			boxCounts[i] = sc.nextLong();
			boxTypes[i] = sc.nextLong();
		}
		
		toyCounts = new long[toys];
		toyTypes = new long[toys];
		for (int i=0;i<toys;i++) {
			toyCounts[i] = sc.nextLong();
			toyTypes[i] = sc.nextLong();
		}
		
		return getBoxedCount(0,0,0,0,0);
	}
	
	private long getBoxedCount(int boxIndex, int toyIndex, long boxUsed, long toyUsed, long boxed) {
		if (boxIndex>=boxTypes.length || toyIndex>=toyTypes.length)
			return boxed;
		
		if (boxTypes[boxIndex]==toyTypes[toyIndex]) {
			long count = Math.min(boxCounts[boxIndex]-boxUsed, toyCounts[toyIndex]-toyUsed);
			boxed += count;
			boxUsed += count;
			toyUsed += count;
		}
		
		return Math.max(
			getBoxedCount(boxIndex+1,toyIndex,0,toyUsed,boxed),
			getBoxedCount(boxIndex,toyIndex+1,boxUsed,0,boxed));
	}

	public void run() throws IOException {
		Scanner sc = new Scanner(new FileReader(FILE_NAME+".in"));
		PrintWriter pw = new PrintWriter(new FileWriter(FILE_NAME+".out"));
		
		int cases = Integer.valueOf(sc.nextLine());
		for (int i=1;i<=cases;i++) {
			String output = "Case #"+i+": "+solve( sc);
			pw.println(output);
			System.out.println(output);
		}
		
		pw.flush();
		pw.close();
		sc.close();
	}
	public static void main(String[] args) throws IOException {
		new BoxFactory().run();
	}
}
