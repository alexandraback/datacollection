package diamondinheritance;

import inout.In;
import inout.Out;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class Main {

    public static void main(String[] args) throws Exception {
        List<String> dynamicRead = In.dynamicRead("A-small-attempt1.in");
        int cont = 1;
        ext:
        for (int i = 0; i < dynamicRead.size(); i++) {
            String s = dynamicRead.get(i++);
            int n = Integer.parseInt(s);
            HashMap<Integer, List<Integer>> map = new HashMap<Integer, List<Integer>>(n);
            for (int j = 0; j < n; j++) {
                String[] split = dynamicRead.get(i + j).split(" ");
                ArrayList<Integer> list = new ArrayList<Integer>(Integer.parseInt(split[0]));
                for (int k = 1; k < split.length; k++) {
                    if (Integer.parseInt(split[k]) != 0) {
                        list.add(Integer.parseInt(split[k]));
                    }
                }
                map.put(j + 1, list);
            }
            i += n - 1;
            ArrayList<Integer> list = new ArrayList<Integer>(map.keySet());
            for (int j = 0; j < list.size(); j++) {
                ArrayList<Integer> pars = new ArrayList<Integer>();
                pars.addAll(map.get(j + 1));
                for (int k = 0; k < pars.size(); k++) {
                    int a = pars.get(k);
                    List<Integer> get = map.get(a);
                    for (Integer g : get) {
                        if (pars.contains(g)) {
                            Out.write("output.txt", cont++, "Yes");
                            continue ext;
                        }
                        pars.add(g);
                    }
                }
            }
            Out.write("output.txt", cont++, "No");
        }
    }
}
