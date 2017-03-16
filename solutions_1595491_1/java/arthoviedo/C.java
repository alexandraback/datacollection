import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;


public class C {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner s=new Scanner(new File("./data/B.txt"));
		PrintWriter pw=new PrintWriter(new File("./data/B_sol.txt"));
		int nCases=s.nextInt();s.nextLine();
		for(int i=0;i<nCases;i++){
			int N=s.nextInt();
			int S=s.nextInt();
			int P=s.nextInt();
			int count=0;
			
			for(int j=0;j<N;j++){
				int T=s.nextInt();
				
				boolean ok=false;
				for(int a=0;a<=10 &&!ok;a++){
					for(int b=0;b<=10&&!ok;b++){
						for(int c=0;c<=10&&!ok;c++){
							if(a+b+c==T && Math.abs(a-b)<=1 && Math.abs(a-c)<=1 && Math.abs(b-c)<=1
									&& (a>=P || b>=P || c>=P))
							{
								ok=true;
								System.out.println(a+" "+b+" "+c+" = "+T);
								
							}
						}
					}
				}
				if(ok)
					count++;
				else
				{
					boolean ok_2=false;
					for(int a=0;a<=10&&!ok_2;a++)
					{
						for(int b=0;b<=10&&!ok_2;b++){
							for(int c=0;c<=10&&!ok_2;c++)
							{
								if(a+b+c==T && Math.abs(a-b)<=2 && Math.abs(a-c)<=2 && Math.abs(b-c)<=2
										&& (a>=P || b>=P || c>=P))
								{
									ok_2=true;
									System.out.println(a+" "+b+" "+c+" = "+T);
								}
										
							}
						}
					}
					if(ok_2 && S>0){
						S--;
						count++;
					}
				}
				
			}
			pw.println("Case #"+(i+1)+": " +count);
			System.out.println("->"+i);
		}
		pw.close();
	}
}
