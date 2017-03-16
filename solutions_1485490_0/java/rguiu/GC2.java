
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class GC2 {

	
	public static void main(String[] args) throws IOException {
		GC2 trans = new GC2();
		trans.doMe();
	}
	
	private static final String NAME = "C-small-attempt1";
	
	public void doMe() throws IOException {
		File file = new File(NAME + ".in");
		BufferedWriter out = new BufferedWriter(new FileWriter(NAME+".out"));
		try {
			//use buffering, reading one line at a time
			//FileReader always assumes default encoding is OK!
			BufferedReader input = new BufferedReader(new FileReader(file));
			try {
				String line = input.readLine();
				int count = Integer.parseInt(line);
				
				for (int i=0;i<count;i++) {
				    line = input.readLine();
				    //int count2 = Integer.parseInt(line);
				    //System.out.println(line);
				    String[] s = new String[2];
				    for (int j = 0; j < 2; j++) {
						s[j] = input.readLine().trim();
					}
					String str = this.proccessLine(s);
					out.write("Case #"+(i+1)+": "+str);
					if (i<count-1)
						out.write(System.getProperty("line.separator"));
					System.out.println(str);
				}
			} finally {
				input.close();
				out.flush();
				out.close();
			}
		} catch (IOException ex) {
			ex.printStackTrace();
		}
	}
	
	long[] toIntArray(String str) {
		StringTokenizer tokens = new StringTokenizer(str);
		long[] a= new long[tokens.countTokens()];
		int i = 0;
		while(tokens.hasMoreElements()) {
			a[i++] = Long.parseLong(tokens.nextToken());
		}
		return a;
	}
	
	
	String proccessLine(String line[]) {
		// build graph
		long[][]ns = new long[line.length][];
		for (int i = 0; i < line.length; i++) {
			ns[i] = toIntArray(line[i]);
		}
		return ""+clc(ns[0], ns[1]);
	}
	Map<String, Integer> memo = new HashMap<String, Integer>();
	
	long clc(long a[], long b[]) {
		if (b.length==0 || a.length==0) return 0;
		String yu = toKey(a, b);
		if (memo.containsKey(yu)) return memo.get(yu);
		if (a[1]==b[1]) {
			if (a[0]>b[0]) {
				long an[] = new long[a.length];
				System.arraycopy(a, 0, an, 0, a.length);
				long bn[] = new long[b.length-2];
				System.arraycopy(b, 2, bn, 0, b.length - 2);
				an[0] = a[0]-b[0];
				return clc(an,bn) + b[0];
			} else if (a[0]<b[0]) {
				long an[] = new long[a.length - 2];
				System.arraycopy(a, 2, an, 0, a.length-2);
				long bn[] = new long[b.length];
				System.arraycopy(b, 0, bn, 0, b.length);
				bn[0] = b[0]-a[0];
				return clc(an,bn) + a[0];
			} else {
				long an[] = new long[a.length - 2];
				System.arraycopy(a, 2, an, 0, a.length-2);
				long bn[] = new long[b.length - 2];
				System.arraycopy(b, 2, bn, 0, b.length - 2);
				return clc(an,bn) + a[0];
			}
		} else {
			long an[] = new long[a.length - 2];
			System.arraycopy(a, 2, an, 0, a.length-2);
			long bn[] = new long[b.length];
			System.arraycopy(b, 0, bn, 0, b.length);
			long u = clc(an,bn);
			
			an = new long[a.length];
			System.arraycopy(a, 0, an, 0, a.length);
			bn = new long[b.length-2];
			System.arraycopy(b, 2, bn, 0, b.length - 2);
			long v = clc(an,bn);
			return Math.max(u,v);
		}
	}

	String toKey(long[] a, long[] b) {
		StringBuilder c = new StringBuilder();
		for (int i = 0; i < a.length; i++) {
			c.append(a[i]).append(':');
		}
		c.append('|');
		for (int i = 0; i < b.length; i++) {
			c.append(b[i]).append(':');
		}
		return c.toString();
	}

}
