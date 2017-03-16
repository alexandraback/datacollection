package codejam;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Gedion Moyo
 */
public class tongues {

    /**
     * @param args the command line arguments
     */
    
    public static HashMap<String,String> map = Googlerese();
    
    public static void main(String[] args) {
        try {
            solve();
        } catch (Exception ex) {
            Logger.getLogger(tongues.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    public static void solve() throws Exception {
        Scanner in = new Scanner(new FileReader("src/codejam/input.txt"));
        PrintWriter out = new PrintWriter(new FileWriter("src/codejam/output.txt"));

        int caseCount = Integer.valueOf(in.nextLine());
        for (int caseNum = 0; caseNum < caseCount; caseNum++) {
            System.out.println("solving case " + caseNum);
            
            out.print("Case #" + (caseNum + 1) + ":");
            out.print(" ");
            String line = in.nextLine();
            out.print(translate(line));
            out.print("\n");
        }
        out.flush();
        out.close();
        in.close();

    }
    
    public static String translate(String text){
        String[] textArray = text.split("");
        text = "";
        for(int i =0; i<textArray.length;i++){
            text = text+map.get(textArray[i]);
        }
        return text;
    }
    public static HashMap<String,String> Googlerese(){
        HashMap<String, String> map = new HashMap<>();
        String input = "ejp mysljylc kd kxveddknmc re jsicpdrysi"
                + "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd"
                + "de kr kd eoya kw aej tysr re ujdr lkgc jv";
        String output = "our language is impossible to understand"
                + "there are twenty six factorial possibilities"
                + "so it is okay if you want to just give up";
        String[] IN = input.split("");
        String[] OUT = output.split(""); 
        map.put("z", "q");
        map.put("q", "z");
        for(int i=0;i<IN.length;i++){
            map.put(IN[i], OUT[i]);
            //map.put(OUT[i], IN[i]);
        } 
        
        return map;
    }
}
