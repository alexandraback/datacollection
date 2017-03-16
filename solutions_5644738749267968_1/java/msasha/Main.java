import java.io.*;
import java.util.*;


public class Main{
	
	
	private static int honestWar(Integer[] blocks){
		int counter = 0;
		int ken = 0;
		
		for (int i = 0; i < blocks.length; ++i){
			if (blocks[i] < 0)
				counter++;
			else if (counter > 0){
				counter--;
				ken++;
			}
		}
		return blocks.length/2 - ken;
	}
	
	private static int deceitfulWar(Integer[] blocks){
		int counter = 0;
		int naomi = 0;
		
		for (int i = blocks.length-1; i >= 0; --i){
			if (blocks[i] < 0)
				counter++;
			else if (counter > 0){
				counter--;
				naomi++;
			}
		}
		return naomi;
	}
	
	public static void main(String[] args) throws IOException{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		
		int t = Integer.parseInt(in.readLine());
		for (int tn = 1; tn <= t; ++tn){
			int n = Integer.parseInt(in.readLine());
			
			Integer[] blocks = new Integer[2*n];
			
			String[] parts;
			
			parts = in.readLine().split(" ");
			for (int i = 0; i < n; ++i){
				StringBuilder sb = new StringBuilder(parts[i].substring(2));
				while (sb.length() < 5)
					sb.append('0');
				blocks[i] = Integer.parseInt(sb.toString());
			}
			
			parts = in.readLine().split(" ");
			for (int i = 0; i < n; ++i){
				StringBuilder sb = new StringBuilder(parts[i].substring(2));
				while (sb.length() < 5)
					sb.append('0');
				blocks[n+i] = -Integer.parseInt(sb.toString());
			}
			
			Arrays.sort(blocks, new Comparator<Integer>(){
				public int compare(Integer i1, Integer i2){
					int a1 = Math.abs(i1);
					int a2 = Math.abs(i2);
					
					if (a1 < a2)
						return 1;
					else if (a1 == a2)
						return 0;
					else 
						return -1;
				}
			});
			
			int dw = deceitfulWar(blocks);
			int hw = honestWar(blocks);			
			
			System.out.printf("Case #%d: %d %d\n", tn, dw, hw);
		}
		
			
	}	
	
}