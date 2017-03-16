import java.util.Scanner;

public class Fourteen1BB {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(int t = 1; t<=T;t++)
		{
			long A = sc.nextLong();
			long B = sc.nextLong();
			long k = sc.nextLong();
			long count = 0;
			for(int a=0; a<A;a++)
			{
				for(int b=0;b<B;b++)
				{
					if((a&b) < k)
						count++;
				}
			}
			System.out.println("Case #"+t+": "+count);
		}
	}
}
