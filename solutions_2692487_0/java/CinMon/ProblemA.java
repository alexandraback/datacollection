package RoundB;

import java.util.Arrays;
import java.util.Scanner;

public class ProblemA {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int cases = input.nextInt();
		for (int c = 0; c < cases; c++) {
			int mSize = input.nextInt();
			int mSize2 = mSize;
			int N = input.nextInt();
			int[] particals = new int [N];
			for (int i = 0; i < N; i++) {
				particals[i] = input.nextInt();
			}
			//sorting
			Arrays.sort(particals);
			int operations1=0;
			for (int i = 0; i < particals.length; i++) {
				if(mSize > particals[i]){
					mSize+= particals[i];
				}else if(mSize + mSize-1 > particals[i]){//add partical
					mSize += (mSize -1)+ particals[i];
					operations1++;
				}else{//remove mote
					operations1++;
				}
			}
			if (operations1 > N)
				operations1 = N;
			
			int operations2=0;
			for (int i = 0; i < particals.length && operations2<=N; i++) {
				if(mSize2 > particals[i]){
					mSize2+= particals[i];
				}else if(mSize2==1){
					operations2++;
				}else {//add partical
					mSize2 += (mSize2 -1);
					operations2++;
					i--;
				}
			}
			System.out.format("Case #%d: %d\n", c + 1,operations1>operations2?operations2:operations1);
		}
	}

}
