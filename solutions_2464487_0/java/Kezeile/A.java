import java.util.*;
import java.io.*;

public class A
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int tt = sc.nextInt();
		int[] arr = new int[501];
		arr[0] = 0;
		for(int i=1;i<501;i++)
		{
			arr[i] = 4*i-1 + arr[i-1];
				//System.out.println(arr[i]);
		}
		for(int kk=1;kk<=tt;kk++)
		{
			int r = sc.nextInt();
			int t = sc.nextInt();
			int dummy = 0;
			int temp = 0;
			for(int i=r;i<1001;i+=2)
			{
				temp += ((i+1)*(i+1)) - (i*i);
				if(temp <= t)
					dummy++;
				else
					break;
			}
			System.out.printf("Case #%d: %d\n",kk,dummy);
		}
	}
}