package gcj2013.q;
import java.io.File;
import java.io.PrintWriter;
import java.text.SimpleDateFormat;
import java.util.Arrays;
import java.util.Date;
import java.util.Scanner;

public class A {
	static String BASEPATH = "x:\\gcj\\";
	static boolean LARGE = false;
	static String INPATH = BASEPATH + A.class.getSimpleName().charAt(0) + (LARGE ? "-large.in" : "-small-attempt0.in");
	static String OUTPATH = INPATH.substring(0, INPATH.length()-3) + new SimpleDateFormat("-HHmmss").format(new Date()) + ".out";
	
	static String INPUT = "";
	
	boolean won(char[][] map, String ok)
	{
		outer1:
		for(int i = 0;i < 4;i++){
			for(int j = 0;j < 4;j++){
				if(ok.indexOf(map[i][j]) == -1)continue outer1;
			}
			return true;
		}
		outer2:
		for(int i = 0;i < 4;i++){
			for(int j = 0;j < 4;j++){
				if(ok.indexOf(map[j][i]) == -1)continue outer2;
			}
			return true;
		}
		if((
				ok.indexOf(map[0][0]) > -1 &&
				ok.indexOf(map[1][1]) > -1 &&
				ok.indexOf(map[2][2]) > -1 &&
				ok.indexOf(map[3][3]) > -1
				))return true;
		if((
				ok.indexOf(map[3][0]) > -1 &&
				ok.indexOf(map[2][1]) > -1 &&
				ok.indexOf(map[1][2]) > -1 &&
				ok.indexOf(map[0][3]) > -1
				))return true;
		return false;
	}
	
	public void call()
	{
		char[][] map = new char[4][];
		for(int i = 0;i < 4;i++){
			map[i] = in.next().toCharArray();
		}
		
		// X won
		if(won(map, "XT")){
			out.println("X won");
			return;
		}
		
		// O won
		if(won(map, "OT")){
			out.println("O won");
			return;
		}
		
		// not completed
		for(int i = 0;i < 4;i++){
			for(int j = 0;j < 4;j++){
				if(map[i][j] == '.'){
					out.println("Game has not completed");
					return;
				}
			}
		}
				
		// Draw
		out.println("Draw");
	}
	
	Scanner in;
	PrintWriter out;
	int cas;
	
	public A(int cas, Scanner in, PrintWriter out)
	{
		this.cas = cas;
		this.in = in;
		this.out = out;
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
	
	public static void main(String[] args) throws Exception
	{
		long start = System.currentTimeMillis();
		boolean real = INPUT.isEmpty();
		
		if(real){
			System.out.println("INPATH : " + INPATH);
			System.out.println("OUTPATH : " + OUTPATH);
		}
		Scanner in = real ? new Scanner(new File(INPATH)) : new Scanner(INPUT);
		PrintWriter out = real ? new PrintWriter(new File(OUTPATH)) : new PrintWriter(System.out);
		int n = in.nextInt();
		in.nextLine();
		
		for(int i = 0;i < n;i++){
			out.printf("Case #%d: ", i+1);
			new A(i+1, in, out).call();
			out.flush();
			if(real)System.err.println("case " + (i + 1) + " solved.\t");
		}
		
		long end = System.currentTimeMillis();
		System.out.println((end - start) + "ms");
		if(real){
			System.out.println("INPATH : " + INPATH);
			System.out.println("OUTPATH : " + OUTPATH);
		}
	}
}
