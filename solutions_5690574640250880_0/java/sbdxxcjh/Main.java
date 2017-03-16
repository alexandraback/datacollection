import java.util.Arrays;
import java.util.Scanner;


public class Main {
	static Scanner in = new Scanner(System.in);
	public static void main(String[] arg){
		int T = in.nextInt();
		for(int i = 1; i <= T; i++){
			solve(i);
		}
	}
	public static void solve(int casenumber){
		int R = in.nextInt();
		int C = in.nextInt();
		int M = in.nextInt();
		int S = R * C - M;
		int remain = 0;
		boolean found = false;
		int quotients = 0;
		int maxeage = Math.max(R, C);
		int mineage = Math.min(R, C);
		int spareeage = 0;
		if(mineage == 1){
			found = true;
			remain = 0;
			quotients = S;
			spareeage = 1;
		}
		else if(S == 1){
			found = true;
			remain = 0;
			quotients = 1;
			spareeage = 1;
		}
		else if(S >= 2 * (R + C) - 4 && mineage > 3){
			found = true;
			quotients = -1;//Just do it!
		}
		else{
			for(int i = 2; i <= maxeage; i++){
				quotients = S / i;
				remain = S % i;

				int spareeage1 = remain == 0?quotients:quotients + 1;
				int spareeage2 = i;
				
				if(Math.max(spareeage1, spareeage2) <= maxeage 
						&& Math.min(spareeage2, spareeage1) <= mineage 
						&& quotients > 1
						&& remain != 1){
					found = true;
					spareeage = i;
					break;
				}
			}
		}
		System.out.println("Case #" + casenumber + ":");
		if(found == false)
			System.out.println("Impossible");
		else if(found == true && quotients == -1){//just brush it!
			int [][]map = new int[R][C];
			for(int i = 0 ; i < R; i++)
				Arrays.fill(map[i], 0);
			
			for(int c = 0 ; c < C ; c++){
				map[0][c] = 1;
				map[1][c] = 1;
			}
			
			for(int r = 0; r < R; r++){
				map[r][0] = 1;
				map[r][1] = 1;
			}
			
			map[0][0] = 2;
			
			int left = S - (2 * (R + C) - 4);
			int startrow = 2;
			while(left >0){
				if(left >= C - 2){ // brush one row
					for(int c = 2; c < C; c++){
						map[startrow][c] = 1;
						left--;
					}
					startrow++;
				}
				else{
					for(int c = 2 ; left > 0; c++){
						map[startrow][c] = 1;
						left--;
					}
					startrow++;
				}
			}
			
			for(int r = 0 ; r < R; r++){
				for(int c = 0 ; c < C; c++){
					switch(map[r][c]){
						case 0://mine
							System.out.print("*");
							break;
						case 1://space
							System.out.print(".");
							break;
						case 2://click
							System.out.print("c");
							break;
					}
				}
				System.out.println();//newline
			}
			
			
		}
		else{
			/*Print it*/
			/*1 represents space
			 *0 represents mine
			 **/
			int [][]map = new int[R][C];
			for(int i = 0 ; i < R; i++)
				Arrays.fill(map[i], 0);
			
			int spareeage1 = remain == 0?quotients: quotients+1;
			
			if(spareeage <= C && spareeage1 <= R){
				for(int r =0; r < quotients; r++){
					for(int c = 0; c < spareeage; c++){
						map[r][c] = 1;
					}
				}
				for(int c = 0; c < remain; c++){
					map[quotients][c] = 1;
				}
			}
			
			else{//another orientation
				for(int r = 0; r < spareeage; r++){
					for(int c = 0 ; c < quotients; c++){
						map[r][c] = 1;
					}
				}
				for(int r = 0; r < remain; r++){
					map[r][quotients] = 1;
				}
			}
			
			map[0][0] = 2;//current click point
			
			for(int r = 0 ; r < R; r++){
				for(int c = 0 ; c < C; c++){
					switch(map[r][c]){
						case 0://mine
							System.out.print("*");
							break;
						case 1://space
							System.out.print(".");
							break;
						case 2://click
							System.out.print("c");
							break;
					}
				}
				System.out.println();//newline
			}
		}
	}
}
