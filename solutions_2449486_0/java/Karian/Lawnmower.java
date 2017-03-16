import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;


public class Lawnmower {

	/**
	 * @param args
	 * @throws IOException 
	 * @throws NumberFormatException 
	 */
	public static void main(String[] args) throws NumberFormatException, IOException {
		// open file and create a buffered reader
		FileReader input = new FileReader(args[0]);
		BufferedReader buffer = new BufferedReader(input);
		
		//read the number of testcases
		int max = Integer.parseInt(buffer.readLine().trim());
		
		// read a line and call the solving procedure for a single test case.  We expect back the result as a string
		for (int i = 1; i <= max; i++) {
			System.out.println("Case #"+i+": " + solve(buffer));
		}
	}

	private static String solve(BufferedReader buffer) throws IOException {
		String size = buffer.readLine().trim();
		String[] split = size.split(" ");
		int N = Integer.parseInt(split[0]);
		int M = Integer.parseInt(split[1]);
		if(N == 1 || M == 1)
		{
			for(int i = 0; i < N; i++) {
				buffer.readLine();
			}
			return new String("YES");
		}
		int[][] field = new int[N][M];
		for (int i = 0; i < N; i++)
		{
			String[] fieldSplit = buffer.readLine().trim().split(" ");
			for (int j = 0; j < M; j++){
				field[i][j] = Integer.parseInt(fieldSplit[j]);
			}
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++){
				int pivot = field[i][j];
				boolean horizontal = true;
				boolean vertical = true;
				for (int k = 0; horizontal && k < N; k++)
				{
					if (pivot < field[k][j])
						horizontal = false;
				}
				if(!horizontal)
				{
					for (int l = 0; vertical && l < M; l++)
					{
						if(pivot < field[i][l])
						{
							vertical = false;
						}
					}
					if(!vertical)
					{
						return new String("NO");
					}
				}
			}
		}

		return new String("YES");
	}
}
