import java.io.*;
import java.util.*;


public class t3 {
    final static String WORK_DIR = "C:\\Users\\Sola\\Desktop\\";
    static Random rd = new Random();
    
    
    
    public static void main (String[] args) throws IOException {
        
        Scanner sc = new Scanner(new FileReader(WORK_DIR + "t3.in"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "t3.out"));
        int tc = sc.nextInt();

        
        
        
        for (int tci=1;tci<=tc;tci++) {
            pw.println("Case #1:");
            int r = sc.nextInt();
            int n = sc.nextInt();
            int m = sc.nextInt();
            int k = sc.nextInt();
            for (int ri=1;ri<=r;ri++) {
                int[] nums = new int[k];
                for (int i=0;i<k;i++) {
                    nums[i] = sc.nextInt();
                }
                Arrays.sort(nums);
                int[] ans = new int[n];
                int maxcnt = 0;
                for (int t=0;t<1000;t++) {
                    int[] ons = new int[n];
                    for (int i=0;i<n;i++) {
                        ons[i] = rd.nextInt(m-1)+2;
                    }
                    int[] ps = new int[k];
                    int ln = 1;
                    for (int ni=0;ni<n;ni++) {
                        ln *=ons[ni];
                    }
                    int fcnt=0;
                    for (int t2=0;t2<100;t2++) {
                        
                        for (int ki=0;ki<k;ki++) {
                            int p = 1;
                            for (int i=0;i<n;i++) {
                                if (rd.nextFloat()<0.5) p = p*ons[i];
                            }
                            ps[ki] = p;
                        }
                        Arrays.sort(ps);
                        int cnt = 0;
                        for (int i=0,j=0;i<k&&j<k;) {
                            if (nums[i]==ps[j]) {
                                cnt++;
                                i++;
                                j++;
                            }
                            else if (nums[i]<ps[j]) {
                                i++;
                            }
                            else {
                                j++;
                            }
                        }
                        if (cnt>fcnt) fcnt = cnt;
                    }
                    boolean e = true;
                    
                    for (int ki=0;ki<k;ki++) {
                        e = false;
                        if (nums[ki]>ln) {
                            break;
                        }
                        int pp = nums[ki];
                        if (pp==1) {
                            e = true;
                            continue;
                        }
                        for (int ni=0;ni<n;ni++) {
                            if (pp==1) {
                                e= true;
                                break;
                            }
                            else if (pp%ons[ni]==0) {
                                pp = pp/ons[ni];
                            }
                        }
                        if (pp==1) e=true;
                        if (!e) break;
                    }
                            
                    if (e && fcnt>maxcnt) {
                        ans = Arrays.copyOf(ons,n);
                    }
                
                }
                for (int i:ans) {
                    pw.print(i);
                }
                pw.println();
            }
        }
        
        
        pw.close();
    }
}