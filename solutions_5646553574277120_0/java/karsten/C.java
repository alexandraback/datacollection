package round1c;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Collections;
import java.util.SortedSet;
import java.util.TreeSet;

public class C {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new FileReader(args[0]));
    BufferedWriter bw = new BufferedWriter(new FileWriter(args[1]));
    String line = br.readLine();
    int testCase = 1;
    while ((line = br.readLine()) != null) {
      if (line.length() == 0) {
        break;
      }
      String[] firstStrings = line.split(" ");
      //System.out.println(line);
      int c = Integer.parseInt(firstStrings[0]);
      int d = Integer.parseInt(firstStrings[1]);
      long v = Long.parseLong(firstStrings[2]);
      SortedSet<Long> denominations = new TreeSet<Long>(
          Collections.reverseOrder());
      line = br.readLine();
      //System.out.println(line);
      for (String s : line.split(" ")) {
        denominations.add(Long.parseLong(s));
      }
      long amount = 1;
      do {
        //System.out.println("Looking at amount " + amount);
        long leftToPay = amount;
        long highestDenomination = -1, highestDenominationCoins = -1;
        for (long denomination : denominations.tailSet(amount)) {
          //System.out.println("Looking at denomination " + denomination);
          long coins = Math.min(c, leftToPay / denomination);
          if (highestDenomination < 0) {
            highestDenomination = denomination;
            highestDenominationCoins = coins;
          }
          //System.out.println("Paying " + payNow + " with "
          //    + denomination + " coins.");
          leftToPay -= denomination * coins;
          if (leftToPay <= 0) {
            break;
          }
        }
        if (leftToPay > 0) {
          //System.out.println("Need to add coin. How about " + amount);
          denominations.add(amount);
        }
        if (highestDenominationCoins > 0 &&
            c > highestDenominationCoins) {
          //System.out.println("Cranking up amount by " +
          //    ((c - highestDenominationCoins) * highestDenomination));
          amount += (c - highestDenominationCoins) * highestDenomination;
        }
        amount++;
      } while (amount <= v);
      int addedDenominations = denominations.size() - d;
      bw.write("Case #" + testCase++ + ": " + addedDenominations + "\n");
    }
    br.close();
    bw.close();

  }
}
