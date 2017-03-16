import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;


public class qt2 {
	public static void test(BufferedReader in) throws IOException {
		int cases = Integer.parseInt(in.readLine());
		for (int j = 1;j<=cases;j++) {
			System.out.print("Case #"+j+": ");
			String nm = in.readLine();
			String tokens[] = nm.split(" ");
			int n = Integer.parseInt(tokens[0]);
			int m = Integer.parseInt(tokens[1]);
			int[][] matrix = new int [n][m]; 
			boolean[][][] matrix2 = new boolean [101][n][m]; 
			boolean[] hasHeight = new boolean[101];
						
			int max = -1;
			for (int x = 0;x < n;x++) {
				String h = in.readLine();
				String to[] = h.split(" ");
				for (int y = 0;y < m;y++) {
					int height = Integer.parseInt(to[y]);
					hasHeight[height] = true;
					if (max<height) {
						max = height;
					}
					matrix[x][y]= height;
					for (int z = 1;z < 101;z++) {
						if (z<height) {
							matrix2[z][x][y] = false;
						}
						else {
							matrix2[z][x][y] = true;
						}
					}
				}
			}
			boolean canDo = true;
			for (int z = 1;z < max;z++) {
				for (int x = 0; x < n;x++) {
					for (int y = 0; y< m;y++) {
						if (matrix2[z][x][y]) {
							boolean flag = true;
							for (int i = 0;i < n;i++) {
								if (!matrix2[z][i][y]) {
									flag = false;
									break;
								}
							}
							if (!flag) {
								for (int i = 0;i < m;i++) {
									if (!matrix2[z][x][i]) {
										flag = true;
										break;
									}
								}
								if (flag) {
									canDo = false;
									break;
								}
							}		
						}
					}
					if (!canDo) {
						break;
					}
				}
				if (!canDo) {
					break;
				}
			}
			if (canDo) {
				System.out.println("YES");
			}
			else {
				System.out.println("NO");
			}		
		}	
		in.close();
	}
	
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		File conf = new File(args[0]);
		FileReader fr=new FileReader(conf);
		BufferedReader in=new BufferedReader(fr);
		test(in);
	}
}
