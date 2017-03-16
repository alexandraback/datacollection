import java.io.*;
import java.util.Arrays;
import java.util.Scanner;


public class Dijkstra {
	public Dijkstra() {
		int[][] m = {
			//		1  i  j  k -1 -i -j -k
			/* 1*/{ 0, 1, 2, 3, 4, 5, 6, 7}, // 0
			/* i*/{ 1, 4, 3, 6, 5, 0, 7, 2}, // 1
			/* j*/{ 2, 7, 4, 1, 6, 3, 0, 5}, // 2
			/* k*/{ 3, 2, 5, 4, 7, 6, 1, 0}, // 3
			/*-1*/{ 4, 5, 6, 7, 0, 1, 2, 3}, // 4
			/*-i*/{ 5, 0, 7, 2, 1, 4, 3, 6}, // 5
			/*-j*/{ 6, 3, 0, 5, 2, 7, 4, 1}, // 6
			/*-k*/{ 7, 6, 1, 0, 3, 2, 5, 4}  // 7
		};
		String str = "_ijk";
		
		Scanner in = new Scanner(System.in);
		int tests = in.nextInt();
		for(int t = 1; t<=tests; t++){
			int n = in.nextInt();
			long mults = in.nextLong();
			String ln = in.next();
			String ans = "NO";
			int[] val = new int[(int)Math.min(n*16, mults*n)];
			int subVal = 0;
			for(int i = 0, j=0; i<val.length; i++, j++){
				if(j==n)
					j=0;
				val[i] = subVal = m[subVal][str.indexOf(ln.charAt(j))];
			}
			subVal = val[n-1];
			int totalVal = 0;
			for(int i = 0; i<mults%4; i++)
				totalVal = m[totalVal][subVal];
			if(totalVal == 4){ // total val is -1
				boolean foundI = false;
				int i = 0;
				for(; i<val.length; i++)
					if(val[i] == 1){
						foundI = true;
						break;
					}
				if(foundI){
					for(; i<val.length; i++)
						if(val[i] == 3){
							ans = "YES";
							break;
						}
				}
			}
			System.out.printf("Case #%d: %s\n", t, ans);
		}
	}
	public static void main(String[] args) throws FileNotFoundException {
		System.setIn(new FileInputStream(new File("C-small-attempt0.in")));
		System.setOut(new PrintStream(new File("C-small-attempt0.out")));
		new Dijkstra();
	}
}
