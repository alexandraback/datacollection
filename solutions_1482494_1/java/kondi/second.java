import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.Scanner;
import java.util.StringTokenizer;
 

public class second { 

	 
	public static void main (String[]args) throws IOException
	{  
		FileWriter wr = new FileWriter(new File("output.out")); 
		Scanner scan = new Scanner(new   File("input.in")); 
		int test = scan.nextInt(); 
		for(int i = 0 ; i < test ; i++)
		{
			int N = scan.nextInt();
			String ret = "Case #"+ (i+1)+": ";
			int[] onestar = new int[N];
			int [] twostar = new int [N];
			for(int j = 0; j < N ; j++)
			{
				onestar[j] = scan.nextInt();
				twostar[j] = scan.nextInt();
			}
			boolean [] onedone = new boolean[N];
			boolean [] twodone = new boolean[N];
			int twoscompleted = 0;
			boolean incomplete = true;
			int levelsdone = 0;
			int sta = 0;
			boolean somethingdone = false;
			boolean toobad = false;
			while(incomplete)
			{
				somethingdone = false;
				if(twoscompleted == N)
				{
					incomplete = false;
					continue;
				}				
				boolean cont = false;
				for(int j = 0 ;j < N ; j++)
				{
					if(twostar[j] <= sta && !twodone[j])
					{
						somethingdone = true;
						cont = true;
						twodone[j] = true;
						if(onedone[j])
							sta++;
						else
							sta+=2;
						levelsdone++;
						twoscompleted++;
					}
				}
				if(cont)
					continue;
				int whichtomake = 0;
				int maxavailabletwo = 0;
				for(int j = 0 ;j < N ; j++ )
				{
					if(onestar[j] <=sta &&!onedone[j] && !twodone[j])
					{
						if(twostar[j]>maxavailabletwo)
						{
							maxavailabletwo = twostar[j];
							whichtomake = j;
							somethingdone = true;
						}
					}
				}
				if(somethingdone)
				{
					onedone[whichtomake ] = true;
					sta++;
					levelsdone++;
				}
				else
				{
					toobad = true;
					break;
				} 
			}
			//Scanner sc = new Scanner (scan.nextLine());
		 
			if(toobad)
			wr.write(ret + "Too Bad\n");
			else
				wr.write(ret + levelsdone + "\n");
		}
		
		
		
		 
		 wr.flush();
	}
		
	 
}
