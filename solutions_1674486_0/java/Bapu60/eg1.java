import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;
import java.util.StringTokenizer;


public class eg1 {

	/**
	 * @param inheritmatrix 
	 * @param hm 
	 * @param numClasses 
	 * @param args
	 */
	static boolean add_parents(int parent , int[][] inheritmatrix, HashMap hm ){
		if(hm.containsKey(parent))
			return true;
		else
			hm.put(parent, 1);
		
		if(inheritmatrix[parent][0] == 0)
			return false;
		
		else{
			int grand = inheritmatrix[parent][0];
			for(int j=1; j <= grand ; j++){
				boolean result = add_parents(inheritmatrix[parent][j],inheritmatrix,hm );
			    if(result == true)
			    	return result;
			}
		}
		return false;
	}
	
	
		static boolean process(int[][] inheritmatrix, int numClasses){
			
			HashMap hm = new HashMap(); 
			boolean diamond = false;
			for(int i=1;i<=numClasses;i++){
			    
				int numParents = inheritmatrix[i][0];
				 
				for(int j=1;j<=numParents;j++)
				{         
					diamond = add_parents(inheritmatrix[i][j] ,inheritmatrix,hm);
				    if(diamond)
					   return diamond;
				}
				
				hm.clear();
			}
			return false; 
		}
		
			
		
		/**
		 * @param args
		 */
		public static void main(String[] args) {
			
			BufferedReader in = null;
			
			BufferedWriter out = null;
			FileWriter fstream=null;
			try {
				in = new BufferedReader(new FileReader("c:\\personal\\input.in"));
				
				try {
					fstream = new FileWriter("c:\\personal\\output.txt");
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				out = new BufferedWriter(fstream);
			} catch (FileNotFoundException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
	        int num =0;
			try {
				String s = in.readLine();
				 num =  Integer.parseInt(s);
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			
			
			for(int i=1;i<=num;i++){
				
				int numClasses =0;
				try {
					StringTokenizer st = new StringTokenizer(in.readLine());
					if (st.hasMoreElements()) {
						numClasses = Integer.parseInt((String) st.nextElement());
					}
	                
					
					int[][] inheritmatrix = new int[1000][100];

					for(int j=1;j<=numClasses;j++){
						StringTokenizer st1 = new StringTokenizer(in.readLine());
						if (st1.hasMoreElements()) {
							int numParent = Integer.parseInt((String) st1.nextElement());
							inheritmatrix[j][0] = numParent;
							for(int l=1;l<=numParent;l++)
							     inheritmatrix[j][l] = Integer.parseInt((String) st1.nextElement());
						}		
					}
					
					boolean y = process(inheritmatrix,numClasses);
					
				    out.write("Case #" + i+": ");
				    if(y)
				       out.write("Yes");
				    else
				    	out.write("No");
				    out.newLine();
				    
				    
					
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				
				
			}
			
			try {
				out.close();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			  
			

		}

	

}
