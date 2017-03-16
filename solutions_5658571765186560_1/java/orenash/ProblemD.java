

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class ProblemD {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	
	public static void main(String[] args) throws Exception {
		
		int cases = readInt();
		
		for (int caseNum=0; caseNum<cases; caseNum++) {
			
			int[] params = readInts();
			int X = params[0];
			int R = params[1];
			int C = params[2];
			int winner;
			
			if (R*C % X != 0) {
				winner = 0;
			} else {
				if (X<3) {
					winner = 1;
				} 
				else if (X==3) {
					if (R==1 || C==1) {
						winner = 0;
					} else {
						winner = 1;
					}
				}
				else if (X==4) {
					if (R==1 || C==1) {
						winner = 0;
					} else if (R==2 || C==2) {
						if (R>=6 || C>=6) {
							winner = 1;
						} else {
							winner = 0;
						}
					} else {
						winner = 1;
					}
				}
				else if (X==5) {
					if (R<=2 || C<=2) {
						winner = 0;
					} else if (R==3 || C==3) {
						if (R>=10 || C>=10) {
							winner = 1;
						} else {
							winner = 0;
						}
					} else {
						winner = 1;
					}
				}
				else if (X==6) {
					if (R<=3 || C<=3) {
						winner = 0;
					} else {
						winner = 1;
					}
				}
				else {
					winner = 0;
				}
			}
			
			System.out.println(String.format("Case #%d: %s", caseNum+1, winner==0 ? "RICHARD" : "GABRIEL"));
		}

	}
	
	private static int readInt() throws IOException {
		return Integer.parseInt(br.readLine());
	}
	
	private static int[] readInts() throws IOException {
		return Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
	}
	
}
