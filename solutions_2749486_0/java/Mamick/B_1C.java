import java.io.*;
import java.util.*;
import java.lang.*;
 
public class B_1C {
    
    public static void main(String[] args) {
		try 
		{
			Scanner s = new Scanner(new File("B-small-attempt0.in"));
			
			FileOutputStream out = new FileOutputStream(new File("lawn2.txt"));
			PrintStream p = new PrintStream(out);
			
			int num=s.nextInt();
			for(int n=1;n<=num;n++){
				p.print("Case #"+n+": ");
				int x=s.nextInt();
				int y=s.nextInt();
				boolean negx=x<0;
				boolean negy=y<0;
				x=Math.abs(x);y=Math.abs(y);
				int curx=0;int cury=0;
				while(curx<x){
					if(negx){
						p.print("EW");
					}
					else
						p.print("WE");
					curx++;
				}
				while(cury<y){
					if(negy){
						p.print("NS");
					}
					else
						p.print("SN");
					cury++;
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
