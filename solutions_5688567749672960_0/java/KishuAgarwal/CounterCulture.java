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
		int shortest[] = new int[1000010];
		for (int i=  0; i < shortest.length; i++)
			shortest[i] = Integer.MAX_VALUE;
		shortest[1] = 1;
		int temp;
		for (int i = 2; i < shortest.length; i++) {
			if (shortest[i] != Integer.MAX_VALUE) continue;
			temp = reverse(i);
			if (temp < i && reverse(temp) == i)
				shortest[i] = Math.min(shortest[i-1], shortest[temp]) + 1;
			else
				shortest[i] = shortest[i-1] + 1;
		}
		for (int i = 1; i <= t; i++) {
			int number = in.nextInt();
			//System.out.println(shortest[number]);
			writer.println("Case #" +i+": "+ shortest[number]);
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
