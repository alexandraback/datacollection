import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;


public class FairAndSquare {

	/**
	 * @param args
	 */
	static boolean [] pp = new boolean [10000000];
	public static void main(String[] args) throws Exception {
		for(long i = 0; i < pp.length; i++  )
			if(isPalindrome(""+i) && isPalindrome("" + (i*i)))
				pp[(int)i] = true;
				
		Scanner sc = new Scanner(new File("in.txt"));
		FileWriter out = new FileWriter(new File("out.txt"));
		int T = new Integer(sc.nextLine());
		for(int i = 1 ; i < T+1 ; i++)
		{
			int res = 0;
			long A = sc.nextLong(); 
			long B = sc.nextLong();
			long a = (long) Math.sqrt(A);
			long b = (long) Math.sqrt(B);
			if(a*a<A) a++;
			for(int j = (int) a ; j < b+1 ; j++)
				if(pp[j])res++;
			System.out.println("Case #"+i+": "+res);
			out.write("Case #"+i+": "+res+"\n");
			try{ sc.nextLine();}
			catch(Exception e){}

		}
		out.flush();
		sc.close();
		out.close();
	}
	
	public static boolean isPalindrome(String str)
	{
	    //test for end of recursion
	    if(str.length() < 2) {return true;}

	    //check first and last character for equality
	    if(str.charAt(0) != str.charAt(str.length() - 1)){return false;}

	    //recursion call 
	    return isPalindrome(str.substring(1, str.length() - 1));
	}

}
