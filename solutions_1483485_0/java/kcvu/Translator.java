public class Translator { 
	static final String MAP = "yhesocvxduiglbkrztnwjpfmaq";
	static final char BIG_A = 65;
	static final char BIG_Z = 90;
	static final char SMALL_A = 97;
	static final char SMALL_Z = 122;
	
	public String translate (String str) {
		int len = str.length();
		StringBuffer res = new StringBuffer(len);
		for (int i=0; i<len; i++) {
			char c = str.charAt(i);
			char o = c;
			if (c>=BIG_A && c<=BIG_Z) {
				o = (char) (MAP.charAt(c-BIG_A) - (SMALL_A-BIG_A));
			}
			else if (c>=SMALL_A && c<=SMALL_Z) {
				o = MAP.charAt(c-SMALL_A);
			}
			res.append(o);
		}
		return res.toString();
	}
   
   
}
