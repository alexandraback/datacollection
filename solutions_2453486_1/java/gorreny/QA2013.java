import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class QA2013 {
	
	public void szamol(){
		//String filename="input.txt";
		//String filename="A-small-attempt0.in";
		String filename="A-large.in";
		String thisLine;
		try {
			BufferedReader br = new BufferedReader(new FileReader(filename));
			BufferedWriter bw= new BufferedWriter(new FileWriter(filename+".out"));
			thisLine=br.readLine();
			Integer tnum=Integer.parseInt(thisLine);
		    for(int i=0;i<tnum;i++) { // while loop begins here
		    	Integer[][] tabla=new Integer[4][4];
		    	Integer[] oszlopx=new Integer[4];
		    	Integer[] oszlopo=new Integer[4];
		    	Integer[] sorx=new Integer[4];
		    	Integer[] soro=new Integer[4];

		    	Integer atlo1x=0;
		    	Integer atlo1o=0;
		    	Integer atlo2x=0;
		    	Integer atlo2o=0;
		    	Boolean vanpont=false;
		    	for (int j=0;j<4;j++){
		    		oszlopx[j]=0;
		    		oszlopo[j]=0;
		    		sorx[j]=0;
		    		soro[j]=0;
		    	/*	for (int k=0;k<4;k++){
		    			tabla[j][k]=0;
		    		}*/
		    	}
		    	
		    	String result="";
		    	for (int j=0;j<4;j++){
		    	 	thisLine=br.readLine();
		    	 	char[] sor=thisLine.toCharArray();
		    	 	for (int k=0;k<4;k++){
		    	 		if (sor[k]=='.') vanpont=true;
		    	 		if (sor[k]=='T'){
		    	 			sorx[j]++;
		    	 			soro[j]++;
		    	 			oszlopx[k]++;
		    	 			oszlopo[k]++;
		    	 			if (k==j) {
		    	 				atlo1x++;
		    	 				atlo1o++;
		    	 			}
		    	 			if (k==3-j){
		    	 				atlo2x++;
		    	 				atlo2o++;
		    	 			}
		    	 		}
		    	 		if (sor[k]=='X'){
		    	 			sorx[j]++;
		    	 			oszlopx[k]++;
		    	 			if (k==j) {
		    	 				atlo1x++;
		    	 			}
		    	 			if (k==3-j){
		    	 				atlo2x++;
		    	 			}
		    	 		}
		    	 		if (sor[k]=='O'){
		    	 			soro[j]++;
		    	 			oszlopo[k]++;
		    	 			if (k==j) {
		    	 				atlo1o++;
		    	 			}
		    	 			if (k==3-j){
		    	 				atlo2o++;
		    	 			}
		    	 		}
		    	 	}
		    	}
		    	br.readLine();
		    	if (atlo1x==4 || atlo2x==4) result="X won";
		    	if (atlo1o==4 || atlo2o==4) result="O won";
		    	for (int j=0;j<4;j++){
			    	if (oszlopx[j]==4 || sorx[j]==4) result="X won";
			    	if (oszlopo[j]==4 || soro[j]==4) result="O won";		    		
		    	}
		    	if (result.length()==0){
		    		if (vanpont) result="Game has not completed";
		    		else result="Draw";
		    	}
		        bw.write("Case #"+(i+1)+": "+result+"\n");
		     } // end while 
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
	
	
	public static void main(String[] args) {
		new QA2013().szamol();

	}

}
