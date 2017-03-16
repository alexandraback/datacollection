import java.util.*;
import java.io.*;

public class FairSquare {
	public static void main(String[] args) throws IOException{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("file")));
		StringTokenizer st = new StringTokenizer(in.readLine());
		int[] palins = {1, 4, 9, 121, 484};
		int cases = Integer.parseInt(st.nextToken());
		for(int i=1; i<= cases; i++){
			st = new StringTokenizer(in.readLine());
			int min = Integer.parseInt(st.nextToken());
			int max = Integer.parseInt(st.nextToken());
			
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
}
