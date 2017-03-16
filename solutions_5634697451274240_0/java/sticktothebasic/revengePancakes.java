import java.util.*;
import java.lang.*;

public class revengePancakes
{
	static String calculateFlips(String s){
		// System.out.println(s);
		if (s.length() == 1){
			if (s.equals("+"))
				return "0";
			else 
				return "1";
		}
		else {
			int flips = 0;
			for(int i = 0; i < s.length() - 1; i++){
				if (s.charAt(i) != s.charAt(i+1)){
					flips++;
					// System.out.println(s.charAt(i) + "," + s.charAt(i+1));
				}
			}
			if (s.charAt(s.length() - 1) == '-')
				flips++;
			return Integer.toString(flips);
		}
	} 

    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        int numberOfTests = in.nextInt();
        in.nextLine();
        for (int i = 0; i < numberOfTests; i++)
        {
        	String pStk = in.nextLine();
            System.out.println("Case #" + (i + 1) + ": " + calculateFlips(pStk));
        }  
        // bruteTest("", 5);
    }
}