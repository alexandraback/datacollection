import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.math.BigInteger;
import java.util.Scanner;

public class Clarge {
	public static void main(String[] args) throws FileNotFoundException, UnsupportedEncodingException {
		//Scanner sc = new Scanner(System.in);
		Scanner sc = new Scanner(new File("C-large.in"));
		PrintWriter pw = new PrintWriter("C-out-large.txt", "UTF-8");
		while(sc.hasNext()) {
			int T = sc.nextInt();
			int N = sc.nextInt();
			int J = sc.nextInt();
			String s = "";
			for(int i = 2; i <= 10; i++) {
				s += " " + new BigInteger("10000000000000001", i).toString();
			}
			System.out.println("Case #1:");
			pw.println("Case #1:");
			
			for(int i = 1; i <= J; i++) {
				String str = "1" + String.format("%1$14s", Integer.toBinaryString(i-1)).replace(' ', '0') + "1";
				System.out.println(str + str + s);
				pw.println(str + str + s);
			}
			
			pw.close();
		}
	}
}
