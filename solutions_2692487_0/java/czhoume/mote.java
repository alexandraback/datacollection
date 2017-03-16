import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class mote{
	public static String out="";
	
	public static int partition(long arr[], int left, int right)
	{
	      int i = left, j = right;
	      long tmp;
	      long pivot = arr[(left + right) / 2];
	     
	      while (i <= j) {
	            while (arr[i] < pivot)
	                  i++;
	            while (arr[j] > pivot)
	                  j--;
	            if (i <= j) {
	                  tmp = arr[i];
	                  arr[i] = arr[j];
	                  arr[j] = tmp;
	                  i++;
	                  j--;
	            }
	      };
	     
	      return i;
	}
	 
	public static void quickSort(long arr[], int left, int right) {
	      int index = partition(arr, left, right);
	      if (left < index - 1)
	            quickSort(arr, left, index - 1);
	      if (index < right)
	            quickSort(arr, index, right);
	}
	
	public static long absorb(long a, long[] m, int start){
		
		
		while(a>m[start]){
			a=a+m[start];
			start++;
			if(start==m.length)
				return 0;
		}
		
		long ins=0, del;
		

		del=m.length-start;
		
		if(a==1)
			return del;
		
		do{
		a=a+a-1;
		ins++;}while(a<=m[start]);
		
		while(a>m[start]){
			a=a+m[start];
			start++;
			if(start==m.length)
				break;
		}
		if(start<m.length)
			ins= ins+absorb(a,m,start);
		
		
		return Math.min(ins, del);
	}
	
	public static void main(String[] args) {
		BufferedReader br = null;
		BufferedWriter writer = null;
		try {

			br = new BufferedReader(new FileReader(
					"C:/codejam/A-small-attempt0.in"));
			int T, i, j;
			long a;
			int n;
			String tmpd;
			long res;
			T = Integer.parseInt(br.readLine());
			for (i = 1; i < T + 1; i++) {
				out += "Case #" + i + ": ";
				tmpd = br.readLine();
				String[] d = tmpd.split(" ");
				a = Long.parseLong(d[0]);
				n = Integer.parseInt(d[1]);
				long[] m = new long[n];
				tmpd = br.readLine();
				d = tmpd.split(" ");
				for (j = 0; j < n; j++) {
					m[j] = Long.parseLong(d[j]);
				}
				quickSort(m,0,n-1);
				res = absorb(a, m, 0);
			
				out += res + "\n";
				System.out.println("Case #" + i + ": " + res);

			}
			// }
			writer = new BufferedWriter(new FileWriter("C:/codejam/output.out"));

			writer.write(out);

		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			try {
				if (writer != null)
					writer.close();
			} catch (IOException e) {
			}
		}

	}
}