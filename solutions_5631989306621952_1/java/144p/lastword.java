import java.util.*;
import java.io.*;

public class lastword {

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int cases = Integer.valueOf(br.readLine());

		for (int c = 0; c < cases; c++) {
			
			char input[] = br.readLine().toCharArray();
			String current = "" + input[0];
			
		
			for (int i = 1; i < input.length; i++) {
				char look = input[i];
				if (look >= current.charAt(0)) {
					current = look + current;
				}
				else current = current + look;
			}		

			System.out.println("Case #" + (c+1) + ": " + current);

		}
		

	}//em
} //EM
