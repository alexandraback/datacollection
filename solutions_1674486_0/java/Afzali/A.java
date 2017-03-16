import static java.lang.Math.*;
import static java.util.Arrays.*;
import java.io.*;
import java.util.*;

public class A {
	Scanner sc = new Scanner(System.in);
	
	int N;
	int[][] cs;
	boolean[] cc;
	boolean cct;
	
	void read() {
		N = sc.nextInt();
		
		cs = new int[N][];
		
		for (int i = 0; i < N; i++){
			int C = sc.nextInt();
			cs[i] = new int[C];
			for(int j = 0; j<C; j++)
				cs[i][j] = sc.nextInt(); 
		}
			
	}
	
	void solve() {
		boolean t = false;
		for (int i = 0; i < N; i++){
			if(cs[i].length>1){
				cc = new boolean[N];
				cct = false;
				checkFork(i);
				if(cct) {System.out.println("Yes");t = true;break;};
				
			}			
		}
		if(!t) System.out.println("No");
	}
	
	boolean checkFork(int n) {
		for(int i=0; i< cs[n].length; i++){
			int nc = cs[n][i]-1;
			if(cc[nc] == true){
				cct = true;
				return true;
			}else{
				cc[nc] = true;
				checkFork(nc);
			}
		}
		return false;
	}
	
	void run() {
		int caseN = sc.nextInt();
		for (int caseID = 1; caseID <= caseN; caseID++) {
			read();
			System.out.printf("Case #%d: ", caseID);
			solve();
			System.out.flush();
		}
	}
	
	public static void main(String[] args) {
		try {
			System.setIn(new BufferedInputStream(new FileInputStream(args.length > 0 ? args[0] : ("A-small-attempt0 (2).in"))));
			System.setOut(new PrintStream(new FileOutputStream("A.out.txt")));
		} catch (Exception e) {
			e.printStackTrace();
		}
		new A().run();
	}
}
