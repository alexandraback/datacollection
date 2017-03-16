import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.List;


public class TypewriterMonkey {
	
	public static double MAX = 0;
	public static double AVG = 0;
	public static double N = 0;

	public static void main(String[] args) throws FileNotFoundException, UnsupportedEncodingException {
        String fileName = "B-small-attempt1.in";
        PrintWriter writer = new PrintWriter("B-small-attempt1.out", "UTF-8");
        try {
            List<String> lines = Files.readAllLines(Paths.get(fileName), Charset.defaultCharset());
            int t = Integer.parseInt(lines.get(0));
            for (int i = 0; i < t; i++) {
            	String line[] =  lines.get(3*i+1).split(" ");
            	int k = Integer.parseInt(line[0]);
            	int l = Integer.parseInt(line[1]);
            	int s = Integer.parseInt(line[2]);
            	String keyboard = lines.get(3*i+2);
            	String targetWord = lines.get(3*i+3);
            	writer.println("Case #"+(i+1)+": "+typewriterMonkey(k,l,s,keyboard,targetWord));
            }
            writer.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
	}
	
	public static double typewriterMonkey(int k, int l, int s, String keyboard, String targetWord) {
		MAX = 0;
		AVG = 0;
		N = 0;
		for (int i = 0; i < l; i++){
			if(!keyboard.contains(""+targetWord.charAt(i))) return 0.0;
		}
		char[] chars = keyboard.toCharArray();
		iterate(chars, s, new char[s], 0, targetWord);
		return MAX - AVG/N;
	}
	
    public static void iterate(char[] chars, int len, char[] build, int pos, String targetWord) {
    	if (pos == len) {
            String word = new String(build);
            double freq = freq(word,targetWord);
		    if(freq > MAX) MAX = freq;
			AVG += freq;
			N++;
			return;
        }

        for (int i = 0; i < chars.length; i++) {
            build[pos] = chars[i];
            iterate(chars, len, build, pos + 1, targetWord);
        }
        
    }
	
	public static int freq(String word, String targetWord) {
		int count = 0;
		
		int l = targetWord.length();

		for (int i = 0; i < word.length() - l+1; i++) {
			String sub = (String)word.subSequence(i, i+l);
			if (sub.equals(targetWord)) count++;
		}

		return count;
	}

}
