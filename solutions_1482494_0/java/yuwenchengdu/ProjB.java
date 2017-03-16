import java.io.*;
import java.util.*;

class Element implements Comparable {
	int data1;
	int data2;
	int index;
	public Element (int data1, int data2, int index) {
		this.data1 = data1;
		this.data2 = data2;
		this.index = index;
	}

	@Override
	public int compareTo(Object arg0) {
		// TODO Auto-generated method stub
		Element first = this, second = (Element)arg0;
		if (first.data2 != second.data2)
			return first.data2 - second.data2;
		return first.index - second.index;
			
	}
	
}

public class ProjB {
	static Scanner scan = new Scanner (System.in);
	

	
	static void test () {
		int N = scan.nextInt();
		Element[] A = new Element[N];
		for (int i = 0; i < N; ++i) {
			int a = scan.nextInt (), b = scan.nextInt();
			A[i] = new Element (a, b, i);
		}
		
		Arrays.sort(A);

		
		boolean[][] visited = new boolean[2][N];
		int start = 0;
		int level1 = 0, level2 = 0;
		while (level2 < N) {
			if (start >= A[level2].data2) {
				start += visited[0][A[level2].index]?1:2;
				visited[1][A[level2].index] = true;
				level2++;
			} else {
				int i;
				for (i = N - 1; i >= 0; --i) {
					if (!visited[0][A[i].index] && !visited[1][A[i].index] && start >= A[i].data1) {
						++start;
						++level1;
						visited[0][A[i].index] = true;
						break;
					}
				}
				if (i < 0) {
					System.out.println ("Too Bad");
					return;
				}
			}
		}
		if (level2 == N) {
			System.out.println (level1 + level2);
			return;
		}
		System.out.println ("Too Bad");
		return;
		
	}
	
	public static void main (String[] args) {
		int T = scan.nextInt();
		for (int i = 1; i <= T; ++i) {
			System.out.print ("Case #" + i + ": ");
			test ();
		}
		
	}
}
