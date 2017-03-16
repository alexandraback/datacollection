import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;


public class test3 {

	private static int limit=9;
	
	private static boolean palindrome(String number)
	{
		
		StringBuffer sb=new StringBuffer(number);
		
		if(number.compareTo(String.valueOf(sb.reverse()))==0)
				return true;
				
		else
			return false;
	}
	/*
	private static int binarysearch(ArrayList<String> list,int size,int low,int high)
	{
		int middle=(low+high)/2;
		int len=list.get(middle).length();
		
		System.out.println(low+" "+middle+" "+high);
		
		if(len==size)
			return middle;
		else
		if(len<size)
			return binarysearch(list,size,middle+1,high);
		else
			return binarysearch(list,size,low,middle);
	}
	*/
	
	public static void main(String[] arsg) throws Exception
	{
		PrintWriter pw=new PrintWriter("SmallInput.txt");
		//PrintWriter pw=new PrintWriter(new OutputStreamWriter(System.out));
		
		//BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		BufferedReader br=new BufferedReader(new FileReader("C-small-attempt0.in"));
		ArrayList<String> fairnsq=new ArrayList<String>();
		 
		fairnsq.add("1");
		fairnsq.add("4");
		fairnsq.add("9");
		fairnsq.add("121");
		fairnsq.add("484");
		fairnsq.add("10201");
		fairnsq.add("12321");
		fairnsq.add("14641");
		fairnsq.add("40804");
		fairnsq.add("44944");
		
		ArrayList<StringBuffer> ODD=new ArrayList<StringBuffer>();
		ArrayList<StringBuffer> EVEN=new ArrayList<StringBuffer>();
		
		ODD.add(new StringBuffer("101"));
		ODD.add(new StringBuffer("111"));
		ODD.add(new StringBuffer("121"));
		ODD.add(new StringBuffer("202"));
		ODD.add(new StringBuffer("212"));
		
		EVEN.add(new StringBuffer("11"));
		EVEN.add(new StringBuffer("22"));
		
		for(int t=4;t<limit;++t)
		{
			if(t%2==0)
			{
				int size=EVEN.size();
				int val=2*size;
				StringBuffer[] temp=new StringBuffer[val];
				
				for(int i=0;i<val;++i)
					temp[i]=new StringBuffer(EVEN.get(i%size));
				
				for(int i=0,j=size;i<size&&j<val;++i,++j)
				{
					temp[i]=temp[i].insert(1,'0');
					temp[i]=temp[i].insert(temp[i].length()-1,'0');
					
					temp[j]=temp[j].insert(1,'1');
					temp[j]=temp[j].insert(temp[j].length()-1,'1');
					
					
				}
				
				
				ArrayList<String> temp2=new ArrayList<String>();
				EVEN=new ArrayList<StringBuffer>();
				BigInteger bi;
				for(int i=0;i<val;++i)
				{
					bi=new BigInteger(temp[i].toString()).pow(2);
					
					if(palindrome(bi.toString()))
					{
						EVEN.add(temp[i]);
						temp2.add(bi.toString());
						
					}
				}
				Collections.sort(temp2);
				fairnsq.addAll(temp2);
			}
			else
			{
				
				int size=ODD.size();
				int val=2*size;
				StringBuffer[] temp=new StringBuffer[val];
				
				for(int i=0;i<val;++i)
					temp[i]=new StringBuffer(ODD.get(i%size));
				
				
				for(int i=0,j=size;i<size&&j<val;++i,++j)
				{
					temp[i]=temp[i].insert(1,'0');
					temp[i]=temp[i].insert(temp[i].length()-1,'0');
					
					temp[j]=temp[j].insert(1,'1');
					temp[j]=temp[j].insert(temp[j].length()-1,'1');
				}
				ArrayList<String> temp2=new ArrayList<String>();
				ODD=new ArrayList<StringBuffer>();
				BigInteger bi;
				for(int i=0;i<val;++i)
				{
					bi=new BigInteger(temp[i].toString()).pow(2);
					
					if(palindrome(bi.toString()))
					{
						ODD.add(temp[i]);
						temp2.add(bi.toString());
						
					}
				}
				
				Collections.sort(temp2);
				fairnsq.addAll(temp2);
				
			}
		}
		
		//System.out.println(fairnsq.get(fairnsq.size()-1));
		int size=fairnsq.size();
		int testcases=Integer.parseInt(br.readLine());
		
		for(int t=0;t<testcases;++t)
		{
			
			StringTokenizer st=new StringTokenizer(br.readLine());
			String v1=new String(st.nextToken());
			String v2=new String(st.nextToken());
			
			BigInteger b1=new BigInteger(v1);
			BigInteger b2=new BigInteger(v2);
			int count=0;
			
			for(int i=0;i<size;++i)
			{
				BigInteger b=new BigInteger(fairnsq.get(i));
				int val1=b.compareTo(b1);
				int val2=b.compareTo(b2);
				if(((val1==0)||(val1==1))&&((val2==-1)||(val2==0)))
					count++;
				
			}
			
			pw.println("Case #"+(t+1)+": "+count);
			
			
		}
	//	System.out.println("DONE");
		pw.flush();
		pw.close();
		
		 
	}
	
}
