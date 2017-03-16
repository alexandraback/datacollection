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
        	char[] s = nxtCharArr();
        	char[] last = new char[s.length];
        	last[0] = s[0];
        	for (int j = 1; j < s.length; j++) {
        		if (s[j] < last[0]) {
        			last[j] = s[j];
        		} else {
        			char[] temp = new char[s.length];
        			temp[0] = s[j];
        			for (int k = 1; k <= j; k++)
        				temp[k] = last[k - 1];
        			last = temp;
        		}
        	}
        	
        	String sol = new String(last);
        	out.println("Case #" + i + ": " + sol);
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