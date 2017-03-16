import java.io.*;
import java.util.*;


public class Main2{
	
	
	private static int maxIndex(List<Integer> p){
		int count = p.size();
		int m = -1;
		int ri = -1;
		for (int i = 0; i < count; ++i){
			if (p.get(i) > m){
				m = p.get(i);
				ri = i;
			}
		}
		return ri;
	}
	
	
	private static int calc(List<Integer> p){
		int maxIndex = maxIndex(p);
		int max = p.get(maxIndex);
		if (max == 1)
			return 1;
		
		int size = p.size();
		
		int ifSplit = Integer.MAX_VALUE;
		if (max >= 4){
			for (int j = 2; j <= max/2; j++){
				p.set(maxIndex, j);
				p.add(max - j);
				int ifSplitThis = 1+calc(p);
				if (ifSplitThis < ifSplit)
					ifSplit = ifSplitThis;
				p.set(maxIndex, max);
				p.remove(p.size()-1);
			}
		}
		
//		ArrayList<Integer> copy = new ArrayList<>(p);
//		for (int i = 0; i < size; ++i){
//			int val = copy.get(i);
//			if (val > 0)
//				copy.set(i, val-1);
//		}
//		int ifNotSplit = 1+calc(copy);
		
		return Math.min(max, ifSplit);
	}
	
	
	
	public static void main(String[] args) throws IOException{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int tCount = Integer.parseInt(in.readLine());
		for (int t = 1; t <= tCount; ++t){
			int d = Integer.parseInt(in.readLine());
			String ps = in.readLine();
			List<Integer> p = new ArrayList<>();
			int si = 0;
			for (int i = 0; i < d; ++i){
				si = ps.indexOf(" ", si);
				if (si == -1)
					si = ps.length();
				p.add(Integer.parseInt(ps.substring(0, si)));
				if (i < d-1)
					ps = ps.substring(si+1);
			}
			
			System.out.printf("Case #%d: %d\n", t, calc(p));
		}
		
	}
	
}