import java.util.*;
import java.io.*;
import java.math.*;

public class Gold {

  
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
      writer.write("Case #" + caseNum + ":");
      dumbAlgTwo(writer, Integer.valueOf(args[0]), Integer.valueOf(args[1]), Integer.valueOf(args[2]));
      caseNum++;
      writer.newLine();
    }
    writer.close();
    long elapsed = System.currentTimeMillis() - time;
    System.out.println("millis elapsed: " + elapsed);
  }

  // dumb interval check algorithm (works for small, not for large problem)
  public static void alg(BufferedWriter writer, int originLength, int complexity, int looks)
    throws Exception {
    System.out.println("" + originLength + "," + complexity + "," + looks);

    BigInteger interval = BigInteger.valueOf(originLength).pow(complexity - 1);
    for (int i = 0; i < looks; i++) {
      BigInteger indexToCheck = interval.multiply(BigInteger.valueOf(i)).add(BigInteger.ONE);
      writer.write(" ");
      writer.write(indexToCheck.toString());
    }
  }

  // just look at the first K
  public static void dumbAlgTwo(BufferedWriter writer, int originLength, int complexity, int looks) throws Exception {
    for (int i = 0; i < looks; i++) {
      writer.write(" ");
      int pos = i + 1;
      writer.write("" + pos);
    }
  }

  public static void hard(BufferedWriter writer, int originLength, int complexity, int looks) {
  }
}
