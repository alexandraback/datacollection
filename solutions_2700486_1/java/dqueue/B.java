import java.util.*;
import java.io.*;

public class B
{

    public static double binomial(int N, int k, double p) {
        double[][] b = new double[N+1][k+1];

        // base cases
        for (int i = 0; i <= N; i++)
            b[i][0] = Math.pow(1.0 - p, i);
        b[0][0] = 1.0;

        // recursive formula
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= k; j++) {
                b[i][j] = p * b[i-1][j-1] + (1.0 - p) *b[i-1][j];
            }
        }
        
        double sum = 0;
        for (int i = 0; i < k; i++)
        	sum += b[N][i];
        return sum;
    }

	
	public static void main(String[] args) throws Exception 
	{
		File infile = new File("C:\\Users\\dq\\workspace\\CJ1B\\src\\B-large.in");
		File outfile = new File("C:\\Users\\dq\\workspace\\CJ1B\\src\\B-output.txt");
		BufferedReader br = new BufferedReader(new FileReader(infile));
		BufferedWriter bw = new BufferedWriter(new FileWriter(outfile));
		String s;
		String[] splits;
		int cases = Integer.parseInt(br.readLine());
		for(int i = 0; i < cases; i++)
		{
			bw.write("Case #" + (i+1) + ": ");
			s = br.readLine();
			splits = s.split(" ");
			int N = Integer.parseInt(splits[0]);
			int X = Integer.parseInt(splits[1]);
			int Y = Integer.parseInt(splits[2]);
			X = X > 0 ? X : -X;
			
			int count;
			for(count = 0; count < N; count++)
				if((2 * count + 3)*(2 * count + 4)/2 >= N)
					break;
			
			
			int remainder = N - (2 * count + 1)*(2 * count + 2) / 2;
			int layer = (X + Y) / 2;
			
			
			//WRITE ANSWER HERE
			if((X - Y) % 2 != 0 || layer > count + 1)
				bw.write("0.0");
			else if(layer <= count || remainder > layer * 2 + Y)
				bw.write("1.0");
			else if(Y >= remainder || X == 0)
				bw.write("0.0");
			else
			{
				double odds = binomial(remainder, remainder - Y, .5);
				bw.write("" + binomial(remainder, remainder - Y, .5));
			}
			if((i + 1) < cases)
			{
				bw.write("\n");
			}
		}
		bw.flush();
	}

}
