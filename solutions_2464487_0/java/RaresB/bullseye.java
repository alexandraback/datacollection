import java.io.*;
import java.util.*;


public class bullseye {
	public static void main(String args[]) throws IOException{
		int testCases;
		long maxCircles = 0, radius, totalPaint, difference;
		BufferedReader f = new BufferedReader(new FileReader("A-small-attempt0 (2).in"));
		PrintWriter p = new PrintWriter(new BufferedWriter(new FileWriter("bulls.out")));
		StringTokenizer st = new StringTokenizer(f.readLine());
		testCases = Integer.parseInt(st.nextToken());
		for(int i = 0; i < testCases; i++){
			maxCircles = 0;
			radius = 0;
			st = new StringTokenizer(f.readLine());
			radius = Long.parseLong(st.nextToken());
			totalPaint = Long.parseLong(st.nextToken());
			while(totalPaint>0){
				difference = (long) (Math.pow(radius+1, 2) - Math.pow(radius, 2));
				if( difference <= totalPaint){
					maxCircles++;
					totalPaint -= difference;
					radius+=2;
				}else{
					totalPaint = 0;
				}
			}
			p.append("Case #" + (i+1) + ": " + maxCircles + "\n");
			}
		p.close();
		System.exit(0);
		}
}