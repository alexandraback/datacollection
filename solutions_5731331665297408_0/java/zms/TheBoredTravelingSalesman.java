package com.zms.gcj;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.*;


public class TheBoredTravelingSalesman {

    public static String resolveOne(Collection<Integer> visited,List<Integer> path,int N,String result,List<PairObj> pairs,List<PairObj> pairs1) {
        if(visited.size()<1) {
            for (PairObj one : pairs) {
                visited.add(one.from);
                visited.add(one.to);
                path.add(one.from);
                path.add(one.to);
                result+=one.zip1+one.zip2;
                String s=resolveOne(visited, path, N, result, pairs,pairs1);
                if(s!=null) {
                    return s;
                }
                visited.clear();
                path.clear();
                result="";
            }
            return null;
        } else if(visited.size()==N) {
            return result;
        } else {
            List<Integer> path1=new ArrayList<>(path);
            String s=result;
            for (PairObj one : pairs1) {
                int index=path.indexOf(one.from);
                if(index>=0 && !visited.contains(one.to)) {
                    visited.add(one.to);
                    while(path.size()>(index+1)) {
                        path.remove(index+1);
                    }
                    path.add(one.to);
                    result+=one.zip2;
                    String ss=resolveOne(visited, path, N, result, pairs,pairs1);
                    if(ss!=null) {
                        return ss;
                    }
                    path.clear();
                    path.addAll(path1);
                    visited.remove(one.to);
                    result=s;
                }
            }
            return null;
        }
    }

    public static void main(String[] args) throws Exception {
        File folder = new File("C:\\Users\\zms\\Downloads");
        File input = new File(folder, "C-small-attempt2.in");
        File output = new File(folder, "C-small-attempt2.out");
        try (Scanner scanner = new Scanner(new FileInputStream(input))) {
            try (PrintWriter writer = new PrintWriter(new FileOutputStream(output))) {
                int T = scanner.nextInt();
                for (int k = 1; k <= T; k++) {
                    int N = scanner.nextInt();
                    int M = scanner.nextInt();
                    List<String> zips=new ArrayList<>(N);
                    for(int i=0;i<N;i++) {
                        zips.add(scanner.next());
                    }
                    List<PairObj> pairs=new ArrayList<>();
                    for(int i=0;i<M;i++) {
                        int a=scanner.nextInt();
                        int b=scanner.nextInt();
                        PairObj one=new PairObj();
                        one.from=a-1;
                        one.to=b-1;
                        one.zip1=zips.get(a-1);
                        one.zip2=zips.get(b-1);
                        pairs.add(one);
                        one=new PairObj();
                        one.from=b-1;
                        one.to=a-1;
                        one.zip1=zips.get(b-1);
                        one.zip2=zips.get(a-1);
                        pairs.add(one);
                    }
                    Collections.sort(pairs);
                    List<PairObj> pairs1=new ArrayList<>(pairs);
                    Collections.sort(pairs1,new Comparator<PairObj>() {
                        @Override
                        public int compare(PairObj o1, PairObj o2) {
                            return o1.zip2.compareTo(o2.zip2);
                        }
                    });
                    String s;
                    if(N==1) {
                        s=zips.get(0);
                    } else {
                        s=resolveOne(new HashSet<Integer>(),new ArrayList<Integer>(),N,"",pairs,pairs1);
                    }
                    assert s!=null;
                    writer.printf("Case #%d: %s\n", k, s);
                }
            }
        }
    }

}

class PairObj implements Comparable<PairObj> {
    int from;
    int to;
    String zip1;
    String zip2;

    @Override
    public int compareTo(PairObj o) {
        int n=zip1.compareTo(o.zip1);
        if(n==0) {
            n=zip2.compareTo(o.zip2);
        }
        return n;
    }
}