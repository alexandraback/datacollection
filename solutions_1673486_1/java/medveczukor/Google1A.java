import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.text.NumberFormat;


public class Google1A {

	/**
	 * @param args
	 */
	public String szamol(String input,Integer inp,Integer max){
		String result="";
		String a=input;
			Double[] p=new Double[inp+1];
			Double[] p2=new Double[inp+1];
			p[inp]=1.0;
			for (int i=0; i<inp;i++){
				Double pakt;
				if (i<inp-1){
					pakt=Double.parseDouble(a.substring(0,a.indexOf(' ')));
					a=a.substring(a.indexOf(' ')+1);
				}
				else pakt=Double.parseDouble(a);
				p[inp-i-1]=p[inp-i]*pakt;
			}
			int betu1=max-inp+1;
			int betu2=2*(max+1)-inp;
			Double min=(max+2.0);
			for (int i=0; i<=inp;i++){
				Double akt=p[i]*betu1+((1.0-p[i])*betu2);
				if (akt<min) min=akt;
				betu1+=2;
				betu2+=2;
			}
		NumberFormat nf=NumberFormat.getInstance();
		nf.setMaximumFractionDigits(6);
		nf.setMinimumFractionDigits(6);
		nf.setGroupingUsed(false);
		return nf.format(min);
	}
	
	public static void main(String[] args) {
		Google1A a=new Google1A();
		//String filename="input.txt";
		//String filename="A-small-attempt1.in";
		String filename="A-large.in";
		String thisLine;
		try {
			BufferedReader br = new BufferedReader(new FileReader(filename));
			BufferedWriter bw= new BufferedWriter(new FileWriter(filename+".out"));
			thisLine=br.readLine();
			Integer tnum=Integer.parseInt(thisLine);
		     for(int i=0;i<tnum;i++) { // while loop begins here
		    	 	thisLine=br.readLine();
		    		Integer inp=Integer.parseInt(thisLine.substring(0,thisLine.indexOf(' ')));
		    		thisLine=thisLine.substring(thisLine.indexOf(' ')+1);
		    		Integer max=Integer.parseInt(thisLine);
		    		thisLine=br.readLine();
		           //System.out.println(thisLine);
		           //System.out.println("Case #"+(i+1)+": "+a.szamol(thisLine,inp,max)+"\n");
		           bw.write("Case #"+(i+1)+": "+a.szamol(thisLine,inp,max).replace(',','.').replaceAll(" ", "")+"\n");
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
