import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.Scanner;


public class R1C_B {
	private final static String CLASS_NAME = R1C_B.class.getSimpleName();
	
	public static void main(String[] args) throws FileNotFoundException, UnsupportedEncodingException {
		PrintWriter writer = new PrintWriter(CLASS_NAME + ".out", "UTF-8");
		Scanner scan = new Scanner(System.in);
		int T = scan.nextInt();
		for(int t=0; t<T; t++)
		{
			int K = scan.nextInt();
			int L = scan.nextInt();
			int S = scan.nextInt();
			String keys = scan.next();
			String target = scan.next();
			String ans = "Case #"+(t+1)+": " + getAns(K, L, S, keys, target);
			System.out.println(ans);
			writer.println(ans);
		}
		scan.close();
		writer.close();
	}
	
	private static String getAns(int K, int L, int S, String keys, String target)
	{
		for(char c : target.toCharArray())
		{
			if(keys.indexOf(c + "") == -1 )
			{
				return "0.0";
			}
		}
		
		int takeUpLength = stringTakeUpLength(target);
		double totalBanana = (S-(target.length()-takeUpLength))/takeUpLength;
		
		double expectedBananaGiven = totalBanana;
		for(char c : target.toCharArray())
		{
			expectedBananaGiven *= getCharChance(keys, c);
		}
		return "" + (totalBanana - expectedBananaGiven);
	}
	
	private static double getCharChance(String s, char c)
	{
		double count = s.length() - s.replaceAll(c + "", "").length();
		return count / (double)s.length();
	}
	
	private static int stringTakeUpLength(String s)
	{
		if(s.length() == 1)
			return 1;
		
		for(int i=1; i< s.length(); i++)
		{
			String sBeg = s.substring(i);
			String sEnd = s.substring(0, s.length() - i);
			
			if(sBeg.equals(sEnd))
				return i;
		}
		return s.length();
	}
}
