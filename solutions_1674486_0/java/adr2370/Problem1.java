import java.io.*;
import java.util.*;
class Problem1
{
    public static void main (String [] args) throws Exception 
    {
        BufferedReader f = new BufferedReader(new FileReader("input.java"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("output.java")));
        StringTokenizer st = new StringTokenizer(f.readLine());
        int T=Integer.parseInt(st.nextToken());
        for(int t=0;t<T;t++) {
            st=new StringTokenizer(f.readLine());
            int N=Integer.parseInt(st.nextToken());
            ArrayList<ArrayList<ArrayList<Integer>>> paths=new ArrayList<ArrayList<ArrayList<Integer>>>();
            ArrayList<ArrayList<Integer>> inherits=new ArrayList<ArrayList<Integer>>();
            for(int i=0;i<N;i++) {
                st=new StringTokenizer(f.readLine());
                ArrayList<ArrayList<Integer>> currInherits=new ArrayList<ArrayList<Integer>>();
                ArrayList<Integer> otherCurr=new ArrayList<Integer>();
                int Mi=Integer.parseInt(st.nextToken());
                for(int j=0;j<Mi;j++) {
                    ArrayList<Integer> nextInherit=new ArrayList<Integer>();
                    int curr=Integer.parseInt(st.nextToken())-1;
                    nextInherit.add(curr);
                    currInherits.add(nextInherit);
                    otherCurr.add(curr);
                }
                paths.add(currInherits);
                inherits.add(otherCurr);
            }
            //System.err.println(paths);
            boolean changed=true;
            while(changed) {
                changed=false;
                for(int i=0;i<N;i++) {
                    for(int j=0;j<inherits.get(i).size();j++) {
                        ArrayList<ArrayList<Integer>> otherPaths=paths.get(inherits.get(i).get(j));
                        for(int k=0;k<otherPaths.size();k++) {
                            ArrayList<Integer> currPath=new ArrayList<Integer>(otherPaths.get(k));
                            currPath.add(inherits.get(i).get(j));
                            if(!paths.get(i).contains(currPath)) {
                                paths.get(i).add(currPath);
                                changed=true;
                            }
                        }
                    }
                }
                if(t==19) System.err.println(paths.get(0));
            }
            boolean anyDiamonds=false;
            for(int i=0;i<N;i++) {
                ArrayList<Integer> allOthers=new ArrayList<Integer>();
                for(int j=0;j<paths.get(i).size();j++) {
                    if(paths.get(i).get(j).get(0)!=i&&allOthers.contains(paths.get(i).get(j).get(0))) {
                        anyDiamonds=true;
                    }
                    allOthers.add(paths.get(i).get(j).get(0));
                }
            }
            System.err.println("Case #"+(t+1));
            if(anyDiamonds) {
                out.println("Case #"+(t+1)+": Yes");
            } else {
                out.println("Case #"+(t+1)+": No");
            }
        }
        out.close();
        System.exit(0);
    }
}