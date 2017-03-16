import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.HashMap;


public class Recycled {

	
	public static void main(String args[]) {
	try {
		BufferedReader br=new BufferedReader(new InputStreamReader(new FileInputStream("c:\\gcj\\CL\\C-large.in")));
		String line=br.readLine();
		PrintStream ps=new PrintStream("c:\\gcj\\CL\\C-large.out");
		
		int n=Integer.parseInt(line);
			for(int i=1;i<=n;i++) {
				
				line=br.readLine();
				String[] nums=line.split(" ");
				long A=Long.parseLong(nums[0]);
				long B=Long.parseLong(nums[1]);
				ps.println("Case #"+i+": "+getCount(A,B));
										
			}
		} 
		catch(Exception e) {
			e.printStackTrace();
		}
		
		//System.out.print(""+getCount(105279,1957139));
	}
	
	public static long getCount(long A, long B) {
		
		long count=0;
		
		for(long i=A;i<=B;i++)
		{
			//for(long j=i+1;j<=B;j++) 
			/*{
				if(j>i && isRecycled(i,j))
				{
					//hm.put(i, j);
					count++;
					System.out.println("C:"+count);
				}
			}*/
			count+=getRecycled(i, B);
			
		}
		return count;
	}


	static long getRecycled(long n,long limit) {
		long temp=n;
		
		int numDigits=String.valueOf(n).length();

		long count=0;
	
		
		long denom=(long)Math.pow(10, numDigits-1);
	
	temp=n;
//	int digit=firstDigit;
	long sub=0;
	do {
	
		int firstDigit=(int)(temp/denom);
		sub=denom*firstDigit;
		//int digit=(int)temp%10;
		temp=temp-sub;
		temp=temp*10+firstDigit;
		if(temp>n && temp<=limit) {
			count++;
		}
		
		
	}
	while(temp!=n);
	
	
		
	/*
		
		String strN=String.valueOf(n);
		StringBuilder strM=new StringBuilder(String.valueOf(m));

for(int i=0;i<strM.length();i++)
{
	char ch=strM.charAt(0);
	strM.deleteCharAt(0);
	strM.append(ch);
	if(strM.toString().equals(strN))
		return true;
	
}*/
		return count;
		
	}

	static boolean isRecycled(long n, long m) {
		long temp=n;
		int[] countN=new int[10];
		int[] countM=new int[10];
		
		int numDigits=0;
		//int[] orderN=new int[10];
		//int[] orderM=new int[10];
		for(int i=0;i<10;i++) {
			countN[i]=0;
			countM[i]=0;
			
			//orderN[i]=-1;
			//orderM[i]=-1;
		}
		//int firstDigit=0;
		while(temp!=0)
		{
			int digit=(int)temp%10;
			countN[digit]++;
			temp=temp/10;
			numDigits++;
	/*		if(temp==0)
				firstDigit=digit;
		*/		
		}

		temp=m;
		while(temp!=0)
		{
			int digit=(int)temp%10;
			countM[digit]++;
			temp=temp/10;
		}
		
		for(int i=0;i<10;i++){

			if(countN[i]!=countM[i])
				return false;
		}
		
	
		
	long denom=(long)Math.pow(10, numDigits-1);
	
	temp=m;
//	int digit=firstDigit;
	long sub=0;
	do {
	
		int firstDigit=(int)(temp/denom);
		sub=denom*firstDigit;
		//int digit=(int)temp%10;
		temp=temp-sub;
		temp=temp*10+firstDigit;
		if(temp==n)
			return true;
		
		
	}
	while(temp!=m);
	
	
		
	/*
		
		String strN=String.valueOf(n);
		StringBuilder strM=new StringBuilder(String.valueOf(m));

for(int i=0;i<strM.length();i++)
{
	char ch=strM.charAt(0);
	strM.deleteCharAt(0);
	strM.append(ch);
	if(strM.toString().equals(strN))
		return true;
	
}*/
		return false;
		
	}
}
