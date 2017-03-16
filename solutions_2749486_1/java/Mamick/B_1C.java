import java.io.*;
import java.util.*;
import java.lang.*;
 
public class B_1C {
    
    public static void main(String[] args) {
		try 
		{
			Scanner s = new Scanner(new File("B-large.in"));
			
			FileOutputStream out = new FileOutputStream(new File("lawn2.txt"));
			PrintStream p = new PrintStream(out);
			
			int num=s.nextInt();
			for(int n=1;n<=num;n++){
				char [] moves=new char[10000];
				for(int i=0;i<moves.length;i++){
					moves[i]='a';
				}
				p.print("Case #"+n+": ");
				int x=s.nextInt();
				int y=s.nextInt();
				boolean negx=x<0;
				boolean negy=y<0;
				x=Math.abs(x);y=Math.abs(y);
				
				int numpos=0;
				int curx=-x;
				int jumpn=1;
				while(curx+jumpn<=y)
				{
					curx+=jumpn;
					jumpn++;
					numpos++;
				}
				if(curx+jumpn-y<y-curx){
					curx+=jumpn;
					jumpn++;
					numpos++;
					negy=!negy;
				}
				for(int i=numpos;i>=1;i--){
					if(i<=x){
						x-=i;
						if(negx)
							moves[i]='W';
						else
							moves[i]='E';
					}
				}
				for(int i=1;i<=numpos;i++){
					if(moves[i]=='a')
					{
						y-=i;
						if(negy)
							moves[i]='S';
						else
							moves[i]='N';
					}
				}
				for(int i=1;i<=numpos;i++){
					p.print(moves[i]);
				}
				while(y>0){
					y--;
					if(negy)
						p.print("NS");
					else
						p.print("SN");
				}
				p.println();
			}
			
			p.close();
		}
		catch(IOException e)
		{
			System.out.println("There was a problem:" + e);
		
		}
    }
}
