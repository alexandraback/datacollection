import java.io.File;
import java.io.FileReader;
import java.io.FileNotFoundException;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

class Main
{
	static File file;
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static Scanner sc = new Scanner(new InputStreamReader(System.in));

	public static void main (String[] args) throws java.lang.Exception {
		int T = Integer.parseInt(br.readLine());
		int[][] matrix = createMatrix();
		for (int i=0; i<T; i++) {
			solve(i, matrix);
		}
	}

	public static int[][] createMatrix() throws IOException{
		int[][] mx = {
			{0,1,2,3,4,5,6,7},
			{1,4,3,6,5,0,7,2},
			{2,7,4,1,6,3,0,5},
			{3,2,5,4,7,6,1,0},
			{4,5,6,7,0,1,2,3},
			{5,0,7,2,1,4,3,6},
			{6,3,0,5,2,7,4,1},
			{7,6,1,0,3,2,5,4}
		};
		return mx;
	}

	public static void solve(int num, int[][] matrix) throws IOException{
		StringTokenizer data = new StringTokenizer(br.readLine(), " ");
		int L = Integer.parseInt(data.nextToken());
		int X = Integer.parseInt(data.nextToken());
		String str = br.readLine();

		int current = 0;
		int total = 0;
		int check = 1;

		for (int k=0; k<X; k++){
			for (int i=0; i<L; i++){
				switch(str.charAt(i)){
					case 'i':
						current = matrix[current][1];
						total = matrix[total][1];
					break;
					case 'j':
						current = matrix[current][2];
						total = matrix[total][2];
					break;
					case 'k':
						current = matrix[current][3];
						total = matrix[total][3];
					break;
					default:
				}

				if (current == check){
					check++;
					current = 0;
				}
			}
		}

		if (check > 3 && total == 4){
			System.out.println("Case #" + (num+1) + ": YES");
		}else{
			System.out.println("Case #" + (num+1) + ": NO");
		}
	}
}
