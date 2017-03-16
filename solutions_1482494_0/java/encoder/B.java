package FirstRound;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class B {
	public static void main(String[] args) {
		try {
			FileWriter w = new FileWriter(new File("E:\\output.out"));
			BufferedReader r = new BufferedReader(new FileReader(new File("E:\\B-small-attempt3.in")));
			int numbeOfCases = Integer.parseInt(r.readLine());
			for(int t = 0; t < numbeOfCases; t++) {
				int levels = Integer.parseInt(r.readLine());
				int[][] req = new int[levels][2];
				for(int i = 0; i < levels; i++) {
					String[] s = r.readLine().split(" ");
					req[i][0] = Integer.parseInt(s[0]);
					req[i][1] = Integer.parseInt(s[1]);
				}
				/*Arrays.sort(req, new Comparator<int[]>() {
					@Override
					public int compare(int[] o1, int[] o2) {
						if(o1[0] != o2[0])
							return o1[0] - o2[0];
						else
							return  o1[1] - o2[1];
						return (o1[0] * o1[0] - o2[0] * o2[0]) + (o1[1] * o1[1] - o2[1] * o2[1]);
					}
				});*/
				int[] done = new int[levels];
				int rating = 0;
				int att = 0;
				String output;
				
				if(att > 0)
					output = Integer.toString(att);
				else
					output = "Too Bad";
				A: while(isAllPending(done)) {
					boolean found = false;
					for(int i = 0; i < levels; i++) {
						if(done[i] < 2 && rating >= req[i][1]) {
							rating += 2 - done[i];
							done[i] = 2;
							att++;
							found = true;
							continue A;
						}
					}
					for(int i = 0; i < levels; i++) {
						if(done[i] < 1 && rating >= req[i][0]) {
							rating += 1 - done[i];
							done[i] = 1;
							att++;
							found = true;
							continue A;
						}
					}
					if(!found) {
						att = 0;
						break;
					}
				}
				if(att == 0)
					output = "Too Bad";
				else
					output = att + "";
				w.write("Case #" + (t + 1) + ": " + output);
				//System.out.println("Case #" + (t + 1) + ": " + output);
				if(t < numbeOfCases - 1)
					w.write("\n");
				//System.out.println(t);
			}
			w.close();
			r.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	private static boolean isAllPending(int[] done) {
		for(int i : done)
			if(i != 2)
				return true;
		return false;
	}
}