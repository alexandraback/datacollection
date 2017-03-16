import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.*;

public class C {
    Scanner input;
    PrintWriter output;
    Map<Set<Integer>, boolean[]> reachable;
    Queue<Set<Integer>> worklist;
    int max;

    public C(Scanner input, PrintWriter output){
        this.input = input;
        this.output = output;
    }

    public boolean allReachable(boolean[] reachableNumbers){
        for(int i = 1; i < reachableNumbers.length; i++){
            if(!reachableNumbers[i]){
                return false;
            }
        }
        return true;
    }

    public void solveProblem(int testCase){
        worklist = new LinkedList<>();
        reachable = new HashMap<>();
        input.nextInt(); // always 1
        int numberOfDistinctCoins = input.nextInt();
        max = input.nextInt();
        Set<Integer> coins = new HashSet<>();
        boolean[] reachableNumbers = new boolean[max + 1];
        reachableNumbers[0] = true;
        for(int i = 0; i < numberOfDistinctCoins; i++){
            int coin = input.nextInt();
            boolean[] nextReachableNumbers = reachableNumbers.clone();
            for(int number = 0; number < reachableNumbers.length; number++){
                if(reachableNumbers[number] && number + coin < (reachableNumbers.length)){
                    nextReachableNumbers[number + coin] = true;
                }
            }
            reachableNumbers = nextReachableNumbers;
            coins.add(coin);
        }
        worklist.add(new HashSet<>(coins));
        reachable.put(coins, reachableNumbers);

        if(allReachable(reachableNumbers)){
            output.println("Case #" + testCase + ": 0");
            return;
        }
        while(!worklist.isEmpty()){
            Set<Integer> currentWork = worklist.poll();


            for(int i = 1; i <= max; i++){
                if(!currentWork.contains(i)){
                    Set<Integer> nextWork = new HashSet<>(currentWork);
                    nextWork.add(i);
                    if(!reachable.containsKey(nextWork)){
                        boolean[] newReachable = reachable.get(currentWork);
                        boolean[] nextReachableNumbers = newReachable.clone();
                        for(int number = 0; number < newReachable.length; number++){
                            if(newReachable[number] && number + i < (newReachable.length)){
                                nextReachableNumbers[number + i] = true;
                            }
                        }
                        if(allReachable(nextReachableNumbers)){
                            nextWork.removeAll(coins);
                            output.println("Case #" + testCase + ": " + nextWork.size());
                            return;
                        }

                        reachable.put(nextWork, nextReachableNumbers);
                        worklist.add(nextWork);
                    }
                }
            }
        }
        System.out.println("nothing printed!");
    }

    public static void main(String[] args){
        final long startTime = System.currentTimeMillis();
        File file = new File("C.in");
        Scanner input = null;
        try {
            input = new Scanner(file).useLocale(Locale.US);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        PrintWriter output = null;
        try {
            output = new PrintWriter("C.out", "UTF-8");
        } catch (FileNotFoundException | UnsupportedEncodingException e) {
            e.printStackTrace();
        }

        int problems = input.nextInt();
        for(int i = 1; i <= problems; i++){
            System.out.println("processing problem" + i);
            new C(input, output).solveProblem(i);
        }
        output.close();
        final long endTime = System.currentTimeMillis();
        System.out.println("Total execution time: " + (endTime - startTime) + " ms");
    }
}
