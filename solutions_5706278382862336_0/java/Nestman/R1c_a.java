package r1c_a;

import java.io.*;
import java.util.*;

public class R1c_a {
	
	public static void main(String[] args) throws FileNotFoundException, IOException{
		// TODO Auto-generated method stubScanner 
	Scanner sc=new Scanner(new BufferedReader(new InputStreamReader (new FileInputStream("CodeJam2014/r1c_a/A-small-attempt0 (1).in"))));
		//Scanner sc=new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		PrintWriter ou=new PrintWriter(new FileWriter("CodeJam2014/r1c_a/testa.out"));
		int res,rep,i,j,p,q,tp,tq,cp,cq;
		boolean vis;
		String s;
		String[] s2=new String[3];
		String out="";
		
		res=sc.nextInt();
		s=sc.nextLine();
		for(rep=1;rep<=res;rep++){
			s=sc.nextLine();
			s2=s.split("/");
			p=Integer.parseInt(s2[0]); q=Integer.parseInt(s2[1]);
			//p=sc.nextInt(); q=sc.nextInt();
			tp=p; tq=q;
			cp=0; cq=0;
			vis=true;
			while(tp!=1){
				tp=tp>>1;
				cp++;
			}
			while(tq!=1){
				if (tq%2==1) {vis=false; break;}
				tq/=2;
				cq++;
			}
			ou.print("Case #"+rep+": ");
			if (!vis) ou.print("impossible");
			else ou.print(cq-cp);
			if (res!=rep) ou.println();
			System.out.println(cq-cp);
		}
		ou.close();
	}
}