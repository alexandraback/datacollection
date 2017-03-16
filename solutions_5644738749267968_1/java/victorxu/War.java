import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.PriorityQueue;


public class War {
	public static void main(String[] args) throws IOException{
		BufferedReader buf =  new BufferedReader(new FileReader("War.txt"));
		PrintWriter out = new PrintWriter(new FileWriter("WarOut.txt"));
		int t = Integer.parseInt(buf.readLine());
		for(int i = 0; i < t; i++){
			PriorityQueue<Pair> p = new PriorityQueue<Pair>();
			int n = Integer.parseInt(buf.readLine());
			String[] s = buf.readLine().split(" ");
			for(int j = 0; j < s.length; j++){
				p.add(new Pair(Double.parseDouble(s[j]),true));
			}
			s = buf.readLine().split(" ");
			for(int j = 0; j < s.length; j++){
				p.add(new Pair(Double.parseDouble(s[j]),false));
			}
			int fcount = 0;
			int ucount = 0;
			int fnum = 0;
			int unum = 0;
			while(!p.isEmpty()){
				Pair next = p.poll();
				if(next.n){
					fnum++;
					if(unum > 0){
						unum--;
						fcount++;
					}
				} else {
					unum++;
					if(fnum > 0){
						fnum--;
						ucount++;
					}
				}
			}
			out.println("Case #" + (i + 1) + ": " + fcount + " " + (n - ucount));
		}
		out.close();
	}
	static class Pair implements Comparable<Pair>{
		double w;
		boolean n;
		Pair(double a, boolean b){
			w = a;
			n = b;
		}
		public int compareTo(Pair o) {
			return Double.compare(this.w, o.w);
		}
	}
}
