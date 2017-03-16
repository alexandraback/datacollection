import java.util.*;
import java.io.*;
public class bullseye {
	public static void main(String[] args) throws IOException{
		BufferedReader in = new BufferedReader (new FileReader ("A-small-attempt2.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("bull.out")));
		int n = Integer.parseInt(in.readLine());
		for(int i = 0; i<n;i++) {
			//solve here
			StringTokenizer s = new StringTokenizer(in.readLine());
			double r = Double.parseDouble(s.nextToken());
			double t = Double.parseDouble(s.nextToken());
			double total = 0;
			double count = 0;
			while (total<=t) {
				double a = ((r+1)*(r+1) - r*r);
				if(total+a<=t) {
					total+=a;
					count+=1;
					System.out.println(total + " " + t + " " + r + " " + a);
					r+=2;
				}
				else{ break;}

			}
			out.println("Case #" + (i+1) + ": " + (int)count);
		}
		out.close();
		in.close();
	}
}
