import java.io.*;
import java.util.*;

public class B {
	
	public static BufferedReader in;
	public static StringTokenizer st;
	
	public static int[] used;
	
	public static void main(String[] args) throws IOException{
		in = new BufferedReader(new FileReader("B.in"));
		PrintWriter out = new PrintWriter(new FileWriter("B.out"));
		
		int test = readInt();
		for (int t=1; t<=test; t++){
			out.print("Case #"+t+": ");
			
			int num = readInt();
			used = new int[num];
			Level[] oneLvls = new Level[num];
			Level[] twoLvls = new Level[num];
			
			for (int i=0; i<num; i++){
				oneLvls[i] = new Level(readInt(), i);
				twoLvls[i] = new Level(readInt(), i);
				
				used[i] = twoLvls[i].starReq;
			}
			
			Arrays.sort(oneLvls);
			Arrays.sort(twoLvls);
			
			boolean[] gotOne = new boolean[num];
			int stars = 0;
			int count = 0;
			int oneInd = 0, twoInd = 0;
			while (stars<2*num){
				if (twoLvls[twoInd].starReq<=stars){
					int level = twoLvls[twoInd].lvl;
					stars++;
					count++;
					if (!gotOne[level]) stars++;
					used[level]=-1;
					twoInd++;
					continue;
				}
				
				if (oneInd>=oneLvls.length) break;
				int level = oneLvls[oneInd].lvl;
				if (used[level]==-1) oneInd++;
				else if(oneLvls[oneInd].starReq<=stars){
					stars++;
					gotOne[level] = true;
					count++;
					oneInd++;
				}
				else break;
			}
			
			if (stars<2*num) out.println("Too Bad");
			else out.println(count);
		}
		
		in.close();
		out.close();
	}
	
	public static String readLine() throws IOException{
		return in.readLine();
	}
	
	public static String readToken() throws IOException{
		if (st==null || !st.hasMoreTokens())
			st = new StringTokenizer(readLine());
		return st.nextToken();
	}
	
	public static int readInt() throws IOException{
		return Integer.parseInt(readToken());
	}
}

class Level implements Comparable<Level>{
	int starReq;
	int lvl;
	
	public Level(int s, int l){
		starReq = s;
		lvl = l;
	}
	
	public int compareTo(Level other){
		if (starReq==other.starReq)
			return - B.used[lvl] + B.used[other.lvl];
		return starReq-other.starReq;
	}
}
