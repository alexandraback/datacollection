package tongue;
import java.io.*;

public class Tongue {
	private int N;
	private String[] InputStringArray;
	private String[] OutputStringArray;
	
	public static void main(String[] args) {
		try{	
			Tongue t = new Tongue();
			if (t.GetDataFromInputFile())
				if (t.ProcestestData())
					t.WriteDatatoOutputFile();
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
		FileInputStream in = new FileInputStream("E:\\Study\\Google Code jam\\2012\\tongues" +
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
		FileOutputStream out = new FileOutputStream("E:\\Study\\Google Code jam\\2012\\tongues\\Output\\output.txt");
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
		String Googler = "ynficwlbkuomxsevzpdrjgthaq";
		String English = "abcdefghijklmnopqrstuvwxyz";
		String outputString="";
		char Currchar,NewChar; 
		int pos;
		for (int i=0; i<aString.length();i++){
			Currchar = aString.charAt(i);
			if (Currchar ==' ')
				NewChar=' ';
			else{
			pos=Googler.indexOf(Currchar);
			NewChar = English.charAt(pos);
			}
			outputString = outputString + NewChar;
		}
		return outputString;
	}
}
