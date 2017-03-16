import java.util.*;

public class Fair {
  public static void main(String[] args) {
    ArrayList<Long> list = generate();
    Scanner in = new Scanner(System.in);
    int numTests = in.nextInt();
    StringBuilder output = new StringBuilder();
    for (int testNum = 1; testNum <= numTests; ++testNum) {
      output.append(String.format("Case #%d: ", testNum));
      long low = in.nextLong();
      long high = in.nextLong();
      output.append(count(high, list) - count(low-1, list));
      output.append('\n');
    }
    System.out.print(output);
  }
  
  public static int count(long limit, ArrayList<Long> list) {
    int count = 0;
    for (int i = 0; i < list.size(); ++i) {
      if (limit >= list.get(i))
        ++count;
      else
        break;
    }
    return count;
  }
  
  public static ArrayList<Long> generate() {
    ArrayList<Long> list = new ArrayList<Long>();
    for (long i = 1; i <= 10000001; ++i) {
      if (isPalindrome(i) && isPalindrome(i*i)) {
        //System.out.printf("%d*%d=%d\n", i, i, i*i);
        list.add(i*i);
      }
    }
    return list;
  }
  
  public static boolean isPalindrome(long n) {
    String num = "" + n;
    for (int low = 0, high = num.length()-1; low < high; ++low, --high) {
      if (num.charAt(low) != num.charAt(high))
        return false;
    }
    return true;
  }
}