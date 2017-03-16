import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

public class Dwar {
	
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new File("dwar.in"));
		FileWriter fw = new FileWriter(new File("dwar.out"));
		
		int t =sc.nextInt();
		for(int i=0; i<t; i++)
		{
			int N=sc.nextInt();
			double[] P1 = new double[N];
			double[] P2= new double[N];
			for(int j=0; j<N; j++)
				P1[j]=sc.nextDouble();
			for(int j=0; j<N; j++)
				P2[j]=sc.nextDouble();
			Arrays.sort(P1);
			Arrays.sort(P2);
			
			System.out.println(Arrays.toString(P1));
			System.out.println(Arrays.toString(P2));
			int war=0, dwar=0;
			int n=0;
			int p1=0, p2=0;
			while(n<N)
			{
				if(P1[p1]>P2[p2]) //point
				{
					++p2;
					++dwar;
				}
				++p1;
				++n;
			}

			n=0;
			p1=N-1;
			p2=N-1;
			while(n<N)
			{
				if(P1[p1]>P2[p2]) //point
					++war;
				else
					--p2;
				--p1;
				++n;
			}

			
			fw.write("Case #"+(i+1)+": "+dwar+" "+war+"\n");
		}
		fw.flush();
		fw.close();
	}
}
