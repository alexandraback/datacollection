import java.io.*;
import java.util.*;

public class Osmos {
	static class Hash{
		long a;
		int b;
		Hash(long a, int b){
			this.a = a;
			this.b = b;
		}
		public int hashCode(){
			return (int)a*1000007 + (int)b;
		}
		public boolean equals(Hash o){
			return a == o.a && b == o.b;
		}
	}
	static HashMap<Hash, Integer> memo;
	static int length;
	static long[] motes;
	
	static int solve(long mote, int nth){
		int answer = 0;
		if(nth == length){
			answer = 0;
		}else if(motes[nth] < mote){
			answer = solve(mote+motes[nth], nth+1);
		}else{
			int t1 = solve(2*mote-1, nth) + 1; //Put large mote
			int t2 = solve(mote, nth+1) + 1; //Drop mote
			
			if(t1 < t2){
				answer = t1;
			}else{
				answer = t2;
			}
		}
		memo.put(new Hash(mote, nth), answer);
		return answer;
	}
	
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		PrintStream out = new PrintStream(new BufferedOutputStream(System.out));
		int cases = sc.nextInt();
		for(int ctr=0; ctr<cases; ctr++){
			memo = new HashMap<Hash, Integer>();
			
			long mote = sc.nextLong();
			length = sc.nextInt();
			motes = new long[length];
			for(int i=0; i<length; i++){
				motes[i] = sc.nextLong();
			}
			Arrays.sort(motes);
			int answer;
			if(mote == 1){
				answer = length;
			}else{
				answer = solve(mote, 0);
			}
			out.printf("Case #%d: %d\n", ctr+1, answer);
		}
		out.flush();
	}
}
