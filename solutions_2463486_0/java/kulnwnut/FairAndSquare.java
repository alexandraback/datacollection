import java.math.BigInteger;
import java.util.Scanner;

public class FairAndSquare {
	public static void main(String[] args) {
		new FairAndSquare().run();
	}
	
	Scanner sc = new Scanner(System.in);
	int count = 1;
	boolean [] list = new boolean [255];
	
	public void run()
	{	
		int [] numList = new int []{1,4,5,6,9};
		for(int y:numList)
			list[y] = true;
		
		
		int n = sc.nextInt();
		sc.nextLine();
		for( count = 1; count <= n; count++)
			solve();
	}
	
	BigInteger min,max;
	int ans = 0;
	boolean isMax = false;
	private void solve()
	{
		ans = 0;
		isMax = false;
		
		String Astr = sc.next();
		String Bstr = sc.next();
		//if(sc.hasNext())
			//sc.nextLine();
		
		min = new BigInteger(Astr);
		max = new BigInteger(Bstr);
		genPalinDrome(Astr,Bstr);
		System.out.println("Case #" + count + ": " + ans);
		
	}
	
	
	int radix;
	private void getPalindromeHelper(int n,String palin)
	{
		if( n >= (radix+1)/2 )
		{
			String realPalin = palin;
			for(int i=(radix/2)-1;i>=0;i--)
				realPalin += palin.charAt(i);
			calculate(realPalin);
			return;
		}
		
		for(int i=0;i<=9;i++)
		{
			getPalindromeHelper( n+1 , palin + i);
		}
	}
	
	private void genPalinDrome(String beginNum,String maxNum)
	{
		for(int i=1;i<9;i++)
			calculate(i+"");
		
		for(  int i = 2; i <= maxNum.length() ;i++)
		{
			radix = i;
			for(int y=1;y<=9;y++)
			{
				getPalindromeHelper(1, y + "");
				if(isMax)
					return;
			}
			
		}
	}
	
	private boolean isPalinDrome(BigInteger a)
	{
		String line = a.toString();
		int n = line.length();
		for(int i=0;i<n/2;i++)
			if(line.charAt(i) != line.charAt(n-i-1))
				return false;
		return true;
	}
	
	private void calculate(String palinString)
	{
		//System.out.println(palinString);
		BigInteger p = new BigInteger(palinString);
		BigInteger q = p.pow(2);
		if(q.compareTo(min) < 0)
			return;
		if(q.compareTo(max) > 0)
		{
			isMax = true;
			return;
		}
		if( list [ q.toString(0).charAt(0) - '0' ] == false)
			return;
		
		if( isPalinDrome(q) ){
			++ans;
			//System.out.println(palinString);
		}
		
	}
	
}













