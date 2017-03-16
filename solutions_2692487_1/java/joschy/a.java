package a;

import java.io.*;
import java.util.Arrays;

public class a {
	public static void main(String[] args) throws IOException
	{
		FileReader infile = new FileReader("Input.txt");
		BufferedReader fin = new BufferedReader(infile);
		FileWriter outfile = new FileWriter("Output.txt");
		BufferedWriter fout = new BufferedWriter(outfile);
		
		a.start(fin, fout);
	}
	

	private static void start(BufferedReader fin, BufferedWriter fout) throws NumberFormatException, IOException{
		int numCases = Integer.parseInt(fin.readLine());
		for(int i = 0; i < numCases; i++){
			String answer = test(fin);
			System.out.println("Case #" + Integer.toString(i+1)+ ": " + answer);
		}
	}
	
	private static String test(BufferedReader fin) throws IOException{
		String[] str = fin.readLine().split(" ");
		long A = Integer.parseInt(str[0]);
		int N = Integer.parseInt(str[1]);
		String[] str2 = fin.readLine().split(" ");
		int[] motes = new int[N];
		for(int i = 0; i < N; i++)
		{
			motes[i] = Integer.parseInt(str2[i]);
		}
		Arrays.sort(motes);
		return Long.toString(search(0, motes, A, 0));	
	}
	
	private static long search(long counter, int[] motes, long A, int depth)
	{
		if(depth == motes.length)
			return counter;
		if(A > motes[depth])
			return search(counter, motes, A + motes[depth], depth + 1);
		long Acopy = A;
		long temp = counter;
		do
		{
			temp++;
			Acopy = 2*Acopy-1;
		}while(Acopy <= motes[depth] && Acopy != A);
		long first = -1;
		if(Acopy!=A)first = search(temp, motes, Acopy + motes[depth], depth+1);
		long second = search(counter + 1, motes, A, depth+1);
		if(second < first || first == -1)
			return second;
		return first;
	}
}