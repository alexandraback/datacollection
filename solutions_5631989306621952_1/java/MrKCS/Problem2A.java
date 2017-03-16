import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class Problem2A {
	private static final String FILENAME = "A-large";
	private static final String INFILE = FILENAME + ".in";
	private static final String OUTFILE = FILENAME + ".out";
	private static final boolean fileIn = true;
	private static final boolean fileOut = true;
	int T;
	int K, C, S;

	String revers(String s) {
		String ret = "";
		int length = s.length();
		
		for (int i = length - 1 ; i >= 0 ; i--) {
			ret += s.charAt(i);
		}
		return ret;
	}
	
	String doit(String strO) {
		String str = strO;
		String ret = "";
		String small = "";
		while(true) {
			int length = str.length();
			int index = -1;
			char bigc = (char)('A' - 1);
			for(int i = 0 ; i < length ; i++) {
				if (str.charAt(i) > bigc) {
					bigc = str.charAt(i);
					index = i;
				}
			}
			
			if (index < 0) {
				System.out.println("error");
				break;
			}
			for (int i = length - 1 ; i >= index ; i--) {
				if (str.charAt(i) == bigc) {
					ret+= str.charAt(i);
				} else {
					small += str.charAt(i);
				}
			}
			str = str.substring(0, index);
			if (index == 0) {
				break;
			}
		}
		ret += revers(small);

		return ret;
	}
	void solve() {
		File input;
		BufferedWriter output;
		Scanner scan;
		if (!fileIn) {
			scan = new Scanner(System.in);
		} else {
			input = new File(INFILE);
			try {
				scan = new Scanner(input);
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				System.out.println("error to get input " + INFILE + '\n' + e);
				return;
			}
		}
		if (fileOut) {
			try {
				output = new BufferedWriter(new FileWriter(OUTFILE));
			} catch (IOException e) {
				// TODO Auto-generated catch block
				System.out.println("error to get output " + INFILE + '\n' + e);
				return;
			}
		}

		T = scan.nextInt();
		for (int i = 1 ; i <= T ; i++) {
			//			K = scan.nextInt();
			//			C = scan.nextInt();
			//			S = scan.nextInt();
			String s = scan.next();
			String solved = "Case #" + i + ": " + doit(s) + '\n';
			if (!fileOut) {
				System.out.println(solved);
			} else {
				try {
					output.write(solved);
				} catch (IOException e) {
					// TODO Auto-generated catch block
					System.out.println("error to write output\n" + e);
				}
			}
		}
		if (fileOut) {
			try {
				output.flush();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				System.out.println("error to flush output\n" + e);
			}
		}
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Problem2A d= new Problem2A();
		d.solve();
	}

}
