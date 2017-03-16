import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;


public class Energy {
	
	public static void main(String[] args)
	{
		Scanner reader = new Scanner(System.in);
		int T = reader.nextInt();
		for(int t = 1; t <= T; t++){
			long E = reader.nextLong();
			long R = reader.nextLong();
			int N =reader.nextInt();
			long [] v=new long[N];
			for(int n=0;n<N;n++)
			{
				v[n]=reader.nextLong();
			}
			
			
			System.out.println("Case #"+t+": "+cal(E,R,v));
		}
	}
	public static long cal(long E,long R,long[] v)
	{
		long[] val=new long[v.length+1];
		val[0]=E;
		long ret = 0;
		
		ValueAndIndex [] ValueAndIndexs=new ValueAndIndex[v.length];
		for (int i = 0; i < v.length; ++i) {
			ValueAndIndexs[i]=new ValueAndIndex(v[i], i);
		}
		Arrays.sort(ValueAndIndexs);
		for (int j = v.length-1; j >=0 ; --j) {
			int i=ValueAndIndexs[j].index;
//			System.out.println(index);
//			System.out.println(ValueAndIndexs[i].value);
			
			if(val[i]==0&&val[i+1]==0)
			{
				val[i]=E;
				val[i+1]=R;
				ret+=v[i]*E;
			}
			else if(val[i]==0&&val[i+1]!=0)
			{
				val[i]=E;
				ret+=v[i]*(E-val[i+1]+R);
			}
			else if(val[i]!=0&&val[i+1]==0)
			{
				val[i+1]=R;
				ret+=v[i]*(val[i]);
			}
			else
			{
				ret+=v[i]*(val[i]-val[i+1]+R);
			}
			
				
		}
		return ret;
	}
}
