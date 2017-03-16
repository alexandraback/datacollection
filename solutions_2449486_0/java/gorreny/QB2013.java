import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class QB2013 {
	
	public void szamol(){
		//String filename="input.txt";
		String filename="B-small-attempt1.in";
		//String filename="B-large.in";
		String thisLine;
		try {
			BufferedReader br = new BufferedReader(new FileReader(filename));
			BufferedWriter bw= new BufferedWriter(new FileWriter(filename+".out"));
			thisLine=br.readLine();
			Integer tnum=Integer.parseInt(thisLine);
		    for(int db=0;db<tnum;db++) { // while loop begins here
		    	Integer n=0;
		    	Integer m=0;
		    	String result="";
	    		thisLine=br.readLine();
	    		try {
	    		Scanner scan=new Scanner(thisLine);
	    		n=scan.nextInt();
	    		m=scan.nextInt();
	    		System.out.println(db+":"+n+" "+m);
	    		}
	    		catch
	    		(Exception ex){
	    			System.out.println("hiba");
	    			System.out.println(thisLine);
	    			System.out.println(db);
	    		}
	    		if (n==1|| m==1){
	    			for (int k=0;k<n;k++) thisLine=br.readLine();
	    			bw.write("Case #"+(db+1)+": YES\n");
	    			continue;
	    		}
		    	Integer[][] tabla=new Integer[n][m];
		    	Integer[] maxx=new Integer[n];
		    	Integer[] maxy=new Integer[m];
		    	for (int i=0;i<m;i++){
		    		maxy[i]=0;
		    	}
		    	for (int i=0;i<n;i++){
		    		maxx[i]=0;
		    		thisLine=br.readLine();
		    		Scanner scanner=new Scanner(thisLine);
		    		for (int j=0;j<m;j++){
		    			tabla[i][j]=scanner.nextInt();
		    			if (tabla[i][j]>maxx[i]) maxx[i]=tabla[i][j];
		    			if (tabla[i][j]>maxy[j]) maxy[j]=tabla[i][j];
		    		}
		    	}
		    	result="YES";
		    	for (int i=0;i<n;i++){
		    		for (int j=0;j<m;j++){
		    			if (tabla[i][j]<maxx[i] && tabla[i][j]<maxy[j]) result="NO";
		    		}
		    	}
		    	bw.write("Case #"+(db+1)+": "+result+"\n");
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
		new QB2013().szamol();

	}

}
