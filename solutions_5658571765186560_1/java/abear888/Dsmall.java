import java.io.*;
import java.util.*;

public class Dsmall {
	public static void main (String[]args)throws IOException{
		BufferedReader f=new BufferedReader(new FileReader("Dlarge.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("Dlarge.out")));
		int t=Integer.parseInt(f.readLine());
		for (int cases=1; cases<=t; cases++){
			StringTokenizer st=new StringTokenizer(f.readLine());
			int x=Integer.parseInt(st.nextToken());
			int r=Integer.parseInt(st.nextToken());
			int c=Integer.parseInt(st.nextToken());
			if (x==1){
				out.println("Case #"+cases+": GABRIEL");
			}
			if (x==2){
				if ((r*c)%2==0){
					out.println("Case #"+cases+": GABRIEL");
				}else{
					out.println("Case #"+cases+": RICHARD");
				}
			}
			if (x==3){
				if ((r==2 && c==3) || (r==3 && c==2) || (r==4 && c==3) || (r==3 && c==4) || (r==3 && c==3)){
					out.println("Case #"+cases+": GABRIEL");
				}else{
					out.println("Case #"+cases+": RICHARD");
				}
			}
			if (x==4){
				if ((r==4 && c==4) || (r==3 && c==4) || (r==4 && c==3)){
					out.println("Case #"+cases+": GABRIEL");
				}else{
					out.println("Case #"+cases+": RICHARD");
				}
			}
			if (x==5){
				if ((r%5==0 && c>=4) || (c%5==0 && r>=4)|| (r%5==0 && r>5 && c==3) || (c%5==0 && c>5 && r==3)){
					out.println("Case #"+cases+": GABRIEL");
				}else{
					out.println("Case #"+cases+": RICHARD");
				}
			}
			if (x==6){
				if ((r*c)%6==0 && Math.max(r,c)>=6 && Math.min(r,c)>=4){
					out.println("Case #"+cases+": GABRIEL");
				}else{
					out.println("Case #"+cases+": RICHARD");
				}
			}
			if (x>=7){
				out.println("Case #"+cases+": RICHARD");
			}
		}
		out.close();
		System.exit(0);
	}
}