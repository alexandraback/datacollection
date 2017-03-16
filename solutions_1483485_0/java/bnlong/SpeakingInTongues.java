import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;
import java.util.HashMap;
import java.util.Scanner;

public class SpeakingInTongues{

    private final static HashMap<String,String> mDictionary = new HashMap<String,String> ();  
    
    //ejp mysljylc kd kxveddknmc re jsicpdrysi  
    //our language is impossible to understand
    
    //rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
    //there are twenty six factorial possibilities
    
    
    //de kr kd eoya kw aej tysr re ujdr lkgc jv
    //so it is okay if you want to just give up

    private static void initDictionary()
    {
        mDictionary.put("a","y");
        mDictionary.put("b","h");
        mDictionary.put("c","e");
        mDictionary.put("d","s");
        mDictionary.put("e","o");
        mDictionary.put("f","c");
        mDictionary.put("g","v");
        mDictionary.put("h","x");
        mDictionary.put("i","d");
        mDictionary.put("j","u");
        mDictionary.put("k","i");
        mDictionary.put("l","g");
        mDictionary.put("m","l");
        mDictionary.put("n","b");
        mDictionary.put("o","k");
        mDictionary.put("p","r");
        mDictionary.put("q","z");
        mDictionary.put("r","t");
        mDictionary.put("s","n");
        mDictionary.put("t","w");
        mDictionary.put("u","j");
        mDictionary.put("v","p");
        mDictionary.put("x","m");
        mDictionary.put("y","a");
        mDictionary.put("z","q");
        mDictionary.put("w","f");
        mDictionary.put(" "," ");
        
//        System.out.print(mDictionary.get("e"));
    }
    
    public static void main(String[] args) throws IOException {
        
        initDictionary();
        BufferedReader br = null; 
        try {
            
        
            br = new BufferedReader(new FileReader("A-small-attempt0.in"));
            PrintStream out = new PrintStream(new File("A-Small.out"));
            
            int testcases = Integer.parseInt(br.readLine());
    
            for (int casenr = 1; casenr <= testcases; casenr++) {
                String result="";
    
                String line = br.readLine();
                
                for (int i=0 ;i<line.length();i++){
                    char c =line.charAt(i);
                    
                    result += mDictionary.get(String.valueOf(c));
                }
                
                System.out.printf("Case #%d: %s\n", casenr, result);
                out.printf("Case #%d: %s\n", casenr, result);
    
            }
        
        } catch(FileNotFoundException fe) {
            fe.printStackTrace();
        } catch(IOException ie) {
            ie.printStackTrace();
        } finally {
            try {
              if(br != null) {
                 br.close();
              }
            } catch (IOException ex) {
                ex.printStackTrace();
            }  
        }
    }    

}


