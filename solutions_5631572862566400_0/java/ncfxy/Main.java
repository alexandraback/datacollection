/**
 * File Name: Main.java
 * Package Name: com.ncfxy.codejam
 * Description： TODO 
 *
 *   ver					date			author
 * ──────────────────────────────────
 *   1.0-SNAPSHOT			2016年4月16日			Administrator
 *
 * Copyright (c) 2016, ncfxy All Rights Reserved.
 */

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.Stack;

/**
 * ClassName: Main<br/>
 * Description: TODO ADD Description
 *
 * @author Administrator
 * @version 1.0-SNAPSHOT
 * @Date 2016 2016年4月16日 上午8:45:47
 */

class GraphPoint {
	private int index;
	private List<Integer> NextPoint = new ArrayList<Integer>();
	private List<Integer> edgeValue = new ArrayList<Integer>();

	public int getIndex() {
		return index;
	}

	public void setIndex(int index) {
		this.index = index;
	}

	public List<Integer> getNextPoint() {
		return NextPoint;
	}

	public void setNextPoint(List nextPoint) {
		NextPoint = nextPoint;
	}

	public List<Integer> getEdgeValue() {
		return edgeValue;
	}

	public void setEdgeValue(List edgeValue) {
		this.edgeValue = edgeValue;
	}
}

class DirectedGraph {

	List<GraphPoint> pointList = new ArrayList<GraphPoint>();

	public void addPoint(int totalPointNumber) {
		pointList.clear();
		for (int i = 0; i < totalPointNumber; i++) {
			GraphPoint graphPoint = new GraphPoint();
			graphPoint.setIndex(i);
			pointList.add(graphPoint);
		}
	}

	public void addEdge(int from, int to, int value) {
		if (from > pointList.size() || to > pointList.size()) {
			return;
		}
		(pointList.get(from)).getNextPoint().add(to);
		(pointList.get(from)).getEdgeValue().add(value);
	}

	public int circleIndexPoint = 0;

	public int searchForMax() {
		int cover[] = new int[pointList.size()];
		int result = 0;
		Arrays.fill(cover, 0);
		for (int i = 0; i < pointList.size(); i++) {
			cover[i] = 1;
			Boolean find = false;
			int tmp = findCircle(pointList.get(i), cover, i,find);
			cover[i] = 0;
			if (tmp > result && find)
				result = tmp;
			if (tmp == 2 && find) {
				cover[circleIndexPoint] =1;
				tmp += dfs(i,cover);
				cover[circleIndexPoint] = 0;
				cover[i] = 1;
				tmp += dfs(circleIndexPoint,cover);
				cover[i] = 0;
				if(tmp > result)result = tmp;
			}
		}
		return result;
	}
	
	public int dfs(int from,  int[] cover){
		int result = 0;
		GraphPoint p = pointList.get(from);
		cover[from] = 1;
		for(int i = 0;i < p.getNextPoint().size();i++){
			int tmp = p.getNextPoint().get(i);
			if(cover[tmp] == 1)continue;
			int isMax = dfs(tmp,cover)+1;
			if(isMax > result)result = isMax;
		}
		cover[from] = 0;
		return result;
	}

	public int findCircle(GraphPoint gIndex, int[] cover, int start,Boolean find) {
		int result = 0;
		for (int i = 0; i < gIndex.getNextPoint().size(); i++) {
			int tmp = gIndex.getNextPoint().get(i);
			if (tmp == start) {
				find = true;
				return 1;
			}
			if (cover[tmp] == 1)
				continue;
			cover[tmp] = 1;
			int isMax = findCircle(pointList.get(tmp), cover, start, find);
			cover[tmp] = 0;
			circleIndexPoint = tmp;
			if(isMax > result && find){
				result = isMax;
				return result + 1;
			}
		}
		return result + 1;
	}

}

public class Main {

	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		while (cin.hasNext()) {
			int t = cin.nextInt();
			for (int caseNumber = 1; caseNumber <= t; caseNumber++) {
				String output = sol(cin);
				System.out.println("Case #" + caseNumber + ": " + output);
			}

		}
	}

	public static String sol(Scanner cin) {
		int n = cin.nextInt();
		DirectedGraph g = new DirectedGraph();
		g.addPoint(n);
		for (int i = 1; i <= n; i++) {
			int x = cin.nextInt();
			g.addEdge(x - 1, i - 1, 0);
		}
		return new Integer(g.searchForMax()).toString();

	}

}
