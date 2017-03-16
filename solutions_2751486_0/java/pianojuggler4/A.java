import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
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
			
			int count = 0;
			int prev = 0;
			int finalcount = 0;
			
			System.out.println("TRIAL: "+X);
			
			for(int n=0;n<name.length();n++) {
				if(!("aeiou".contains(""+name.charAt(n)))) {
					count++;
					if(count >= N) {
						finalcount += (n-N+2-prev)*(name.length()-n);
						prev = n-N+2;
						System.out.println(finalcount);
					}
				} else {
					count = 0;
				}
			}
			
			
			out.write("Case #" + X + ": " + finalcount + "\n");
		}
		
		in.close();
		out.close();
	}
}