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
				String strLine1=line;
				String strLine2=input.readLine();
				String strLine3=input.readLine();
				String strLine4=input.readLine();
				line = input.readLine();
				oneCase(i,strLine1,strLine2,strLine3,strLine4);
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


  public void oneCase (int c,String st1,String st2,String st3,String st4){
	String re="";

//*** output
	System.out.println(" ");
	System.out.println("case="+c+": ");
	System.out.println(st1);
	System.out.println(st2);
	System.out.println(st3);
	System.out.println(st4);
//***
    boolean xWin=false,oWin=false;
    boolean xCounting=true;
    boolean oCounting=true;

    char[] stringArray1;
    stringArray1 = st1.toCharArray();
	for(int i=0; i < stringArray1.length && (xCounting||oCounting); i++){
		if (stringArray1[i]=='T'){}
		else if (stringArray1[i]=='X'){
			oCounting=false;
		}else if (stringArray1[i]=='O'){
			xCounting=false;
		}else if (stringArray1[i]=='.'){
			xCounting=false;
			oCounting=false;
		}
	}
	if(xCounting){xWin=true;}
	if(oCounting){oWin=true;}

	char[] stringArray2;
	stringArray2 = st2.toCharArray();
    if (!xWin && !oWin){
		xCounting=true;
		oCounting=true;
		for(int i=0; i < stringArray2.length && (xCounting||oCounting); i++){
			if (stringArray2[i]=='T'){}
			else if (stringArray2[i]=='X'){
				oCounting=false;
			}else if (stringArray2[i]=='O'){
				xCounting=false;
			}else if (stringArray2[i]=='.'){
				xCounting=false;
				oCounting=false;
			}
		}
		if(xCounting){xWin=true;}
		if(oCounting){oWin=true;}
	}

	char[] stringArray3;
	stringArray3 = st3.toCharArray();
    if (!xWin && !oWin){
		xCounting=true;
		oCounting=true;
		for(int i=0; i < stringArray3.length && (xCounting||oCounting); i++){
			if (stringArray3[i]=='T'){}
			else if (stringArray3[i]=='X'){
				oCounting=false;
			}else if (stringArray3[i]=='O'){
				xCounting=false;
			}else if (stringArray3[i]=='.'){
				xCounting=false;
				oCounting=false;
			}
		}
		if(xCounting){xWin=true;}
		if(oCounting){oWin=true;}
	}

	char[] stringArray4;
	stringArray4 = st4.toCharArray();
    if (!xWin && !oWin){
		xCounting=true;
		oCounting=true;
		for(int i=0; i < stringArray4.length && (xCounting||oCounting); i++){
			if (stringArray4[i]=='T'){}
			else if (stringArray4[i]=='X'){
				oCounting=false;
			}else if (stringArray4[i]=='O'){
				xCounting=false;
			}else if (stringArray4[i]=='.'){
				xCounting=false;
				oCounting=false;
			}
		}
		if(xCounting){xWin=true;}
		if(oCounting){oWin=true;}
	}


    if (!xWin && !oWin){
		for(int i=0; i < 4 && !xWin && !oWin; i++){
			xCounting=true;
			oCounting=true;
			if (stringArray1[i]=='T'){}
			else if (stringArray1[i]=='X'){
				oCounting=false;
			}else if (stringArray1[i]=='O'){
				xCounting=false;
			}else if (stringArray1[i]=='.'){
				xCounting=false;
				oCounting=false;
			}

			if (stringArray2[i]=='T'){}
			else if (stringArray2[i]=='X'){
				oCounting=false;
			}else if (stringArray2[i]=='O'){
				xCounting=false;
			}else if (stringArray2[i]=='.'){
				xCounting=false;
				oCounting=false;
			}

			if (stringArray3[i]=='T'){}
			else if (stringArray3[i]=='X'){
				oCounting=false;
			}else if (stringArray3[i]=='O'){
				xCounting=false;
			}else if (stringArray3[i]=='.'){
				xCounting=false;
				oCounting=false;
			}

			if (stringArray4[i]=='T'){}
			else if (stringArray4[i]=='X'){
				oCounting=false;
			}else if (stringArray4[i]=='O'){
				xCounting=false;
			}else if (stringArray4[i]=='.'){
				xCounting=false;
				oCounting=false;
			}
			if(xCounting){xWin=true;}
			if(oCounting){oWin=true;}
		}
	}



    if (!xWin && !oWin){
		xCounting=true;
		oCounting=true;
		if (stringArray1[0]=='T'){}
		else if (stringArray1[0]=='X'){
			oCounting=false;
		}else if (stringArray1[0]=='O'){
			xCounting=false;
		}else if (stringArray1[0]=='.'){
			xCounting=false;
			oCounting=false;
		}

		if (stringArray2[1]=='T'){}
		else if (stringArray2[1]=='X'){
			oCounting=false;
		}else if (stringArray2[1]=='O'){
			xCounting=false;
		}else if (stringArray2[1]=='.'){
			xCounting=false;
			oCounting=false;
		}

		if (stringArray3[2]=='T'){}
		else if (stringArray3[2]=='X'){
			oCounting=false;
		}else if (stringArray3[2]=='O'){
			xCounting=false;
		}else if (stringArray3[2]=='.'){
			xCounting=false;
			oCounting=false;
		}

		if (stringArray4[3]=='T'){}
		else if (stringArray4[3]=='X'){
			oCounting=false;
		}else if (stringArray4[3]=='O'){
			xCounting=false;
		}else if (stringArray4[3]=='.'){
			xCounting=false;
			oCounting=false;
		}
		if(xCounting){xWin=true;}
		if(oCounting){oWin=true;}
	}


    if (!xWin && !oWin){
		xCounting=true;
		oCounting=true;
		if (stringArray1[3]=='T'){}
		else if (stringArray1[3]=='X'){
			oCounting=false;
		}else if (stringArray1[3]=='O'){
			xCounting=false;
		}else if (stringArray1[3]=='.'){
			xCounting=false;
			oCounting=false;
		}

		if (stringArray2[2]=='T'){}
		else if (stringArray2[2]=='X'){
			oCounting=false;
		}else if (stringArray2[2]=='O'){
			xCounting=false;
		}else if (stringArray2[2]=='.'){
			xCounting=false;
			oCounting=false;
		}

		if (stringArray3[1]=='T'){}
		else if (stringArray3[1]=='X'){
			oCounting=false;
		}else if (stringArray3[1]=='O'){
			xCounting=false;
		}else if (stringArray3[1]=='.'){
			xCounting=false;
			oCounting=false;
		}

		if (stringArray4[0]=='T'){}
		else if (stringArray4[0]=='X'){
			oCounting=false;
		}else if (stringArray4[0]=='O'){
			xCounting=false;
		}else if (stringArray4[0]=='.'){
			xCounting=false;
			oCounting=false;
		}
		if(xCounting){xWin=true;}
		if(oCounting){oWin=true;}
	}


	if (xWin){re="X won";}
	if (oWin){re="O won";}

	if (!xWin && !oWin){
		if (st1.indexOf('.')!=-1 || st2.indexOf('.')!=-1 || st3.indexOf('.')!=-1 || st4.indexOf('.')!=-1){
			re="Game has not completed";
		} else {
			re="Draw";
		}
	}

	System.out.println(re);



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
    File testFile = new File("C:\\java\\readwritetext\\TicTacToe\\source.txt");
    File testFile2 = new File("C:\\java\\readwritetext\\TicTacToe\\result.txt");
	Case allcases = new Case(testFile);
    setContents(testFile2, allcases.getResult());
  }
}



















