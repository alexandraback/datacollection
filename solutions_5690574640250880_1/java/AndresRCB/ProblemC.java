package andresrcb.codejam14.qual.solutions;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Scanner;

public class ProblemC {

	public static void main(String[] args) {
		try {
			String fileName;
			String outputName;
			int runType = 2;
			switch(runType) {
			case 0:
				fileName = "/Users/andrescontreras/Development/codeJamIO/qualification/3/C-sample.in";
				outputName = "/Users/andrescontreras/Development/codeJamIO/qualification/3/C-sample.out";
				break;
			case 1:
				fileName = "/Users/andrescontreras/Development/codeJamIO/qualification/3/C-small-attempt0.in";
				outputName = "/Users/andrescontreras/Development/codeJamIO/qualification/3/C-small-attempt0.out";
				break;
			default:
				fileName = "/Users/andrescontreras/Development/codeJamIO/qualification/3/C-large.in";
				outputName = "/Users/andrescontreras/Development/codeJamIO/qualification/3/C-large.out";
			}


			BufferedReader bufferedReader = new BufferedReader(new FileReader(fileName));
			Scanner s = new Scanner(bufferedReader);

			File outputFile = new File(outputName);

			if (!outputFile.exists()) {
				System.out.println(outputFile.getName());
				outputFile.createNewFile();
			}

			FileWriter fw = new FileWriter(outputFile.getAbsoluteFile());
			BufferedWriter bw = new BufferedWriter(fw);


			int cases = s.nextInt();
			int r, c, m, empties;
			boolean first;

			for(int t = 1; t<=cases;++t) {
				bw.write("Case #" + t + ":\n");
				first = true;
				r = s.nextInt();
				c= s.nextInt();
				m= s.nextInt();

				empties = (r*c) - m;

				if(r==1 || c == 1 || empties == 1 || m==0){		
					for(int i =0;i<r;++i) {
						for(int j=0;j<c;++j) {
							if(empties > 0) {
								if(first) {
									bw.write("c");
									first = false;
								}
								else {
									bw.write(".");
								}
								--empties;
							}
							else {
								bw.write("*");
							}
						}
						bw.write("\n");
					}
				}
				else if (r==2 || c==2) {
					if((empties % 2)==0 && empties > 2){
						int emptiesPerRow = empties/r;
						for(int i =0;i<r;++i) {
							for(int j=0;j<c;++j) {
								if(empties > 0 && (j<2 || j<emptiesPerRow)) {
									if(first) {
										bw.write("c");
										first = false;
									}
									else {
										bw.write(".");
									}
									--empties;
								}
								else {
									bw.write("*");
								}
							}
							bw.write("\n");
						}
					}
					else {
						bw.write("Impossible\n");
					}
				}
				else {
					if(empties == 2 ||
							empties == 3 ||
							empties == 5 ||
							empties == 7){
						bw.write("Impossible\n");
					}
					else {
						int emptyGrid = (int)Math.floor(Math.sqrt(empties));
						boolean[][] mines = new boolean[r][c];
						if(emptyGrid >= r) {
							for(int j = 0;j<c; ++j) {
								for (int i = 0; i<r;++i) {
									if(empties > 0 && (r-i > 1 || empties!=2)) {
										mines[i][j] = false;
										--empties;
									}
									else {
										mines[i][j] = true;
									}
								}
							}
						}
						else if (emptyGrid >= c) {
							for(int i = 0;i<r; ++i) {
								for (int j = 0; j<c;++j) {
									if(empties > 0 && (c-j > 1 || empties!=2)) {
										mines[i][j] = false;
										--empties;
									}
									else {
										mines[i][j] = true;
									}
								}
							}
						}
						else {
							for(int i = 0;i<r; ++i) {
								for (int j = 0; j<c;++j) {
									if(i<emptyGrid && j<emptyGrid) {
										mines[i][j] = false;
										--empties;
									}
									else {
										mines[i][j] = true;
									}
								}
							}
							if(empties == 1) {
								mines[emptyGrid-1][emptyGrid-1] = true;
								mines[0][emptyGrid] = false;
								mines[1][emptyGrid] = false;
							}
							else if(empties <= 3){
								for (int i= 0; i<empties;++i) {
									mines[i][emptyGrid] = false;
								}
							}
							else {
								for (int i= 0; i<(empties/2 + empties % 2);++i) {
									mines[i][emptyGrid] = false;
								}
								for (int j= 0; j<(empties/2);++j) {
									mines[emptyGrid][j] = false;
								}
							}
						}
						for(int i =0;i<r;++i) {
							for(int j=0;j<c;++j) {
								if(!mines[i][j]) {
									if(first) {
										bw.write("c");
										first = false;
									}
									else {
										bw.write(".");
									}
								}
								else {
									bw.write("*");
								}
							}
							bw.write("\n");
						}
					}
				}
			}

			s.close();
			bufferedReader.close();

			bw.close();

		} catch (Exception e) {
			e.printStackTrace();
		}
	}

}
