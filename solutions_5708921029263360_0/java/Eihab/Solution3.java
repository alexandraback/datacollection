import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Solution3 {
	static BufferedReader br;
    static StringTokenizer sc;
    static PrintWriter out;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new FileReader("input.in"));
        out = new PrintWriter("output.out");
        sc = new StringTokenizer("");
        int t = nxtInt();
        for (int i = 1; i <= t; i++) {
        	out.print("Case #" + i + ":");
        	int j = nxtInt();
        	int p = nxtInt();
        	int s = nxtInt();
        	int k = nxtInt();
        	
        	int[][][] jps = new int [j][][];
        	for (int l = 0; l < j; l++)
        		jps[l] = new int[p][];
        	for (int l = 0; l < j; l++)
        		for (int m = 0; m < p; m++)
        			jps[l][m] = new int[s];
        	
        	int[][] jp = new int[j][];
        	for (int l = 0; l < j; l++)
        		jp[l] = new int[p];
        	
        	int[][] js = new int[j][];
        	for (int l = 0; l < j; l++)
        		js[l] = new int[s];
        	
        	int[][] ps = new int[p][];
        	for (int l = 0; l < p; l++)
        		ps[l] = new int[s];
        	
        	int counter = 0;
        	for (int i1 = 1; i1 <= j; i1++) {
        		for (int i2 = 1; i2 <= p; i2++) {
        			for (int i3 = 1; i3 <= s; i3++) {
        				if (jp[i1 - 1][i2 - 1] == k || js[i1 - 1][i3 - 1] == k || ps[i2 - 1][i3 - 1] == k)
        					continue;

        				counter++;
        				jps[i1 - 1][i2 - 1][i3 - 1]++;
        				jp[i1 - 1][i2 - 1]++;
        				js[i1 - 1][i3 - 1]++;
        				ps[i2 - 1][i3 - 1]++;
        			}
        		}
        	}
        	
        	out.println(" " + counter);
        	for (int i1 = 0; i1 < j; i1++)
        		for (int i2 = 0; i2 < p; i2++)
        			for (int i3 = 0; i3 < s; i3++)
        				if (jps[i1][i2][i3] == 1)
        					out.println((i1 + 1) + " " + (i2 + 1) + " " + (i3 + 1));
        }
        System.out.println("finish");
        br.close();
        out.close();
    }    

    static String nxtTok() throws IOException {
        while (!sc.hasMoreTokens()) {
            String s = br.readLine();
            if (s == null) {
                return null;
            }
            sc = new StringTokenizer(s.trim());
        }
        return sc.nextToken();
    }

    static int nxtInt() throws IOException {
        return Integer.parseInt(nxtTok());
    }

    static long nxtLng() throws IOException {
        return Long.parseLong(nxtTok());
    }

    static double nxtDbl() throws IOException {
        return Double.parseDouble(nxtTok());
    }

    static int[] nxtIntArr(int n) throws IOException {
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = nxtInt();
        }
        return a;
    }

    static long[] nxtLngArr(int n) throws IOException {
        long[] a = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = nxtLng();
        }
        return a;
    }

    static char[] nxtCharArr() throws IOException {
        return nxtTok().toCharArray();
    }
    
    static int getMin(int arr[], int count)
    {
    	int min = arr[0];
    	for (int i = 1; i < count; i++)
    		if (arr[i] < min)
    			min = arr[i];

    	return min;
    }

    static int getMax(int arr[], int count)
    {
    	int max = arr[0];
    	for (int i = 1; i < count; i++)
    		if (arr[i] > max)
    			max = arr[i];

    	return max;
    }

    static void sortAsc(int arr[], int count)
    {
        int temp;

        for (int i = 0; i < count - 1; i++)
        {
            for (int j = i + 1; j < count; j++)
            {
                if (arr[i] > arr[j])
                {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }

    static void sortDesc(int arr[], int count)
    {
        int temp;

        for (int i = 0; i < count - 1; i++)
        {
            for (int j = i + 1; j < count; j++)
            {
                if (arr[i] < arr[j])
                {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }
}