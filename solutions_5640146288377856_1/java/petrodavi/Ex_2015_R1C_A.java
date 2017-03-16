package com.petrodavi.exercises.R123;

import java.util.List;
import java.util.StringTokenizer;

import com.petrodavi.utils.ReadDataFromFile;


public class Ex_2015_R1C_A {

	private static int solve(int R, int C, int W){
		//System.out.println("R "+R+" - C "+C+" - W "+W+"");
		int time = 0;
		
		if (C % W != 0) {
			time++;
		}
		
		int first = (int)(C / W);
		
		time += first + W - 1;
		
		return time;
	}
	
	public static void main(String[] args) throws Throwable {

		List<String> mList = null;

		try {
			mList = ReadDataFromFile.readStringsArraysFromFile(
					"Ex/R123/Ex_2015_R1C_A_B.in");
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}

		String outString = "";
		int numrow=0;
		int T = Integer.parseInt(mList.get(numrow++));
		int t=1;

		while ( t<=T ) {

			StringTokenizer strTkn = new  StringTokenizer(mList.get(numrow++));
			int R = Integer.parseInt(strTkn.nextToken());
			int C = Integer.parseInt(strTkn.nextToken());
			int W = Integer.parseInt(strTkn.nextToken());

			int first_res = (int)(C / W);
			int res_row = first_res * (R-1);
			
			int solve = solve(R, C, W);

			String m_outString=String.format("Case #%d: %d", t++, solve+res_row);
			m_outString+=String.format("\n");
			System.out.println("R "+R+" - C "+C+" - W "+W+"");
			System.out.print(m_outString);
			outString+=m_outString;

		}


		try {
			ReadDataFromFile.writeToFile("Sol/"+"solution.txt", outString);
		} catch (Exception e) {
			e.printStackTrace();
		}

	}

}
