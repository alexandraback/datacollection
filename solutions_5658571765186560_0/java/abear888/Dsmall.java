import java.io.*;
import java.util.*;

public class Dsmall {
	public static void main (String[]args)throws IOException{
		BufferedReader f=new BufferedReader(new FileReader("Dsmall.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("Dsmall.out")));
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
		}
		out.close();
		System.exit(0);
	}
}