import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.StringTokenizer;


public class probB {
	static  String input = "probC.in";
	static  String output = "probC.out";
	public static void main(String[] args) throws IOException{
//		BufferedReader in =new BufferedReader(new InputStreamReader(System.in));
//		PrintWriter out = new PrintWriter(System.out);
		BufferedReader in =new BufferedReader(new FileReader(input));
	PrintWriter out = new PrintWriter(new FileWriter(output));
		
		int t = Integer.parseInt(in.readLine());
		
		for(int i=1; i<=t; i++){
			out.print("Case #"+i+": ");
			int n = Integer.parseInt(in.readLine());
			
			
			out.println(oneTest(n, in, out));
			out.flush();
		}
		
	}
	
	private static int oneTest(int n, BufferedReader in, PrintWriter out) throws IOException{
		reverse = new ArrayList[n+1];
		HashMap<Integer, Integer> bff = bff(in.readLine(), n);
		
		
		int res = 1;
		
		for(int i = 1; i<n; i++){
			
			res = Math.max(res, solve(bff,i));
			//System.out.println(i+" "+res);
		}
		return res;
	}
	private static int solveReverse(int cur, HashSet<Integer> all){
		ArrayList<Integer> [] gr = reverse;
		int res = 1;
		for(int i=0; i<reverse[cur].size(); i++){
			int next = reverse[cur].get(i);
			if(all.contains(next)) continue;
			res = Math.max(res, 1+solveReverse(next, all));
		}
		
		return res;
	}
	private static int solve(HashMap<Integer, Integer> bff, int first){
		int res = 0;
		ArrayList<Integer> circle = new ArrayList<>();
		HashSet<Integer> all = new HashSet<>();
		all.add(first);
		circle.add(first);
		while(true){
			first = bff.get(first);
			if(all.contains(first)){
				if(circle.get(0) == first){
					return res;
				} 
				
				if(circle.get(circle.size() - 2) == first || circle.get(circle.size() - 1) == first){
					break;
				} else {
					return 0;
				}
			}
			all.add(first);
			circle.add(first);
			res = Math.max(res, circle.size());
		}
		
		res = res + solveReverse(circle.get(0),all) - 1;
		res = res+solveReverse(circle.get(circle.size() - 1),all) - 1;
		return res;
	}
	
	static ArrayList<Integer> [] reverse;
	private static HashMap<Integer, Integer> bff(String str,  int n){
		HashMap<Integer, Integer> res  = new HashMap<>();
		StringTokenizer tok = new StringTokenizer(str);
		for(int i=0; i<=n; i++){
			reverse[i] = new ArrayList<>();
		}
		for(int i=1; i<=n; i++){
			int a = Integer.parseInt(tok.nextToken());
			res.put(i, a);
			reverse[a].add(i);
		}
		
		return res;
	}
}
