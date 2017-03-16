import java.io.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class P3 {


    public static void main(String[] args) throws Exception {
        init();
        P3 trans = new P3();
        trans.doMe();

    }

    private static final String NAME = "t23";

    public void doMe() throws IOException {
        File file = new File(NAME + ".in");
        BufferedWriter out = new BufferedWriter(new FileWriter(NAME + ".out"));
        try {
            //use buffering, reading one line at a time
            //FileReader always assumes default encoding is OK!
            BufferedReader input = new BufferedReader(new FileReader(file));
            try {
                String line = input.readLine();
                int count = Integer.parseInt(line);
                for (int i = 0; i < count; i++) {
                    String str = this.processLine(input.readLine().trim());
                    out.write("Case #" + (i + 1) + ": " + str);
                    if (i < count - 1)
                        out.write(System.getProperty("line.separator"));
                    System.out.println(str);
                }
            } finally {
                input.close();
                out.flush();
                out.close();
            }
        } catch (IOException ex) {
            ex.printStackTrace();
        }
    }

    HashMap <String, Integer[]> memo = new HashMap<String, Integer[]>();
    HashMap <String, Integer> memo2 = new HashMap<String, Integer>();
    String processLine(String line) {
        return ""+rec(line, -10000)[0];
    }

    Integer[] rec(String s, int index) {
        if (memo.containsKey(s)) return memo.get(s);
        int uu[] = new int[]{Integer.MAX_VALUE, index};
        if (s.length()<=10) {
            uu = dif(s,index);
        }

        if (s.length()>1 && uu[0]>0) {
            //System.out.println("-------------");
            for(int i=1;i<=10 && i<s.length();i++) {
                //System.out.println(i+":"+(s.substring(i)).length());
                Integer yu1[] = rec(s.substring(0,i), index);
                if (yu1[0]==Integer.MAX_VALUE) continue;
                Integer[] yu2 = rec(s.substring(i), yu1[1]);
                if (yu2[1]==Integer.MAX_VALUE) continue;

                //System.out.println((s.substring(0,i)).length());
                if (uu[0]>yu1[0]+yu2[0])  {
                    uu = new int[]{yu1[0]+yu2[0], yu2[1]};
                } else if (uu[0]==yu1[0]+yu2[0]) {
                    uu = new int[]{yu1[0]+yu2[0], Math.min(yu2[1], uu[1])};
                }
            }
        }

        memo.put(s, new Integer[]{uu[0], uu[1]});
        return new Integer[]{uu[0], uu[1]};
    }

    int[] dif(String s, int oo) {
        //if (memo2.containsKey(s)) return memo2.get(s);
        List<String> u = dict.get(s.length());
        Integer o = Integer.MAX_VALUE;
        int latest = Integer.MIN_VALUE;
        ax: for(String v: u) {
            int ui = 0;
            int change = oo;
            for(int i=0;i<s.length();i++) {
                if (s.charAt(i) !=  v.charAt(i))  {
                    if ( change>=0 && i - change < 5) continue ax;
                    change = i;
                    ui++;
                }
            }
            if (ui<=o) {
                latest = Math.min(latest, change);
            }
            o = Math.min(ui,o);
        }
        memo2.put(s,o);
        return new int[]{o, latest};
    }

    String proccessLines(String lines[]) {
        return null;
    }

    static Map<Integer, List<String>> dict = new HashMap<Integer, List<String>>();
    public static void init() throws Exception {
        File file = new File("dict.txt");
        try {
            //use buffering, reading one line at a time
            //FileReader always assumes default encoding is OK!
            BufferedReader input = new BufferedReader(new FileReader(file));
            try {
                String line = null;

                while ((line =input.readLine())!=null) {
                    String key = line.trim();
                    List<String> b = dict.get(key.length());
                    if (b==null) {
                        b = new ArrayList<String>();
                        dict.put(key.length(), b);
                    }
                    b.add(key);
                }
            } finally {
                input.close();
            }
        } catch (IOException ex) {
            ex.printStackTrace();
        }
     /*   int total = 0;
        for(int i=0;i<12;i++) {
            if (dict.containsKey(i)) {
                total += dict.get(i).size();
                System.out.println(i+") "+dict.get(i).size());
            }
        }
        System.out.println("x: "+total);          */
    }

}
