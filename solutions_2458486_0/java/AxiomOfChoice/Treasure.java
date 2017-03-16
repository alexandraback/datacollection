import java.util.*;

public class Treasure
{
	static Scanner in = new Scanner( System.in );

	public static void main( String[] args )
	{
		int T = in.nextInt();
		for( int t = 1; t <= T; t++ )
		{
			System.out.printf( "Case #%d:", t );
			new Treasure().run();
			System.out.println();
		}
	}

	int get( HashMap<Integer,Integer> m, Integer k )
	{
		if( !m.containsKey( k ) ) m.put( k, 0 );
		return m.get( k );
	}

	void run()
	{
		int k = in.nextInt(), n = in.nextInt();

		HashMap<Integer,Integer> start = new HashMap<Integer,Integer>();
		for( int i = 0; i < k; i++ )
		{
			int key = in.nextInt();
			start.put( key, get( start, key ) + 1 );
		}

		int[] need = new int[n];
		HashMap<Integer,Integer>[] inChest = (HashMap<Integer,Integer>[])(new HashMap[n]);
		for( int i = 0; i < n; i++ )
		{
			need[i] = in.nextInt();
			HashMap<Integer,Integer> have = inChest[i] = new HashMap<Integer,Integer>();
			int h = in.nextInt();
			for( int j = 0; j < h; j++ )
			{
				int key = in.nextInt();
				have.put( key, get( have, key ) + 1 );
			}
		}

		int N = 1<<n;
		final ArrayList<Integer>[] ans = (ArrayList<Integer>[])(new ArrayList[N]);
		ans[0] = new ArrayList<Integer>();

		final Comparator<ArrayList<Integer>> lex = new Comparator<ArrayList<Integer>>()
		{
			public int compare( ArrayList<Integer> a, ArrayList<Integer> b )
			{
				if( a == null ) return 1;
				if( b == null ) return -1;
				for( int i = 0; i < a.size(); i++ )
				{
					if( a.get(i) < b.get(i) ) return -1;
					if( a.get(i) > b.get(i) ) return 1;
				}
				return 0;
			}
		};

		TreeSet<Integer> q = new TreeSet<Integer>(
		new Comparator<Integer>()
		{
			public int compare( Integer a, Integer b )
			{ return lex.compare( ans[a], ans[b] ); }
		});
		q.add( 0 );
		while( !q.isEmpty() )
		{
			int u = q.pollFirst();
			HashMap<Integer,Integer> have = new HashMap<Integer,Integer>( start );
			for( int i = 0; i < n; i++ ) if( ( ( u >> i ) & 1 ) == 1 )
			{
				have.put( need[i], get( have, need[i] ) - 1 );
				for( int key : inChest[i].keySet() )
					have.put( key, get( have, key ) + inChest[i].get( key ) );
			}

			for( int i = 0; i < n; i++ )
			if( ( ( u >> i ) & 1 ) == 0 && get( have, need[i] ) > 0 )
			{
				int v = u | ( 1 << i );
				ArrayList<Integer> path = new ArrayList<Integer>( ans[u] );
				path.add( i );
				if( lex.compare( path, ans[v] ) < 0 )
				{
					q.remove( v );
					ans[v] = path;
					q.add( v );
				}
			}
		}
		if( ans[N-1] == null )
		{
			System.out.print( " IMPOSSIBLE" );
			return;
		}

		for( int i : ans[N-1] )
			System.out.printf( " %d", 1 + i );
	}
}
