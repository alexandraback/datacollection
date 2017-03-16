package main;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.regex.Pattern;

public class Main {

  public static String changeLine = System.getProperty("line.separator");

  public static void main(String[] args) throws FileNotFoundException, IOException {
    new Main();
  }

  long n;
  int k,l,s;
  int maxRepeat;
  long repeatCount;
  char [] str;
  char [] current;
  String target;
  double result;
  Pattern pat;
 // Matcher matcher = new Matcher();

  public Main() throws FileNotFoundException, IOException {
    BufferedReader br = new BufferedReader(new FileReader("D:/B-small-attempt0.in"));
    BufferedWriter bw = new BufferedWriter(new FileWriter("D:/result.txt"));
    int cases = Integer.parseInt(br.readLine());
    for (int caseNum = 0; caseNum < cases; caseNum++) {
      String[] split = br.readLine().split(" ");
      k = Integer.parseInt(split[0]);
      l = Integer.parseInt(split[1]);
      s = Integer.parseInt(split[2]);
      current = new char[s];
      String kk = br.readLine();
      str = kk.toCharArray();
      target = br.readLine();
      pat = Pattern.compile(target);
      double all = Math.pow(k, s);
      maxRepeat = 0;
      repeatCount = 0;
      count(0);
      result = maxRepeat - (repeatCount / all);
      // output
      System.out.println(getResult(caseNum));
      bw.write(getResult(caseNum));
      bw.write(changeLine);
    }
    br.close();
    bw.close();
  }

  public String getResult(int caseNum) {
    String str = "Case #" + (caseNum + 1) + ": ";
    str += result;
    return str;
  }

  public void count(int depth) {
    for (int i = 0; i < k; i++) {
      current[depth] = str[i];
      if (depth == s - 1) {
        //Matcher m = pat.matcher(new String(current));
        int repeat = 0;//m.groupCount();
        String temp = new String(current);
        while (true) {
          int ind = temp.indexOf(target);
          if (ind != -1) {
            repeat ++;
            temp = temp.substring(ind + 1);
          } else {
            break;
          }
        }
        if (repeat > maxRepeat) {
          maxRepeat = repeat;
        }
        repeatCount += repeat;
        //TODO
      } else {
        count(depth + 1);
      }
    }
  }
}
