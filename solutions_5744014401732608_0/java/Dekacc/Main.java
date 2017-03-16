import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;

class Vertex{
    ArrayList<Integer> neigh;
    Vertex(){
        neigh = new ArrayList<>();
    }
}

public class Main {

    static int B;
    static int total;

    private static String toBinary(int n){
        StringBuilder out = new StringBuilder();
        while(n > 0){
            out.insert(0, n % 2);
            n /= 2;
        }
        return out.toString();
    }

    private static void runDFS(int current, Vertex[] ver, HashSet<Integer> inQueue){
        inQueue.add(current);
        for(int neig : ver[current].neigh){
            if(neig == B-1){
                total++;
                inQueue.remove(current);
                return;
            }
            if(!inQueue.contains(neig)){
                runDFS(neig, ver, inQueue);
            }
        }
        inQueue.remove(current);
    }

    private static void printMatrix(int[][] matrix){
        for(int i = 0; i<B; i++){
            for(int j = 0; j<B; j++){
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for(int itt = 1; itt <= T; itt++){

            B = sc.nextInt();
            int M = sc.nextInt();

            int power = (B*B) - B - (B-1) - (B-2);
            int hi = (int) Math.pow(2, power);

            boolean possible = false;

            int[][] matrix = new int[B][B];

            //bruteforce
            for(int i = 1; i < hi; i++){

                //generate matrix
                String bin = toBinary(i);

                for(int j = 0, len = power-bin.length(); j<len; j++){
                    bin = "0" + bin;
                }
                //System.out.println("BIN: " + power);

                int cur = 0;

                for(int j = 0; j < B; j++){
                    for(int k = 0; k < B; k++){
                        if(j == B - 1 || k == 0 || j == k) matrix[j][k] = 0;
                        else{
                            if(bin.charAt(cur) == '1') matrix[j][k] = 1;
                            else matrix[j][k] = 0;
                            cur++;
                        }
                    }
                }

                //check if paths from 1 to B equals M

                Vertex[] ver = new Vertex[B];
                for(int j = 0; j<B; j++) ver[j] = new Vertex();

                for(int j = 0; j < B; j++) {
                    for (int k = 0; k < B; k++) {
                        if(matrix[j][k] == 1) ver[j].neigh.add(k);
                    }
                }

                total = 0;
                runDFS(0, ver, new HashSet<Integer>());
                if(total == M){
                    possible = true;
                    break;
                }
            }

            if(possible){
                System.out.println("Case #" + itt + ": POSSIBLE");
                printMatrix(matrix);
            }
            else{
                System.out.println("Case #" + itt + ": IMPOSSIBLE");
            }

        }
    }
}
