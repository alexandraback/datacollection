import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;


public class GarbledEmail {
	
	private Scanner scanner = null;
	private PrintWriter out = null;
	private ArrayList<ArrayList<String>> words = new ArrayList<ArrayList<String>>();
	
	public int get(String s) {
		int res = Integer.MAX_VALUE / 2;
		for (String word : words.get(s.length())) {
			int cur = 0;
			int last = -1000;
			for (int i = 0; i < s.length(); i++)
				if (s.charAt(i) != word.charAt(i)) {
					cur++;
					if (i - last < 5) {
						cur = Integer.MAX_VALUE;
						break;
					}
					last = i;
				}
			res = Math.min(res, cur);
		}
		return res;
	}
	
	public void solveSingleTest(int testNumber) {
		int f[] = new int[51];
		Arrays.fill(f, Integer.MAX_VALUE / 2);
		
		String s = scanner.next();
		f[0] = 0;
		int n = s.length();
		for (int i = 1; i <= n; i++) {
			for (int j = i; j >= 1; j--) {
				f[i] = Math.min(f[i], f[j - 1] + get(s.substring(j - 1, i)));
			}
		}
		
		out.printf("Case #%d: %d\n", testNumber, f[n]);
	}
	
	public GarbledEmail() {
		Scanner in = null; 
		try {
			scanner = new Scanner(new File("input.txt"));		
			in = new Scanner(new File("dic.txt"));
			out = new PrintWriter(new File("output.txt"));
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		for (int i = 0; i < 100; i++)
			words.add(new ArrayList<String>());
		
		while (in.hasNext()) {
			String word = in.next();
			words.get(word.length()).add(word);
		}
		
		int T = scanner.nextInt();
		for (int test = 1; test <= T; test++) {
			solveSingleTest(test);
		}
		
		out.close();
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new GarbledEmail();
	}

}
