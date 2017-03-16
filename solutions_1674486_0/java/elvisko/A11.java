import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.InputStreamReader;


public class A11 {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		
	    try{
    	    FileInputStream fstream = new FileInputStream("in.in");
    	    DataInputStream in = new DataInputStream(fstream);
    	        BufferedReader br = new BufferedReader(new InputStreamReader(in));
    	    String strLine;
    
    	    strLine = br.readLine();
    	    int T = Integer.valueOf(strLine);
 //   	    System.out.println(T);
    	    int N[] = new int[T];

    	    int M[][] = new int[T][1000];
    	    int r[][][] = new int[T][1000][1000];
    	    	    	    
    	    int t = 0;
    	    
    	    while ((strLine = br.readLine()) != null)   {
	    	    String[] ss = strLine.split(" ");
	    	    N[t] = Integer.valueOf(ss[0]);
	  //  	    System.out.println(N[t]);
	    	    for (int n = 0; n < N[t]; n++){
	    	    	strLine = br.readLine();
		    	    ss = strLine.split(" ");
		    	    M[t][n] = Integer.valueOf(ss[0]);
    	  //  	    System.out.print(M[t][n]+" ");
		    	    for (int i = 0; i < M[t][n]; i++) {
	    	    		r[t][n][i] = Integer.valueOf(ss[i+1])-1;
	    	    		
	    //	    	    System.out.print(r[t][n][i]+" ");
		    	    }
	   // 	    	System.out.println();
	    	    }
	    	    t++;
	    	     
    	    }
    	    
    	    
    	    
    	    
//    	    System.out.println(T);
	    boolean [][][] rel = new boolean[1000][1000][1000]; 
 	    for (t=0; t<T; t++)
    	    {
    	    	
 	    		for (int i=0; i<1000; i++)
 	    			for (int j=0; j<1000; j++){
 	    				for (int k=0; k<1000; k++)
 	    				rel[i][j][k] = false;
 	    			}
 	    	
 	    		
 	    		for (int n=0; n<N[t]; n++){
 	    			for (int i=0; i<M[t][n]; i++){
 	    				rel[n][r[t][n][i]][r[t][n][i]] = true; 	    				
 	    			}
 	    		}
 	    	
 	    		for (int i=0;i<N[t];i++){
 //	    			System.out.print(rel[0][1][i]+" ");
 	    		}
 	    		
 	    		boolean chg = true;
 	    		while (chg == true){
 	    			chg=false;
 	    			for (int i=0; i<N[t]; i++){
 	    				for (int j=0; j<N[t]; j++){
 	    					for (int p=0; p<N[t]; p++){
 	 	    					if (rel[i][j][p]) {
 	 	    						for (int k=0; k<N[t]; k++){
 	 	    							boolean c = rel[i][k][p];
 	 	    							for (int p1=0; p1<N[t]; p1++){
 	 	 	    							rel[i][k][p] = rel[i][k][p] || rel[j][k][p1];
 	 	    							}
 	 	    							if (c != rel[i][k][p]) {
 	 	    								chg = true;
 	 	    							}
 	 	    						}
 	    						
 	 	    					}
 	    					}
 	    				}
 	    			}
 	    			
 	    		}
    	    	
 	    		
 	    		String res = "No";
 	    		int tt = 0;
 	    		for (int i=0;i<N[t];i++){
 	    			for (int j=0; j<N[t];j++){
 	    				tt = 0;
 	    				for (int k=0; k<N[t];k++){
 	    					if (rel[i][j][k]) tt++;
 	    				}
 	    				if (tt>1) res ="Yes";
 	    				
 	    			}
 	    		}
 	    		
    	    	
	    	   	System.out.print("Case #");
    	    	System.out.print(t+1);
    	    	System.out.print(": ");
    	    	System.out.print(res);
    	    	
    	    	
    	    	System.out.println();
   	    		
    	    	
    	    }
    	    
    	    
    	    
    	    
    	    
    	    
    	    //Close the input stream
    	    in.close();
    	    }catch (Exception e){//Catch exception if any
    	      System.err.println("Error: " + e.getMessage());
    	    }
	   
	
	}

}
