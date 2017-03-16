
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;



public class DancingWithTheGooglers {

	public static void main(String[] args) throws IOException 
	{
		//BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream("B-small-attempt3.in")));
		BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream("B-large.in")));
		//BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter out = new BufferedWriter(new FileWriter("DancingWithTheGooglers.txt"));
		int cases = Integer.parseInt(reader.readLine());

		for(int i=1; i <= cases; i++)
		{

			String line = reader.readLine();
			//out.write(line+"\n");
			String[] l = line.split(" ");
			int n = Integer.parseInt(l[0]);
			int s = Integer.parseInt(l[1]);
			int p = Integer.parseInt(l[2]);
			int[] t = new int[n];

			for(int j = 0; j < n; j++) t[j] = Integer.parseInt(l[j+3]);
			Arrays.sort(t);
			//out.write(Arrays.toString(t)+"\n");
			int count = 0;
			for(int j = n-1; j >=0 ; j--) 
				if(p==0) count++;
				else if(p==1)
				{
					if(t[j] >= 1) count++;
					else break;
				}else
				{
					if(t[j] >= p*3-2)
						count++;
					else if (t[j] >= p*3-4 && s>0) {
						s--;
						count++;	
					}
					else break;
				}


			//out.write((p*3-2) + " " + (p*3-4) + "\n");
			System.out.print("Case #" + i+ ": " + count+"\n");
			out.write("Case #" + i+ ": " + count+"\n");
		}
		out.close();

	}
}