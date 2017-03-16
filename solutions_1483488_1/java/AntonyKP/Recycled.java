package recycled;
import java.io.*;

public class Recycled {
	private int N;
	private String[] InputStringArray;
	private String[] OutputStringArray;
	
	public static void main(String[] args) {
		try{	
			Recycled R = new Recycled();
			if (R.GetDataFromInputFile())
				if (R.ProcestestData())
					R.WriteDatatoOutputFile();
				else
					System.out.println("Error while writing to outputfile");
			else
				System.out.println("Error while getting the input data");
		}catch(IOException ex){
			System.out.println("IO Error");
		}
	}
	private boolean GetDataFromInputFile() throws IOException{
		int casecount=0;
		FileInputStream in = new FileInputStream("E:\\Study\\Google Code jam\\2012\\Recyclednumbers" +
				"\\Input\\C-small-attempt0.in");
		DataInputStream di = new DataInputStream(in);
		BufferedReader br = new BufferedReader(new InputStreamReader(di));
		String line;
		if ((line = br.readLine())!= null) {
			casecount = Integer.parseInt(line);
			InputStringArray = new String[casecount];
			OutputStringArray = new String[casecount];
		}
		for (int i=0; i<casecount; i++){
			if ((line = br.readLine())!= null) 
				InputStringArray[i]=line;
		}
		return true;
	}
	private void WriteDatatoOutputFile() throws IOException{
		FileOutputStream out = new FileOutputStream("E:\\Study\\Google Code jam\\2012\\Recyclednumbers\\Output\\output.txt");
		DataOutputStream dout = new DataOutputStream(out);
		BufferedWriter br = new BufferedWriter(new OutputStreamWriter(dout));
		for (int i=1; i<=OutputStringArray.length;i++){
			br.write("Case #"+i+": "+OutputStringArray[i-1]+"\r\n");
		}
		br.close();
		dout.close();
		out.close();
		System.out.println("Done");
	}
	private boolean ProcestestData(){
		for (int i=0; i<(InputStringArray.length);i++){
			String CurrentString =  InputStringArray[i];
			OutputStringArray[i] = ProcessString(CurrentString);
		}
		return true;
	}
	private String ProcessString(String aString){
		int A,B,count=0;
		int digitcount;
		String[] parameters = aString.split(" ");
		A=Integer.parseInt(parameters[0]);
		B=Integer.parseInt(parameters[1]);
		digitcount = String.valueOf(A).length(); 
		int[] store = new int[digitcount-1];
		for (int i=A; i<=B;i++){
			int subdigit1, subdigit2;
			int newnumber;
			for (int j=0; j<digitcount-1;j++)
				store[j]=0;
			for (int j=1;j<digitcount;j++){
				boolean repetition = false;
				subdigit1 = (int)(i%(Math.pow(10,j)));
				subdigit2 = (int)((i/Math.pow(10,digitcount-j)));	
				if ((subdigit1>=subdigit2) &&
				   (subdigit1<=(B/Math.pow(10,digitcount-j))))
				{
					newnumber = (int) (subdigit1*Math.pow(10, digitcount-j)+ (int)((i/Math.pow(10,j))));
					if ((newnumber>i)&&(newnumber<=B)){
						for (int k=0; k<digitcount-1;k++){
							if (newnumber==store[k])//repetition
								repetition = true;
						}
						//System.out.println(i+" "+newnumber);
						if (!repetition) {
							count++;
							store[j-1]=newnumber;
						}	
					}	
				}
			}
		}
		return String.valueOf(count);
	}
}
