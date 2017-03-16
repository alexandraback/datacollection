import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Locale;
import java.util.Scanner;

public class CodeJam {

	Scanner in;
	PrintWriter out;
	
	static class Hiker implements Comparable <Hiker> {
		int startPos;
		int fullTime;
		
		Hiker(int startPos, int fullTime) {
			this.startPos = startPos;
			this.fullTime = fullTime * 360;
		}
		
		int timeToFinish() {
			int remained = startPos;
			return remained * fullTime / 360;
		}
		
		int countOfIntersections(Hiker second) {
			int timeThis = timeToFinish();
			int time21 = second.timeToFinish();
			int time22 = time21 + second.fullTime;
			int time23 = time22 + second.fullTime;
			if (timeThis >= time23) {
				return 3;
			} else if (timeThis >= time22) {
				return 2;
			} else if (timeThis >= time21 && this.startPos <= second.startPos) {
				return 1;
			}
			return 0;
		}
		
		public int compareTo(Hiker second) {
			if (this.startPos == second.startPos) {
				return second.fullTime - this.fullTime;
			}
			return second.startPos - this.startPos;
		}
	}
	
	int solveFor() {
		int nGroups = in.nextInt(); 
		List<Hiker> hikers = new ArrayList<>();
		for (int i = 0; i < nGroups; i++) {
			int pos = in.nextInt();
			int count = in.nextInt();
			int fullTime = in.nextInt();
			for (int h = 0; h < count; h++) {
				hikers.add(new Hiker(pos, h + fullTime));
			}
		}
		
		if (hikers.size() == 1) {
			return 0;
		} else {
			Collections.sort(hikers);
			Hiker closerToOrigin = hikers.get(1);
			Hiker afterOrigin = hikers.get(0);
			
			int time1 = closerToOrigin.timeToFinish();
			int time2 = afterOrigin.timeToFinish();
			
			if (time1 == time2) {
				return 0;
			}
			
			int count = closerToOrigin.countOfIntersections(afterOrigin);
			int count2 = afterOrigin.countOfIntersections(closerToOrigin);
			int max = Math.max(count, count2);
			if (max >= 2) {
				return 1;
			} else if (max == 0) {
				return 0;
			} else if (max == 1) {
				if (closerToOrigin.countOfIntersections(afterOrigin) == 1) {
					return 1;
				} else {
					return 0;
				}
			}
			
		}
		return 0;
	}

	void solve() {
		int n = in.nextInt();
		for (int test = 1; test <= n; test++) {
			out.print("Case #" + test + ": ");
			out.println(solveFor());
			out.flush();
		}
	}
	
	static private final String path = "C:\\jam\\1B\\";
	static private final String problem = "C";
	static private final String tests = "C-small";
	

	void run() {
		try {
			in = new Scanner(new FileReader(path + problem + "\\" + tests + ".in"));
			//out = new PrintWriter(System.out);
			out = new PrintWriter(path + problem + "\\" + tests + ".out3");
		} catch (IOException e) {
		//	throw new Error(e);
			
			in = new Scanner(System.in);
			out = new PrintWriter(System.out);
			out.println(">");
			out.flush();
		}
		try {
			solve();
		} finally {
			out.close();
		}
	}

	public static void main(String[] args) {
		new CodeJam().run();
	}
}