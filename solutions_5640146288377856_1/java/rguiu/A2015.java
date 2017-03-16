import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.StringTokenizer;

public class A2015 {


    public static void main(String[] args) throws IOException {
        A2015 trans = new A2015();
        trans.doMe();
    }

    private static final String NAME = "A-large";

    public void doMe() throws IOException {
        File file = new File("./inputs/"+NAME + ".in");
        BufferedWriter out = new BufferedWriter(new FileWriter("./output/"+NAME+".out"));
        try {
            //use buffering, reading one line at a time
            //FileReader always assumes default encoding is OK!
            BufferedReader input = new BufferedReader(new FileReader(file));
            try {
                String line = input.readLine();
                int count = Integer.parseInt(line);

                for (int i=0;i<count;i++) {
                    line = input.readLine();
                    System.out.println(line);
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

    int[] toIntArray(String str) {
        StringTokenizer tokens = new StringTokenizer(str);
        int[] a= new int[tokens.countTokens()];
        int i = 0;
        while(tokens.hasMoreElements()) {
            a[i++] = Integer.parseInt(tokens.nextToken());
        }
        return a;
    }

    String proccessLine(String line) {
        int[] params = toIntArray(line);
        int rows = params[0];
        int cols = params[1];
        int width = params[2];

        int count = 0;

        int perrow = cols/width;

        count = perrow * rows;

        count += width - 1;

        if (perrow*width < cols) {
            count++;
        }

        return Integer.toString(count);
    }

}
