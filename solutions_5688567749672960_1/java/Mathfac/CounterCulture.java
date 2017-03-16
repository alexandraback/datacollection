package jam2015_1B;

import java.io.*;
import java.util.StringTokenizer;

/**
 * Created by MatFuck on 11.04.15.
 */
public class CounterCulture {

    public static long flip(Long val) {
        return Long.parseLong((new StringBuilder(val.toString())).reverse().toString());
    }

    public static void main (String... aArguments) throws IOException {
        //File testFile = new File("src/jam2015_Qua/1A1.in");
        InputReader in = new InputReader(new FileInputStream("src/jam2015_1B/1A1.in"));
        //System.out.println("Original file contents: " + getContents(testFile));


        String ans[] = new String[1000];



        int NC = in.nextInt();


        for(int ci = 0; ci < NC; ci++)
        {
            long n = in.nextLong();
            long res = 0;
            long flip = 0;


            while(n > 19)
            {
                int nLen = ((n + "").length())/2;
                long b = 1;
                while ((nLen--) > 0) {
                    b *= 10;
                }
                long rest = (n % b);
                if(rest > 0)
                {
                    n -= rest - 1;
                    res += rest - 1;
                    long r = flip(n);
                    if(r < n)
                    {
                        ++res;
                        n = r;
                    }
                }
                ++res;
                --n;
            }

            ans[ci] = (res + n) + "";
        }




        String out ="";

        StringBuilder contents = new StringBuilder();

        for (int i=0;i<NC;i++){
            try {

                contents.append( "Case #" + (i+1)+ ": " + ans[i] );
                contents.append(System.getProperty("line.separator"));
            }
            catch (Exception ex){
                ex.printStackTrace();
            }
        }

        out = contents.toString();




        File outFile = new File("src/jam2015_1B/1B3.txt");
        outFile.createNewFile();
        setContents(outFile, out);
    }

    static public void setContents(File aFile, String aContents)
            throws FileNotFoundException, IOException {
        if (aFile == null) {
            throw new IllegalArgumentException("File should not be null.");
        }
        if (!aFile.exists()) {
            throw new FileNotFoundException ("File does not exist: " + aFile);
        }
        if (!aFile.isFile()) {
            throw new IllegalArgumentException("Should not be a directory: " + aFile);
        }
        if (!aFile.canWrite()) {
            throw new IllegalArgumentException("File cannot be written: " + aFile);
        }

        //use buffering
        Writer output = new BufferedWriter(new FileWriter(aFile));
        try {
            //FileWriter always assumes default encoding is OK!
            output.write( aContents );
        }
        finally {
            output.close();
        }
    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream));
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }


    }

}

