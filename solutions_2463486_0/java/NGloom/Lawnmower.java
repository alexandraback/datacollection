import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.Scanner;


public class Lawnmower {
    static Long[] ARRAY = new Long[] {
            1L, 2L, 3L,11L,22L
    };
    
    public static void main(String[] args) {
        
//        List<Long> list = new ArrayList<Long>();
//        
//        Date s = new Date();
//        for(long i = 1; i < 10000000000L; i ++) {
//            if(isOk(i*i)) {
//                list.add(i);
//            }
//            if(i % 100000000 == 0) {
//                System.out.println(System.currentTimeMillis() + ":" + i / 100000000);
//                
//            }
//        } 
//        System.out.println(list.size());
//        Date end = new Date();
//        System.out.println(end.getTime() - s.getTime());
        
        
        
        
        try {
            Scanner in = new Scanner(new File("lawnmower.txt"));
            int num = in.nextInt();
            
            for(int n = 1; n <= num; n++) {
                long a = in.nextLong();
                long b = in.nextLong();
                a = upper(a);
                b = lower(b);
                int rtn = 0;
                for(long i : ARRAY) {
                    if( i >=a && i <= b) {
                        rtn ++;
                    }
                }
                System.out.println(String.format("Case #%d: %d", n,rtn));
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
    
    static long upper(long i) {
        long rtn = (long)Math.sqrt(i);
        if(rtn * rtn >= i) {
            return rtn;
        }
        return rtn + 1;
    }
    
    static long lower(long i) {
        long rtn = (long)Math.sqrt(i);
        if(rtn * rtn <= i) {
            return rtn;
        }
        return rtn - 1;
    }
}
