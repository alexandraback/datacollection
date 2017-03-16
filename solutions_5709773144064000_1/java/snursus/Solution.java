import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.util.Locale;
import java.util.Scanner;


public class Solution {
	static void solve(InputStream in) {
		Scanner scn = new Scanner(in);
		int numcases = scn.nextInt();
		for(int i = 1; i <= numcases; ++i) {
			solveCase(scn, i);
		}
	}

	static void solveCase(Scanner in, int casenumber) {
		String cs = in.next();
		String fs = in.next();
		String xs = in.next();

		double c = 0, f = 0, x = 0;
		try {
			c = Double.parseDouble(cs);
			f = Double.parseDouble(fs);
			x = Double.parseDouble(xs);
		} catch(NumberFormatException ex) {
			ex.printStackTrace();
			System.exit(0);
		}

		double income = 2;
		double time = 0;
		
		while(true) {
			double time_to_win = x/income;
			double time_to_win_after_farm = c / income + x / (income + f);
			if(time_to_win < time_to_win_after_farm) {
				time += time_to_win;
				System.out.printf(Locale.US, "Case #%d: %.7f\n", casenumber, time);
				return;
			} else {
				time += c/income;
				income += f;
			}
		}
	}

	public static void main(String[] args) {
		String infile;
		if(args.length == 0) {
			Scanner scn = new Scanner(System.in);
			infile = scn.nextLine();
		} else {
			infile = args[0];
		}

		InputStream is;

		try {
			is = new FileInputStream(infile);

			solve(is);

			is.close(); 
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
