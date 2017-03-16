/*

 */
package cj2016;

import java.io.*;
//import java.math.BigInteger;
import java.util.*;
//import java.math.*;

/**
 *
 *  
 */
public class CJ2016 {

  /**
   * 
   */
  public static void main(String[] args) throws Exception {
    //long mainStartTime = System.nanoTime();
		CJ2016 cj = new CJ2016();
		cj.run();
		//double dur = (1.0 * System.nanoTime() - mainStartTime) / 1000000000;
		//System.out.println("main elapsed time: " + String.format("%.3f", dur) + " sec");
	}
  
  public void run() throws Exception {
		long result = 0;
		//String info = "";
		//long count = 0;
		//long MAX = 1000000000000L;
		//long perc = MAX / 100;
    //System.out.println("Starting run.");
    
    String infile = "in.txt";
    String outfile = "out.txt";
    BufferedReader br = new BufferedReader(new FileReader(infile));
    PrintWriter pw = new PrintWriter(new FileWriter(outfile));
    
    int T = Integer.parseInt(br.readLine());
    
    for (int cas = 1; cas <= T; cas++) {
      String line = br.readLine();
      //String[] line_parts = line.split(" ");
      //int N = Integer.parseInt(line_parts[0]);  // length of coin
      //int J = Integer.parseInt(line_parts[1]);  // number of coins
      
      Map<Character,Integer> data = new HashMap<>();
      List<Integer> phone = new ArrayList<>();
      char[] chars = line.toCharArray();
      for (char c : chars) {
        if (data.get(c) == null) {
          data.put(c, 1);
        } else {
          data.put(c, data.get(c) + 1);
        }
      }
      
      boolean changed = true;
      while (changed) {
        changed = false;
        
        // 0
        if (data.get('Z') != null) {
          phone.add(0);
          data.put('Z', data.get('Z') - 1);
          data.put('E', data.get('E') - 1);
          data.put('R', data.get('R') - 1);
          data.put('O', data.get('O') - 1);
          changed = true;
        }
        
        // 2
        if (data.get('W') != null) {
          phone.add(2);
          data.put('T', data.get('T') - 1);
          data.put('W', data.get('W') - 1);
          data.put('O', data.get('O') - 1);
          changed = true;
        }
        
        // 4
        if (data.get('U') != null) {
          phone.add(4);
          data.put('F', data.get('F') - 1);
          data.put('O', data.get('O') - 1);
          data.put('U', data.get('U') - 1);
          data.put('R', data.get('R') - 1);
          changed = true;
        }
        
        // 6
        if (data.get('X') != null) {
          phone.add(6);
          data.put('S', data.get('S') - 1);
          data.put('I', data.get('I') - 1);
          data.put('X', data.get('X') - 1);
          changed = true;
        }
        
        // 8
        if (data.get('G') != null) {
          phone.add(8);
          data.put('E', data.get('E') - 1);
          data.put('I', data.get('I') - 1);
          data.put('G', data.get('G') - 1);
          data.put('H', data.get('H') - 1);
          data.put('T', data.get('T') - 1);
          changed = true;
        }
        
        clean(data);
        
      }
      
      // now 1 3 5 7 9
      changed = true;
      while (changed) {
        changed = false;
        
        // 5
        if (data.get('F') != null) {
          phone.add(5);
          data.put('F', data.get('F') - 1);
          data.put('I', data.get('I') - 1);
          data.put('V', data.get('V') - 1);
          data.put('E', data.get('E') - 1);
          changed = true;
          clean(data);
          continue;
        }
        
        // 9
        if (data.get('I') != null) {
          phone.add(9);
          data.put('N', data.get('N') - 1);
          data.put('I', data.get('I') - 1);
          data.put('N', data.get('N') - 1);
          data.put('E', data.get('E') - 1);
          changed = true;
          clean(data);
          continue;
        }
        
        // 7
        if (data.get('V') != null) {
          phone.add(7);
          data.put('S', data.get('S') - 1);
          data.put('E', data.get('E') - 1);
          data.put('V', data.get('V') - 1);
          data.put('E', data.get('E') - 1);
          data.put('N', data.get('N') - 1);
          changed = true;
          clean(data);
          continue;
        }
        
        // 1
        if (data.get('O') != null) {
          phone.add(1);
          data.put('O', data.get('O') - 1);
          data.put('N', data.get('N') - 1);
          data.put('E', data.get('E') - 1);
          changed = true;
          clean(data);
          continue;
        }
        
        // 1
        if (data.get('T') != null) {
          phone.add(3);
          data.put('T', data.get('T') - 1);
          data.put('H', data.get('H') - 1);
          data.put('R', data.get('R') - 1);
          data.put('E', data.get('E') - 1);
          data.put('E', data.get('E') - 1);
          changed = true;
          clean(data);
          continue;
        }
        
        
      }
      
      // sort
      Object[] ia = phone.toArray();
      Arrays.sort(ia);
      
      String ans = "";
      for (Object i : ia) {
        ans += ((Integer)i).intValue();
      }
      
      pw.println("Case #" + cas + ": " + ans);
      
    }   // end loop thru all cases
    br.close();
    pw.close();
  }  // end run
  
  private static void clean (Map<Character, Integer> map) {
    boolean changed = true;
    while (changed) {
      changed = false;
      char toRemove = '0';
      
      for (Character c : map.keySet()) {
        if (map.get(c) == 0) {
          toRemove = c;
          changed = true;
          break;
        }
      }
      
      if (changed) {
        map.remove(toRemove);
      }
      
    }
    
    
  }

  
  
}

class Helper {

  
  @Override
  public String toString() {
    String s = "";
    return s;
  }
  

  public boolean isValid() {
    boolean valid = true;
    return valid;
  }

}

