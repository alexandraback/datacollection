import java.util.*;
import java.io.*;

public class mine {
	public static int r, c, m;
	// public static State start;
	static HashSet<State> hs = new HashSet<State>();
	static State ans;
	
	static int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	static int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
	
	
	static void dfs( State s, int cnt ){
		if( cnt > r * c - m ) return;
		if( hs.contains(s) ) return;
		hs.add(s);
		// pw.println( s + " " + cnt );
		if( cnt == r * c - m ){
			ans = new State(s);
			return;
		}
		for( int i=0; i<r; ++i ){
			for( int j=0; j<c; ++j ){
				if( s.c[i][j] == 2 ){
					State ns = new State(s);
					ns.c[i][j] = 1;
					// if( s == start ) ns.c[i][j] = 3;
					int add = 0;
					for( int k=0; k<dx.length; ++k ){
						int nx = i + dx[k];
						int ny = j + dy[k];
						if( nx >= 0 && ny >= 0 && nx < r && ny < c ){
							if( ns.c[nx][ny] == 0 ){
								ns.c[nx][ny] = 2;
								add++;
							}
						}
					}
					dfs( ns, cnt + add );
					if( ans != null ) return;
				}
			}
		}
		
	}
	static BufferedReader br = new BufferedReader( new InputStreamReader( System.in ) );
	static PrintWriter pw = new PrintWriter( new BufferedWriter( new OutputStreamWriter( System.out ) ) );
	public static void main( String[] args ) throws IOException {
		int t = Integer.parseInt( br.readLine() );
		for( int tc=1; tc<=t; ++tc ){
			String sp[] = br.readLine().trim().split( "\\s+" );
			r = Integer.parseInt( sp[0] );
			c = Integer.parseInt( sp[1] );
			m = Integer.parseInt( sp[2] );
			State start = new State();
			hs.clear();
			ans = null;
			outer: for( int i=0; i<r; ++i ){
				for( int j=0; j<c; ++j ){
					start.c[i][j] = 2;
					dfs( start, 1 );
					if( ans != null ){
						ans.c[i][j] = 3;
						break outer;
					}
					start.c[i][j] = 0;
				}
			}
			pw.println( "Case #" + tc + ":" );
			if( ans == null ) pw.println( "Impossible" );
			else pw.print( ans.toString2() );
		}
		
		pw.close();
	}
}

class State {
	public int[][] c;
	private int h;
	public State(){
		h = -1;
		c = new int[mine.r][mine.c];
		for( int[] ar : c ){
			Arrays.fill( ar, 0 );
		}
	}
	public State( State s ){
		h = -1;
		c = new int[s.c.length][s.c[0].length];
		for( int i=0; i<c.length; ++i ){
			for( int j=0; j<c[i].length; ++j ){
				c[i][j] = s.c[i][j];
			}
		}
	}
	public String toString(){
		StringBuilder sb = new StringBuilder();
		for( int i=0; i<c.length; ++i ){
			for( int j=0; j<c[i].length; ++j ){
				// if( c[i][j] == 0 ) sb.append( '*' );
				// else sb.append( '.' );
				sb.append( c[i][j] );
			}
			sb.append( '\n' );
		}
		return sb.toString();
	}
	public String toString2(){
		StringBuilder sb = new StringBuilder();
		for( int i=0; i<c.length; ++i ){
			for( int j=0; j<c[i].length; ++j ){
				if( c[i][j] == 0 ) sb.append( '*' );
				else if( c[i][j] == 3 ) sb.append( 'c' );
				else sb.append( '.' );
				// sb.append( c[i][j] );
			}
			sb.append( '\n' );
		}
		return sb.toString();
	}
	public int hashCode(){
		if( h != -1 ) return h;
		return h = toString().hashCode();
	}
}