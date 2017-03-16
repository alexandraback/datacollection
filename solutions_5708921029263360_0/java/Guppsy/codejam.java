import java.io.*;

import java.util.*;

public class codejam {

    static String i0 = "dummy.in";
    static String o0 = "dummy.out";

    static String i1 = "small.in";
    static String o1 = "small.out";

    static String i2 = "large.in";
    static String o2 = "large.out";

    public static void main(String[] args) throws Exception {

        Scanner r = null;
        FileWriter w = null;

        r = new Scanner(new FileReader(i0));
        w = new FileWriter(new File(o0));

        int t = r.nextInt();
        //r.nextLine();
        
        for (int i=0;i<t;i++){
            w.write("Case #"+(i+1)+": ");
            int j = r.nextInt();
            int p = r.nextInt();
            int s = r.nextInt();
            int k = r.nextInt();
            Map<String, Integer> jps = new HashMap<String, Integer>();
            Map<String, Integer> jp = new HashMap<String, Integer>();
            Map<String, Integer> ps = new HashMap<String, Integer>();
            Map<String, Integer> js = new HashMap<String, Integer>();
            for (int _j=0;_j<j;_j++){
                for (int _p=0;_p<p;_p++){
                    for (int _s=0;_s<s;_s++){
                        String _jps = _j+""+_p+""+_s;
                        String _jp = _j+""+_p;
                        String _ps = _p+""+_s;
                        String _js = _j+""+_s;
                        if (jps.containsKey(_jps)){
                            continue;
                        } else if (jp.containsKey(_jp) && jp.get(_jp) >= k){
                            continue;
                        } else if (ps.containsKey(_ps) && ps.get(_ps) >= k){
                            continue;
                        } else if (js.containsKey(_js) && js.get(_js) >= k){
                            continue;
                        } else {
                            jps.put(_jps, 0);
                            if (jp.containsKey(_jp))
                                jp.put(_jp, jp.get(_jp)+1);
                            else 
                                jp.put(_jp, 1);
                            if (ps.containsKey(_ps))
                                ps.put(_ps, ps.get(_ps)+1);
                            else 
                                ps.put(_ps, 1);
                            if (js.containsKey(_js))
                                js.put(_js, js.get(_js)+1);
                            else 
                                js.put(_js, 1);
                        }
                    }
                }
            }
            w.write(jps.size()+"\n");
            for (Map.Entry<String, Integer> e:jps.entrySet()){
                String _s = e.getKey();
                w.write((_s.charAt(0) - '0')+1+" ");
                w.write((_s.charAt(1) - '0')+1+" ");
                w.write((_s.charAt(2) - '0')+1+"\n");
            }
            //w.write("\n");
        }
        w.close();
    }
}
