import java.util.Scanner;
import java.io.File;
import java.util.LinkedList;
import java.util.Stack;

public class A {
    public static void main(String[] args) {
        /* File Parsing Setup */
        Scanner input = null;

        try {
            input = new Scanner(new File(args[0]));
        } catch (Exception e) {
            System.out.println("Please pass a correct filename as a program parameter");
            System.exit(1);
        }

        int t = input.nextInt();
        input.nextLine();

        /* Solution Implementation */
        // For each test case
        for (int testCase = 0; testCase < t; testCase++) {
            int n = input.nextInt();
            input.nextLine();
            boolean diamond = false;

            LinkedList[] superclasses = new LinkedList[n];
            for (int init = 0; init < n; init++) {
                superclasses[init] = new LinkedList();
            }

            // For each class
            for (int i = 0; i < n; i++) {
                int m = input.nextInt();

                // For each inherited class, update the superclasses
                for (int j = 0; j < m; j++) {
                    int parent = input.nextInt()-1;
                    superclasses[i].add(new Integer(parent));
                }

                input.nextLine();
            }

            // Now DFS from every node and check if a node is revisited
            for (int i = 0; i < n; i++) {
                Stack stack = new Stack();
                
                boolean[] visited = new boolean[n];
                for (int set = 0; set < n; set++) {
                    visited[set] = false;
                }

                for (Object par : superclasses[i]) {
                    stack.push((Integer)par);
                }

                while (!stack.empty()) {
                    Integer next = (Integer)(stack.pop());

                    if (visited[next.intValue()]) {
                        // LOOP EXISTS
                        diamond = true;
                        break;
                    } else {
                        visited[next.intValue()] = true;
                    }

                    for (Object par : superclasses[next.intValue()]) {
                        stack.push((Integer)par);
                    }
                }

                if (diamond) {
                    break;
                }
            }

            System.out.print("Case #" + (testCase+1) + ": ");
            if (diamond) {
                System.out.println("Yes");
            } else {
                System.out.println("No");
            }
        }
    }
}