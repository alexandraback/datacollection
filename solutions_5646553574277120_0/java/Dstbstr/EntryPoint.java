package main;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
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
         System.out.println("Case #" + caseNum + ": " + process(input.remove(0), input.remove(0)));
         caseNum++;
      }
   }

   private int process(String input1, String input2) {
      String[] split1 = input1.split(" ");
      String[] split2 = input2.split(" ");

      int maxCoins = Integer.parseInt(split1[0]);
      int maxValue = Integer.parseInt(split1[2]);

      List<Long> existingCoins = new ArrayList<Long>();
      for (int i = 0; i < split2.length; ++i) {
         existingCoins.add(Long.parseLong(split2[i]));
      }

      // 1 2 3 4 5
      // 1
      // 2
      // 3
      // 4
      // 5
      // 6 [1,5]
      // 7 [2,5]
      // 8 [3,5]
      // 9 [4,5]
      // 10 [1,4,5]
      // 11 [2,4,5]
      // 12 [3,4,5]
      // 13 [1,3,4,5]
      // 14 [2,3,4,5]
      // 15 [1,2,3,4,5]

      // 1, 2, 3, 4, 5, [1,2], [1,3], [1,4], [1,5], [2, 3], [2,4], [2,5], [3,4], [3,5], [4,5]
      // [1,2,3], [1,2,4], [1,2,5], [1,3,4], [1,3,5], [1,4,5], [2,3,4], [2,3,5], [2,4,5], [3,4,5]


      int newCoins = 0;
      for (int i = 1; i <= maxValue; ++i) {
         int current = i;
         while (current > 0) {
            for (int j = existingCoins.size() - 1; j >= 0; --j) {
               Long coin = existingCoins.get(j);
               if (coin <= current) {
                  current -= coin;
               }
               if (current == 0) {
                  break;
               }
               if (current < 0) {
                  System.out.println("ERROR: negative value");
               }
            }
            if (current > 0) {
               existingCoins.add(findMissingCoin(i, existingCoins));
               Collections.sort(existingCoins);
               newCoins++;
            }
         }
      }
      return newCoins;
   }

   private long findMissingCoin(int target, List<Long> existingCoins) {
      // find the smallest missing coin
      for (long i = 1; i < target; ++i) {
         if (!existingCoins.contains(i) && existingCoins.contains(target - i)) {
            return i;
         }
      }
      return target;
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
