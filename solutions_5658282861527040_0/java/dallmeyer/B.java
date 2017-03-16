import java.util.Scanner;


public class B {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		int T = in.nextInt();
		for (int caseNo = 1; caseNo <= T; caseNo++)
		{
			int A = in.nextInt(),
				B = in.nextInt(),
				K = in.nextInt();
			
			int count = 0;	//include 0,b and a,0 sols by default
			for (int a = 0; a < A; a++)
			{
				for (int b = 0; b < B; b++)
				{
					int and = a & b;
					if (and < K)
					{
						count++;
					}
				}
			}
			
			
			System.out.println("Case #" + caseNo + ": " + count);
		}
	}

}
