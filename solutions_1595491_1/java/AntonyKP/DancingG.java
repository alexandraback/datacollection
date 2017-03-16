package dancing;
import java.io.*;

public class DancingG {
	private int N;
	private String[] InputStringArray;
	private String[] OutputStringArray;
	
	public static void main(String[] args) {
		try{	
			DancingG dg = new DancingG();
			if (dg.GetDataFromInputFile())
				if (dg.ProcestestData())
					dg.WriteDatatoOutputFile();
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
		FileInputStream in = new FileInputStream("E:\\Study\\Google Code jam\\2012\\DancingG" +
				"\\Input\\A-small-attempt0.in");
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
		FileOutputStream out = new FileOutputStream("E:\\Study\\Google Code jam\\2012\\DancingG\\Output\\output.txt");
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
		int N,S,p;
		String outputString="";
		int spacepos=0;
		int count=0;
		String[] parameters = aString.split(" ");
		N=Integer.parseInt(parameters[0]);
		S=Integer.parseInt(parameters[1]);
		p=Integer.parseInt(parameters[2]);
		int normallimit = 28-(10-p)*3;
		int surprisinglimit = normallimit-2;
		if (surprisinglimit<2) surprisinglimit = 2;
		int surprisinglimtcount =0;
		for (int i=3; i<parameters.length;i++){
			if (Integer.parseInt(parameters[i])>=normallimit)
				count++;
				else
					if (Integer.parseInt(parameters[i])>=surprisinglimit)
						surprisinglimtcount++;
					
		}
		if (surprisinglimtcount>S) surprisinglimtcount=S;
		count = count + surprisinglimtcount;
		return String.valueOf(count);
	}
}
