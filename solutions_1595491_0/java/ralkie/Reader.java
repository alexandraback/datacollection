package lt.kasrud.gcj.common.io;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;


public class Reader {
  public static List<String> readFile(String filename) throws IOException {
    List<String> results = new ArrayList<String>();

    BufferedReader reader = new BufferedReader(new FileReader(filename));
    String line = null;
    while ((line = reader.readLine()) != null)    {
//      String[] tokens = line.trim().split(" ");
//      results.add(Arrays.asList(tokens));
      results.add(line);
    }

    reader.close();
    return results;
  }
}
