import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.PrintStream;


public class GB {

	public static PrintStream O = System.out;
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		BufferedReader in;
		try{
			in = new BufferedReader(new FileReader("B-small-attempt2.in"));
			O = new PrintStream(new File("B.out"));
			
			String input;
			String[] inputarr;
			int T = Integer.parseInt(in.readLine());
			int N;
			int[][] levels;
			int res;
			for (int kase = 1; kase <= T; kase++){
				N = Integer.parseInt(in.readLine());
				levels = new int[N][2];
				for (int i = 0; i < N; i++){
					inputarr = in.readLine().split(" ");
					levels[i][0] = Integer.parseInt(inputarr[0]);
					levels[i][1] = Integer.parseInt(inputarr[1]);
				}
				res = rec2(levels, new int[N], 0, 0);
				String output = (res < 0 ? "Too Bad" : ""+res);
				O.println("Case #" + kase + ": " + output);
			}
		}catch(Exception e){
			e.printStackTrace();
		}
	}

	public static int rec2(int[][] levels, int[] finished, int stars, int count){
		int best = Integer.MAX_VALUE;
		int t, t2;
		boolean played = false;
		boolean exists = true;
		while (exists){
			played = false;
			exists = false;
			for (int i = 0; i < finished.length; i++){
				if (finished[i] != 2){
					exists = true;
					break;
				}
			}
			if (!exists){
				continue;
			}
			// finish all 0 to 2 stars
			for (int i = 0; i < finished.length; i++){
				if (finished[i] == 0 && levels[i][1] <= stars){
					played = true;
					finished[i] = 2;
					stars += 2;
					count++;
				}
			}
			if (played){
				continue;
			}
			// finish 1 to 2 stars
			for (int i = 0; i < finished.length; i++){
				if (finished[i] == 1 && levels[i][1] <= stars){
					played = true;
					finished[i] = 2;
					stars += 1;
					count++;
					break;
				}
			}
			if (played){
				continue;
			}
			
			// finishe best one 0 to 1 stars
			int min = -1;//Integer.MAX_VALUE;
			int position = -1;
			for (int i = 0; i < finished.length; i++){
				if (finished[i] == 0 && levels[i][0] <= stars && levels[i][1] > min){
					played = true;
					position = i;
					min = levels[i][1];
				}
			}
			if (played){
				finished[position] = 1;
				stars += 1;
				count++;
				continue;
			}		
			
			return -1;
		}
		return count;
	}
	
	public static int rec(int[][] levels, int[] finished, int stars, int count){
		int best = Integer.MAX_VALUE;
		int t, t2;
		boolean played = false;
		boolean exists = false;

		for (int i = 0; i < finished.length; i++){
			if (finished[i] < 2){
				exists = true;
				if (levels[i][1] <= stars){
					t2 = finished[i];
					finished[i] = 2;
					played = true;
					t = rec(levels, finished, stars + (t2 == 0 ? 2 : 1), count + 1);
					if (t < 0){
						return -1;
					}else if (t < best){
						best = t;
					}
					finished[i] = t2;
				}else if (levels[i][0] <= stars && finished[i] == 0){
					finished[i] = 1;
					t = rec(levels, finished, stars + 1, count + 1);
					played = true;
					if (t < 0){
						return -1;
					}else if (t < best){
						best = t;
					}
					finished[i] = 0;
				}
			}
		}
		if (played)
			return best;
		if (exists && !played)
			return -1;
		return count;
	}
}
