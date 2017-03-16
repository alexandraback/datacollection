import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.SortedSet;
import java.util.TreeSet;


public final class RecycledNumbers {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		BufferedReader br = null;
		try {
			br = new BufferedReader(new InputStreamReader(new FileInputStream("test.txt")));
			int count = 1;
			String input;
			int cases = Integer.valueOf(br.readLine());
			while (((input = br.readLine()) != null) && (count <= cases)) {
				String output = "Case #"+(count++)+": "+process(input);
				System.out.println(output);				
			}
		} catch (Exception e) {// Catch exception if any
			System.err.println("Error: " + e.getMessage());
		} finally {
			if (br!=null) try { br.close(); } catch(IOException e) {}
		}
	}
	private static final int process(String input) {
		String[] s = input.split(" ");
		if (s[0].length()==1) return 0;
		int A = Integer.valueOf(s[0]);
		int B = Integer.valueOf(s[1]);
		int counter = 0;
		for (int n=A; n<B; n++) {
			SortedSet<Integer> rotates = rotate(n, A, B);
			if (n != rotates.first()) continue;
			counter += count(rotates.size());
		}
		return counter;
	}
	
	private final static int count(int n) {
		if (n < 2) return 0;
		if (n == 2) return 1;
		return --n + count(n);
	}
	
	private static final SortedSet<Integer> rotate(int N, int min, int max) {
		SortedSet<Integer> set = new TreeSet<Integer>();
		set.add(N);
		String sN = Integer.toString(N);
		for (int i = 0; i < sN.length()-1;i++) {
			//if (sN.charAt(1) == '0') continue;
			sN = sN.substring(1)+sN.charAt(0);
			int n = Integer.valueOf(sN);
			if (min<=n && n<=max) set.add(n);
		}
		return set;
	}
}
