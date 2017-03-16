import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.StreamTokenizer;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;

public class Garbled {

	public static void main(String[] args) throws Exception {
		Garbled object = new Garbled();
		String className = object.getClass().getSimpleName();

		FileReader fileReader = new FileReader(new File(className.toLowerCase()
				+ ".in"));
		StreamTokenizer st = new StreamTokenizer(new BufferedReader(fileReader));

		FileWriter wr = new FileWriter(className.toLowerCase() + ".out");
		
		ArrayList<String> dictionary = readDictionary();

		st.nextToken();
		int testCases = (int) st.nval;
		
		st.resetSyntax();
		st.wordChars(0, 256);
		st.whitespaceChars(0, 32);

		for (int tc = 1; tc <= testCases; tc++) {
			st.nextToken();
			String str = st.sval;

			int output = object.solve(dictionary, str);
			wr.write("Case #" + tc + ": " + output + "\r\n");
		}

		wr.close();
	}

	private int solve(ArrayList<String> bigDictionary, String s) {
		int result = 1000000000;
		
		ArrayList<String> dictionary = new ArrayList<String>();
		
		for (String word : bigDictionary) {
		
			boolean needed = false;
			
			for (int i=0; i<s.length()-word.length() + 1; i++) {

				int lastPosChange = -1000;
				boolean ok = true;
				
				for (int k=0; k<word.length(); k++) {
					char ch1 = word.charAt(k);
					char ch2 = s.charAt(i + k);
					
					if (ch1 != ch2) {
						if (i+k - lastPosChange < 5) {
							ok = false;
							break;
						}
						
						lastPosChange = i+k;
					}
				}
				
				if (ok)
				{
					needed = true;
					break;
				}				
			}
			
			if (needed)
				dictionary.add(word);
		}
		
		
		Queue<int[]> q = new LinkedList<int[]>();
		q.add(new int[]{0, 54});
		
		int[][] dp = new int[51][55];
		
		for (int i=0; i<51; i++)
				for (int k=0; k<55; k++)
					dp[i][k] = -1;
		
		dp[0][54] = 0;
		
		while (!q.isEmpty()) {
			int[] state = q.poll();
			int pos = state[0];
			int lastChange = state[1];
			
			int changes = dp[pos][lastChange];
			
			if (lastChange == 54)
				lastChange = -1000;

			if (changes >= result)
				continue;
			
			if (pos == s.length()) {
				result = changes;
				continue;
			}
			
			for (String word : dictionary)
			{
				if (pos + word.length() > s.length())
					continue;
				
				int requiredChanges = 0;
				int swappedAt = lastChange;
				boolean possible = true;
				
				for (int c=0; c<word.length(); c++) {
					char ch1 = word.charAt(c);
					char ch2 = s.charAt(pos + c);
					
					if (ch1 == ch2)
						continue;
					
					//different
					int curIndex = pos+c;
					int prevIndex = swappedAt;
					
					if (curIndex-prevIndex < 5)
					{
						possible = false;
						break;
					}
					
					swappedAt = curIndex;
					requiredChanges++;
				}
				
				if (!possible)
					continue;
				
				
				if (changes + requiredChanges >= result)
					continue;
				
				if (swappedAt == -1000)
					swappedAt = 54;
				
				//ok, continue with this
				if (dp[pos+word.length()][swappedAt] != -1 && dp[pos+word.length()][swappedAt] <= changes+requiredChanges)
					continue;
				
				dp[pos+word.length()][swappedAt] = changes+requiredChanges;
				q.add(new int[]{pos+word.length(), swappedAt});
			}	
		}

		
		return result;
	}

	private static ArrayList<String> readDictionary() throws Exception  {
		FileReader fileReader = new FileReader(new File("dict.txt"));
		StreamTokenizer st = new StreamTokenizer(new BufferedReader(fileReader));

		st.resetSyntax();
		st.wordChars(0, 256);
		st.whitespaceChars(0, 32);
		
		ArrayList<String> dictionary = new ArrayList<String>();
		
		while (st.nextToken() != StreamTokenizer.TT_EOF)
			dictionary.add(st.sval);
		
		
		Collections.sort(dictionary);
		return dictionary;
			
	}

}
