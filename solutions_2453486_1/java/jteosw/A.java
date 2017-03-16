import java.util.*;
public class A{
    static Scanner s;
    public static void main(String[] args){
        s = new Scanner(System.in);
        int rounds = s.nextInt();
        for (int i = 1; i <= rounds; i++) {
            s.nextLine();
            String result = play();
            System.out.printf("Case #%d: %s\n", i, result);
        }
    }

    public static String play() {
        int[][] array = new int[4][4];
        clear(array);
        store(array);
        String result = check(array);

        return result;

    }

    public static String check(int[][] array) {
        for(int i = 0; i < 4; i++) {
            int sum = 0;
            String result = "";
            for(int j = 0; j < 4; j++) {
                sum += array[i][j];
            }
            result = hum(sum);
            if (result.length() > 1) {
                return result;
            }
        }


        for(int i = 0; i < 4; i++) {
            int sum = 0;
            String result = "";
            for(int j = 0; j < 4; j++) {
                sum += array[j][i];
            }
            result = hum(sum);
            if (result.length() > 1) {
                return result;
            }
        }

        String result = "";
        result = hum(array[0][0] + array[1][1] + array[2][2] + array[3][3]);
        if (result.length() > 1) 
            return result;
        result = hum(array[0][3] + array[1][2] + array[2][1] + array[3][0]);
        if (result.length() > 1) 
            return result;
        result = scan(array);
        return result;

    }
    
    public static String hum(int sum) {
            if (sum == 4 || sum == 203) {
                return "O won";
            } else if (sum == 40 || sum == 230) {
                return "X won";
            } else return "";
    }

                

    public static String scan(int[][] array) {
        boolean flag = false;
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                if (array[i][j] == 0) {
                    flag = true;
                }
            }
        }
        if (flag) {
            return "Game has not completed";
        } else return "Draw";
    }

    public static void clear(int[][] array) {
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                array[i][j] = 0;
            }
        }
    }

    public static void store(int[][] array) {
        for(int i = 0; i < 4; i++) {
            String line = s.nextLine();
            for(int j = 0; j < 4; j++) {
                char c = line.charAt(j);
                int var;
                if (c == 'O') {
                    var = 1;
                } else if (c == 'X') {
                    var = 10;
                } else if (c == 'T') {
                    var = 200;
                } else {
                    var = 0;
                }
                array[i][j] = var;
            }
        }
    }
}
