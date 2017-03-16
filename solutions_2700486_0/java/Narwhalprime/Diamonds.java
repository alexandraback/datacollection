import java.io.*;
import java.util.*;
import java.math.*;

public class Diamonds {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("diamonds.in"));
		FileWriter out = new FileWriter(new File("diamonds.out"));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int Z = new Integer(st.nextToken());
		for(int z = 0; z < Z; z++)
		{
			st = new StringTokenizer(br.readLine());
			int N = Integer.parseInt(st.nextToken());
			int X= Integer.parseInt(st.nextToken());
			int Y = Integer.parseInt(st.nextToken());
			double prob = 0.0;
			
			// if my layer is too big, return 0
			// if my layer is too small, return 1
			
			int ind = 1;
			int layerMax = 4*((ind-1)*ind/2) + ind;
			while(layerMax < N)
			{
				ind++;
				layerMax = 4*((ind-1)*ind/2) + ind;
			}
			int layerNum = (ind - 1) * 2;
			if(X+Y > layerNum)
				prob = 0;
			else if(X+Y < layerNum)
				prob = 1;
			else
			{
				int layerSize = layerNum * 2 + 1; // number of spaces in this layer
				ind--;
				int nD = N - (4*((ind-1)*ind/2) + ind); // remaining diamonds left
				if(nD <= Y)
					prob = 0;
				else if((layerSize +1)/2 + Y <= nD)
					prob = 1;
				else if(X == 0 && nD != layerSize)
					prob = 0;
				else
				{
					prob = 0;
					for(int i = 1; i <= nD; i++)
					{
						int product = 1; 
						for(int a = nD-i+1; a <= nD; a++)
							product *= a;
						for(int a = 1; a <= i; a++)
							product /= a;
						prob += product;
					}
					prob *= Math.pow(0.5, nD);
				}
			}
			
			out.write("Case #"+(z+1)+": ");
			out.write("" + prob  + '\n');
		}
		out.close();
	}
}
