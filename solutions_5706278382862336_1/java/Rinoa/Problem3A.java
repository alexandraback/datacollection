import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class Problem3A {

	static BigInteger two=new BigInteger("2");
	static BigInteger one=new BigInteger("1");
	
	public static void main(String[] args) {
		List<BigInteger[]> input=readInput("D:\\A-large.in");
		String[] result=solve(input);
		outputResults("D:\\A-large.out",result);
	}

	public static String[] solve(List<BigInteger[]> input)
	{
		String[] result=new String[input.size()];
		for(int i=0; i<result.length; i++)
		{
			result[i]=solveSingle(input.get(i));
		}
		return result;
	}
	
	private static String solveSingle(BigInteger[] array)
	{
		BigInteger[] values=toShort(array);
		if(!dividesOnTwo(values[1])) return "impossible";
		BigInteger pow=BigInteger.ZERO;
		while(true){
			if(values[0].compareTo(values[1].divide(two))==-1)
			{
				values=modifyTwo(values);
				pow=pow.add(one);
			}
			else if(values[0].compareTo(values[1].divide(two))==0)
			{
				pow=pow.add(one);
				break;
			}
			else
			{
				values=modify(values);
				pow=pow.add(one);
				break;
			}
		}
		return pow.toString();
	}
	
	private static BigInteger findNOD(BigInteger A, BigInteger B)
	{
		BigInteger a=A;
		BigInteger b=B;
		BigInteger[] ress=a.divideAndRemainder(b);
		while(ress[1].compareTo(BigInteger.ZERO)!=0)
		{
			a=b;
			b=ress[1];
			ress=a.divideAndRemainder(b);
		}
		return b;
	}
	
	private static BigInteger[] toShort(BigInteger[] array)
	{
		BigInteger[] newArray=array;
		BigInteger nod=findNOD(array[1], array[0]);
		newArray[0]=array[0].divide(nod);
		newArray[1]=array[1].divide(nod);
		return newArray;
	}
	
	private static BigInteger[] modify(BigInteger[] array)
	{
		BigInteger[] result=new BigInteger[2];
		result[0]=array[0].add(array[1].divide(two).negate());
		result[1]=array[1].divide(two);
		return result;
	}
	
	private static BigInteger[] modifyTwo(BigInteger[] array)
	{
		BigInteger[] result=new BigInteger[2];
		result[0]=array[0];
		result[1]=array[1].divide(two);
		return result;
	}
	
	private static BigInteger countPowOfTwo(BigInteger value)
	{
		BigInteger[] divideRes=new BigInteger[2];
		BigInteger pow=new BigInteger("0");
		divideRes=value.divideAndRemainder(two);
		while(true)
		{
			if(divideRes[0].compareTo(BigInteger.ONE)==0)
			{
				pow=pow.add(one);
				break;
			}
			if(divideRes[1].compareTo(BigInteger.ZERO)==0)
			{
				pow=pow.add(one);
				divideRes=divideRes[0].divideAndRemainder(two);
			}
			else break;
		}
		return pow;
	}
	
	private static boolean dividesOnTwo(BigInteger value)
	{

		BigInteger[] divideRes=value.divideAndRemainder(two);
		while(true)
		{
			if(divideRes[0].compareTo(BigInteger.ONE)==0) break;
			if(divideRes[1].compareTo(BigInteger.ZERO)==0)
			{
				divideRes=divideRes[0].divideAndRemainder(two);
			}
			else return false;
		}
		return true;
	}
	
	public static List<BigInteger[]> readInput(String fileName)
	{
		List<BigInteger[]> results=new ArrayList<BigInteger[]>();
		try(Scanner in=new Scanner(new File(fileName)))
		{
			int numberOfCases=Integer.parseInt(in.nextLine());
			for(int i=0; i<numberOfCases; i++)
			{
				String[] values=in.nextLine().trim().split("/");
				
				BigInteger[] array=new BigInteger[2];
				
				for(int j=0; j<values.length; j++)
					array[j]=new BigInteger(values[j]);
				
				results.add(array);
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
