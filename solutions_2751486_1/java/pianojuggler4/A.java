import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.math.BigInteger;
import java.util.Scanner;

public class A
{
	public static void main(String args[]) throws Exception
	{
		Scanner in = new Scanner(new File("in.txt"));
		BufferedWriter out = new BufferedWriter(new FileWriter("out.txt"));
		int T = in.nextInt();
		for(int X=1;X<=T;X++) {
			String name = in.next();
			int N = in.nextInt();
			
			long count = 0;
			long prev = 0;
			BigInteger finalcount = new BigInteger("0");
			
			for(int n=0;n<name.length();n++) {
				if(!("aeiou".contains(""+name.charAt(n)))) {
					count++;
					if(count >= N) {
						finalcount = finalcount.add(new BigInteger(""+(n-N+2-prev)*(name.length()-n)));
						prev = n-N+2;
					}
				} else {
					count = 0;
				}
			}
			
			
			out.write("Case #" + X + ": " + finalcount.toString() + "\n");
		}
		
		in.close();
		out.close();
	}
}