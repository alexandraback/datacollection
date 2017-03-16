package codejam;

import java.io.*;
import java.util.Scanner;


public final class ReadWriteTextFile {


  
  /** Constructor. */
  ReadWriteTextFile(){
        try {
                out =new BufferedWriter(new FileWriter("output.in"));
            
                
              scanner = new Scanner(new FileInputStream("input.in"));
              

        } catch (FileNotFoundException ex) {
                  }catch (IOException ex) {
                
            }
  
      
  }
  
  /** Write fixed content to the given file. */
  void writeNextLine(int text)   {
        try {
            out.write("Case #"+lineNumber +": "+text+"\r\n");
  
            System.out.println("Case #"+lineNumber +": "+text);
            
        } catch (IOException ex) {
            
                 }
    
   lineNumber++;
  }
  /** Write fixed content to the given file. */
  void writeNextLine(String text)   {
        try {
            out.write("Case #"+lineNumber +": "+text+"\r\n");
  
            System.out.println("Case #"+lineNumber +": "+text);
            
        } catch (IOException ex) {
            
                 }
    
   lineNumber++;
  }
   String readLine()  {
    
       
 
       String output = null;
       if(scanner.hasNext())
       {
       output = scanner.nextLine();
       }
    return output;
    
  }
   int readIntLine(){
    
    String output = scanner.nextLine();  
       return Integer.decode(output).intValue();
   }
   int readInt(){
    
       int x = scanner.nextInt();
       
       return x;
   }
   
   public void close()
   {
        try {
            out.close();
        } catch (IOException ex) {
              }
   scanner.close();
   }
  // PRIVATE 
  private int lineNumber = 1;
  private BufferedWriter out = null;
  private Scanner scanner = null;
  
}