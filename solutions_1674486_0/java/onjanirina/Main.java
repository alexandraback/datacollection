import java.io.*;
import java.util.*;

/**
 * */
public class Main {

	public class TestClass{
		public int id;
		public boolean bResult=false; 
		public Map<Integer, TestClass> map=null;
		public Set<Integer> setParents=Collections.synchronizedSet( new HashSet<Integer>());
		public Set<Integer> setChildren=Collections.synchronizedSet( new HashSet<Integer>());
		
		public TestClass( int id){
			this.id=id; }
		
		public boolean addChildren( Integer idChild){
			if( this.setChildren.contains( idChild))
				return true;
			
			Iterator<Integer> iterParent=this.setParents.iterator();
			while( iterParent.hasNext()){
				TestClass cParent=this.map.get( iterParent.next());
				if( cParent.addChildren(idChild))
					return true; }
			
			this.setChildren.add( idChild);
			return false; }
	}
	public TestClass createTestClass( int id){
		return new TestClass( id); }
	
	/**
	 * */
	public static void main( String[] args){
		
		try {
		
			Main m=new Main();
			LineNumberReader reader=new LineNumberReader( new FileReader( new File( args[ 0].trim())));
			PrintWriter printer=new PrintWriter( new FileWriter( args[ 1].trim()));
			
			Integer nTestCase=Integer.valueOf( reader.readLine().trim());
			for( int n=0; n!=nTestCase; n++){
				
				Integer nClasses=Integer.valueOf( reader.readLine().trim());
				Boolean bResult=false; 
				Map<Integer, TestClass> mapClasses=Collections.synchronizedMap( new HashMap<Integer, TestClass>());
				for( int i=0; i!=nClasses; i++){
					TestClass c=m.createTestClass( i+ 1);
					String strClass[]=reader.readLine().split( " ");
					if( strClass.length>1){
						for( int ci=1; ci!=strClass.length; ci++)
							c.setParents.add( Integer.valueOf( strClass[ ci].trim())); }
					c.map=mapClasses;
					mapClasses.put( c.id, c); }
				
				Iterator<Integer> iter=mapClasses.keySet().iterator();
				while( iter.hasNext() && !bResult){
					TestClass c=mapClasses.get(iter.next());
					Iterator<Integer> iterParent=c.setParents.iterator();
					while( iterParent.hasNext() && !bResult){
						TestClass cParent=mapClasses.get(iterParent.next());
						bResult=cParent.addChildren( c.id); }}
				
				printer.println( "Case #"+( n+1)+": "+( bResult? "Yes": "No")); 
				System.out.println( "Case #"+( n+1)+": "+( bResult? "Yes": "No")); }
						
			printer.close();
			
		} catch ( Exception e) {
			
			e.printStackTrace();
		}		
	}
}
