import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;


public class BoxFactory {
	static Scanner sc;
	static int n,m;
	static long res;
	static int toy[],box[];
	static long tcount[],bcount[];
	public static void main(String a[]) throws FileNotFoundException
	{
		int n,i;
	
		sc= new Scanner(new FileInputStream("d:\\test\\a.in"));
		PrintStream out=new PrintStream(new FileOutputStream("d:\\test\\a.out"));
		
		n=sc.nextInt();
		sc.nextLine();
		for(i=1;i<=n;i++)
		{
			res=0;
			process();
			out.println("Case #"+i+": "+res);
			System.out.println("Case #"+i+": "+res);
			
		}
	}
	static void process()
	{
		int i,j;
		n=sc.nextInt();
		m=sc.nextInt();
		toy=new int[m];
		tcount=new long[m];
		box=new int[n];
		bcount=new long[n];
		for(i=0;i<n;i++)
		{
			
			bcount[i]=sc.nextLong();
			box[i]=sc.nextInt();
		}
		for(i=0;i<m;i++)
		{
			
			tcount[i]=sc.nextLong();
			toy[i]=sc.nextInt();
		}
		
		recurse(0,0,0,0,0);
	}
	static void recurse(int t,long tpos,int b,long bpos,long tot)
	{
//		System.out.println(t+":"+tpos+":"+b+":"+":"+bpos+":"+tot);
		long count;
		if(tot>res) res=tot;
		if(t>=m || b>=n) return;
		if(toy[t]==box[b])
		{
			if((tcount[t]-tpos) == (bcount[b]-bpos))
			{
				bpos=tpos=0;
				tot+=tcount[t]-tpos;
				t++;b++;
			}
			else if((tcount[t]-tpos) > (bcount[b]-bpos)) 
			{
				count = bcount[b]-bpos;
				tpos+=count;
				bpos=0;
				tot+=count;
				b++;
			}
			else
			{
				count = tcount[t]-tpos;
				tpos=0;
				bpos+=count;
				tot+=count;
				t++;
			}
			recurse(t,tpos,b,bpos,tot);
		}
		else
		{
			recurse(t+1,0,b,bpos,tot);
			recurse(t,tpos,b+1,0,tot);
		}
	}
}
