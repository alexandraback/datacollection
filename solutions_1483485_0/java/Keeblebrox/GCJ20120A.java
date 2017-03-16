import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Reader;
import java.io.Writer;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Google Code Jam 2012
 * 	Qualifier Round
 * 	Problem A
 * 
 * @author Brian Crockford
 */
public class GCJ20120A {
	public static final String inputFilename = "A-small-attempt1.in";
	
	static final String[] sourceEncoded = {
		"ejp mysljylc kd kxveddknmc re jsicpdrysi",
		"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
		"de kr kd eoya kw aej tysr re ujdr lkgc jv"
	};
	static final String[] sourceDecoded = {
		"our language is impossible to understand",
		"there are twenty six factorial possibilities",
		"so it is okay if you want to just give up"
	};
	
	
	
	static class Cipher {
		List<Character> sourceCodePoints = new ArrayList<Character>();
		List<Character> encodedCodePoints = new ArrayList<Character>();
		
		private void pushTranslation(Character source, Character encoded) {
			if (!encodedCodePoints.contains(encoded)) {
				sourceCodePoints.add(source);
				encodedCodePoints.add(encoded);
			}
		}
		
		public char encode(char c) {
			if (sourceCodePoints.contains(c)) {
				return encodedCodePoints.get(sourceCodePoints.indexOf(c));
			}
			else if (Character.isWhitespace(c)) {
				return c;
			}
			return '.';
		}
		
		public String encode(String s) {
			char[] translation = new char[s.length()];
			s.toLowerCase().getChars(0, s.length(), translation, 0);
			for (int i=0, n=translation.length; i<n; ++i) {
				translation[i] = encode(translation[i]);
			}
			return String.copyValueOf(translation);
		}
		
		public char decode(char c) {
			if (encodedCodePoints.contains(c)) {
				return sourceCodePoints.get(encodedCodePoints.indexOf(c));
			}
			else if (Character.isWhitespace(c)) {
				return c;
			}
			return '.';
		}
		
		public String decode(String s) {
			char[] translation = new char[s.length()];
			s.toLowerCase().getChars(0, s.length(), translation, 0);
			for (int i=0, n=translation.length; i<n; ++i) {
				translation[i] = decode(translation[i]);
			}
			return String.copyValueOf(translation);
		}
		
		@Override
		public String toString() {
			StringBuilder sb = new StringBuilder("<$Cipher: ");
			sb.append("{");
			for (int i=0, n=sourceCodePoints.size(); i<n; ++i) {
				sb.append(sourceCodePoints.get(i)).append("->").append(encodedCodePoints.get(i));
				if (i<n-1) sb.append(", ");
			}
			return sb.append("}>").toString();
		}
		
		public static Cipher build(String[] encoded, String[] decoded) {
			Cipher result = new Cipher();
				result.pushTranslation('a', 'y');
				result.pushTranslation('o', 'e');
				result.pushTranslation('z', 'q');
				result.pushTranslation('q', 'z');
			
			for (int i=0, n=Math.min(encoded.length, decoded.length); i<n; ++i) {
				String e = encoded[i].toLowerCase();
				String d = decoded[i].toLowerCase();
				for (int j=0, m = Math.min(e.length(), d.length()); j<m; ++j) {
					if (!Character.isWhitespace(e.codePointAt(j)) && !Character.isWhitespace(d.codePointAt(j))) {
						result.pushTranslation(d.charAt(j), e.charAt(j));
					}
				}
			}
			return result;
		}
	}
	
	
	
	public static Reader getFileReader(String filename) {
		BufferedReader result = null;
		try {
			result = new BufferedReader(new FileReader(filename));
		}
		catch (FileNotFoundException e) {
			System.err.println("Couldn't find the file \""+filename+"\"");
			e.printStackTrace();
		}
		return result;
	}
	
	
	
	public static String readLine(BufferedReader reader) {
		try {
			return reader.readLine();
		} catch (IOException e) {
			e.printStackTrace();
		}
		return null;
	}
	
	
	
	public static void closeReader(Reader r) {
		try { 
			r.close(); 
		} catch (IOException e) { e.printStackTrace(); }
	}
	
	
	
	public static Writer getFileWriter(String filename) {
		BufferedWriter result = null;
		try {
			result = new BufferedWriter(new FileWriter(filename));
		}
		catch (IOException e) {
			e.printStackTrace();
		}
		return result;
	}
	
	
	
	public static void writeLine(BufferedWriter writer, String line) {
		try {
			writer.write(line);
			writer.newLine();
		} catch (IOException e) { e.printStackTrace(); }
	}
	
	
	
	public static void closeWriter(Writer w) {
		try { 
			w.close(); 
		} catch (IOException e) { e.printStackTrace(); }
	}
	
	
	
	public static String formatCase(int caseNumber, String result) {
		return new StringBuilder("Case #").append(caseNumber).append(": ").append(result).toString();
	}
	
	
	
	public static void main(String[] args) {
		Cipher cipher = Cipher.build(sourceEncoded, sourceDecoded);
		System.out.println(cipher);
		
		BufferedReader in = (BufferedReader) getFileReader(inputFilename);
		int lineCount = Integer.parseInt(readLine(in));
		String[] encoded = new String[lineCount];
		for (int i=0; i<lineCount; ++i) {
			encoded[i] = readLine(in);
		}
		closeReader(in);
		
		// perform the testing
		BufferedWriter out = (BufferedWriter) getFileWriter(inputFilename.replace(".in", ".out"));
		for (int i=0; i<lineCount; ++i) {
			writeLine(out, formatCase(i+1, cipher.decode(encoded[i])));
		}
		closeWriter(out);
	}

}
