import java.io.*;
import java.util.Arrays;
import java.util.Scanner;

public class B {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in;
		try {
			in = new Scanner(new File("C:\\temp\\google\\B-large.in"));
			int T = in.nextInt();
			for(int cas=1; cas<=T; cas++) {
				double C=in.nextDouble();
				double F=in.nextDouble();
				double X=in.nextDouble();
				
				double i=2;
				double remaining =X;
				double r=C*(i+F)/F;
				double total=0;
				
				while (r<remaining)
				{
					total=total+C/i;
					//remaining=remaining-C;
					i=i+F;
					
					r=C*(i+F)/F;
				}
				
				total=total+remaining/i;
				
				
				
				System.out.printf("Case #%d: %.7f\n", cas, total);	
			}
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}
