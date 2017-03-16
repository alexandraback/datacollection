import java.io.*;
import java.util.*;

public class Osmos {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("osmos.in"));
		FileWriter out = new FileWriter(new File("osmos.out"));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int Z = new Integer(st.nextToken());
		for(int z = 0; z < Z; z++)
		{
			st = new StringTokenizer(br.readLine());
			int currSize = Integer.parseInt(st.nextToken());
			int N = Integer.parseInt(st.nextToken());
			int oldSize = currSize;
			
			int[] sizesArr = new int[N];
			st = new StringTokenizer(br.readLine());
			for(int i = 0; i < sizesArr.length; i++)
				sizesArr[i] = Integer.parseInt(st.nextToken());
			Arrays.sort(sizesArr);
			//LinkedList<Integer> motes = new LinkedList<Integer>();
			//for(int i = 0; i < sizesArr.length; i++)
			//	motes.add(sizesArr[i]);
			
			int motesChanged = 0;
			int[] tS = new int[N];
			int[] nA = new int[N];
			
			for(int i = 0; i < N; i++)
			{
				while(currSize <= sizesArr[i] && motesChanged <= 999)
				{
					currSize = currSize * 2 - 1;
					motesChanged++;
				}
				tS[i] = sizesArr[i] + currSize;
				currSize = tS[i];
				nA[i] = motesChanged;
			}

			int[] nAaD = new int[N+1];
			for(int i = 0; i < N; i++)
			{
				nAaD[i] = nA[i] + N - i - 1;
			}
			nAaD[N] = N;
			Arrays.sort(nAaD);
			out.write("Case #"+(z+1)+": ");
			out.write("" + nAaD[0] + '\n');
		}
		out.close();
	}
}
