import java.io.*;

public class Qualy2015CDijkstra {

	enum ProblemType{SAMPLE,SMALL,LARGE};
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		String roundPrefix = "Qualy2015";
		String problem = "C";
		ProblemType activeFile = ProblemType.SMALL;
		File file, outFile;
		String activeFileName;
		switch (activeFile) {
			case SAMPLE :
				activeFileName="sample";
				break;
			case SMALL:
				activeFileName="small-attempt2";
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
			 params =  br.readLine().split(" ");
			 cadena =br.readLine(); 
			 result = solveTestCase(Long.parseLong(params[0]),Long.parseLong(params[1]),cadena );
			 StringBuilder caso = new StringBuilder();
			 caso.append("Case #");
			 caso.append(t);
			 caso.append(": ");
			 if (result) {
				 caso.append("YES");
			 }else{
				 caso.append("NO");
			 }
			 caso.append("\n");
			 bw.write(caso.toString());
		 }
		 br.close();
		 bw.close();

	}

	
	private static boolean solveTestCase(long lengthString,long numTimes, String dijkstraString){
		
//		char [] stringInChars = dijkstraString.toCharArray();
//		Quaternion valueDijkstraString =new Quaternion(stringInChars[0]);
//		for (int i =1;i < stringInChars.length;i++) {
//			valueDijkstraString.applyMult(stringInChars [i]);
//		}
		
		// According to the result, we build the "reduced" version of the string to be solved
		// if value = 1 -> valor (cadena) = 1
		// if value = -1 -> valor (cadena * cadena) = 1
		// if value = i,j,k,-i,j-k (cadena * cadena * cadena * cadena) = 1
		// Caso general: nos valen 12 cadenas (13 si numTimes es impar).
		long numStringsReduced = numTimes;
		if (numTimes > 9) {
			numStringsReduced = 8 + (numTimes % 4);
		}
		StringBuilder cadenaAAnalizarTemp = new StringBuilder();
		for ( int i = 0; i < numStringsReduced;i++) {
			cadenaAAnalizarTemp.append(dijkstraString);
		}
		char[] cadenaCompleta = cadenaAAnalizarTemp.toString().toCharArray();
		Quaternion valorI,valorJ,valorK; 
		valorI = new Quaternion(cadenaCompleta[0]);
		for (int corteI = 1; corteI <= cadenaCompleta.length -2;corteI++){
			if (valorI.compara('i')) {
				valorJ = new Quaternion(cadenaCompleta[corteI]);
				for (int corteJ = corteI+1;corteJ <= cadenaCompleta.length -1; corteJ++){
					 if (valorJ.compara('j')) {
						 valorK = new Quaternion(cadenaCompleta[corteJ]);
						 if (corteJ <= cadenaCompleta.length)
						 for (int indiceK = corteJ+1;indiceK<=cadenaCompleta.length -1;indiceK++){
							 valorK.applyMult(cadenaCompleta[indiceK]);
						 }
						 if (valorK.compara('k')){
							 return true;
						 }
					 }
					valorJ.applyMult(cadenaCompleta[corteJ]);	
				}
			}
			valorI.applyMult(cadenaCompleta[corteI]);
		}
		return false;
	}

}
