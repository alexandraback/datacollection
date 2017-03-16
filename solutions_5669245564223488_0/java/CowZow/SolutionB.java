import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;


public class SolutionB {
	public static void main(String[] args) throws IOException {
		
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	    
		int testCases = Integer.parseInt(in.readLine());
		
		String input;
		
		for (int testCaseCount = 1; testCaseCount <= testCases; testCaseCount++) {
			input = in.readLine();
			input = in.readLine();
			String[] stringArr = input.split("\\s+");
			ArrayList<String> stringList = new ArrayList<String>();
			for (int i = 0; i < stringArr.length; i++) {
				stringList.add(stringArr[i]);
			}
			
			Permutations<String> perm = new Permutations<String>(stringList);
			int count = 0;
			while (perm.hasNext()) {
				List<String> next = perm.next();
				if (isValid(next)) {
					count++;
 				}
			}
			
			System.out.println("Case #" + testCaseCount + ": " + count);
			
			
		}
		
	}
	
	public static boolean isValid(List<String> arr) {
		HashSet<Character> charSet = new HashSet<Character>();
		char currChar = '\0';
		for (int i = 0; i < arr.size(); i++) {
			String currString = arr.get(i);
			for (int j = 0; j < currString.length(); j++) {
				char stringChar = currString.charAt(j);
				if (currChar == '\0') {
					currChar = stringChar;
				} else if (stringChar != currChar) {
					if (charSet.contains(currChar)) {
						return false;
					} else {
						charSet.add(currChar);
						currChar = stringChar;
					}
				}
			}
		}
		
		if (charSet.contains(currChar)) {
			return false;
		}
		return true;
	}
}
