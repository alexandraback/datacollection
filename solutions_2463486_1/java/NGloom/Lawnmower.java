import java.io.File;
import java.io.FileNotFoundException;
import java.sql.Array;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.Scanner;


public class Lawnmower {
    static Long[] ARRAY = new Long[] {
        1L,
        4L,
        9L,
        121L,
        484L,
        10201L,
        12321L,
        14641L,
        40804L,
        44944L,
        1002001L,
        1234321L,
        4008004L,
        100020001L,
        102030201L,
        104060401L,
        121242121L,
        123454321L,
        125686521L,
        400080004L,
        404090404L,
        10000200001L,
        10221412201L,
        12102420121L,
        12345654321L,
        40000800004L,
        1000002000001L,
        1002003002001L,
        1004006004001L,
        1020304030201L,
        1022325232201L,
        1024348434201L,
        1210024200121L,
        1212225222121L,
        1214428244121L,
        1232346432321L,
        1234567654321L,
        4000008000004L,
        4004009004004L,
    };
    
    public static void main(String[] args) {
        
//        List<Long> list = new ArrayList<Long>();
//        
//        Date s = new Date();
//        for(long i = 1; i < 10000000; i ++) {
//            if(isOk(i) && isOk(i*i)) {
//                list.add(i*i);
//            }
//        } 
//        System.out.println(list.size());
//        Date end = new Date();
////        System.out.println(end.getTime() - s.getTime());
//        
//        for(long i : list) {
//            System.out.println(i+"L,");
//        }
        
        
        
        try {
            Scanner in = new Scanner(new File("lawnmower.txt"));
            int num = in.nextInt();
            
            for(int n = 1; n <= num; n++) {
                long a = in.nextLong();
                long b = in.nextLong();
                
                int l = firstBigger(a, 0, ARRAY.length-1);
//                System.out.println("l:"+l);
                int r = firstSmaller(b,0,ARRAY.length-1);

                System.out.println(String.format("Case #%d: %d", n,r-l+1));
            }
            
        } catch (FileNotFoundException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
    }
    
    static boolean isOk(long a) {
        String s = ""+a;
        int i = 0; 
        int j = s.length() - 1;
        while(i<j) {
            if(s.charAt(i) != s.charAt(j)) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    
//    static long upper(long i) {
//        long rtn = (long)Math.sqrt(i);
//        if(rtn * rtn >= i) {
//            return rtn;
//        }
//        return rtn + 1;
//    }
//    
//    static long lower(long i) {
//        long rtn = (long)Math.sqrt(i);
//        if(rtn * rtn <= i) {
//            return rtn;
//        }
//        return rtn - 1;
//    }
    
    
    static int firstBigger(long i, int l, int r) {
        while(l < r) {
            int mid = l + (r-l)/2;
            if(ARRAY[mid] < i) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return r;
    }
    
    static int firstSmaller(long i, int l ,int r) {
        while(l < r) {
            int mid = l + (r-l+1)/2;
            if(ARRAY[mid] > i) {
                r = mid - 1;
            } else {
                l = mid;
            }
//            System.out.println(l+" " +r);
        }
        return l;
    }
}
