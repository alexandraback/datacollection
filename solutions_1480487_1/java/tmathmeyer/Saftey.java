package b1;

import java.io.File;
import java.text.DecimalFormat;
import java.util.Arrays;
import java.util.Scanner;

public class Saftey {
	public void run(){
		int[][] data = Reader.getInput(new File("A-large.in"));
		for (int i = 0; i < data.length; i++){
			int[] contest = data[i];
			int totalPoints = sumArray(contest);
			int tpc = totalPoints;
			int[] sorted = bubble_srt(contest);
			double Fmin = 0;
			while(tpc>=0){
				int min = getMin(sorted);
				int countMin = getCount(sorted, min);
				
				if (tpc < countMin){
					Fmin = min + (double)tpc/(double)countMin;
					tpc=-1;
					continue;
				}
				for (int q = 0; q < sorted.length; q++){
					if (sorted[q]==min && tpc>0){
						sorted[q]++;
						tpc--;
					}
				}
			}
			
			
			double required = Fmin;
			
			String printResult = "Case #"+(i+1)+":";
			
			for (int j = 0; j<contest.length; j++){
				int myScore = contest[j];
				double d = ((required-myScore)/totalPoints)*100;
				if (required<myScore)d = 0;
				printResult+=" "+d;
			}
			System.out.println(printResult);
		}	
	}
	
	
	
	
	public int sumArray(int[] a){
		int r = 0;
		for (int i : a)r+=i;
		return r;
	}
	
	public int getMin(int[] a){
		int b = 99999999;
		for (int i : a)
			b = i<b?i:b;
		return b;
	}
	
	public int getCount(int[] a, int b){
		int c = 0;
		for (int i : a)c = b==i?c+1:c;
		return c;
	}
	
	public int[] bubble_srt(int[] b){
		int[] a = Arrays.copyOf(b, b.length);
		  int i, j;
		  int t=0;
		  for(i = 0; i < a.length; i++){
			  for(j = 1; j < i; j++){
				  if(a[j-1] > a[j]){
					  t = a[j-1];
					  a[j-1]=a[j];
					  a[j]=t;
				  }
			  }
		  }
		  return a;
	}
	
	
	public static void main(String[] args){
		new Saftey().run();
	}
}







class Reader {
	public static int[][] getInput(File f){
		try {
			Scanner reader = new Scanner(f);
			int numLines = Integer.parseInt(reader.nextLine());
			int[][] res = new int[numLines][];
			for (int i = 0; i < res.length; i++){
				String[] nums = reader.nextLine().split(" ");
				int numContestants = Integer.parseInt(nums[0]);
				res[i] = new int[numContestants];
				for (int j = 0; j < numContestants; j++){
					res[i][j] = Integer.parseInt(nums[j+1]);
				}
			}
			return res;
		} catch (Exception e) {
			e.printStackTrace();
			return null;
		}
	}
}