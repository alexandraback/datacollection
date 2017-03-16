package pack1;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;
import java.util.Scanner;

public class Pogo {
	
	public static int [] vx = new int[]{0,1,0,-1}; 
	public static int [] vy = new int[]{1,0,-1,0};
	
	public static Map<String,Integer> marcat = new HashMap(); 
	public static Map<String,Integer> pas = new HashMap(); 
	
	public static void main ( String [] arg ) throws FileNotFoundException{
		Scanner s = new Scanner ( new File( "input" ) );
		System.setOut( new PrintStream ( new File("output" )));
		int cases = s.nextInt(); 
		
		for ( int c=1; c<=cases; c++ ){
			Queue<int[]> q = new LinkedList();
			int x = s.nextInt(); 
			int y = s.nextInt(); 
			
			marcat.clear(); 
			pas.clear(); 
			
			q.add( new int[]{0,0} );
			marcat.put(0+","+0, -1);
			pas.put( "0,0", 1);
			while ( q.size()>0 ){
				int [] current = q.poll();
				int cpas = pas.get( current[0] + ","+ current[1] );
			//	System.err.println( q.size() ); 
				if ( current[0] == x && current[1] == y ){
					System.out.print( "Case #"+c+": " );
					System.err.println( "Case #"+c+": " );
					List<String> sol = new ArrayList(); 
					while ( true ){
						int cp = pas.get( current[0] + "," + current[1] ) - 1;
						int dir = marcat.get( current[0] + "," + current[1] );
						if ( dir == -1 ) break; 
						
						if ( dir == 0 ){
							sol.add("N");
							current[1] -= cp; 
						}
						if ( dir == 1 ){
							sol.add("E");
							current[0] -= cp; 
						}
						if ( dir == 2 ){
							current[1] += cp; 
							sol.add("S");
						}
						if ( dir == 3 ){
							sol.add("W");
							current[0] += cp;
						}
					}
					for ( int i=0; i<sol.size(); i++ ){
						System.out.print( sol.get(sol.size() - i - 1) ); 
					}
					System.out.println(); 
					break; 
				}
				for ( int i=0; i<4; i++ ){
					int cx = current[0] + vx[i]*cpas; 
					int cy = current[1] + vy[i]*cpas; 
					String key = cx+","+cy; 
					if ( marcat.get(key) == null ){
						if ( Math.abs(cx)>300 || Math.abs(cy) > 300 ) {
							
						} else {
							marcat.put( key, i );
							pas.put(key, cpas+1);
							q.add( new int[]{cx,cy} );
						}
					}
				}
			}
			
		}
	}
}
