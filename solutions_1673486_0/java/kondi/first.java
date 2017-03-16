import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.Scanner;
import java.util.StringTokenizer;
 

public class first { 

	 
	public static void main (String[]args) throws IOException
	{  
		FileWriter wr = new FileWriter(new File("output.out")); 
		Scanner scan = new Scanner(new   File("input.in")); 
		int test = scan.nextInt(); 
		for(int i = 0 ; i < test ; i++)
		{ 
			int A = scan.nextInt();
			int B = scan.nextInt(); 
			System.out.println(A + "   "+ B);
			double [] pos = new double[A];
			scan.nextLine();
			 Scanner sc = new Scanner(scan.nextLine()); 
			// System.out.println(sc.nextDouble());
			for(int j = 0; j< A ; j++){
				System.out.println( j + "  jj ");
				pos[j] = sc.nextDouble();
				
			}
			double mistake = 1;
			for(int j = 0; j < A ; j++)
				mistake*=pos[j];
			mistake = 1-mistake;
			double first = mistake*(2*B-A+2) + (1-mistake)* (B-A+1);
			double second = 11111.0;
			for(int j = 1 ; j <=A ; j++)
			{
				 
				double mis = 1;
				for(int g = 0; g < A-j ; g++)
					mis*=pos[g];
				mis = 1-mis;
				double total = mis *(2*B-A+2+2*j) + (1-mis)* (2*j+B-A+1);
				if(total < second)second = total;
			}
			String ret = "Case #"+ (i+1)+": ";
			double r = Math.min(first , Math.min(second, (double)(B+2) ));
			//Scanner sc = new Scanner (scan.nextLine());
		 
			wr.write(ret +r+ "\n");
		}
		
		
		
		 
		 wr.flush();
	}
}
