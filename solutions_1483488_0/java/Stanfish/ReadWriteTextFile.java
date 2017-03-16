import java.io.*;
import java.util.*;
import java.awt.Point;

class Case{
	int num0;
	long num1,num2;
	String result="";
	public Case(File aFile) {

		try{
			StringBuilder contents = new StringBuilder();
		  	BufferedReader input =  new BufferedReader(new FileReader(aFile));
			String line = input.readLine();
			num0 = Integer.valueOf(line).intValue();
			int i=1;
			while (i<=num0 && ( line = input.readLine()) != null){
				StringTokenizer st = new StringTokenizer(line," ");
				num1=Long.valueOf(st.nextToken()).longValue();
				num2=Long.valueOf(st.nextToken()).longValue();

				oneCase(i,num1,num2);
			  	i++;
			}

		}
		catch (IOException ex){
		  ex.printStackTrace();
		}
	}

  public String getResult (){

	return result;

  }


  public void oneCase (int c,long n1,long n2){
	String re="";

//*** output
	System.out.println("case="+c+": "+n1+":"+n2);
//***

	int y=0;
	for (long i=n1; i<=n2; i++){
		y+=checkRecycle(n1,n2,i);
	}

	re=y+"";

	result+="Case #"+c+": "+re+System.getProperty("line.separator");
  }


	public int checkRecycle (long n1, long n2, long num){
		String numSt=Long.valueOf(num).toString();
		if (numSt.length()<2)	return 0;
		int re=0;
		Vector allNum=new Vector();
		for (int i=1; i<numSt.length(); i++){
			String newNumSt=numSt.substring(i)+numSt.substring(0,i);
			if (!newNumSt.substring(0,1).equals("0")){
				if (Long.valueOf(newNumSt).longValue()>num){
					if (Long.valueOf(newNumSt).longValue()>n1 && Long.valueOf(newNumSt).longValue()<=n2){
						boolean found=false;
						for (int j=0;!found&&j<allNum.size();j++){
							if (newNumSt.equals((String)(allNum.elementAt(j))))
								found=true;
						}
						if (!found){
							allNum.addElement(newNumSt);
							re++;
						}
					}
				}
			}
		}
		//if (re>0)System.out.println("checkRecycle "+numSt+" re="+re+" allNum="+allNum);
		return re;
	}








}















public class ReadWriteTextFile {
  static public String getContents(File aFile) {
    StringBuilder contents = new StringBuilder();
    try {
      BufferedReader input =  new BufferedReader(new FileReader(aFile));
      try {
        String line = null;
        while (( line = input.readLine()) != null){
          contents.append(line);
          contents.append(System.getProperty("line.separator"));
        }
      }
      finally {
        input.close();
      }
    }
    catch (IOException ex){
      ex.printStackTrace();
    }
    return contents.toString();
  }
  static public void setContents(File aFile, String aContents)
                                 throws FileNotFoundException, IOException {
    if (aFile == null) {
      throw new IllegalArgumentException("File should not be null.");
    }
    if (!aFile.exists()) {
      throw new FileNotFoundException ("File does not exist: " + aFile);
    }
    if (!aFile.isFile()) {
      throw new IllegalArgumentException("Should not be a directory: " + aFile);
    }
    if (!aFile.canWrite()) {
      throw new IllegalArgumentException("File cannot be written: " + aFile);
    }
    Writer output = new BufferedWriter(new FileWriter(aFile));
    try {
      output.write( aContents );
    }
    finally {
      output.close();
    }
  }
  public static void main (String... aArguments) throws IOException {
    File testFile = new File("source.txt");
    File testFile2 = new File("result.txt");
	Case allcases = new Case(testFile);
    setContents(testFile2, allcases.getResult());
  }
}



















