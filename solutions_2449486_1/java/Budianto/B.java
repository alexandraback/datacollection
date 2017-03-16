import java.util.*;
import java.io.*;

public class B{
	public static void main(String[] args) throws Exception{
		Scanner in = new Scanner(System.in);
		
		int T = Integer.parseInt(in.nextLine());
		
		for(int caseNo=1;caseNo<=T;caseNo++){
			int N = in.nextInt();
			int M = in.nextInt();
			
			int[][] board = new int[N][M];
			TreeSet<Integer> numberSet = new TreeSet<Integer>();
			
			for(int i=0;i<N;i++){
				for(int j=0;j<M;j++){
					board[i][j]=in.nextInt();
					numberSet.add(board[i][j]);
				}
			}
			
			boolean pos = true;
			// get all possible number
			ArrayList<Integer> numberList = new ArrayList<Integer>(numberSet);
			for(int idx=0;idx<numberList.size()-1;idx++) {
				int level = numberList.get(idx);
				int nextlevel = numberList.get(idx+1);
				boolean can = true;
				
				int[][] newboard = new int[N][M];
				for(int i=0;i<N;i++){
					for(int j=0;j<M;j++){
						newboard[i][j]=board[i][j];
					}
				}
				
				// try all edge
				for (int i=0;i<N;i++) {
					if (board[i][0] == level) {

						boolean innercan = true;
						// check
						for(int j=0;j<M;j++) {
							if(board[i][j] != level) {
								innercan = false;
								break;
							}
						}
						if (innercan) {
							// restore
							for(int j=0;j<M;j++) {
								newboard[i][j] = nextlevel;
							}
						}
					}
				}
				for (int j=0;j<M;j++) {
					//System.out.println(j+" "+board[0][j]);
					if (board[0][j] == level) {
						// check
						boolean innercan = true;
						//System.out.println(j+" "+innercan+" "+M);
						for(int i=0;i<N;i++) {
							if(board[i][j] != level) {
								innercan = false;
								break;
							}
						}
						//System.out.println(j+" "+innercan+" "+M);
						if (innercan) {					
							 // restore
							for(int i=0;i<N;i++) {
								newboard[i][j] = nextlevel;
							}
						}
					}
				}
				
				/*for(int i=0;i<N;i++){
					for(int j=0;j<M;j++){
						System.out.print(newboard[i][j]+" ");
					} System.out.println();
				}System.out.println();*/
				
				for(int i=0;i<N;i++){
					for(int j=0;j<M;j++){
						if(newboard[i][j]==level) {
							can=false;
							break;
						}
					}
					if (!can) break;
				}
				if (!can) {
					pos = false;
					break;
				} else {
					board = newboard;
				}
			}
			
			
			/*for(int i=0;i<N;i++){
				for(int j=0;j<M;j++){
					if(board[i][j]!=numberList.get(numberList.size()-1)) {
						pos=false;
						break;
					}
				}
				if (!pos) break; 
			}*/
			
			//System.out.println(numberList);
			
			System.out.printf("Case #%d: %s\n", caseNo, pos?"YES":"NO");
		}
	}
}