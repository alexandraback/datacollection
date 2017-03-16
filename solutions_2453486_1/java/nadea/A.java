import java.io.*;
import java.text.MessageFormat;

public class A {
    private static String test = "Case #{0}: {1}";
    private static String xWon = "X won";
    private static String oWon = "O won";
    private static String draw = "Draw";
    private static String incomplete = "Game has not completed";

    public static void main(String[] args) {
        A instance = new A();
        instance.start();
    }

    private void start() {
        try {
            BufferedReader reader = new BufferedReader(new FileReader("A-small.in"));
            BufferedWriter writer = new BufferedWriter(new FileWriter("A-small.out"));
            int n = 4; // field;
            String s = reader.readLine().trim();
            int t = Integer.parseInt(s);
            for(int i = 0; i < t; ++i){
                String field[] = new String[4];
                field[0] = reader.readLine().trim();
                field[1] = reader.readLine().trim();
                field[2] = reader.readLine().trim();
                field[3] = reader.readLine().trim();
                reader.readLine();
                if (isWon(field, 'X')) {
                    writer.write("Case #" +(i+1)+": " +xWon);
                } else if (isWon(field, 'O')) {
                    writer.write(MessageFormat.format(test, i + 1, oWon));
                } else if (isEmpty(field)) {
                    writer.write(MessageFormat.format(test, i + 1, incomplete));
                } else {
                    writer.write(MessageFormat.format(test, (i + 1), draw));
                }
                if(i < t-1) {
                    writer.write("\n");
                }
            }
            reader.close();
            writer.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private boolean isEmpty(String[] field) {
        for (int i = 0; i < field.length; i++) {
            for (int j = 0; j < field.length; j++) {
                if (field[j].charAt(i) == '.') {
                    return true;
                }
            }
        }
        return false;
    }

    private boolean isWon(String[] field, char t) {
        boolean isLine = true;
        boolean isLine2 = true;
        for (int i = 0; i < field.length; i++) {
            isLine = true;
            isLine2 = true;
            for (int j = 0; j < field[0].length(); j++) {
                if(field[j].charAt(i) != t && field[j].charAt(i) != 'T'){
                    isLine = false;
                }
                if(field[i].charAt(j) != t && field[i].charAt(j) != 'T'){
                    isLine2 = false;
                }
            }
            if(isLine || isLine2){
                return true;
            }
        }
        isLine = true;
        isLine2 = true;
        for (int i = 0; i < field.length; i++) {
            if(field[i].charAt(i) != t && field[i].charAt(i) != 'T'){
                isLine = false;
            }
            if(field[3-i].charAt(i) != t && field[3-i].charAt(i) != 'T'){
                isLine2 = false;
            }
        }
        return isLine || isLine2;
    }

}