import java.io.*;
import java.nio.charset.*;
import java.nio.file.*;
import java.util.*;

public class Pancakes {

  public static void main(String[] args) {
    String file = args[0];
    List<String> cases = new ArrayList<>();

    Path inPath = FileSystems.getDefault().getPath(file);
    try (BufferedReader reader = Files.newBufferedReader(inPath)) {
      String line = null;
      boolean firstLine = true;
      while ((line = reader.readLine()) != null) {
        if (firstLine) {
          firstLine = false;
        } else {
          cases.add(line);
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
        String out = "Case #" + caseNumber + ": " + flip(cases.get(i));
        writer.write(out, 0, out.length());
        if (i != cases.size() - 1) {
          writer.newLine();
        }
      }
    } catch (IOException e) {
      System.err.format("IOException - %s", e);
    }

  }

  private static int flip(String s) {
    if (s == null || s.equals("")) {
      return 0;
    }
    char start = s.charAt(0);
    int sectors = 1;
    char current = start;
    for (int i = 1; i < s.length(); i++) {
      if (current != s.charAt(i)) {
        sectors++;
        current = s.charAt(i);
      }
    }

    if (start == '-') {
      if (sectors % 2 == 1) {
        return sectors;
      } else {
        return sectors - 1;
      }
    } else {
      if (sectors % 2 == 1) {
        return sectors - 1;
      } else {
        return sectors;
      }
    }
  }

}
