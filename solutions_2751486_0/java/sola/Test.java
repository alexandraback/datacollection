import java.io.*;
import java.util.*;


public class Test {
    final static String WORK_DIR = "C:\\Users\\Sola\\Desktop\\";
    final static boolean[] isVowel = {true,false,false,false,true,false,false,false,true,false,false,false,false,false,true,false,false,
        false,false,false,true,false,false,false,false,false};
    
    
    public static void main (String[] args) throws IOException {
        
        
        //generateInput(100);
        Scanner sc = new Scanner(new FileReader(WORK_DIR + "1.in"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "1.out"));
        
        int tc = sc.nextInt();

        for (int tci=1;tci<=tc;tci++) {
            String name = sc.next();
            int N = sc.nextInt();
            int cnt=0;
            Hashtable<String,Boolean> ht = new Hashtable<String,Boolean>();
            for (int i=0;i<=name.length()-N;i++) {
                boolean b = true;
                for (int n=0;n<N;n++) {
                    if (isVowel[name.charAt(i+n)-'a']) {
                        b = false;
                        break;
                    }
                }
                if (b==true) {
                    for (int s=0;s<=i;s++) {
                        for (int e=i+N;e<=name.length();e++) {
                            String sub = s + " "+e;
                            if (!ht.containsKey(sub)) {
                                ht.put(sub,true);
                                cnt++;
                            }
                        }
                    }
                }
            }
            pw.println("Case #" + tci + ": " + cnt);
        }
        pw.close();
        sc.close();
    }
    
    public static int minMoves (long a, int i, int[] motes) {
        if (i>=motes.length) {
            return 0;
        }
        int cnt = 0;
        System.out.println("a="+a+",i="+i+",m="+motes[i]);
        if (a==1) return motes.length-i;
        while (a<=motes[i]) {
            a+=a-1;
            cnt++;
        }
        if (cnt==1||cnt==0) return cnt+minMoves(a+motes[i],i+1,motes);
        if (cnt>motes.length-i) {
            return motes.length-i;
        }
        
        return Math.min(motes.length-i,cnt+minMoves(a+motes[i],i+1,motes));
    }
    
    public static void generateInput (int tc) throws IOException {
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "1.in"));
        int maxS = 1000000;
        int maxN = 100;
        
        pw.print(tc);
        Random rd = new Random();
        for (int tci=1;tci<=tc;tci++) {
            pw.println();
            int a = rd.nextInt(maxS)+1;
            int n = rd.nextInt(maxN)+1;
            pw.println(a+ " "+n);
            for (int i=0;i<n;i++) {
                int m = rd.nextInt(maxS)+1;
                pw.print(m+" ");
            }
        } 
        pw.close();
    }
}
