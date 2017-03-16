import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;


public class ProbB {
	static boolean[][] events;
	public static void main(String[] args) {
		events = new boolean[1<<20][20];
		for(int i=0; i<events.length; i++){
			int num = i;
			for(int j=0; j<20; j++){
				events[i][j] = num%2!=0;
				num /= 2;
			}
		}
		Scanner sc = new Scanner(System.in);
		int numCases = sc.nextInt();
		for(int i=0; i<numCases; i++)
			solve(i+1, sc.nextInt(), sc.nextInt(), sc.nextInt());
		sc.close();
	}
	public static void solve(int caseNum, int num, int x, int y){
		int numIn = 0;
		for(int i=0; i<1<<num; i++){
			boolean[] dirs = events[i];
			
//			System.out.println("Event: "+i);
			
			HashSet<Integer> hasDie = new HashSet<Integer>();
			int top = 0;
			int xSlideFromLeft[] = new int[40];
			int xSlideFromRight[] = new int[40];
			for(int j=0; j<xSlideFromLeft.length; j++){
				xSlideFromRight[j] = -j-1;
				xSlideFromLeft[j] = j+1;
			}
			hasDie.add(hash(0,0));
			top = 2;
			for(int die=1; die<num; die++){
				int landX = 0;
				int landY = 0;
				if(!dirs[die]){	//to left
					landX = xSlideFromRight[top]+1;
					if(landX!=0){
						xSlideFromRight[top]++;
						landY = landX + top;
					}else{
						landX = xSlideFromLeft[top]-1;
						xSlideFromLeft[top]--;
						landY = -landX + top;
					}
				}else{	//to right
					landX = xSlideFromLeft[top]-1;
					if(landX!=0){
						xSlideFromLeft[top]--;
						landY = -landX + top;
					}else{
						landX = xSlideFromRight[top]+1;
						xSlideFromRight[top]++;
						landY = landX + top;
					}
				}
				if(landX==0)
					top+=2;
//				System.out.println("Die "+die+": NewTop:"+top+" x,y:"+landX+" "+landY);
				hasDie.add(hash(landX,landY));
			}
			if(hasDie.contains(hash(x,y)))
				numIn++;
		}
		double d = numIn/(double)(1<<num);
		System.out.printf("Case #%d: %f\n",caseNum, d);
	}
	public static int hash(int x, int y){
		x += 10000;
		return x*100000+y;
	}
}
