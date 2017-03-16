import java.io.FileInputStream;
import java.io.FileWriter;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;


public class Problem2
{

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception
	{
		FileInputStream is = new FileInputStream("in.txt");
		Scanner sc = new Scanner(is);
		
		FileWriter fw = new FileWriter("out.txt");
		
		int testCasesNumber = sc.nextInt();
		for(int i=0;i<testCasesNumber;i++)
		{
			fw.write("Case #"+(i+1)+": "+(new TestCase()).solve(sc)+"\n");
		}
		fw.close();
	}
	
	static class TestCase
	{
		int E;
		int R;
		int N;
		int[] v;
		
		public String solve(Scanner sc)
		{
			E = sc.nextInt();
			R = sc.nextInt();
			N = sc.nextInt();
			v = new int[N];
			for(int i=0;i<N;i++)
			{
				v[i] = sc.nextInt();
			}
			
			int[] r1 = new int[E-R+1];
			int[] r2 = new int[E-R+1];
			
			Arrays.fill(r1, 0);
			
			for(int i=N-1;i>=0;i--)
			{
				int vi = v[i];
				int vp = i==N-1 ? 0 : v[i+1];
				for(int j=0;j<E-R+1;j++)
				{
					if(vp>=vi)
					{
						int e = Math.max(2*R+j-E, 0);
						r2[j] = e * vi + r1[j-e+R]; 
					}
					else
					{
						int e=Math.max(2*R+j-E, 0);
						for(;e<j+R && e*vi+r1[j-e+R] < (e+1)*vi+r1[j-e+R-1];e++);
						r2[j] = e * vi + r1[j-e+R];
					}
				}
				int[] tmp = r2;
				r2 = r1;
				r1 = tmp;
			}
			
			return r1[r1.length - 1]+"";
		}
	}

}
