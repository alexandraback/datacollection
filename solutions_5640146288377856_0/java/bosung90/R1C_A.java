import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.Scanner;

public class R1C_A {
	private final static String CLASS_NAME = R1C_A.class.getSimpleName();
	
	public static void main(String[] args) throws FileNotFoundException, UnsupportedEncodingException {
		PrintWriter writer = new PrintWriter(CLASS_NAME + ".out", "UTF-8");
		Scanner scan = new Scanner(System.in);
		int T = scan.nextInt();
		for(int t=0; t<T; t++)
		{
			int R = scan.nextInt();
			int C = scan.nextInt();
			int W = scan.nextInt();
			String ans = "Case #"+(t+1)+": " + getAns(R, C, W);
			System.out.println(ans);
			writer.println(ans);
		}
		scan.close();
		writer.close();
	}
	
	private static String getAns(int R, int C, int W)
	{
		if(W == 1)
		{
			return R*C + "";
		}
		
		int upperBound = (int)Math.ceil((double)C/(double)W);
		int max = upperBound * R;
		
		int extraShipLengh = W - 1;
		
		max += extraShipLengh;
		
		return "" + max;
	}
}
