import java.io.*;

public class Qualy2015DOminousOmino {

	enum ProblemType{SAMPLE,SMALL,LARGE};
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		String roundPrefix = "Qualy2015";
		String problem = "D";
		ProblemType activeFile = ProblemType.SMALL;
		File file, outFile;
		String activeFileName;
		switch (activeFile) {
			case SAMPLE :
				activeFileName="sample";
				break;
			case SMALL:
				activeFileName="small-attempt1";
				break;
			case LARGE:
				activeFileName="large";
				break;
			default:
				throw new RuntimeException("Problem type not supported");
		}
		 file = new File(String.format("files/%s/%s-%s.in",roundPrefix,problem,activeFileName));
		 outFile = new File(String.format("files/%s/%s-%s.out",roundPrefix,problem,activeFileName));
		

		 BufferedReader br = new BufferedReader(new FileReader(file));
		 BufferedWriter bw = new BufferedWriter(new FileWriter(outFile));
		 int testCases = Integer.parseInt(br.readLine());
		 
		 //Specific for the problem
		 String [] params;
		 String cadena;
		 boolean result;
		// initializeMagicArray();
		 for(int t=1;t<=testCases;t++){
			 System.out.printf("Test case %d...\n",t);
			 params =  br.readLine().split(" ");
			 result = solveTestCase(Integer.parseInt(params[0]),Integer.parseInt(params[1]),Integer.parseInt(params[2]) );
			 StringBuilder caso = new StringBuilder();
			 caso.append("Case #");
			 caso.append(t);
			 caso.append(": ");
			 if (result) {
				 caso.append("Richard");
			 }else{
				 caso.append("Gabriel");
			 }
			 caso.append("\n");
			 bw.write(caso.toString());
		 }
		 br.close();
		 bw.close();

	}

	// Return TRUE if it is possible to find a piece that makes impossible filling the grid
	private static boolean solveTestCase(int size,int rows, int columns){
		int size1,size2;
		if (rows >= columns) {
			size1= rows;
			size2 = columns;
		} else {
			size1 = columns;
			size2 = rows;
		}
		if (((size1*size2) % size) != 0) return true;
		int maxMinimumWidth = (size +1) / 2;
		
		// Casos analizados con papel y lapiz
		if (size == 1) {
			return false;
		}else if (size == 2) {
			return size1==1;
		} else if (size == 3) {
			return  size2 == 1 ;
		} else if (size == 4) {
			return (size1 < 4) || (size2 < 3);
		} else {
			throw new RuntimeException("TAmaño no válido:" + size);
		}
	}

}
