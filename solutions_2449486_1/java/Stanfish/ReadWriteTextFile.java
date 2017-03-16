import java.io.*;
import java.util.*;
import java.awt.Point;

class Case{
	int num1,num2,num3;
	String result="";
	public Case(File aFile) {

		try{
			StringBuilder contents = new StringBuilder();
		  	BufferedReader input =  new BufferedReader(new FileReader(aFile));
			String line = input.readLine();
			num1 = Integer.valueOf(line).intValue();

			int i=1;
			while (i<=num1 && ( line = input.readLine()) != null){
				StringTokenizer st = new StringTokenizer(line," ");
				num3 = Integer.valueOf(st.nextToken()).intValue();
				num2 = Integer.valueOf(st.nextToken()).intValue();
				Vector mainV=new Vector();
				for (int j=0; j<num3; j++){
					line = input.readLine();
					StringTokenizer st1 = new StringTokenizer(line," ");
					Vector v1=new Vector();
					for (int k=0; k<num2; k++){
						v1.addElement(st1.nextToken());
					}
					mainV.addElement(v1);
				}
				oneCase(i,mainV);
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


  public void oneCase (int c,Vector mainV){
	String re="";

	boolean ok=true;
	for (int i=0; i<mainV.size() && ok; i++){
		for (int j=0; j<((Vector)mainV.elementAt(i)).size() && ok; j++){
			ok=checkSpot(mainV,i,j);
		}
	}

	if (ok){re="YES";}
	else {re="NO";}


//*** output
	System.out.println(" ");
	System.out.println("case="+c+": ");
	System.out.println(mainV);
//***

	System.out.println(re);



	result+="Case #"+c+": "+re+System.getProperty("line.separator");
  }


	public boolean checkSpot(Vector mainV, int i, int j){
		double num=Double.valueOf(((Vector)mainV.elementAt(i)).elementAt(j)+"").doubleValue();
		Vector v1=(Vector)mainV.elementAt(i);
		Vector v2=new Vector();
		for (int k=0; k<mainV.size(); k++){
			v2.addElement(((Vector)mainV.elementAt(k)).elementAt(j));
		}
		if (isLargest(v1,num) || isLargest(v2,num)){
			return true;
		}
		return false;
	}

	public boolean isLargest(Vector vv, double num){
		for (int k=0; k<vv.size(); k++){
			double num2=Double.valueOf(vv.elementAt(k)+"").doubleValue();
			//System.out.println("compare "+num+" "+num2);
			if (num2>num){ return false;}
		}
		return true;
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
    File testFile = new File("C:\\java\\readwritetext\\Lawnmower\\source.txt");
    File testFile2 = new File("C:\\java\\readwritetext\\Lawnmower\\result.txt");
	Case allcases = new Case(testFile);
    setContents(testFile2, allcases.getResult());
  }
}



















