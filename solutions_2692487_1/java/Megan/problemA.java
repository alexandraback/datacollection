import java.util.Scanner;
import java.io.BufferedInputStream;
import java.util.Arrays;
import java.util.ArrayList;

public class problemA
{
	public static void main(String args[])
	{
		Scanner in = new Scanner(new BufferedInputStream(System.in));
		int testCases = in.nextInt();
		
		for (int i = 0; i< testCases; i++)
		{
			int A = in.nextInt();
			int N = in.nextInt();
			int motes[] = new int[N];
			for (int j=0; j<N; j++)
			{
				motes[j]=in.nextInt();
			}
			Arrays.sort(motes);
			int count = 0;
			for (int j=0; j<N; j++)
			{
				int innercount = 0;
				if (A<=motes[j]&&A==1)
				{
					count = N;
					break;
				}
				while (A<=motes[j]&&innercount<(N-j))
				{
					innercount++;
					A+=A-1;
				}
				if (innercount<(N-j))
				{
					count+=innercount;
				}
				else
				{
					count+=N-j;
					break;
				}
				A+=motes[j];
			}
			if (count>N)
			{
				System.out.println("Case #"+(i+1)+": "+N);
			}
			else
			{
				System.out.println("Case #"+(i+1)+": "+count);
			}
		}
	}
}