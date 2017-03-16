import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class LastWord {

	public static void main(String[] args) throws NumberFormatException, IOException {
			BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
			int numCases = Integer.parseInt(in.readLine());
			for (int caseNumber = 1; caseNumber <= numCases; caseNumber++) {
				String S = in.readLine();
				String lastWord = getLastWord(S);
				System.out.println("Case #" + caseNumber + ": " + lastWord);
			}
		}
	

	private static String getLastWord(String s) {
		String result = "";
		for(int i=0;i<s.length();i++)
		{
			char c = s.charAt(i);
			if(result.length()==0)
				result+=c;
			else
			{
				if(c>=result.charAt(0))
					result=c+result;
				else
					result=result+c;
			}
		}
		
		return result;
	}

}
