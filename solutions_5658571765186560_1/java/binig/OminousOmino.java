import java.io.*;
import java.util.*;

/**
 * Created by benoi_000 on 4/11/2015.
 */
public class OminousOmino {
    static int [][][][] omnios ={
            {{{0,0}}},
            {{{0,0},{1,0}}},
            {{{0,0},{1,0},{2,0}},{{0,0},{1,0},{1,1}}},
            {
                    {{0,0},{1,0},{2,0},{3,0}},
                    {{0,0},{1,0},{1,1},{0,1}},
                    {{0,0},{1,0},{1,1},{2,0}},
                    {{0,0},{1,0},{2,0},{2,1}},
                    {{0,0},{1,0},{1,1},{2,1}}
            },
            {
                    {{0,0},{1,0},{1,1},{0,1},{2,1}},
                    {{0,0},{1,0},{2,0},{3,0},{3,1}},
                    {{0,0},{1,0},{2,0},{3,0},{4,0}},

                    {{0,0},{1,0},{1,1},{2,0},{1,2}},
                    {{0,1},{1,1},{1,2},{2,1},{1,0}},

                    {{0,0},{1,0},{2,0},{2,1},{0,1}},
                    {{0,0},{1,0},{2,0},{2,1},{2,2}},
                    {{0,1},{1,1},{2,1},{2,2},{2,0}},

                    {{0,0},{1,0},{1,1},{2,1},{2,2}},
                    {{0,0},{1,0},{1,1},{2,1},{3,1}},
            },
            {
                    {{0,0},{1,0},{1,1},{0,1},{2,1},{2,0}},
                    {{0,0},{1,0},{1,1},{0,1},{2,1},{3,1}},
                    {{0,0},{1,0},{1,1},{0,1},{2,1},{0,2}},
                    {{1,0},{2,0},{2,1},{1,1},{3,1},{0,0}},

                    {{0,0},{1,0},{2,0},{3,0},{3,1},{3,2}},
                    {{0,0},{1,0},{2,0},{3,0},{3,1},{4,1}},
                    {{0,0},{1,0},{2,0},{3,0},{4,0},{5,0}},
                    {{0,0},{1,0},{2,0},{3,0},{4,0},{4,1}},

                    {{0,0},{1,0},{1,1},{2,0},{1,2},{1,3}},
                    {{0,0},{1,0},{1,1},{2,0},{1,2},{3,0}},
                    {{0,1},{1,1},{1,2},{2,1},{1,0},{1,3}},

                    {{0,0},{1,0},{2,0},{2,1},{0,1},{0,2}},
                    {{0,0},{1,0},{2,0},{2,1},{0,1},{3,1}},
                    {{0,0},{1,0},{2,0},{2,1},{0,1},{3,0}},
                    {{0,0},{1,0},{2,0},{2,1},{2,2}, {1,2}},
                    {{0,0},{1,0},{2,0},{2,1},{2,2},{3,0}},
                    {{0,1},{1,1},{2,1},{2,2},{2,0},{0,0}},
                    {{0,1},{1,1},{2,1},{2,2},{2,0},{3,1}},

                    {{0,0},{1,0},{1,1},{2,1},{2,2},{1,2}},
                    {{0,0},{1,0},{1,1},{2,1},{2,2},{3,2}},
                    {{0,0},{1,0},{1,1},{2,1},{2,2},{2,3}},
                    {{0,0},{1,0},{1,1},{2,1},{3,1},{4,1}},
                    {{0,0},{1,0},{1,1},{2,1},{3,1},{3,2}},
            },
    };
    public static void main(String args[]) throws IOException {
        InputStream inputStream = args.length<1?System.in:Thread.currentThread().getContextClassLoader().getResourceAsStream(args[0]);
        BufferedReader reader = new BufferedReader(new InputStreamReader(inputStream));
        PrintStream out = args.length<2?System.out:new PrintStream(new FileOutputStream(args[1]));
        int nbPb = Integer.parseInt( reader.readLine());
        for (int i=0;i<nbPb;i++) {
            processLine(i+1, reader.readLine(),out);
        }

    }

    // you need to move at least 2 to be worth it
    // and have a stack of 4 , moving 2 from 3 is useless
    // decide how to split ?  well if
    private static void processLine(int caseNb, String spec, PrintStream out) {
        boolean canWin =false;
        int startIdx =0;
        int idx = spec.indexOf(' ',startIdx);
        int X = Integer.parseInt(spec.substring(startIdx,idx));
        startIdx= idx+1;
        idx = spec.indexOf(' ',startIdx);
        int R = Integer.parseInt(spec.substring(startIdx, idx));
        startIdx= idx+1;
        int C = Integer.parseInt(spec.substring(startIdx));
        //to have R be the bigger side
        canWin = canWin(X,R,C);
        out.println( "Case #" +
                + caseNb+
                ": " +
                ( canWin?"GABRIEL":"RICHARD")  );
    }

    private static boolean canWin(int X, int R, int C) {
        if (X>6) return false;
        List<int[][]> omnios = getOmnios(X);
        for(int[][] ominio:omnios) {
           if(cantWin(ominio,X,R,C)) {
               return false;
           }
        }
        return true;

    }

    private static boolean cantWin(int[][] ominio, int X, int R, int C) {
        // we need to look up for a position where each space has a size % X
        // if found one return false
        for (int x=0;x<C;x++) {
            for(int y=0;y<R;y++) {
                if (canWin(ominio,x,y,X,R,C)) return false;
            }
        }


        return true;
    }

    private static boolean canWin(int[][] ominio, int x, int y, int X, int R, int C) {
        // for each (one rotation)  we check if its not out of the grid
        boolean hOk=true;
        boolean vOk =true;
        int[] groupsH = new int[R*C];
        int[] groupsV = new int[R*C];

        for (int[] coords:ominio) {
            hOk &=  coords[0]+x <C  && coords[1]+y <R ;
            vOk &=  coords[1]+x <C  && coords[0]+y <R ;
            if (hOk==false && vOk==false) return false;
            if (hOk) groupsH[coords[0]+x + (coords[1]+y)*C] =-1;
            if (vOk) groupsV[coords[1]+x + (coords[0]+y)*C] =-1;
        }
        int seqH = 0;
        int seqV = 0;
        for (int i=0;i<groupsH.length;i++) {
            if (hOk) { pushGroupMap(C, groupsH, i);
            }
            if (vOk) {
                pushGroupMap(C, groupsV, i);
            }
        }
        boolean ok = hOk&&checkGroups(X, groupsH)||vOk&&checkGroups(X, groupsV);
        return ok;
    }

    private static void pushGroupMap(int C, int[] groupsH, int i) {

        int g =  groupsH[i];
        if (g!=-1) {
            if (g == 0) {
                g = i;
                groupsH[i] = g;
            }
            g = getGroup(groupsH,g);
            List<Integer> idxes= new ArrayList<Integer>();
            idxes.add(-C);
            idxes.add(C);
            if ((i-1)/C == (i/C)) idxes.add(-1);
            if ((i+1)/C == (i/C)) idxes.add(1);
            for (int idx : idxes) {
                int j = i + idx;
                if (j >= 0 && j < groupsH.length ){
                    int gr = groupsH[j] ;
                     if (gr==0) {
                         groupsH[j]=g;
                     } else if (gr>0) {
                        int rg = getGroup(groupsH,gr);
                         if (rg!= g) {
                             groupsH[rg] =g;
                         }
                     }
                }
            }
        }

    }
    private static int getGroup(int[] group, int g) {
        if (g==0||g==-1) return g;
        int root=g;
        while(!(group[root]==root)) {
            root= group[root];
        }
        return root;
    }
    private static boolean checkGroups(int X, int[] groupsH) {
        Map<Integer,Integer> countByGroup = new HashMap<Integer, Integer>();
        for (int g: groupsH) {
            int group = getGroup(groupsH,g);

            if (countByGroup.containsKey(group)) {
                countByGroup.put(group, countByGroup.get(group)+1);
            } else {
                countByGroup.put(group,1);
            }
        }
        boolean ok=true;
        for(int count:countByGroup.values()) {
            ok&= count%X==0;
        }
        return ok;
    }

    private static List<int[][]> getOmnios(int X) {
        return Arrays
                .asList(omnios[X-1]);
    }

    private static void doRecurse(List<int[][]> res, int[][] omnio, int i) {


    }

}
