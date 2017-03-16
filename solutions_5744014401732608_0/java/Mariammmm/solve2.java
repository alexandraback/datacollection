import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;
import java.util.TreeSet;


public class solve2 {
	static  String input = "solve2.in";
	static  String output = "solve2.out";
	public static void main(String[] args) throws IOException{
//		BufferedReader in =new BufferedReader(new InputStreamReader(System.in));
//		PrintWriter out = new PrintWriter(System.out);
		BufferedReader in =new BufferedReader(new FileReader(input));
		PrintWriter out = new PrintWriter(new FileWriter(output));
		
		int t = Integer.parseInt(in.readLine());
		
		for(int i=1; i<=t; i++){
			out.print("Case #"+i+": ");
			StringTokenizer tok = new StringTokenizer(in.readLine());
			b = Integer.parseInt(tok.nextToken());
			m = Integer.parseInt(tok.nextToken());
			oneTest(out);
			//out.println();
		}
		out.flush();
	}
	
	public static void oneTest(PrintWriter out){
		 st = new ArrayList<>();
		 en = new ArrayList<>();
		 roadExists=new boolean[b][b];
//		 roadExists = new boolean [][]{
//				 {false,true,false,false,true},
//				 {false,false,true,true,false},
//				 {false,false,false,false,true},
//				 {false,false,true,false,true},
//				 {false,false,false,false,false}};
//		 out.print(countRoads(0, new TreeSet<>()));
		for(int start=0; start<b; start++){
			for(int end=0; end<b; end++){
				
				if(start == b - 1) continue;
				if(end == 0) continue;
				if(start == end) continue;
				
				st.add(start);
				en.add(end);
			}
		}
		
		if(!solve(0, out)){
			out.println("IMPOSSIBLE");
		}
	}
	
	static boolean solve(int cur, PrintWriter out){
		//print(out);
		if(cur == st.size()){
			
			
			if(countRoads(0, new HashSet<>()) == m) {
				
				print(out);
				return true;
			}
			return false;
		}
		
		if(solve(cur+1, out)) return true;
		roadExists[st.get(cur)][en.get(cur)] = true;
		boolean res = solve(cur+1,out);
		roadExists[st.get(cur)][en.get(cur)] = false;
		return res;
	}
	
	private static void print(PrintWriter out){
		out.println("POSSIBLE");
		for(int i=0; i<b; i++){
			for(int j=0; j<b; j++){
				if(roadExists[i][j]){
					out.print(1);
				}	else {
					out.print(0);
				}
			}
			out.println();
		}
	}
	static boolean [][] roadExists;
	static int b;
	static int m;
	static ArrayList<Integer> st;
	static ArrayList<Integer> en;
	static int countRoads(int curNode, Set<Integer> visited){
		if(curNode == b -1) return 1;
		visited.add(curNode);
		int res = 0;
		for(int i=0; i<b; i++){
			if(roadExists[curNode][i]&&i!=curNode&&visited.contains(i)){
				visited.remove(curNode);
				return m+3;
			}
			if(visited.contains(i)|| !roadExists[curNode][i])
				continue;
			
			res = res+countRoads(i, visited);
			if(res > m) return res;
		}
		
		visited.remove(curNode);
		return res;
	}
}
