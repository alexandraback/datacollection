import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;


public class CounterCulture2 {
	static String filename = "A-small-attempt1";
	static Scanner sc;
	
	public static void main(String[] args) throws FileNotFoundException{
		System.setIn(new FileInputStream(filename + ".in"));
		System.setOut(new PrintStream(filename + "COR.out"));
		sc = new Scanner(System.in);
		int t = sc.nextInt();
		int[] table = precompute(1000000);
		for(int casee = 1 ; casee<=t ; casee++){
			System.out.print("Case #" + casee + ": ");
			int n = sc.nextInt();
			System.out.println(table[n]);
		}
	}
	private static int[] precompute(int n) {
		int[] table = new int[n+1];
		Queue<Pair> q = new LinkedList<Pair>();
		q.add(new Pair(1, 1));
		while(!q.isEmpty()){
			Pair cur = q.poll();
			if(cur.val > n || table[cur.val] != 0){
				continue;
			}
			table[cur.val] = cur.dist;
			q.add(new Pair(cur.val+1, cur.dist+1));
			q.add(new Pair(reverse(cur.val), cur.dist+1));
		}
		return table;
	}
	private static int reverse(int val) {
		String revString = new StringBuilder(Integer.toString(val)).reverse().toString();
		return Integer.parseInt(revString);
	}
	
	static class Pair{
		int val;
		int dist;
		Pair(int a, int b){
			val = a;
			dist = b;
		}
	}
}
