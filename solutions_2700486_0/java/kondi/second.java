import java.io.File;
import java.io.FileWriter; 
import java.util.Scanner;


public class second {

	/**
	 * @param args
	 * @throws Exception 
	 */
	static double []  list = new double [10000];
	public static void main(String[] args) throws Exception {
		double d = 1.0;
		for(int i = 0; i < 10000 ; i++)
		{
			d/=2;
			list[i]=d; 
		}
		Scanner sc = new Scanner(new File("in.txt"));
		FileWriter out = new FileWriter(new File("out.txt"));
		int T = new Integer(sc.nextLine());
		for(int i = 1 ; i < T+1 ; i++)
		{
			 
			double res=0.0;
			int N = sc.nextInt();
			int x =Math.abs( sc.nextInt() ) ;
			int y = sc.nextInt();
			int rr = x+y;
			long covered = ((long)rr-1)*((long)rr )/2;
			long bigcovered = ((long)rr+1)*((long)rr+2 )/2;
			long remains = N - covered;
			System.out.println(covered +  "  = covered");
			System.out.println(bigcovered +  "  = bigcovered");
			if(N <=covered){
				res = 0;
			}
			else if(bigcovered <= N)
				res = 1;
			else
			{
				long ones = remains - rr;
				if(ones>0&&y<ones)
				{
					res = 1;
				}
				else
				{
					remains = remains - 2*(Math.max(0,ones));
					System.out.println("rr" + remains);
					int level = y;
					if(ones >0)
						level =(int) (  y - ones);
					for(int j = level ; j < remains ; j++)
					{
						res+=list[j-level];
						System.out.println("added " +list[j-level] );
					}
					if(level>0)
						res*=list[level-1];
					System.out.println("level ="+ level);
					System.out.println("ones ="+ ones);
					System.out.println("remains ="+ remains);
				}
					
				
			}
			
			 
			System.out.println("Case #"+i+": "+res );
			out.write("Case #"+i+": "+res +"\n");
			
			System.out.println("\n\n\n" );
			try{ sc.nextLine();}
			catch(Exception e){}

		}
		out.flush();
		sc.close();
		out.close(); 
	}
	  
}
