import java.util.*;
import java.io.*;


public class A {
	
	static char[] map = new char[128];
	
	static {
		String G = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv y qee";
		String E = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up a zoo";
		
		for (int i = 0; i < G.length(); i++) {
			map[G.charAt(i)] = E.charAt(i);
		}

		boolean[] used = new boolean[128];
		for (int d = 'a'; d <= 'z'; d++)
			used[map[d]] = true;
		
		char unused = 0;
		for (char d = 'a'; d <= 'z'; d++)
			if (!used[d])
				unused = d;
		
		for (int c = 'a'; c <= 'z'; c++)
			if (map[c] == 0) {
				map[c] = unused;
//				System.out.println((char)c + " -> " + unused);
			}
	}
	
	private Object solve() {
		String line = sc.nextLine();
		String res = "";
		for (int i = 0; i < line.length(); i++)
			res += map[line.charAt(i)];
		return res;
	}
	
	
	private static Scanner sc; private static PrintWriter fw;
	
	public static void main(String[] args) throws IOException {
		String inFile;
//		inFile = "input.txt";
		inFile = "A-small-attempt0.in";
//		inFile = "A-large.in";
		
//		sc = new Scanner(System.in);
		sc = new Scanner(new FileInputStream(inFile));
		
		fw = new PrintWriter(new FileWriter("output.txt", false));

		
		int N = sc.nextInt();
		sc.nextLine();
		
		for (int cas = 1; cas <= N; cas++) {
			fw.print("Case #" + cas + ": ");
//			fw.println("Case #" + cas + ": ");
			Object res = new A().solve();
			if (res instanceof Double) 
				fw.printf("%.10f\n", res);
			else
				fw.printf("%s\n", res);
			fw.flush();
		}
		fw.close();
		sc.close();
	}


}
