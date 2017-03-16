package b;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map.Entry;
import java.util.Map;

public class EjB {
	public static void main(String[] args) {

        ArrayList<String> list = new ArrayList<String>();

        try {

            FileReader fileReader =  new FileReader("B-small-attempt0.in");

            BufferedReader br = new BufferedReader(fileReader);
            
            int testCases = Integer.valueOf(br.readLine());
      
            for (int i = 1; i <= testCases; i++){
            	int N = Integer.valueOf(br.readLine());
            	Map<Long,Long> hash = new HashMap<Long,Long>();
            	for ( int j = 0; j < (2*N)-1; j++){            		
            		String[] stSplited = br.readLine().split(" ");
        			for (int k = 0; k < N ; k++){
	            		if ( !hash.containsKey(Long.valueOf(stSplited[k]))) {
	        				hash.put(Long.valueOf(stSplited[k]), (long) 1 );
	        			}else {
	        				hash.put(Long.valueOf(stSplited[k]), hash.get(Long.valueOf(stSplited[k])) + 1);
	        			}
        			}
            	}
            	
            	list.add(procesar(hash));
            	//System.out.println("TestCase : "+String.valueOf(i)+"  : "+stSplited[0]+" Columns : "+stSplited[1]+" Width : "+stSplited[2]);
            }

            br.close();
            writeFile(list);
        } catch(Exception ex) {
            System.out.println("Error reading file");                  

        }
	}
	
	public static String procesar(Map<Long,Long> hash) {
		List<Long> array = new ArrayList<Long>();
		
	    Iterator<Entry<Long, Long>> it = hash.entrySet().iterator();
	    while (it.hasNext()) {
	        Map.Entry pair = (Map.Entry)it.next();
	        if ((Long) pair.getValue() % 2 != 0){
	        	array.add((Long) pair.getKey());
	        }
	       it.remove();
	    }
	    
	    Collections.sort(array);
	    
	    String salida = "";
	    for (int i = 0; i < array.size(); i++){
	    	salida = salida.concat(String.valueOf(array.get(i)));
	    	if (i != array.size()-1){
	    		salida = salida.concat(" ");
	    	}
	    }
		
		return salida;
	}

	
	public static void writeFile (ArrayList<String> l){
		try {
			PrintWriter writer = new PrintWriter("output_b_small.txt", "UTF-8");
			for (int i = 0; i < l.size() ; i++ ){
				writer.println("Case #"+String.valueOf(i+1)+": "+l.get(i));
			}
			writer.close();
		} catch (Exception e){
			 System.out.println("Error writing file");
		}
	}


}