package cf;

import java.io.*;
import java.lang.*;
import java.math.*;
import java.util.*;

import tools.*;

public class B extends cf {
	public static void main(String[] args) {B b=new B();}
	public void run(InputReader in, PrintWriter out) {
		int t=in.nextInt();
		for (int k=1;k<=t;k++) {
			String c=in.next(),j=in.next(),mc="",mj="";
			int n=c.length();
			for (int i=0;i<n;i++) {
				if (c.charAt(i)=='?' && j.charAt(i)=='?') {
					mc+="0";
					mj+="0";
				}
				else if (c.charAt(i)=='?' && j.charAt(i)!='?') {
					mc+=j.substring(i,i+1);
					mj+=j.substring(i,i+1);
				}
				else if (c.charAt(i)!='?' && j.charAt(i)=='?') {
					mc+=c.substring(i,i+1);
					mj+=c.substring(i,i+1);
				}
				else {
					mc+=c.substring(i,i+1);
					mj+=j.substring(i,i+1);
				}
			}
			out.println("Case #"+k+": "+mc+" "+mj);
		}
	}
}