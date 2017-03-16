import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.Arrays;

public class EqualSums {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new FileReader(new File("C-small-attempt0.in")));
//    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String line = br.readLine();
    int t = Integer.parseInt(line);
    for (int i = 0; i < t; i++) {
      line = br.readLine();
      String[] split = line.split(" ");
      int n = Integer.parseInt(split[0]);
      int[] numbers = new int[n];
//      int acc=0;
      
      for (int j = 0; j < n; j++) {
        numbers[j]=Integer.parseInt(split[j+1]);
//        acc+=numbers[j];
      }
      
      Arrays.sort(numbers);
      
      int[] sums = new int[(int) Math.pow(2, 20)];
      for (int j = 0; j < sums.length; j++) {
        int sum = 0;
        String bits = new StringBuilder(Integer.toBinaryString(j)).reverse().toString();
        for (int j2 = 0; j2 < numbers.length; j2++) {
          if(bits.length() > j2 && bits.charAt(j2)=='1') {
            sum+=numbers[j2];
          }
        }
        sums[j] = sum;
      }
      
      int[] sumsCopy = new int[sums.length];
      System.arraycopy(sums, 0, sumsCopy, 0, sums.length);
      
      Arrays.sort(sumsCopy);
      
      
      int previous = -1;
      int ansJ = -1;
      
      for (int j = 0; j < sumsCopy.length; j++) {
        if(sumsCopy[j] == previous) {
          ansJ = j;
          break;
        }else {
          previous=sumsCopy[j];
        }
      }
      
      System.out.println("Case #" + (i + 1) + ":");
      if(ansJ==-1) {
        System.out.println("Impossible");
      }else {
        int firstBits = 0;
        for (int j = 0; j < sums.length; j++) {
          if(sums[j] == sumsCopy[ansJ]) {
            firstBits = j;
            break;
          }
        }
        String bits = new StringBuilder(Integer.toBinaryString(firstBits)).reverse().toString();
        for (int j = 0; j < bits.length(); j++) {
          char a = bits.charAt(j);
          if(a=='1') {
            System.out.print(numbers[j] + " ");
          }
        }
        System.out.println();
        int secondBits = 0;
        for (int j = 0; j < sums.length; j++) {
          if(sums[j] == sumsCopy[ansJ] && j != firstBits) {
            secondBits = j;
            break;
          }
        }
        String bits2 = new StringBuilder(Integer.toBinaryString(secondBits)).reverse().toString();
        for (int j = 0; j < bits2.length(); j++) {
          char a = bits2.charAt(j);
          if(a=='1') {
            System.out.print(numbers[j] + " ");
          }
        }
        System.out.println();
      }
    }
  }


}
