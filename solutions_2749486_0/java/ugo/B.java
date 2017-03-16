package gcj2013.R1C;

import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.util.Arrays.deepToString;

import java.io.BufferedInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.*;

public class B {
	public static void main(String[] args) throws FileNotFoundException{
		String DIR = "src/gcj2013/R1C/";
		String READ_FILE = null;
		String WRITE_FILE = null;

				READ_FILE = "bsmall.in";
				WRITE_FILE = "bsmall.out";
//		READ_FILE = "blarge.in";
//		WRITE_FILE = "blarge.out";

		if(READ_FILE != null){
			System.setIn(new BufferedInputStream(new FileInputStream(new File(DIR+READ_FILE))));
		}
		if(WRITE_FILE != null){
			System.setOut(new PrintStream(new File(DIR+WRITE_FILE)));
		}
		precalc();
		new B().run();
	}

	Scanner sc;

	void debug(Object... o){
		System.out.println(deepToString(o));
	}

	
	static void precalc(){}

	void run(){
		sc = new Scanner(System.in);
		int caseCnt = sc.nextInt();
		for (int caseNum = 1; caseNum <= caseCnt; caseNum++) {
			System.out.print("Case #" + caseNum + ": ");
			solve();
			System.out.flush();
		}
	}
	
	void solve(){
		int x = sc.nextInt();
		int y = sc.nextInt();

		LinkedList<Pt> q = new LinkedList<Pt>();
		HashMap<Pt, Integer> num = new HashMap<Pt, Integer>();
		
		HashMap<Pt, String> way = new HashMap<Pt, String>();

		q.add(new Pt(0, 0));
		num.put(new Pt(0, 0), 0);
		way.put(new Pt(0, 0), "");
		outer: while(q.size() > 0) {
			Pt node = q.removeFirst();
			int nx = node.x;
			int ny = node.y;
			int sofar = num.get(node);
			
			for(int[] dd : diff){
				int xx = nx + (sofar+1) * dd[0];
				int yy = ny + (sofar+1) * dd[1];
				if(!num.containsKey(new Pt(xx, yy))){
					num.put(new Pt(xx, yy), sofar+1);
					way.put(new Pt(xx, yy), way.get(node) + (char) dd[2]);
					q.add(new Pt(xx, yy));
					
					if(xx == x && yy == y) break outer;
					
				}
			}
		}
/*		
		for(int  i = -10 ; i <= 10 ; i++){
			for(int j = -10 ; j <= 10 ; j++ ){
				Integer nnn = (num.get(new Pt(i, j)));
				System.out.print(nnn == null ? "." : nnn);
			}
			System.out.println();
		}
		*/
		System.out.println(way.get(new Pt(x, y)));
	}

	int[][] diff = {{0,1,'N'}, {0,-1,'S'}, {1,0,'E'}, {-1,0,'W'}};
	
	static class Pt {
		int x, y;
		public Pt(int x, int y){this.x = x; this.y = y;}
		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + x;
			result = prime * result + y;
			return result;
		}
		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			Pt other = (Pt) obj;
			if (x != other.x)
				return false;
			if (y != other.y)
				return false;
			return true;
		}
	}

}

/*
Input 
 	
Output 
 
2
3 4
-3 4
Case #1: ENWSEN
Case #2: ENSWN


*/