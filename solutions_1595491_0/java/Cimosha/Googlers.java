import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;


public final class Googlers {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
// 			*				/3	%3
// 0 	0    	000			0	0
// 1    1 		100			0	1
// 2	1	2	110 200*	0 	2	
// 3 	1   2	111 210*	1 	0
// 4    2 	2	112 022*	1 	1
// 5 	2	3	122 113*	1 	2			
// 6 	2	3	222 123*	2 	0
// 7	3	3	223 133*	2 	1
// 8	3	4	233 224*	2 	2
// 9	3	4	333 234*	3 	0
// ...
// 28	10	10  9 9 10 		9	1
// 29	10	10	9 10 10		9	2
// 30	10  10				10  0
		//  max = x/3 + x%3>=1
		// *max = x/3 + x%3=2
		
//prepare table
		int[][] max = new int[31][2];
		max[0][0] = 0;
		max[0][1] = 0;
		for (int i = 1; i <=27; i++) {
			int quotient = i / 3;
			int reminder = i % 3;
			max[i][0] = quotient + (reminder>=1?1:0);
			max[i][1] = quotient + (reminder==2?2:1);
		}
		max[28][0] = 10;
		max[28][1] = 10;
		max[29][0] = 10;
		max[29][1] = 10;
		max[30][0] = 10;
		max[30][1] = 10;
		BufferedReader br = null;
		BufferedWriter bw = null;
		try {
			br = new BufferedReader(new InputStreamReader(new FileInputStream("test.txt")));
			bw = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("solution.txt")));
			int count = 1;
			int cases = Integer.valueOf(br.readLine());
			String input;
			while (((input = br.readLine()) != null) && (count <= cases)) {
				String output = "Case #"+(count++)+": "+process(input, max);
				System.out.println(output);
				bw.write(output);
				bw.newLine();
			}
		} catch (Exception e) {// Catch exception if any
			System.err.println("Error: " + e.getMessage());
		} finally {
			if (br!=null) try { br.close(); } catch(IOException e) {}
			if (bw!=null) try {
				bw.flush();
				bw.close();
			} catch(IOException e) {}
		}
		
	}
	
	private static final int process(String input, int[][] max) {
		String[] s = input.split(" ");
		int N = Integer.valueOf(s[0]);
		int S = Integer.valueOf(s[1]);
		int p = Integer.valueOf(s[2]);
		//int t[] = new int[N];
		int count = 0;
		for (int i = 0; i < N; i++) {
			int t = Integer.valueOf(s[i+3]);
			if (max[t][0] >= p) count++;
			else if (S > 0 && max[t][1] >= p) {
				count++;
				S--;
			}
		}
		return count;
	}

}
