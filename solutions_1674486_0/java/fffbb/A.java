import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class A {
    public static void main(String[] args) throws Exception {
        if(args.length != 1) {
            return;
        }
        FileInputStream inputStream = new FileInputStream(args[0]);
        InputStreamReader istReader = new InputStreamReader(inputStream);
        BufferedReader buffReader = new BufferedReader(istReader);

        // T
        int T = Integer.valueOf(buffReader.readLine());

        for(int i = 1; i <= T; i++) {
            List<List<Integer>> diagram = new ArrayList<List<Integer>>();
            // M:num of classes
            int M = Integer.valueOf(buffReader.readLine());
            for(int j = 0; j < M; j++) {
                String[] term = buffReader.readLine().split(" ");
                // Mi:num of classes inherit
                int Mi = Integer.valueOf(term[0]);
                List<Integer> inherit = new ArrayList<Integer>();
                for(int k = 0; k < Mi; k++) {
                    int classNum = Integer.valueOf(term[k + 1]);
                    inherit.add(classNum);
                }
                diagram.add(inherit);
            }

            boolean twopath = false;
            for(int x = 1; x <= M; x++) {
                for(int y = 1; y <= M; y++) {
                    if(x == y) {
                        continue;
                    }
                    // <x, y>
                    List<Integer> targetQ = new ArrayList<Integer>();
                    Set<Integer> done = new HashSet<Integer>();
                    targetQ.add(x);
                    boolean onepath = false;
                    while(true) {
                        int target = targetQ.remove(0);
                        done.add(target);
                        List<Integer> targetinherit = diagram.get(target - 1);
                        if(targetinherit.contains(y)) {
                            if(onepath) {
                                twopath = true;
                                break;
                            } else {
                                onepath = true;
                            }
                        }
                        for(int from:targetinherit) {
                            if((!done.contains(from)) && (from != y)) {
                                targetQ.add(from);
                            }
                        }
                        if(targetQ.isEmpty()) {
                            break;
                        }
                    }
                    
                    if(twopath) {
                        break;
                    }
                }
                if(twopath) {
                    break;
                }
            }

            if(twopath) {
                putYes(i);
            } else {
                putNo(i);
            }
        }
    }

    public static void putYes(int caseNum) {
        System.out.println("Case #" + caseNum + ": Yes");
    }


    public static void putNo(int caseNum) {
        System.out.println("Case #" + caseNum + ": No");
    }
}
