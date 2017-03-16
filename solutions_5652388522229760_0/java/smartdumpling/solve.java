package solve;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashSet;
import java.util.Scanner;

import javax.swing.JFrame;


public class solve {

	public static int solvea(int t) {
		// TODO Auto-generated constructor stub
		if(t==0)
			return 0;
		int s = 0;
		HashSet<Integer> hset = 
	               new HashSet<Integer>();
		int a=0;
		for(int i = 1;i <= 200; i++)
		{
			a=i*t;
			while(a > 0)
			{
				hset.add(a%10);
				a=a/10;
			}
			if( hset.size()==10)
			{
				return i*t;
			}
		}
		return 0;
	}
	public static void main(String[] args) throws IOException {
		Scanner scanner = new Scanner(new File("A-small-attempt0.in"));
		//int [] tall = new int [100];
		int total = scanner.nextInt();
		System.out.println(total);
		int a;
		FileWriter fw = new FileWriter("out.txt");
		for(int i=0;i<total;i++){
		   a = scanner.nextInt();
		   int n=solvea(a);
		   if(n==0)
		   {
			   System.out.println(n);
			   fw.write("Case #"+(i+1)+": INSOMNIA\n");
		   }
		   else
		   {
			   System.out.println( n);
			   fw.write("Case #"+(i+1)+": "+n+"\n");
		   }
		}
        fw.close();
		
	}

}
