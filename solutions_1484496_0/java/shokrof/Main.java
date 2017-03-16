import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;


public class Main {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		Scanner input=new Scanner(new File("input.txt"));
		FileWriter writer=new FileWriter("output.txt",false);
		PrintWriter output=new PrintWriter(writer);
		int t=input.nextInt();
		for(int o=1;o<=t;o++)
		{
			int A=input.nextInt();
			int B=input.nextInt();
			double [] prob=new double[A];
			for(int i=0;i<A;i++)
				prob[i]=input.nextDouble();
			
			int keeptypingKeystrokes_right=(B-A)+1;
			int keeptypingKeystrokes_wrong=(B-A)+1+B+1;
			
			double [] prob_keeptypingKeystrokes_right=new double[A+1];
			prob_keeptypingKeystrokes_right[0]=0;
			prob_keeptypingKeystrokes_right[1]=prob[0];
			for(int i=2;i<=A;i++)
				prob_keeptypingKeystrokes_right[i]=prob_keeptypingKeystrokes_right[i-1]*prob[i-1];
			double minmum=B+2;
			double temp=keeptypingKeystrokes_right*prob_keeptypingKeystrokes_right[A]+keeptypingKeystrokes_wrong*(1-prob_keeptypingKeystrokes_right[A]);
			minmum=Math.min(temp, minmum);
			
			for(int i=1;i<A;i++)
			{
				int num_r=1+2*(i)+(B-A);
				int num_w=1+2*(i)+(B-A)+B+1;
				temp=num_r*prob[i]+num_w*(1-prob[i]);
				minmum=Math.min(temp, minmum);
			}
			
			
					
					
			output.printf("Case #%d: %.6f\n",o,minmum);
		}
		output.close();


	}

}
