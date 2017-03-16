import java.util.*;
import java.io.*;
/**
 * @author RathinaKumar V 
 *         Created on 05.05.2012
 */
public class A{
	public static ArrayList rec(ArrayList m, ArrayList n, int x)
	{
		for(int i: (int[])n.get(x-1))
		{
			if(m.indexOf(i)>=0)return null;
			m.add(i);
			m=rec(m,n,i);
			if(m==null)return null;
		}
		
		return m;
	}
	public static void main(String[] args) throws NumberFormatException, IOException
	{
		Scanner sc = new Scanner(new File("A.txt"));
		int TestCases = sc.nextInt();
		for(int Case=1;Case<=TestCases;Case++)
		{
			ArrayList mas = new ArrayList();
			int N= sc.nextInt();
			ArrayList A = new ArrayList();
			for(int i=0;i<N;i++)
			{
				int size = sc.nextInt();
				int[] temp =new int[size];
				for(int j=0;j<size;j++)temp[j]=sc.nextInt();
				A.add(temp);
			}
			int cnt = 0;
			boolean flag=true;
			do
			{
				if(cnt==N)break;
				cnt++;
				mas = new ArrayList();
				mas=rec(mas,A,cnt);
			}while(mas!=null);
			if(mas==null)
				System.out.println("Case #"+Case+": Yes");
			else
				System.out.println("Case #"+Case+": No");}
	}	
}