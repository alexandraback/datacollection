import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Created by juanc on 15-Apr-16.
 */
public class TheLastWord {
    private static Scanner sn;
    private static PrintWriter writer;
    private final static boolean INLINE = true;
    private final static String INPUT = "A-small-attempt0 (1).in";
    private final static String OUTPUT = "answer";


    public static void main(String[] args) throws IOException {
        sn = Input.getScanner("resources/" + INPUT);
        writer = new PrintWriter("resources/" + OUTPUT);
        int T = Integer.parseInt(sn.nextLine());
        for(int i = 1; i<=T; i++){
            if(INLINE)
                writer.print("Case #" + i + ": ");
            else
                writer.println("Case #" + i + ":");
            TheLastWordMain();
        }
        writer.close();

    }

    private static void TheLastWordMain(){
        String word = sn.nextLine();
        char[] array = word.substring(1).toCharArray();
        StringBuilder sb = new StringBuilder(word.charAt(0));
        char current = word.charAt(0);
        for(char c:word.toCharArray()){
            if(current<=c){
                sb.insert(0,c);
                current = c;
            }else{
                sb.append(c);
            }
        }
        writer.println(sb.toString());

    }
}
