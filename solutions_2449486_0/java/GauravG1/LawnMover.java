/*  
    Author: Gaurav Gupta
    Date:   Apr 13, 2013
 */
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;
public class LawnMover {

	
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub.

		FileWriter fw = new FileWriter("ProblemB.txt");
		PrintWriter pw = new PrintWriter(fw);

		Scanner sc = new Scanner(System.in);

		int T = sc.nextInt();
		String result[]= {"YES","NO"};
		

		for (int i = 0; i < T; i++) {
			
			int N= sc.nextInt();
			int M= sc.nextInt();
	
			int arr[][]= new int [N][M];
			int test[][]= new int [N][M];
			int table[]= new int [101];
			
			int X=0;
			int ans=0;
			
			
			for(int j =0; j<N; j++)
				for(int k=0;k<M ; k++)
				{
					arr[j][k]= sc.nextInt();
					test[j][k]= 100;
					table[arr[j][k]]++;
				}
			
	
			boolean cut=true;
			for(int j=100; j>=1; j-- )
			{
				if(table[j]>0)
				{
					//horizontal fill
					for(int k=0; k<N; k++)
					{
						cut=true;
						for(int l=0;l<M ; l++)
						{
							if(arr[k][l]> j)
							{	cut=false;
								break;
							}
						}
						if(cut)
							for(int l=0;l<M ; l++)
								test[k][l]= j;
					}
					
					//vertical fill
					for(int k=0; k<M; k++)
					{
						cut=true;
						for(int l=0;l<N ; l++)
						{
							if(arr[l][k]> j)
							{	cut=false;
								break;
							}
						}
						if(cut)
							for(int l=0;l<N ; l++)
								test[l][k]= j;
					}
					
				}//end if
			}// end for j
			
			ans=0;
			for(int k=0; k<N; k++)
			{
				for(int l=0;l<M ; l++)
				{
					if (arr[k][l]!=test[k][l])
					{
						ans=1;
						break;
					}
				}
				if(ans==1)
					break;
			}
			
	
			
			

			pw.println("Case #" + (i + 1) + ": " + result[ans]);
			System.out.println("Case #" + (i + 1) + ": " + result[ans]);
		}// end for T

		pw.close();

	}
}
