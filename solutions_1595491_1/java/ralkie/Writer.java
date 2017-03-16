package lt.kasrud.gcj.common.io;

import java.io.*;
import java.util.List;

public class Writer {
  private static String formatCase(int caseNr, String output){
    return String.format("Case #%d: %s", caseNr, output);
  }

  public static void writeFile(String filename, List<String> data) throws IOException {
    BufferedWriter writer = new BufferedWriter(new FileWriter(filename));
    for (int i = 0; i < data.size(); i++) {
      String output = formatCase(i+1, data.get(i));
      writer.write(output + "\n");
    }
    writer.close();
  }
}
