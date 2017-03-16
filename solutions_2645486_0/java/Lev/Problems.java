import java.io.*;
import java.util.*;
import java.util.regex.*;
import java.lang.reflect.Array;
import java.math.*;

import java.awt.geom.*;


/**
 * Google Code Jam problems solved (sometimes incorrectly) by Lev. A. Neiman.
 * 
 * @author Lev Neiman - lev.neiman@gmail.com
 * 
 */
public class Problems
{

	public static PrintStream dOut = System.out;
	
	public interface Problem
	{
		public void solve( InputStream in, PrintStream out ) throws Exception;
	}

	public interface acm_problem extends Problem
	{

	}

	public static class ACM_Problems
	{
		public static class Codeforces
		{
			public static class Round12
			{
				public static class CorrectSolution implements acm_problem
				{

					@Override
					public void solve( InputStream in, PrintStream out )
							throws Exception
					{
						Scanner scanner = new Scanner( in );
						String a = scanner.nextLine();
						String b = scanner.nextLine();
						if( a.length() != b.length() )
						{
							out.println( "WRONG_ANSWER" );
							return;
						}

						Integer [] a_int = new Integer[a.length()];
						for( int i = 0; i < a_int.length; ++i )
							a_int[i] = ( int ) a.charAt( i ) - '0';
						Arrays.sort( a_int );
						// System.out.println( Arrays.toString( a_int ) );

						while( a_int[0] == 0
								&& Util.next_permutation( a_int,
										new Util.TrivialComporator< Integer >() ) )
							;

						// System.out.println( Arrays.toString( a_int ) );
						for( int i = 0; i < a_int.length; ++i )
						{
							if( b.charAt( i ) - '0' != a_int[i] )
							{
								out.println( "WRONG_ANSWER" );
								return;
							}
						}
						out.println( "OK" );
					}
				}

				public static class SuperAgent implements acm_problem
				{

					@Override
					public void solve( InputStream in, PrintStream out )
							throws Exception
					{
						Scanner scanner = new Scanner( in );
						String combo[] = new String[3];
						combo[0] = scanner.nextLine();
						combo[1] = scanner.nextLine();
						combo[2] = scanner.nextLine();
						for( int i = 0; i < 3; ++i )
						{
							for( int j = 0; j < 3; ++j )
							{
								if( combo[i].charAt( j ) != combo[2 - i]
										.charAt( 2 - j ) )
								{
									System.out.print( "NO" );
									return;
								}
							}
						}
						System.out.print( "YES" );
					}

				}
			}

			public static class Round9

			{
				public static class A implements acm_problem
				{

					public void solve( InputStream in, PrintStream out )
							throws Exception
					{
						Scanner scanner = new Scanner( in );
						Integer Y, W;
						Y = scanner.nextInt();
						W = scanner.nextInt();
						Integer M = Math.max( Y, W );
						if( M == 1 )
						{
							out.println( "1/1" );
						}
						if( M == 2 )
						{
							out.println( "5/6" );
						}
						if( M == 3 )
						{
							out.println( "2/3" );
						}
						if( M == 4 )
						{
							out.println( "1/2" );
						}
						if( M == 5 )
						{
							out.println( "1/3" );
						}
						if( M == 6 )
						{
							out.println( "1/6" );
						}
					}
				}
			}
		}
	}

	public interface facebook_problem extends Problem
	{
	}

	public static class facebook_problems
	{
		public static class liarliar implements facebook_problem
		{

			boolean find_liars( Map< String, Set< String >> people,
					Set< String > peeps, Set< String > liars,
					Set< String > truthers, String liar )
			{
				if( !peeps.contains( liar ) )
					return false;
				System.out.println( "LIAR ! " + liar );
				peeps.remove( liar );
				liars.add( liar );
				for( String truthee : people.get( liar ) )
				{
					if( liars.contains( truthee ) )
						return false;
					System.out.println( "TRUTHER ! " + truthee );
					truthers.add( truthee );
					peeps.remove( truthee );
					for( String liarz : people.get( truthee ) )
					{
						find_liars( people, peeps, liars, truthers, liarz );
					}
				}
				return true;
			}

			void printPeople( Map< String, Set< String >> people )
			{
				for( String person : people.keySet() )
				{
					System.out.println( person + ":" );
					for( String liar : people.get( person ) )
					{
						System.out.println( "\t" + liar );
					}
				}
			}

			@Override
			public void solve( InputStream inFile, PrintStream out )
					throws Exception
			{
				String input = Util.Stream2String( inFile );
				StringTokenizer tokenizer = new StringTokenizer( input, " \n\r" );
				int n;
				Map< String, Set< String >> people = new HashMap< String, Set< String >>();
				Set< String > peeps = new HashSet< String >();
				n = Integer.parseInt( tokenizer.nextToken() );
				String first_liar = null;
				while( tokenizer.hasMoreTokens() )
				{
					String name = tokenizer.nextToken();
					peeps.add( name );
					int m = Integer.parseInt( tokenizer.nextToken() );
					if( m > 0 && first_liar == null )
						first_liar = name;
					Set liars = new HashSet< String >();
					people.put( name, liars );
					for( int i = 0; i < m; ++i )
					{
						liars.add( tokenizer.nextToken() );
					}
				}
				// printPeople( people );
				Set< String > liars, goodies;
				liars = new HashSet< String >();
				goodies = new HashSet< String >();
				find_liars( people, peeps, liars, goodies, first_liar );
				while( peeps.size() > 0 )
				{
					String liar = peeps.iterator().next();
					find_liars( people, peeps, liars, goodies, liar );
				}
				System.out.print( Math.max( liars.size(), goodies.size() )
						+ " " );
				System.out.print( Math.min( liars.size(), goodies.size() ) );

			}

		}
	}
	
	public static class GCJ_Problems
	{
		public static class GCJ_Africa
		{

			public static class OnlineRound_Africa_2010
			{
				public static class GetToWork implements Problem
				{
					@Override
					public void solve( InputStream in, PrintStream out )
							throws Exception
					{
						Scanner scanner = new Scanner( in );
						int C = scanner.nextInt();
						for( int case_num = 1; case_num <= C; ++case_num )
						{
							int N = scanner.nextInt();
							int T = scanner.nextInt();
							int E = scanner.nextInt();
							Map< Integer, List< Integer >> town2employees = new HashMap< Integer, List< Integer >>();
							int count[] = new int[N];
							for( int i = 0; i < N; ++i )
								count[i] = 0;
							for( int i = 0; i < E; ++i )
							{
								int H = scanner.nextInt(), P = scanner
										.nextInt();
								if( !town2employees.containsKey( H ) )
									town2employees.put( H,
											new ArrayList< Integer >() );
								town2employees.get( H ).add( P );
							}
							boolean impossible = false;
							for( int i = 0; i < count.length; ++i )
							{
								if( i + 1 == T )
									continue;
								count[i] = solveTown( town2employees
										.get( i + 1 ) );
								if( count[i] == -1 )
								{
									impossible = true;
									break;
								}
							}
							String ret = "Case #" + case_num + ": ";
							if( impossible )
							{
								ret += "IMPOSSIBLE";
							}
							else
							{
								for( int i = 0; i < count.length; ++i )
									ret += count[i] + " ";
							}
							out.println( ret );

						}
					}

					public int solveTown( List< Integer > employees )
					{
						if( employees == null )
							return 0;
						Collections.sort( employees );
						Collections.reverse( employees );
						int ret = 0;
						int covered = 0;
						int i = 0;
						while( i < employees.size()
								&& covered < employees.size() )
						{
							covered += employees.get( i++ );
							++ret;
						}
						if( covered < employees.size() )
							return -1;
						return ret;
					}
				}

				public static class OddManOut implements Problem
				{
					@Override
					public void solve( InputStream in, PrintStream out )
							throws Exception
					{
						Scanner scanner = new Scanner( in );
						int N = scanner.nextInt();

						for( int case_num = 1; case_num <= N; ++case_num )
						{
							int G = scanner.nextInt();
							Map< Long, Integer > num = new HashMap< Long, Integer >();
							while( G-- > 0 )
							{
								Long c = scanner.nextLong();
								Integer t = num.get( c );
								if( t == null )
									t = 1;
								else
									++t;
								num.put( c, t );
							}
							long ret = 0;
							for( Long n : num.keySet() )
							{
								if( num.get( n ) == 1 )
								{
									ret = n;
									break;
								}
							}
							out.println( "Case #" + case_num + ": " + ret );
						}
					}
				}

				public static class QualificationRound implements Problem
				{

					@Override
					public void solve( InputStream in, PrintStream out )
							throws Exception
					{
						Scanner scanner = new Scanner( in );
						int T = scanner.nextInt();
						for( int case_num = 1; case_num <= T; ++case_num )
						{
							int P = scanner.nextInt(), C = scanner.nextInt();
							List< Long > problems = new ArrayList< Long >();
							for( int i = 0; i < P; ++i )
								problems.add( scanner.nextLong() );
							Collections.sort( problems );
							Collections.reverse( problems );
							long ret = problems.get( C - 1 );

							out.println( "Case #" + case_num + ": " + ret );
						}

					}

				}
			}

			public static class QualificationRound_Africa_2010
			{
				public static class ReverseWords implements Problem
				{
					@Override
					public void solve( InputStream in, PrintStream out )
							throws Exception
					{
						Scanner scanner = new Scanner( in );
						int N = Integer.parseInt( scanner.nextLine() );
						for( int case_num = 1; case_num <= N; ++case_num )
						{
							String line = scanner.nextLine();
							List< String > list = new ArrayList< String >();
							StringTokenizer tokenizer = new StringTokenizer(
									line, " " );
							while( tokenizer.hasMoreTokens() )
								list.add( tokenizer.nextToken() );
							Collections.reverse( list );
							String ret = "Case #" + case_num + ": ";
							for( String word : list )
								ret += word + " ";
							out.println( ret );
						}
					}
				}

				public static class StoreCredit implements Problem
				{

					@Override
					public void solve( InputStream in, PrintStream out )
							throws Exception
					{
						Scanner scanner = new Scanner( in );
						int N = scanner.nextInt();
						for( int case_num = 1; case_num <= N; ++case_num )
						{
							int C, l;
							C = scanner.nextInt();
							l = scanner.nextInt();
							int p[] = new int[l];
							for( int i = 0; i < l; ++i )
								p[i] = scanner.nextInt();
							int i1 = 0, i2 = 0;
							for( int i = 0; i < l; ++i )
							{
								boolean found = false;
								for( int j = i + 1; j < l; ++j )
								{
									if( p[i] + p[j] == C )
									{
										i1 = i;
										i2 = j;
										found = true;
										break;
									}
								}
								if( found )
									break;
							}
							out.println( "Case #" + case_num + ": " + ( i1 + 1 )
									+ " " + ( i2 + 1 ) );
						}
					}
				}

				public static class T9Spelling implements Problem
				{
					static String [] keys = { "abc", "def", "ghi", "jkl",
							"mno", "pqrs", "tuv", "wxyz" };
					static Map< Character, Integer > char_2_key = new HashMap< Character, Integer >();
					static Map< Character, Integer > char_2_presses = new HashMap< Character, Integer >();

					public static void init()
					{
						char_2_key.put( ' ', 0 );
						char_2_presses.put( ' ', 1 );
						for( int i = 0; i < keys.length; ++i )
						{
							for( int j = 0; j < keys[i].length(); ++j )
							{
								Character c = keys[i].charAt( j );
								char_2_key.put( c, i + 2 );
								char_2_presses.put( c, j + 1 );
							}
						}
					}

					@Override
					public void solve( InputStream in, PrintStream out )
							throws Exception
					{
						init();
						Scanner scanner = new Scanner( in );
						int N = Integer.parseInt( scanner.nextLine() );
						for( int case_num = 1; case_num <= N; ++case_num )
						{
							String line = scanner.nextLine();
							String ret = "Case #" + case_num + ": ";
							int p = -1;
							for( int i = 0; i < line.length(); ++i )
							{
								int key = char_2_key.get( line.charAt( i ) );
								int presses = char_2_presses.get( line
										.charAt( i ) );
								if( key == p )
									ret += " ";
								for( int j = 0; j < presses; ++j )
									ret += Integer.toString( key );
								p = key;
							}
							out.println( ret );
						}
					}
				}
			}

		}
		public static class GCJ_2009
		{

			public static class QualificationRound_2009
			{
				public static class AlienLanguage implements Problem
				{

					@Override
					public void solve( InputStream inFile, PrintStream out )
							throws FileNotFoundException
					{
						Scanner in = new Scanner( inFile );
						int L, D, N;

						L = in.nextInt();
						D = in.nextInt();
						N = in.nextInt();
						in.nextLine();
						ArrayList< String > words = new ArrayList< String >();

						for( int i = 0; i < D; ++i )
						{
							words.add( in.nextLine() );
							// System.out.println( "Added word " +
							// words.get(words.size() -1 ));
						}
						for( int i = 1; i <= N; ++i )
						{
							String pattern = in.nextLine();
							pattern = pattern.replace( '(', '[' );
							pattern = pattern.replace( ')', ']' );
							// System.out.println( "case pattern = " + pattern);
							Pattern p_pattern = Pattern.compile( pattern );

							int num_match = 0;
							for( int j = 0; j < words.size(); ++j )
							{
								Matcher m = p_pattern.matcher( words.get( j ) );
								boolean matches = m.matches();
								num_match += matches ? 1 : 0;
								// System.out.println( words.get(j) +
								// " matches = " + matches);
							}
							out.println( "Case #" + i + ": " + num_match );
						}

					}

				}

				public static class Watersheds implements Problem
				{
					// Map<Character,List<Character>> same_basins = new
					// HashMap<Character,List<Character>>();
					Map< Character, Character > replace = new HashMap< Character, Character >();

					int D[][] = { { 0, -1 }, { -1, 0 }, { 1, 0 }, { 0, 1 } };

					void DFS( int [][] board, char [][] drains, int x, int y,
							char cur_char )
					{
						drains[x][y] = cur_char;
						int next_move[] = next_drain( board, drains, x, y );
						// System.out.println( x + " " + y);
						// System.out.println( next_move[0] + " " +
						// next_move[1]);
						// System.out.println( " ============ ");
						if( next_move[0] == x && next_move[1] == y )
						{
							// System.out.println( "omg");
							return;
						}
						char drain = drains[next_move[0]][next_move[1]];
						if( drain == '.' )
						{
							DFS( board, drains, next_move[0], next_move[1],
									cur_char );
						}
						else if( drain == cur_char )
							return;
						else
						{
							/*
							 * if( !same_basins.containsKey(drain)) {
							 * same_basins.put(drain, new
							 * ArrayList<Character>()); }
							 * same_basins.get(drain).add(cur_char);
							 */
							// System.out.println( "")
							// drains[x][y]=drain;
							replace.put( cur_char, drain );
						}
					}

					int [] next_drain( int [][] board, char [][] drains, int x,
							int y )
					{
						int nx = x, ny = y;
						int min_drain = board[x][y];
						for( int d = 0; d < D.length; ++d )
						{
							int tx = x + D[d][0];
							int ty = y + D[d][1];

							if( tx < 0 || tx >= board.length || ty < 0
									|| ty >= board[0].length )
								continue;

							if( min_drain > board[tx][ty] )
							{
								min_drain = board[tx][ty];
								nx = tx;
								ny = ty;
							}
						}
						// System.out.println( x + " " + y);
						// System.out.println( nx+ " " + ny);
						int [] ret = { nx, ny };
						return ret;
					}

					@Override
					public void solve( InputStream inFile, PrintStream out )
							throws FileNotFoundException
					{
						Scanner in = new Scanner( inFile );

						int num_maps = in.nextInt();
						for( int case_num = 1; case_num <= num_maps; ++case_num )
						{
							replace.clear();
							// System.out.println( "==============");
							int H, W;
							int [][] board;
							char [][] drains;
							H = in.nextInt();
							W = in.nextInt();
							board = new int[W][H];
							drains = new char[W][H];
							for( int h = 0; h < H; ++h )
							{
								for( int w = 0; w < W; ++w )
								{
									board[w][h] = in.nextInt();
									drains[w][h] = '.';
								}
							}
							// drains[0][0] = 'a';
							char cur_drain = '`';
							for( int y = 0; y < H; ++y )
							{
								for( int x = 0; x < W; ++x )
								{
									if( drains[x][y] != '.' )
										continue;
									DFS( board, drains, x, y, ++cur_drain );

								}

							}

							trim_replace();
							sort_replace( drains, W, H );

							out.println( "Case #" + case_num + ":" );
							for( int y = 0; y < H; ++y )
							{
								for( int x = 0; x < W; ++x )
								{
									Character p_char = replace
											.get( drains[x][y] );
									p_char = p_char == null ? drains[x][y]
											: p_char;
									out.print( p_char + " " );
									// System.out.println( drains[x][y] + "==>"
									// + p_char);
								}
								out.print( "\n" );

							}

						}

					}

					void sort_replace( char drains[][], int W, int H )
					{
						for( int y = 0; y < H; ++y )
						{
							for( int x = 0; x < W; ++x )
							{
								Character c = replace.get( drains[x][y] );
								c = c == null ? drains[x][y] : c;
								drains[x][y] = c;
							}
						}
						Map< Character, Character > rep_replace = new HashMap< Character, Character >();
						char largest = 'a';
						for( int y = 0; y < H; ++y )
						{
							for( int x = 0; x < W; ++x )
							{
								if( drains[x][y] > largest
										&& !rep_replace
												.containsKey( drains[x][y] ) )
								{
									rep_replace.put( drains[x][y], ++largest );
								}
							}
						}
						replace = rep_replace;
					}

					void trim_replace()
					{
						Map< Character, Character > rep_replace = new HashMap< Character, Character >();
						for( Character c : replace.keySet() )
						{
							char new_replace = c;
							while( replace.containsKey( new_replace ) )
							{
								new_replace = replace.get( new_replace );
							}

							rep_replace.put( c, new_replace );
						}
						replace = rep_replace;
					}

				}

				public static class WelcomeToCodeJam implements Problem
				{
					public static final String welcome = "welcome to code jam";

					long mem[][];

					String beautify( Long num )
					{
						String ret = num.toString();
						if( ret.length() > 4 )
							return ret.substring( ret.length() - 4 );

						while( ret.length() != 4 )
							ret = '0' + ret;

						return ret;
					}

					long dfs( String text, int pos, int cons )
					{
						if( mem[pos][cons] != -1 )
							return mem[pos][cons];
						if( cons == welcome.length() - 1
								&& text.charAt( pos ) == 'm' )
							return 1;
						long ret = 0;
						for( int i = pos + 1; i < text.length(); ++i )
						{
							if( text.charAt( i ) == welcome.charAt( cons + 1 ) )
							{
								// System.out.println( "yay");
								ret += dfs( text, i, cons + 1 ) % 10000;
							}
						}
						ret = ret % 10000;
						mem[pos][cons] = ret % 10000;
						return ret;
					}

					@Override
					public void solve( InputStream inFile, PrintStream out )
							throws FileNotFoundException
					{
						Scanner in = new Scanner( inFile );

						String t;
						t = in.nextLine();
						int num_cases = Integer.parseInt( t );
						for( int case_num = 1; case_num <= num_cases; ++case_num )
						{
							System.out.println( "========== " + case_num
									+ " ===========" );
							String line = in.nextLine();
							out.println( "Case #" + case_num + ": "
									+ beautify( solve_iterative( line ) ) );
						}

					}

					long solve( String text )
					{
						long ret = 0;
						mem = new long[text.length()][welcome.length()];
						for( int i = 0; i < mem.length; ++i )
							for( int j = 0; j < welcome.length(); ++j )
								mem[i][j] = -1;
						for( int i = 0; i < text.length(); ++i )
						{
							if( text.charAt( i ) == 'w' )
							{
								ret += dfs( text, i, 0 );

							}
						}
						return ret;
					}

					long solve_iterative( String text )
					{
						long ret = 0;

						mem = new long[text.length()][welcome.length()];
						for( int i = 0; i < text.length(); ++i )
							for( int j = 0; j < welcome.length(); ++j )
								mem[i][j] = 0;
						for( int i = 0; i < text.length(); ++i )
							if( text.charAt( i ) == 'w' )
								mem[i][0] = 1;

						for( int i = 0; i < text.length(); ++i )
						{
							for( int j = 1; j < welcome.length(); ++j )
							{
								if( text.charAt( i ) == welcome.charAt( j ) )
								{
									for( int k = 0; k < i; ++k )
									{
										mem[i][j] += mem[k][j - 1] % 10000;
									}
									if( j == welcome.length() - 1 )
										ret += mem[i][j] % 10000;
									ret = ret % 10000;
								}
							}
						}
						for( int i = 0; i < text.length(); ++i )
						{
							for( int j = 0; j < welcome.length(); ++j )
							{
								// System.out.print( mem[i][j] + " ");
							}
							// System.out.print( "\n");
						}
						return ret;
					}

				}
			}

			public static class Round1A_2009
			{
				public static class CrossingTheRoad implements Problem
				{

					@Override
					public void solve( InputStream inFile, PrintStream out )
							throws FileNotFoundException
					{
						Scanner in = new Scanner( inFile );
						int C = in.nextInt();
						for( int case_num = 1; case_num <= C; ++case_num )
						{
							int N, M;
							N = in.nextInt();
							M = in.nextInt();

							int S[][] = new int[N][M];
							int W[][] = new int[N][M];
							int T[][] = new int[N][M];
							for( int i = 0; i < N; ++i )
							{
								for( int j = 0; j < M; ++j )
								{
									S[i][j] = in.nextInt();
									W[i][j] = in.nextInt();
									T[i][j] = in.nextInt();
								}
							}
							wait( S, W, T, 0, 0, 4, true );

						}
					}

					int wait( int S[][], int W[][], int T[][], int i, int j,
							int t, boolean north_south )
					{
						int p = S[i][j] + W[i][j];
						int k = T[i][j] % p;
						int c = Math.abs( ( t - k ) % p );
						// c= p % t + T[i][j] %p;

						System.out.println( c );
						// int k = t/T[i][j];
						return t;
					}

				}

				public static class MultiBaseHappiness implements Problem
				{

					static HashMap< Long, String > [] conv_mem = new HashMap[11];
					static
					{
						for( int i = 2; i <= 10; ++i )
						{
							conv_mem[i] = new HashMap< Long, String >();
						}
					}

					static HashMap< String, Boolean > happy_mem[] = new HashMap[11];

					static
					{
						for( int i = 2; i <= 10; ++i )
						{
							happy_mem[i] = new HashMap< String, Boolean >();
						}
					}

					static int lim = 1 * ( int ) 1e6;

					// String step

					static boolean [][] happiness = new boolean[lim][11];

					String convert( long i, int base )
					{
						if( conv_mem[base].containsKey( i ) )
							return conv_mem[base].get( i );

						String ret = "";

						while( i > 0 )
						{
							ret = i % base + ret;
							i /= base;
						}
						conv_mem[base].put( i, ret );
						return ret;
					}

					int convert( String numb, int base )
					{
						int ret = 0;
						int c = 0;
						for( int i = numb.length() - 1; i >= 0; --i )
						{
							ret += Math.pow( base, c )
									* ( numb.charAt( i ) - 48 );
							++c;
						}
						return ret;
					}

					int findHappy( ArrayList< Integer > bases )
					{
						int ret = 0;

						for( int i = 2; i < lim; ++i )
						{
							boolean isgood = true;
							for( Integer k : bases )
							{
								if( !happiness[i][k] )
								{
									isgood = false;
									break;
								}
							}
							if( isgood )
								return i;
						}

						return ret;
					}

					boolean isHappy( int i, int base )
					{

						String t = convert( i, base );
						HashSet< String > set = new HashSet< String >();
						Boolean happy = null;
						while( !t.equals( "1" ) && !set.contains( t ) )
						{
							set.add( t );
							t = next_step( t, base );
							if( happy_mem[base].containsKey( t ) )
							{
								happy = new Boolean( happy_mem[base].get( t ) );
								break;
							}
						}
						happy = happy == null ? t.equals( "1" ) : happy;

						for( String k : set )
						{
							happy_mem[base].put( k, happy );
						}

						return happy;

						// return isHappy( convert( i, base ), base, new
						// HashSet<String>());
					}

					boolean isHappy( String t, int base, Set< String > already )
					{
						if( t.equals( "1" ) )
							return true;
						if( already.contains( t ) )
							return false;
						if( happy_mem[base].containsKey( t ) )
							return happy_mem[base].get( t );

						already.add( t );

						String next = next_step( t, base );

						boolean ret = isHappy( next, base, already );
						happy_mem[base].put( t, ret );
						return ret;

					}

					String next_step( String str, int base )
					{
						long sum = 0;
						for( int i = 0; i < str.length(); ++i )
						{
							char [] t = { str.charAt( i ) };
							int k = convert( new String( t ), base );
							sum += k * k;
						}
						return convert( sum, base );
					}

					void precomptue()
					{
						for( int base = 2; base <= 10; ++base )
						{
							for( int i = 2; i < lim; ++i )
							{
								happiness[i][base] = isHappy( i, base );
							}
						}
						System.out.println( "done precomputing" );
					}

					@Override
					public void solve( InputStream inFile, PrintStream out )
							throws FileNotFoundException
					{
						precomptue();
						Scanner in = new Scanner( inFile );
						int T = in.nextInt();
						in.nextLine();
						for( int case_num = 1; case_num <= T; ++case_num )
						{
							String line = in.nextLine();
							ArrayList< Integer > bases = new ArrayList< Integer >();
							StringTokenizer tokenizer = new StringTokenizer(
									line, " " );
							while( tokenizer.hasMoreTokens() )
							{
								bases.add( Integer.parseInt( tokenizer
										.nextToken() ) );
							}
							out.println( "Case #" + case_num + ": "
									+ findHappy( bases ) );
							System.out.println( convert( 82, 10 ) );
							// System.out.println( convert( "82", 10 ));
							// System.out.println( isHappy( 51, 2));
							// System.out.println( next_step( "82",10));
						}

					}

				}
			}

			public static class Round1B_2009
			{
				public static class DecisionTree implements Problem
				{

					public static class animal
					{
						Set< String > attr = new HashSet< String >();
						double prob = 1;
						String name;

						void compute( StringTokenizer t )
						{
							// t.nextToken();
							String p = t.nextToken();
							if( p.equals( "(" ) )
								p = t.nextToken();
							System.out.println( name + " " + p );
							prob *= Double.parseDouble( p );
							p = t.nextToken();

							System.out.println( name + " " + p );

							if( p.equals( ")" ) )
							{
								return;
							}
							if( attr.contains( p ) )
							{
								System.out.println( name + " is " + p );
								compute( t );
							}
							else
							{
								System.out.println( name + " is not " + p );
								int z = 0;
								boolean ok_to_break = false;
								while( true )
								{
									if( ok_to_break && z == 0 )
										break;
									p = t.nextToken();
									if( p.equals( "(" ) )
									{
										++z;
										ok_to_break = true;
									}
									if( p.equals( ")" ) )
									{
										--z;

									}
									System.out.println( "skipping " + p );
								}
								compute( t );
							}

						}
					}

					public void solve( InputStream inFile, PrintStream out )
							throws FileNotFoundException
					{
						Scanner in = new Scanner( inFile );

						int N = in.nextInt();
						for( int case_num = 1; case_num <= N; ++case_num )
						{
							ArrayList< animal > animals = new ArrayList< animal >();

							int L = in.nextInt();
							in.nextLine();
							String tree = "";
							for( int i = 0; i < L; ++i )
								tree += in.nextLine();
							tree = tree.replace( "(", " ( " );
							tree = tree.replace( ")", " )  " );
							System.out.println( tree );
							int A = in.nextInt();
							in.nextLine();
							for( int i = 0; i < A; ++i )
							{
								String t = in.nextLine();
								// System.out.println(t);
								StringTokenizer tokenizer = new StringTokenizer(
										t, " " );
								animal new_animal = new animal();
								new_animal.name = tokenizer.nextToken();
								tokenizer.nextToken();

								while( tokenizer.hasMoreTokens() )
									new_animal.attr.add( tokenizer.nextToken() );
								animals.add( new_animal );
							}

							out.println( "Case #" + case_num + ": " );
							for( animal an : animals )
							{
								// System.out.println( an.attr);
								an.compute( new StringTokenizer( tree, " " ) );
								out.println( an.prob );
							}
						}
					}
				}

				public static class TheNextNumber implements facebook_problem
				{

					public static String conv( Integer [] t )
					{
						String ret = "";
						for( int i = 0; i < t.length; ++i )
						{
							ret += Integer.toString( t[i] );
						}
						return ret;
					}

					@Override
					public void solve( InputStream inFile, PrintStream out )
							throws FileNotFoundException
					{
						Scanner in = new Scanner( inFile );
						int T = in.nextInt();
						in.nextLine();
						for( int case_num = 1; case_num <= T; ++case_num )
						{
							String N = in.nextLine();
							Integer [] c_N = new Integer[N.length()];
							for( int i = 0; i < N.length(); ++i )
								c_N[i] = N.charAt( i ) - 48;
							boolean p = Util.next_permutation( c_N );
							if( !p )
							{

							}
							out.println( "Case #" + case_num + ": "
									+ conv( c_N ) );
						}
					}
				}
			}

			public static class Round1C_2009
			{
				public static class BribeThePrisoners implements Problem
				{

					@Override
					public void solve( InputStream inFile, PrintStream out )
							throws Exception
					{

						Scanner in = new Scanner( inFile );
						// System.out.println( in);
						// in.next();
						int N = in.nextInt();
						for( int case_num = 1; case_num <= N; ++case_num )
						{
							System.out.println( "==== " + case_num + " ===" );
							int P, Q;
							P = in.nextInt();
							Q = in.nextInt();
							System.out.println( P + " " + Q );
							int [] release = new int[Q];
							for( int i = 0; i < Q; ++i )
								release[i] = in.nextInt();
							int [][] dp = new int[P + 1][P + 1];
							for( int i = 0; i < P + 1; ++i )
								for( int j = 0; j < P + 1; ++j )
									dp[i][j] = -1;
							// for( int i = 0; i < Q; ++i) System.out.println(
							// release[i]);
							int sol = P > 1 ? solve( release, dp, 1, P ) : P
									- Q;

							out.println( "Case #" + case_num + ": " + sol );

						}

					}

					int solve( int [] release, int [][] dp, int a, int b )
					{
						if( b >= dp[0].length || a >= dp.length || a <= 0
								|| b <= 0 )
							return 0;
						if( dp[a][b] != -1 )
							return dp[a][b];
						int ret = 0;
						for( int i = release.length - 1; i >= 0; --i )
						{
							if( release[i] >= a && release[i] <= b )
							{
								int t = ( b - a )
										+ solve( release, dp, a, release[i] - 1 )
										+ solve( release, dp, release[i] + 1, b );
								if( ret == 0 || t < ret )
									ret = t;
							}
						}
						// System.out.println( ret );
						dp[a][b] = ret;
						return ret;
					}

				}
			}

			public static class Round2_2009
			{
				public static class A implements Problem
				{
					@Override
					public void solve( InputStream inFile, PrintStream out )
							throws Exception
					{
						Scanner in = new Scanner( inFile );
						int T = in.nextInt();
						for( int case_num = 1; case_num <= T; ++case_num )
						{
							// System.out.println( "==========");

							int N = in.nextInt();
							in.nextLine();
							int k = 0;
							int num = 0;
							ArrayList< String > matrix = new ArrayList< String >();
							for( int i = 0; i < N; ++i )
							{
								String line = in.nextLine();
								matrix.add( line );
							}
							while( k < N )
							{
								int z = k;
								for( int i = k; i < N; ++i )
								{
									int p = zero( matrix.get( i ) );
									if( p >= N - ( k + 1 ) )
									{
										z = i;
										break;
									}
								}
								for( int j = z; j > k; --j )
								{
									swap( matrix, j, j - 1 );
								}
								num += z - k;
								// System.out.println( num );
								++k;
							}
							out.println( "Case #" + case_num + ": " + num );
						}

					}

					void swap( ArrayList< String > matrix, int a, int b )
					{
						String t = matrix.get( a );
						matrix.set( a, matrix.get( b ) );
						matrix.set( b, t );
					}

					int zero( String a )
					{
						int ret = 0;
						for( int i = a.length() - 1; i >= 0; --i )
						{
							if( a.charAt( i ) != '0' )
								break;
							ret++;
						}
						return ret;
					}
				}

				public static class B implements Problem
				{
					public static class node
					{
						int n;
						boolean goal = false;
						ArrayList< node > can_get_to = new ArrayList< node >();
					}

					public static int num_nodes = 1;

					public static Map< Integer, node > num2node = new HashMap< Integer, node >();

					int D[][] = { { 1, 0 }, { -1, 0 } };

					int DIG[][] = { { 1, 1 }, { -1, 1 } };

					void build_graph( char [][] cave, int [][] mark, int F,
							node curr_node, int x, int y, boolean dug )
					{

						if( y >= cave.length || y < 0 || x >= cave[0].length
								|| x < 0 )
							return;
						if( mark[y][x] > 0 )
							return;
						if( cave[y][x] == '#' && !dug )
							return;
						mark[y][x] = curr_node.n;
						if( cave[y][x] == '.' || dug )
						{
							if( y == cave.length - 1 )
								curr_node.goal = true;
							for( int i = 0; i < D.length; ++i )
							{
								build_graph( cave, mark, F, curr_node, x
										+ D[i][0], y + D[i][1], false );
							}
							int f = fall( cave, x, y );
							if( f <= F )
								build_graph( cave, mark, F, curr_node, x,
										y + 1, false );

							// try to dig left and right;
							for( int i = 0; i < DIG.length; ++i )
							{
								int x1 = x + DIG[i][0];
								int y1 = y + DIG[i][1];
								if( x1 < cave[0].length && x1 >= 0 && y1 >= 0
										&& y1 < cave.length )
								{
									if( y1 < cave.length - 1 )
									{
										if( cave[y][x1] == '.'
												&& cave[y1][x1] == '#' )
										{
											// cave[y1][x1]='.';
											int fall = 1 + fall( cave, x1,
													y1 + 1 );
											if( fall <= F )
											{

												int num = mark[y1 + 1][x1];
												if( num > 0 )
												{
													curr_node.can_get_to
															.add( num2node
																	.get( num ) );
												}
												else
												{
													node new_node = new node();
													new_node.n = ++num_nodes;
													curr_node.can_get_to
															.add( new_node );
													num2node.put( new_node.n,
															new_node );
													build_graph( cave, mark, F,
															new_node, x1, y1,
															true );
												}
											}
										}
									}
								}
							}
						}

					}

					int fall( char [][] cave, int x, int y )
					{
						int ret = 0;
						while( y < cave.length && cave[y][x] == '.' )
						{
							++ret;
							++y;
						}
						return ret;
					}

					@Override
					public void solve( InputStream inFile, PrintStream out )
							throws Exception
					{
						Scanner in = new Scanner( inFile );
						int N = in.nextInt();
						for( int case_num = 1; case_num <= N; ++case_num )
						{
							int R, C, F;
							R = in.nextInt();
							C = in.nextInt();
							F = in.nextInt();
							in.nextLine();
							char [][] cave = new char[R][];
							for( int i = 0; i < R; ++i )
								cave[i] = in.nextLine().toCharArray();
							int [][] mark = new int[R][C];
							for( int i = 0; i < R; ++i )
								for( int j = 0; j < C; ++j )
									mark[i][j] = 0;
							node root = new node();
							root.n = num_nodes;
							build_graph( cave, mark, F, root, 0, 0, false );
							out.println( "Case #" + case_num + ": "
									+ solve( root ) );
						}

					}

					int solve( node n )
					{
						if( n.goal )
							return 0;
						int ret = 1;
						int m = Integer.MAX_VALUE;
						for( node child : n.can_get_to )
						{
							m = Math.min( m, solve( child ) );
						}

						return ret + m;
					}

				}

				public static class C implements Problem
				{

					@Override
					public void solve( InputStream inFile, PrintStream out )
							throws Exception
					{
						Scanner in = new Scanner( inFile );
						int T = in.nextInt();
						for( int case_num = 1; case_num <= T; ++case_num )
						{
							int n, k;
							n = in.nextInt();
							k = in.nextInt();
							double stocks[][] = new double[n][k];
							for( int i = 0; i < n; ++i )
							{
								for( int j = 0; j < k; ++j )
								{
									stocks[i][j] = in.nextDouble();
								}
							}
							Map< Integer, Set< Integer >> intersections = new HashMap< Integer, Set< Integer >>();
							for( int i = 0; i < n; ++i )
							{
								for( int j = 0; j < n; ++j )
								{
									if( i == j )
										continue;
									for( int z = 0; z < k - 1; ++z )
									{
										if( Line2D.linesIntersect( z,
												stocks[i][z], z + 1,
												stocks[i][z + 1], z,
												stocks[j][z], z + 1,
												stocks[j][z + 1] ) )
										{
											if( !intersections.containsKey( i ) )
												intersections
														.put( i,
																new HashSet< Integer >() );
											intersections.get( i ).add( j );
										}

									}
								}
							}
							Map< Integer, List< Integer >> together = new HashMap< Integer, List< Integer >>();
							for( Integer z : intersections.keySet() )
							{
								for( Integer zk : together.keySet() )
								{
									for( Integer lol : together.get( zk ) )
									{
										if( lol == z )
											continue;
									}
								}
								together.put( z, new ArrayList< Integer >() );
								for( int i = 0; i < n; ++i )
								{
									if( !intersections.get( z ).contains( i ) )
									{
										together.get( z ).add( i );
									}
								}
							}
							int sol = Integer.MAX_VALUE;
							out.println( "Case #"
									+ case_num
									+ ": "
									+ solve( intersections,
											new HashSet< Integer >(), 0 ) );
						}

					}

					int solve( Map< Integer, Set< Integer >> intersections,
							Set< Integer > done, int k )
					{
						if( done.contains( k ) )
							return 0;
						done.add( k );
						if( !intersections.containsKey( k ) )
							return 0;
						int ret = 1;
						if( intersections.containsKey( k ) )
						{
							for( Integer z : intersections.get( k ) )
							{
								ret += solve( intersections, done, z );
							}
						}
						return ret;
					}

				}

				public static class D implements Problem
				{

					public double dist( int x, int y, int x1, int y2 )
					{
						return Math.sqrt( ( Math.pow( ( x1 - x ), 2 ) + Math
								.pow( y2 - y, 2 ) ) );
					}

					@Override
					public void solve( InputStream inFile, PrintStream out )
							throws Exception
					{
						Scanner in = new Scanner( inFile );
						int C = in.nextInt();
						for( int case_num = 1; case_num <= C; ++case_num )
						{
							int N = in.nextInt();
							int [] x = new int[N];
							int [] y = new int[N];
							int [] r = new int[N];
							for( int i = 0; i < N; ++i )
							{
								x[i] = in.nextInt();
								y[i] = in.nextInt();
								r[i] = in.nextInt();
							}
							double sol = 0;
							if( N == 1 )
								sol = ( double ) r[0];
							if( N == 2 )
							{
								sol = ( double ) Math.max( r[0], r[1] );
							}
							if( N == 3 )
							{
								double rad1 = dist( x[0], y[0], x[1], y[1] )
										+ r[0] + r[1];
								double rad2 = dist( x[1], y[1], x[2], y[2] )
										+ r[1] + r[2];
								double rad3 = dist( x[0], y[0], x[2], y[2] )
										+ r[0] + r[2];
								sol = Math.min( rad1, Math.min( rad2, rad3 ) ) / 2;

							}
							else
							{

							}

							out.println( "Case #" + case_num + ": " + sol );

						}

					}

				}
			}
		}

		public static class GCJ_2010
		{
			public static class Round2
			{
				public static class A implements Problem
				{

					@Override
					public void solve( InputStream in, PrintStream out )
							throws Exception
					{
						Scanner scanner = new Scanner( in );
						int T = scanner.nextInt();
						for( int case_num = 1; case_num <= T; ++case_num )
						{
							int k = scanner.nextInt();
							int d[][] = new int[k * 2][k];
							for( int i = 0; i < d.length; ++i )
								for( int j = 0; j < k; ++j )
									d[i][j] = -1;

							for( int i = 1; i <= 2 * k - 1; ++i )
							{
								int kn = i <= k ? k - i : i - k;
								for( int ki = 0; ki < kn; ++ki )
								{
									d[i - 1][ki] = scanner.nextInt();
								}
							}
							boolean v_symm[] = new boolean[k - 1];
							for( int i = 0; i < v_symm.length; ++i )
								v_symm[i] = true;
							for( int i = 0; i < v_symm.length; ++i )
							{
								for( int j = 0; j < k; ++j )
								{
									if( d[2 * k - ( i + 1 )][j] != d[i][j] )
									{
										v_symm[i] = false;
										break;
									}
								}
							}
							// for( int i =)
						}
					}
				}

				public static class B implements Problem
				{
					@Override
					public void solve( InputStream in, PrintStream out )
							throws Exception
					{
						Scanner scanner = new Scanner( in );
						int T = scanner.nextInt();
						for( int case_num = 1; case_num <= T; ++case_num )
						{
							int P = scanner.nextInt();
							int num_teams = 1 << P;
							int M[] = new int[num_teams];
							int prices[][] = new int[P][num_teams / 2];
							for( int i = 0; i < P; ++i )
								for( int j = 0; j < num_teams / 2; ++j )
									prices[i][j] = -1;
							for( int i = 0; i < num_teams; ++i )
								M[i] = scanner.nextInt();
							for( int i = 0; i < P; ++i )
							{
								int num_prices = 1 << ( P - i - 1 );
								for( int j = 0; j < num_prices; ++j )
									prices[i][j] = scanner.nextInt();

							}
						}
					}
				}

				public static class C implements Problem
				{
					long solve( int xd, int yd )
					{
						return Math.max( xd, yd ) + 1;
					}

					public static class box implements Comparable
					{
						Integer x1, x2, y1, y2;

						Integer area()
						{
							return ( x2 - x1 ) * ( y2 - y1 );
						}

						void paint_board( boolean [][] board )
						{
							for( int i = x1; i <= x2; ++i )
							{
								for( int j = y1; j <= y2; ++j )
								{
									board[i][j] = true;
								}
							}
						}

						boolean intersects( box b )
						{
							return ( b.x1 >= x1 && b.x1 <= x2 )
									|| ( b.y1 >= y1 && b.y1 <= y2 );
						}

						@Override
						public int compareTo( Object arg0 )
						{
							box b = ( ( box ) arg0 );
							Integer c = y1.compareTo( b.y1 );
							if( c != 0 )
								return c;
							return x1.compareTo( b.y1 );
						}
					}

					boolean [][] board = new boolean[1000000][1000000];
					boolean [][] board2 = new boolean[1000000][1000000];

					void break_up( ArrayList< box > boxes )
					{
						while( true )
						{
							boolean ok = true;
							for( int i = 0; i < boxes.size(); ++i )
							{
								for( int j = i + 1; j < boxes.size(); ++j )
								{
									box boxi = boxes.get( i );
									box boxj = boxes.get( j );

									if( boxi.intersects( boxj ) )
									{
										ok = false;
										if( boxi.y1 == boxj.y2 )
										{

										}

									}

								}

							}
							if( ok )
								break;
						}
					}

					long solve()
					{
						long ret = 0;
						int k = 1;
						boolean curr_board[][] = board2;
						boolean prev_board[][] = board;
						while( true )
						{
							// System.out.println( curr_board);
							boolean ok = true;

							for( int i = 1; i < board.length; ++i )
							{
								for( int j = 1; j < board.length; ++j )
								{
									curr_board[i][j] = prev_board[i][j];
									if( prev_board[i][j] )
									{
										ok = false;
										if( !( prev_board[i - 1][j] || prev_board[i][j - 1] ) )
										{
											// System.out.println( i + " " + j
											// );
											curr_board[i][j] = false;
										}
									}
									else
									{
										if( prev_board[i - 1][j]
												&& prev_board[i][j - 1] )
										{
											// System.out.println( i + " " + j
											// );
											curr_board[i][j] = true;
										}
									}

									// else curr_board[i][j] = prev_board[i][j];

								}
							}
							// System.out.println( "==============");
							if( ok )
								break;

							boolean [][] t = curr_board;
							curr_board = prev_board;
							prev_board = t;

							ret++;
						}
						return ret;
					}

					@Override
					public void solve( InputStream in, PrintStream out )
							throws Exception
					{
						Scanner scanner = new Scanner( in );
						int C = Integer.parseInt( scanner.nextLine() );
						for( int case_num = 1; case_num <= C; ++case_num )
						{
							System.out.println( case_num );
							for( int i = 0; i < 200; ++i )
								for( int j = 0; j < 200; ++j )
								{
									board[i][j] = false;
									board2[i][j] = false;
								}

							int R = scanner.nextInt();
							int X1[] = new int[R];
							int X2[] = new int[R];
							int Y1[] = new int[R];
							int Y2[] = new int[R];

							ArrayList< box > boxes = new ArrayList< box >();

							for( int i = 0; i < R; ++i )
							{
								X1[i] = scanner.nextInt();
								Y1[i] = scanner.nextInt();
								X2[i] = scanner.nextInt();
								Y2[i] = scanner.nextInt();

								box new_box = new box();
								new_box.x1 = X1[i];
								new_box.x2 = X2[i];
								new_box.y1 = Y1[i];
								new_box.y2 = Y2[i];

								boxes.add( new_box );
								new_box.paint_board( board );
								// new_box.paint_board( board2 );
							}

							Collections.sort( boxes );
							// Collections.reverse( boxes );

							out.println( "Case #" + case_num + ": " + solve() );
						}
					}
				}
			}

			public static class QualificationRound_2010
			{
				public static class FairWarning implements Problem
				{

					BigInteger GCD( Vector< BigInteger > v )
					{
						BigInteger answer = v.get( 0 ).gcd( v.get( 1 ) );
						for( int i = 2; i < v.size(); ++i )
						{
							answer = answer.gcd( v.get( i ) );
						}
						return answer;
					}

					@Override
					public void solve( InputStream in, PrintStream out )
							throws Exception
					{
						Scanner scanner = new Scanner( in );
						int C = scanner.nextInt();
						for( int case_num = 1; case_num <= C; ++case_num )
						{
							System.out.println( "Doing " + case_num );
							int N = scanner.nextInt();
							Vector< BigInteger > numbers = new Vector< BigInteger >();

							for( int i = 0; i < N; ++i )
							{
								numbers.add( scanner.nextBigInteger() );
							}

							Vector< BigInteger > arr = new Vector< BigInteger >();

							BigInteger answer = BigInteger.valueOf( 0 );

							if( N == 2 )
							{
								BigInteger t = numbers.get( 1 )
										.subtract( numbers.get( 0 ) ).abs();
								answer = t.subtract( numbers.get( 0 ).mod( t ) )
										.mod( t );
							}
							else
							{
								for( int i = 0; i < N; ++i )
								{
									for( int j = 0; j < N; ++j )
									{
										BigInteger t = numbers.get( 0 )
												.subtract( numbers.get( j ) )
												.abs();
										if( !t.equals( BigInteger.ZERO ) )
											arr.add( t );
									}
								}
								BigInteger gcd = GCD( arr );
								System.out.println( gcd );

								answer = gcd.subtract(
										numbers.get( 0 ).mod( gcd ) ).mod( gcd );

							}

							out.println( "Case #" + case_num + ": " + answer );
						}

					}

				}

				public static class SnapperChain implements Problem
				{

					@Override
					public void solve( InputStream in, PrintStream out )
							throws Exception
					{
						int snappers_power[] = new int[30];
						int snappers_on[] = new int[30];
						snappers_power[0] = snappers_on[0] = 1;
						for( int i = 1; i < 30; ++i )
						{
							snappers_on[i] = snappers_power[i - 1] + 1;
							snappers_power[i] = snappers_on[i]
									+ snappers_power[i - 1];
							// System.out.println( snappers_power[i]);
						}

						Scanner scanner = new Scanner( in );
						int T = scanner.nextInt();
						for( int case_num = 1; case_num <= T; ++case_num )
						{
							for( int i = 1; i < 30; ++i )
								snappers_on[i] = -1;

							int N, K;
							N = scanner.nextInt();
							K = scanner.nextInt();

							boolean on;
							if( K == 0 )
								on = false;
							else if( N == 1 )
								on = K % 2 != 0;
							else if( K == snappers_power[N - 1] )
								on = true;
							else
							{
								int j;
								for( j = 1; snappers_power[N - 1] * ( j + 1 )
										+ j < K; ++j )
									;
								if( ( snappers_power[N - 1] * ( j + 1 ) + j ) == K )
									on = true;
								else
									on = false;
							}
							out.println( "Case #" + case_num + ": "
									+ ( on ? "ON" : "OFF" ) );
						}
					}
				}

				public static class ThemePark implements Problem
				{

					long simpleSolve( long R, long k, int N, int g[] )
					{

						long money[] = new long[N];
						long len[] = new long[N];
						for( int i = 0; i < N; ++i )
							money[i] = len[i] = 0;

						long ret = 0;
						for( int i = 0; i < N; ++i )
						{
							int pos = i;
							while( money[i] + g[pos] <= k && len[i] < N )
							{
								money[i] += g[pos];
								len[i]++;
								pos = ( pos + 1 ) % N;
							}
						}

						int moves = 0;
						for( int i = 0; i < R; ++i )
						{
							ret += money[moves];
							moves = ( int ) ( ( moves + len[moves] ) % N );
						}
						return ret;
					}

					@Override
					public void solve( InputStream in, PrintStream out )
							throws Exception
					{
						Scanner scanner = new Scanner( in );

						int T = scanner.nextInt();
						for( int case_num = 1; case_num <= T; ++case_num )
						{
							long R = scanner.nextLong(), k = scanner.nextLong();
							int N = scanner.nextInt();
							int g[] = new int[N];
							long money_cycle[] = new long[N];
							long num_cycle[] = new long[N];
							for( int i = 0; i < N; ++i )
							{
								g[i] = scanner.nextInt();
								money_cycle[i] = 0;
								num_cycle[i] = 0;
							}
							long money = simpleSolve( R, k, N, g );

							out.println( "Case #" + case_num + ": " + money );
						}

					}

				}
			}

			public static class Round1A_2010
			{
				public static class MakeItSmooth implements Problem
				{

					@Override
					public void solve( InputStream in, PrintStream out )
							throws Exception
					{
						Scanner scanner = new Scanner( in );
						int T = scanner.nextInt();
						int line_num = 2;
						for( int case_num = 1; case_num <= T; ++case_num )
						{

							int D = scanner.nextInt(), I = scanner.nextInt(), M = scanner
									.nextInt(), N = scanner.nextInt();
							System.out.println( N );
							int answer = 0;

							int a[] = new int[N];
							for( int i = 0; i < N; ++i )
								a[i] = scanner.nextInt();

							out.println( "Case #" + case_num + ": " + answer );

							/*
							 * int d[][] = new int[N+1][N+1]; for( int i = 0; i
							 * < N; ++i )d[i][0]=i*D; for( int j = 0; j < N; ++j
							 * )d[0][j]=j*I; for( int i = 1; i <= N; ++i ) {
							 * for( int j = 1; j <= N; ++j ) { int diff =
							 * Math.abs( a[i-1]-a[j-1]); if( diff <= M) {
							 * d[i][j] = d[i-1][j-1]; } else { int del =
							 * d[i-1][j] + D; int ins = d[i][j-1] + I *(diff/M);
							 * int subs = Math.abs( a[i-1] - a[+1]); if( subs /
							 * 2 > M )subs=Integer.MAX_VALUE; else subs +=
							 * d[i-1][j-1]; int m = Integer.MAX_VALUE; m =
							 * Math.min( del, m ); m = Math.min( ins, m ); m =
							 * Math.min( subs, m ); d[i][j]=m; } } } for( int i
							 * = 0; i <N; ++i )System.out.println(
							 * Arrays.toString( d[i] )); out.println( "Case #" +
							 * case_num + ": " + d[N][N]);
							 */

						}

					}

					private int subs( int a, int b, int M )
					{
						int d = Math.min( a, b );
						int d1 = Math.max( a, b );
						return Math.abs( d1 - ( d + M ) );
					}

				}

				public static class Rotate implements Problem
				{
					static int [] dx = { 1, 1, 0, -1 };
					static int [] dy = { 0, 1, 1, 1 };

					private static void check( String board[], int K,
							boolean [] ret )
					{
						int N = board.length;
						ret[0] = ret[1] = false;
						for( int i = 0; i < N; ++i )
						{
							for( int j = 0; j < N; ++j )
							{
								char t = board[i].charAt( j );

								if( t == '.' )
									continue;
								// System.out.println( "---" + i + ":"
								// +j+":"+t);
								boolean ok = true;
								int i1, j1;
								for( int k = 0; k < dx.length; ++k )
								{
									// System.out.println( k );
									ok = true;
									i1 = i;
									j1 = j;
									for( int k1 = 0; k1 < K - 1; ++k1 )
									{
										i1 += dx[k];
										j1 += dy[k];
										if( i1 >= N || j1 >= N || i1 < 0
												|| j1 < 0 )
										{
											ok = false;
											break;
										}
										char t1 = board[i1].charAt( j1 );
										// System.out.println( i1 + ":" +
										// j1+":"+t1);
										if( t != t1 )
										{
											ok = false;
											break;
										}
									}
									if( ok )
									{
										if( t == 'R' )
											ret[0] = true;
										if( t == 'B' )
											ret[1] = true;
										break;
									}
								}

							}
						}
					}

					private static String [] rotate( String [] board )
					{
						int N = board.length;
						String [] ret = new String[board.length];
						for( int i = 0; i < N; ++i )
						{
							String line = board[i];
							StringTokenizer tokenizer = new StringTokenizer(
									line, "." );
							line = "";
							while( tokenizer.hasMoreTokens() )
								line = line + tokenizer.nextToken();

							while( line.length() != N )
							{
								line = '.' + line;
							}

							ret[i] = line;
						}

						return ret;
					}

					@Override
					public void solve( InputStream in, PrintStream out )
							throws Exception
					{
						Scanner scanner = new Scanner( in );
						int T = Integer.parseInt( scanner.nextLine() );
						for( int case_num = 1; case_num <= T; ++case_num )
						{
							int N, K;
							String t = scanner.nextLine();
							N = Integer.parseInt( t.substring( 0,
									t.indexOf( ' ' ) ) );
							K = Integer
									.parseInt( t.substring( t.indexOf( ' ' ) + 1 ) );
							String [] board = new String[N];
							for( int i = 0; i < N; ++i )
								board[i] = scanner.nextLine();
							String [] rotated = rotate( board );
							boolean ret[] = new boolean[2];
							this.check( rotated, K, ret );
							// System.out.println( Arrays.toString(ret));
							// for( int i = 0; i <N; ++i)System.out.println(
							// rotated[i]);
							String answer = ret[0] && ret[1] ? "Both"
									: !( ret[0] || ret[1] ) ? "Neither"
											: ret[0] ? "Red" : "Blue";
							out.println( "Case #" + case_num + ": " + answer );
						}

					}

				}
			}

			public static class Round1B_2010
			{

				public static class A implements Problem
				{

					public void addToExist( Set< String > exist, String to_add )
					{
						String t = new String( to_add );
						while( !t.equals( "" ) )
						{
							exist.add( t );
							t = getParent( t );
						}
					}

					public String getParent( String dir )
					{
						return dir.substring( 0, dir.lastIndexOf( '/' ) );
					}

					public int mkDirs( String to_add, Set< String > exist )
					{
						int ret = 0;
						String t = new String( to_add );
						while( !exist.contains( t ) && !( t.equals( "" ) ) )
						{
							++ret;
							exist.add( t );
							t = getParent( t );
						}
						return ret;
					}

					@Override
					public void solve( InputStream in, PrintStream out )
							throws Exception
					{
						Scanner scanner = new Scanner( in );
						int T = Integer.parseInt( scanner.nextLine() );
						for( int case_num = 1; case_num <= T; ++case_num )
						{
							int N, M;
							String t = scanner.nextLine();
							N = Integer.parseInt( t.substring( 0,
									t.indexOf( ' ' ) ) );
							M = Integer
									.parseInt( t.substring( t.indexOf( ' ' ) + 1 ) );
							Set< String > exist = new HashSet< String >();
							Set< String > create = new HashSet< String >();
							for( int i = 0; i < N; ++i )
							{
								addToExist( exist, scanner.nextLine() );

							}
							for( int j = 0; j < M; ++j )
							{
								create.add( scanner.nextLine() );
							}
							int ret = 0;
							for( String to_add : create )
							{
								ret += mkDirs( to_add, exist );
							}
							out.println( "Case #" + case_num + ": " + ret );
						}
					}

				}

				public static class B implements Problem
				{
					@Override
					public void solve( InputStream in, PrintStream out )
							throws Exception
					{
						Scanner scanner = new Scanner( in );
						int C = scanner.nextInt();
						for( int case_num = 1; case_num <= C; ++case_num )
						{
							int N, K, B, T;
							N = scanner.nextInt();
							K = scanner.nextInt();
							B = scanner.nextInt();
							T = scanner.nextInt();

							int x[] = new int[N];
							int v[] = new int[N];
							double t[] = new double[N];
							boolean chicken[] = new boolean[N];
							int slow[] = new int[N];
							int passed = 0;

							for( int i = 0; i < N; ++i )
								x[i] = scanner.nextInt();
							for( int i = 0; i < N; ++i )
								v[i] = scanner.nextInt();

							for( int i = 0; i < N; ++i )
							{
								chicken[i] = false;
								t[i] = ( ( double ) Math.abs( x[i] - B ) )
										/ ( double ) v[i];
								if( t[i] <= ( double ) T )
								{
									chicken[i] = true;
									passed++;
								}
							}

							String answer = "";

							if( passed < K )
							{
								answer = "IMPOSSIBLE";
							}
							else
							{
								for( int i = 0; i < N; ++i )
								{
									int cnt = 0;
									for( int j = i + 1; j < N; ++j )
									{
										if( !chicken[j] )
											++cnt;
									}
									slow[i] = cnt;
								}
								int ret = 0;
								int zomg = 0;
								for( int i = N - 1; i >= 0; --i )
								{
									if( chicken[i] )
									{
										ret += slow[i];
										++zomg;
									}
									if( zomg == K )
										break;
								}
								answer = Integer.toString( ret );
							}
							out.println( "Case #" + case_num + ": " + answer );
						}

					}

				}

				public static class C implements Problem
				{

					HashMap< TreeSet< Integer >, Integer > mem = new HashMap< TreeSet< Integer >, Integer >();

					int getRank( TreeSet< Integer > set, int n )
					{
						int ret = 1;
						for( Integer k : set )
						{
							if( k == n )
								return ret;
							++ret;
						}
						return ret;
					}

					boolean ok( TreeSet< Integer > set, int n )
					{
						while( n != 1 )
						{
							int rank = getRank( set, n );
							if( rank == 1 )
								return true;
							// System.out.println( rank );
							if( !set.contains( rank ) )
								return false;
							n = rank;
						}
						return true;
					}

					/*
					 * int waysi( TreeSet<Integer> set, int size, int n ) {
					 * while( set.size() < n - 2 ) {
					 * 
					 * }
					 * 
					 * }
					 */
					@Override
					public void solve( InputStream in, PrintStream out )
							throws Exception
					{
						Scanner scanner = new Scanner( in );
						int T = scanner.nextInt();
						for( int case_num = 1; case_num <= T; ++case_num )
						{
							int n = scanner.nextInt();
							TreeSet< Integer > set = new TreeSet< Integer >();

							for( int i = 2; i <= n; ++i )
								set.add( i );
							System.out.println( ok( set, n ) );
							int answer = ways( set, n );

							out.println( "Case #" + case_num + ": " + answer );
						}
					}

					int ways( TreeSet< Integer > set, int n )
					{
						if( mem.containsKey( set ) )
							return 0;
						if( set.size() == 0 )
							return 0;
						int ret = ok( set, n ) ? 1 : 0;
						// System.out.println( set.size());

						TreeSet< Integer > nset;
						// System.out.println( set + " = " + ret );

						// if( ret == 0 )return 0;
						for( Integer k : set )
						{
							if( k == n )
								continue;
							nset = ( TreeSet< Integer > ) set.clone();
							nset.remove( k );

							int t = ways( nset, n );
							ret += t;
							mem.put( nset, t );
						}
						return ret;
					}

				}
			}

			public static class Round1C_2010
			{
				public static class A implements Problem
				{
					public static class Wire implements Comparable
					{
						Integer A, B;

						public Wire( int A, int B )
						{
							this.A = A;
							this.B = B;
						}

						@Override
						public int compareTo( Object arg0 )
						{
							return A.compareTo( ( ( Wire ) arg0 ).A );
						}

					}

					@Override
					public void solve( InputStream in, PrintStream out )
							throws Exception
					{
						Scanner scanner = new Scanner( in );
						int T = scanner.nextInt();
						for( int case_num = 1; case_num <= T; ++case_num )
						{
							int N = scanner.nextInt();
							ArrayList< Wire > wires = new ArrayList< Wire >();
							for( int i = 0; i < N; ++i )
								wires.add( new Wire( scanner.nextInt(), scanner
										.nextInt() ) );

							Collections.sort( wires );

							int ret = 0;
							for( int i = 0; i < wires.size(); ++i )
							{
								for( int j = i + 1; j < wires.size(); ++j )
								{
									if( wires.get( i ).B > wires.get( j ).B )
										++ret;
								}
							}

							out.println( "Case #" + case_num + ": " + ret );

						}

					}

				}

				public static class B implements Problem
				{
					@Override
					public void solve( InputStream in, PrintStream out )
							throws Exception
					{
						Scanner scanner = new Scanner( in );
						int T = scanner.nextInt();
						for( int case_num = 1; case_num <= T; ++case_num )
						{
							long L, P, C;
							L = scanner.nextLong();
							P = scanner.nextLong();
							C = scanner.nextLong();

							long ret = 0;
							long c = L * C;
							while( c < P )
							{
								ret++;
								c *= C;
							}
							long ret1 = 0;
							long xc = 1;
							while( xc <= ret )
							{
								xc *= 2;
								++ret1;
							}

							out.println( "Case #" + case_num + ": " + ret1 );
						}
					}
				}

				public static class C implements Problem
				{

					boolean [] convertBigInt( BigInteger num, int N )
					{
						int n = Math.max( num.bitLength(), N );
						boolean [] ret = new boolean[n];

						for( int i = 0; i < ret.length; ++i )
						{
							ret[i] = num.testBit( n - 1 - i );
						}
						if( num.bitLength() < n )
						{
							for( int i = 0; i < N - num.bitLength(); ++i )
								ret[i] = false;
						}

						return ret;
					}

					int testSize( boolean [][] board, boolean [][] done,
							int [][] group, int num, int x, int y, int size )
					{
						int ret = 0;
						int k = 2;

						return ret;
					}

					@Override
					public void solve( InputStream in, PrintStream out )
							throws Exception
					{
						Scanner scanner = new Scanner( in );
						int T = Integer.parseInt( scanner.nextLine() );
						for( int case_num = 1; case_num <= T; ++case_num )
						{
							String t = scanner.nextLine();
							int M, N;
							M = Integer.parseInt( t.substring( 0,
									t.indexOf( ' ' ) ) );
							N = Integer
									.parseInt( t.substring( t.indexOf( ' ' ) + 1 ) );
							boolean [][] board = new boolean[M][N];
							for( int i = 0; i < M; ++i )
							{
								board[i] = convertBigInt( new BigInteger(
										scanner.nextLine(), 16 ), N );
							}

						}

					}

				}

			}

		}

		public static class GCJ_2011
		{
			public static class QualificationRound
			{
				public static class A implements Problem
				{

					@Override
					public void solve( InputStream in, PrintStream out )
							throws Exception
					{
						Scanner scanner = new Scanner( in );
						int T = scanner.nextInt();

					}

				}

				public static class B implements Problem
				{

					@Override
					public void solve( InputStream in, PrintStream out )
							throws Exception
					{
						Scanner scanner = new Scanner( in );

					}

				}

				public static class C implements Problem
				{

					@Override
					public void solve( InputStream in, PrintStream out )
							throws Exception
					{
						Scanner scanner = new Scanner( in );

					}

				}
			}
		}

		public static class GCJ_2012
		{
			public static class QualificationRound
			{
				public static class B implements Problem
				{
					int N, S, p;
					LinkedList<Integer> t;
					
					int best( int x, int d )
					{
						int best = 0;
						for( int i = 0; i <= x; ++i )
						{
							for( int j = i; j <= x; ++j )
							{
								for( int k = j; k <= x; ++k )
								{
									if( k - i <= d )
									{
										if( i + j + k == x )
										{
											best = Math.max( best, k );
											dOut.println( String.format("%d, %d - %d %d %d", x, d, i, j, k));
										}
									}
								}
							}
						}
						return best;
					}
					
					int solve( )
					{
						int ret = 0;
						Collections.sort( t );
						Collections.reverse( t );
						for( Integer total : t )
						{
							int best1 = best(total, 1 );
							int best2 = best(total, 2 );
							dOut.println( String.format( "%d - %d %d", total, best1, best2));
							if( best1 >= p )
							{
								++ret;
							}
							else if( S > 0 && best2 >= p )
							{
								--S;
								++ret;
							}
						}
						
						return ret;
					}
					
					@Override
					public void solve( InputStream in, PrintStream out ) throws Exception
					{
						Scanner scanner = new Scanner( in );
						int T = scanner.nextInt();
						for( int CASE = 1; CASE <= T; ++CASE )
						{
							N = scanner.nextInt();
							S = scanner.nextInt();
							p = scanner.nextInt();
							t = new LinkedList<Integer>();
							for( int i = 0; i < N; ++i )
							{
								t.add( scanner.nextInt() );
							}
							dOut.println( String.format("Case #%d: %d %d %d", CASE, N, S, p));
							out.println( String.format( "Case #%d: %d", CASE, solve() ) );
						}
						
					}
					
				}
				
				public static class C implements Problem
				{
					static int numDigits = 0;
					static int divider;
					
					int rotate( int x )
					{
						int leadingNum = x / divider;
						int lastNum = x % 10;
						int y = x - leadingNum * divider;
						y *= 10;
						y += leadingNum;
						if( numDig( y ) < numDigits )
							y *= 10;
						return y;
					}
					
					int numDig( int x )
					{
						int ret = 0;
						while( x > 0 )
						{
							++ret;
							x /= 10;
						}
						return ret;
					}
					
					int solve( int A, int B )
					{
						numDigits = numDig( A );
						divider = ( int ) Math.pow( 10, numDigits - 1 );
						
						int ret = 0;
						for( int a = A; a < B; ++a )
						{
							int b = rotate( a );
							while( b != a )
							{
								if( b > a &&  b <= B )
									++ret;
								b = rotate(b);
							}
						}
						
						return ret;
					}

					@Override
					public void solve( InputStream in, PrintStream out )
							throws Exception
					{
						numDigits = 4;
						divider = ( int ) Math.pow(10,3);
						//out.println( rotate(rotate(3056)) );
						Scanner scanner = new Scanner( in );
						int T = scanner.nextInt();
						for( int CASE = 1; CASE <= T; ++CASE )
						{
							int A = scanner.nextInt();
							int B = scanner.nextInt();
							out.println( String.format( "Case #%d: %d", CASE, solve(A,B)));
						}
					}

				}
				
				public static class D implements Problem
				{
					int H, W, D;
					
					int solve( char grid[][] )
					{
						return -1;
					}
					

					@Override
					public void solve( InputStream in, PrintStream out ) throws Exception
					{
						Scanner scanner = new Scanner( in );
						int T = scanner.nextInt();
						for( int CASE = 1; CASE <= T; ++CASE )
						{
							H = scanner.nextInt();
							W = scanner.nextInt();
							D = scanner.nextInt();
							char [][] grid = new char[H][W];
							for( int i = 0; i < H; ++i )
							{
								String tt = scanner.next();
								for( int j = 0; j < tt.length(); ++j )
								{
									grid[i][j] = tt.charAt( j );
								}
							}
						}
						
					}
					
				}
			}
			
			public static class Round1A
			{
				public static class C implements Problem
				{
					int N;
					@Override
					public void solve( InputStream in, PrintStream out )
							throws Exception
					{
						Scanner sin = new Scanner(in);
						int T = sin.nextInt();
						for( int CASE = 1; CASE <= T; ++CASE )
						{
						
						}
						
					}
					
				}
			}
			
			public static class Round1B
			{
				public static class B implements Problem
				{

					@Override
					public void solve( InputStream in, PrintStream out )
							throws Exception
					{
						// TODO Auto-generated method stub
						
					}
					
				}
			}
			
			public static class Round2
			{
				
				public static class A implements Problem
				{
					int N, D;
					int [] d;
					int [] l;
					
					int newReach( int i, int j, int reach )
					{
						int dist = d[j] - d[i];
						if( dist <= reach )
						{
							return Math.min( dist, l[j] );
						}
						return -1;
					}
					
					boolean solve()
					{
						boolean ret = false;
						/*
						d[N] = D;
						l[N] = 0;
						int [] reach = new int[N+1];
						for( int i = 0; i <= N; ++i )
							reach[i] = -1;
						reach[0] = d[0];
						for( int i = 0; i < N ; ++i )
						{
							if( reach[i] > 0 )
							{
								for( int j = i + 1; j <= N; ++j )
								{
									int nr = newReach( i, j, reach[i] );
									reach[j] = Math.max(reach[j], nr );
								}
							}
						}
						ret = reach[N] > -1;
						*/
						
						
						int pos, reach;
						pos = 0;
						reach = d[0];
						while( pos < N )
						{
							int posNext = -1;
							int reachMax = -1;
							for( int i = pos + 1; i < N; ++i )
							{
								int nreach = newReach( pos, i, reach );
								if( nreach >= reachMax )
								{
									reachMax = nreach;
									posNext = i;
								}
							}
							if( posNext == -1 )
								break;
							dOut.println( String.format("%d, %d --> %d, %d", pos, reach, posNext, reachMax));
							pos = posNext;
							reach = reachMax;
							if( D <= reach + d[pos] )
								ret = true;
						}
						return ret;
					}
					
					@Override
					public void solve( InputStream in, PrintStream out )
					{
						Scanner sin = new Scanner( in );
						int T = sin.nextInt();
						for( int CASE = 1; CASE <= T; ++CASE )
						{
							dOut.println(String.format("Case %d", CASE));
							
							N = sin.nextInt();
							d = new int[N+1];
							l = new int[N+1];
							String dstr = "";
							for( int i = 0; i < N; ++i )
							{
								d[i] = sin.nextInt();
								l[i] = sin.nextInt();
								dstr += "(" + d[i] + ", " + l[i] + "), ";
							}							
							D = sin.nextInt();
							
							dOut.println( String.format( "%d, %d ", N, D) );
							dOut.println( dstr);
							
							out.println( String.format( "Case #%d: %s", CASE, solve() ? "YES" : "NO"));
						}
					}
				}
			}
		}

		public static class GCJ_2013
		{
			public static class QualificationRound
			{
				public static class A implements Problem
				{
					int dx[] = {1,-1,1,0};
					int dy[] = {1, 1,0,1};
					
					String solve( String[] board )
					{
						String ret="Game has not completed";
						boolean someEmpty = false;
						boolean done = false;
						boolean won = false;
						for( int i = 0; i < 4; ++i )
						{
							for( int j = 0; j < 4; ++j )
							{
								char c = board[i].charAt( j ); 
								if( c == '.' )
								{
									someEmpty = true;
								}
								else
								{
									for (int k = 0; k < 4; ++k )
									{
										int ii = i + dx[k];
										int jj = j + dy[k];
										int cnt = 1;
										while( ii >= 0 && ii < 4 && jj >= 0 && jj < 4 )
										{
											char cc = board[ii].charAt( jj );
											if( c == 'T' )
											{
												c = cc;
											}
											else
											{
												if( cc != 'T' )
													if(cc != board[ii-dx[k]].charAt(jj-dy[k]))
														break;
											}
											++cnt;
											ii += dx[k];
											jj += dy[k];
										}
										if( cnt == 4 )
										{
											ret = c == 'X' ? "X won" : "O won";
											won = done = true;
											break;
										}
									}
								}
								if( done )
									break;
							}
							if( done )
								break;
						}
						if( ! won && ! someEmpty )
							ret = "Draw";
						return ret;
					}
					
					@Override
					public void solve( InputStream in, PrintStream out )
							throws Exception
					{
						Scanner scanner = new Scanner(in);
						int T = scanner.nextInt();
						dOut.println( T );					
						for( int CASE = 1; CASE <= T; ++CASE )
						{
							String board [] = new String[4];
							scanner.nextLine();
							for( int i = 0; i < 4; ++i )
							{
								board[i] = scanner.nextLine();
								dOut.println( board[i] );
							}
							String ans = String.format( "Case #%d: %s", CASE, solve(board) );
							dOut.println( ans );
							out.println(ans);
						}
						
					}
					
				}
				
				public static class B implements Problem
				{
					boolean checkRow( int i, int j, int board[][], int N, int M, int maxRow[], int maxCol[] )
					{					
						int n = board[i][j];
						int nn = board[i][maxRow[i]];
						return nn <= n;
						/*
						for( int jj = 0; jj < M; ++jj  )
						{
							if( board[i][jj] > n )
								return false;
						}
						*/
						
						
					//	return true;
					}
					
					boolean checkCol( int i, int j, int board[][], int N, int M, int maxRow[], int maxCol[] )
					{					
						int n = board[i][j];
						int nn = board[maxCol[j]][j];
						return nn <= n;
						/*
						for( int ii = 0; ii < N; ++ii  )
						{
							if( board[ii][j] > n )
								return false;
						}						
						return true;
						*/
					}
					
					boolean check( int i, int j, int board[][], int N, int M, int maxRow[], int maxCol[])
					{
						return checkRow(i,j,board,N,M, maxRow, maxCol) || checkCol(i,j,board,N,M, maxRow, maxCol);
					}
					
					boolean solve( int N, int M, int board[][], int [] maxRow, int[] maxCol)
					{
						boolean ret = true;
						/*
						for( int i = 0; i < N; ++i )
						{
							int j = minRow[i];
							if( ! check(i,j,board,N,M))
								return false;
						}
						for( int j = 0; j < M; ++j )
						{
							int i = minCol[j];
							if( ! check(i,j,board,N,M))
								return false;
						}
						*/
						
						for( int i = 0; i < N; ++i )
						{
							for( int j = 0; j < M; ++j )
							{
								if( ! check(i,j,board,N,M, maxRow, maxCol))
									return false;
							}
						}
						
						return ret;
					}
		
					@Override
					public void solve( InputStream in, PrintStream out )
							throws Exception
					{
						Scanner scanner = new Scanner( in );
						int T = scanner.nextInt();
						for( int CASE = 1; CASE <= T; ++CASE )
						{
							int N = scanner.nextInt();
							int M = scanner.nextInt();
							int a[][] = new int[N][M];
							int maxRow[] = new int[N];
							int maxCol[] = new int[M];
							for( int i = 0; i < N; ++i )
							{
								maxRow[i] = -1;
								int max = Integer.MIN_VALUE;
								for( int j = 0; j < M; ++j )
								{
									int n = scanner.nextInt();
									if(max <= n )
									{
										maxRow[i] = j;
										max = n;
									}
									a[i][j] = n;
								}
							}
							for( int j = 0; j < M; ++j )
							{
								maxCol[j] = -1;
								int max = Integer.MIN_VALUE;
								for( int i =0; i < N; ++i )
								{
									int n = a[i][j];
									if( max <= n )
									{
										maxCol[j] = i;
										max = n;
									}
								}
							}
							dOut.println( "=========");
							dOut.println( Arrays.toString(maxRow));
							dOut.println( Arrays.toString(maxCol));
							String ans = String.format("Case #%d: %s ", CASE, solve(N,M,a,maxRow,maxCol) ? "YES":"NO");
							out.println(ans);
						}
						
					}
					
				}
				
				public static class C implements Problem
				{
					
					public Set<Long> demSquares(long limit) 
					{

					    TreeSet<Long> result = new TreeSet<Long>();

					    for (int i = 0; i <= 9 && i <= limit; i++)
					    {
					    	long ii = i *i;
					    	if( isPalindrome(ii))
					    		result.add(ii);
					    }

					    boolean cont = true;
					    for (long i = 1; cont; i++) 
					    {
					        StringBuffer rev = new StringBuffer("" + i).reverse();
					        cont = false;
					        for (String d : "0123456789".split("")) 
					        {
					        	long n = Long.parseLong("" + i + d + rev);
					        	long nn = n*n;
					            if (n <= limit) 
					            {
					                cont = true;
					                if(isPalindrome(nn))
					                	result.add(nn);
					            }
					        }
					    }

					    return result;
					}

					boolean isPalindrome(String num)
					{
						int n = num.length()-1;
						for( int i = 0 ; i < n; ++i )
						{
							if( num.charAt(i) != num.charAt(n-i))
								return false;
						}
						return true;
					}
					
					boolean isPalindrome(long number)
					{
						return isPalindrome( Long.toString(number) );
						
					}

					@Override
					public void solve(InputStream in, PrintStream out)
							throws Exception 
					{
						Set<Long> demSquares = demSquares((long)Math.sqrt(10e15));
						for( Long l : demSquares )
						{
							dOut.println( l );
						}
						Scanner scanner = new Scanner(in );
						int T = scanner.nextInt();
						for( int CASE = 1; CASE <= T; ++CASE )
						{
							long A = scanner.nextLong();
							long B = scanner.nextLong();
							long cnt = 0;
							/*
							for( long i = 0; i <=B; ++i )
							{
								if( isPalindrome(i))
								{
									long ii = i * i;
									if( isPalindrome(ii) && ii <= B && ii >= A)
									{
										dOut.println( ii );
										cnt++;
									}
								}
							}
							*/
							
							for( Long i : demSquares )
							{
								if( i >= A && i <= B)
									++cnt;
							}
							out.println( String.format("Case #%d: %d", CASE, cnt));
						}
						
						
					}
					
				}
				
				public static class D implements Problem
				{
					public static class Chest
					{
						public Chest()
						{
							for( int i = 1; i <= 200; ++i )
							{
								k.put(i, 0);
							}
						}
						int i;
						int T,K;
						Map<Integer,Integer> k = new HashMap<Integer,Integer>();
					}
					
					LinkedList<Integer> canDo( int chest_i, HashMap<Integer,Integer> myKeys, Chest chests[], TreeMap<Integer,Chest> key2Chest, HashSet<Integer> visited, LinkedList<Integer> path )
					{
						int N = chests.length;
						visited.add(chest_i);
						path.add(chest_i);
						
						for( Integer key_i : chests[chest_i].k.keySet() )
						{
							dOut.println( key_i );
							myKeys.put( key_i, myKeys.get(key_i) + chests[chest_i].k.get(key_i));
						}
						
						if( visited.size() == N )
							return path;
						
						for( int i = 0; i < N; ++i )
						{
							if( i == chest_i ) 
								continue;
							if( visited.contains( i ))
								continue;
							if( myKeys.containsKey(chests[i].T))
							{
								LinkedList<Integer> ans = canDo(i, (HashMap<Integer,Integer>) myKeys.clone(), chests, key2Chest, visited,(LinkedList<Integer>)path.clone() );
								if( null != ans )
								{
									return ans;
								}
							}							
						}						
						return null;
						
					}

					@Override
					public void solve(InputStream in, PrintStream out)
							throws Exception 
					{
						Scanner scanner = new Scanner(in);
						int T = scanner.nextInt();
						
						for( int CASE = 1; CASE <= T; ++ CASE )
						{
							int K,N;
							K = scanner.nextInt();
							N = scanner.nextInt();
							HashMap<Integer,Integer> k = new HashMap<Integer,Integer>();
							for( int i = 1; i <= 200; ++i )
							{
								k.put(i, 0);
							}
							for( int i = 0; i < K; ++i )
								k.put( scanner.nextInt(), 1 );
							Chest chests[] = new Chest[N];
							TreeMap<Integer,Chest> key2Chest = new TreeMap<Integer,Chest>();
							for( int i = 0; i < N; ++i )
							{
								Chest chest = new Chest();
								chest.i = i;
								chest.T = scanner.nextInt();
								chest.K = scanner.nextInt();
								for( int j = 0; j < K; ++j )
								{
									//chest.k[j] = scanner.nextInt();
									chest.k.put( scanner.nextInt(), 1);
								}
								key2Chest.put( chest.T, chest);
								chests[i] = chest;
							}
							LinkedList<Integer>  ans = null;
							for( int i = 0; i < N; ++i )
							{
								ans = canDo(i, (HashMap<Integer,Integer>) k.clone(), chests, key2Chest, new HashSet<Integer>(), new LinkedList<Integer>());
								if( ans != null )
									break;
							}
							String answer = "";
							if( ans != null )
							{
								for( int i = 0; i < ans.size(); ++i )
								{
									answer += ans.get(i);
									answer += " ";
								}
							}
							else
							{
								answer = "IMPOSSIBLE";
							}
							out.println( String.format( "Case #%d: %s", CASE, answer ));
						}
						
					}
					
				}
			}
			
			public static class Round1A
			{
				public static class A implements Problem
				{

					@Override
					public void solve(InputStream in, PrintStream out)	throws Exception 
					{
						Scanner scanner = new Scanner(in);
						int T = scanner.nextInt();
						for( int CASE = 1; CASE <= T; ++CASE)
						{
							double r,t;
							r = scanner.nextDouble();
							t = scanner.nextDouble();
							double rr = r + 1;
							long cnt = 0;
							while(true)
							{
								double req = Math.PI * rr*rr - Math.PI * (rr-1) *(rr-1);
								//req /= Math.PI;
								if( req > t )
									break;
								t -= req;
								++cnt;								
								rr += 2;
							}
							out.println( String.format( "Case #%d: %d", CASE, cnt ) );
							
						}
						
					}
					
				}
				
				public static class B implements Problem
				{
					
					int findMax( int E, int R, int N, int [] v, int i, int EE )
					{
						if( E > EE )
							E = EE;
						if( i == N - 1 )
						{
							return E * v[i];
						}
						int ret = 0;
						for( int j = 0; j <= E; ++j )
						{
							int t = j * v[i] + findMax( E-j+R, R, N, v, i+1, EE );
							ret = Math.max(ret,t);
						}
						return ret;
						
					}

					@Override
					public void solve(InputStream in, PrintStream out)
							throws Exception 
					{
						
						
						Scanner scanner = new Scanner(in);
						int T = scanner.nextInt();
						for( int CASE = 1; CASE <= T; ++ CASE )
						{
							int E,R,N;
							E = scanner.nextInt();
							R = scanner.nextInt();
							N = scanner.nextInt();
							int v[] = new int [N];
							for( int i = 0; i < N; ++i )
								v[i] = scanner.nextInt();
							out.println(String.format("Case #%d: %d", CASE, findMax( E, R, N, v, 0, E )));
						}
						
					}
					
				}
				
				public static class C implements Problem
				{

					@Override
					public void solve(InputStream in, PrintStream out)
							throws Exception {
						// TODO Auto-generated method stub
						
					}
					
				}
				
				public static class D implements Problem
				{

					@Override
					public void solve(InputStream in, PrintStream out)
							throws Exception {
						// TODO Auto-generated method stub
						
					}
					
				}
			}
		}

	}

	public static class Util< T >
	{

		public static class Pair< T, U >
		{
			private final T first;
			private final U second;
			private transient final int hash;

			public Pair( T f, U s )
			{
				this.first = f;
				this.second = s;
				hash = ( first == null ? 0 : first.hashCode() * 31 )
						+ ( second == null ? 0 : second.hashCode() );
			}

			@Override
			public boolean equals( Object oth )
			{
				if( this == oth )
				{
					return true;
				}
				if( oth == null || !( getClass().isInstance( oth ) ) )
				{
					return false;
				}
				Pair< T, U > other = getClass().cast( oth );
				return ( first == null ? other.first == null : first
						.equals( other.first ) )
						&& ( second == null ? other.second == null : second
								.equals( other.second ) );
			}

			public T getFirst()
			{
				return first;
			}

			public U getSecond()
			{
				return second;
			}

			@Override
			public int hashCode()
			{
				return hash;
			}

		}

		public static class Primes
		{
			public static boolean [] primes = null;

			public static boolean [] prime_numbers( int lim )
			{
				if( primes != null )
					return primes;
				primes = new boolean[lim];
				for( int i = 0; i < lim; ++i )
					primes[i] = true;
				primes[0] = primes[1] = false;
				for( int k = 2; k < lim; ++k )
					if( primes[k] )
						for( int c = 2; c * k < lim; ++c )
							primes[c * k] = false;

				return primes;
			}

			public void testPrimes()
			{
				boolean [] p = prime_numbers( ( int ) 1e6 );
				for( int i = 0; i < 100; ++i )
					if( p[i] )
						System.out.println( i );
			}
		}

		public static class TrivialComporator< T > implements Comparator
		{
			public int compare( Object a, Object b )
			{
				if( a instanceof Comparable && b instanceof Comparable )
					return ( ( Comparable ) a ).compareTo( b );
				throw new IllegalArgumentException(
						"passed arguments are not Comparable!" );
			}
		}

		/**
		 * Convert number in given base given as a string into base 10.
		 * 
		 * @param numb
		 * @param base
		 * @return
		 */
		public static int convert( String numb, int base )
		{
			int ret = 0;
			int c = 0;
			for( int i = numb.length() - 1; i >= 0; --i )
			{
				ret += Math.pow( base, c ) * ( numb.charAt( i ) - 48 );
				++c;
			}
			return ret;
		}

		public static void main( String [] arg )
		{
			Integer [] a = { 0, 1, 2, 3 };
			reverseArray( a, 0, a.length );
			System.out.println( Arrays.toString( a ) );
		}

		public static boolean next_permutation( Comparable [] s )
		{
			int i = -1, j = 0;

			for( int x = s.length - 2; x >= 0; x-- )
				if( s[x].compareTo( s[x + 1] ) < 0 )
				{
					i = x;
					break;
				}

			if( -1 == i )
				return false;

			for( int x = s.length - 1; x > i; x-- )
				if( s[x].compareTo( s[i] ) > 0 )
				{
					j = x;
					break;
				}

			// Swapping elements pointed by i and j;
			swap( s, i, j );

			// Reversing elements after i

			reverseArray( s, i + 1, s.length - ( i + 1 ) );
			return true;
		}

		public static < T > boolean next_permutation( T [] s,
				Comparator< T > comp )
		{

			int i = -1, j = 0;

			for( int x = s.length - 2; x >= 0; x-- )
				if( comp.compare( s[x], s[x + 1] ) < 0 )
				{
					i = x;
					break;
				}

			if( -1 == i )
				return false;

			for( int x = s.length - 1; x > i; x-- )
				if( comp.compare( s[x], s[i] ) > 0 )
				{
					j = x;
					break;
				}

			// Swapping elements pointed by i and j;
			swap( s, i, j );

			// Reversing elements after i

			reverseArray( s, i + 1, s.length - ( i + 1 ) );
			return true;
		}

		public static < T > void reverseArray( T [] a, int start, int length )
		{
			int end = start + length - 1;
			while( start < end )
			{
				swap( a, start++, end-- );
			}
		}

		public static String Stream2String( InputStream is ) throws IOException
		{
			String ret = "";
			while( is.available() > 0 )
			{
				byte [] buff = new byte[is.available()];
				is.read( buff );
				String t = new String( buff );
				ret += t;
			}
			return ret;
		}

		public static < T > void swap( T [] a, int i, int k )
		{
			T t = a[i];
			a[i] = a[k];
			a[k] = t;
		}

	}

	/**
	 * @param args
	 * @throws IOException
	 */
	public static void main( String [] args )
	{
		try
		{
			solveProblem(
					new Problems.GCJ_Problems.GCJ_2013.Round1A.B(),
					"input.in", "output.txt" );
		}
		catch( Exception e )
		{
			e.printStackTrace();
		}
	}

	public static void solveProblem( Problem prob, String input_file,
			String output_file ) throws Exception
	{
		boolean gcj_problem = true;

		PrintStream out;
		InputStream in;
		if( prob instanceof acm_problem )
		{
			in = System.in;
			out = System.out;
			gcj_problem = false;
		}
		else
		{
			in = new FileInputStream( input_file );
			if( !( prob instanceof facebook_problem ) )
			{
				FileOutputStream ofs = new FileOutputStream( output_file );
				out = new PrintStream( ofs );
			}
			else
			{
				out = System.out;
				gcj_problem = false;
			}
		}

		long start = System.currentTimeMillis();
		prob.solve( in, out );
		long end = System.currentTimeMillis();
		double duration = ( ( double ) ( end - start ) ) / 1e3;

		if( gcj_problem )
			System.out.println( "Problem was solved in " + duration
					+ " seconds." );
	}
}