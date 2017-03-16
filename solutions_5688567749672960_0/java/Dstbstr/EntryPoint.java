package main;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class EntryPoint {

   public static void main(String[] args) {
      EntryPoint ep = new EntryPoint();
      ep.run();
   }

   // 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 91 92 93 94 95 96 97 98 99 100
   private void run() {
      List<String> input = getFileAsListOfStrings("input.txt");
      int cases = Integer.parseInt(input.remove(0));
      int caseNum = 1;

      cache.put(1L, 1L);
      cache.put(10L, 10L);
      for (long i = 100; i < 100000000000000L; i *= 10) {
         calculateCache(i);
      }

      while (input.size() > 0) {
         System.out.println("Case #" + caseNum + ": " + process(input.remove(0)));
         caseNum++;
      }
   }

   private Map<Long, Long> cache = new HashMap<Long, Long>();

   private String process(String input) {
      int target = Integer.parseInt(input);

      if (target < 19) {
         return Integer.toString(target);
      }
      return Long.toString(calc(target));
   }

   private long calc(long target) {
      long result = 0;
      long firstHalf = getReverseRemainder(target);
      long startingPoint = getStartingPoint(target);

      if (target % 10 == 0) {
         return calc(target - 1) + 1;
      }
      if (firstHalf > 1) {
         result = cache.get(startingPoint);
         result += firstHalf;

         long flipPoint = startingPoint + firstHalf;
         long remainder = target - reverse(flipPoint);
         result += remainder + 1; // +1 for flip
      } else if (firstHalf == 1) {

         result = cache.get(startingPoint);
         result += target - startingPoint;
      } else {
         result = calc(target - 1) + 1;
      }
      return result;
   }

   private long getStartingPoint(long target) {
      String result = "1";
      for (int i = 1; i < Long.toString(target).length(); ++i) {
         result += "0";
      }
      return Long.parseLong(result);
   }

   private long getReverseRemainder(long target) {
      String val = "" + target;
      int digits = val.length() / 2;
      return reverse(Long.parseLong(val.substring(0, digits)));
   }

   private long reverse(long input) {
      String str = Long.toString(input);
      String rev = "";
      for (int i = str.length() - 1; i >= 0; --i) {
         rev += str.charAt(i);
      }
      return Long.parseLong(rev);
   }

   private void calculateCache(long input) {
      cache.put(input, calc(input - 1) + 1);
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
