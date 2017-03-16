import java.io.*;
import java.util.*;

public class Template {
	public static void main(String[] args) throws IOException {
		if(!testing) pw = new PrintWriter(new FileWriter("out.txt"));
		int numTests = Integer.parseInt(rd.readLine());
		for(int t=1; t<=numTests; t++){
			st = new StringTokenizer(rd.readLine());
			int x = Integer.parseInt(st.nextToken()), y = Integer.parseInt(st.nextToken());
			int move = 1;
			pw.print("Case #"+t+": ");
			if(x!=0){
				if(x<0){
					for(int i=0; i<-x; i++) pw.print("EW");
				}
				else{
					for(int i=0; i<x; i++) pw.print("WE");
				}
			}
			if(y<0){
				for(int i=0; i<-y; i++) pw.print("NS");
			}
			else if(y>0){
				for(int i=0; i<y; i++) pw.print("SN");
			}
			pw.println();
		}
		pw.flush();
	}
	
	static ArrayList<Interval> intervals = new ArrayList<Interval>();
	
	static boolean isVowel(char ch){
		return !(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u');
	}
	
	static String S;
	
	static int n;
	
	static StringTokenizer st;
	static BufferedReader rd = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pw = new PrintWriter(System.out);
	
	static boolean testing = true;
	
}

class Interval{
	public int x, y;
	
	public Interval(int x, int y){
		this.x = x;
		this.y = y;
	}
	
	public static Comparator<Interval> cmp = new Comparator<Interval>() {
		
		@Override
		public int compare(Interval o1, Interval o2) {
			return o1.x-o2.x;
		}
	};
	
}