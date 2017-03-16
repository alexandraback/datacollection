import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class DeceitfulWar {
	public static void main(String[]Args) throws FileNotFoundException{
		Scanner sc = new Scanner(new File("D-small-attempt0.in"));
		PrintWriter out = new PrintWriter(new File("things.out"));
//		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt(),cc=0;
		while(t-->0){
			int N = sc.nextInt();
			int[] me = new int[N];
			int[] them = new int[N];
			for (int k = 0;k<N;k++){
				String s = sc.next().substring(2);
				while(s.length() != 5)
					s = s+"0";
				me[k] = Integer.parseInt(s);
			}
			for (int k = 0;k<N;k++){
				String s = sc.next().substring(2);
				while(s.length() != 5)
					s = s+"0";
				them[k] = Integer.parseInt(s);
			}
			Arrays.sort(me);
			Arrays.sort(them);
			int fptr = 0;
			int good = 0;
			for (int k = 0; k < N && fptr < N;k++){
				while(fptr< N && me[fptr] < them[k])
					fptr++;
				if(fptr < N && me[fptr] > them[k])
					good++;
				fptr++;
			}
			int[] tmp = me;
			me = them;
			them = tmp;
			fptr = 0;
			int bad = 0;
			for (int k = 0; k < N && fptr < N;k++){
				while(fptr< N && me[fptr] < them[k])
					fptr++;
				if(fptr < N && me[fptr] > them[k])
					bad++;
				fptr++;
			}
			out.printf("Case #%d: %d %d%n", ++cc, good, N-bad);
		}
		out.close();
	}
}
