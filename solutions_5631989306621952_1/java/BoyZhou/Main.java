import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws IOException{
		// Scanner s = new Scanner(System.in);
		InputStream is = new FileInputStream(".\\input_and_output\\1A2016\\A-large-1A2016.in");
		FileWriter fr = new FileWriter(".\\input_and_output\\1A2016\\A-large-1A2016.out");
		Scanner s = new Scanner(is);
		
		int n = s.nextInt();
		for (int i = 1; i <= n; ++i){			
			String str = s.next();

			int l = str.length();
			String[] dp = new String[l];
			dp[0] = str.substring(0, 1);
			for (int j = 1; j < l; ++j){
				String str1 = dp[j-1] + str.charAt(j);
				String str2 = str.charAt(j) + dp[j-1];
				dp[j] = str1.compareTo(str2) > 0 ? str1 : str2;
			}
			
			fr.write(String.format("Case #%d: %s\n", i, dp[l-1]));
			// System.out.print(String.format("Case #%d: %s\n", i, dp[l-1]));
		}
		
		fr.close();
		s.close();
	}
}




