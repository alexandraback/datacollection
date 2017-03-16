import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;


public class Lawn {
	
	public static void main(String[] args) {

	try {
		BufferedReader br = new BufferedReader(new FileReader("B-large.in"));
		FileWriter fstream = new FileWriter("out.txt");
		BufferedWriter out = new BufferedWriter(fstream);
		ArrayList<String> result = new ArrayList<String>();

		int cases = Integer.parseInt(br.readLine());
		for (int i = 0;i <cases;i++){
			int thiscase = i+1;
			String nm = br.readLine();
			int n = Integer.parseInt(nm.split(" ")[0]);
			int m = Integer.parseInt(nm.split(" ")[1]);
			ArrayList<ArrayList<Integer>> lawn = new ArrayList<ArrayList<Integer>>();
        	for(int a = 0;a < n; a++){
        		lawn.add(new ArrayList<Integer>());
        		String[] row = br.readLine().split(" ");
        		for(int c = 0; c < m; c++){
        			lawn.get(a).add(Integer.parseInt(row[c]));
        		}
        	}
        	while (true){

        		if (lawn.isEmpty()){
        			result.add("Case #" + thiscase +": YES");
        			break;
        		}
        		
        		for(int r = 0; r < lawn.size(); r++){	        		
	        		for(int c = 0; c < lawn.get(0).size(); c++){
	       // 			System.out.print(lawn.get(r).get(c)+" ");
	        		}
	//        		System.out.println();
	        	}
        			
        		int min = Integer.MAX_VALUE;
        		int minr = 0;
        		int minc = 0;
        	   
        		for (int r = 0; r< lawn.size() ;r ++){
        			for (int c = 0; c<lawn.get(0).size();c ++){
        				if (lawn.get(r).get(c) < min){
        					min = lawn.get(r).get(c);
        					minr = r;
        					minc = c;
        				}
        			}
        		}

        //		System.out.println(minr + " " + minc);
        		
        		boolean rok = true; 
        		boolean cok = true;
        		int numr = 0;
        		int numc = 0;
        		// check min row
        		for (int c = 0; c< lawn.get(minr).size();c ++){
        			if (lawn.get(minr).get(c) == min){
        				numr ++;
        			}
        		}
       // 		System.out.println("r = "+minr+", c = "+minc+", min ="+min + ",numr =" + numr);
        		if (numr != lawn.get(0).size())
        			rok = false;
        		
        		// check min column
        		for (int r = 0;r<lawn.size();r ++){
        			if (lawn.get(r).get(minc) == min){
        				numc ++;
        			}
        		}
    //    		System.out.println("r = "+minr+", c = "+minc+", min ="+min + ",numc =" + numc);

        		if (numc != lawn.size())
        			cok = false;
        		
        		if (!rok && !cok){
        			result.add("Case #" + thiscase +": NO");
        			break;
        		}
        		
        		if (rok){
        		//	System.out.println("rok");
        			lawn.remove(minr);
        			continue;
        		}
        		
        		else if (cok){
        	//		System.out.println("cok");
        			for (int j =0;j<lawn.size();j++){
        				lawn.get(j).remove(minc);
        			}
        			continue;
        		}

        		if (!lawn.isEmpty())
        			continue;
        			
        	}
		}
		

	
	for (int i = 0;i<result.size();i++){
		out.write(result.get(i)+"\n");
	}
	br.close();
	out.close();
	}catch (Exception e) {
        System.err.println("Error:" + e.getMessage());
        e.printStackTrace();
    }
}

}
