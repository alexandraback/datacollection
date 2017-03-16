import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Scanner;


public class RecycledNumbers {
	static int[] pow = { 1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
	public static void main(String[] args) {
		PrintStream theOut=null;
		try {
			FileOutputStream o = new FileOutputStream("./output.txt", false);
			theOut = new PrintStream(o);
		}
		catch (Exception e) {
			e.printStackTrace();
			return;
		}


		Scanner sc=null;
		try {
			//sc = new Scanner(new File("./C-small.in"));
			//sc = new Scanner(new File("/home/duck/Downloads/B-large.in"));
			sc = new Scanner(new File("/home/duck/Downloads/C-small-attempt0.in"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}

		int nbCases = sc.nextInt();

		mainloop: for(int curCase=1; curCase <= nbCases ;++curCase) {
			sc.nextLine();
			long res = 0;
			int min = sc.nextInt();
			int max = sc.nextInt();
			ArrayList<Integer> found = new ArrayList<Integer>();

			for(int i=min; i <= max ;++i) {
				int nbDigit = (int)Math.ceil(Math.log10((double)i));
				found.clear();
				for(int j= 1; j < nbDigit ; j++) {
					int low  =  i% pow[j];
					int swap = low * pow[nbDigit - j] + (i-low) /pow[j];
					if(swap > i && swap <= max && !found.contains(swap)) {
						found.add(swap);
						++res; 
						//System.out.println(i+" "+swap);
					}
				}
			}
			/*******************************************************************/
			theOut.format("Case #%d: %d\n",curCase,res);
			System.out.format("Case #%d: %d\n",curCase,res);
		}

	}
}
