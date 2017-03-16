package cj.y2015.qr;

import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;
import java.util.*;

/**
 * Created by admin on 4/6/2015.
 */
public class C {

    private Scanner scanner;
    private Writer writer;

    public static void main(String[] args) throws IOException {
        C a = new C();
        a.meat();
    }

    private void meat() throws IOException {
        scanner = new Scanner(new FileInputStream("src/cj/y2015/qr/C-large.in"));
        writer = new FileWriter("src/cj/y2015/qr/C-large.out", false);
        Map<Tuple, Quaternion> qmap = new HashMap<Tuple, Quaternion>();
        qmap.put(new Tuple(Quaternion.P_1, Quaternion.P_1), Quaternion.P_1);
        qmap.put(new Tuple(Quaternion.P_1, Quaternion.P_i), Quaternion.P_i);
        qmap.put(new Tuple(Quaternion.P_1, Quaternion.P_j), Quaternion.P_j);
        qmap.put(new Tuple(Quaternion.P_1, Quaternion.P_k), Quaternion.P_k);
        qmap.put(new Tuple(Quaternion.N_1, Quaternion.P_1), Quaternion.N_1);
        qmap.put(new Tuple(Quaternion.N_1, Quaternion.P_i), Quaternion.N_i);
        qmap.put(new Tuple(Quaternion.N_1, Quaternion.P_j), Quaternion.N_j);
        qmap.put(new Tuple(Quaternion.N_1, Quaternion.P_k), Quaternion.N_k);
        qmap.put(new Tuple(Quaternion.P_1, Quaternion.N_1), Quaternion.N_1);
        qmap.put(new Tuple(Quaternion.P_1, Quaternion.N_i), Quaternion.N_i);
        qmap.put(new Tuple(Quaternion.P_1, Quaternion.N_j), Quaternion.N_j);
        qmap.put(new Tuple(Quaternion.P_1, Quaternion.N_k), Quaternion.N_k);
        qmap.put(new Tuple(Quaternion.N_1, Quaternion.N_1), Quaternion.P_1);
        qmap.put(new Tuple(Quaternion.N_1, Quaternion.N_i), Quaternion.P_i);
        qmap.put(new Tuple(Quaternion.N_1, Quaternion.N_j), Quaternion.P_j);
        qmap.put(new Tuple(Quaternion.N_1, Quaternion.N_k), Quaternion.P_k);

        qmap.put(new Tuple(Quaternion.P_i, Quaternion.P_1), Quaternion.P_i);
        qmap.put(new Tuple(Quaternion.P_i, Quaternion.P_i), Quaternion.N_1);
        qmap.put(new Tuple(Quaternion.P_i, Quaternion.P_j), Quaternion.P_k);
        qmap.put(new Tuple(Quaternion.P_i, Quaternion.P_k), Quaternion.N_j);
        qmap.put(new Tuple(Quaternion.N_i, Quaternion.P_1), Quaternion.N_i);
        qmap.put(new Tuple(Quaternion.N_i, Quaternion.P_i), Quaternion.P_1);
        qmap.put(new Tuple(Quaternion.N_i, Quaternion.P_j), Quaternion.N_k);
        qmap.put(new Tuple(Quaternion.N_i, Quaternion.P_k), Quaternion.P_j);
        qmap.put(new Tuple(Quaternion.P_i, Quaternion.N_1), Quaternion.N_i);
        qmap.put(new Tuple(Quaternion.P_i, Quaternion.N_i), Quaternion.P_1);
        qmap.put(new Tuple(Quaternion.P_i, Quaternion.N_j), Quaternion.N_k);
        qmap.put(new Tuple(Quaternion.P_i, Quaternion.N_k), Quaternion.P_j);
        qmap.put(new Tuple(Quaternion.N_i, Quaternion.N_1), Quaternion.P_i);
        qmap.put(new Tuple(Quaternion.N_i, Quaternion.N_i), Quaternion.N_1);
        qmap.put(new Tuple(Quaternion.N_i, Quaternion.N_j), Quaternion.P_k);
        qmap.put(new Tuple(Quaternion.N_i, Quaternion.N_k), Quaternion.N_j);

        qmap.put(new Tuple(Quaternion.P_j, Quaternion.P_1), Quaternion.P_j);
        qmap.put(new Tuple(Quaternion.P_j, Quaternion.P_i), Quaternion.N_k);
        qmap.put(new Tuple(Quaternion.P_j, Quaternion.P_j), Quaternion.N_1);
        qmap.put(new Tuple(Quaternion.P_j, Quaternion.P_k), Quaternion.P_i);
        qmap.put(new Tuple(Quaternion.N_j, Quaternion.P_1), Quaternion.N_j);
        qmap.put(new Tuple(Quaternion.N_j, Quaternion.P_i), Quaternion.P_k);
        qmap.put(new Tuple(Quaternion.N_j, Quaternion.P_j), Quaternion.P_1);
        qmap.put(new Tuple(Quaternion.N_j, Quaternion.P_k), Quaternion.N_i);
        qmap.put(new Tuple(Quaternion.P_j, Quaternion.N_1), Quaternion.N_j);
        qmap.put(new Tuple(Quaternion.P_j, Quaternion.N_i), Quaternion.P_k);
        qmap.put(new Tuple(Quaternion.P_j, Quaternion.N_j), Quaternion.P_1);
        qmap.put(new Tuple(Quaternion.P_j, Quaternion.N_k), Quaternion.N_i);
        qmap.put(new Tuple(Quaternion.N_j, Quaternion.N_1), Quaternion.P_j);
        qmap.put(new Tuple(Quaternion.N_j, Quaternion.N_i), Quaternion.N_k);
        qmap.put(new Tuple(Quaternion.N_j, Quaternion.N_j), Quaternion.N_1);
        qmap.put(new Tuple(Quaternion.N_j, Quaternion.N_k), Quaternion.P_i);

        qmap.put(new Tuple(Quaternion.P_k, Quaternion.P_1), Quaternion.P_k);
        qmap.put(new Tuple(Quaternion.P_k, Quaternion.P_i), Quaternion.P_j);
        qmap.put(new Tuple(Quaternion.P_k, Quaternion.P_j), Quaternion.N_i);
        qmap.put(new Tuple(Quaternion.P_k, Quaternion.P_k), Quaternion.N_1);
        qmap.put(new Tuple(Quaternion.N_k, Quaternion.P_1), Quaternion.N_k);
        qmap.put(new Tuple(Quaternion.N_k, Quaternion.P_i), Quaternion.N_j);
        qmap.put(new Tuple(Quaternion.N_k, Quaternion.P_j), Quaternion.P_i);
        qmap.put(new Tuple(Quaternion.N_k, Quaternion.P_k), Quaternion.P_1);
        qmap.put(new Tuple(Quaternion.P_k, Quaternion.N_1), Quaternion.N_k);
        qmap.put(new Tuple(Quaternion.P_k, Quaternion.N_i), Quaternion.N_j);
        qmap.put(new Tuple(Quaternion.P_k, Quaternion.N_j), Quaternion.P_i);
        qmap.put(new Tuple(Quaternion.P_k, Quaternion.N_k), Quaternion.P_1);
        qmap.put(new Tuple(Quaternion.N_k, Quaternion.N_1), Quaternion.P_k);
        qmap.put(new Tuple(Quaternion.N_k, Quaternion.N_i), Quaternion.P_j);
        qmap.put(new Tuple(Quaternion.N_k, Quaternion.N_j), Quaternion.N_i);
        qmap.put(new Tuple(Quaternion.N_k, Quaternion.N_k), Quaternion.N_1);


        int t = scanner.nextInt();
        for (int i=0; i<t; i++) {
            long l = scanner.nextLong();
            long x = scanner.nextLong();
            List<Character> base = new ArrayList<Character>();
            String s = scanner.nextLine();
            s = scanner.nextLine();
            for (int j=0; j<s.length(); j++) {
                char c = s.charAt(j);
                base.add(c);
            }
            List<Character> list = new ArrayList<Character>();
            // small case
//            for (int j=0; j<x; j++) {
//                list.addAll(base);
//            }
//            System.out.println("l="+l+", x="+x+", s="+s+", base.size="+base.size()+", list.size="+list.size());
//            List<Quaternion> qList = new ArrayList<Quaternion>();
//            for (int j=0; j<list.size(); j++) {
//                if (j==0) {
//                    qList.add(Quaternion.fromChar(list.get(j)));
//                } else {
//                    qList.add(qmap.get(new Tuple(qList.get(j-1), Quaternion.fromChar(list.get(j)))));
//                }
//            }
//            String result = "NO";
//            if (qList.get(qList.size()-1)==Quaternion.N_1) {
//                for (int j=0; j<qList.size()-2; j++) {
//                    if (qList.get(j)==Quaternion.P_i) {
//                        for (int k=j+1; k<qList.size()-1; k++) {
//                            if (qList.get(k)==Quaternion.P_k) {
//                                result = "YES";
//                            }
//                        }
//                    }
//                }
//            }

            // large case
            for (int j=0; j<8; j++) {
                list.addAll(base);
            }
            System.out.println("l="+l+", x="+x+", s="+s+", base.size="+base.size()+", list.size="+list.size());
            List<Quaternion> qList = new ArrayList<Quaternion>();
            for (int j=0; j<list.size(); j++) {
                if (j==0) {
                    qList.add(Quaternion.fromChar(list.get(j)));
                } else {
                    qList.add(qmap.get(new Tuple(qList.get(j-1), Quaternion.fromChar(list.get(j)))));
                }
            }
            String result = "NO";
            // check last element
            int xmod = (int)(x % 4);
            Quaternion check = null;
            int limit = -1;
            if (xmod==0) {
                check = qList.get(base.size()*4-1);
                limit = base.size()*8;
            } else if (xmod==1) {
                check = qList.get(base.size()-1);
                limit = base.size()*5;
            } else if (xmod==2) {
                check = qList.get(base.size()*2-1);
                limit = base.size()*6;
            } else if (xmod==3) {
                check = qList.get(base.size()*3-1);
                limit = base.size()*7;
            }
            if (check==Quaternion.N_1) {
                if (x<=8) {
                    for (int j = 0; j < x*l - 2; j++) {
                        if (qList.get(j) == Quaternion.P_i) {
                            for (int k = j + 1; k < x*l - 1; k++) {
                                if (qList.get(k) == Quaternion.P_k) {
                                    result = "YES";
                                }
                            }
                        }
                    }
                } else {
                    for (int j = 0; j < limit - 2; j++) {
                        if (qList.get(j) == Quaternion.P_i) {
                            for (int k = j + 1; k < limit - 1; k++) {
                                if (qList.get(k) == Quaternion.P_k) {
                                    result = "YES";
                                }
                            }
                        }
                    }
                }
            }

            writer.write("Case #" + (i + 1) + ": " + result + "\n");
            System.out.println("Case #" + (i + 1) + ": " + result);
        }
        scanner.close();
        writer.close();
    }

    private enum Quaternion {
        P_1,
        P_i,
        P_j,
        P_k,
        N_1,
        N_i,
        N_j,
        N_k;

        public static Quaternion fromChar(char c) {
            if (c=='1')
                return P_1;
            else if (c=='i')
                return P_i;
            else if (c=='j')
                return P_j;
            else if (c=='k')
                return P_k;
            else
                throw new IllegalArgumentException("cannot covert:"+c);
        }
    }

    private class Tuple {
        private Quaternion first;
        private Quaternion second;
        private Tuple(Quaternion first, Quaternion second) {
            this.first = first;
            this.second = second;
        }
        public boolean equals(Object o) {
            if (o instanceof Tuple) {
                Tuple t = (Tuple) o;
                return (first==t.first) && (second==t.second);
            }
            return false;
        }

        public int hashCode() {
            return first.hashCode()*17+second.hashCode()*13;
        }
    }
}
