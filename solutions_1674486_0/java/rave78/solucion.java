import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;


public class solucion {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
				try{
			 FileReader fr=new FileReader("A-small-attempt1.in"); 
		
			 BufferedReader  br = new BufferedReader (fr);
		     int numCases = Integer.parseInt(br.readLine());
		     BufferedWriter bw = new BufferedWriter(new FileWriter(new File("googleCodeJam.txt")));
		     int i;
		     

		     for(i=1; i<=numCases; i++ ){
		    	 int nodes = Integer.parseInt(br.readLine());
		    	 int path[][] = new int [nodes][nodes];
		    	 int numberLinks [] = new int[nodes];
		    	 ArrayList<Integer> lstZeros = new ArrayList<Integer>();
		    	 for (int j=1; j<=nodes; j++){
		    		 String linea = new String(br.readLine());
		    		 StringTokenizer palabraSeparation = new StringTokenizer(linea);
		    		 int links=Integer.parseInt(palabraSeparation.nextToken());
		    		 if (links ==0)
		    			 lstZeros.add(j-1);
		    		 else
		    			 numberLinks[j-1] = links;
		    		 for (int z=0; z<links;z++){
		    			 int index = Integer.parseInt(palabraSeparation.nextToken());
		    			 path[j-1][index-1] = 1;
		    			 
		    			 
		    		 }
		    	 }
		    	 
		    	 
		    	 
		    	 int roadToGoal=0;
		    	 for (int index_Links = 0; index_Links<numberLinks.length; index_Links++){
			    	 if (numberLinks[index_Links] > 0){
			    		 for (Integer temp:lstZeros){
			    			 //System.out.println(temp + " "+ index_Links);
				    		 int initial = temp;
					    	 int goal = index_Links;
					    	 roadToGoal = 0;
					    	 ArrayList<Integer> lstInteger = new ArrayList<Integer>();
					    	 lstInteger.add(initial);
					    	 
					    	 while (!lstInteger.isEmpty()){
					    		 int currentNode = lstInteger.remove(0);
					    		 for (int index = 0; index < nodes; index++){
					    			 if (path[index][currentNode]==1)
					    				 lstInteger.add(0, index);
					    		 }
					    		 if (currentNode == goal) roadToGoal++;
					    		 
					    		 if(roadToGoal>= 2){ 
					    			 
					    			 break;
					    		 }
					    	 }
					    	 if (roadToGoal>= 2) break;
				    	 }
			    	 }
			    	 if (roadToGoal>= 2) break;
		    	 }	 
		    	 String solution;
		    	 if (roadToGoal >= 2) 
		    		 solution = "Yes";
		    	 else
		    		 solution = "No";
		    	 

		    	 System.out.println("Case #" + i+": "+solution);
				 bw.write("Case #" + i+": "+solution);
				 bw.newLine();


				         
		     }
		     
		 bw.close();
		}catch (Exception e){//Catch exception if any
		    	  System.err.println("Error: " + e.getMessage());
		}
			  


	}

}
