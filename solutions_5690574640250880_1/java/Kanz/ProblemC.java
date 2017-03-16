package googleJam;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.Scanner;

public class ProblemC {
	public static void main(String[] args){
		String filename = "src/input.txt";
		String output = "src/output.txt";
		String answer = "";
		
		try {
			Scanner scan = new Scanner(new File(filename));
			int a = scan.nextInt();
			for(int i = 0; i < a; i++){
				int r = scan.nextInt();
				int c = scan.nextInt();
				int m = scan.nextInt();
				String[][] board;
				String boardOutput = "";
				boolean fail;
				Collection<Integer> fails = new ArrayList<Integer>();
				fails.add(0); fails.add(2); fails.add(3); fails.add(5); fails.add(7);
				if(r == 1 || c == 1){
					fail = (m >= r*c);
				}else if (r == 2 || c == 2){
					int temp = ((r*c) - m);
					fail = (temp%2 == 1 || fails.contains(temp)) && temp != 1;
					
				}else{
					fail = fails.contains(r*c - m);
				}
				
				if(!fail){
					board = new String[r][c];
					int newr = r;
					int newc = c;
					System.out.println((i+1) + ": " + newr + " " + newc +" :: " + m);
					while (newr >= 1 || newc >= 1){
						if (newr <= newc){
							for(int j = 0; j < newr; j++){
								//System.out.println((r-newr+j) + " :: " + (c-newc));
								//System.out.println(m + "-" + j + "--" + (newr-2));
								if(m > 0 && !(m == 1 && j == newr-2 && newr > 2)){
									board[r-newr + j][c-newc] = "*";
									m--;
									if (j>0){
										if (board[r-newr + j-1][c-newc].equals(".")){
											board[r-newr + j][c-newc] = ".";
											m++;
										}
									}
								}else{
									board[r-newr + j][c-newc] = ".";
								}
							}
							newc--;
						}else{
							for(int j = 0; j < newc; j++){
								//System.out.println((r-newr) + " :: " + (c-newc + j));
								//System.out.println(m + "-" + j + "--" + (newc-2));
								if(m > 0 && !(m == 1 && j == newc-2 && newc > 2)){
									board[r-newr][c-newc + j] = "*";
									m--;
									if (j>0){
										if (board[r-newr][c-newc + j-1].equals(".")){
											board[r-newr][c-newc + j] = ".";
											m++;
										}
									}
								}else{
									board[r-newr][c-newc + j] = ".";
								}
							}
							newr--;
						}
					}
					board[r-1][c-1] = "c";
					for(int j = 0; j < r; j++){
						for(int k = 0; k < c; k++){
							boardOutput += board[j][k];
						}
						boardOutput += "\n";
					}
				}
				
				answer += "Case #" + (i+1) + ":\n";
				if (fail){
					answer += "Impossible\n";
				}else{
					answer += boardOutput;
				}
			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		
		try {
			PrintWriter writer = new PrintWriter(new File(output));
			writer.print(answer);
			writer.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		
	}
}
