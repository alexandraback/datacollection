package round12016;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.HashMap;

public class B {

	static class MergerSort
	{
		public static void main(String[] args)
		{
			Integer[] a = {2, 6, 3, 5, 1};
			mergeSort(a);
		}

		public static void mergeSort(Comparable [ ] a)
		{
			Comparable[] tmp = new Comparable[a.length];
			mergeSort(a, tmp,  0,  a.length - 1);
		}


		private static void mergeSort(Comparable [ ] a, Comparable [ ] tmp, int left, int right)
		{
			if( left < right )
			{
				int center = (left + right) / 2;
				mergeSort(a, tmp, left, center);
				mergeSort(a, tmp, center + 1, right);
				merge(a, tmp, left, center + 1, right);
			}
		}


	    private static void merge(Comparable[ ] a, Comparable[ ] tmp, int left, int right, int rightEnd )
	    {
	        int leftEnd = right - 1;
	        int k = left;
	        int num = rightEnd - left + 1;

	        while(left <= leftEnd && right <= rightEnd)
	            if(a[left].compareTo(a[right]) <= 0)
	                tmp[k++] = a[left++];
	            else
	                tmp[k++] = a[right++];

	        while(left <= leftEnd)    // Copy rest of first half
	            tmp[k++] = a[left++];

	        while(right <= rightEnd)  // Copy rest of right half
	            tmp[k++] = a[right++];

	        // Copy tmp back
	        for(int i = 0; i < num; i++, rightEnd--)
	            a[rightEnd] = tmp[rightEnd];
	    }
	 }
	
	static String ats(Integer[] res){
		String r="";
		for(int i=0;i<res.length-1;i++)
			r+=res[i]+" ";
		r+=res[res.length-1];
		return r;
	}
	
	public static void main(String[] args) throws Exception {
//		BufferedReader br = new BufferedReader(new FileReader("B-small-attempt0.in"));
//        PrintWriter pw = new PrintWriter(new File("B-small.out"));
        BufferedReader br = new BufferedReader(new FileReader("B-large.in"));
        PrintWriter pw = new PrintWriter(new File("B-large.out"));
        int T = Integer.parseInt(br.readLine());
        for(int i=1;i<=T;i++){
        	int N = Integer.parseInt(br.readLine());
        	HashMap<Integer,Integer> occ = new HashMap<>();
        	for(int j=0;j<2*N-1;j++){
        		String[] line = br.readLine().split(" ");
        		for(int k=0;k<N;k++){
        			int x = Integer.parseInt(line[k]);
        			if(occ.containsKey(x))
        				occ.put(x, (occ.get(x)+1)%2);
        			else
        				occ.put(x, 1);
        		}
        	}
        	Integer[] res = new Integer[N];
        	int index = 0;
        	for(int k:occ.keySet())
        		if(occ.get(k)%2==1)
        			res[index++]=k;
        	MergerSort.mergeSort(res);
        	pw.println("Case #"+i+": "+ats(res));
        }
        pw.close();
        br.close();
	}
}
