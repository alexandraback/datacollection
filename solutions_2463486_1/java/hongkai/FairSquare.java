import java.util.*;
import java.io.*;

public class FairSquare {
	public static void main(String[] args) throws IOException{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("file")));
		long[] palins = new long[39];
		int numPalins = 0;
		for(long i=1; i < 10000000; i++){
			if(isPalin(i))
				if(isPalin(i*i)){
					palins[numPalins] = i*i;
					numPalins++;
				}
		}
		StringTokenizer st = new StringTokenizer(in.readLine());
		int cases = Integer.parseInt(st.nextToken());
		for(int i=1; i<= cases; i++){
			st = new StringTokenizer(in.readLine());
			long min = Long.parseLong(st.nextToken());
			long max = Long.parseLong(st.nextToken());
			
			for(int n=0; n < palins.length; n++){
				
			}
			int count = palins.length;
			
			int pointA = Arrays.binarySearch(palins, min);
			int pointB = Arrays.binarySearch(palins, max);
			
			if(pointA >= 0)
				count -= pointA;
			else
				count -= -(pointA + 1);  //subtract off insertion point
			
			if(pointB >= 0)
				count -= palins.length - pointB - 1;
			else
				count -= palins.length + (pointB + 1);
			
			out.println("Case #" + i + ": " + count);
		}
		out.close();
	}
	
	public static boolean isPalin(long num){
		int digits = (int) Math.log10(num) + 1;
		long digs[] = new long[digits];
		for(int n=0; n < digits; n++){
			digs[n] = num % 10;
			num /= 10;
		}
		
		for(int n=0; n < digits; n++){
			if(digs[n] != digs[digits-n-1])
				return false;
		}
		return true;
	}
}
