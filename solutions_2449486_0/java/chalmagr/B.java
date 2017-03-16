package Q1;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.StringWriter;
import java.util.Arrays;

public class B {

	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
		int cases = Integer.valueOf(in.readLine());
		int x, y, height;
		x = y = height = -1;
		String[] line = new String[0];
		for ( int caseN=0 ; caseN < cases ; caseN++ ) {
			try {
				String[] size = in.readLine().split(" ");
				int h = Integer.valueOf(size[0]);
				int w = Integer.valueOf(size[1]);
				int[] hMax = new int[h];
				int[] wMax = new int[w];
				int[] field = new int[h*w];
				for ( y=0 ; y<h ; y++ ) {
					line = in.readLine().split(" ");
					for ( x=0 ; x<w ; x++ ) {
						height = Integer.valueOf(line[x]);
						field[y*w + x] = height;
						hMax[y] = hMax[y] < height ? height : hMax[y];
						wMax[x] = wMax[x] < height ? height : wMax[x];
					}
				}
				boolean possible = true;
				for ( y=0 ; possible && y<h ; y++ ) {
					for ( x=0 ; possible && x<w ; x++ ) {
						height = field[y*w + x];
						possible = height == hMax[y] || height == wMax[x];
					}
				}
				out.append("Case #" + (caseN+1) + ": " + (possible?"YES":"NO"));
				out.newLine();
			} catch (Exception e) {
				StringWriter sw = new StringWriter();
				e.printStackTrace(new PrintWriter(sw));
				System.err.println(String.format("Error %d: %d,%d - %s : %s",caseN,x,y,Arrays.toString(line), sw.toString()));
			}
		}
		in.close();
		out.close();
	}
}
