package r1b_b;

import java.io.*;
import java.util.*;

public class r1b_b {
	public static void main(String[] args) throws FileNotFoundException, IOException{
		// TODO Auto-generated method stubScanner 
	Scanner sc=new Scanner(new BufferedReader(new InputStreamReader (new FileInputStream("CodeJam2014/r1b_b/B-small-attempt0.in"))));
	//	Scanner sc=new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		PrintWriter ou=new PrintWriter(new FileWriter("CodeJam2014/r1b_b/r1b_b.out"));
		int res,rep,i,j,a,b,k,x,ans;
		
		String out;
		
		res=sc.nextInt();
		for(rep=1;rep<=res;rep++){
			a=sc.nextInt();
			b=sc.nextInt();
			k=sc.nextInt();
			ans=0;
			//System.out.println(a&b);
			
			for(i=0;i<a;i++)
				for(j=0;j<b;j++){
					x=i&j;
					if (x<k) ans++;
				}
			ou.print("Case #"+rep+": "+ans);
			System.out.println(ans);
			if (rep!=res) ou.println();
		}
		
		ou.close();
	}
}
