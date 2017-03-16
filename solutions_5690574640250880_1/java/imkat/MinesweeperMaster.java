import java.io.*;
import java.util.*;
public class MinesweeperMaster {	
    public static void main(String[] args) throws IOException {
        File path = new File("C-large.in");
        Scanner inFile = new Scanner(new FileReader(path));
    	PrintWriter outFile = new PrintWriter ("MinesweeperMaster.out");
        int T = inFile.nextInt();
        for(int i = 1; i <= T; i++){
        	//input
        	int R = inFile.nextInt();
        	int C = inFile.nextInt();
        	int M = inFile.nextInt();
        	//process & output
        	outFile.print("Case #");
        	outFile.print(i);
        	outFile.println(":");
        	int E = R * C - M;
        	if(Math.min(R, C) == 2 && ((E > 1 && E % 2 == 1) || E == 2)){
        		outFile.println("Impossible");
        	} else if(Math.min(R, C) > 2 && (E == 2 || E == 3 || E == 5 || E == 7)){
        		outFile.println("Impossible");
        	} else {
        		char[][] board = new char[R][C];
        		if(R == 1 || C == 1 || E == 1){
        			//simplest cases
        			for(int j = 0; j < R; j++){
            			for(int k = 0; k < C; k++){
            				if(j == 0 && k == 0){
            					board[j][k] = 'c';
            					E--;
            				} else if(E > 0){
            					board[j][k] = '.';
            					E--;
            				} else {
            					board[j][k] = '*';
            				}
            			}
            		}
        		} else {
        			//normal cases
        			//top-left corner 2*2
        			for(int j = 0; j < 2; j++){
            			for(int k = 0; k < 2; k++){
            				if(j == 0 && k == 0){
            					board[j][k] = 'c';
            					E--;
            				} else if(E > 0){
            					board[j][k] = '.';
            					E--;
            				} else {
            					board[j][k] = '*';
            				}
            			}
            		}
        			//top-right corner
        			for(int k = 2; k < C; k++){
        				if(E == 0 || E == 3){
        					board[0][k] = '*';
        					board[1][k] = '*';
        				} else {
        					board[0][k] = '.';
        					board[1][k] = '.';
        					E = E - 2;
        				}
        			}
        			//bottom
        			for(int j = 2; j < R; j++){
        				for(int k = 0; k < C - 1; k++){
            				if(E > 0){
            					board[j][k] = '.';
            					E--;
            				} else {
            					board[j][k] = '*';
            				}
            			}
            			if(E == 1 || E > 2){
            				board[j][C - 1] = '.';
            				E--;
            			} else {
            				board[j][C - 1] = '*';
            			}
            		}
        		}
        		for(int j = 0; j < R; j++){
        			for(int k = 0; k < C; k++){
        				outFile.print(board[j][k]);
        			}
        			outFile.println();
        		}
        	}
        }
        inFile.close();
        outFile.close();
    }
}