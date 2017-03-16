import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;


public class R1_ProblemB {

	public static String name="problemB";
	public static void main(String[] args) throws IOException{
		BufferedReader buf=new BufferedReader(new FileReader(name+".txt"));
		PrintWriter printer=new PrintWriter(name+"_out.txt");
		int N=Integer.parseInt(buf.readLine());

		for(int i=1;i<=N;i++){
			printer.print("Case #"+i+": ");
			//do stuff
			String[] p=buf.readLine().split(" ");
			double r=Double.parseDouble(p[0]);
			//r=35;
			double t=Double.parseDouble(p[1]);
			//t=71;
			double k=(-2*r-3)+Math.sqrt((2*r+3)*(2*r+3)-4*2*(2*r+1-t));
			//System.out.println(k);
			k/=4d;
			if(k!=Math.floor(k))
				k++;
			else if(2*k*k+(2*r+3)*k+2*r+1==t){
				//System.out.println("!"+k);
				k++;
			}
			printer.println((long)Math.floor(k));
		}
		printer.close();
	}
	public static boolean works(double d){
		if(d!=Math.floor(d))
			return false;
		for(long g=2;g<=d;g++){
			//System.out.println(d);
			if(d==1)
				return true;
			else if(g>d)
				return false;
			else if(d/(g*g)==Math.floor(d/(g*g)))
				while(d/(g*g)==Math.floor(d/(g*g))){
					d/=g*g;
					System.out.println("*"+d);
				}
			System.out.println("^"+d);
		}
		return true;
	}

}
