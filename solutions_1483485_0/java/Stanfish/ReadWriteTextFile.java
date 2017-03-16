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
				String strLine=line;
				oneCase(i,strLine);
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


  public void oneCase (int c,String st){
	String re="";

//*** output
	System.out.println(" ");
	System.out.println("case="+c+": "+st);
//***
    char[] stringArray;
    stringArray = st.toCharArray();
	for(int i=0; i < stringArray.length; i++){
		stringArray[i]=changeChar(stringArray[i]);
		System.out.print(stringArray[i]);
	}
	re = new String(stringArray);
	result+="Case #"+c+": "+re+System.getProperty("line.separator");
  }


	public char changeChar(char c){
		if (c=='y') return 'a';
		if (c=='n') return 'b';
		if (c=='f') return 'c';
		if (c=='i') return 'd';
		if (c=='c') return 'e';
		if (c=='w') return 'f';
		if (c=='l') return 'g';
		if (c=='b') return 'h';
		if (c=='k') return 'i';
		if (c=='u') return 'j';
		if (c=='o') return 'k';
		if (c=='m') return 'l';
		if (c=='x') return 'm';
		if (c=='s') return 'n';
		if (c=='e') return 'o';
		if (c=='v') return 'p';
		if (c=='z') return 'q';
		if (c=='p') return 'r';
		if (c=='d') return 's';
		if (c=='r') return 't';
		if (c=='j') return 'u';
		if (c=='g') return 'v';
		if (c=='t') return 'w';
		if (c=='h') return 'x';
		if (c=='a') return 'y';
		if (c=='q') return 'z';
		return c;
	}



//Adding elements in Vector b to the end of Vector a
	public Vector addingVector(Vector a, Vector b){
		for (int i=0; i<b.size(); i++){
			a.addElement(b.elementAt(i));
		}
		return a;
	}

	public void sortingDouble(Vector v){
	  int numSorted=0;
	  int index;
	  while(numSorted<v.size()){
		  double temp1=((Double)v.elementAt(numSorted)).doubleValue();
		  int i=numSorted;
		  for(i=numSorted;i>0;i--){
			  double temp2=((Double)v.elementAt(i-1)).doubleValue();
			  if (temp1<temp2){
				  v.setElementAt(v.elementAt(i-1),i);
			  }
			  else {
				  break;
			  }
		  }
		  v.setElementAt(temp1,i);
		  numSorted++;
	  }
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
    File testFile = new File("D:\\java\\readwritetext\\Speaking in Tongues\\source.txt");
    File testFile2 = new File("D:\\java\\readwritetext\\Speaking in Tongues\\result.txt");
	Case allcases = new Case(testFile);
    setContents(testFile2, allcases.getResult());
  }
}



















