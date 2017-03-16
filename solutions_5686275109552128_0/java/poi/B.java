package cj.y2015.qr;

import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;
import java.util.*;

/**
 * Created by admin on 4/6/2015.
 */
public class B {

    private Scanner scanner;
    private Writer writer;
    private NavigableMap<Integer, Integer> cmap = new TreeMap<Integer, Integer>();


    public static void main(String[] args) throws IOException {
        B a = new B();
        a.meat();
    }

    private void meat() throws IOException {
        scanner = new Scanner(new FileInputStream("src/cj/y2015/qr/B-small-attempt2.in"));
        writer = new FileWriter("src/cj/y2015/qr/B-small-attempt2.out", false);
        int t = scanner.nextInt();
        for (int i=0; i<t; i++) {
            cmap.clear();
            int d = scanner.nextInt();
            for (int j=0; j<d; j++) {
                int pj = scanner.nextInt();
                putInMap(cmap, pj, 1);
            }
            int time = 0;
            int nt = time + cmap.lastKey();
            while (time<nt) {
                if (cmap.isEmpty()) {
                    break;
                }
                int dt = cmap.lastKey();
//                int count = cmap.get(dt);
                if (dt!=1) {
                    putInMap(cmap, dt, -1);
                    if (dt % 2 == 0) {
                        putInMap(cmap, dt / 2, 2);
                    } else {
                        putInMap(cmap, dt / 2, 1);
                        putInMap(cmap, dt / 2 + 1, 1);
                    }
                } else {
                    cmap.clear();
                }
                ++time;
                int cal_time = time;
                if (!cmap.isEmpty()) {
                    cal_time += cmap.lastKey();
                }
                if (cal_time<nt) {
                    nt = cal_time;
                }
                if (dt==1) {
                    break;
                }
            }
            writer.write("Case #" + (i + 1) + ": " + nt + "\n");
            System.out.println("Case #" + (i + 1) + ": " + nt);
        }
        scanner.close();
        writer.close();
    }

    private void putInMap(Map<Integer, Integer> map, int key, int count) {
        if (map.get(key)!=null) {
            int temp = map.get(key);
            int newTemp = temp + count;
            if (newTemp>0) {
                map.put(key, newTemp);
            } else {
                map.remove(key);
            }
        } else {
            map.put(key, count);
        }
    }

    private class AbsComparator implements Comparator<Long> {

        @Override
        public int compare(Long o1, Long o2) {
            return (Math.abs(o1)>Math.abs(o2))?-1:((Math.abs(o1)==Math.abs(o2))?0:1);
        }
    }
}
