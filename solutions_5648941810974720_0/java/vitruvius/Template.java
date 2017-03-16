import java.io.BufferedReader;
import java.io.InputStreamReader;


public class Template {

	public static void main(String[] args) throws Exception {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		
		int T = Integer.parseInt(bf.readLine());
		for(int testcase = 1; testcase <= T; testcase++){
			
			String line = bf.readLine().toUpperCase();
			int[] letterCounts = new int[26];
			for(int i=0; i < line.length(); i++){
				letterCounts[line.charAt(i) - 'A']++;
			}
			
			// weirdly enough, zero, two, four, six, and eight (which are coincentally even) all have a unique letter (z, w, u, x, g resp)
			// we can prune those out
			// but once that's done, one, three, five, and seven have unique letters (o, h, i, s)
			// and then all that's left is nine
			
			
			int[][] countsPerLetter = new int[10][26];
			String[] words = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
			for(int i=0; i < words.length; i++){
				for(int j=0; j < words[i].length(); j++){
					countsPerLetter[i][words[i].charAt(j) - 'A']++;
				}
			}
			
			int[] numberCounts = new int[10];
			char[] decidingChars = {'Z', 'W', 'U', 'X', 'G', 'O', 'H', 'F', 'S'};
			int[] correspondingNums = {0, 2, 4, 6, 8, 1, 3, 5, 7};
			for(int i=0; i < decidingChars.length; i++){
				int numLeft = letterCounts[decidingChars[i] - 'A'];
				for(int j=0; j < 26; j++){
					letterCounts[j] -= numLeft * countsPerLetter[correspondingNums[i]][j];
				}
				numberCounts[correspondingNums[i]] = numLeft;
			}
			numberCounts[9] = letterCounts['E' - 'A'];
			
			StringBuilder output = new StringBuilder();
			for(int i=0; i < numberCounts.length; i++){
				for(int j=0; j < numberCounts[i]; j++){
					output.append("" + i);
				}
			}
			System.out.println("Case #" + testcase + ": " + output.toString());
		}
	}
}
