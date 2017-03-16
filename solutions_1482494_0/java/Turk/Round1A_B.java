import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class Round1A_B {

public static void main(String[] args) {
		
		BufferedReader in;
		BufferedWriter out;
		int T, i;
		String line;
		
		try {
			in = new BufferedReader(new FileReader("B-small-attempt0.in"));
			out = new BufferedWriter(new FileWriter("output.txt"));
		} catch (FileNotFoundException e) {
			System.out.println(e.getMessage());
			return;
		} catch (IOException e) {
			System.out.println(e.getMessage());
			return;
		}

		try {
			T = Integer.parseInt(in.readLine());

			
			
			for (i = 0; i < T; i++) {
				line = in.readLine();
				
				int N = Integer.parseInt(line);
				
				int[] a = new int[N];
				int[] b = new int[N];
				
				for (int j = 0; j < N; j++) {
					line  = in.readLine();
					String[] ab = line.split(" ");
					a[j] = Integer.parseInt(ab[0]);
					b[j] = Integer.parseInt(ab[1]);
				}
				
				
				String lineToWrite = "Case #" + (i+1) + ": ";
				
				System.out.println("Solving case " + (i+1));
/*				for (int j = 0; j < N; j++) {
					System.out.println(a[j] + " " + b[j]);
				}*/
				
				
				lineToWrite += solve(N, a, b);
				
				
				out.write(lineToWrite + "\n");
				
			}
			in.close();
			out.close();
		} catch (IOException e) {
			System.out.println(e.getMessage());
			return;
		}
	}

	public static String solve(Integer N, int[] a, int[] b) {
		
		int minimum = Integer.MAX_VALUE;
		int minThis, tempa, tempb;
		
		for (int i = 0; i < N; i++) {
			if (b[i] == 0) {
				tempb = b[i];
				tempa = a[i];
				b[i] = Integer.MAX_VALUE;
				a[i] = Integer.MAX_VALUE;
				minThis = doLevel(N, a, b, 2, 1, minimum);
				b[i] = tempb;
				a[i] = tempa;
				if (minThis < minimum) minimum = minThis;
			} else if (a[i] == 0) {
				tempa = a[i];
				a[i] = Integer.MAX_VALUE;
				minThis = doLevel(N, a, b, 1, 1, minimum);
				a[i] = tempa;
				if (minThis < minimum) minimum = minThis;
			}
		}
		
		
		if (minimum == Integer.MAX_VALUE) return "Too Bad";
		
		
		return String.valueOf(minimum);
		
	}
	
	public static int doLevel(int N, int[] a, int[] b, int stars, int levels, int minOverall) {
		
		int minimum = Integer.MAX_VALUE;
		int minThis;
		int recursions = 0;
		int tempa, tempb;
		
//		System.out.println(stars + " " + levels);

		if (levels >= minOverall) return minimum;
		
		for (int i = 0; i < N; i++) {
			if (b[i] <= stars) {
//				System.out.println(i + " b: " + b[i]);
				tempb = b[i];
				b[i] = Integer.MAX_VALUE;
				if (a[i] < b[i]) {
					tempa = a[i];
					a[i] = Integer.MAX_VALUE;
					
					minThis = doLevel(N, a, b, stars+2, levels+1, minOverall);
					a[i] = tempa;
					recursions++;
				} else {
					minThis = doLevel(N, a, b, stars+1, levels+1, minOverall);
					recursions++;
				}
				b[i] =  tempb;
				if (minThis < minimum) minimum = minThis;
			} else if (a[i] <= stars) {
//				System.out.println(i + " a: " + a[i]);
				tempa = a[i];
				a[i] = Integer.MAX_VALUE;
				minThis = doLevel(N, a, b, stars+1, levels+1, minOverall);
				a[i] = tempa;
				recursions++;
				if (minThis < minimum) minimum = minThis;
			}
		}
		
		if (recursions == 0) {
			if (stars == N*2){
//				System.out.println(levels);
				return levels;
			}
			return Integer.MAX_VALUE;
		}
		
		return minimum;
		
	}
	
}
