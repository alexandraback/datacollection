package main;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class EntryPoint {

   public static void main(String[] args) {
      EntryPoint ep = new EntryPoint();
      ep.run();
   }

   private void run() {
      List<String> input = getFileAsListOfStrings("input.txt");
      int cases = Integer.parseInt(input.remove(0));
      int caseNum = 1;

      while (input.size() > 0) {
         System.out.println("Case #" + caseNum + ": " + process(input.remove(0)));
         caseNum++;
      }
   }

   private int process(String input) {
      String[] split = input.split(" ");
      int rows = Integer.parseInt(split[0]);
      int cols = Integer.parseInt(split[1]);
      int width = Integer.parseInt(split[2]);

      if (width == 1) {
         return rows * cols;
      }
      if (width == cols) {
         return rows - 1 + width;
      }

      int r = (rows - 1) * (cols / width);
      r += cols / width;
      if (cols % width == 0) {
         r--;
      }
      r += width;

      return r;
   }

   private List<String> getFileAsListOfStrings(String fileName) {
      final String fileBase = "C:\\Users\\drandall\\workspace\\Practice\\src\\files\\";
      List<String> result = new ArrayList<String>();
      BufferedReader in = null;
      try {
         in = new BufferedReader(new FileReader(fileBase + fileName));
         while (in.ready()) {
            result.add(in.readLine());
         }
      } catch (Exception e) {
         System.out.println("Error reading file: " + e);
      } finally {
         if (in != null) {
            try {
               in.close();
            } catch (IOException e) {
            }
         }
      }
      return result;
   }
}
