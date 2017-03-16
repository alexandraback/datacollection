import java.util.*;

public class Main {
    
    public static void main(String[] args) throws Exception {
        Scanner scan = new Scanner(System.in);
        int taskCount = scan.nextInt();
        scan.nextLine();
        char[][] map = new char[4][];
        char[] arr = new char[]{'X', 'O'};
        outer:
        for (int taskIndex = 1; taskIndex <= taskCount; taskIndex++) {
            if (taskIndex > 1) {
                scan.nextLine();
            }
            for (int i = 0; i < 4; i++) {
                map[i] = scan.nextLine().toCharArray();
            }
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 2; j++) {
                    int count = 0;
                    for (int k = 0; k < 4; k++) {
                        if (map[i][k] == arr[j] || map[i][k] == 'T') {
                            count++;
                        }
                    }
                    if (count == 4) {
                        System.out.println(String.format("Case #%d: %c won", taskIndex, arr[j]));
                        continue outer;
                    }
                    count = 0;
                    for (int k = 0; k < 4; k++) {
                        if (map[k][i] == arr[j] || map[k][i] == 'T') {
                            count++;
                        }
                    }
                    if (count == 4) {
                        System.out.println(String.format("Case #%d: %c won", taskIndex, arr[j]));
                        continue outer;
                    }
                }
            }
            for (int i = 0; i < 2; i++) {
                int count = 0;
                for (int j = 0; j < 4; j++) {
                    if (map[j][j] == 'T' || map[j][j] == arr[i]) {
                        count++;
                    }
                }
                if (count == 4) {
                    System.out.println(String.format("Case #%d: %c won", taskIndex, arr[i]));
                    continue outer;
                }
                count = 0;
                for (int j = 0; j < 4; j++) {
                    if (map[j][3 - j] == 'T' || map[j][3 - j] == arr[i]) {
                        count++;
                    }
                }
                if (count == 4) {
                    System.out.println(String.format("Case #%d: %c won", taskIndex, arr[i]));
                    continue outer;
                }
            }
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if (map[i][j] == '.') {
                        System.out.println(String.format("Case #%d: Game has not completed", taskIndex));
                        continue outer;
                    }
                }
            }
            System.out.println(String.format("Case #%d: Draw", taskIndex));
        }
    }
}
