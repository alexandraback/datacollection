import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;


public class A1 {

	/**
	 * @param args
	 * @throws IOException  
	 */
	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(new FileInputStream("in.in"));
		PrintWriter pw = new PrintWriter(new FileOutputStream("out.out"));
		int num = sc.nextInt();
		
		for (int temp = 1;temp<=num;temp++)
		{
			long r = sc.nextLong();
			long t = sc.nextLong();
			
			long n = findn(r,t);
			pw.printf("Case #%d: ", temp);
			pw.println(n);
		}
		pw.close();
		sc.close();
	}

	private static long findn(long r, long t) {
		// TODO Auto-generated method stub
		long max = (long) Math.min(Math.floor(t/(2*r-1)),Math.floor(Math.sqrt(t/2)));
		long min = 1;
		while (max>=min)
		{
			long mid = (max+min)/2;
			if (compute(mid+1,r,t))
			{
				min = mid+1;
			}
			else if (!compute(mid,r,t))
			{
				max = mid-1;
			}
			else
			{
				return mid;
			}
		}
		return -1;
	}

	private static boolean compute(long mid, long r, long t) {
		// TODO Auto-generated method stub
		if (2*mid*mid-mid+2*mid*r<=t) return true;
		return false;
	}

}
