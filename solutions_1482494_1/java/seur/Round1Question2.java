import java.awt.Point;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.Comparator;


public class Round1Question2 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new FileReader(new File("r1q2.in")));
		int T = Integer.parseInt(br.readLine());
		for (int i = 0;i < T;i++) {
			int N = Integer.parseInt(br.readLine());
			String[] caseArgs = new String[N];
			for (int j = 0;j < N;j++)
			{
				caseArgs[j] = br.readLine();
			}
			doCase(i + 1, caseArgs);
		}
	}

	static void doCase(int caseNum, String[] args) {
		int ret = -1;
		int[] s1 = new int[args.length];
		int[] s2 = new int[args.length];
		Point[] lb1 = new Point[args.length];
		Point[] lb2 = new Point[args.length];
		for (int i = 0;i < args.length;i++) {
			String[] ss = args[i].split(" ");
			s1[i] = Integer.parseInt(ss[0]);
			s2[i] = Integer.parseInt(ss[1]);
			Point p = new Point(s1[i],s2[i]);
			lb1[i] = p;
			lb2[i] = p;
		}
		Arrays.sort(lb1,new Comparator<Point>() {
			public int compare(Point o1, Point o2) {
				if (o1.x > o2.x)
					return 1;
				else if (o1.x < o2.x) 
					return -1;
				else if (o1.y < o2.y)
					return 1;
				else if (o1.y > o2.y)
					return -1;
				else
					return 0;
			}
		});
		Arrays.sort(lb2,new Comparator<Point>() {
			public int compare(Point o1, Point o2) {
				if (o1.y > o2.y)
					return 1;
				else if (o1.y < o2.y) 
					return -1;
				else if (o1.x > o2.x)
					return 1;
				else if (o1.x < o2.x) 
					return -1;
				else
					return 0;
			}
		});
		int levelsDone = 0;
		int l2i = 0;
		int l1i = 0;
		int currentStars = 0;
		boolean failedOneStar = false;
		while (true) {
			if (l2i < lb2.length && lb2[l2i].y != -1 && lb2[l2i].y <= currentStars) {
				if (lb2[l2i].x != -1)
					currentStars++; // Counts for 2!
				currentStars++;
				lb2[l2i].x = -1;
				lb2[l2i].y = -1;
				levelsDone++;
				l2i++;
			}  else if ((l2i >= lb2.length || lb2[l2i].y > currentStars) && failedOneStar) {
				break;
			}
			else if (l1i < lb1.length && lb1[l1i].x != -1 && lb1[l1i].x <= currentStars) {
				lb1[l1i].x = -1;
				l1i++;
				currentStars++;
				levelsDone++;
			} else if (l1i < lb1.length && lb1[l1i].x == -1) {
				l1i++;
			} else if (l1i >= lb1.length || lb1[l1i].x > currentStars) {
				failedOneStar = true;
			}
		}
		ret = (currentStars == lb1.length * 2) ? levelsDone : 0;
		if (ret == 0)
			System.out.println("Case #" + caseNum + ": Too Bad");
		else
			System.out.println("Case #" + caseNum + ": " + ret);
	}
}
