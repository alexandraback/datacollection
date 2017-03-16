import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;


public class RoundCProb3 {
public static void main(String[] args) throws IOException {
	Scanner sc = new Scanner(new File("RCP3.in"));
//	BufferedWriter out = new BufferedWriter(new FileWriter(new File("p1.out")));
	
	int T = sc.nextInt();
	for(int t=1; t<=T; ++t)
	{
		int N=sc.nextInt(), M=sc.nextInt(), K=sc.nextInt();
		int minDim = Math.min(M,N);
		int maxDim = Math.max(M,N);
		if(minDim<=2)
			System.out.println("Case #"+t+": "+K);
		else
		{
			int total=0, area=0;
			int max_total=2*(M+N)-4;
			while(total<=max_total)
			{
				if(area>=K)
					break;
				if(area+1==K)
				{
					++total;
					break;
				}
				total+=2;
				if(total+2==max_total)
				{
					area=M*N-2;
					continue;
				}
				if(total==max_total)
				{
					area=M*N;
					continue;
				}
				if(total%4==0) // diamond
				{
					if(total/2+1<=minDim)//fits
					{
						area=(total*total)/8+total/2+1;
					}
					else
					{
						int a=(total-2*(minDim-2))/2;
						int dif=maxDim-minDim;
						int b=minDim-2*(dif/2);
						int c=minDim-2*((dif+1)/2);
						area=area(a, b, c, total);
					}
				}
				else if(total%4==2) // long diamond
				{
					if(total/2<=minDim && total/2+1<=maxDim)//fits
					{
						area=(total+2)*(total+2)/8;
					}
					else
					{
						int a=(total-2*(minDim-2))/2;
						int dif=maxDim-minDim;
						int b=minDim-2*(dif/2);
						int c=minDim-2*((dif+1)/2);
						area=area(a, b, c, total);
					}
				}
			}
			System.out.println("Case #"+t+": "+total);
		}
	}
	
	
}
static int area(int a, int b, int c, int per)
{
	if(a>2)
		return area(a-2, b, c, per)-2*(a-2);
	if(b>2)
		return area(a, b-2, c, per)-(b-2);
	if(c>2)
		return area(a, b, c-2, per)-(c-2);
	if(a==2 && b==2)
		return (per*per)/8+per/2;
	if(a==2 || b==2)
		return (per+2)*(per+2)/8;
	else
		return (per*per)/8+per/2+1;
}
}
