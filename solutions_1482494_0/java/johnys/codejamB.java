package ulohy;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class codejamB {
	
	static int Nconst = 1000;
	static String Task = "B";
	static int nStars;
	static int nComplete;
	
	static byte cases;
	static int[] result = new int[Nconst];
	
	static int[] nr_levels = new int[Nconst];
	
	static int[][] levels = new int[Nconst*100][4];
	
	static int[][] max = new int[Nconst][Nconst];
	static int[][] supr_max = new int[Nconst][Nconst];
	static int[] treshold = new int[Nconst];

	
	public static void read_input() {
		
		Scanner s = null;
		try {
			//s = new Scanner(new FileReader("./src/ulohy/"+Task+"-large.in"));
			s = new Scanner(new FileReader("./src/ulohy/"+Task+"-small-attempt0.in"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}		
		cases = s.nextByte();		
		//System.out.println("Cases: " + cases);
		for (int i = 0; i < cases; i++) {
			nr_levels[i] = s.nextInt();			
			//System.out.println("Prvy parameter: " + nr_levels[i]);
			
			for (int j = 0; j < nr_levels[i]; j++) {								
				levels[j+(i*Nconst)][0] = s.nextInt();
				//System.out.print(levels[j+(i*Nconst)][0]);
			
				levels[j+(i*Nconst)][1] = s.nextInt();
				//System.out.println(" " + levels[j+(i*Nconst)][1]);				
			}
		}

		s.close();	
	}
	
	public static void write_output() {
		FileWriter outFile;
		try {
			outFile = new FileWriter("./src/ulohy/"+Task+"-output");
			PrintWriter out = new PrintWriter(outFile);
			for (int i = 1; i <= cases; i++) {
				//out.println("Case #"+i+": "+result[i-1]);
				if (result[i-1] != 9999999) {
					out.println("Case #"+i+": "+result[i-1]);
				} else {
					out.println("Case #"+i+": "+"Too Bad");
				}
			}
			out.close();
			System.out.println("done");
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	public static void bubbleSort(int nCase) {
		
	    for (int pass=1; pass < nr_levels[nCase]; pass++) {  // count how many times
	        // This next loop becomes shorter and shorter
	        for (int i=nCase*Nconst; i < nCase*Nconst+nr_levels[nCase]-pass; i++) {
	            if (levels[i][1] > levels[i+1][1]) {
	                // exchange elements
	                int temp = levels[i][1];  levels[i][1] = levels[i+1][1]; levels[i+1][1] = temp;
	                temp = levels[i][0];  levels[i][0] = levels[i+1][0]; levels[i+1][0] = temp;
	            }
	        }
	    }
	}
	
	public static void main(String args[]) {
		
		read_input();
		
		for (int i = 0; i < cases; i++) {
			bubbleSort(i);
			nComplete = 0;
			nStars = 0;
			while (nComplete != nr_levels[i]){
				if (find2star(i)) {
					result[i]++;
				} else {
					if (find1star(i)) {
						result[i]++;
					} else {
						result[i] = 9999999;
						break;
					}
				}			
			}
		}

		write_output();		
	}

	private static boolean find1star(int nCase) {
		for (int i=nCase*Nconst+nr_levels[nCase]-1; i >= nCase*Nconst; i--) {
			if (levels[i][1] <= nStars && levels[i][2] == 1 && levels[i][3] == 0) {
				levels[i][3] = 1;
				nStars++;
				nComplete++;
				return true;
			}
		}
		for (int i=nCase*Nconst+nr_levels[nCase]-1; i >= nCase*Nconst; i--) {
			if (levels[i][0] <= nStars && levels[i][2] == 0 && levels[i][3] == 0) {
				levels[i][2] = 1;
				nStars++;
				return true;
			}
		}		
		return false;
		
	}

	private static boolean find2star(int nCase) {
		
		for (int i=nCase*Nconst+nr_levels[nCase]-1; i >= nCase*Nconst; i--) {
			if (levels[i][1] <= nStars && levels[i][2] == 0 && levels[i][3] == 0) {
				levels[i][3] = 1;
				nStars = nStars+2;
				nComplete++;
				return true;
			}
		}
		return false;
	}

}