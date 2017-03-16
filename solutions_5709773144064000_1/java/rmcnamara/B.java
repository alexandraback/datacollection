import java.io.File;
import java.io.FileInputStream;
import java.io.PrintStream;
import java.util.HashSet;
import java.util.Scanner;


public class B {
	public static double simTime(int facts, double prod, double price, double x){
		int curr = 0;
		double time = 0;
		while ( curr < facts ){
			double rate = 2 + prod * curr;
			time += price / rate;
			curr++;
		}
		
		time += x / (2 + facts * prod);
		return time;
		
	}
	
	public static void main( String[] args ) throws Exception{
		System.setIn(new FileInputStream("blarge.in"));
		System.setOut(new PrintStream(new File("blarge.out")));
		
		Scanner in = new Scanner(System.in);
		
		int T = in.nextInt();
		for ( int casenum = 1; casenum <= T; casenum++ ){
			double c = in.nextDouble();
			double f = in.nextDouble();
			double x = in.nextDouble();
			//System.out.println(simTime(3,f,c,x));
			
			int left = 0;
			int right = (int) (x / c) + 1;
			double leftSim = simTime(left,f,c,x);
//			while ( simTime(right, f, c, x ) <= leftSim ){
//				if ( right > 1000000 ){
//					int y = 0;
//					y++;
//				}
//				right *= 2;
//			}
			
			double min = Double.MAX_VALUE;
			while ( left < right ){
				int mid = (left + right) / 2;
				double midtime = simTime(mid,f,c,x);
				min = Math.min(midtime,min);
				double midtime2 = simTime(mid+1,f,c,x);
				min = Math.min(midtime2,min);
				min = Math.min(simTime(left,f,c,x),min);
				min = Math.min(simTime(right,f,c,x),min);
				if ( midtime2 < midtime ){
					left = mid + 1;
				}
				else{
					right = mid - 1;
				}
				
			}
			
			
			
			
			
			System.out.print("Case #" + casenum + ": ");
			System.out.printf("%.7f",min);
			System.out.println();
		}
	}
}
