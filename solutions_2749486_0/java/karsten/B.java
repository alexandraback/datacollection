import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;

public class B {
  public static void main(String[] args) throws Exception {
    if (args.length != 2) {
      System.err.println("Usage: java B <input> <output>");
      System.exit(1);
    }
    BufferedReader br = new BufferedReader(new FileReader(args[0]));
    new File(args[1]).getParentFile().mkdirs();
    BufferedWriter bw = new BufferedWriter(new FileWriter(args[1]));
    String line;
    line = br.readLine();
    int num = 1;
    while ((line = br.readLine()) != null) {
      if (line.length() == 0) {
        continue;
      }
      String[] parts = line.split(" ");
      int targetX = Integer.parseInt(parts[0]);
      int targetY = Integer.parseInt(parts[1]);
      StringBuilder sb = new StringBuilder();
      int curX = 0, curY = 0, nextDist = 1;
      while (curX != targetX) {
        if (targetX < 0) {
          curX += nextDist++;
          curX -= nextDist++;
          sb.append("EW");
        } else {
          curX -= nextDist++;
          curX += nextDist++;
          sb.append("WE");
        }
      }
      while (curY != targetY) {
        if (targetY < 0) {
          curY += nextDist++;
          curY -= nextDist++;
          sb.append("NS");
        } else {
          curY -= nextDist++;
          curY += nextDist++;
          sb.append("SN");
        }
      }
      bw.write("Case #" + num++ + ": " + sb.toString() + "\n");
    }
    br.close();
    bw.close();
  }
}

