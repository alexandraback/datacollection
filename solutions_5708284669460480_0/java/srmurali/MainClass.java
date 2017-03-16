import java.io.File;
import java.util.Scanner;
import java.util.HashMap;

public class MainClass {
	public static int countOccurrences(String haystack, char needle)
	{
	    int count = 0;
	    for (int i=0; i < haystack.length(); i++)
	    {
	        if (haystack.charAt(i) == needle)
	        {
	             count++;
	        }
	    }
	    return count;
	}
	
	public static void main(String[] args) {
		int T = 0;
		try {
			Scanner scan = new Scanner(new File("B-small-attempt0.in"));
			T = scan.nextInt();
			scan.nextLine();
			//System.out.println("Number of test cases is " + T);
			for(int i = 0; i < T; i++) {
				HashMap <String, Integer> possibleChars = new HashMap<String, Integer>();
				double answer = 0.0;
				int K, L, S;
				K = scan.nextInt();
				L = scan.nextInt();
				S = scan.nextInt();
				scan.nextLine();
				String keyboard = scan.nextLine();
				String target = scan.nextLine();
				boolean targetPossible = true;
				double numBananas = 0.0;
				for(char c : keyboard.toCharArray()) {
					possibleChars.put(String.valueOf(c), 1);
				}
				
				for(char c : target.toCharArray()) {
					if(!possibleChars.containsKey(String.valueOf(c))) {
						targetPossible = false;
						break;
					}
				}
				if(targetPossible) {
					numBananas = S / target.length();
				
				
				double probabilityOfOneOccurence = 1.0;
				
				for(char c : target.toCharArray()) {
					double probOfCurrentChar = countOccurrences(keyboard, c) / (double)keyboard.length();
					probabilityOfOneOccurence *= probOfCurrentChar;
				}
				
				double totalProbability = 0.0;
				
				for(int j = 0; j < numBananas; j++) 
					totalProbability += probabilityOfOneOccurence;
				
				answer = numBananas - totalProbability;
				}
				System.out.println("Case #" + (i+1) + ": " + answer);
			}
			
			
		}
		catch(Exception e) {
			e.printStackTrace();
		}

	}

}
