import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Arrays;

public class FairAndSquareSmall {

	private static final String inputFilePath = "Input/input.txt";
	private static final int LIMIT = 1000;
	private static boolean[] FAS = new boolean[LIMIT + 1];
	
	private static int solve(int A, int B) {
		int ret = 0;
		for (int i = A; i <= B; i ++)
			if (FAS[i]) 
				ret ++;
		return ret;
	}
	
	private static boolean isPalindrome(int x) {
		char[] bits = String.valueOf(x).toCharArray();
		int len = bits.length;
		for (int i = 0; i < len / 2; i ++)
			if (bits[i] != bits[len - 1 - i])
				return false;
		return true;
	}
	
	private static void init() {
		Arrays.fill(FAS, false);
		for (int i = 1; i <= LIMIT; i ++) 
			if (isPalindrome(i) && i * i <= LIMIT)
				FAS[i * i] = true;
		for (int i = 1; i <= LIMIT; i ++)
			if (FAS[i] && !isPalindrome(i))
				FAS[i] = false;
	}
	
	/**
	 * Good Luck, Wash!
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		init();		
		BufferedReader br = new BufferedReader(new FileReader(inputFilePath)); 
		int T = Integer.parseInt(br.readLine());
		for (int i = 1; i <= T; i ++) {
			String[] parts = br.readLine().split(" ");
			int A = Integer.parseInt(parts[0]);
			int B = Integer.parseInt(parts[1]);
			System.out.println(String.format("Case #%d: %d", i, solve(A, B)));
		}
		br.close();

	}

}
