import java.nio.file.*;
import java.nio.charset.*;
import java.io.*;
import java.util.*;

public class CountSheep {

  public static void main(String[] args) {
    String file = args[0];
    List<Integer> cases = new ArrayList<>();

    Path inPath = FileSystems.getDefault().getPath(file);
    try (BufferedReader reader = Files.newBufferedReader(inPath)) {
      String line = null;
      boolean firstLine = true;
      while ((line = reader.readLine()) != null) {
        if (firstLine) {
          firstLine = false;
        } else {
          cases.add(Integer.parseInt(line));
        }
      }
    } catch (IOException e) {
      System.err.format("IOException - %s", e);
    }

    Charset charset = Charset.forName("UTF-8");
    Path outPath = FileSystems.getDefault().getPath("out.txt");
    try (BufferedWriter writer = Files.newBufferedWriter(outPath, charset)) {
      for (int i = 0; i < cases.size(); i++) {
        int caseNumber = i + 1;
        String out = "";
        if (cases.get(i) == 0) {
          out = "Case #" + caseNumber + ": " + "INSOMNIA";
        } else {
          out = "Case #" + caseNumber + ": " + multiply(cases.get(i));
        }
        writer.write(out, 0, out.length());
        if (i != cases.size() - 1) {
          writer.newLine();
        }
      }
    } catch (IOException e) {
      System.err.format("IOException - %s", e);
    }
  }

  private static int multiply(int n) {
    boolean[] digits = new boolean[10];
    int digitCount = 0;
    int current = n;

    while (digitCount != 10) {
      int temp = current;
      while (temp != 0) {
        int digit = temp % 10;
        if (!digits[digit]) {
          digits[digit] = true;
          digitCount++;
        }
        temp /= 10;
      }
      current += n;
    }

    return (current - n);
  }

}
