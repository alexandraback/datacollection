import java.io.*;
import java.util.*;

public class C {
	public static BufferedReader in;
	public static StringTokenizer st;
	
	public static final int MAX = 100000;
	
	public static void main(String[] args) throws IOException{
		in = new BufferedReader(new FileReader("C.in"));
		PrintWriter out = new PrintWriter(new FileWriter("C.out"));
		
		int test = readInt();
		for (int t=1; t<=test; t++){
			out.println("Case #"+t+": ");
			
			int num = readInt();
			
			int[] sums = new int[2*MAX*num+2];
			Arrays.fill(sums, -2);
			int offset = MAX*num+1;
			
			sums[offset] = -1;
			boolean flag = false;
			ArrayList<Integer> minus = new ArrayList<Integer>();
			ArrayList<Integer> plus = new ArrayList<Integer>();
			for (int i=0; i<num; i++){
				int curr = readInt();
				if (flag) continue;
				
				if (sums[curr+offset]!=-2){
					minus.add(curr);
					
					int x = curr+offset;
					while (sums[x]!=-1){
						if (sums[x]<0) minus.add(-sums[x]);
						else plus.add(sums[x]);
						x -= sums[x];
					}
					flag = true;
				}
				
				for (int j=sums.length-1; j>=curr; j--){
					if (sums[j-curr]!=-2 && sums[j]==-2)
						sums[j] = curr;
				}
				for (int j=0; j<sums.length-curr; j++){
					if (sums[j+curr]!=-2 && sums[j]==-2)
						sums[j] = -curr;
				}
			}
			
			if(!flag) out.println("Impossible");
			else{
				for (int i:plus)
					out.print(i+" ");
				out.println();
				for (int i:minus)
					out.print(i+" ");
				out.println();
			}
			
		}
		
		out.close();
		in.close();
	}
	
	public static String readLine() throws IOException{
		return in.readLine();
	}
	
	public static String readToken() throws IOException{
		while (st==null || !st.hasMoreTokens())
			st = new StringTokenizer(readLine());
		return st.nextToken();
	}
	
	public static int readInt() throws IOException{
		return Integer.parseInt(readToken());
	}
}
