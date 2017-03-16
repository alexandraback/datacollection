import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;


public class RoundCProb2 {
	
	static final long MOD = 1000000007;
	
public static void main(String[] args) throws IOException {
	Scanner sc = new Scanner(new File("RCP2.in"));
	Scanner key = new Scanner(System.in);
	
	int T = sc.nextInt();
	for(int t=1; t<=T; ++t)
	{
		int N=sc.nextInt();
		long multiplier=1;
		ArrayList<String> trains = new ArrayList<String>();
		for(int i=0; i<N; ++i)
			trains.add(sc.next());
		boolean compliant = true;
		for(char C='a'; C<='z' && compliant; ++C)
		{
			ArrayList<String> candidates = new ArrayList<String>();
			for(int i=0; i<trains.size(); ++i)
			{
				if(trains.get(i).contains(C+""))
				{
					candidates.add(trains.remove(i));
					--i;
				}
			}
			String begin=null, end=null;
			ArrayList<String> midpoints = new ArrayList<String>();
			if(candidates.size()==0)
				continue;
			if(candidates.size()==1)
			{
				if(candidates.get(0).replaceAll("^[^"+C+"]*", "").replaceAll("[^"+C+"]*$", "").replaceAll(C+"", "").length()!=0)
					compliant=false;
				trains.add(candidates.get(0));
				continue;
			}
			for(String str:candidates)
			{
				if(str.charAt(0)==C && str.endsWith(C+"")) // midstring
				{
					if(str.replaceAll(C+"", "").length()==0) //OK
						midpoints.add(str);
					else
						compliant=false;
				}
				else
				{
					if(str.endsWith(C+"")) //begin
					{
						if(begin==null)
						{
							String ss=str.replaceAll(C+"*$", "");
							if(!ss.contains(C+"")) //OK
								begin=str;
							else
								compliant=false;
						}
						else
							compliant=false;
					}
					else if(str.charAt(0)==C) //end
					{
						if(end==null)
						{
							String ss=str.replaceAll("^"+C+"*", "");
							if(!ss.contains(C+"")) //OK
								end=str;
							else
								compliant=false;
						}
						else
							compliant=false;
					}
					else
						compliant=false;
				}
			}
			multiplier=(multiplier*factorial(midpoints.size()))%MOD;
			String newStr="";
			if(begin!=null)
				newStr=begin;
			for(String S:midpoints)
				newStr=newStr+S;
			if(end!=null)
				newStr=newStr+end;
			trains.add(newStr);
		}
		multiplier=(multiplier*factorial(trains.size()))%MOD;
		if(compliant)
			System.out.println("Case #"+t+": "+multiplier);
		else
			System.out.println("Case #"+t+": 0");
	}
}

static long factorial(long n)
{
	return ((n<0)?0:((n==0)?1:factorial(n-1)*n))%MOD;
}
}
