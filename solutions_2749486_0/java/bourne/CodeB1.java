import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;


public class CodeB1 {
	public static void main(String[] args) throws IOException {
		String inp = "E:\\CodeJam\\B-small-attempt0.in";
		//String inp = "inp";
		String otp = "opt3.txt";
		BufferedReader read = new BufferedReader(new FileReader(new File(inp)));
		BufferedWriter write = new BufferedWriter(new FileWriter(new File(otp)));
		int t = Integer.parseInt(read.readLine());
		for(int i=0; i<t; i++) {
			String[] v1 = read.readLine().split(" ");
			int x = Integer.parseInt(v1[0]);
			int y = Integer.parseInt(v1[1]);
			write.write("Case #"+(i+1)+": " +solve(x, y) + "\n");
		}
		write.flush();
		write.close();
	}
	
	public static String solve(int x, int y) {
		LinkedList<Data> q = new LinkedList<>();
		q.add(new Data(0, 0 , "", 0));
		Map<Data, Boolean> seen = new HashMap<CodeB1.Data, Boolean>();
		while(!q.isEmpty()) {
			Data cur = q.remove();
			if(seen.containsKey(cur)) {
				continue;
			}
			seen.put(cur, Boolean.TRUE);
			if(cur.x == x && cur.y == y) {
				return cur.dir;
			}
			Data d1 = new Data(cur.x + cur.l +1, cur.y, cur.dir+"E", cur.l + 1);
			Data d2 = new Data(cur.x-cur.l - 1, cur.y, cur.dir+"W", cur.l + 1);
			Data d3 = new Data(cur.x, cur.y+ cur.l + 1, cur.dir+"N", cur.l + 1);
			Data d4 = new Data(cur.x, cur.y-cur.l-1, cur.dir + "S", cur.l + 1);
			if(!seen.containsKey(d1)) {
				q.add(d1);
			}
			if(!seen.containsKey(d2)) {
				q.add(d2);
			}
			if(!seen.containsKey(d3)) {
				q.add(d3);
			}
			if(!seen.containsKey(d4)) {
				q.add(d4);
			}
		}
		return "NENENENEW";
	}
	
	public static class Data {
		long x;
		long y;
		long l;
		String dir;
		public Data(long x1, long y1, String d1, long l1) {
			x = x1;
			y = y1;
			dir = d1;
			l = l1;
		}
		
		public boolean equals(Object ot) {
			Data o = (Data) ot;
			return o.x == x && o.y == y && o.l == l;
		}
		
		public int hashCode() {
			return (int)(x^y^l);
		}
	}
}
