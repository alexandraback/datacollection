package codejam.tounges;

import codejam.is.TestAbstract;

import java.util.HashMap;
import java.util.Map;

/**
 * Created with IntelliJ IDEA.
 * User: ofer
 * Date: 4/14/12
 * Time: 2:18 AM
 * To change this template use File | Settings | File Templates.
 */
public class ToungeTest extends TestAbstract {

    private static String googlerese = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
    private static String orig = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";

    Map<Character, Character> map = new HashMap<Character, Character>();

    public ToungeTest() {

        for (int i = 0; i < googlerese.length(); i++) {
            if (googlerese.charAt(i) != ' ') {
                map.put(googlerese.charAt(i), orig.charAt(i));
            }
        }

        map.put(' ', ' ');
        map.put('z', 'q');
        map.put('q', 'z');
    }


    @Override
    public void run(String s) {
        for (int i = 0; i < s.length(); i++) {
            output.append(map.get(s.charAt(i)));
        }
    }
}
