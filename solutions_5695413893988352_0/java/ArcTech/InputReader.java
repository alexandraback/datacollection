import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
public class InputReader {
	BufferedReader r;
	String cur;
	public InputReader(String filename) throws IOException
	{
		r = new BufferedReader(new FileReader(filename));
		cur = r.readLine();
	}
	
	public String getCur()
	{
		return cur;
	}
	
	public String getNext() throws IOException
	{
		cur = r.readLine();
		return cur;
	}
	public static int[] stringToInts(String s, int n)
	{
		int[] nums = new int[n];
		int nextstart = 0;
		int temp = 0;
		int i = 0;
		while (i < n - 1)
		{
			temp = s.indexOf(' ', nextstart);
			nums[i] = Integer.parseInt(s.substring(nextstart, temp));
			i++;
			nextstart = temp+1;
		}
		nums[n-1] = Integer.parseInt(s.substring(nextstart));
		return nums;	
	}
	public static long[] stringToLongs(String s, int n)
	{
		long[] nums = new long[n];
		int nextstart = 0;
		int temp = 0;
		int i = 0;
		while (i < n - 1)
		{
			temp = s.indexOf(' ', nextstart);
			nums[i] = Integer.parseInt(s.substring(nextstart, temp));
			i++;
			nextstart = temp+1;
		}
		nums[n-1] = Integer.parseInt(s.substring(nextstart));
		return nums;	
	}
	
	public static int getFirstInt(String s)
	{
		
			int temp = s.indexOf(' ');
			return Integer.parseInt(s.substring(0, temp));
	}
}
