import java.io.*;
import java.util.*;
import java.awt.Point;

class Case{
	int num1;
	long num2,num3;
	String result="";
	Vector storeNum = new Vector();

	public Case(File aFile) {

		try{

			for(long i=1;i<=(long)Math.sqrt(Math.pow(10,14));i++){
				if (isPalindromes(i+"") && isPalindromes((i*i)+"")){
					System.out.println("init count at "+(i*i));
					storeNum.addElement((i*i)+"");
				}
			}



			StringBuilder contents = new StringBuilder();
		  	BufferedReader input =  new BufferedReader(new FileReader(aFile));
			String line = input.readLine();
			num1 = Integer.valueOf(line).intValue();
			int i=1;
			while (i<=num1 && ( line = input.readLine()) != null){
				StringTokenizer st = new StringTokenizer(line," ");
				num2 = Long.valueOf(st.nextToken()).longValue();
				num3 = Long.valueOf(st.nextToken()).longValue();
				oneCase(i,num2,num3);
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


  public void oneCase (int c,long num1, long num2){
	String re="";
	int count=0;
	boolean done=false;
	boolean found=false;
	for(int i=0;i<storeNum.size()&&!done;i++){
		Long nummm=Long.valueOf(""+storeNum.elementAt(i)).longValue();
		if (nummm>=num1 && nummm<=num2){
			found=true;
			count++;
		} else if (found){
			done=true;
		}
	}



/*
	long smaller1=(long)Math.ceil(Math.sqrt(num1));
	long smaller2=(long)Math.sqrt(num2);

	System.out.println("smaller range "+smaller1+" "+smaller2);


	for(long i=smaller1;i<=smaller2;i++){
		if (isPalindromes(i+"") && isPalindromes((i*i)+"")){

			System.out.println("count at "+i);

			count++;
		}
	}
*/


	re=count+"";




//*** output
	System.out.println("case="+c+": "+re);
//***



	result+="Case #"+c+": "+re+System.getProperty("line.separator");
  }

	public boolean isInteger(String s) {
		double a = Double.valueOf(s).doubleValue();
		return (a==(int)a);
	}

	public boolean isPalindromes(String s){
		for (int i=0; i<s.length()/2; i++){
			if (s.charAt(i)!=s.charAt(s.length()-1-i)){
				return false;
			}
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
    File testFile = new File("C:\\java\\readwritetext\\Fair and Square\\source.txt");
    File testFile2 = new File("C:\\java\\readwritetext\\Fair and Square\\result.txt");
	Case allcases = new Case(testFile);
    setContents(testFile2, allcases.getResult());
  }
}



















