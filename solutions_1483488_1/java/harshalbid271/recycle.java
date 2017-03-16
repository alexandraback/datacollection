import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.Vector;


public class recycle {

	
	public static void main(String arg[]) throws FileNotFoundException
	{
		Scanner in=new Scanner(new FileReader("rec.in"));
		PrintWriter pw=new PrintWriter("ansRec.txt");
		int cases=in.nextInt();
		in.nextLine();
		
		for(int counter=1;counter<=cases;counter++)
		{
			int small=in.nextInt();
			int large=in.nextInt();
			
			int ans=0;

			for(int i=small;i<large;i++)
			{
				int length=(int)(Math.log10(i))+1;
								
				boolean flag=false;
				int label=i%10;
				int temp=i;
				
				for(int j=0;j<length;j++)
				{
					if(temp%10!=label)
					{
						flag=true;
						break;
					}
					else
					{
						temp=temp/10;
					}
				}
				
				boolean f2=false;
				
				Vector<Integer> vec=new Vector<Integer>();
				
				for(int j=1;j<length&&flag;j++)
				{
					int exponent=(int) (Math.pow(10,j));
					int lead=(int) (i/exponent);
					int residual=(i%exponent);
					
					if(residual/(exponent/10)==0)
						continue;
					
					int newI=(int) (Math.pow(10, (int)(Math.log10(lead)+1))*residual+lead);
					if(newI>i&&newI<=large&&!vec.contains(newI))
					{
						ans++;
//						System.out.print("("+i+", "+newI+") -- ");
						vec.add(newI);
						f2=true;
					}
					
//					System.out.println("for "+i+" checking with "+newI);
				}
//				if(f2) System.out.println();
				
			}
			
			pw.println("Case #"+counter+": "+ans);

		}
		pw.close();
	}
}
