import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class D {

	public static void main(String[] args) throws IOException
	{
		Scanner file = new Scanner(new File("D-large.in"));
		PrintWriter out = new PrintWriter(new FileWriter(new File("out.txt")));
		int zz = file.nextInt();
    loop:
		for(int i = 1;i<=zz;i++)
		{
			int K = file.nextInt();
			int C = file.nextInt();
			int S = file.nextInt();
			if(C==1)
            {
                if(S<K)
                {
                    out.printf("Case #%d: IMPOSSIBLE%n",i);
                    continue loop;
                }else
                {
                    out.printf("case #%d: ",i);
                    for(int j = 0;j<K;j++)
                        out.print(j+1+" ");
                    out.println();
                    continue loop;
                }
            }
            if((K+1)/2>S)
            {
                out.printf("Case #%d: IMPOSSIBLE%n",i);
                continue loop;
            }
			long total = pow(K,C);
			long dif = pow(K,C-1);
			out.printf("Case #%d: ",i);
			for(int j = 0;j<(K+1)/2;j++)
			{
				out.print(dif*j+K-j+" ");
			}
			out.println();
		}
		out.close();
	}

	public static long pow(long K, int C)
	{
		if(C%2!=0)
			return K*pow(K*K,C/2);
		if(C==0)
			return 1;
		return pow(K*K,C/2);
	}

	public static int find(char ch, char[] str)
	{
		for(int i = 0;i<str.length;i++)
			if(str[i]==ch)
				return i;
		return -1;
	}

}
