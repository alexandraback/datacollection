import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;


public class TestProgram {
	public static void main(String args[]) {
		try{			
			char toGoogleLookupTable[] = new char[26];
			char toEnglishLookupTable[] = new char[26];

			buildLookupTables(toGoogleLookupTable, toEnglishLookupTable);
			//printLookupTable(toGoogleLookupTable);
			//printLookupTable(toEnglishLookupTable);
			
			 BufferedReader in = new BufferedReader(new FileReader("A-small-attempt0.in"));
			 BufferedWriter out = new BufferedWriter(new FileWriter("A-small-0.out"));

			 String line = in.readLine();
			 int caseCount = Integer.parseInt(line);
			 
			 StringBuffer outputWriter = new StringBuffer();
			 
			 for(int i = 1; i <= caseCount; i++){
				 line = in.readLine();
				 
				 outputWriter.append("Case #" + i + ": ");
				 outputWriter.append(translateLine(line, toGoogleLookupTable));
				 
				 if(i != caseCount)
					 outputWriter.append("\n");
			 }

			 out.write(outputWriter.toString()); 
			 System.out.println(outputWriter.toString());
			 
			 in.close();
			 out.close();
		} catch(Exception e){
			//swallow the exception
		}

	}
	
	//assuming correct lookup table, source string not null
	public static String translateLine(String source, char[] lookupTable){
		String translation = "";
		
		char sourceChar, transChar;
		int index;
		for(int i = 0; i < source.length(); i++){
			sourceChar = source.charAt(i);
			index = indexForLetter(sourceChar);
			
			if(index == -1)
				transChar = sourceChar;
			else
				transChar = lookupTable[index];
			
			translation = translation + transChar;
		}
		
		return translation;
	}

	public static void buildLookupTables(char[] toGoogleLookupTable, char[] toEnglishLookupTable){
		String source0 = "aoz";
		String source1 = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
		String source2 = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
		String source3 = "de kr kd eoya kw aej tysr re ujdr lkgc jv";
		String sourcePatch = "q";
		
		String translation0 = "yeq";
		String translation1 = "our language is impossible to understand";
		String translation2 = "there are twenty six factorial possibilities";
		String translation3 = "so it is okay if you want to just give up";
		String translationPatch = "z";

		addMappingToTable(source0, translation0, toGoogleLookupTable);
		addMappingToTable(source1, translation1, toGoogleLookupTable);
		addMappingToTable(source2, translation2, toGoogleLookupTable);
		addMappingToTable(source3, translation3, toGoogleLookupTable);
		addMappingToTable(sourcePatch, translationPatch, toGoogleLookupTable);

		addMappingToTable(translation0, source0, toEnglishLookupTable);
		addMappingToTable(translation1, source1, toEnglishLookupTable);
		addMappingToTable(translation2, source2, toEnglishLookupTable);
		addMappingToTable(translation3, source3, toEnglishLookupTable);
		addMappingToTable(translationPatch, sourcePatch, toEnglishLookupTable);
	}
	
	public static void printLookupTable(char[] lookupTable){
		for(int i = 0; i < 26; i++){
			String letter = "" + (char) (i + 'a');
			System.out.print(letter + " -> ");
			System.out.println(lookupTable[i]);
		}
	}
	
	//assumes letter is 'a' - 'z'
	public static int indexForLetter(char letter){
		int index = letter - 'a';

		if(index >= 0 && index < 26)
			return letter - 'a';
		else
			return -1;
	}
	
	//builds lookup table given a source string and its translation
	//assumes table is length 26, source not null, translation not null
	//assumes source length = translation length
	public static void addMappingToTable(String source, String translation, char[] table){
		char currentLetter, mappingLetter;
		int index;
		for(int i = 0; i < source.length(); i++){
			index = -1;
			currentLetter = source.charAt(i);
			mappingLetter = translation.charAt(i);
			index = indexForLetter(currentLetter);
			
			if(index != -1){
				table[index] = mappingLetter;
			}
		}
	}
	
}
