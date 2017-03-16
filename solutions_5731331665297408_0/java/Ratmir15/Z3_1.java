package c2014_c.c2014_r2;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.*;

public class Z3_1 {

    public static void main(String[] args) throws Exception {
        FileWriter fw = new FileWriter("C:\\output.txt");
        BufferedWriter out = new BufferedWriter(fw);
        //String pathname = "C:\\Users\\YC14rp1\\Downloads\\z3.txt";
        String pathname = "C:\\Users\\YC14rp1\\Downloads\\C-small-attempt1.in";
        //String pathname = "C:\\Users\\YC14rp1\\Downloads\\D-large.in";
        Scanner scanner = new Scanner(new File(pathname));
        int tn = scanner.nextInt();
        scanner.nextLine();
        for (int ti = 1; ti <= tn; ti++) {
            int n = scanner.nextInt();
            int m = scanner.nextInt();
            //String s1 = scanner.next();
            //String s2 = scanner.next();
            Integer[] idxs = readArray(scanner, n);
            System.out.println(Arrays.toString(idxs));
            int[][] matrix = new int[n][n];
            readGraphAsMatrix(scanner, m, matrix);
            //System.out.println(Arrays.deepToString(matrix));
            List<Integer> res = null;
            for (int i=0;i<n;i++) {
                List<Integer> visited = new ArrayList<Integer>();
                visited.add(i);
                List<Integer> refs = new ArrayList<Integer>();
                refs.add(-1);
                List<List<Integer>> list = find(visited,refs, i, matrix);
                for (List<Integer> integers : list) {
                    if (res==null ) { res = integers;}
                    //System.out.println(integers);
                    if (less(integers, res, idxs)) {
                        res = integers;
                    }
                }
            }

            System.out.println(res);
            String result = "";
            if (res!=null) {
                for (Integer re : res) {
                    result += idxs[re];
                }
            } else {
                if (n!=1) {
                    result = "FAIL!";
                } else {
                    result = idxs[0].toString();
                }
            }
            String s;
                s = "Case #" + ti + ": "+result;
            System.out.println(s);
            out.write(s);
            out.write("\n");
        }
        out.close();
    }

    private static boolean less(List<Integer> integers, List<Integer> res, Integer[] idxs) {
        if (integers.size()!=res.size()) {
            System.out.println(integers);
            System.out.println(res);
            throw new UnsupportedOperationException();
        }
        if (idxs[integers.get(0)]<idxs[res.get(0)]) {
            return true;
        }
        if (idxs[integers.get(0)]>idxs[res.get(0)]) {
            return false;
        }
        if (integers.size()==1) {
            return false;
        }
        return less(integers.subList(1,integers.size()),res.subList(1,res.size()),idxs);
    }

    private static List<List<Integer>> find(List<Integer> visited, List<Integer> refs, int cur, int[][] matrix) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        //int cur = visited.get(visited.size()-1);
        HashSet<Integer> vis = new HashSet<Integer>();
        vis.addAll(visited);
        for (int i=0;i<matrix.length;i++) {
            if (matrix[cur][i]==1) {
                if (!vis.contains(i)) {
                    List<Integer> nl = new ArrayList<Integer>();
                    nl.addAll(visited);
                    nl.add(i);
                    List<Integer> nr = new ArrayList<Integer>();
                    nr.addAll(refs);
                    nr.add(cur);
                    if (nl.size()==matrix.length) {
                        res.add(nl);
                        //return visited;
                    } else {
                        res.addAll(find(nl, nr, i, matrix));
                    }
                }
            }
        }
        /*int prev = -1;
        for (int k=0;k<visited.size();k++) {
            if (visited.get(k)==cur) {
                if (k>0) {
                    prev=visited.get(k-1);
                }
            }
        } */
        if (visited.get(0)!=cur) {
            int prev = -1;
            for (int k=0;k<visited.size();k++) {
                if (visited.get(k)==cur) {
                    prev=refs.get(k);
                }
            }
            res.addAll(find(visited, refs, prev, matrix));
        }
        return res;
    }

    // 1 2/ 2 3 -> [[0 1 0],[1 0 1],[0 1 0]]
    private static void readGraphAsMatrix(Scanner scanner, int n, int[][] matrix) {
        for (int i=0;i<n;i++) {
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            matrix[x-1][y-1] = 1;
            matrix[y-1][x-1] = 1;
        }
    }

    // sdf ssf ggg -> [3]
    private static Integer[] readArray(Scanner scanner, int n) {
        Integer[] l2 = new Integer[n];
        for (int i=0;i<n;i++) {
            l2[i] = scanner.nextInt();
        }
        return l2;
    }

}
