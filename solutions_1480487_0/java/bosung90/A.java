import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Scanner;


public class A {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner scan = new Scanner(System.in);
		int testCases = scan.nextInt();
		int k = 0;
		while(testCases>0){
			testCases--;
			k++;
			
			int n = scan.nextInt();
			//LinkedList<Integer> scores = new LinkedList<Integer>();
			double[] ans = new double[n];
			int[] scores = new int[n];
			int x = 0;
			for(int i=0; i<n; i++){
				scores[i] = scan.nextInt();
				x += scores[i];
			}
			//System.out.println(x);
			//find lowest
			int lowest;
			lowest = scores[0];
			for(int i=1; i<n; i++){
				if(scores[i]<lowest)
					lowest = scores[i];
			}
			//count noLowest + find their indexes
			int noLowest = 0;
			ArrayList<Integer> lowestIndexes = new ArrayList<Integer>();
			for(int i=0; i<n; i++){
				if(scores[i]==lowest){
					noLowest ++;
					lowestIndexes.add(i);
				}
			}
			//find second
			int second = 999999999;
			for(int f=0; f<scores.length; f++){
				if(scores[f]<second && scores[f]>lowest){
					second = scores[f];
				}
			}
//			System.out.print(lowest +" , ");
//			System.out.print(x +" , ");
//			System.out.print(noLowest +" , ");
//			System.out.print(second +" , ");
//			System.out.print(Arrays.toString(ans) +" , ");
//			System.out.print(lowestIndexes.toString() +" , ");
//			System.out.print(1.0 +" , ");
//			System.out.print(Arrays.toString(scores) +" , ");
//			System.out.println();
			calcAns(lowest, x, noLowest, second, ans, lowestIndexes, x, scores);
			
//			for(int i=0; i<n; i++){
//				int myScore = scores[i];
//				int highest = 0;
//				for(int j=0; j<n; j++){
//					if(j==i)
//						continue;
//					if(highest<scores[j])
//						highest = scores[j];
//				}
//				
//				ans[i] = 0.5 - ((myScore - highest)/(2.0*x));
//				System.out.println(myScore + " : " + highest +" : " +x);
//				
//				
//			}
			
			
			System.out.print("Case #"+k+": ");
			for(int a = 0; a<n; a++){
				System.out.print(ans[a]*100+" ");
			}
			System.out.println();
			
			
			
			
			
			//System.out.printf("Case #%d: %.6f\n",k,ans*100);
		}
	}
	public static void calcAns(int lowest, int x, int noLowest, int second, double[] ans, ArrayList<Integer> lowestIndexes, int availScore, int[] scores){
		if((second-lowest)*noLowest>=availScore){
			for(int i=0; i<lowestIndexes.size(); i++){
				ans[lowestIndexes.get(i)] += (availScore/(double)noLowest)/x;
			}
		}
		else{
			//find next second
			int newSecond = 999999999;
			for(int f=0; f<scores.length; f++){
				if(scores[f]<newSecond && scores[f]>second){
					newSecond = scores[f];
				}
			}
			if(newSecond == 999999999){
				//find highest
				int highest = scores[0];
				for(int i=1; i<scores.length; i++){
					if(scores[i]>highest)
						highest = scores[i];
				}
				//find totalSpace
				int totalSpace = 0;
				for(int i=0; i<scores.length; i++){
					if(scores[i]<=lowest){
						totalSpace += highest-lowest;
					}
					else{
						totalSpace += highest - scores[i];
					}
				}
				double maxHeight = highest + ((availScore - totalSpace)/(double)scores.length);
				for(int i=0; i<scores.length; i++){
					ans[i] += (maxHeight - ((scores[i]<lowest)?lowest:scores[i]))/x;
				}
				return;
			}
			
			for(int i=0; i<lowestIndexes.size(); i++){
				ans[lowestIndexes.get(i)] += (second-lowest)/(double)x;
			}
			
			
			int newAvailScore = availScore - (second-lowest)*noLowest;
			int newNoLowest = noLowest;
			int newLowest = second;
			for(int s = 0; s<scores.length; s++){
				if(scores[s] == second){
					lowestIndexes.add(s);
					newNoLowest += 1;
				}
			}

			calcAns(newLowest, x , newNoLowest, newSecond, ans, lowestIndexes, newAvailScore, scores);
		}
	}
	
	public static void calcAns(int lowest, int x, int noLowest, int second, double[] ans, ArrayList<Integer> lowestIndexes,double totalPerc, int[] scores){
		if(lowest+(x*(totalPerc/noLowest))<=second){
			for(int i=0; i<lowestIndexes.size(); i++){
				ans[lowestIndexes.get(i)] += totalPerc/noLowest;
			}
		}
		else{
			double newTotalPerc = totalPerc - (second - lowest)/second * noLowest;
			double diff = (second - lowest)/second;
			for(int i=0; i<lowestIndexes.size(); i++){
				ans[lowestIndexes.get(i)] += diff;
			}
			int newNoLowest = noLowest;
			int newLowest = second;
			
			for(int s = 0; s<scores.length; s++){
				if(scores[s] == second){
					lowestIndexes.add(s);
					newNoLowest += 1;
				}
			}
			//find next second
			int newSecond = 999999999;
			for(int f=0; f<scores.length; f++){
				if(scores[f]<newSecond && scores[f]>second){
					newSecond = scores[f];
				}
			}
			
			
			calcAns(newLowest, x, newNoLowest, newSecond, ans, lowestIndexes, newTotalPerc, scores);
			
		}
		
		
	}

}
