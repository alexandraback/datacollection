import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;


public class B2 {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(new FileInputStream("in.in"));
		PrintWriter pw = new PrintWriter(new FileOutputStream("out.out"));
		int num = sc.nextInt();
		
		for (int temp =1 ;temp<=num;temp++)
		{
			long e = sc.nextLong();
			long r = sc.nextLong();
			long n = sc.nextLong();
			long sum = 0;
			long max = 0;
			for (int i=0;i<n;i++)
			{
				long t = sc.nextLong();
				if (t>max) max = t;
				sum+=t;
			}
				
			pw.printf("Case #%d: ", temp);
			long result = (e-r)*max+sum*r;
			pw.println(result);
		}
		
		pw.close();
		sc.close();
	}

}
