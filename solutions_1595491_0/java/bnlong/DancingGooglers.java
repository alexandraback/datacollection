import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class DancingGooglers{

    private static final int NUMBEROFJUDGES = 3;  

    public static void main(String[] args) throws IOException {
        
        BufferedReader br = null; 
        try {
            
        
            br = new BufferedReader(new FileReader("B-small-attempt0.in"));
            PrintStream out = new PrintStream(new File("B-Small.out"));
            
            int testcases = Integer.parseInt(br.readLine());
    
            for (int casenr = 1; casenr <= testcases; casenr++) {
    
                String line = br.readLine();
                Scanner scanner= new Scanner(line);
                
                int numOfGoogler = scanner.nextInt();
                int numOfSurprising = scanner.nextInt();
                int bestResult = scanner.nextInt();
                ArrayList<Integer> totalPoints =new ArrayList<Integer> ();
                
                for (int i=0;i<numOfGoogler ;i++){
                    totalPoints.add(scanner.nextInt());
                }
                Collections.sort(totalPoints, Collections.reverseOrder());
                
                int numberOfBestGoogler = 0;
                for (int i= 0;i<numOfGoogler ;i++){
                    double averagePoint = ((totalPoints.get(i)*1.0)/ NUMBEROFJUDGES);
                    if ( averagePoint > (bestResult-1) ){
                        numberOfBestGoogler++;
                    }
                    else {
                        if ((Math.max((bestResult-2),0)*(NUMBEROFJUDGES-1) <= (totalPoints.get(i)-bestResult) ) && (numOfSurprising>0)) {
                            numOfSurprising--;
                            numberOfBestGoogler++;
                        }
                    }
                        
                }
                
                
                System.out.printf("Case #%d: %d\n", casenr, numberOfBestGoogler);
                out.printf("Case #%d: %s\n", casenr, numberOfBestGoogler);
    
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


