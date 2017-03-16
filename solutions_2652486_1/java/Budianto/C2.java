import java.util.*;
import java.io.*;
import java.math.*;

public class C2{
	static int N, M, K, R;
	
	static HashSet<Integer> subset;
	static void generateSubset(String tmp, int idx, int cur) {
		if (idx == N) {
			subset.add(cur);
		} else {
			int val = (int)(tmp.charAt(idx)-'0');
			// not take
			generateSubset(tmp, idx+1, cur);
			// take
			generateSubset(tmp, idx+1, cur * val);
			
		}
	}
	
	public static void main(String[] args) throws Exception{
		Scanner in = new Scanner(System.in);
		
		int Tes = in.nextInt();
		
		for(int caseNo=1;caseNo<=Tes;caseNo++){
			R = in.nextInt();
			N = in.nextInt();
			M = in.nextInt();
			K = in.nextInt();
			
			System.out.println("Case #"+caseNo+":");
						
			for (int c=0;c<R;c++) {
				int[] sub = new int[K];
				for(int i=0;i<K;i++)sub[i]=in.nextInt();
				
				// try random, several times
				//for(int randCount = 0; randCount < 10000; randCount++) {
				while(true) {
					String tmp = "";
					for(int i=0;i<N;i++) {
						int num = (int)(Math.random() * (M-1))+2;
						tmp += num;
					}
					
					boolean pos = true;
					subset = new HashSet<Integer>();
					generateSubset(tmp, 0, 1);
					for(int i=0;i<K;i++) {
						if (!subset.contains(sub[i])) {
							pos = false;
							break;
						}
					}
					
					if (pos) {
						System.out.println(tmp);
						break;
					}
				}

			}
		}
	}
}