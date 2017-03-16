/*
ID: tonyjia1
LANG: JAVA
TASK: password
 */
import java.io.*;
import java.util.*;

public class password {
	public static void main(String[] args) throws IOException {
		PrintWriter out;
		BufferedReader f;

		try {
			f = new BufferedReader(new FileReader("password.in"));
			out = new PrintWriter(new BufferedWriter(new FileWriter(
					"password.out")));
		} catch (Exception e) {
			f = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
		}
		int n=Integer.parseInt(f.readLine());
		for(int i=0;i<n;i++){
			StringTokenizer token = new StringTokenizer(f.readLine());
			int already = Integer.parseInt(token.nextToken());
			int numchars = Integer.parseInt(token.nextToken()); //expected numleft+numchars+2
			int numleft = numchars-already; //expected numleft+1
			double[] probs = new double[already];
			token=new StringTokenizer(f.readLine());
			for(int j=0;j<already;j++){
				probs[j] = Double.parseDouble(token.nextToken());
			}
			double best=Double.MAX_VALUE;
			for(int j=0;j<already+1;j++){
				double probright=1;
				for(int k=0;k<j;k++){
					probright*=probs[k];
				}
				double totalexpected=probright*(1+numchars-j+already-j);
				totalexpected+=((1.0-probright)*(1+numchars-j+already-j+1+numchars));
				if(totalexpected<best){
					best=totalexpected;
				}	
			}
			best=Math.min(best,numchars+2);
			out.println("Case #"+(i+1)+": "+best);
		}
		out.close();
		System.exit(0);
	}
}