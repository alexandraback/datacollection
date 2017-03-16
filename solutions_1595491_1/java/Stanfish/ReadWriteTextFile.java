import java.io.*;
import java.util.*;
import java.awt.Point;
import java.lang.Math;

class Case{
	int num0,num1,num2,num3;
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
				num1=Integer.valueOf(st.nextToken()).intValue();
				num2=Integer.valueOf(st.nextToken()).intValue();
				num3=Integer.valueOf(st.nextToken()).intValue();

				Vector v1=new Vector();
				for (int j=0; j<num1; j++){
					int inum1=Integer.valueOf(st.nextToken()).intValue();
					v1.addElement(inum1);
				}

				oneCase(i,num1,num2,num3,v1);

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


  public void oneCase (int c,int n1,int n2,int n3,Vector vv){
	String re="";

	int noSurpriseScore=Math.max(0,n3*3-2);
	int needSurpriseScore=Math.max(0,n3*3-4);
	if (n3==1){
		needSurpriseScore=1;
	}
	int re_y=0;
	for (int i=0; i<vv.size(); i++){
		int score=((Integer)(vv.elementAt(i))).intValue();
		if (score>=noSurpriseScore){
			re_y++;
		} else if (n2>0 && score>=needSurpriseScore){
			re_y++;
			n2--;
		}
	}


//*** output
	System.out.println(" ");
	System.out.println("case="+c+": "+n1+":"+n2+":"+n3+" "+vv);
//***
	re=re_y+"";
	result+="Case #"+c+": "+re+System.getProperty("line.separator");
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
    File testFile = new File("D:\\java\\readwritetext\\Dancing With the Googlers\\source.txt");
    File testFile2 = new File("D:\\java\\readwritetext\\Dancing With the Googlers\\result.txt");
	Case allcases = new Case(testFile);
    setContents(testFile2, allcases.getResult());
  }
}



















