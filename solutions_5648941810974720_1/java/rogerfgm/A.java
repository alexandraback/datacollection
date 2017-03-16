

import java.io.*;
import java.util.*;

import static java.lang.Math.*;
import static java.lang.Integer.*;

public class A {
	static Scanner sc = null;
	static BufferedReader br = null;
	static PrintWriter out = null;
	static PrintStream sysout = System.out;
	static Random rnd = new Random();
	
	int INF = Integer.MAX_VALUE / 10;
	double DF = 0.0000000001;
	
	long b = 1;
	int N = 0;
	int M = 0;
	List<String> list = new ArrayList<>();

	
	public void solve() throws Exception{
		String s = br.readLine();
		list = new ArrayList<>();
		for(int i = 0; i < s.length(); i++){
			list.add(s.substring(i, i+1));
		}
		
		List<Integer> ans = new ArrayList<>();
		while(list.contains("Z")){
			ans.add(0);
			list.remove("Z");
			list.remove("E");
			list.remove("R");
			list.remove("O");
		}
		while(list.contains("G")){
			ans.add(8);
			list.remove("E");
			list.remove("I");
			list.remove("G");
			list.remove("H");
			list.remove("T");
		}
		while(list.contains("W")){
			ans.add(2);
			list.remove("T");
			list.remove("W");
			list.remove("O");
		}
		while(list.contains("X")){
			ans.add(6);
			list.remove("S");
			list.remove("I");
			list.remove("X");
		}
		while(list.contains("T")){
			ans.add(3);
			list.remove("T");
			list.remove("H");
			list.remove("R");
			list.remove("E");
			list.remove("E");
		}
		while(list.contains("R")){
			ans.add(4);
			list.remove("F");
			list.remove("O");
			list.remove("U");
			list.remove("R");
		}
		while(list.contains("F")){
			ans.add(5);
			list.remove("F");
			list.remove("I");
			list.remove("V");
			list.remove("E");
		}
		while(list.contains("O")){
			ans.add(1);
			list.remove("O");
			list.remove("N");
			list.remove("E");
		}
		while(list.contains("S")){
			ans.add(7);
			list.remove("S");
			list.remove("E");
			list.remove("V");
			list.remove("E");
			list.remove("N");
		}
		while(list.contains("N")){
			ans.add(9);
			list.remove("N");
			list.remove("I");
			list.remove("N");
			list.remove("E");
		}
		
		if(list.size() > 0){
			print("");
		}
		Collections.sort(ans);
		StringBuilder ansb = new StringBuilder();
		for(int i = 0; i < ans.size(); i++){
			ansb.append(ans.get(i));
		}
		println(ansb.toString());

	}
	
	int count(String s){
		int cnt = 0;
		for(int i = 0; i< list.size(); i++){
			if(list.get(i).equals(s)){
				cnt++;
			}
		}
		
		return cnt;
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception{
		File file = new File("A-large.in");
		if(file.exists()){
			System.setIn(new BufferedInputStream(new FileInputStream(file)));
		}
		else{
			throw new Exception("can't find a input file : " + file.getAbsolutePath());
		}
		//sc =  new Scanner(System.in);
		br = new BufferedReader(new InputStreamReader(System.in));
		FileWriter fw = new FileWriter(new File("output.txt"));
		out = new PrintWriter(fw);
		
		A b = new A();
		int T = 0;
		if(sc != null){
			T = sc.nextInt();
		}
		else{
			T = parseInt(br.readLine());
		}
		int t = 1;
		while(t <= T){
			out.print("Case #" + t + ": ");
			System.out.print("Case #" + t + ": ");
			b.solve();
			t++;
		}
		out.close();
		fw.close();
	}
	
	void print(int i){
		out.print(i + "");
		System.out.print(i);
	}
	void println(int i){
		out.println(i + "");
		System.out.println(i);
	}
	void print(String s){
		out.print(s);
		System.out.print(s);
	}
	void println(String s){
		out.println(s);
		System.out.println(s);
	}
	void print(long i){
		out.print(i + "");
		System.out.print(i);
	}
	void println(long i){
		out.println(i + "");
		System.out.println(i);
	}
}
