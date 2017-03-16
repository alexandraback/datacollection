import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.text.DecimalFormat;
import java.util.StringTokenizer;


public class B {
	static BufferedReader br;
	static PrintWriter out;
	static StringTokenizer tokenizer;
	
	public static void main(String[]args) throws IOException{
		File inF = new File("/home/taras/workspace/Google_Code_Jam_2014_ Qualification_Round/src/BSmall.txt");
		
		File outF = new File("/home/taras/workspace/Google_Code_Jam_2014_ Qualification_Round/src/BSmall_out.txt");
		FileReader reader = new FileReader(inF);
		FileWriter writer = new FileWriter(outF);
		br = new BufferedReader(reader);
		out = new PrintWriter(writer);
		
		tokenizer = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(tokenizer.nextToken());
		
		double c,f,x;
		for(int z=0;z<n;z++){
			tokenizer = new StringTokenizer(br.readLine());
			c = Double.parseDouble(tokenizer.nextToken());
			f = Double.parseDouble(tokenizer.nextToken());
			x = Double.parseDouble(tokenizer.nextToken());
			out.append("Case #"+(z+1)+": ");
			out.append(new DecimalFormat("0.0000000").format(find(c,f,x))+"\n");
		}
		
		out.flush();
		out.close();
	}

	private static double find(double c, double f, double x) {
		double minres = x/(2.0);
		double res = minres;
		double tn = 0;
		int i=0;
		do{
			minres = res;
			i++;
			tn+=(double)c/(double)(2+(i-1)*f);
			res = tn + (double)x/(double)(2+i*f);
		}while(res<minres &&(minres-res>0.00000001));
		return minres;
	}
}
