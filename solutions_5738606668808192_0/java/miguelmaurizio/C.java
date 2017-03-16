import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class C {

	public static void main(String... args) throws Exception {
		configure();

		int casos = Integer.parseInt(in.readLine());
		for (int casito = 1; casito <= casos; casito++) {
			Object o = new C().solve();

			out.println("Case #" + casito + ":" + o);
			System.out.println("Case #" + casito + ": " + o);
		}
		out.close();
	}
	
	private Object solve() throws Exception {
		int N = ni();
		int J = ni();
		
		TreeSet<Res> set = new TreeSet<>();
		while (set.size() < J) {
			Res res = tryRes(N);
			if(res != null && !set.contains(res))
				set.add(res);
		}
		StringBuilder str = new StringBuilder();
		str.append("\n");
		for(Res res : set) {
			str.append(res);
			str.append("\n");
		}
		return str;
	}
	
	private Res tryRes(int N) {
		char[] cs = new char[N];
		for(int i =1;i<N-1;i++){
			double d = Math.random();
			if(d > 0.5){
				cs[i] = '1';
			} else {
				cs[i] = '0';
			}
		}
		cs[0] = '1';
		cs[N-1] = '1';
		String s = new String(cs);
		
		int[] prove = new int[9];
		for (int i = 2; i<=10;i++){
//			System.out.println(s);
//			System.out.println(i);
			long val = Long.parseLong(s,i);
			Integer ok = check(val);
			if(ok == null) {
				return null;
			}
			prove[i-2] = ok;
		}
		return new Res(s, prove);
	}

	private Integer check(long val) {
		for(long i =2L; i * i <=val;i++ ) {
			if(val % i ==0)
				return (int) i;
		}
		return null;
	}

	class Res implements Comparable<Res>{
		String s;
		int[] prove;
		
		public Res(String s, int[] prove) {
			this.s = s;
			this.prove = prove;
		}

		@Override
		public int compareTo(Res arg0) {
			return this.s.compareTo(arg0.s);
		}

		@Override
		public String toString() {
			StringBuilder str = new StringBuilder();
			str.append(s);
			for(int c : prove){
				str.append(" ");
				str.append(c);
			}
			return str.toString();
		}
		
		
		
		
	}
	
	// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	public static BufferedReader in;
	public static PrintWriter out;
	static String name_class = "C"; //
	static String loc = "/home/miguel/workspace/CodeJam/qualy2016/src"; //

	static void configure() throws Exception {

		File file = new File(loc);
		File[] paths = file.listFiles();
		List<File> input = new ArrayList<File>();
		for (File f : paths) {
			String s = f.getName();
			if (s.startsWith(name_class) && s.endsWith(".in"))
				input.add(f);
		}

		if (input.isEmpty()) {
			System.err.println("LEYENDO DE CONSOLA");
			in = new BufferedReader(new InputStreamReader(System.in));
		} else {
			File last_file = input.get(0);
			for (File f : input) {
				if (f.lastModified() > last_file.lastModified())
					last_file = f;
			}

			in = new BufferedReader(new FileReader(last_file.toString()));
			System.err.println("LEYENDO DE ARCHIVO");

		}
		FileWriter fw = new FileWriter(loc + "/output.txt");
		out = new PrintWriter(fw);

	}

	static StringTokenizer strTok = new StringTokenizer("");

	static String nextToken() throws IOException {
		while (!strTok.hasMoreTokens())
			strTok = new StringTokenizer(in.readLine());
		return strTok.nextToken();
	}

	static int ni() throws IOException {
		return Integer.parseInt(nextToken());
	}

	static long nl() throws IOException {
		return Long.parseLong(nextToken());
	}

	static double nd() throws IOException {
		return Double.parseDouble(nextToken());
	}

	static int[] nia(int size) throws IOException {
		int[] ret = new int[size];
		for (int i = 0; i < size; i++)
			ret[i] = ni();
		return ret;
	}

	static long[] nla(int size) throws IOException {
		long[] ret = new long[size];
		for (int i = 0; i < size; i++)
			ret[i] = nl();
		return ret;
	}

	static double[] nda(int size) throws IOException {
		double[] ret = new double[size];
		for (int i = 0; i < size; i++)
			ret[i] = nd();
		return ret;
	}

}