import java.util.*;

public class A
{
	public static void main(String[] args) 
	{
		Scanner sc = new Scanner(System.in);
		int tt = sc.nextInt();
		for(int kk = 1; kk<=tt;kk++)
		{
			String name = sc.next();
			int a = sc.nextInt();
			int[] arr = new int[name.length()];
			char c = name.charAt(0);
			if(c!='a' && c!='e' && c!='i' && c!='o' && c!='u')
			{
				arr[0] = 1;
			}
			for(int i = 1 ;i <name.length(); i++)
			{
				char cc = name.charAt(i);
				if(cc!='a' && cc!='e' && cc!='i' && cc!='o' && cc!='u')
				{
					arr[i] = 1;// + arr[i-1];
				}
			}
			int count = 0;
			//for(int aa:arr)
			//		System.out.print(aa+" ");
			//System.out.println();
			for(int i = 0; i< name.length(); i++)
			{
				for(int j = i; j<name.length(); j++)
				{
					int prev = 1;
					int temp = 0;
					int max = 0;
					for(int k = i; k<=j;k++)
					{
						/*if(arr[k] >= a)
						{
							count++;
							System.out.println(i+" "+j);
							break;
						}*/
						temp += arr[k];
						if(arr[k] == 0)
							temp = 0;
						//prev = arr[k];
						//System.out.print("woot "+temp+" "+prev+" toow");
						if(max<temp)
						{
							max = temp;
						}
					}
					//System.out.println();
					//	System.out.println(i+" "+j+" "+max);
					if(max >= a)
					{
						count++;
					}
				}
			}
			System.out.printf("Case #%d: %d \n", kk, count);
		}	
	}
}