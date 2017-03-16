import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;

public class FairAndSquareSmall {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		InputStreamReader isr = new InputStreamReader(System.in);
		BufferedReader br = new BufferedReader(isr);
		
		String line = null;
		line = br.readLine();

		int T = Integer.parseInt(line);
		
		String[] results = new String[T];
		String[] A = new String[T];
		String[] B = new String[T];
		
		for (int t=0; t<T; t++) {
			String[] endPoints = br.readLine().split(" ");
			
			A[t] = endPoints[0];
			B[t] = endPoints[1];
		}

		isr.close();
		br.close();

		for (int t=0; t<T; t++) {
			long numFS = 0;
			long a = (long) Math.ceil(Math.sqrt(Long.parseLong((A[t]))));
			long b = (long) Math.floor(Math.sqrt(Long.parseLong(B[t])));
			
			for (long num = a; num <= b; num++) {
				if (isPalindrome(num) && isPalindrome((long) Math.pow(num, 2))) {
					numFS++;
				}
			}
			
			results[t] = "Case #" + (t+1) + ": " + numFS;
			System.out.println(results[t]);
			
		}
		
		resultsToFile("FairAndSquareSmall.txt", results);

	}
	
	private static void resultsToFile(String fileName, String[] results) throws IOException {
		File file = new File(fileName);
        BufferedWriter output = new BufferedWriter(new FileWriter(file));
        for (int i=0; i< results.length; i++) {
        	output.write(results[i]);
        	if (i < results.length - 1) {
        		output.write("\n");
        	}
        }
        output.close();
	}
	
	public static boolean isPalindrome(long a) {
        long palindrome = a;
        long reverse = 0;

        while (palindrome != 0) {
            long remainder = palindrome % 10;
            reverse = reverse * 10 + remainder;
            palindrome = palindrome / 10;
        }

        if (a == reverse) {
            return true;
        }
        return false;
    }	
}
