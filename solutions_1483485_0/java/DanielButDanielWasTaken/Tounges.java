import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;

/**
 * Date: 14/4/12
 * Time: 9:16 AM
 */
public class Tounges {

    private static HashMap<Character,Character> mapping = new HashMap<Character, Character>();

    public static void constructMapping() {
        String input = "ejp mysljylc kd kxveddknmc re jsicpdrysi" +
        "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd" +
        "de kr kd eoya kw aej tysr re ujdr lkgc jv";

        String output = "our language is impossible to understand" +
        "there are twenty six factorial possibilities" +
        "so it is okay if you want to just give up";

        mapping.put('y','a');
        mapping.put('e','o');
        mapping.put('q','z');
        mapping.put('z','q');

        for( int i = 0; i < input.length();i++)
        {
            if( mapping.containsKey(input.charAt(i)) && mapping.get(input.charAt(i) ) != output.charAt(i ) )
                throw new RuntimeException( "Found bad char." );

            mapping.put(input.charAt(i),output.charAt(i));
        }
        if( mapping.size() != 27 )
            throw new RuntimeException("Unknown letter exception");
    }

    public static void main(String[] args) throws IOException {
        constructMapping();

        ArrayList<String> al = GoogleFileStream.getInput();

        ArrayList<String> ret = new ArrayList<String>();
        for( String i : al )
        {
            StringBuilder sb = new StringBuilder();
            for( int c = 0; c < i.length(); c++ )
                sb.append( mapping.get(i.charAt(c)) );

            ret.add(sb.toString());
        }

        GoogleFileStream.setOutput(ret);
    }
}
