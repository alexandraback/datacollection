import java.util.List;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.text.NumberFormat;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;


public class Google3A {
	public String szamol(Integer n, int[][] graf){
		boolean van=false;
		int i=0;
		while (!van && i<n){
			List<Integer> adj=new ArrayList<Integer>();
			int j=0;
			adj.add(i);
			int oldsize=-1;
			
			while (!van && oldsize!=adj.size()){
				if (oldsize==-1) oldsize=0;
				Integer[] z=adj.toArray(new Integer[adj.size()]);
				List<Integer> ujadj=new ArrayList<Integer>(adj);
				for (int alma=oldsize; alma<z.length && !van; alma++)
				{
					Integer a=z[alma];
					for (int m=1; m<=graf[a][0] && !van; m++){
						if (ujadj.contains(graf[a][m])) van=true;
						else ujadj.add(graf[a][m]);
					}
					
				}
				oldsize=adj.size();
				adj=ujadj;
			}
			i++;
		}
		return (van)?"Yes":"No";
	}
	public static void main(String[] args) {
		Google3A a=new Google3A();
		//String filename="input.txt";
		//String filename="A-small-attempt1.in";
		//
	
		
		String filename="A-large.in";
		String thisLine;
		try {
			BufferedReader br = new BufferedReader(new FileReader(filename));
			BufferedWriter bw= new BufferedWriter(new FileWriter(filename+".out"));
			thisLine=br.readLine();
			Integer tnum=Integer.parseInt(thisLine);
		     for(int i=0;i<tnum;i++) { // while loop begins here
		    	 	System.out.println(i);
		    	 	thisLine=br.readLine();
		    	 	Integer n=Integer.parseInt(thisLine);
		    	 	int [][] graf=new int[n][n+1];
		    	 	for (int j=0;j<n;j++){
		    	 		thisLine=br.readLine();
		    	 		if (thisLine.indexOf(' ')<0) continue;
		    	 		Integer m=Integer.parseInt(thisLine.substring(0, thisLine.indexOf(' ')));
		    	 		thisLine=thisLine.substring(thisLine.indexOf(' ')+1);
		    	 		graf[j][0]=m;
		    	 		for (int k=0; k<m-1; k++){
		    	 			Integer akt=Integer.parseInt(thisLine.substring(0, thisLine.indexOf(' ')));
			    	 		thisLine=thisLine.substring(thisLine.indexOf(' ')+1);
			    	 		graf[j][k+1]=akt-1;
		    	 		}
	    	 			Integer akt=Integer.parseInt(thisLine);
		    	 		graf[j][m]=akt-1;
		    	 	}
		           //System.out.println("Case #"+(i+1)+": "+a.szamol(n,graf)+"\n");
		           bw.write("Case #"+(i+1)+": "+a.szamol(n,graf)+"\n");
		         } // end while 
		        // end try
		     br.close();
		     bw.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}


	}

}
