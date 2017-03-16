package codejam.CJ2015;

import java.util.PriorityQueue;
import java.util.Scanner;

public class QRB {

	
	private static class Diner implements Comparable<QRB.Diner>{
		private int value;
		private int splits;
		private static int totalSplits=0;
		
		
		public Diner(int value){
			this.value = value;
			this.splits = 0;
		}
		
		public void split(){
			splits++;
			totalSplits++;
		}
		
/*		public boolean unSplit(){
			if(splits>0){
				splits--;
				totalSplits--;
				return true;
			}
			return false;
		}*/

		@Override
		public int compareTo(Diner o) {
			return - this.getMinutes() + o.getMinutes();
		}
		
/*		public int getValue(){
			return value;
		}
		
		public int getSplits(){
			return splits;
		}
		
		public static int getTotalSplits(){
			return totalSplits;
		}*/
		
		public int getMinutes(){
			return totalSplits + (value+splits)/(splits+1);
		}
		
		public static void reset(){
			totalSplits = 0;
		}
	}
	
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		for(int i=1; i<=t; i++){
			int d = in.nextInt();
			PriorityQueue<Diner> diners = new PriorityQueue<>(d);
			for(int j=0; j<d; j++){
				diners.add(new Diner(in.nextInt()));
			}
			int minMinutes = diners.peek().getMinutes();
			int curMinutes = minMinutes;
			while(true){
				Diner head = diners.poll();
				head.split();
				if(head.getMinutes()>minMinutes) break;
				diners.offer(head);
				curMinutes = diners.peek().getMinutes();
				if(curMinutes < minMinutes) minMinutes = curMinutes;
			}
			Diner.reset();
			
			System.out.print("Case #" + i + ": ");
			System.out.print(minMinutes);
			System.out.println();
		}
		
		in.close();
	}
}
