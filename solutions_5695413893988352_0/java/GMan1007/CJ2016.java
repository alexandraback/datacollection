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
      String[] line_parts = line.split(" ");
      String C = line_parts[0];
      String J = line_parts[1];
      char[] CA = C.toCharArray();
      char[] JA = J.toCharArray();
      char bigger = 'U';
      
      Board board = new Board();
      board.C = CA;
      board.J = JA;
      
      board = process(board);
      
      
      String ans = board.toString();
      
      pw.println("Case #" + cas + ": " + ans);
      
    }   // end loop thru all cases
    br.close();
    pw.close();
  }  // end run
  
  private Board process(Board board) throws Exception {
    int i = 0; 
    char bigger = 'U';
    while (i < board.C.length &&
            board.C[i] != '?' && 
            board.J[i] != '?') {
      if (bigger == 'U') {
        if (board.C[i] > board.J[i])
          bigger = 'C';
        else if (board.C[i] < board.J[i])
          bigger = 'J';
      }
      i++;
    }
    if (i == board.C.length) {
      return board;  //nothing to do. 
    }
    
    List<Board> test = new ArrayList<>();
    
    // i is the first ? we have found. 
    if (board.C[i] == '?' && board.J[i] == '?') {
      if (bigger == 'U') { 
        Board b1 = board.clone();
        b1.C[i] = '0';
        b1.J[i] = '0';
        test.add(b1);
        Board b2 = board.clone();
        b2.C[i] = '0';
        b2.J[i] = '1';
        test.add(b2);
        Board b3 = board.clone();
        b3.C[i] = '1';
        b3.J[i] = '0';
        test.add(b3);
      } else if (bigger == 'C') {
        Board b1 = board.clone();
        b1.C[i] = '0';
        b1.J[i] = '9';
        test.add(b1);
      } else if (bigger == 'J') {
        Board b1 = board.clone();
        b1.C[i] = '9';
        b1.J[i] = '0';
        test.add(b1);
      }
    } else if (board.C[i] == '?') {
      if (bigger == 'U') {
        if (board.J[i] != '0') {
          Board b3 = board.clone();
          b3.C[i] = (char) (b3.J[i] - 1);
          test.add(b3);
        }
        Board b1 = board.clone();
        b1.C[i] = b1.J[i];
        test.add(b1);
        if (board.J[i] != '9') {
          Board b2 = board.clone();
          b2.C[i] = (char) (b2.J[i] + 1);
          test.add(b2);
        } 
      } else if (bigger == 'C') {
        Board b1 = board.clone();
        b1.C[i] = '0';
        test.add(b1);
      } else if (bigger == 'J') {
        Board b1 = board.clone();
        b1.C[i] = '9';
        test.add(b1);
      }
    } else if (board.J[i] == '?') {
      if (bigger == 'U') {
        if (board.C[i] != '0') {
          Board b3 = board.clone();
          b3.J[i] = (char) (b3.C[i] - 1);
          test.add(b3);
        }
        Board b1 = board.clone();
        b1.J[i] = b1.C[i];
        test.add(b1);
        if (board.C[i] != '9') {
          Board b2 = board.clone();
          b2.J[i] = (char) (b2.C[i] + 1);
          test.add(b2);
        } 
      } else if (bigger == 'C') {
        Board b1 = board.clone();
        b1.J[i] = '9';
        test.add(b1);
      } else if (bigger == 'J') {
        Board b1 = board.clone();
        b1.J[i] = '0';
        test.add(b1);
      }
    }
    
    for (int j = 0; j < test.size(); j++) {
      Board res = process(test.get(j));
      test.set(j, res);
    }
    int bestIndex = 0;
    long bestDiff = test.get(0).getDiff();
    for (int j = 1; j < test.size(); j++) {
      long diff = test.get(j).getDiff();
      if ( 
              ( Math.abs(diff) < Math.abs(bestDiff) ) 
          /*    ||
              (
                ( Math.abs(diff) == Math.abs(bestDiff) )
                &&
                ( diff < bestDiff )   // when c is smaller than j
              )
          */
          ) {
        bestIndex = j;
        bestDiff = diff;
      }
    }
    
    
    return test.get(bestIndex);
  }
  
  
  
}

class Board implements Cloneable {
  public char[] C;
  public char[] J;
  
  @Override
  public String toString() {
    String s = "";
    for (char c : C )
      s += c;
    s += " ";
    for (char j : J )
      s += j;
    return s;
  }
  
  public long getDiff() {
    String sc = new String(C);
    String sj = new String(J);
    Long lc = Long.parseLong(sc);
    Long lj = Long.parseLong(sj);
    return (lc - lj);
    
  }
  

  public boolean isValid() {
    boolean valid = true;
    return valid;
  }
  
  @Override
  public Board clone() throws CloneNotSupportedException {
    Board b = (Board) super.clone();
    b.C = Arrays.copyOf(C, C.length);
    b.J = Arrays.copyOf(J, J.length);
    return b;
  }

}

