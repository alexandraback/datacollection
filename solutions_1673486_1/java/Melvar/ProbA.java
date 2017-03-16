import java.io.File;
import java.io.BufferedReader;
import java.io.PrintWriter;
import java.io.FileWriter;
import java.io.FileReader;
import java.lang.Math;
import java.util.Arrays;

public class ProbA {

	static String inputfile = "A-large.in";
	static String outputfile = "A-large.out";

		public static void main(String args[]) throws Exception {
			
			BufferedReader in = new BufferedReader(new FileReader(inputfile));
			PrintWriter out = new PrintWriter(new FileWriter(outputfile));
	
			String line = in.readLine();
			String[] inputdata =line.split(" ");

			int TCASES = Integer.parseInt(inputdata[0]);

			double[] exp = new double[100002];
			double[] p = new double[100002];

			for (int i=1;i<=TCASES;i++){

				line = in.readLine();
			        inputdata =line.split(" ");
				int A = Integer.parseInt(inputdata[0]);
				int B = Integer.parseInt(inputdata[1]);	
				
				line = in.readLine();
			        inputdata =line.split(" ");
				
				p[0]= Double.parseDouble(inputdata[0]);
				for (int j=1;j<A;j++) p[j]=p[j-1]*Double.parseDouble(inputdata[j]);	
		
				exp[0]=B+2;
				exp[1]=(p[A-1]*(-B-1))+(2*B)-A+2;
				for(int j=1;j<A;j++) exp[j+1]=(-B-1)*p[A-j-1]+(2*j)+2*B+2-A;
				exp[A+1]=A+1+B;
				
				Arrays.sort(exp,0,A+1) ;
		
				out.println("Case #"+i+": "+exp[0]);
			}

			in.close();
			out.flush();
			out.close();

		}
}
