import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Iterator;
import java.util.LinkedList;

public class LastWord {
    private static final String CASE = "Case #";

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out), true);

        int tcs = Integer.parseInt(br.readLine());

        for (int t = 1; t <= tcs; ++t) {
            String opFormat = CASE + t + ": ";
            String word = br.readLine();
            LinkedList<Character> lastWord = new LinkedList<Character>();
            int wordLen = word.length();
            if (wordLen == 1) {
                lastWord.add(word.charAt(0));
            } else {
                char firstLetter = word.charAt(0);
                lastWord.add(firstLetter);
                for (int i = 1; i < wordLen; ++i) {
                    if(word.charAt(i)>=firstLetter){
                        lastWord.addFirst(word.charAt(i));
                        firstLetter = word.charAt(i);
                    }else{
                        lastWord.add(word.charAt(i));
                    }
                }
            }
            pw.print(opFormat);
            
            Iterator<Character> lastWordIterator = lastWord.iterator();
            while(lastWordIterator.hasNext()){
                pw.print(lastWordIterator.next());
            }
            pw.println();
        }

        pw.flush();
        pw.close();
        br.close();
    }
}

