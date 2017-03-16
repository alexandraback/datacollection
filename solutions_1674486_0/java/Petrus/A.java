
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.*;

public class A {
	public void solve( Scanner sc, PrintWriter pw ) {
		int tests = sc.nextInt( ); sc.nextLine( );
		for ( int i = 0 ; i < tests; i++ ) {
			
			HashMap<Integer, Cls> classMap = new HashMap<Integer, Cls>( );

			int n = sc.nextInt( );
			for ( int j=0; j < n; j++ ) {
				Cls c = new Cls( );
				c.id = (j+1);
				classMap.put( c.id, c );
			}
			for ( int j=0; j < n; j++ ) {
				Cls currentClass = classMap.get( (j+1) );
				int classes = sc.nextInt( );
				for ( int k=0; k < classes; k++ ) {
					int inheritsFrom = sc.nextInt( );
					Cls parentClass = classMap.get( (inheritsFrom) );
					currentClass.parents.add(parentClass);
					parentClass.children.add(currentClass);
				}
				
			}
			boolean diamond = false;
			all: for ( int j=0; j < n; j++ ) {
				Cls currentClass = classMap.get( (j+1) );
				String[] path = currentClass.toString( ).split( "," );
				HashSet<String> finalParents = new HashSet<String>( );
				for( String s : path ) {
					String p = s.split( " " )[0];
					if ( finalParents.contains( p ) ) {
						diamond = true;
						break all;
					} else {
						finalParents.add( p );
					}
				}
			}
			pw.print( "Case #" + (i+1) + ": " + ((diamond)?"Yes":"No") );
			pw.println( );
			pw.flush( );
		}
	}

	public static void main ( String[] args ) throws IOException {
		Scanner sc = new Scanner(new FileReader("A-small-attempt0.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("A-small-attempt0.out"));
		new A( ).solve( sc, pw );
		pw.close( );
		sc.close( );
	}
}
class Cls {
	public int id = -1;
	public ArrayList<Cls> parents = new ArrayList<>( );
	public ArrayList<Cls> children = new ArrayList<>( );
	public String toString( ) {
		String s = "";
		for ( Cls c : parents ) {
			String[] path = c.toString( ).split( "," );
			for ( String s2 : path ) {
				s+= s2 + " " + id + ",";
			}
		}
		if ( parents.size() > 0 ) {
			s = s.substring(0, s.length( )-1);
		} else {
			s = "" + id;
		}
		return s;
	}
}