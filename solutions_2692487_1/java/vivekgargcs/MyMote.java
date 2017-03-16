import java.util.*;
import java.io.*;
import java.util.Arrays;
import java.math.BigInteger;

class Mote implements Comparable<Mote> {
	long size;

	public Mote (long w){
		size=w;
	} 
	public long getSize() {
		return(this.size);
	}
	public void incrSize() {
		size+=size-1;
	}
	public void incrSize(long t) {
		size+=t;
	}
	public int compareTo(Mote taskToCompare) {
		return((int)(this.size - taskToCompare.getSize()));
  	}
	public String toString() {
		return(" Size : " + size );
	}
}
class MyMote {

	public static void myPrint(String s) {
		System.out.println(s);
	}

	public static void myTrace(String s) {
		//System.out.println("TRACE : " + s);
	}
	public static void main(String args[]) {
		
		int caseCount = 1 ;
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			String str;
			str = br.readLine();
			str = br.readLine();
			String inputs[];
			while (str != null) {
				long workDone=0;
				long operations=0;
				//BigInteger workDone=new BigInteger(0+"");
				//LinkedList workList = new LinkedList();
				//LinkedList subList = new LinkedList();
				
				inputs=str.split(" ");
				Mote aMote    =new Mote(Long.parseLong(inputs[0]));
				Mote aMote_org    =new Mote(Long.parseLong(inputs[0]));
				int totalMote    = Integer.parseInt(inputs[1]);

				Mote[] myMote = new Mote[totalMote];
				//int currentEnergy=maxEnergy;
				str = br.readLine();
				inputs=str.split(" ");
  				int i;
				for(i=0;i<totalMote;i++) {
					myMote[i] = new Mote(Long.parseLong(inputs[i]));
				}
				Arrays.sort(myMote);
				String motes= "" ;
				for(i=0;i<totalMote;i++) {
					motes += myMote[i] + " " ;
				}
				long[] operationMote = new long[totalMote];
				for(i=0;i<totalMote;i++) {
					operationMote[i] = (long) 0 ;
				}
				if(aMote.getSize() == 1) {
					operations=totalMote;
				} else {
					for(i=0;i<totalMote;i++) {
						while(aMote.getSize() <= myMote[i].getSize() ) {
							operationMote[i]++;
							aMote.incrSize();
						}
						aMote.incrSize(myMote[i].getSize());
					}
					long[] sumMote = new long[totalMote+1];
					for(i=0;i<totalMote;i++) {
						sumMote[i] = (long) 0 ;
						for(int j=0;j<i;j++) {
							sumMote[i]+=operationMote[j];
						}
						sumMote[i]+=totalMote-i;
					}
					for(int j=0;j<totalMote;j++) {
						sumMote[i]+=operationMote[j];
					}
					Arrays.sort(sumMote);
					operations=sumMote[0];
					myTrace( aMote_org + " ," +motes + " ," + sumMote[0] +  ", " + sumMote[totalMote-1]);
				}
				myPrint("Case #" + caseCount++ + ": " + operations );
				str = br.readLine();
			}
		} catch(IOException E) {
			System.out.println("ERROR");
			
		}
	}
}
