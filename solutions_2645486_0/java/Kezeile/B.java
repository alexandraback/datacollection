import java.util.*;
import java.io.*;

public class B
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int tt = sc.nextInt();
		for(int kk=1;kk<=tt;kk++)
		{
			int e = sc.nextInt();
			int r = sc.nextInt();
			if(r>e) r=e;
			int n = sc.nextInt();
			int[] arr = new int[n];
			int sum = 0;
			for(int i=0;i<n;i++)
			{
				arr[i] = sc.nextInt();
			}
			Arrays.sort(arr);
			for(int i=n-1;i>=0;i--)
			{
				if(i==n-1)
					sum += e*arr[i];
				else
					sum += r*arr[i];
			}
			System.out.printf("Case #%d: %d\n",kk,sum);
		}
	}
}