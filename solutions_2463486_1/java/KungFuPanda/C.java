import java.util.*;
import java.io.*;
import java.util.Collections;


public class C {
  
  private static long MAX = 100000000000000l;
  private static ArrayList<Long> num = new ArrayList<Long>();
  private static long[] numL;
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    
    preprocess();
    int T = sc.nextInt();
    for(int i=1;i<=T;i++) {
      long a = sc.nextLong();
      long b = sc.nextLong();
      
      int count = 0;
      /*
      for(int j=0;j<numL.length;j++) {
        if(numL[j] > b) break;
        System.out.print(numL[j]+" ");
      }
        System.out.println();
      */  
      for(int j=0;j<numL.length;j++) {
        if(numL[j] >= a && numL[j] <= b) count++;
      }
      
      System.out.print("Case #"+i+": "+count);
      if(i!=T) System.out.println();
    }
  }
  
  private static void preprocess() {
    long start = 1;
    while(start*start <= MAX) {
      if(isPalindrom(start) && isPalindrom(start*start))
        num.add(start*start);
      start++;
    }
    int i=0;
    numL = new long[num.size()];
    for(long x: num) numL[i++] = x;
    //System.out.println("Length "+num.size());
  }
  
  private static boolean isPalindrom(long num) {
    long tmp;
    tmp = num;
    long count=0;
    
    while(tmp!=0) {
      count = 10*count+(tmp%10);
      tmp = tmp/10;
    }
    return count == num;
  }
  /*
  private static int findVal(long val, long[] num) {
    int low = 0;
    int high = num.length-1;
    int res=-1;
    int mid;
    while(low<=high) {
      mid = (low+high)/2;
      if(num[mid] >= val) {
        res = mid;
        high = mid-1;
      } else {
        low = mid+1;
      }
    }
    return res;
  }
  */
}