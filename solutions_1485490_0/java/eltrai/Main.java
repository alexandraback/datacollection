import java.util.Arrays;
import java.util.LinkedList;
import java.util.Scanner;

class Stock {
	int type;
	long number;
	Stock(int t, long n) {
		type = t;
		number = n;
	}
}

public class Main {
	static Stock[] toys;
	static Stock[] boxes;
	static int N;
	static int M;
	
	public static long result(int t_pos, int b_pos, long t_malus, long b_malus) {
		if(t_pos >= M || b_pos >= N)
			return 0;
		//System.out.println("Called. t_malus " + String.valueOf(t_malus) + "b_malus " + String.valueOf(b_malus));
		Stock b = boxes[b_pos];
		Stock t = toys[t_pos];
		//System.out.println("Called. t_val " + String.valueOf(t.number) + "b_val " + String.valueOf(b.number));
		//System.out.println("Called. t_pos " + String.valueOf(t_pos) + "b_pos " + String.valueOf(b_pos));
		if(b.type == t.type) {
			long tadd = t.number - t_malus;
			long badd = b.number - b_malus;
			if(badd > tadd) {
				//System.out.println("Added (limit t) " + String.valueOf(tadd));
				long old = result(t_pos+1, b_pos, 0, b_malus + tadd);
				//System.out.println("Can do (limit t) " + String.valueOf(old));
				return tadd + old;
			}
			else {
				//System.out.println("Added (limit b) " + String.valueOf(badd));
				long old = result(t_pos, b_pos+1, t_malus + badd, 0);
				//System.out.println("Can do (limit b) " + String.valueOf(old));
				return badd + old;
			}
		}
		long result1 = result(t_pos+1, b_pos, 0, b_malus);
		long result2 = result(t_pos, b_pos+1, t_malus, 0);
		return (result1 > result2)? result1 : result2;
	}
	
	public static void main(String [] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for(int x=0; x<T; x++) {
			N = in.nextInt();
			M = in.nextInt();
			toys = new Stock[M];
			boxes = new Stock[N];
			for(int i=0; i<N; i++) {
				long n = in.nextLong();
				int t = in.nextInt();
				boxes[i] = new Stock(t,n);
			}
			for(int i=0; i<M; i++) {
				long n = in.nextLong();
				int t = in.nextInt();
				toys[i] = new Stock(t,n);
			}
			long result = result(0,0,0,0);
			System.out.println("Case #" + String.valueOf(x+1) + ": " + String.valueOf(result));
		}
	}
}