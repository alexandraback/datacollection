package con2013Q;

import java.io.*;
import java.util.*;

public class A {
	
	private static final String islarge = "-large";
	private static final String fileName = "results/con2013Q/"+A.class.getSimpleName().toLowerCase();//+islarge;
	private static final String inputFileName = fileName + ".in";
	private static final String outputFileName = fileName + ".out";
	private static Scanner in;
	private static PrintWriter out;
	
	private static String XWON = "X won",OWON = "O won", DRAW = "Draw",NOTEND = "Game has not completed";
	
	private void solve() {
		in.nextLine();
		String[]bord = new String[4];
		for(int i=0;i<4;i++){
			bord[i] = in.nextLine();
		}
		boolean xwon1 = true,
				owon1 = true,
				xwon2 = true,
				owon2 = true;
		boolean alldone = true;
		for(int i=0;i<4;i++){
			xwon1 = true;
			owon1 = true;
			xwon2 = true;
			owon2 = true;
			for(int j=0;j<4;j++){
				xwon1 &= bord[i].charAt(j)=='X'||bord[i].charAt(j)=='T';
				owon1 &= bord[i].charAt(j)=='O'||bord[i].charAt(j)=='T';
				xwon2 &= bord[j].charAt(i)=='X'||bord[j].charAt(i)=='T';
				owon2 &= bord[j].charAt(i)=='O'||bord[j].charAt(i)=='T';
				alldone &= bord[i].charAt(j)!='.';
			}
			if(xwon1||owon1||xwon2||owon2){
				break;
			}
		}
		if(xwon1||xwon2){
			out.println(XWON);
			return;
		}
		if(owon1||owon2){
			out.println(OWON);
			return;
		}
		xwon1 = true;
		owon1 = true;
		xwon2 = true;
		owon2 = true;
		for(int i=0;i<4;i++){
			xwon1 &= bord[i].charAt(i)=='X'||bord[i].charAt(i)=='T';
			owon1 &= bord[i].charAt(i)=='O'||bord[i].charAt(i)=='T';
			xwon2 &= bord[3-i].charAt(i)=='X'||bord[3-i].charAt(i)=='T';
			owon2 &= bord[3-i].charAt(i)=='O'||bord[3-i].charAt(i)=='T';		
		}
		if(xwon1||xwon2)
			out.println(XWON);
		else if(owon1||owon2)
			out.println(OWON);
		else
			out.println(alldone ? DRAW : NOTEND);
	}

	public static void main(String[] args) throws IOException {
		long start = System.currentTimeMillis();
		in = new Scanner(new FileReader(inputFileName));
		out = new PrintWriter(outputFileName);
		int tests = in.nextInt();
		for (int t = 1; t <= tests; t++) {
			out.print("Case #" + t + ": ");
			new A().solve();
			System.out.println("Case #" + t + ": solved");
		}
		in.close();
		out.close();
		long stop = System.currentTimeMillis();
		System.out.println(stop-start+" ms");
	}
}
