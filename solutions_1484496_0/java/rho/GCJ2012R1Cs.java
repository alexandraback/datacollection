import java.util.Scanner;


public class GCJ2012R1Cs {
	public static int[] isP;
	public static boolean done = false;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		sc.nextLine();
		for(int t=1; t<=T; t++)
		{
			done = false;
			int S=0;
			int N=sc.nextInt();
			int[] nums = new int[N];
			for(int i=0; i<N; i++)
				nums[i]=sc.nextInt();
			for(int i=0; i<N; i++)
				S+=nums[i];
			isP=new int[S+1];
			System.out.println("Case #"+t+":");
			doIt(nums, 0,0);
			
			if(!done)
				System.out.println("Impossible");
			else
				System.out.println();
		}
	}
	
	public static void doIt(int[] vals, int idx, int S)
	{
		if(done)
			return;
		if(idx>=vals.length)
		{
			isP[S]++;
			if(isP[S]>1)
			{
				doIt2(vals, 0, 0);
				if(done)
					System.out.println();
			}
		}
		else
		{
			doIt(vals, idx+1, S+vals[idx]);
			if(done)
				System.out.print(vals[idx]+" ");
			else
				doIt(vals, idx+1, S);		
		}
	}
	
	public static void doIt2(int[] vals, int idx, int S)
	{
		if(idx>=vals.length)
		{
			if(isP[S]>1)
				done = true;
		}
		else
		{
			doIt2(vals, idx+1, S+vals[idx]);
			if(done)
				System.out.print(vals[idx]+" ");
			else
				doIt2(vals, idx+1, S);				
		}
	}
}
