import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;


public class InfiniteHouseofPancakes {

	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new File("D:\\javaspace\\codjam\\B-small-attempt0.in"));//
		int n = in.nextInt();
		PrintWriter out = new PrintWriter("D:\\javaspace\\Practise\\src\\out.txt");
		for(int i=1;i<=n;i++){
			int D = in.nextInt();
			int[] cakesNum = new int[D];
			for(int j=0;j<D;j++){
				cakesNum[j] = in.nextInt();
			}
			Arrays.sort(cakesNum);
			int res = findMinTime(cakesNum);
			out.println("Case #"+i+": "+res);
		}
		out.close();
		in.close();
	}

	private static int findMinTime(int[] cakesNum){
		int l=0, r = cakesNum[cakesNum.length-1];
		while(l<r-1){
			int m = (l+r)/2;
			if(isPossible(m,cakesNum)){
				r=m;
			}
			else{
				l=m;
			}
		}
		if(isPossible(r,cakesNum)){
			return r;
		}
		else{
			return l;
		}
	}
	
	private static boolean isPossible(int time, int[] cakesNum){
		boolean changed = true;
		int wait =0;
		while(changed&&wait<time){
			changed=false;
			int waitLeft = wait;
			for(int i=cakesNum.length-1;i>=0;i--){
				if(cakesNum[i]<=time-wait){
					continue;
				}
				else{
					int waitNeed = (int) (Math.ceil(cakesNum[i]*1.0/(time-wait))-1);
					waitLeft-=waitNeed;
					if(waitLeft<0){
						changed=true;
						wait-=waitLeft;
						break;
					}
				}
			}
		}
		return wait<time;
	}
}
