import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;


public class PartElf {

	public void dealCore(String filename)
	{
		Scanner sc = null;
		PrintWriter pw = null;
		int T, P, Q;
		String result;
		try {
			sc = new Scanner(new File(filename));
			pw = new PrintWriter(new File("out.txt"));
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		T = Integer.parseInt(sc.nextLine());
		
		for (int i = 0; i < T; i++)
		{
			result = "Case #" + (i+1) + ": ";
			String[] s= sc.nextLine().split("[/]");
			P = Integer.parseInt(s[0]);
			Q = Integer.parseInt(s[1]);
			int f = minTerms(P, Q);
			P = P / f;
			Q = Q / f;
			if(isM(Q) == false)
				result += "impossible";
			else
			{
				int times = 1;
				while (((double)P / (double)Q) * 2 < 1)
				{
					P = P * 2;
					times ++;
				}
				result += times;
			}
			pw.println(result);
			
		}
		pw.flush();pw.close();
	}
	
	public boolean isM(int a)
	{
		while(a % 2 == 0)
		{
			a = a / 2;
		}
		if (a % 2 != 0 && a != 1)
			return false;
		else
			return true;
	}
	
	public int minTerms(int m, int n)
	{
		int  temp;
        if (m < n){     // if m<n,swap m,n 
           temp = m;
           m = n;
           n = temp;
       }
        while (m % n != 0 ){
           temp = n;
           n = m % n;
           m = temp;
       }
        return  n;
	}
	
	public static void main(String args[])
	{
		String filename = "A-small-attempt0.in";
		PartElf p = new PartElf();
		p.dealCore(filename);
	}
}
