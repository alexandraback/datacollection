import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Locale;
import java.util.Scanner;


public class PbD {

	public static void main(String[] args) {
		
		FileReader fr = null ;
    	Scanner sc = null;
    	int n_cases = 0;
    	
    	Locale.setDefault(Locale.US);
    	
    
    	try{
    		fr = new FileReader(args[0]);
    		sc = new Scanner(fr);
    		
    		if (sc.hasNextInt()) n_cases = sc.nextInt();
    		
    		for (int i=0;i<n_cases;i++){
    			
    			ArrayList<Double> l1 = new ArrayList<Double>();
    	    	ArrayList<Double> l2 = new ArrayList<Double>();
    			
    			int n = sc.nextInt();
    			   			
    			for(int j=0;j<n;j++){
    				l1.add(sc.nextDouble());
    			}
    			for(int j=0;j<n;j++){
    				l2.add(sc.nextDouble());
    			}
    			
    			Collections.sort(l1);
    			Collections.sort(l2);
    			
    			ArrayList<Double> l1_deceit = new ArrayList<Double>(l1);
    			ArrayList<Double> l2_deceit = new ArrayList<Double>(l2);
    			int size_d = n;
    			int d_pts = 0;
    			
    			while(size_d > 0 && l1_deceit.get(size_d-1)>l2_deceit.get(0)){
    				double temp = l2_deceit.get(0);
    				int idx = Collections.binarySearch(l1_deceit,temp);
    				l1_deceit.remove(-1-idx);
    				l2_deceit.remove(0);
    				size_d--;
    				d_pts++;
    			}
    			
    			int size_w = n;
    			
    			while(size_w > 0 && l1.get(0)<l2.get(size_w-1)){
    				double temp = l1.get(0);
    				l1.remove(0);
    				int idx = Collections.binarySearch(l2,temp);
    				l2.remove(-1-idx);
    				size_w--;
    			}
    			
    			System.out.println("Case #"+(i+1)+": "+d_pts+" "+size_w);
    		}
    		
    	} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
    	finally{
    		if(sc != null) sc.close();
    		if(fr != null)	try {fr.close();} catch (Exception e) {}
    	}
       	

	}

}
