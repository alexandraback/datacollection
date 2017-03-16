import java.util.Scanner;
import java.io.*;

public class a{

	public static void main(String[] args){
		
		Scanner sc = new Scanner(System.in);
		
		int c = 1;
		int t = sc.nextInt();
		sc.nextLine();
		
		while(c<=t){
			String[] s = sc.nextLine().split("/");
			long p = Long.valueOf(s[0]);
			long q = Long.valueOf(s[1]);
			int g = 0;
			int sol = -1;

			if(p==q&&p==1){sol=0;}
			while(p-q<0){
				if(q%2==1){ sol = -1; break; }
				q/=2;
				g++;
				sol = g;
			}
			if(!get(p,q,g)){sol = -1;}


			
			System.out.println("Case #"+c+": "+ ((sol>=0)?sol:"impossible") );

			c++;
		}
		
		sc.close();

	}

	public static boolean get(long p, long q, int g){
		if(g>40){return false;}
		else if(p-q>0){return get(p-q,q,g);}
		else if(p-q==0){return true;}
		else if(q%2==1){return false;}
		else{ return get(p,q/2,g+1); }
	}

	
}