import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;


public class D {
	static BufferedReader br;
	static PrintWriter out;
	static StringTokenizer tokenizer;
	
	public static void main(String[]args) throws IOException{
		File inF = new File("/home/taras/workspace/Google_Code_Jam_2014_ Qualification_Round/src/DSmall.txt");
		
		File outF = new File("/home/taras/workspace/Google_Code_Jam_2014_ Qualification_Round/src/DSmall_out.txt");
		FileReader reader = new FileReader(inF);
		FileWriter writer = new FileWriter(outF);
		br = new BufferedReader(reader);
		out = new PrintWriter(writer);
		
		tokenizer = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(tokenizer.nextToken());
		
		double[] a,b;
		
		for(int z=0;z<n;z++){
			tokenizer = new StringTokenizer(br.readLine());
			int m = Integer.parseInt(tokenizer.nextToken());
			a = new double[m];
			b = new double[m];
			
			tokenizer = new StringTokenizer(br.readLine());
			for(int j=0;j<m;j++){
				a[j] = Double.parseDouble(tokenizer.nextToken());
			}
			
			tokenizer = new StringTokenizer(br.readLine());
			for(int j=0;j<m;j++){
				b[j] = Double.parseDouble(tokenizer.nextToken());
			}
			
			Arrays.sort(a);
			Arrays.sort(b);
			int p1 = 0;
			
			int i = 0;
			int j = 0;
			while(j<m && i<m){
				while(j<m && b[j]<a[i]){
					j++;
					p1++;
				}
				i++;
				j++;
			}
			int p2 = 0;
			i = 0;
			j = 0;
			
			while(j<m && i<m){
				while(i<m && b[j]>a[i]){
					i++;
				}
				if(i<m)p2++;
				i++;
				j++;
			}
			out.append("Case #"+(z+1)+": ");
			out.append(p2+" "+p1+" \n");
		}
		
		out.flush();
		out.close();
	}
}
