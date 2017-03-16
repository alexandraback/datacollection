import java.io.*;

public class Omino {

    public static final String RICHARD = "RICHARD";
    public static final String GABRIEL = "GABRIEL";

    public static void main (String[] args) {
        BufferedReader br;
        BufferedWriter bw;
        try {
            br = new BufferedReader(new FileReader("D-small-attempt0.in"));
            bw = new BufferedWriter(new FileWriter("D-small.out"));
            int n = Integer.parseInt(br.readLine());
            for (int iii = 1; iii <= n; iii++) {
                bw.write("Case #" + iii + ": ");
                String[] splits = br.readLine().split(" ");
                int x = Integer.parseInt(splits[0]);
                int r = Integer.parseInt(splits[1]);
                int c = Integer.parseInt(splits[2]);
                if (x == 1) {
                    bw.write(GABRIEL);
                    bw.newLine();
                } else if (x == 2) {
                    if ((r * c) % 2 == 0) {
                        bw.write(GABRIEL);
                        bw.newLine();
                    } else {
                        bw.write(RICHARD);
                        bw.newLine();
                    }
                } else if (x == 3) {
                    if ((r * c) % 3 != 0) {
                        bw.write(RICHARD);
                        bw.newLine();
                    } else {
                        if (r == 1 || c == 1) {
                            bw.write(RICHARD);
                            bw.newLine();
                        } else {
                            bw.write(GABRIEL);
                            bw.newLine();
                        }
                    }
                } else if (x == 4) {
                    if ((r * c) % 4 != 0) {
                        bw.write(RICHARD);
                        bw.newLine();
                    } else {
                        if (r <= 2 || c <= 2) {
                            bw.write(RICHARD);
                            bw.newLine();
                        } else {
                            bw.write(GABRIEL);
                            bw.newLine();
                        }
                    }
                }
            }
            bw.close();
            br.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}
