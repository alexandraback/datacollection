import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;


public class RecycledNumbers{

    public static void main(String[] args) throws IOException {
        
        BufferedReader br = null; 
        try {
            
        
            br = new BufferedReader(new FileReader("C-small-attempt0.in"));
            PrintStream out = new PrintStream(new File("C-Small.out"));
            
            int testcases = Integer.parseInt(br.readLine());
    
            for (int casenr = 1; casenr <= testcases; casenr++) {
    
                String line = br.readLine();
                Scanner scanner= new Scanner(line);
                
                int min = scanner.nextInt();
                int max = scanner.nextInt();

                HashSet <String> recycledPairs  = new HashSet <String> ();
                
                for (int i = min ;i<= max ;i++){
                    String numberString = String.valueOf(i);
                    int strLen = numberString.length();
                    if (strLen <= 1) continue;
                    
                    for (int j = 0 ;j< strLen;j++){
                        
                        char firstChar= numberString.charAt(0);
                        numberString = numberString.substring(1).concat(String.valueOf(firstChar));
                        
                        int  newNumber= Integer.parseInt(numberString);
                        
                        if ( (newNumber > i) && newNumber >=  min && newNumber <= max ){

                            String pair = String.valueOf(i)+","+String.valueOf(newNumber);

                            recycledPairs.add(pair);
                            
                        }
                    
                    }                    
                    
                }
                
                
                System.out.printf("Case #%d: %d\n", casenr, recycledPairs.size());
                out.printf("Case #%d: %s\n", casenr, recycledPairs.size());
    
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


