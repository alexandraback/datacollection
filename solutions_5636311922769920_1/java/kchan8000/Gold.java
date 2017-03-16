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
      hard(writer, Integer.valueOf(args[0]), Integer.valueOf(args[1]), Integer.valueOf(args[2]));
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


  // complex case
  public static void hard(BufferedWriter writer, int originLength, int complexity, int looks) throws Exception {
    if (looks * complexity < originLength) {
      writer.write(" IMPOSSIBLE");
      System.out.println("INCONCEIVABLE");
      return;
    }
    BigInteger bigOriginLength = BigInteger.valueOf(originLength);
    
    // need to test each originBit
    int originBitsChecked = 0;
    while (originBitsChecked < originLength) {
      BigInteger index = BigInteger.ZERO;
      for (int c = 1; c < complexity + 1; c++) {
        index = index.add(bigOriginLength.pow(complexity - c).multiply(BigInteger.valueOf(originBitsChecked)));
        originBitsChecked++;
        if (originBitsChecked == originLength) {
          break;
        }
      }
      writer.write(" ");
      // add one because indexes in the problem start at 1
      index = index.add(BigInteger.ONE);
      writer.write(index.toString());
    }
  }
}
