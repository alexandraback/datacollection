import java.util.Scanner;


public class Test2 {
	
	int	solve(int n, int[] list) {
		int		pMax	= max(list, n);
		int[]	pHist	= new int[pMax + 1];
		int		pTotal	= 0;
		
		for(int i: list) {
			pHist[i]++;
			pTotal	+= i;
		}
		
		int	iSize	= (int)Math.sqrt((double)pTotal/(double)n);
		
		int	ret	= Integer.MAX_VALUE;
		for(int ts = iSize; ts<=pMax; ts++) {
			int	sum	= 0;
			int	max	= 0;
			
			for(int i= ts+1; i<=pMax; i++) {
				if(pHist[i] == 0)
					continue;
				
				int	N	= (i + ts - 1) / ts;
				int	res	= (i + N - 1) / N;
				sum	+= pHist[i] * (N-1);
				
				max = (max < res) ? res: max;
			}
			
			for(int i=max+1; i<=ts; ++i) {
				if(pHist[i] > 0)
					max	= i;
			}
			sum	+= max;
			
			ret	= (ret > sum) ? sum: ret;
		}
		
		return	ret;
	}
	
	int max(int[] list, int n) {
		int max	= list[0];
		for(int i=1; i<n; ++i) {
			if(list[i] > max)
				max	= list[i];
		}
		
		return	max;
	}
	
	public static void main(String[] args) {
		Scanner	scanIn	= new Scanner(System.in);
		
		int T	= scanIn.nextInt();
		
		for(int i=0; i<T; ++i) {
			Test2	inst	= new Test2();
			int		n		= scanIn.nextInt();
			
			int[]	pList	= new int[n];

			for(int j=0; j<n; ++j)
				pList[j]	= scanIn.nextInt();
			
			int	ret	= inst.solve(n, pList);
			
			System.out.println("Case #" + (i+1) + ": " + ret);
		}
		
		scanIn.close();
	}
}
