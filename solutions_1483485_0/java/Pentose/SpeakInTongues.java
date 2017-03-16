import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;


public class SpeakInTongues {
	public static void main(String[] args){
		Map<Character, Character> map = new HashMap<Character, Character>();
		map.put('y', 'a');
		map.put('e', 'o');
		map.put('q', 'z');
		String[] sampleEnc = {"ejp mysljylc kd kxveddknmc re jsicpdrysi", 
				"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
				"de kr kd eoya kw aej tysr re ujdr lkgc jv",
		};
		String[] sampleDec = {"our language is impossible to understand",
				"there are twenty six factorial possibilities",
				"so it is okay if you want to just give up",
		};
		for (int i = 0; i < sampleEnc.length; i++){
			for (int j = 0; j < sampleEnc[i].length(); j++){
				map.put(sampleEnc[i].charAt(j), sampleDec[i].charAt(j));
			}
		}
		// there is one missing, find it...
		int total = 0;
		String charSet = "abcdefghijklmnopqrstuvwxyz ";
		for (Character c : charSet.toCharArray()){
			total += c.charValue();
		}
		int countE = 0, countD = 0;
		for (Character c : map.keySet()){
			countE += c.charValue();
			countD += map.get(c).charValue();
		}
		map.put((char)(total - countE), (char)(total - countD));

		// now start the actual solving
		try{
			BufferedReader in = new BufferedReader(new FileReader("A-small-attempt1.in"));
		
			int cases = Integer.parseInt(in.readLine());
			for (int kase = 0; kase < cases; kase++){
				System.out.println("Case #" + (kase + 1) + ": " + decode(in.readLine(), map));
			}
		}catch(Exception e){
			e.printStackTrace();
		}
	}
	public static String decode(String in, Map<Character, Character> map){
		String out = "";
		for (int i = 0; i < in.length(); i++){
			out += map.get(in.charAt(i));
		}
		return out;
	}
}
