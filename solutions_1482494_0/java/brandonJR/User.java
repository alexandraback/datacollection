import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.util.PriorityQueue;

public class User {

	private static final String FILENAME = "B-small-attempt2.in";
	private static final String OUTFILENAME = FILENAME.substring(0,FILENAME.lastIndexOf("."))+".out";
	public static String newline = System.getProperty("line.separator");

	public static void main(String[] args) throws Exception {
		
		PrintWriter out = new PrintWriter(new FileWriter(OUTFILENAME));
	//	PrintStream out = System.out;
		
		FileReader fr = null;
		try {
			fr = new FileReader(FILENAME);
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		BufferedReader input = new BufferedReader(fr);
		
		int T = Integer.parseInt(input.readLine());
		
		for (int t=1; t<=T; t++){
			
			int gamesPlayed =0;
			int stars= 0;
			boolean toobad=false;

			int N = Integer.parseInt(input.readLine());
			String[] line;
			int[] oneCost =new int[N];
			int[] twoCost =new int[N];
			boolean[] onePlayable = new boolean[N];
			boolean[] twoPlayable =new boolean[N];
			int oneLeft = N;
			int twoLeft = N;
			int[] onePayout = new int[N];
			int[] twoPayout = new int[N];

			for (int n=0; n<N;n++){
				line = input.readLine().split(" ");
				int cost = Integer.parseInt(line[0]);
				oneCost[n]=cost;
				onePlayable[n] = true;
				onePayout[n] = 1;
				cost = Integer.parseInt(line[1]);
				twoCost[n]=cost;
				twoPlayable[n] = true;
				twoPayout[n]=2;
				
			}
			
			while (twoLeft>0 && !toobad){
				if (!anyPlayable(twoPlayable, twoCost, stars)){ //cannot play a two star level
					if (!anyPlayable(onePlayable, oneCost, stars)){ //cannot play a one star level
						toobad=true;
					}
					else{ //play a one star level
						playNextOne(onePlayable,oneCost,stars);
						gamesPlayed++;
						stars++;
						

				//		System.out.println("Won 1 stars ");
					}
				}
				else {
					int highPayoutIndex =  payTwoIndex(twoPlayable, twoCost, stars, onePlayable);
					gamesPlayed++;
					if (onePlayable[highPayoutIndex]){
						stars+=2;
						twoPlayable[highPayoutIndex]=false;
						onePlayable[highPayoutIndex]=false;
				//		System.out.println("Won 2 stars ");
						twoLeft--;
					}
					else {
						stars+=1;
						twoPlayable[highPayoutIndex]=false;
				//		System.out.println("Won 1 stars ");
						twoLeft--;
					}
				//	System.out.println("Won stars "+ currentGame.prize );
				}
			}
			
			String result;
			
			if (toobad) result = "Too Bad";
			else result = Integer.toString(gamesPlayed);
		
			
			out.println("Case #"+t+": "+result);
			
			
		}
		out.close();
		
	}

	private static int payTwoIndex(boolean[] twoPlayable,int[] twoCost,
			int stars , boolean[] onePlayable) {
		int len = twoPlayable.length;
		for (int i=0; i<len; i++){
			if ((twoPlayable[i] && onePlayable[i]) && twoCost[i]<=stars){
				return i;
			}
		}
		for (int i=0; i<len; i++){
			if (twoPlayable[i] && (twoCost[i]<=stars)){
				twoPlayable[i] = false;
				return i;
			}
		}
		
		return -1;
	
	}

	private static void playNextOne(boolean[] onePlayable, int[] oneCost,
			int stars) {
		int len = onePlayable.length;
		for (int i=0; i<len; i++){
			if (onePlayable[i] && oneCost[i]<=stars){
				onePlayable[i] = false;
				return;
			}
		}	
	}

	private static boolean anyPlayable(boolean[] twoPlayable, int[] twoCost, int stars) {

		int len = twoPlayable.length;
		for (int i=0; i<len; i++){
			if (twoPlayable[i] && twoCost[i]<=stars) return true;
		}
		return false;
	}

	private static int arrMax(int[] twoCost, boolean[] twoPlayable) {
		int max = Integer.MIN_VALUE;
		int index = -1;
		int len = twoCost.length;
		for (int i=0; i<len; i++){
			if (twoPlayable[i] && max<twoCost[i]) max = twoCost[i];
		}
		return index;
	}
	

}

class Level implements Comparable<Level>{
	
	int cost;
	int prize;
	int level;
	
	public Level(int cost, int prize, int level){
		this.cost = cost;
		this.prize = prize;
		this.level = level;
	}

	@Override
	public int compareTo(Level arg0) {
		if (cost<arg0.cost) return -1;
		if (cost>arg0.cost) return 1;
		return 0;
	}
	
	public int compareTo(int arg0) {
		if (cost<arg0) return -1;
		if (cost>arg0) return 1;
		return 0;
	}

}
	