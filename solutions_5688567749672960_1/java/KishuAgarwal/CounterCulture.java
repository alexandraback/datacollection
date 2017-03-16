import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;


public class CounterCulture {

	public static void main(String[] args)throws IOException {
		Scanner in = new Scanner(new File("in.in"));
		//Scanner  in = new Scanner(System.in);
		PrintWriter writer = new PrintWriter(new File("out.out"));
		int t = in.nextInt();
		
		for (int i = 1; i <= t; i++) {
			long number = in.nextLong();
			long temp = 0;
			long ans = number;
			long increment = 10;
			if (number >= 21) 
			{
				temp = 21;
				ans = 13;
				while (true) {
					temp += increment;
					if (temp > number) {
						temp-= increment;
						break;
					}
					if (temp == number) {
						ans++;
						break;
					}
					ans++;
					if (temp == increment * 10 + 1) 
						increment *= 10;
					
				}
				ans += number - temp;
			}
			//System.out.println(ans);
			writer.println("Case #" +i+": "+ ans);
		}
		in.close();
		writer.close();
	}
	
	public static int reverse(int number) {
		int reverse = 0;
		while (number > 0) {
			reverse = reverse * 10 + number % 10;
			number /= 10;
		}
		return reverse;
	}
	
	

}
