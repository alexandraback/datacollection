package GoogleCodeJamRound2;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Problem_C {
	public static int [] c = new int[1000];
	public static int count(int C, int D, int V){
		int  [] A = new int[1000];
		int sum = 0;
		int count = 0;
		
		
		for (int j=1; j<=V; j++)
		{
			A[j] = 0;
		}
		A[0] = 1;
		int inc_i=0;
		while (count == 0)
		{
			for (; inc_i<D; inc_i++)
			{	
				int x= c[inc_i];
				for (int j=V; j>=0; j--)
				{
					if (A[j] == 1 && j+x<=V)
					{ 
						A[j+x] = 1;
						System.out.print(j+x+" ");
					}
				}
			}
			count = 1;
			for (int i=0; i<=V; i++)
			{
				if (A[i] == 0)
				{
					c[D++] = i;
					count = 0;
					sum++;
					break;
				}
			}
		}
		System.out.println("");
		
		
		return sum;
	}
	
	
	
	
	public static void main(String[] args) {
		//String inFile = "//Users//lixuefei//Documents//JavaWorkspace//Interview//src//GoogleCodeJamRound2//in.txt";
		String inFile = "//Users//lixuefei//Documents//JavaWorkspace//Interview//src//GoogleCodeJamRound2//C-small-attempt0.in";
		String outFile = "//Users//lixuefei//Documents//JavaWorkspace//Interview//src//GoogleCodeJamRound2//result.txt";
		int n = 0;
		String line;
		try {
			FileReader fileReader = new FileReader(inFile);
			BufferedReader br = new BufferedReader(fileReader);
			FileWriter fileWriter = new FileWriter(outFile);
			BufferedWriter bw = new BufferedWriter(fileWriter);
			line = br.readLine();
			n = Integer.parseInt(line);
			for(int i = 0; i < n ; i++){
				line = br.readLine();
				
				String[] parts = line.split(" ");
				int C = Integer.parseInt(parts[0]);
				int D =  Integer.parseInt(parts[1]);
				int V =  Integer.parseInt(parts[2]);
				
				
				
				line = br.readLine();
				String[] part = line.split(" ");
				
				for (int j = 0; j < D; j++) {
					c[j] = Integer.parseInt(part[j]);
				}
				
				
				int result = count(C, D, V);
				bw.write("Case #" + (i+1) + ": " + result + "\n");
				
			}
			br.close();
			bw.close();
		} catch (IOException ex) {
			ex.printStackTrace();
		}

	}
}

