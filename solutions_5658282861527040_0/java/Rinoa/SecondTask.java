import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class SecondTask {

	public static void main(String[] args) {
		long[][] input=readInput("D:\\B-small-attempt0.in");
		String[] result=solve(input);
		outputResults("D:\\B-small-attempt0.out",result);
	}

	public static String[] solve(long[][] input)
	{
		String[] result=new String[input.length];
		for(int i=0; i<result.length; i++)
		{
			result[i]=String.valueOf(solve(input[i][0],input[i][1],input[i][2]));
		}
		return result;
	}

	private static long solve(long A, long B, long K)
	{
		long nums=0;
		for(int i=0; i<A; i++)
			for(int j=0; j<B; j++)
				if((i&j)<K) nums++;
		return nums;
	}
	
	private static long countTwoPow(int nums)
	{
		long result=0;
		for(int i=0; i<nums; i++)
			result+=Math.pow(2,i);
		return result;
	}
	
	public static long[][] readInput(String fileName)
	{
		long[][] results=null;
		try(Scanner in=new Scanner(new File(fileName)))
		{
			int numberOfCases=Integer.parseInt(in.nextLine());
			results=new long[numberOfCases][3];
			for(int i=0; i<numberOfCases; i++)
			{
				String[] values=in.nextLine().split("( )+");
				results[i][0]=Long.parseLong(values[0]);
				results[i][1]=Long.parseLong(values[1]);
				results[i][2]=Long.parseLong(values[2]);
			}
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
		return results;
	}

	public static void outputResults(String fileName, String[] results)
	{
		File flt = new File(fileName);
		try(FileWriter wrt = new FileWriter(flt);) {
			if (flt.exists()) {
				flt.delete();
				flt.createNewFile();
			}	
			for(int i=0; i<results.length; i++)
			{
				wrt.append("Case #"+(i+1)+": "+results[i]+"\n");
			}

			wrt.flush();
		} catch (IOException e) {
			System.out.println("Произошла ошибка при записи");
			e.printStackTrace();
		}
	}

}
