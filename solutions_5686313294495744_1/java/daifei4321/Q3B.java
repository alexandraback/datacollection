package r1B;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class Q3B {
	public static void main(String... args) {
		try (Scanner in = new Scanner(System.in)) {
			int T = in.nextInt();
			for (int caseI = 0; caseI < T; caseI++) {
				int N = in.nextInt();
				HashMap<String, Integer> dict1 = new HashMap<>();
				HashMap<String, Integer> dict2 = new HashMap<>();
				int[] word1 = new int[N];
				int[] word2 = new int[N];
				for (int n = 0; n < N; n++) {
					word1[n] = getWord(dict1, in.next());
					word2[n] = getWord(dict2, in.next());
				}
				int result;
				{
					// Find minimum edge set, to cover all points in group A and group B.
					class Point {
						ArrayList<Point> edges = new ArrayList<>();
					}
					ArrayList<Point> pointAs = new ArrayList<>();
					for (int i = 0, iMax = dict1.size(); i < iMax; i++) {
						pointAs.add(new Point());
					}
					ArrayList<Point> pointBs = new ArrayList<>();
					for (int i = 0, iMax = dict2.size(); i < iMax; i++) {
						pointBs.add(new Point());
					}
					for (int n = 0; n < N; n++) {
						int indexA = word1[n];
						Point pointA = pointAs.get(indexA);
						int indexB = word2[n];
						Point pointB = pointBs.get(indexB);
						pointA.edges.add(pointB);
						pointB.edges.add(pointA);
					}
					ArrayList<Point> pointAToCover = new ArrayList<>(pointAs);
					ArrayList<Point> pointBToCover = new ArrayList<>(pointBs);
					int edgeSelected = 0;
					loopOver:
					for (;;) {
						if (pointAToCover.size() == 0) {
							edgeSelected += pointBToCover.size();
							break;
						}
						if (pointBToCover.size() == 0) {
							edgeSelected += pointAToCover.size();
							break;
						}
						for (int i = 0, iMax = pointAToCover.size(); i < iMax; i++) {
							Point pointA = pointAToCover.get(i);
							int edgeSize = pointA.edges.size();
							if (edgeSize == 0) {
								edgeSelected++;
								pointAToCover.remove(i);
								continue loopOver;
							}
							if (edgeSize == 1) {
								edgeSelected++;
								pointAToCover.remove(i);
								Point pointB = pointA.edges.get(0);
								pointBToCover.remove(pointB);
								for (Point pReflect : pointB.edges) {
									pReflect.edges.remove(pointB);
								}
								continue loopOver;
							}
						}
						for (int i = 0, iMax = pointBToCover.size(); i < iMax; i++) {
							Point pointB = pointBToCover.get(i);
							int edgeSize = pointB.edges.size();
							if (edgeSize == 0) {
								edgeSelected++;
								pointBToCover.remove(i);
								continue loopOver;
							}
							if (edgeSize == 1) {
								edgeSelected++;
								pointBToCover.remove(i);
								Point pointA = pointB.edges.get(0);
								pointAToCover.remove(pointA);
								for (Point pReflect : pointA.edges) {
									pReflect.edges.remove(pointA);
								}
								continue loopOver;
							}
						}
						Point pointA = pointAToCover.get(0);
						edgeSelected++;
						pointAToCover.remove(0);
						Point pointB = pointA.edges.get(0);
						pointBToCover.remove(pointB);
						for (Point pReflect : pointB.edges) {
							pReflect.edges.remove(pointB);
						}
					}
					result = N - edgeSelected;
				}
				System.out.println("Case #" + (caseI + 1) + ": " + result);
			}
		}
	}

	private static int getWord(HashMap<String, Integer> dict, String word) {
		Integer id = dict.get(word);
		if (null == id) {
			int idInt = dict.size();
			dict.put(word, idInt);
			return idInt;
		}
		return id;
	}
}
