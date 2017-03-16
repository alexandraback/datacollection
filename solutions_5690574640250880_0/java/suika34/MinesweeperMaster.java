import java.io.BufferedReader;
import java.io.InputStreamReader;


public class MinesweeperMaster {

	public static void main(String[] args) {
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			String line = br.readLine();
			int T = Integer.parseInt(line);

			for (int i=1; i<=T; i++) {
				line = br.readLine();
				String[] array = line.split(" ");
				int R = Integer.parseInt(array[0]);
				int C = Integer.parseInt(array[1]);
				int M = Integer.parseInt(array[2]);

				String result = solve_small(R, C, M);

				System.out.println("Case #"+i+": "+result);
				//System.out.println("Case #"+i+": "+R+" "+C+" "+M+result);
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	private static String solve_small(int R, int C, int M) {
		int shortEdge = R;
		int longEdge = C;
		if (longEdge < shortEdge) {
			shortEdge = C;
			longEdge = R;
		}

		boolean impossible = false;
		String[] board = new String[shortEdge];
		if (shortEdge == 1) {
			return line(R, C, M);
		} else if (shortEdge == 2) {
			if (longEdge == 2) {
				if (M==1 || M==2) {
					impossible = true;
				} else if (M == 0) {
					board[0] = "c.";
					board[1] = "..";
				} else if (M==3){
					board[0] = "c*";
					board[1] = "**";
				}
			} else if (longEdge == 3) {
				if (M==1 || M==3 || M==4) {
					impossible = true;
				} else if (M==0) {
					board[0] = "c..";
					board[1] = "...";
				} else if (M==2) {
					board[0] = "c.*";
					board[1] = "..*";
				} else if (M==5) {
					board[0] = "c**";
					board[1] = "***";
				}
			} else if (longEdge == 4) {
				if (M==1 || M==3 || M==5 || M==6) {
					impossible = true;
				} else if (M==0) {
					board[0] = "c...";
					board[1] = "....";
				} else if (M==2) {
					board[0] = "c..*";
					board[1] = "...*";
				} else if (M==4) {
					board[0] = "c.**";
					board[1] = "..**";
				} else if (M==7) {
					board[0] = "c***";
					board[1] = "****";
				}
			} else if (longEdge == 5) {
				if (M==1 || M==3 || M==5 || M==7 || M==8) {
					impossible = true;
				} else if (M==0) {
					board[0] = "c....";
					board[1] = ".....";
				} else if (M==2) {
					board[0] = "c...*";
					board[1] = "....*";
				} else if (M==4) {
					board[0] = "c..**";
					board[1] = "...**";
				} else if (M==6) {
					board[0] = "c.***";
					board[1] = "..***";
				} else if (M==9){
					board[0] = "c****";
					board[1] = "*****";					
				}
			}
		} else if (shortEdge == 3) {
			if (longEdge == 3) {
				if (M==2 || M==4 || M==6 || M==7) {
					impossible = true;
				} else if (M==0) {
					board[0] = "c..";
					board[1] = "...";
					board[2] = "...";
				} else if (M==1) {
					board[0] = "c..";
					board[1] = "...";
					board[2] = "..*";
				} else if (M==3) {
					board[0] = "c..";
					board[1] = "...";
					board[2] = "***";
				} else if (M==5) {
					board[0] = "c.*";
					board[1] = "..*";
					board[2] = "***";
				} else if (M==8) {
					board[0] = "c**";
					board[1] = "***";
					board[2] = "***";
				}
			} else if (longEdge == 4) {
				if (M==5 || M==7 || M==9 || M==10) {
					impossible = true;
				} else if (M==0) {
					board[0] = "c...";
					board[1] = "....";
					board[2] = "....";
				} else if (M==1) {
					board[0] = "c...";
					board[1] = "....";
					board[2] = "...*";
				} else if (M==2) {
					board[0] = "c...";
					board[1] = "....";
					board[2] = "..**";
				} else if (M==3) {
					board[0] = "c..*";
					board[1] = "...*";
					board[2] = "...*";
				} else if (M==4) {
					board[0] = "c...";
					board[1] = "....";
					board[2] = "****";
				} else if (M==6) {
					board[0] = "c.**";
					board[1] = "..**";
					board[2] = "..**";
				} else if (M==8) {
					board[0] = "c.**";
					board[1] = "..**";
					board[2] = "****";
				} else if (M==11) {
					board[0] = "c***";
					board[1] = "****";
					board[2] = "****";
				}
			} else if (longEdge == 5) {
				if (M==8 || M==10 || M==12 || M==13) {
					impossible = true;
				} else if (M==0) {
					board[0] = "c....";
					board[1] = ".....";
					board[2] = ".....";
				} else if (M==1) {
					board[0] = "c....";
					board[1] = ".....";
					board[2] = "....*";
				} else if (M==2) {
					board[0] = "c....";
					board[1] = ".....";
					board[2] = "...**";
				} else if (M==3) {
					board[0] = "c....";
					board[1] = ".....";
					board[2] = "..***";
				} else if (M==4) {
					board[0] = "c...*";
					board[1] = "....*";
					board[2] = "...**";
				} else if (M==5) {
					board[0] = "c....";
					board[1] = ".....";
					board[2] = "*****";
				} else if (M==6) {
					board[0] = "c..**";
					board[1] = "...**";
					board[2] = "...**";
				} else if (M==7) {
					board[0] = "c..**";
					board[1] = "...**";
					board[2] = "..***";
				} else if (M==9) {
					board[0] = "c.***";
					board[1] = "..***";
					board[2] = "..***";
				} else if (M==11) {
					board[0] = "c.***";
					board[1] = "..***";
					board[2] = "*****";
				} else if (M==14) {
					board[0] = "c****";
					board[1] = "*****";
					board[2] = "*****";
				}
			}
		} else if (shortEdge == 4) {
			if (longEdge == 4) {
				if (M==9 || M==11 || M==13 || M==14) {
					impossible = true;
				} else if (M==0) {
					board[0] = "c...";
					board[1] = "....";
					board[2] = "....";
					board[3] = "....";
				} else if (M==1) {
					board[0] = "c...";
					board[1] = "....";
					board[2] = "....";
					board[3] = "...*";
				} else if (M==2) {
					board[0] = "c...";
					board[1] = "....";
					board[2] = "....";
					board[3] = "..**";
				} else if (M==3) {
					board[0] = "c...";
					board[1] = "....";
					board[2] = "...*";
					board[3] = "..**";
				} else if (M==4) {
					board[0] = "c...";
					board[1] = "....";
					board[2] = "....";
					board[3] = "****";
				} else if (M==5) {
					board[0] = "c...";
					board[1] = "....";
					board[2] = "...*";
					board[3] = "****";
				} else if (M==6) {
					board[0] = "c...";
					board[1] = "....";
					board[2] = "..**";
					board[3] = "****";
				} else if (M==7) {
					board[0] = "c..*";
					board[1] = "...*";
					board[2] = "...*";
					board[3] = "****";
				} else if (M==8) {
					board[0] = "c...";
					board[1] = "....";
					board[2] = "****";
					board[3] = "****";
				} else if (M==10) {
					board[0] = "c..*";
					board[1] = "...*";
					board[2] = "****";
					board[3] = "****";
				} else if (M==12) {
					board[0] = "c.**";
					board[1] = "..**";
					board[2] = "****";
					board[3] = "****";
				} else if (M==15) {
					board[0] = "c***";
					board[1] = "****";
					board[2] = "****";
					board[3] = "****";
				}
			} else if (longEdge == 5) {
				if (M==13 || M==15 || M==17 || M==18) {
					impossible = true;
				} else if (M==0) {
					board[0] = "c....";
					board[1] = ".....";
					board[2] = ".....";
					board[3] = ".....";
				} else if (M==1) {
					board[0] = "c....";
					board[1] = ".....";
					board[2] = ".....";
					board[3] = "....*";
				} else if (M==2) {
					board[0] = "c....";
					board[1] = ".....";
					board[2] = ".....";
					board[3] = "...**";
				} else if (M==3) {
					board[0] = "c....";
					board[1] = ".....";
					board[2] = ".....";
					board[3] = "..***";
				} else if (M==4) {
					board[0] = "c...*";
					board[1] = "....*";
					board[2] = "....*";
					board[3] = "....*";
				} else if (M==5) {
					board[0] = "c....";
					board[1] = ".....";
					board[2] = ".....";
					board[3] = "*****";
				} else if (M==6) {
					board[0] = "c....";
					board[1] = ".....";
					board[2] = "....*";
					board[3] = "*****";
				} else if (M==7) {
					board[0] = "c....";
					board[1] = ".....";
					board[2] = "...**";
					board[3] = "*****";
				} else if (M==8) {
					board[0] = "c....";
					board[1] = ".....";
					board[2] = "..***";
					board[3] = "*****";
				} else if (M==9) {
					board[0] = "c...*";
					board[1] = "....*";
					board[2] = "...**";
					board[3] = "*****";
				} else if (M==10) {
					board[0] = "c....";
					board[1] = ".....";
					board[2] = "*****";
					board[3] = "*****";
				} else if (M==11) {
					board[0] = "c..**";
					board[1] = "...**";
					board[2] = "...**";
					board[3] = "*****";
				} else if (M==12) {
					board[0] = "c.***";
					board[1] = "..***";
					board[2] = "..***";
					board[3] = "..***";
				} else if (M==14) {
					board[0] = "c..**";
					board[1] = "...**";
					board[2] = "*****";
					board[3] = "*****";
				} else if (M==16) {
					board[0] = "c.***";
					board[1] = "..***";
					board[2] = "*****";
					board[3] = "*****";
				} else if (M==19) {
					board[0] = "c****";
					board[1] = "*****";
					board[2] = "*****";
					board[3] = "*****";
				}
			}
		} else if (shortEdge == 5) {
			if (longEdge == 5) {
				if (M==18 || M==20 || M==22 || M==23) {
					impossible = true;
				} else if (M==0) {
					board[0] = "c....";
					board[1] = ".....";
					board[2] = ".....";
					board[3] = ".....";
					board[4] = ".....";
				} else if (M==1) {
					board[0] = "c....";
					board[1] = ".....";
					board[2] = ".....";
					board[3] = ".....";
					board[4] = "....*";
				} else if (M==2) {
					board[0] = "c....";
					board[1] = ".....";
					board[2] = ".....";
					board[3] = ".....";
					board[4] = "...**";
				} else if (M==3) {
					board[0] = "c....";
					board[1] = ".....";
					board[2] = ".....";
					board[3] = ".....";
					board[4] = "..***";
				} else if (M==4) {
					board[0] = "c....";
					board[1] = ".....";
					board[2] = ".....";
					board[3] = "...**";
					board[4] = "...**";
				} else if (M==5) {
					board[0] = "c....";
					board[1] = ".....";
					board[2] = ".....";
					board[3] = ".....";
					board[4] = "*****";
				} else if (M==6) {
					board[0] = "c....";
					board[1] = ".....";
					board[2] = ".....";
					board[3] = "....*";
					board[4] = "*****";
				} else if (M==7) {
					board[0] = "c....";
					board[1] = ".....";
					board[2] = ".....";
					board[3] = "...**";
					board[4] = "*****";
				} else if (M==8) {
					board[0] = "c....";
					board[1] = ".....";
					board[2] = ".....";
					board[3] = "..***";
					board[4] = "*****";
				} else if (M==9) {
					board[0] = "c...*";
					board[1] = "....*";
					board[2] = "....*";
					board[3] = "....*";
					board[4] = "*****";
				} else if (M==10) {
					board[0] = "c....";
					board[1] = ".....";
					board[2] = ".....";
					board[3] = "*****";
					board[4] = "*****";
				} else if (M==11) {
					board[0] = "c....";
					board[1] = ".....";
					board[2] = "....*";
					board[3] = "*****";
					board[4] = "*****";
				} else if (M==12) {
					board[0] = "c....";
					board[1] = ".....";
					board[2] = "...**";
					board[3] = "*****";
					board[4] = "*****";
				} else if (M==13) {
					board[0] = "c....";
					board[1] = ".....";
					board[2] = "..***";
					board[3] = "*****";
					board[4] = "*****";
				} else if (M==14) {
					board[0] = "c..**";
					board[1] = "...**";
					board[2] = "...**";
					board[3] = "..***";
					board[4] = "*****";
				} else if (M==15) {
					board[0] = "c....";
					board[1] = ".....";
					board[2] = "*****";
					board[3] = "*****";
					board[4] = "*****";
				} else if (M==16) {
					board[0] = "c..**";
					board[1] = "...**";
					board[2] = "...**";
					board[3] = "*****";
					board[4] = "*****";
				} else if (M==17) {
					board[0] = "c...*";
					board[1] = "....*";
					board[2] = "*****";
					board[3] = "*****";
					board[4] = "*****";
				} else if (M==19) {
					board[0] = "c..**";
					board[1] = "...**";
					board[2] = "*****";
					board[3] = "*****";
					board[4] = "*****";
				} else if (M==21) {
					board[0] = "c.***";
					board[1] = "..***";
					board[2] = "*****";
					board[3] = "*****";
					board[4] = "*****";
				} else if (M==24) {
					board[0] = "c****";
					board[1] = "*****";
					board[2] = "*****";
					board[3] = "*****";
					board[4] = "*****";
				}
			}
		}
		
		
		if (impossible) {
			return "\nImpossible";
		} else {
			StringBuffer buff = new StringBuffer();
			if (shortEdge == R) {
				for (int i=0; i<shortEdge; i++) {
					buff.append("\n"+board[i]);
				}
			} else {
				char[][] temp = new char[longEdge][shortEdge];
				for (int i=0; i<R; i++) {
					for (int j=0; j<C; j++) {
						temp[i][j] = board[j].charAt(i);
					}
					buff.append("\n"+String.valueOf(temp[i]));
				}				
			}
			return buff.toString();
		}
	}
	
	private static String line(int R, int C, int M) {
		int length = R;
		if (R == 1) {
			length = C;
		}
		if (length == M) {
			return "\nImpossible";
		} 
		char[] board = new char[length];
		for (int i=0; i<length; i++) {
			if (i==0) {
				board[i] = 'c';
			} else if (i < length - M) {
				board[i] = '.';
			} else {
				board[i] = '*';
			}
		}
		if (length == C) {
			return "\n"+String.valueOf(board);
		} else {
			StringBuffer buff = new StringBuffer();
			for (char c : board) {
				buff.append("\n"+c);
			}
			return buff.toString();
		}
	}

}
