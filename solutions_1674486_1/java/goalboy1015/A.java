
import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;

public class A {

    public static void main(String args[]) throws Exception {
        final String PATH = "/home/goalboy/software installation/codejam-commandline-1.0-beta4/source/";
        final String FILE = "A-large-0";
        Scanner in = new Scanner(new File(PATH + FILE + ".in"));
        PrintWriter out = new PrintWriter(PATH + FILE + ".out");

        int test = in.nextInt();
        for (int t = 1; t <= test; t++) {
            int N=in.nextInt();
            ArrayList<Integer> childrens[] = new ArrayList[N];
            for (int i=0;i<N;i++) {
                int M=in.nextInt();
                childrens[i]=new ArrayList<Integer>();
                for (int j=0;j<M;j++) {
                    int index=in.nextInt()-1;
                    childrens[i].add(index);
                }
            }
            boolean checked[]=new boolean[N];
            boolean diamond=false;
            for (int i=0;i<N;i++) {
                if (!checked[i] && hasDiamond(i, new HashSet<Integer>(), childrens, checked)) {
                    diamond=true;
                    break;
                }
            }
            out.print("Case #"+t+": ");
            if (diamond) {
                out.println("Yes");
            }
            else {
                out.println("No");
            }
        }

        out.close();
    }
    
    static boolean hasDiamond(int current, HashSet<Integer> path, ArrayList<Integer> childrens[],boolean checked[]) {
        path.add(current);
        checked[current]=true;
        for (int child:childrens[current]) {
            if (path.contains(child)) {
                return true;
            }
            path.add(child);
            if (hasDiamond(child, path, childrens, checked)) {
                return true;
            }
        }
        return false;
    }
}
