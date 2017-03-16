import java.util.*;


public class Main
{
	public static void main(String[] args) throws Exception
	{
		Scanner in = new Scanner(System.in);
		
		int n = in.nextInt();
		
		int[] alphas = new int[128];
		
		for (int i = 0; i < n; i++)
		{
			String s = in.next();
			
			Arrays.fill(alphas, 'A', 'Z' + 1, 0);
			
			for (int j = 0; j < s.length(); j++)
			{
				alphas[(int)s.charAt(j)]++;
			}
			
			int[] nums = new int[10];
			
			int tmp;
			
			tmp = alphas['Z'];
			if (tmp > 0)
			{
				nums[0] = tmp;
				alphas['Z'] -= tmp;
				alphas['E'] -= tmp;
				alphas['R'] -= tmp;
				alphas['O'] -= tmp;
			}
			
			tmp = alphas['W'];
			if (tmp > 0)
			{
				nums[2] = tmp;
				alphas['T'] -= tmp;
				alphas['W'] -= tmp;
				alphas['O'] -= tmp;
			}
			
			tmp = alphas['U'];
			if (tmp > 0)
			{
				nums[4] = tmp;
				alphas['F'] -= tmp;
				alphas['O'] -= tmp;
				alphas['U'] -= tmp;
				alphas['R'] -= tmp;
			}
			
			tmp = alphas['R'];
			if (tmp > 0)
			{
				nums[3] = tmp;
				alphas['T'] -= tmp;
				alphas['H'] -= tmp;
				alphas['R'] -= tmp;
				alphas['E'] -= tmp;
				alphas['E'] -= tmp;
			}
			
			tmp = alphas['O'];
			if (tmp > 0)
			{
				nums[1] = tmp;
				alphas['O'] -= tmp;
				alphas['N'] -= tmp;
				alphas['E'] -= tmp;
			}
			
			tmp = alphas['F'];
			if (tmp > 0)
			{
				nums[5] = tmp;
				alphas['F'] -= tmp;
				alphas['I'] -= tmp;
				alphas['V'] -= tmp;
				alphas['E'] -= tmp;
			}
			
			tmp = alphas['X'];
			if (tmp > 0)
			{
				nums[6] = tmp;
				alphas['S'] -= tmp;
				alphas['I'] -= tmp;
				alphas['X'] -= tmp;
			}
			
			tmp = alphas['S'];
			if (tmp > 0)
			{
				nums[7] = tmp;
				alphas['S'] -= tmp;
				alphas['E'] -= tmp;
				alphas['V'] -= tmp;
				alphas['E'] -= tmp;
				alphas['N'] -= tmp;
			}
			
			tmp = alphas['G'];
			if (tmp > 0)
			{
				nums[8] = tmp;
				alphas['E'] -= tmp;
				alphas['I'] -= tmp;
				alphas['G'] -= tmp;
				alphas['H'] -= tmp;
				alphas['T'] -= tmp;
			}
			
			tmp = alphas['N'];
			if (tmp > 0)
			{
				tmp /= 2;
				nums[9] = tmp;
				alphas['N'] -= tmp;
				alphas['I'] -= tmp;
				alphas['N'] -= tmp;
				alphas['E'] -= tmp;
			}
			
			System.out.print("Case #" + (i + 1) + ": ");
			for (int j = 0; j < 10; j++)
			{
				for (int k = 0; k < nums[j]; k++)
				{
					System.out.print(j);
				}
			}
			System.out.printf("\n");
			
			for (int j = 'A'; j <= 'Z'; j++)
			{
				if (alphas[j] != 0)
				{
					System.out.println((char)j);
					System.out.println(alphas[j]);
					return;
				}
			}
		}
	}
	
}