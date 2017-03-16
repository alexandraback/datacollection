import java.util.*;

public class SpeakingTongues {

    private static HashMap<Character, Character> themap = new HashMap<Character, Character>();
    
    public static void main(String[] args) {
        SpeakingTongues s = new SpeakingTongues();
        String source1 = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
        String dest1 = "our language is impossible to understand";
        String source2 = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
        String dest2 = "there are twenty six factorial possibilities";
        String source3 = "de kr kd eoya kw aej tysr re ujdr lkgc jv";
        String dest3 = "so it is okay if you want to just give up";
        for (int i = 0; i < source1.length(); i++)
            themap.put(source1.charAt(i), dest1.charAt(i));
        for (int i = 0; i < source2.length(); i++)
            themap.put(source2.charAt(i), dest2.charAt(i));
        for (int i = 0; i < source3.length(); i++)
            themap.put(source3.charAt(i), dest3.charAt(i));
        themap.put('q', 'z');
        themap.put('z', 'q');
        Scanner in = new Scanner(System.in);
        int cases = Integer.parseInt(in.nextLine());
        for (int i = 0; i < cases; i++) {
            System.out.printf("Case #%d: %s\n", i+1, s.solve(in));
        }
    }
    
    private String solve(Scanner in) {
	String s = in.nextLine();
	String translated = "";
	for (int i = 0; i < s.length(); i++)
	    translated += themap.get(s.charAt(i));
	return translated;
    }

}
