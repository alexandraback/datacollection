import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.Set;

public class rankfile {

  public static String missNum(ArrayList<String> nums, int n){
    HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
    for(int i=0; i<nums.size(); i++){
      String[] item = nums.get(i).split(" ");
      for(String valstr : item){
        int val = Integer.parseInt(valstr);
        if(map.containsKey(val)){
          map.put(val, map.get(val)+1);
        }else{
          map.put(val,1);
        }       
      }
    }
    ArrayList<Integer> rnt = new ArrayList<Integer>();
    for(Integer val : map.keySet()){
      if(map.get(val)%2==1){
        rnt.add(val);
      }
    }
    
    Collections.sort(rnt);
    String target = new String();
    for(int i=0; i<rnt.size(); i++){
      if(i!=rnt.size()-1){
        target = target + rnt.get(i)+ " ";
      }else{
        target = target + rnt.get(i);
      }
    }
    return target;
  }
  
  public static void main(String[] args) throws IOException{
   
    BufferedReader br = null;
    
    File fout = new File("output.txt");
    FileOutputStream fos = new FileOutputStream(fout);
   
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(fos));    
    
    try {
      
      String sCurrentLine;

      br = new BufferedReader(new FileReader("B-small-attempt0.in"));
      
      String testCases = sCurrentLine = br.readLine();
      int testNum = Integer.parseInt(testCases);
      for(int i=0; i<testNum; i++){
        int startNum = Integer.parseInt(br.readLine());
        ArrayList<String> lists = new ArrayList<String>();
        for(int j=0; j<2*startNum-1; j++){
          lists.add(br.readLine());
        }
        String lastRead = missNum(lists,startNum);
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
