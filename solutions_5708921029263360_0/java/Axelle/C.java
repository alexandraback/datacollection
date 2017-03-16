import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

public class C {
	
	public static int min;
	
	public static void main(String[] args) throws IOException {
		String dataFile = "./data/C-small-attempt5.in";
		String outFile = "./out/C.out";
		BufferedReader reader = new BufferedReader(new FileReader(dataFile));
		PrintWriter printer = new PrintWriter(outFile, "UTF-8");
		
		String line = reader.readLine();
		
		int nb_problem = Integer.parseInt(line);
		for (int i = 0; i < nb_problem; ++i) {
			line = reader.readLine();
			String[] elements = line.split(" ");
			int[] data = new int[elements.length];
			for (int j = 0; j < elements.length; ++j)
				data[j] = Integer.parseInt(elements[j]);
			
			int[][] res = problemC(data);
			
			printer.println("Case #"+(i+1)+": "+min);
			for (int j = 0; j < res.length; ++j) {
				String str = "";
				for (int k = 0; k < res[j].length; ++k) {
					str += res[j][k]+" ";
				}
				printer.println(str.substring(0, str.length()-1));
			}
		}
		
		reader.close();
		printer.close();
		System.out.println("Done");
	}
	
	public static int[][] problemC(int[] data) {
		min = 0;
		
		int j,p,s,k;
		j = data[0];
		p = data[1];
		s = data[2];
		k = data[3];
		
		int min2 = j * p * s;
		min = j * p;
		
		if (min2 > 1 && min > 1) {
			int m = k < s ? k : s;
			min = min * m;
			int[][] r = new int[min][3];
			int cpt = 0;
			int jj = 1;
			for (int v = 0; v < m; v++) {
				for (int x = 0; x < j; ++x) {
					for (int u = 0; u < p; ++u) {
						r[cpt][0] = jj;
						cpt++;
					}
					jj++;
				}
				jj = 1;
			}
			cpt = 0;
			jj = 1;
			for (int v = 0; v < m; v++) {
				for (int x = 0; x < j; ++x) {
					for (int u = 0; u < p; ++u) {
						r[cpt][1] = jj;
						cpt++;
						jj++;
					}
					jj = 1;
				}
			}
			cpt = 0;
			jj = 1;
			int y = 1;
			for (int v = 0; v < m; v++) {
				jj = y;
				for (int x = 0; x < j; ++x) {
					jj = y;
					for (int u = 0; u < p; ++u) {
						if (jj > s)
							r[cpt][2] = jj % s;
						else 
							r[cpt][2] = jj;
						cpt++;
						jj++;
					}
					
				}
				y++;
			}
			
			return r;
		}
		else if (s > 1) {
			int m = k < s ? k : s;
			min = m;
			int[][] r = new int[m][3];
			int x = 1;
			for (int u = 0; u < m; ++u) {
				r[u][0] = 1;
				r[u][1] = 1;
				r[u][2] = x;
				x++;
				if (x > s)
					x = 1;
			}
			return r;
		}
		else {
			min = 1;
			int[][] r = new int[1][];
			int[] rr = {1,1,1};
			r[0] = rr;
			return r;
		}
		
	}
}

