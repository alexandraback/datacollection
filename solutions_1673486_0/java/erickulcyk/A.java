package a;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class A
{

	public A()
	{
		try {
			Scanner s = new Scanner(new File("/home/kulcyk/workspace/GCJ/asmall.in"));
			int t = s.nextInt();
			BufferedWriter bf = new BufferedWriter(new FileWriter(new File("/home/kulcyk/workspace/GCJ/aout")));
			
			for(int i = 0; i< t; i++)
			{
				int a = s.nextInt();
				int b = s.nextInt();
				
				double[] prob = new double[b];
				
				for(int j = 0; j < a; j++)
				{
					prob[j] = s.nextDouble();
				}
				
				double maxKeyStrokes = b+2;
				
				for(int j = 0; j < a; j++)
				{
					double p = 1;
					for(int k = 0; k <a-j; k++)
					{
						p*=prob[k];
					}
					
					maxKeyStrokes = Math.min(maxKeyStrokes, b-(a-j)+1+j+(b+1)*(1.0-p));
				}
				
				System.out.printf("Case #"+(i+1)+": "+"%.6f"+"\n", maxKeyStrokes);
			}
			
			bf.flush();
			bf.close();
			
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public static void main(String[] args)
	{
		new A();
		
		//System.out.println("Done!");
	}

}
