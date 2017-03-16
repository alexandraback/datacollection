package gcj2015;

import java.io.*;
import java.util.*;

public class QualiD {
	public static void main(String[] args) throws IOException, FileNotFoundException {
		// TODO Auto-generated method stub
		//Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(new FileInputStream("other/gcj2015/D-small-attempt1.in"))));
		PrintWriter ou = new PrintWriter("other/gcj2015/qualiD.txt");

		int res,rep,i,j,x,r,c;
		boolean flag;
		
		res =sc.nextInt();
		for(rep=1;rep<=res;rep++) {
			flag = true;
			
			x = sc.nextInt(); r = sc.nextInt(); c = sc.nextInt();
			if (x>6) flag = false;
			
			if ((r*c) % x!=0) flag = false;
			
			if (((x>=3)&&(x<=6))&&flag) {
				
				if (x==3) {
					if (Math.min(r,c) == 1) flag = false;
				}
				
				if (x==4) {					
					if (Math.min(r, c) < 3) flag = false;				
				}
				
				if (x==5) {
					if (Math.min(r, c)<3) flag = false;
					if ((Math.min(r, c) == 3) && (r*c == 15)) flag = false;
				}
				
				if (x==6) {
					if (Math.min(r, c)<4) flag = false;
					
				}
			}
			
			ou.printf("Case #%d: ", rep);
			if (flag) ou.println("GABRIEL");
			else ou.println("RICHARD");
		}
		
		ou.close();
	}
}