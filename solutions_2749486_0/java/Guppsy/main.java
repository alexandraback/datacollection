import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;

public class main {

	static int c;
	static double t;
	static double r;
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader( new FileReader("inp.in"));
		Scanner scr = new Scanner(br);
		
		BufferedWriter wr = new BufferedWriter(new FileWriter("output.txt"));
		
		c = scr.nextInt();
		
		System.out.println("Total Cases : " + c);
		
		for(int i=0;i<c;i++){
			System.out.println(i);
			int x = scr.nextInt();
			int y = scr.nextInt();
			
			wr.write("Case #" + (i+1) + ": ");
			if(x>=0)
				for(int j=0;j<x;j++)
					wr.write("WE");
			if(x<=0)
				for(int j=0;j>x;j--)
					wr.write("EW");
			if(y>=0)
				for(int j=0;j<y;j++)
					wr.write("SN");
			if(y<=0)
				for(int j=0;j>y;j--)
					wr.write("NS");
			wr.write("\r\n");
		}
		wr.close();
	}	
}