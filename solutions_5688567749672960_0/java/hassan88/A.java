import java.io.*;
import java.util.*;

public class A {
	public static void main(String[] args) throws IOException {
		BufferedInputStream bis = new BufferedInputStream(new FileInputStream("A-small-attempt0.in"));
		BufferedReader br = new BufferedReader(new InputStreamReader(bis));
		PrintWriter out = new PrintWriter(new File("A-small.out"));
		int cases = Integer.parseInt(br.readLine().trim());
		int [] shortest = new int [1000001];
		shortest [1] = 1;
		LinkedList <Integer> q = new LinkedList<Integer>();
		q.add(1);
		while(!q.isEmpty()) {
			int top = q.removeFirst();
			int first = top+1, second = reverseNum(top);
			if(first < shortest.length && shortest[first] == 0) {
				shortest[first] = shortest[top]+1;
				q.add(first);
			}
			if(second < shortest.length && shortest[second] == 0) {
				shortest[second] = shortest[top]+1;
				q.add(second);
			}
		}
		for (int c = 1; c <= cases; c++) {
			int num = Integer.parseInt(br.readLine());
			//System.out.println(reverseNum(num));
			out.println("Case #" + c + ": " + shortest[num]);
		}
		out.close();
	}
	public static int reverseNum(int n) {
		String nStr = n+"";
		int res = 0, len = nStr.length();
		for(int i = len-1;i >= 0;i--) {
			res *= 10;
			res += (nStr.charAt(i)-'0');
		}
		return res;	
	}
}