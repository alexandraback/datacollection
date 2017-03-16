import java.util.Arrays;


public class EqualSums {
	
	public long[][] getAns(int n, int[] arr) {
		
		long[][] sums = new long[Math.pow(2, 20)][n+1];
		long[][] ans = new long[2][n];
		for(int i = 0; i < 2*n+1; i++) {
			
			Arrays.fill(sums[i], 0);
			
		}
		sums[0][0] = arr[0];
		sums[0][1] = arr[0];
		
		for(int i = 1; i < n; i++) {
			
			int ilen = 2*(i-1) + 1;
			for(int j = 0; j < i; j++) {
				
				int jlen = 0;
				for(int m = 1; sums[j][m] != 0; m++,jlen++);
				if(arr[i] == sums[j][0]) {
					
					for(int i1 = 1; i1 < jlen; i1++) {
						
						ans[0][i1-1] = sums[j][i1];
						
					}
					ans[1][0] = arr[i];
					
				} 
				else {
					
					long sum = arr[i] + sums[j][0];
					for(int k = 0; k < i; k++) {
						
						if(k != j && sum == sums[k][0]) {
							
							int i1,i2;
							for(i1 = 1; i1 < jlen; i1++) {
								
								ans[0][i1-1] = sums[j][i1];
								
							}
							ans[0][i1-1] = arr[i];
							for(i2 = 1; i2 < sums[k].length; i2++) {
								
								ans[1][i2-1] = sums[k][i2];
								
							}
							
							
							
						}
						
					}
					
				}
				
				sums[ilen][0] = arr[i];
				sums[ilen][1] = arr[i];
				for(int m = 1; m <= ilen - 1; m++) {
					
					sums[ilen + m][0] = sums[m-1][0] + arr[i];
					int p;
					for(p = 1; sums[m-1][p] != 0; p++) {
						
						sums[ilen + m][p] = sums[m-1][p];
						
					}
					sums[ilen + m][p] = arr[i];
					
				}
				
			}
			
		}
			
			
		return ans;
			
	}
	
	public String get(int n, int[] arr) {
		
		long[][] ans = getAns(n, arr);
		String ret = "";
		
		ret = "" + ans[0][0];
		for(int i = 1; i < ans[0].length; i++) {
			
			ret += " " + ans[0][i];
		
		}
		ret += "\n";
		ret += ans[1][0];
		for(int i = 1; i < ans[1].length; i++) {
			
			ret += " " + ans[1][i];
		
		}
		
		return ret;
		
	}

}
