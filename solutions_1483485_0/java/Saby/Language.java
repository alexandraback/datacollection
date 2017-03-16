import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;




public class Language {


	String[] result = new String[9000];
	int testCases = 0;

	public static void main(String[] args)throws Exception{
		String from = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
		String to = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";


		char[] ingoogle = new char[26];
		char[] inenge = new char[26];


		for(int i = 0; i< 26; i++){ingoogle[i]= (char)(i+97);}

		for(char i = 0; i< 26; i++){
			int index = from.indexOf(ingoogle[i]);
			if(-1 != index){
				inenge[i]=to.charAt(index);
			}
		}
		for(char i = 0; i< 26; i++){System.out.print(ingoogle[i]+ " ");}System.out.println();
		for(char i = 0; i< 26; i++){System.out.print(inenge[i]+ " ");}

		ingoogle['q' - 97] = 'q'; inenge['q' - 97] = 'z';
		ingoogle['z' - 97] = 'z'; inenge['z' - 97] = 'q';

		System.out.println();
		for(char i = 0; i< 26; i++){System.out.print(inenge[i]+ " ");}


		Language bp = new Language();
		InputVectorSequenceLan iv = InputVectorSequenceLan.readFileToCreateInputVector(false);

		bp.testCases = Integer.parseInt(iv.inp[0][0]);

		for(int n = 0 ; n < bp.testCases; n++){
			char[] fromLan = iv.inp[n+1][0].toCharArray();
			char[] toLan = new char[fromLan.length];
			for(int i = 0; i < fromLan.length; i++){
				if(fromLan[i] == ' '){
					toLan[i]= ' ';
					continue;
				}

				int index = fromLan[i] - 97;
				if(index >=0 && index <26){
					toLan[i]=inenge[index];
				}else{
					throw new RuntimeException("no match for index = "+index);
				}

			}

			bp.result[n] = "Case #"+(n+1)+":"+" "+new String(toLan);
		}

		bp.outputFile();
	}




	public void outputFile() throws IOException{
		FileWriter fos = new FileWriter ("C:/workspace/googleCJ/google/input/k.txt");
		BufferedWriter bw = new BufferedWriter(fos);
		for(int i =0; i< testCases; i++){
			bw.write(result[i]);
			bw.write("\r\n");
		}
		bw.close();

	}

}

class InputVectorSequenceLan{
	private static int DATA_LENGTH = 9000;
	public int lines = -1;
	public String[][] inp = new String[DATA_LENGTH][];
	String[] result = new String[DATA_LENGTH];

	private InputVectorSequenceLan(){

	}

	public static InputVectorSequenceLan readFileToCreateInputVector(boolean splitLineBySpace) throws IOException{

		BufferedReader br = new BufferedReader(new FileReader ("C:/workspace/googleCJ/google/input/l.txt"));
		String str = null;
		InputVectorSequenceLan iv = new InputVectorSequenceLan();

		while ((str = br.readLine()) != null) {
				iv.lines++;
		        iv.inp[iv.lines] = process(str, splitLineBySpace);
		}

		return iv;
	}

	private static String[] process(String str, boolean splitLineBySpace) {
		String[] ret = null;
		if(splitLineBySpace){
			ret = str.split("\\ ");
		}else{
			ret = new String[]{str};
		}
	 return ret;
	}


}
