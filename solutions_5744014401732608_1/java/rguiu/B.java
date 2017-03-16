import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.Arrays;

public class B {


    public static void main(String[] args) throws IOException {
        B trans = new B();
        trans.doMe();
    }

    private static final String NAME = "B-large";

    public void doMe() throws IOException {
        File file = new File("./inputs/"+NAME + ".in");
        BufferedWriter out = new BufferedWriter(new FileWriter("./output/"+NAME+".out"));
        try {
            BufferedReader input = new BufferedReader(new FileReader(file));
            try {
                String line = input.readLine();
                int count = Integer.parseInt(line);
                for (int i=0;i<count;i++) {
                    line = input.readLine();
                    String str = this.proccessLine(line.trim());
                    out.write("Case #"+(i+1)+": "+str);
                    if (i<count-1)
                        out.write(System.getProperty("line.separator"));
                    System.out.println(str);
                }
            } finally {
                input.close();
                out.flush();
                out.close();
            }
        } catch (IOException ex) {
            ex.printStackTrace();
        }
    }


    String proccessLine(String line) {
        String u[] = line.split(" ");
        int SIZE = Integer.parseInt(u[0]);
        BigInteger PATHS = new BigInteger(u[1]);

//        if (PATHS.compareTo(new BigInteger(u[0]))>0) {
//            return "IMPOSSIBLE";
//        }
        boolean[][] solution = new boolean[SIZE][SIZE];

        if (PATHS.compareTo(BigInteger.ONE) >= 0) {
            solution[0][SIZE-1] = true;
            PATHS = PATHS.subtract(BigInteger.ONE);
        }

        int counter = 1;


        BigInteger mem[] = new BigInteger[SIZE];
        Arrays.fill(mem, BigInteger.ZERO);
        mem[SIZE-1] = BigInteger.ONE;

        while(PATHS.compareTo(BigInteger.ZERO) != 0) {
            counter++;
            int uu = SIZE - counter;
            if (uu==0) break;
            solution[0][uu] = true;
            for (int i = uu+1; i < SIZE; i++) {
                BigInteger val = mem[i];
                if (val.compareTo(PATHS)<=0) {
                    solution[uu][i] = true;
                    PATHS = PATHS.subtract(val);
                    mem[uu] = mem[uu].add(mem[i]);
                }
            }
            solution[0][SIZE-1] = true;
        }

        if (PATHS.compareTo(BigInteger.ZERO)==0)
            return "POSSIBLE\n" + bolsToString(solution);
        else
            return "IMPOSSIBLE";
    }

    String bolsToString(boolean[][]map) {
        StringBuilder b = new StringBuilder();
        for (int i = 0; i < map.length; i++) {
            for (int j = 0; j < map[0].length; j++) {
                if (map[i][j]) b.append("1");
                else b.append("0");
            }
            b.append("\n");
        }
        return b.toString().trim();
    }
}
