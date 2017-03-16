import java.io.*;
import java.util.*;

public class ReorderingTrainCars {
    public static Scanner sc;

    public static void main(String[] args) throws Exception {
      sc = new Scanner(System.in);
      sc = new Scanner(new File("E:\\GitHub\\HHH\\CodeJam\\R\\B-small-attempt0.in"));
      int c = sc.nextInt();
      String sol = "";
      
      for (int i = 1; i <= c; i++)
          sol += "Case #" + i + ": " + solve() + "\n";
      
      System.out.print(sol);
      PrintWriter pw = new PrintWriter(new File("E:\\GitHub\\HHH\\CodeJam\\R\\B-small-attempt0.out"));
      pw.print(sol);
      pw.close();
    }

    public static int ans = 0;
    public static String[] train;

    public static String solve() {
        int nootrain = sc.nextInt();
        train = new String[nootrain];
        String[] trainOut = new String[nootrain];
        int[] used = new int[nootrain];
        for (int i = 0; i < nootrain; i++) {
            train[i] = sc.next();
        }
        
        if (!isOriginValid(train)) {
        	System.out.println("origin invalid");
        	return "" + 0;
        }

        ans = 0;
        for (int i = 0; i < nootrain; i++) {
            used[i] = 1;
            trainOut[0] = train[i];
            gen(1, trainOut, used);
            used[i] = 0;
        }
        return "" + ans;
    }

    public static void gen(int now, String[] temp, int[] used) {
        if (now == temp.length) {
            if (isValid(temp)) {
                ans++;
            }
            return ;
        }

        for (int i = 0; i < temp.length; i++) {
            if (used[i] == 0) {
                used[i] = 1;
                temp[now] = train[i];
                gen(now + 1, temp, used);
                used[i] = 0;
            }
        }
    }

    public static boolean isValid(String[] o) {
        int[] set = new int[200];
        for (int i = 0; i < o.length; i++) {
            for (int j = 0; j < o[i].length(); j++) {
                set[o[i].charAt(j)]++;
            }
        }

        String temp = "";
        for (int i = 0; i < o.length; i++) {
            temp += o[i];
        }
//        System.out.print(temp + " ");
        int bef = temp.charAt(0);
        for (int i = 0; i < temp.length(); i++) {
            set[temp.charAt(i)]--;
            if (bef != temp.charAt(i)) {
                if (set[bef] != 0) {
//                    System.out.println(" invalid");
                    return false;
                }
            }
            bef = temp.charAt(i);
        }

//        System.out.println(" valid");
        return true;
    }
    
    public static boolean isOriginValid(String[] o) {
    	for (int i = 0; i < o.length; i++) {
    		for (int j = 0; j < o[i].length() - 1; j++) {
    			if (o[i].charAt(j) > o[i].charAt(j+1))
    				return false;
    		}
    	}
    	return true;
    }
}