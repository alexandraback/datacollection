import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class Problem2B {
	private static final String FILENAME = "B-small-attempt0";
	private static final String INFILE = FILENAME + ".in";
	private static final String OUTFILE = FILENAME + ".out";
	private static final boolean fileIn = true;
	private static final boolean fileOut = true;
	int T;
	int K, C, S, N;
	int MAX = 2501;
	int[] nums = new int[MAX];
//	String[] N2 = new String[100]; 
	String[] N2 = new String[50 * 50 * 2];
	int N2Count;
	int[] missing = new int[50];
	Problem2B() {
		
	}

	
	void init() {
		for (int i = 0 ; i < MAX ; i++) {
			nums[i] = 0;
		}		
	}
	
	String doit(String[] strs, int Ncount, int N) {
		int max = -1;
		for (int j = 0 ; j < Ncount ; j++) {
			for (int k = 0 ; k < N ; k++) {
				int index = Integer.parseInt(strs[j * N + k]);
				nums[index]++;
				if (max < index) {
					max = index;
				}
			}
		}
		
		int count = 0;
		for (int i = 0 ; i <= max ;i++) {
			if ((nums[i] %2) != 0) {
				missing[count] = i;
				count++;
			}
		}
		
		if (count != N) {
			System.out.println("Error " + count + " " + N);
			return null;
		}
		
		for (int i = 0 ; i < N - 1; i++) {
			int min = missing[i];
			int index = i;
			for (int j = i + 1 ; j < N ; j++) {
				if (min > missing[j]) {
					min = missing[j];
					index = j;
				}
			}
			int temp = missing[i];
			missing[i] = missing[index];
			missing[index] = temp;
		}
		
		String ret = "";
		for (int i = 0 ; i < N ; i++) {
			ret += (" " + missing[i]);
		}
		
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
			init();
			N = scan.nextInt();
			N2Count = N * 2 -1;
			
			for (int j = 0 ; j < N2Count ; j++) {
				for (int k = 0 ; k < N ; k++) {
					N2[j * N + k] = scan.next();	
				}
			}
//			K = scan.nextInt();
//			C = scan.nextInt();
//			S = scan.nextInt();
			String solved = "Case #" + i + ":" + doit(N2, N2Count, N) + '\n';
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
		Problem2B d= new Problem2B();
		d.solve();
	}

}
