/*  
    Author: Gaurav Gupta
    Date:   Apr 13, 2013
 */
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;
public class Tic_Tac_Toe_Tomek {

	
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub.

		FileWriter fw = new FileWriter("ProblemA.txt");
		PrintWriter pw = new PrintWriter(fw);

		Scanner sc = new Scanner(System.in);

		int T = sc.nextInt();
		String result[]= {"X won","O won","Draw" ,"Game has not completed"};
		char arr[][]= new char [4][4]; 
		
		
		for (int i = 0; i < T; i++) {
			
			int X=0, O=0, dot=0;
			int ans=2;
			
			
			for(int j =0; j<4; j++)
				arr[j]= sc.next().toCharArray();
			
			//check horizontal
			if(ans==2||ans==3)
			for(int j =0; j<4; j++)
			{	
				X=0; O=0; 
				for(int k=0;k<4 ; k++)
				{
					if (arr[j][k]=='X')
					{	X++; O=0; }
					else if(arr[j][k]=='O')
					{	X=0; O++; }
					else if(arr[j][k]=='.')
					{	X=0; O=0; dot++; }
					else if(arr[j][k]=='T')
					{	X++; O++; }
					
				}
				
				if(X==4)
					ans=0;
				else if(O==4)
					ans=1;
				
			}
			
			//check vertical
			if(ans==2||ans==3)
			for(int j =0; j<4; j++)
			{	X=0; O=0;
				for(int k=0;k<4 ; k++)
				{
					
					if (arr[k][j]=='X')
					{	X++; O=0; }
					else if(arr[k][j]=='O')
					{	X=0; O++; }
					else if(arr[k][j]=='T')
					{	X++; O++; }		
				}
				
				if(X==4)
					ans=0;
				else if(O==4)
					ans=1;

			}

			X=0; O=0;
			//check diagonal 1
			if(ans==2||ans==3)
			for(int j =0; j<4; j++)
			{	
				if (arr[j][j]=='X')
				{	X++; O=0; }
				else if(arr[j][j]=='O')
				{	X=0; O++; }
				else if(arr[j][j]=='T')
				{	X++; O++; }
				
			}
			
			if(X==4)
				ans=0;
			else if(O==4)
				ans=1;
			
			X=0; O=0;
			//check diagonal 2
			if(ans==2||ans==3)
			for(int j =0; j<4; j++)
			{	
				if (arr[j][3-j]=='X')
				{	X++; O=0; }
				else if(arr[j][3-j]=='O')
				{	X=0; O++; }
				else if(arr[j][3-j]=='T')
				{	X++; O++; }
				
			}
			if(X==4)
				ans=0;
			else if(O==4)
				ans=1;

			if(ans==2||ans==3){
				if(dot==0)
					ans=2;
				else 
					ans=3;
			}
			
			pw.println("Case #" + (i + 1) + ": " + result[ans]);
			System.out.println("Case #" + (i + 1) + ": " + result[ans]);
		}

		pw.close();

	}
}
