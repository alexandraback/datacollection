package Q2015;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class D {
public static void main(String args[]) throws NumberFormatException,IOException {
		
		Stdin in = new Stdin();
		PrintWriter out = new PrintWriter("D-small-attempt1.out");
		int T=in.readInt();
		int x,r,c;
		for(int i=1;i<=T;i++){
			x=in.readInt();
			r=in.readInt();
			c=in.readInt();
			if(r>c){
				r^=c;
				c^=r;
				r^=c;
			}	
			if(x==1){
				print(out,"GABRIEL",i);
				continue;
			}
			if(x==2){
				if(r%2==0||c%2==0)
					print(out,"GABRIEL",i);
				else
					print(out,"RICHARD",i);
				continue;
			}
			if(x==3){
				if((r==2&&c==3)||r==3)
					print(out,"GABRIEL",i);
				else
					print(out,"RICHARD",i);
				continue;
			}
			if(r>=3&&c==4)
				print(out,"GABRIEL",i);
			else
				print(out,"RICHARD",i);				
		}
		out.flush();
		out.close();

	}
    private static int min(int a,int b){
    	return a<b?a:b;
    } 
	private static void print(PrintWriter out,Object t,int cases){
		out.println("Case #"+cases+": "+t);
	}

	private static class Stdin {
		BufferedReader br;

		StringTokenizer st = new StringTokenizer("");

		private Stdin() throws FileNotFoundException {
			br = new BufferedReader(new FileReader("D-small-attempt1.in"));

		}

		private String readNext() throws IOException {

			while (!st.hasMoreTokens())
				st = new StringTokenizer(br.readLine());
			return st.nextToken();
		}

		private int readInt() throws IOException, NumberFormatException {

			return Integer.parseInt(readNext());

		}

		private long readLong() throws IOException, NumberFormatException {

			return Long.parseLong(readNext());

		}
		private double readDouble() throws IOException, NumberFormatException {

			return Double.parseDouble(readNext());

		}
	}
}
