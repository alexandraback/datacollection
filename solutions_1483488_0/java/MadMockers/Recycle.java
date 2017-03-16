package recycle;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashSet;

public class Recycle
{

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int count = Integer.parseInt(br.readLine());
		
		for(int z = 0;z < count;z++)
		{
			int n = 0;
			int dbgCnt = 0;

			HashSet<Long> used = new HashSet<Long>();
			HashSet<Long> dbgUsed = new HashSet<Long>();
			
			String[] info = br.readLine().split(" ");			
			int a = Integer.parseInt(info[0]);
			int b = Integer.parseInt(info[1]);
			char[] max = String.valueOf(b).toCharArray();
			
			for(int i = a;i < b;i++)
			{
				char[] digits = String.valueOf(i).toCharArray();
				
				for(int j = 1;j < digits.length;j++)
				{
					boolean valid = true;
					boolean low = false;
					boolean high = false;
					boolean same = true;
					for(int k = 0;k < digits.length;k++)
					{
						char comp = digits[(k + j) % digits.length];
						//System.out.println(comp + " >=" + digits[k] + " <=" + max[k]);
						if((high || comp > digits[k]) && (low || comp < max[k] || (k == digits.length - 1 && comp == max[k])))
						{
							same = false;
							break;
						}
						else if((!high && comp < digits[k]) || (!low && comp > max[k]))
						{
							valid = false;
							break;
						}
						if(digits[k] != max[k])
						{
							if(comp == digits[k])
							{
								low = true;
							}
							else if(comp == max[k])
							{
								high = true;
							}
						}
					}
					if(valid && !same)
					{
						//System.out.println("Adding");
						char[] recon = new char[digits.length];
						for(int k = 0;k < digits.length;k++)
						{
							recon[k] = digits[(j + k) % digits.length];
						}
						int num = Integer.parseInt(String.valueOf(recon));
						//System.out.println(a + " <= " + i + " < " + num + " <= " + b);
//						if(!(a <= i && i < num && num <= b))
//						{
//							System.out.println("ERROR: " + num);
//						}
//						
						if(used.contains((num) | ((long) i << 32)))
						{
//							System.out.println("Reused");
						}
						else
						{
							used.add((num) | ((long) i << 32));
							n++;
						}

//						char[] num1 = String.valueOf(i).toCharArray();
//						char[] num2 = String.valueOf(num).toCharArray();
//						for(int k = 0;k < digits.length;k++)
//						{
//							if(num1[(j + k) % digits.length] != num2[k])
//								System.out.println("ERROR!");
//						}
					}
					
					/*char[] recon = new char[digits.length];
					for(int k = 0;k < digits.length;k++)
					{
						recon[k] = digits[(j + k) % digits.length];
					}
					int num = Integer.parseInt(String.valueOf(recon));
					if(i < num && num <= b && !dbgUsed.contains((num) | ((long) i << 32)))
					{
						dbgUsed.add((num) | ((long) i << 32));
						dbgCnt++;
					}*/
				}
			}
			
			/*for(long p : dbgUsed)
			{
				if(!used.contains(p))
				{
					System.out.println((int) (p >> 32) + " " + (int) (p & 0xFFFFFFFF));
				}
			}*/
			
			System.out.println("Case #" + (z + 1) + ": " + n/* + " " + dbgCnt + ((dbgCnt != n)?" !!!":"")*/);
		}
	}
	
}
