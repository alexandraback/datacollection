package com.sokamura.gcj2012;

import java.io.BufferedReader;
import java.io.FileReader;

public class KingdomRush {

	private String solve(int n, int[][] game) {
		int playNum = 0;
		int star = 0;
		boolean[][] clear = new boolean[n][2];
		while(true) {
			boolean flag1 = false;
			for(int i=0; i<n; ++i){
				if(!clear[i][1] && star >= game[i][1]) {
					playNum++;
					if(clear[i][0]){ star++; }
					else{ star+=2; }
					clear[i][1] = true;
					flag1 = true;
				}
			}
			// finish?
			boolean flag2 = true;
			for(int i=0; i<n; ++i) {
				if(!clear[i][1]) {
					flag2 = false;
					break;
				}
			}
			// finish
			if(flag2) { return Integer.toString(playNum); }
			if(flag1) { continue; }
			// play 1-star
			boolean flag3 = false;
			for(int i=0; i<n; ++i) {
				if(!clear[i][1] && !clear[i][0] && star >= game[i][0]) {
					playNum++;
					star++;
					clear[i][0] = true;
					flag3 = true;
					break;
				}
			}
			// cannot solve
			if(!flag3){ return new String("Too Bad"); }
		}
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ
		KingdomRush kr = new KingdomRush();
		try {
			FileReader fr = new FileReader("B-small-attempt0.in");
			BufferedReader br = new BufferedReader(fr);
			int lineNum = Integer.parseInt(br.readLine());
			for(int i=1; i<=lineNum; ++i) {
				String tmpLine = br.readLine();
				int n = Integer.parseInt(tmpLine);
				int[][] game = new int[n][2];
				for(int j=0; j<n; ++j) {
					tmpLine = br.readLine();
					String[] array = tmpLine.split(" ");
					game[j][0] = Integer.parseInt(array[0]);
					game[j][1] = Integer.parseInt(array[1]);
				}
				String ans = kr.solve(n, game);
				System.out.println("Case #" + i + ": " + ans);
			}
		}
		catch(Exception e) {
			e.printStackTrace();
		}
	}

}
