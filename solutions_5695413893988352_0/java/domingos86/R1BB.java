package codejam.CJ2016.R1B;

import java.util.Scanner;

public class R1BB {
	
	private static long bestScore1;
	private static long bestScore2;
	
	private static String score1;
	private static String score2;
	private static int length;
	
	private static long abs(long num1, long num2) {
		return (num1>=num2) ? num1-num2 : num2-num1;
	}
	
	private static long pow10(int exp) {
		long result = 1;
		long mult = 10;
		while (exp>0) {
			if (exp%2 == 1) {
				result*=mult;
			}
			exp/=2;
			mult *= mult;
		}
		return result;
	}
	
	private static void removeBacklog(int position, int backlog, long num1, long num2) {
		long pow10 = pow10(backlog);
		iterate(position, 0, num1*pow10, num2*pow10);
		iterate(position, 0, num1*pow10, num2*pow10+1);
		iterate(position, 0, num1*pow10, num2*pow10+pow10-1);
		iterate(position, 0, num1*pow10+1, num2*pow10);
		iterate(position, 0, num1*pow10+pow10-1, num2*pow10);
	}
	
	private static void iterate(int position, int backlog, long num1, long num2) {
		if (position == length && backlog == 0) {
			if (abs(num1,num2)<abs(bestScore1, bestScore2) || 
					(abs(num1,num2)==abs(bestScore1,bestScore2) &&
					(num1 < bestScore1 || (num1==bestScore1 && num2 < bestScore2)))) {
				bestScore1 = num1;
				bestScore2 = num2;
			}
			return;
		}
		if (position == length) {
			removeBacklog(position, backlog, num1, num2);
			return;
		}
		char at1 = score1.charAt(position);
		char at2 = score2.charAt(position);
		if (at1=='?' && at2=='?') {
//			for (int k = 0; k<= 9; k++) {
//				for (int l = 0; l<=9; l++) {
//					iterate(position+1, 0, num1*10+k, num2*10+l);
//				}
//			}
			iterate(position+1, backlog+1, num1, num2);
		} else if(backlog > 0) {
			removeBacklog(position, backlog, num1, num2);
		} else if (at1!='?' && at2=='?') {
			int digit = at1-'0';
			if (num1>num2) {
				iterate(position+1, 0, num1*10+digit, num2*10+9);
			} else if (num1 < num2) {
				iterate(position+1, 0, num1*10+digit, num2*10);
			} else {
				int prec = (digit>0)? digit-1 : 9;
				int suc = (digit<9)? digit+1 : 0;
				iterate(position+1, 0, num1*10+digit, num2*10+digit);
				iterate(position+1, 0, num1*10+digit, num2*10+prec);
				iterate(position+1, 0, num1*10+digit, num2*10+suc);
			}
//			for (int k = 0; k<= 9; k++) {
//				iterate(position+1, 0, num1*10+digit, num2*10+k);
//			}
		} else if (at1=='?' && at2!='?') {
			int digit = at2-'0';
			if (num1 > num2) {
				iterate(position+1, 0, num1*10, num2*10+digit);
			} else if (num1 < num2) {
				iterate(position+1, 0, num1*10+9, num2*10+digit);
			} else {
				int prec = (digit>0)? digit-1 : 9;
				int suc = (digit<9)? digit+1 : 0;
				iterate(position+1, 0, num1*10+digit, num2*10+digit);
				iterate(position+1, 0, num1*10+prec, num2*10+digit);
				iterate(position+1, 0, num1*10+suc, num2*10+digit);
			}
			
//			for (int k = 0; k<= 9; k++) {
//				iterate(position+1, 0, num1*10+k, num2*10+digit);
//			}
		} else {
			iterate(position+1, 0, num1*10+at1-'0', num2*10+at2-'0');
		}
		
	}
	
	public static void main(String[] args){
		try(Scanner in = new Scanner(System.in)) {
			int t = in.nextInt();
			for(int i=1; i<=t; i++){
				score1 = in.next();
				score2 = in.next();
				bestScore1 = Long.MAX_VALUE;
				bestScore2 = 0;
				length = score1.length();
				
				iterate(0, 0, 0, 0);
				
				System.out.print("Case #" + i + ": ");
				System.out.print(String.format("%0" + length + "d %0" + length + "d", bestScore1, bestScore2));
				System.out.println();
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
