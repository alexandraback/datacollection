import java.io.*;
import java.util.*;
import java.math.*;

public class C
{
	public static void main(String[] args) throws Exception
	{
    int T;	
    RandomAccessFile in = new RandomAccessFile(args[0],"r");
		T=Integer.parseInt(in.readLine());

		for (int i=1; i<=T; i++)
		{
      String[] temp=in.readLine().split(" ");		
      int N=Integer.parseInt(temp[0]);       
      int M=Integer.parseInt(temp[1]);      
      long[][] a=new long[N][2];
      long[][] b=new long[M][2];      
      temp=in.readLine().split(" ");
      for (int m=0; m<2*N; m++) a[m/2][m%2]=Long.parseLong(temp[m]);   
      temp=in.readLine().split(" ");
      for (int m=0; m<2*M; m++) b[m/2][m%2]=Long.parseLong(temp[m]);
      String ans=solve2(a,b);
      System.out.println("Case #"+i+": "+ans);
    }

		in.close();
	}		
	
	public static long get(long[][] a, long[][] b, int i, int start, int end)
	{
    long total=0;
    long left=a[i][0];
    for (int k=start; k<=end; k++)
    {
      if (b[k][1]==a[i][1])
      {
        if (b[k][0]>=left)
        {
          total+=left;        
          left=0;
          return total;
        }
        else
        {
          left-=b[k][0];
          total+=b[k][0];
        }
      }
    }
    return total;
	}
	
	public static long get2(long[][] a, long[][] countsB, long[][] b, int i, int start, int end)
	{
    long left=a[i][0];
    int val=(int)a[i][1];
    long have=0;
    
    have=countsB[end+1][val]-countsB[start+1-1][val];
    long haveOnLast=0;
    if (val==b[end][1])
    {
      haveOnLast=b[end][0];
    }
    if (haveOnLast>0 && have-haveOnLast>left)
    {
      long rem=have-haveOnLast-left;
      if (rem>0 && rem<haveOnLast)
        System.err.println("rem "+rem);
    }
    return Math.min(left,have);
	}	

	public static String solve(long[][] a, long[][] b)
  {
    int N=a.length;
    int M=b.length;
    int Q=101;
    
    //countsB[i][k] = counts before i
    long[][] countsB=new long[M+1][Q];    
    
    for (int i=1; i<M+1; i++)
    {
      for (int k=0; k<Q; k++) countsB[i][k]=countsB[i-1][k];
      //System.err.println(b[i-1][1]);
      countsB[i][(int)b[i-1][1]]+=b[i-1][0];
    }
    
    /*System.err.println("A");
    for (int i=0; i<N; i++) System.err.println(a[i][0]+" "+a[i][1]);
    System.err.println("B");
    for (int i=0; i<M; i++) System.err.println(b[i][0]+" "+b[i][1]);    
    
    System.err.println(get(a,b,2,1,1));*/
    
    long best=0;
    
    for (int i1=0; i1<M; i1++)
    {
    for  (int i2=i1; i2<M; i2++)
    {
    for (int i3=i2; i3<M; i3++)
    {
    for (int i4=i3; i4<M; i4++)
    {
    for (int i5=i4; i5<M; i5++)
    {
    for (int i6=i5; i6<M; i6++)
    {
    long val1=0;
    if (N>=1) val1=get2(a,countsB,b,0,i1,i2);
    long val2=0;
    if (N>=2) val2=get2(a,countsB,b,1,i3,i4);
    long val3=0;
    if (N>=3) val3=get2(a,countsB,b,2,i5,i6);
    long val=val1+val2+val3;
    if (val>best)
    {
      best=val;
      //System.err.println(i1+" "+i2+" "+val1+", "+i3+" "+i4+" "+val2+", "+i5+" "+i6+" "+val3+", "+val);
    }
    }}}}}}
    
    return ""+best;
    
//    return "";
  }
  
  
	public static String solve2(long[][] a, long[][] b)
  {
    int N=a.length;
    int M=b.length;

    
    long best=0;
    
    for  (int i2=0; i2<M; i2++)
    {
    for (int i3=i2; i3<M; i3++)
    {
    for (int i4=i3; i4<M; i4++)
    {
    for (int i5=i4; i5<M; i5++)
    {
    long val1=0;
    if (N>=1) val1=get(a,b,0,0,i2);
    long val2=0;
    if (N>=2) val2=get(a,b,1,i3,i4);
    long val3=0;
    if (N>=3) val3=get(a,b,2,i5,M-1);
    long val=val1+val2+val3;
    
    if (N>=2 && i2==i3 && b[i2][1]==a[0][1] && a[0][1]==a[1][1])
    {
      long val1a=get(a,b,0,0,i2-1);
      long diff1=val1-val1a;
      long val2a=get(a,b,0,i3+1,i4);
      long diff2=val2-val2a;      
      if (diff1+diff2>b[i2][0]) val-=(diff1+diff2-b[i2][0]);
    }
    if (N>=3 && i4==i5 && b[i4][1]==a[1][1] && a[1][1]==a[2][1])
    {
      long val2a=get(a,b,0,i3,i4-1);
      long diff2=val2-val2a;
      long val3a=get(a,b,0,i5+1,M-1);
      long diff3=val3-val3a;      
      if (diff2+diff3>b[i4][0]) val-=(diff2+diff3-b[i4][0]);
    }    
    if (val>best)
    {
      best=val;
      //System.err.println(i1+" "+i2+" "+val1+", "+i3+" "+i4+" "+val2+", "+i5+" "+i6+" "+val3+", "+val);
    }
    }}}}
    
    return ""+best;
    
//    return "";
  }  
}