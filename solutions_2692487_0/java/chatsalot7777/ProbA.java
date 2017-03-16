import java.util.Arrays;
import java.util.Scanner;


public class ProbA {
	static int motesArr[];
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int numCases = sc.nextInt();
		for(int caseNum=1; caseNum<=numCases; caseNum++){
			int armin = sc.nextInt();
			int numOthers = sc.nextInt();
			motesArr = new int[numOthers];
			int sum = 0;
			for(int i=0; i<numOthers; i++){
				motesArr[i] = sc.nextInt();
				sum += motesArr[i];
			}
			Arrays.sort(motesArr);
			memo = new int[motesArr.length][motesArr.length][armin*2+sum*2+10];
			hasMemo = new boolean[motesArr.length][motesArr.length][armin*2+sum*2+10];
			int ans = solve(0, motesArr.length-1, armin);
			System.out.printf("Case #"+caseNum+": "+ans+"\n");
		}
	}
	public static int memo[][][];
	public static boolean hasMemo[][][];
	
	public static int solve(int from, int to, int armin) throws Exception{
		if(from>to)
			return 0;
		if(hasMemo[from][to][armin])
			return memo[from][to][armin];
//		System.out.println(from+" "+to+" "+armin);
//		Thread.sleep(1000);
		int origFrom = from;
		int origTo = to;
		int origArm = armin;
		int ans = 0;
		while(true){
			while(from <= to && motesArr[from]<armin){
				armin += motesArr[from];
				from++;
			}
			if(from > to)
				break;
			int addRes = Integer.MAX_VALUE;
//			System.out.println(armin+armin-1);
			if(armin!=1)
				addRes = solve(from, to, armin+armin-1);
			int rmvRes = solve(from, to-1, armin);
//			ans += Math.min(addRes, rmvRes);
			ans++;
			if(rmvRes<addRes){
//				System.out.println("["+origFrom+","+origTo+","+origArm+"]: "+"rmv "+motesArr[to]);
				to--;
			}else{
//				System.out.println("["+origFrom+","+origTo+","+origArm+"]: "+"add "+(armin-1));
				armin = armin+armin-1;
			}
		}
		memo[origFrom][origTo][origArm] = ans;
//		System.out.println(origFrom+" "+origTo+" "+origArm+" = "+ans);
		hasMemo[origFrom][origTo][origArm] = true;
		return ans;
	}
}
