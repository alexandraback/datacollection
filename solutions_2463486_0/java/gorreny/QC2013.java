import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.Scanner;


public class QC2013 {
	private Long[] palindromsquare;
	public Boolean isPalindrom(Long l){
		String s=l.toString();
		s= new StringBuffer(s).reverse().toString();
		Long k=Long.parseLong(s);
		return k.equals(l);
	}
	public void szamol(){
		palindromsquare=new Long[39];
		int c=0;
		for(Long i=1l;i<=10000000;i++){
			if (isPalindrom(i)){
				if (isPalindrom(i*i)){
					palindromsquare[c]=i*i;
					c++;
				}
					//bw.write(Long.toString(i*i)+"\n");
			}
		}

		//String filename="input.txt";
		//String filename="teszt.in";
		String filename="C-small-attempt0.in";
		//String filename="B-large.in";
		String thisLine;
		try {
			BufferedReader br = new BufferedReader(new FileReader(filename));
			BufferedWriter bw= new BufferedWriter(new FileWriter(filename+".out"));
			thisLine=br.readLine();
			Integer tnum=Integer.parseInt(thisLine);
		    for(int db=0;db<tnum;db++) { // while loop begins here
		    	Long n=1l;//new BigInteger("0");
		    	Long m=10000000l;//new BigInteger("0");
		    	String result="";
	    		thisLine=br.readLine();
	    		try {
	    			Scanner scan=new Scanner(thisLine);
	    			n=scan.nextLong();
	    			m=scan.nextLong();
	    		}
	    		catch
	    		(Exception ex){
	    			System.out.println("hiba");
	    			System.out.println(thisLine);
	    			System.out.println(db);
	    		}
	    		int count=0;
	    		for (int i=0;i<39;i++){
	    			if (palindromsquare[i]>=n && palindromsquare[i]<=m) count++;
	    		}
		    	bw.write("Case #"+(db+1)+": "+count+"\n");
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
		new QC2013().szamol();

	}

}
