import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class B{
	public static void main(String[] args) throws FileNotFoundException
	{
		Scanner sc = new Scanner(new File("B.txt"));
		int testCase = Integer.parseInt(sc.nextLine());
		for(int Case=1; Case<=testCase; Case++)
		{
			int n = sc.nextInt();
			int sup = sc.nextInt();
			int p = sc.nextInt();
			p=3*p;
			int[] X=new int[n];
			int ans=0;
			for(int i=0; i<n;i++)
				{X[i]=sc.nextInt();
				if(X[i]>=(p-2)){ans++;}
				else
				{if(X[i]>0 && X[i]>=(p-4) && sup>0){ans++;sup--;}}
				}
			System.out.println("Case #"+Case+": "+ans);
		}
	}
}