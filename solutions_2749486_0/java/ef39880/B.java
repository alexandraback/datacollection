package round1C2013;

import java.io.PrintWriter;
import java.util.Scanner;

public class B {

	static Scanner scan = new Scanner(System.in);
	static PrintWriter out = new PrintWriter(System.out);

	public static void main(String[] args) {
		int T = si();
		for (int i = 0; i < T; i++) {
			int gx = si(),gy = si(),stp = 1,x = 0,y = 0;
			String ans = "";
			while(!(x==gx && y==gy)){
				if(Math.abs(gx-x)<stp && Math.abs(gy-y)<stp){
					if(gx!=x){
						if(gx<x){
							ans+="EW";
							x--;
						}
						else{
							ans+="WE";
							x++;
						}
					}
					else{
						if(gy<y){
							ans+="NS";
							y--;
						}
						else{
							ans+="SN";
							y++;
						}
					}
					stp+=2;
				}
				else{
					if(Math.abs(gx-x)>=stp){
						if(gx<x){
							ans+="W";
							x-=stp;
						}
						else{
							ans+="E";
							x+=stp;
						}
					}else{
						if(gy<y){
							ans+="S";
							y-=stp;
						}
						else{
							ans+="N";
							y+=stp;
						}
					}
					stp++;
				}
			}
			out.println("Case #"+(i+1)+": "+ans);
		}
		out.flush();
	}

	static int si() {
		return Integer.parseInt(scan.next());
	}
}
