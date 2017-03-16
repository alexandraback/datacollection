package roundC;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashSet;
import java.util.Scanner;

public class Consonants {
    
    
    public static void main(String[] args) throws IOException {
        if (args.length != 2) {
            System.out.println("You should supply two file names (input and output files)");
            return;
        }
        //a, e, i, o, and u
        vowels.add('a');
        vowels.add('e');
        vowels.add('i');
        vowels.add('o');
        vowels.add('u');
        
        new Consonants().run(args);
    }
    
    static HashSet<Character> vowels = new HashSet<Character>();
    
    private void run(String[] args) throws IOException {
        Scanner scan = new Scanner(new File(args[0]));
        StringBuffer writer = new StringBuffer();
        int T = scan.nextInt();
        
        for (int i=0; i<T; i++) {            
            String word = scan.next();
            int n = scan.nextInt();                    
            writer.append(String.format("Case #%d: %s", i+1, solve(word, n)));
            writer.append("\n");
            scan.nextLine();
        }
        FileWriter fw = new FileWriter(args[1]);
        fw.write(writer.toString());        
        fw.close();
        
        System.out.println(writer.toString());
    }
    
    static boolean isVowel(char c) {
        return vowels.contains(c);
    }

    private int solve(String word, int n) {
        int len = word.length();
        HashSet<String> substrings = new HashSet<String>();
        
        int start = -1;
        int count = 0;
        int totalSubsCount = 0;
        int prevStart = -1;
        boolean firstConsonantProcessed = false;
        for (int i=0; i<len; i++) {
            char c = word.charAt(i);
            if (isVowel(c)) {
                start = -1;
                count = 0;
            } else { // consonant
                if (start == -1) {
                    start = i;
                }
                count++;
                if (count >= n) {
                    int subsCount = len - start - n + 1;
                    if (!firstConsonantProcessed) {
                        totalSubsCount += (start + 1) * subsCount;
                        firstConsonantProcessed = true;                        
                    } else {                        
                        totalSubsCount += (start - prevStart) * subsCount;                        
                    }
                    prevStart = start;
                    
                    i -= count - 1;
                    start = -1;
                    count = 0;
                }
            }
        }
        
        
        return totalSubsCount;
    }    
}
