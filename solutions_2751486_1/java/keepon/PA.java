package Round1C.PA;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;


public class PA {
	
	private static boolean isConsonant(char ch) {
		return ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u';
	}
	
	private static long solve(String s, int n) {
		int len = s.length();
		long[] dp = new long[len];
		int[] consonants = new int[len];
		consonants[0] = isConsonant(s.charAt(0)) ? 1 : 0;
		dp[0] = consonants[0] >= n ? 1 : 0;
		long result = dp[0];
		for (int i = 1; i < len; i++) {
			consonants[i] = isConsonant(s.charAt(i)) ? consonants[i-1] + 1 : 0;
			if (consonants[i] < n) {
				dp[i] = dp[i-1];
			} else {
				dp[i] = (i + 1) - n + 1;
			}
			result += dp[i];
		}
		return result;
	}
	
	public static void TestCases(String input){
		File file = new File(input);		
			if(file.exists()){
				BufferedReader br = null;
				int testcaseNum = 0;
				try{					
					br = new BufferedReader(new FileReader(file));
					String line = br.readLine();
					//line = br.readLine();										
					while(true){
						if(line != null && line.isEmpty()){
							line = br.readLine();
							continue;
						}
						line = br.readLine();
						if(line == null)
							break;																			
						
						//System.out.println(line);
						String[] objects = line.split(" ");
						long number = solve(objects[0].trim(), Integer.parseInt(objects[1]));											
						testcaseNum++;
						System.out.println("Case #"+testcaseNum+": "+number);
						
					}
					br.close();
						
				}catch(Exception e){
					e.printStackTrace();
				}finally{
					try{
						br.close();	
					}catch(Exception e){
						e.printStackTrace();
					}
					
				}
			}

	}	
	
	

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		
		PA.TestCases("A-large.in");
	}

}
