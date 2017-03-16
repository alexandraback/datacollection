package codejam2013;

import java.io.*;
import java.util.Collections;
import java.util.LinkedList;
import java.util.ListIterator;

public class QualsD extends CodeJam2013 {

    private class Chest {

        int type;
        boolean closed;
        LinkedList<Integer> inside;

        Chest(String[] vals) {
            type = Integer.parseInt(vals[0]);
            int num = Integer.parseInt(vals[1]);
            inside = new LinkedList();
            for (int i = 0; i < num; ++i) {
                inside.add(Integer.parseInt(vals[2 + i]));
            }
            closed = true;
        }

        public boolean isClosed() {
            return closed;
        }

        public int getType() {
            return type;
        }

        public LinkedList<Integer> getKeys() {
            return inside;
        }

        public int contains(int k) {
            ListIterator<Integer> iter = inside.listIterator(0);
            int count = 0;
            while (iter.hasNext()) {
                if (iter.next() == k) {
                    ++count;
                }
            }
            return count;
        }

        public LinkedList<Integer> open() {
            closed = false;
            return inside;
        }

        public void close() {
            closed = true;
        }
    }
    //variables here
    int nchests;
    int nkeys;
    LinkedList<Integer> keys;
    Chest[] chests;

    //solution algorithm here
    @Override
    public void solveCases(String inputSize) throws IOException {
        String infilename = "qD" + inputSize + "in.in";
        String outfilename = "qD" + inputSize + "out.in";

        //create output file if it does not exist, otherwise overwrite everything in it
        File file = new File("data/" + outfilename);
        if (!file.exists()) {
            file.createNewFile();
        }

        //create reader and writer for the input and output files
        BufferedReader br = new BufferedReader(new FileReader("data/" + infilename));
        BufferedWriter bw = new BufferedWriter(new FileWriter(file.getAbsoluteFile()));

        //get the number of test cases to use throughout solving process
        int numCases = Integer.parseInt(br.readLine());

        //create some temporary variables to use for storing input variabes and output string
        String line;
        String[] splitted;
        for (int i = 1; i <= numCases; i++) {
            //read in variables here
            line = br.readLine();
            splitted = line.split(" ");
            nkeys = Integer.parseInt(splitted[0]);
            nchests = Integer.parseInt(splitted[1]);
            chests = new Chest[nchests];
            keys = new LinkedList();

            line = br.readLine();
            splitted = line.split(" ");
            for (int j = 0; j < nkeys; ++j) {
                keys.add(Integer.parseInt(splitted[j]));
            }
            for (int j = 0; j < nchests; ++j) {
                line = br.readLine();
                splitted = line.split(" ");
                chests[j] = new Chest(splitted);
            }

            line = "Case #" + i + ": " + solve() + "\n"; //solve here
            bw.write(line);
            System.out.print(line);
        }
        br.close();
        bw.close();
    }

    private String linkedString(LinkedList<Integer> l) {
        String res = "";
        ListIterator<Integer> iter = l.listIterator(0);
        while (iter.hasNext()) {
            res += (iter.next() + 1) + " ";
        }
        return res;
    }

    private String solve() {
        int max = 0;
        for (int i = 0; i < nchests; ++i) {
            if (chests[i].getType() > max) {
                max = chests[i].getType();
            }
        }

        int[] numskeys = new int[max];
        for (int i = 0; i < max; ++i) {
            numskeys[i] = 0;
        }
        ListIterator<Integer> iter = keys.listIterator(0);
        int temp;
        while (iter.hasNext()) {
            temp = iter.next();
            if (temp <= max) {
                ++numskeys[temp - 1];
            }
        }
        LinkedList<Integer>[] pchests = new LinkedList[max];
        LinkedList<Integer>[] paths = new LinkedList[max];
        int r;
        for (int i = 0; i < max; ++i) {
            pchests[i] = new LinkedList();
            r = 0;
            for (int j = 0; j < nchests; ++j) {
                if (chests[j].getType() == (i + 1)) {
                    ++r;
                    pchests[i].add(j);
                } else if (chests[j].contains(i + 1) > 0) {
                    pchests[i].add(j);
                }
            }
            paths[i] = getPath(i + 1, r, numskeys[i], pchests[i]);
            if (paths[i].size() == 0) {
                return "IMPOSSIBLE";
            }
        }

        LinkedList<Integer> solution = new LinkedList();
        LinkedList<Integer> trial;
        boolean good;
        int type, index, opened = 0;
        while (opened < nchests) {
            good = false;
            trial = new LinkedList();
            for (int i = 0; i < max; ++i) {
                if (paths[i].size() > 0) {
                    while (!chests[paths[i].getFirst()].isClosed()) {
                        paths[i].removeFirst();
                        if (paths[i].size() == 0) {
                            break;
                        }
                    }
                    if (paths[i].size() > 0) {
                        trial.add(paths[i].getFirst());
                    }
                }
            }
            Collections.sort(trial);
            iter = trial.listIterator(0);
            while (iter.hasNext()) {
                temp = iter.next();
                type = chests[temp].getType();
                index = keys.indexOf(type);
                if (index > -1) {
                    keys.remove(index);
                    keys.addAll(chests[temp].open());
                    solution.add(temp);
                    ++opened;
                    good = true;
                    break;
                }
            }
            if (!good) {
                solution = recursiveSolve(keys, nchests - opened);
                if (solution.size() == 0) {
                    return "IMPOSSIBLE";
                }
                return linkedString(solution);
            }
        }
        return linkedString(solution);

    }

    private LinkedList<Integer> recursiveSolve(LinkedList<Integer> keys, int num) {
        if (keys.size() == 0) {
            return new LinkedList();
        }
        LinkedList<Integer> res = new LinkedList();
        LinkedList<Integer> temp;
        LinkedList<Integer> tkeys;
        int type;
        int index;
        for (int i = 0; i < chests.length; ++i) {
            if (chests[i].isClosed()) {
                type = chests[i].getType();
                index = keys.indexOf(type);
                if (index > -1) {
                    if (num == 1) {
                        res.add(i);
                        return res;
                    }
                    tkeys = new LinkedList(keys);
                    tkeys.remove(index);
                    tkeys.addAll(chests[i].open());
                    temp = recursiveSolve(tkeys, num - 1);
                    if (temp.size() == 0) {
                        chests[i].close();
                    } else {
                        res.add(i);
                        res.addAll(temp);
                        return res;
                    }
                }
            }
        }
        return res;
    }

    private boolean check() {
        int max = 0;
        for (int i = 0; i < nchests; ++i) {
            if (chests[i].getType() > max) {
                max = chests[i].getType();
            }
        }

        int[] numskeys = new int[max];
        for (int i = 0; i < max; ++i) {
            numskeys[i] = 0;
        }
        ListIterator<Integer> iter = keys.listIterator(0);
        int temp;
        while (iter.hasNext()) {
            temp = iter.next();
            if (temp <= max) {
                ++numskeys[temp - 1];
            }
        }
        LinkedList<Integer>[] pchests = new LinkedList[max];
        LinkedList<Integer>[] paths = new LinkedList[max];
        int r;
        for (int i = 0; i < max; ++i) {
            pchests[i] = new LinkedList();
            r = 0;
            for (int j = 0; j < nchests; ++j) {
                if (chests[j].getType() == (i + 1)) {
                    ++r;
                    pchests[i].add(j);
                } else if (chests[j].contains(i + 1) > 0) {
                    pchests[i].add(j);
                }
            }
            paths[i] = getPath(i + 1, r, numskeys[i], pchests[i]);
            if (paths[i].size() == 0) {
                return false;
            }
        }
        return true;
    }

    private LinkedList<Integer> getPath(int t, int r, int nk, LinkedList<Integer> chs) {
        LinkedList<Integer> res = new LinkedList();
        ListIterator<Integer> iter = chs.listIterator(0);
        int cnum;
        int cont;
        while (iter.hasNext()) {
            cnum = iter.next();
            cont = chests[cnum].contains(t);
            if (chests[cnum].getType() == t) {
                if (nk > 0 && !(nk == 1 && cont == 0 && r > 1)) {
                    nk += cont - 1;
                    --r;
                    res.add(cnum);
                    iter.remove();
                    iter = chs.listIterator(0);
                }
            } else if (cont > 0) {
                nk += cont;
                res.add(cnum);
                iter.remove();
                iter = chs.listIterator(0);
            }
        }
        if (r == 0) {
            return res;
        }
        return new LinkedList();
    }

    public static void main(String inputSize) {
        CodeJam2013 prob = new QualsD();
        try {
            prob.solveCases(inputSize);
        } catch (IOException e) {
            System.out.println("Cannot read or write to files.");
            System.out.println(e.getMessage());
        }
    }
}
