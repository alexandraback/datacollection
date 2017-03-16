import java.util.*;
import java.io.*;
public class p1
{
public static void main(String args[])throws IOException
{
Scanner s=new Scanner(System.in);
BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
int t=s.nextInt();
int a,n,c;
int arr[];
for(int i=0;i<t;i++)
{
a=s.nextInt();
n=s.nextInt();
arr=new int[n];
for(int j=0;j<n;j++)
{
arr[j]=s.nextInt();
}
Arrays.sort(arr);
c=0;
if(a==1)
c=n;
else
{
for(int k=0;k<n;k++)
{
if(arr[k]<a)
{
a+=arr[k];
}
else if(arr[k]>=a&&k!=n-1)
{
while(arr[k]>=a)
{
a+=(a-1);
c++;
}
a+=arr[k];
}
else
{
c++;
}
}
}
if(c<n)
System.out.println("Case #"+(i+1)+": "+c);
else
System.out.println("Case #"+(i+1)+": "+n);
}
}
}

