package jamC;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;

public class ProbC extends Prob{

	public static void main(String[] args) {
		for(int i=1;i<1000*1000*1000;i++);
		ProbC pa= new ProbC();
		pa.fromFile("C:\\Users\\tchang\\Downloads\\C-small-attempt1.in");
	}

	@Override
	public void load(BufferedReader br,BufferedWriter bw) {
		try{
			int T=Integer.parseInt(br.readLine());
			for(int cas=0;cas<T;cas++)
			{
				String words[]=br.readLine().split(" ");
				int a=Integer.parseInt(words[0]);
				int b=Integer.parseInt(words[1]);
				int c=Integer.parseInt(words[2]);
				int l=Integer.parseInt(words[3]);

				int comp[]={a*b*c,a*l,b*l,c*l};
				int minI=0;
				for(int i=0;i<4;i++)
					if(comp[i]<comp[minI])
						minI=i;

				//
				//				a=(a>l)?l:a;
				//				b=(b>l)?l:b;
				//				c=(c>l)?l:c;
				//				
				int num=comp[minI];
				bw.write("Case #"+(cas+1)+": "+num);
				bw.newLine();


								bw.write(" "+a+" "+b+" "+c+" "+l);
								bw.newLine();




				switch(minI)
				{
				case 0:
					for(int i=1;i<=a;i++)
						for(int j=1;j<=b;j++)
							for(int k=1;k<=c;k++)
							{
								bw.write(""+i+" "+j+" "+k);
								bw.newLine();
							}
					break;
				case 1:

					o:for(int i=1;i<=a;i++)
					{
						int count=0;
						for(int j=1;j<=b;j++)
							for(int k=1;k<=c;k++)
							{
								bw.write(""+i+" "+j+" "+k);
								bw.newLine();
								if(++count==l)
									continue o;
							}
					}
				break;
				case 2:
					o:for(int j=1;j<=b;j++)
					{
						int count=0;
						for(int i=1;i<=a;i++)
							for(int k=1;k<=c;k++)
							{
								bw.write(""+i+" "+j+" "+k);
								bw.newLine();
								if(++count==l)
									continue o;
							}
					}
				break;
				case 3:
					o:for(int k=1;k<=c;k++)
					{
						int count=0;
						for(int i=1;i<=a;i++)
							for(int j=1;j<=b;j++)
							{
								bw.write(""+i+" "+j+" "+k);
								bw.newLine();
								if(++count==l)
									continue o;
							}
					}
				break;
				}
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
