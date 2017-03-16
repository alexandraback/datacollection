/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package codejam;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class CodeJam {
	final static String PROBLEM_NAME = "Lawnmower";
    final static String WORK_DIR = "D:\\CodeJam\\" + PROBLEM_NAME + "\\";
	
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(new FileReader(WORK_DIR + "B-small-attempt0.in"));
		PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "output.txt"));
		int x,y;
		int[][] map;
		String ansStr;
		String[] splitBuf;
		
		int caseCnt = sc.nextInt();
		
		for (int caseNum = 1; caseNum <= caseCnt; caseNum++) {
			x = sc.nextInt();
			y = sc.nextInt();
			map = new int[x][y];
			sc.nextLine();
			for(int i=0;i<x;i++){
				splitBuf = sc.nextLine().split(" ");
				for(int j=0;j<y;j++){
					map[i][j] = Integer.valueOf(splitBuf[j]);
				}
			}
			ansStr = "YES";
			
			for(int i=0;i<map.length;i++){
				for(int j=0;j<map[i].length;j++){
					//System.out.print(map[i][j]+" ");
					if(!canMow(map, i, j, map[i][j])){
						ansStr = "NO";
						break;
					}
				}
				//System.out.println("");
			}
			
			//ansStr = "";
			ansStr = "Case #"+caseNum+": "+ansStr;
			System.out.println( ansStr );
			pw.println( ansStr );
		}
		pw.flush();
		pw.close();
		sc.close();
	}
	
	public static boolean canMow(int[][] map, int x, int y, int h){
		boolean vertical = true, horizon = true;
		for(int i = 0;i<map.length;i++){
			if( map[i][y]>h ){
				vertical = false;
				break;
			}
		}
		for(int i = 0;i<map[x].length;i++){
			if( map[x][i]>h ){
				horizon = false;
				break;
			}
		}
		
		return vertical || horizon;
	}
	
}