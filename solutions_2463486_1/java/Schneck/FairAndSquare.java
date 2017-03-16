import java.io.*;
import java.util.*;

public class FairAndSquare {
    public static final PrintStream out = System.out;
    public static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    public int numCases;
    
    public void doCase(int caseNumber) throws Exception {
        String line = in.readLine();
        Scanner scan = new Scanner(line);
        String astr = scan.next();
        String bstr = scan.next();
        int aloc = Collections.binarySearch(allFairAndSquare,astr,CMP);
        if(aloc < 0) aloc = -1 - aloc;
        int bloc = Collections.binarySearch(allFairAndSquare,bstr,CMP);
        if(bloc < 0) bloc = -1 - bloc - 1;
        System.out.println(bloc - aloc + 1);
    }
    
    public void run() throws Exception {
        numCases = Integer.parseInt(in.readLine().trim());
        for (int i = 1; i <= numCases; i++) {
            out.print("Case #" + i + ": ");
            doCase(i);
        }
    }
    
    /**
     * @param args
     */
    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream("/Users/schneck/Documents/all-fair-and-square.txt")));
        String line;
        while((line = reader.readLine()) != null) {
            allFairAndSquare.add(line);
        }
        new FairAndSquare().run();
    }

    public static List<String> allFairAndSquare = new ArrayList<String>();
    
    public static Comparator<String> CMP = new Comparator<String>() {
        @Override
        public int compare(String o1, String o2) {
            int l1 = o1.length();
            int l2 = o2.length();
            int res = l1 - l2;
            if(res==0) return o1.compareTo(o2);
            else return res;
        }
    };
}
