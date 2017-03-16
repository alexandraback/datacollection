package gcj14;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class NewLotteryGame {

	private String getAnswer(int first, int second, int bought) {
		int res = 0;
		for (int i = 0; i < first; i++) {
			for (int j = 0; j < second; j++) {
				if ((i & j) < bought) res++;
			}
		}
		
		return String.valueOf(res);
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
				int first = in.nextInt();
				int second = in.nextInt();
				int bought = in.nextInt();
				
				
				System.out.println(i);
				writer.println("Case #" + (i + 1) + ": " + new NewLotteryGame().getAnswer(first, second, bought));
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
