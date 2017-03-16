import java.io.*;
import java.util.*;

public class AC {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner console = new Scanner(new File("ASF3.in"));
		PrintStream output = new PrintStream(new File("ACF.txt"));
		int caseNum = console.nextInt();
		for (int i = 1; i <= caseNum; i++) {
			int R = console.nextInt();
			int C = console.nextInt();
			int W = console.nextInt();
			output.println("Case #" + i + ": " + result(R, C, W));
			}
	}

	public static int result(int R, int C, int W) {
		int res=0;
		if(C%W==0){
			return R*C/W+W-1;
		}
		res=C/W;
		res=R*res;
		if(W==1){
			return res;
		}
		if(W==2){
			return res+2;
		}
		if(C%W==1){
			return res+W;
		}
		res=res+W;
		return res;
	}

}
