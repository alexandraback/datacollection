import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Set;

public class lastword {

  public static String getBest(String baseNum){
    String rnt = new String();
    rnt += baseNum.charAt(0);
    for(int i=1; i<baseNum.length(); i++){
      char first = rnt.charAt(0);
      char curr = baseNum.charAt(i);
      if(first > curr){
        rnt = rnt + curr;
      }else{
        rnt = curr+rnt;
      }
    }
    return rnt;
  }
  
  public static void main(String[] args) throws IOException{
   
    BufferedReader br = null;
    
    File fout = new File("output.txt");
    FileOutputStream fos = new FileOutputStream(fout);
   
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(fos));    
    
    try {
      
      String sCurrentLine;

      br = new BufferedReader(new FileReader("A-large.in"));
      
      String testCases = sCurrentLine = br.readLine();
      int testNum = Integer.parseInt(testCases);
      for(int i=0; i<testNum; i++){
        String word = br.readLine();
        String lastRead = getBest(word);
        System.out.println(lastRead);
        bw.write("Case #"+(i+1)+": "+lastRead);
        if(i!=testNum-1)
        bw.newLine();
      }
      bw.close();
      

    } catch (IOException e) {
      e.printStackTrace();
    } finally {
      try {
        if (br != null)br.close();
      } catch (IOException ex) {
        ex.printStackTrace();
      }
    }
  }
}
