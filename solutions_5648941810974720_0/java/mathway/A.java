package cf;

import java.io.*;
import java.lang.*;
import java.math.*;
import java.util.*;

import tools.*;

public class A extends cf {
	public static void main(String[] args) {A a=new A();}
	public void run(InputReader in, PrintWriter out) {
		int t=in.nextInt();
		for (int i=1;i<=t;i++) {
			int[] c=new int[10];
			String s=in.next(),u="";
			c[0]=count(s,'Z');
			c[2]=count(s,'W');
			c[8]=count(s,'G');
			c[3]=count(s,'T')-c[2]-c[8];
			c[4]=count(s,'R')-c[0]-c[3];
			c[6]=count(s,'X');
			c[5]=count(s,'F')-c[4];
			c[7]=count(s,'V')-c[5];
			c[1]=count(s,'O')-c[0]-c[2]-c[4];
			c[9]=count(s,'I')-c[5]-c[6]-c[8];
			
			for (int j=0;j<=9;j++) {
				for (int k=0;k<c[j];k++) {
					u+=j+"";
				}
			}
			out.println("Case #"+i+": "+u);
		}
	}
	private int count(String s,char y) {
		int c=0;
		for (char x:s.toCharArray()) {
			if (x==y) {
				c++;
			}
		}
		return c;
	}
}