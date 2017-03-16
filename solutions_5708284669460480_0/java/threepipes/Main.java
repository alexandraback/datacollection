import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
	public static char[] s2;
	public static char[] s1;
	public static void main(String[] args) throws NumberFormatException,
	IOException {
		ContestScanner in = new ContestScanner("in.dat");
//		ContestScanner in = new ContestScanner();
		ContestWriter out = new ContestWriter("out.dat");
		int t = in.nextInt();
		for(int test = 0; test < t; test++){
			int k = in.nextInt();
			int l = in.nextInt();
			int s = in.nextInt();
			s1 = in.nextToken().toCharArray();
			s2 = in.nextToken().toCharArray();
			char[] alp = new char[26];
			for(int i=0; i<k; i++){
				alp[s1[i]-'A']++;
			}
			res = new char[s];
			max = 0;
			banana = 0;
			count = 0;
			double s2prob = 1;
			for(int i=0; i<l; i++){
				s2prob *= (double)alp[s2[i]-'A']/k;
			}
			int diff = l;
			for(int i=1; i<l; i++){
				boolean same = true;
				for(int j=0; j<l-i; j++){
					if(s2[i+j] != s2[j]){
						same = false;
						break;
					}
				}
				if(same){
					diff = i;
					break;
				}
			}
//			double max = 1+(s-l)/diff;
//			for(int i=1; i<=max; i++){
//				
//			}
			dfs(0);
			double res = (double)banana/count; 
			
			out.println("Case #"+(test+1)+": "+(max - res)+"");
//			System.out.println(max);
		}
		out.close();
	}
	
	public static char[] res;
	public static long banana = 0;
	public static long count = 0;
	public static int max = 0;
	public static void dfs(int idx){
		if(idx==res.length){
			int cnt = 0;
			for(int i=0; i<res.length; i++){
				boolean same = true;
				for(int j=0; j<s2.length; j++){
					if(i+j >= res.length || res[i+j] != s2[j]){
						same = false;
						break;
					}
				}
				if(same){
					banana++;
					cnt++;
				}
			}
			if(cnt > max) max = cnt;
			count++;
			return;
//			return cnt;
		}
		for(int i=0; i<s1.length; i++){
			res[idx] = s1[i];
			dfs(idx+1);
		}
	}
	
}

class Node{
	int id;
	HashSet<Node> edge = new HashSet<Node>();
	public Node(int id) {
		this.id = id;
	}
	public void createEdge(Node node) {
		edge.add(node);
	}
}

class MyComp implements Comparator<int[]> {
	final int idx;
	public MyComp(int idx){
		this.idx = idx;
	}
	public int compare(int[] a, int[] b) {
		return a[idx] - b[idx];
	}
}

class Reverse implements Comparator<Integer> {
	public int compare(Integer arg0, Integer arg1) {
		return arg1 - arg0;
	}
}


class ContestWriter {
	private PrintWriter out;

	public ContestWriter(String filename) throws IOException {
		out = new PrintWriter(new BufferedWriter(new FileWriter(filename)));
	}

	public ContestWriter() throws IOException {
		out = new PrintWriter(System.out);
	}

	public void println(String str) {
		out.println(str);
	}

	public void print(String str) {
		out.print(str);
	}

	public void close() {
		out.close();
	}
}

class ContestScanner {
	private BufferedReader reader;
	private String[] line;
	private int idx;

	public ContestScanner() throws FileNotFoundException {
		reader = new BufferedReader(new InputStreamReader(System.in));
	}

	public ContestScanner(String filename) throws FileNotFoundException {
		reader = new BufferedReader(new InputStreamReader(new FileInputStream(
				filename)));
	}

	public String nextToken() throws IOException {
		if (line == null || line.length <= idx) {
			line = reader.readLine().trim().split(" ");
			idx = 0;
		}
		return line[idx++];
	}
	
	public String readLine() throws IOException{
		return reader.readLine();
	}

	public long nextLong() throws IOException, NumberFormatException {
		return Long.parseLong(nextToken());
	}

	public int nextInt() throws NumberFormatException, IOException {
		return (int) nextLong();
	}

	public double nextDouble() throws NumberFormatException, IOException {
		return Double.parseDouble(nextToken());
	}
}