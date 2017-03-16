//Program by Matthew Savage
//With help from the TJHSST SCT Grader Example Class

import java.io.*;
import java.util.*;

public class paint{
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new FileReader("A-small-attempt0.in"));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("paint.out")));
		
		int testCases = Integer.parseInt(br.readLine());
		
		for(int t = 1; t <= testCases; t++){
			pw.print("Case #" + t + ": ");
			StringTokenizer st = new StringTokenizer(br.readLine(), " ");
			long r = Long.parseLong(st.nextToken());
			long p = Long.parseLong(st.nextToken());
			
			long ans = 0;
			long it = 0;
			while(p >= 2 * (r + 2*it) + 1){
				p -= 2 * (r + 2*it) + 1;
				it++;
			}
			
			pw.println(it);
		}
		
		br.close();
		pw.close();
	}
}