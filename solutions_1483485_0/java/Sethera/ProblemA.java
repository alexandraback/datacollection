import java.io.*;
import java.util.*;

/**
 *
 * @author Hilos
 */
public class ProblemA {

    public static BufferedWriter bw;
    public static BufferedReader br;

    public static void main(String[] args) {
        try {            
            String problemSize = "small";
            //String problemSize = "large";
            br = new BufferedReader(new FileReader("E:\\Downloads\\A-" + problemSize +  "-attempt0.in"));
            bw = new BufferedWriter(new FileWriter("E:\\Downloads\\A-" + problemSize +  "-attempt0.out"));
            //bw = new BufferedWriter(new OutputStreamWriter(System.out));

            String cypher = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv y qee z";
            String plain =  "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up a zoo q";
            
            HashMap translationMap = new HashMap();
              
            int charCount = cypher.length();
            for(int c = 0; c<charCount; c++){
                char cyp = cypher.charAt(c);
                char pla = plain.charAt(c);
                if(translationMap.containsKey(cyp)){
                    if(translationMap.get(cyp) != pla){
                        System.out.println("you have a problem sir");
                    }
                }else{
                    translationMap.put(cyp, pla);
                }
            }
            
            /* find that missing character
            String alphas = "abcdefghijklmnopqrstuvwxyz";
            for(int c = 0; c<26; c++){
                if(!translationMap.containsKey(alphas.charAt(c))){
                    System.out.println("key missing: " + c);
                }
                if(!translationMap.containsValue(alphas.charAt(c))){
                    System.out.println("value missing: " + c);                    
                }
            }*/
            
            
            
            int caseCount = Integer.parseInt(br.readLine());
            
            for (int c = 0; c < caseCount; c++) {
                String caseLine = br.readLine();
                SolveCase(c + 1, translationMap, caseLine);
            }

        } catch (Exception exc) {
            System.out.println(exc.toString());
        }
    }

    public static void SolveCase(int caseNumber, HashMap translationMap, String caseLine) throws Exception {
        int lineLength = caseLine.length();
        
        String result = "";
        
        for(int i = 0; i< lineLength; i++){
            char caseChar = caseLine.charAt(i);
            result += translationMap.get(caseChar);
        }

        bw.write("Case #" + String.valueOf(caseNumber) + ": " + result + "\n");
        bw.flush();                    
    }
}
