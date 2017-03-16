import java.util.Scanner;

public class MainB {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        sc.nextLine();
        for (int t = 1; t <= T; t++) {
            int x = sc.nextInt();
            int x1 = (x < 0) ? x * -1 : x;
            int y = sc.nextInt();
            int y1 = (y < 0) ? y * -1 : y;
            StringBuilder output = new StringBuilder();
            int c = 1;
            int px = 0;
            int py = 0;
            while (px + c <= x1 || py + c <= y1) {
                if (px + c == x1) {
                    px += c++;
                    output.append('E');
                } else if (py + c == y1) {
                    py += c++;
                    output.append('N');
                } else {
                    if (px + c < x1) {
                        px += c++;
                        output.append('E');
                    }
                    if (py + c < y1) {
                        py += c++;
                        output.append('N');
                    }
                }
            }
            for (int i = 0; i < x1 - px; i++) {
                output.append("WE");
            }
            for (int i = 0; i < y1 - py; i++) {
                output.append("SN");
            }
            String out = output.toString();
            StringBuilder out1 = new StringBuilder();
            for (int i = 0; i < out.length(); i++) {
                char ch = out.charAt(i);
                if (ch == 'E') {
                    if (x < 0) {
                        out1.append('W');
                    }
                    else {
                        out1.append('E');
                    }
                } else if (ch == 'W') {
                    if (x < 0) {
                        out1.append('E');
                    }
                    else {
                        out1.append('W');
                    }
                } else if (ch == 'N') {
                    if (y < 0) {
                        out1.append('S');
                    }
                    else {
                        out1.append('N');
                    }
                } else if (ch == 'S') {
                    if (y < 0) {
                        out1.append('N');
                    }
                    else {
                        out1.append('S');
                    }
                }
            }
            System.out.println("Case #" + t + ": " + out1);
        }
    }
}
