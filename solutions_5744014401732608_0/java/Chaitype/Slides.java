
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

public class Slides {

	static PrintWriter writer;
	
	static String output = "";
	
	public static int bmf(int matrix[][], int dis) {
		int [][] aaa = new int[dis + 1][ dis + 1];
		for(int q = 0; q <= dis ; ++q) {
			for(int w = 0; w <= dis ; ++w) {
				aaa[q][w] = matrix[q][w];
			}
		}
		
		for(int q = 0; q < dis; ++q) {
			for(int w = 0; w  < dis; ++w) {
				for(int e = 0; e  <= dis; ++e) {
					aaa[w][e] = matrix[w][e];
					for(int r = 0; r  < dis; ++r) {
						aaa[w][e] += (aaa[w][r] * matrix[r][e]); 
					}
				}
			}
		}
		//System.out.println(aaa[0][dis]);
		
		//for(int q = 0; q <= dis ; ++q) {
		//	for(int w = 0; w <= dis ; ++w) {
		//		System.out.print(aaa[q][w]);
		//	}
		//	System.out.println("");
		//}
		
		return aaa[0][dis];
	}
	
	public static boolean recure(int B, int M, int matrix[][], int index) {
		if(index == B - 1) {
			int num = bmf(matrix, B - 1);
			if(num == M) {
				output = "";
				for(int q = 0; q < B; ++q) {
					for(int w = 0; w < B; ++w) {
						output += matrix[q][w] +"";
					}
					if(q < B - 1) {
						output += "\n";
					}
				}
				return true;
			}
			return false;
		}
		else {
			for(int q = index + 1; q < B; ++q) {
				matrix[index][q] = 0;
			}
			while(true) {
				int q;
				for(q = index + 1; q < B; ++q) {
					if(matrix[index][q] == 0) {
						matrix[index][q] = 1;
						for(int w = q - 1; w > index; --w) {
							matrix[index][w] = 0;	
						}
						break;
					}
				}
				if(q == B) {
					return false;
				}
				else {
					if(recure(B, M, matrix, index + 1) == true) {
						return true;
					}
				}
			}
		}
	}
	
	public static boolean gen(int B, int M) {
		
		int aaa[][] = new int[10][10];
		for(int q = 0; q <= B ; ++q) {
			for(int w = 0; w <= B ; ++w) {
				aaa[q][w] = 0;
			}
		}
		if(recure(B, M, aaa, 0)) {
			return true;
		}
		return false;
	}
	
	public static void main(String[] args) throws IOException {
		
		writer = new PrintWriter("aout.txt");
		BufferedReader br = null;
		try {
			br = new BufferedReader(new FileReader("B-small-attempt0 (1).in"));
			String line = br.readLine();
		    int Num = Integer.parseInt(line);
		    for(int i = 0; i < Num; ++i) {
		    	line = br.readLine();
		    	String bufs[] = line.split(" ");
		    	int B = Integer.parseInt(bufs[0]);
		    	int M = Integer.parseInt(bufs[1]);		    	
		    	
		    	if(gen(B,M)) {
			    	writer.println("Case #" + (i + 1) + ": " + "POSSIBLE");
			    	writer.println(output);
		    	}
		    	else {
			    	writer.println("Case #" + (i + 1) + ": " + "IMPOSSIBLE");
		    	}
		    }
		} finally {
		    br.close();
			writer.close();
		}
	}
	
}

