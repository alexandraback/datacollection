import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;


public class Osmos {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws NumberFormatException, IOException {
		// open file and create a buffered reader
		FileReader input = new FileReader(args[0]);
		BufferedReader buffer = new BufferedReader(input);
		
		//read the number of testcases
		int max = Integer.parseInt(buffer.readLine().trim());
		
		// read a line and call the solving procedure for a single test case.  We expect back the result as a string
		for (int i = 1; i <= max; i++) {
			System.out.println("Case #"+i+": " + solve(buffer));
		}
	}
	
	public static int solve(BufferedReader buffer) throws IOException
	{
		String input = buffer.readLine().trim();
		String[] split = input.split("\\s+");
		int A = Integer.parseInt(split[0]);
		int N = Integer.parseInt(split[1]);
		input = buffer.readLine().trim();
		if (A == 1)
		{
			return N;
		}
		split = input.split("\\s+");
		int[] size = new int[N];
		
		for(int i = 0; i < N; i++)
		{
			size[i] = Integer.parseInt(split[i]);
		}
		quickSort(size);
		
		int answer = N;
		int added = 0;
		for (int i = 0; i < N; i++)
		{
			if((N - i + added) < answer)
			{
				answer = N - i + added;
			}
			if (added > answer)
			{
				return answer;
			}
			while(size[i] >= A)
			{
				added++;
				A = 2 * A - 1;
			}
			A += size[i];
		}
		if(added < answer)
		{
			answer = added;
		}
		
		
		return answer;
	}
	

	public static void quickSort(int[] a)
    {
		quickSort(a,0,a.length - 1);
    }

	
	
	public static void quickSort(int[] a, int p, int r)
    {
        if(p<r)
        {
            int q=partition(a,p,r);
            quickSort(a,p,q);
            quickSort(a,q+1,r);
        }
    }

    private static int partition(int[] a, int p, int r) {

        int x = a[p];
        int i = p-1 ;
        int j = r+1 ;

        while (true) {
            i++;
            while ( i< r && a[i] < x)
                i++;
            j--;
            while (j>p && a[j] > x)
                j--;

            if (i < j)
                swap(a, i, j);
            else
                return j;
        }
    }

    private static void swap(int[] a, int i, int j) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }	
}
