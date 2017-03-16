import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;


public class Mote {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		Scanner scanner = new Scanner(new File("A-large.in"));
		BufferedWriter writer = new BufferedWriter(new FileWriter(new File("A-large.out"),false));
		int t = scanner.nextInt();
		scanner.nextLine();
		for (int i = 0; i < t; i++){
			int a = scanner.nextInt();
			int n = scanner.nextInt();

			ArrayList<Integer> motes = new ArrayList<Integer>();
			for (int j = 0; j < n; j++) {
				motes.add(scanner.nextInt());
			}
			
			Collections.sort(motes);
			
			ArrayList<Integer> newMotes = new ArrayList<Integer>();
			
			for (Integer k : motes) {
				if (k < a) {
					a+=k;
				} else {
					newMotes.add(k);
				}
			}
					
			int cases = calcCases(a, newMotes);
			
			writer.write("Case #"+(i+1)+": "+cases+" \n");
		}
		scanner.close();
		writer.close();
	}

	private static int calcCases(int a, ArrayList<Integer> motes) {
		if (a == 1) return motes.size();
		if (motes.size() == 0) return 0;
		if (motes.size() == 1) return 1;
		
		int needed = 0;
		while (a <= motes.get(0)) {
			a += a-1;
			needed++;
		}
		
		ArrayList<Integer> newMotes = new ArrayList<Integer>();
		
		for (Integer k : motes) {
			if (k < a) {
				a+=k;
			} else {
				newMotes.add(k);
			}
		}
		
		return Math.min(motes.size(), needed + calcCases(a, newMotes));
	}

}
