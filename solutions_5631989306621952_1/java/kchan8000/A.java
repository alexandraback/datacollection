import java.util.*;
import java.io.*;
import java.math.*;

public class A {
  
  public static void main(String cmdArgs[]) throws Exception {
    long time = System.currentTimeMillis();

    String filename = cmdArgs[0];

    BufferedWriter writer =
      new BufferedWriter(new PrintWriter(filename + "-output.txt", "UTF-8"));
    BufferedReader reader = new BufferedReader(new FileReader(filename));

    String nextLine;
    nextLine = reader.readLine(); // ignore count
    int caseNum = 1;
    while ((nextLine = reader.readLine()) != null) {
      String[] args = nextLine.split(" ");
      writer.write("Case #" + caseNum + ": ");
      alg(writer, args[0]);
      caseNum++;
      writer.newLine();
    }
    writer.close();
    long elapsed = System.currentTimeMillis() - time;
    System.out.println("millis elapsed: " + elapsed);
  }

  public static void alg(BufferedWriter writer, String s)
    throws Exception {
    StringBuilder builder = new StringBuilder();
    char leadingChar = 'A';
    for (char c : s.toCharArray()) {
      if (c >= leadingChar) {
        builder.insert(0, c);
        leadingChar = c;
      } else {
        builder.append(c);
      }
    }
    writer.write(builder.toString());
  }
}
