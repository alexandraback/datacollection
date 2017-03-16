import java.io.*;
import java.util.*;
import java.math.BigInteger;
import java.math.BigDecimal;

public class Main {
	public static int n;
	public static int m;
	public static BigInteger[] list;
	public static BigInteger[] list_abs;
	public static int[] group;
	public static BigInteger nowmax;
	public static int gc_cnt;
	
	public static int compare_it( BigInteger a, BigInteger a_abs, BigInteger b, BigInteger b_abs )
	{
		int cmp = a_abs.compareTo( b_abs );
		if( cmp != 0 )
			return cmp;
		return a.compareTo( b );
	}
	
	public static void update_it()
	{
		int cnt = 0;
		BigInteger now = BigInteger.ONE;
		for( int i = 0; i < n; ++i )
			if( group[i] == 0 )
			{
				now = now.multiply( list[i] );
				++cnt;
			}
			else
				group[i] = -1;
		BigInteger now_sum = now;
		
		int now_group = 1;
		for( int i = 0; i < n; ++i  )
			if( group[i] == -1 )
			{
				int left_group = m-now_group;
				int left_num = n-cnt;
				if( left_group <= 0 || left_num <= 0 )
				{
					System.out.println( left_group + ":" + left_num );
					while(true);
				}
				++now_group;
				group[i] = -2;
				++cnt;
				now = list[i];
				if( left_group == 1 )
				{
					for( int j = i+1; j < n; ++j )
						if( group[j] == -1 )
						{
							group[j] = -2;
							++cnt;
							now = now.multiply( list[j] );
						}
					now_sum = now_sum.add( now );
					continue;
				}
				if( now.compareTo( BigInteger.ZERO ) > 0 || left_group == left_num )
				{
					now_sum = now_sum.add( now );
					continue;
				}
				for( int j = i+1; j < n; ++j )
					if( group[j] == -1 && list[j].compareTo( BigInteger.ZERO) <= 0 )
					{
						group[j] = -2;
						++cnt;
						now = now.multiply( list[j] );
						break;
					}
				now_sum = now_sum.add( now );
			}
		if( now_group != m || cnt != n )
		{
			System.out.println( now_group + ":" + cnt );
			while( true );
		}
		if( nowmax == null )
			nowmax = now_sum;
		else if( now_sum.compareTo(nowmax) > 0 )
			nowmax = now_sum;
		now = null;
		now_sum = null;
		++gc_cnt;
		if( gc_cnt % 1000 == 0 )
			System.gc();
	}
	
	public static void make_it()
	{
		for( int i = 0; i < n; ++i )
			for( int j = i+1; j < n; ++j )
				if( compare_it( list[j], list_abs[j], list[i], list_abs[i] ) > 0 )
				{
					BigInteger tmp = list[i];
					list[i] = list[j];
					list[j] = tmp;
					
					tmp = list_abs[i];
					list_abs[i] = list_abs[j];
					list_abs[j] = tmp;
				}
		nowmax = null;
		
		//for( int i = 0; i < n; ++i )
		//	System.out.println( list[i] );
		int pos = 0;
		BigInteger now = BigInteger.ONE;
		for( int i = 0; i < n-m+1; ++i )
		{
			now = now.multiply( list[i] );
			if( i > 0 && m > 1 && list_abs[i].equals( BigInteger.ONE ) )
				break;
			if( list[i].compareTo( BigInteger.ZERO ) == 0 && i > 0 && m > 1)
				break;
			group[i] = 0;
			pos = i;
		}
		for( int i = pos+1; i < n; ++i )
			group[i] = -1;
		update_it();
		
		if( pos > 0 && pos != n-1 )
		{
			for( int i = 0; i < n; ++i )
				if( group[i] == 0 )
				{
					group[i] = -1;
					update_it();
					group[i] = 0;
				}
		}
		if( pos != n-m )
		{
			for( int i = 0; i < n; ++i )
				if( group[i] < 0 )
				{
					group[i] = 0;
					update_it();
					group[i] = -1;
				}
		}
		boolean n1 = true;
		boolean n2 = true;
		for( int i = n-1; i >= 0; --i )
			if( group[i] == 0 && list[i].compareTo( BigInteger.ZERO )<0 && n1 )
			{
				n1 = false;
				for( int j = 0; j < n; ++j )
					if( group[j] < 0 )
					{
						group[i] = -1;
						group[j] = 0;
						update_it();
						group[i] = 0;
						group[j] = -1;
					}
			}
			else if( group[i] == 0 && list[i].compareTo( BigInteger.ZERO )>0 && n2)
			{
				n2 = false;
				for( int j = 0; j < n; ++j )
					if( group[j] < 0 )
					{
						group[i] = -1;
						group[j] = 0;
						update_it();
						group[i] = 0;
						group[j] = -1;
					}
			}
		System.out.println( nowmax.toString() );
	}
	
	public static BigInteger big_sqrt(BigInteger n) {
		  BigInteger a = BigInteger.ONE;
		  BigInteger b = new BigInteger(n.shiftRight(5).add(new BigInteger("8")).toString());
		  while(b.compareTo(a) >= 0) {
		    BigInteger mid = new BigInteger(a.add(b).shiftRight(1).toString());
		    if(mid.multiply(mid).compareTo(n) > 0) b = mid.subtract(BigInteger.ONE);
		    else a = mid.add(BigInteger.ONE);
		  }
		  return a.subtract(BigInteger.ONE);
		}
	
	public static void main(String[] args) {
		try
		{
			BigInteger r;
			BigInteger t;
		
			
			Scanner scanner = new Scanner( new File("A-small-attempt0.in" ) );
			PrintWriter out = new PrintWriter( new FileWriter("out.txt") );
			int test_case = scanner.nextInt();
			for( int i = 1; i <= test_case; ++i )
			{
				r = scanner.nextBigInteger();
				t = scanner.nextBigInteger();
				
				BigInteger tmp = r.pow(2).multiply(BigInteger.valueOf(4));
				tmp = tmp.add(r.negate().multiply(BigInteger.valueOf(4)));
				tmp = tmp.add(t.multiply(BigInteger.valueOf(8)));
				tmp = tmp.add(BigInteger.ONE);
				
				tmp = big_sqrt(tmp);
				tmp = tmp.add(r.negate().multiply(BigInteger.valueOf(2))).add(BigInteger.ONE);
				tmp = tmp.divide(BigInteger.valueOf(4));
				out.print( "Case #" + i + ": " );
				out.println( tmp );
			}
			out.close();
			System.out.println("finish");
		}
		catch( Exception exp )
		{
			System.out.println( exp );
		}
	}

}
