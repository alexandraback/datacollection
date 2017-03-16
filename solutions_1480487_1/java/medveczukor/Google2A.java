import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.text.NumberFormat;
import java.util.HashSet;
import java.util.Set;


public class Google2A {
	public String szamol(String input){
		
		String a=input;
		Integer db=Integer.parseInt(a.substring(0,a.indexOf(' ')));
		if (db>0)a=a.substring(a.indexOf(' ')+1);
		Integer[] pont=new Integer[db];
		Boolean[] pb=new Boolean[db];
		Integer sum=0;
		for(Integer i=0; i<db; i++){
			Integer akt;
			if (i<db-1){
				akt=Integer.parseInt(a.substring(0,a.indexOf(' ')));
				a=a.substring(a.indexOf(' ')+1);
			}
			else akt=Integer.parseInt(a);
			sum+=akt;
			pont[i]=akt;
		}
		String result="";
		if (db>0) {
			NumberFormat nf=NumberFormat.getInstance();
			nf.setMaximumFractionDigits(6);
			nf.setMinimumFractionDigits(6);
			nf.setGroupingUsed(false);
			
			Double atlag=new Double(sum*2)/db;
			Double sum2=sum+0.0;
			int db2=0;
			for (int i=0;i<db;i++){
				pb[i]=pont[i]>=atlag;
				if (!pb[i]){
					sum2+=pont[i];
					db2++;
				}
			}
			Double atlag2=sum2/db2;
			for (int i=0;i<db;i++){
				if (result.length()>0) result+=" ";
				if (sum==0) result+="0.000000";
				else {
					if (db2==0||db2==db){
						Double min=(atlag-pont[i])/sum;
						result+= nf.format(min*100).replace(" ", "").replace(",",".");
					}
					else
					{
						if (pb[i]) result+="0.000000";
						else {
							Double min=(atlag2-pont[i])/sum;
							result+= nf.format(min*100).replace(" ", "").replace(",",".");
						}
					}
				}
			}
		}
		
		return result;
	}
	public static void main(String[] args) {
		Google2A a=new Google2A();
		//String filename="input.txt";
		//String filename="A-small-attempt2.in";
		String filename="A-large.in";
		String thisLine;
		try {
			BufferedReader br = new BufferedReader(new FileReader(filename));
			BufferedWriter bw= new BufferedWriter(new FileWriter(filename+".out"));
			thisLine=br.readLine();
			Integer tnum=Integer.parseInt(thisLine);
		     for(int i=0;i<tnum;i++) { // while loop begins here
		    	 	thisLine=br.readLine();
		           System.out.println(thisLine);
		           System.out.println("Case #"+(i+1)+": "+a.szamol(thisLine)+"\n");
		           bw.write("Case #"+(i+1)+": "+a.szamol(thisLine)+"\n");
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
