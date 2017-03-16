import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class BoxFactory {

	static final String input_path = "data/input.txt";
	
	static class Produce {
		public long number;
		public long type;
		public Produce(long number, long type) {
			this.number = number;
			this.type = type;
		}
	}
	
	/**
	 * Good luck, Wash :)
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader(input_path)); 
		String intext = in.readLine();
		int T = Integer.parseInt(intext);
		for (int caseIter = 0; caseIter < T; caseIter ++) {
			intext = in.readLine();
			String[] parts = intext.split(" ");
			
			int N = Integer.parseInt(parts[0]);
			int M = Integer.parseInt(parts[1]);
			
			Produce[] boxes = new Produce[N]; 
			Produce[] toys = new Produce[M];
			
			intext = in.readLine();
			parts = intext.split(" ");
			for (int i = 0; i < N; i ++)
				boxes[i] = new Produce(Long.parseLong(parts[2 * i]), Long.parseLong(parts[2 * i + 1]));
			
			intext = in.readLine();
			parts = intext.split(" ");
			for (int i = 0; i < M; i ++)
				toys[i] = new Produce(Long.parseLong(parts[2 * i]), Long.parseLong(parts[2 * i + 1]));
			
			long ans = solve(boxes, toys);
			System.out.println(String.format("Case #%d: %d", caseIter + 1, ans));
		}
		in.close();
	}

	private static long solve(Produce[] boxes, Produce[] toys) {
		int N = boxes.length;
		int M = toys.length;
		
		if (N == 3){
			if (boxes[0].type == boxes[1].type){
				boxes[0].number += boxes[1].number;
				boxes[1] = boxes[2];
				N = 2;
			} else if (boxes[1].type == boxes[2].type){
				boxes[1].number += boxes[2].number;
				N = 2;
			} 
		}
		
		if (N == 2){
			if (boxes[0].type == boxes[1].type){
				boxes[0].number += boxes[1].number;
				N = 1;
			}
		}
		
		long mmax = 0;	
		if (N == 1){
			for (int i = 0 ;i < M ;i++){
				if (toys[i].type == boxes[0].type){
					mmax += toys[i].number;
				}
			}
			mmax = min(mmax, boxes[0].number);
		} else if (N == 2) {
			for (int i = 0 ;i <= M ;i++){
				long tmmax = 0;
				long mmax1 = 0;
				for (int j = 0 ;j < i ;++j){
					if (toys[j].type == boxes[0].type){
						mmax1 += toys[j].number;
					}
				}
				tmmax += min(mmax1, boxes[0].number);
				long mmax2 = 0;
				for (int j = i ;j < M ;++j){
					if (toys[j].type == boxes[1].type){
						mmax2 += toys[j].number;
					}
				}
				tmmax += min(mmax2, boxes[1].number);
				mmax = max(tmmax ,mmax);
			}
		}else if (N == 3){
			for (int i = 0 ;i <= M ;++i){
				for (int j = i ;j <= M ;++j){
					long tmmax = 0;
					long mmax1 = 0 ,mmax2 = 0 ,mmax3 = 0;
					for (int k = 0 ;k < i ;++k){
						if (toys[k].type == boxes[0].type)
							mmax1 += toys[k].number;
					}
					tmmax += min(mmax1, boxes[0].number);
					for (int k = i ;k < j ;++k){
						if (toys[k].type == boxes[1].type){
							mmax2 += toys[k].number;
						}
					}
					tmmax += min(mmax2, boxes[1].number);
					for (int k = j ;k < M ;++k){
						if (toys[k].type == boxes[2].type){
							mmax3 += toys[k].number;
						}
					}
					tmmax += min(mmax3 , boxes[2].number);
					mmax = max(mmax ,tmmax);
				}
			}
			if (boxes[0].type == boxes[2].type){
				long tmmax = 0;
				for (int i = 0 ;i < M ;i++){
					if (toys[i].type == boxes[0].type){
						tmmax += toys[i].number;
					}
				}
				tmmax = min(tmmax ,boxes[0].number + boxes[2].number);
				mmax = max(mmax ,tmmax);
			}
		}
		return mmax;
	}

	private static long min(long a, long b) {
		if (a < b)
			return a;
		else
			return b;
	}
	
	private static long max(long a, long b) {
		if (a > b)
			return a;
		else
			return b;
	}
}
