import java.io.*;
import java.util.*;


public class Test2 {
    final static String WORK_DIR = "C:\\Users\\Sola\\Desktop\\";
    final static int UNKNOWN = -1;
    public static void main (String[] args) throws IOException {
        Scanner sc = new Scanner(new FileReader(WORK_DIR + "2.in"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "2.out"));
        int tc = sc.nextInt();
        for (int tci=1;tci<=tc;tci++) {
            sc.nextLine();
            boolean psb = true;
            int rows = sc.nextInt();
            int cols = sc.nextInt();

            int[][] h = new int[rows][cols];
            for (int r=0;r<rows;r++) {
                for (int c=0;c<cols;c++) {
                    h[r][c] = sc.nextInt();
                    
                }
            }
            
            
            ArrayList<Integer> rL = new ArrayList<Integer>(rows);
            ArrayList<Integer> cL = new ArrayList<Integer>(cols);
            for (int r=0;r<rows;r++) {
                rL.add(r);
            }
            for (int c=0;c<cols;c++) {
                cL.add(c);
            }
            boolean found = true;
            int lastVCut = 0;
            int lastHCut = 0;
            while (found && rL.size()>0 && cL.size()>0) {
                found = false;
                for (Integer r:rL) {
                    found = true;
                    int temp = h[r][cL.get(0)];
                    if (temp<lastVCut) {
                        found = false;
                        continue;
                    }
                    for (int c=1;c<cL.size() && found;c++) {
                        if (h[r][cL.get(c).intValue()]!=temp) {
                            found = false;
                            break;
                        }
                    }
                    if (found) {
                        if (temp>lastHCut) lastHCut = temp;
                        rL.remove(r);
                        break;
                    }
                }
                if (found) continue;
                for (Integer c:cL) {
                    found = true;
                    int temp = h[rL.get(0)][c];
                    if (temp<lastHCut) {
                        found = false;
                        continue;
                    }
                    for (int r=1;r<rL.size();r++) {
                        if (h[rL.get(r).intValue()][c]!=temp) {
                            found = false;
                            break;
                        }
                    }
                    if (found) {
                        if (temp>lastVCut) lastVCut = temp;
                        cL.remove(c);
                        break;
                    }
                }
            }
            
            
            pw.print("Case #" + tci + ": ");
            if (found) pw.print("YES");
            else pw.print("NO");
            if (tci<tc) pw.println();
        }
        sc.close();
        pw.flush();
        pw.close();
    }
}   