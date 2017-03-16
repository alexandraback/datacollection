import java.io.*;
import java.util.*;

public class Main{

	public static void main(String [] args) throws IOException{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(in.readLine());
		
		for (int tc = 0; tc < t; tc++){
			String [] line = in.readLine().split(" ");
			int a = Integer.parseInt(line[0]);
			int n = Integer.parseInt(line[1]);
			int [] motes = new int[n];
			
			if (a == 1){
				in.readLine();
				System.out.println("Case #" + (tc+1) + ": " + n);
				continue;
			}
			
			
			line = in.readLine().split(" ");
			for (int midx = 0; midx < n; midx++)
				motes[midx] = Integer.parseInt(line[midx]);
			Arrays.sort(motes);
			
			ArrayList<Integer> reach = new ArrayList<Integer>();
			int i = 0;
			while ((i < motes.length) || (a <= motes[motes.length-1])){
				if (a > motes[i]){
					a += motes[i];
					i++;
				}
				else{
					reach.add(a);
					a += a-1;
				}
			}
			reach.add(a);
			
			int min = Integer.MAX_VALUE;
			int j = reach.size()-1;
			for (int removed = 0; removed < motes.length; removed++){
				while ((j > 0) && (reach.get(j-1) > motes[motes.length-removed-1]))
					j--;
					
				int total = j+removed;
				if (total < min)
					min = total;
			}
			
			if (min > motes.length)
				min = motes.length;
			
			System.out.println("Case #" + (tc+1) + ": " + min);
		}
	}

}