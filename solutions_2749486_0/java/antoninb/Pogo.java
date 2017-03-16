import java.io.File;
import java.io.FileNotFoundException;
import java.util.Locale;
import java.util.Scanner;


public class Pogo {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String fileName = "../B-small-attempt1.in";
		Scanner sC = null;
		try {
			sC = new Scanner(new File(fileName));
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		int T = sC.nextInt();
		int X, Y;
		
		
		for(int t = 0; t < T; t++){
			X = sC.nextInt();
			Y = sC.nextInt();
			String result = "";
			
			int flagX = 0;
			int flagY = 0;
			if(X < 0){
				X = -X;
				flagX = 1;
			}
			if(Y < 0){
				Y = -Y;
				flagY = 1;
			}
			
			if(X ==2 && Y == 2){
				if(flagX == 1){
					result = result + "E";
				}
				else{
					result = result + "W";
				}
				if(flagY == 1){
					result = result + "S";
				}
				else{
					result = result + "N";
				}
				if(flagX == 1){
					result = result + "W";
				}
				else{
					result = result + "E";
				}
				System.out.println("Case #" + (t + 1) + ": " + result);
				continue;
			}
			
			if(X < Y){
				int x =0;
				int jump = 1;
				while(x != X){
					if(x + jump <= X){
						if(flagX == 1){
							result = result + "W";
						}
						else{
							result = result + "E";
						}
						x = x + jump;
					}
					else{
						if(flagX == 1){
							result = result + "E";
						}
						else{
							result = result + "W";
						}
						x = x - jump;
					}
					jump++;
				}
				if(Y == 1 && flagY == 0){
					result = result + "SN";
				}
				else if(Y == 1 && flagY == 1){
					result = result + "NS";
				}
				else if(Y < jump) System.out.println("IMPOSSIBLE!");
				else{
					int y = 0;
					while(y != Y){
						if(y + jump <= Y){
							if(flagY == 1){
								result = result + "S";
							}
							else{
								result = result + "N";
							}
							y = y + jump;
						}
						else{
							if(flagY == 1){
								result = result + "N";
							}
							else{
								result = result + "S";
							}
							y = y - jump;
						}
						jump++;
					}
				}
			}
			else{
				int y =0;
				int jump = 1;
				while(y != Y){
					if(y + jump <= Y){
						if(flagY == 1){
							result = result + "S";
						}
						else{
							result = result + "N";
						}
						y = y + jump;
					}
					else{
						if(flagY == 1){
							result = result + "N";
						}
						else{
							result = result + "S";
						}
						y = y - jump;
					}
					jump++;
				}
				if(X == 1 && flagX == 0){
					result = result + "WE";
				}
				else if(X == 1 && flagX == 1){
					result = result + "EW";
				}
				else if(X < jump) System.out.println("IMPOSSIBLE!");
				else{
					int x = 0;
					while(x != X){
						if(x + jump <= X){
							if(flagX == 1){
								result = result + "W";
							}
							else{
								result = result + "E";
							}
							x = x + jump;
						}
						else{
							if(flagX == 1){
								result = result + "E";
							}
							else{
								result = result + "W";
							}
							x = x - jump;
						}
						jump++;
					}
				}
			}
			
			System.out.println("Case #" + (t + 1) + ": " + result);
		}
	}

}
