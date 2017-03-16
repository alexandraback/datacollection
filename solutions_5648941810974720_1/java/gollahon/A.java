import java.util.*;
import static java.lang.Math.*;

public class A {
  static int[] counts;
  public static void main(String[] args) {
    Scanner stdin = new Scanner(System.in);
    int T = stdin.nextInt();
    for(int testCase = 1; testCase <= T; ++testCase) {
      char[] s = stdin.next().toCharArray();

      counts = new int[26];
      for(char c : s)
        ++counts[c - 'A'];

      int[] nums = new int[10];
      nums[0] = remove('Z', "ZERO");
      nums[2] = remove('W', "TWO");
      nums[6] = remove('X', "SIX");
      nums[8] = remove('G', "EIGHT");
      nums[3] = remove('H', "THREE");
      nums[7] = remove('S', "SEVEN");
      nums[5] = remove('V', "FIVE");
      nums[4] = remove('F', "FOUR");
      nums[1] = remove('O', "ONE");
      nums[9] = remove('N', "NINE");

      String phoneNumber = "";
      for(int i = 0; i < 10; ++i) {
        for(int j = 0; j < nums[i]; ++j)
          phoneNumber += ("" + i);
      }

      System.out.printf("Case #%d: %s\n", testCase, phoneNumber);
    }
  }

  static int remove(char c, String s) {
    int index = c - 'A';
    char[] chars = s.toCharArray();

    int count = 0;

    while(counts[index] > 0) {
      for(char ch : chars) {
        --counts[ch - 'A'];
      }
      ++count;
    }

    return count;
  }
}

// "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
// "Z", "ONE", "W", "TH", "FOUR", "IX", "X", "V", "EIGHT", "NINE"
//
// "ONE", "THREE", "FOUR", "FIVE", "SEVEN", "NINE"
//
// Z => Zero
// W => tWo
// X => siX
// G => eiGht
//
// "ONE", "THREE", "FOUR", "FIVE", "SEVEN", "NINE"
// H => Three
//
// "ONE", "FOUR", "FIVE", "SEVEN", "NINE"
//
// S => Seven
//
// "ONE", "FOUR", "FIVE", "NINE"
//
// V => Five
//
// "ONE", "FOUR", "NINE"
//
// F => Four
//
// O => One
//
// N => Nine
