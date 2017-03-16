import java.io.InputStreamReader;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.PriorityQueue;
import java.util.Locale;
import java.io.PrintStream;
import java.io.BufferedReader;
import java.io.FileOutputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.io.File;
import java.io.Writer;
import java.util.StringTokenizer;
import java.io.FilenameFilter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        InputStream inputStream;
        try {
            final String regex = "B-(small|large).*[.]in";
            File directory = new File(".");
            File[] candidates = directory.listFiles(new FilenameFilter() {
                public boolean accept(File dir, String name) {
                    return name.matches(regex);
                }
            });
            File toRun = null;
            for (File candidate : candidates) {
                if (toRun == null || candidate.lastModified() > toRun.lastModified())
                    toRun = candidate;
            }
            inputStream = new FileInputStream(toRun);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        OutputStream outputStream;
        try {
            outputStream = new FileOutputStream("b.out");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskB solver = new TaskB();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }
}

class TaskB {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int k=in.nextInt(),l=in.nextInt(),s=in.nextInt();
        String monkey=in.next();
        String target=in.next();
        recurse(monkey,"",s);
        int maxBananas=Integer.MIN_VALUE;
        PriorityQueue<String> copy=new PriorityQueue<String>();
        for(int i=0;ar.size()>0;i++){
            String str=ar.poll();
            copy.add(str);
            int tmp=0;
            while (str.indexOf(target)>=0){
                str=str.substring(str.indexOf(target)+1,str.length());
                tmp++;
            }
            if(tmp>maxBananas)
                maxBananas=tmp;
        }
        int totalStrings=copy.size();
        double ans=0.0;
        for(int i=0;copy.size()>0;i++){
            String str=copy.poll();
            //System.out.println(str);
            int tmp=0;
            while (str.indexOf(target)>=0){
                str=str.substring(str.indexOf(target)+1,str.length());
                tmp++;
            }
            int remainingBananas=maxBananas-tmp;
            ans+=remainingBananas*(1.0/(double)totalStrings);
        }
        //System.out.println(totalStrings);
        System.out.println("Case #" + testNumber + ": " + ans);
    }
    PriorityQueue<String> ar=new PriorityQueue<String>();
    void recurse(String monkey,String s,int l){
        if(s.length()==l){
            //if(!ar.contains(s))
                ar.add(s);
            return;
        }
        else {
            for(int i=0;i<monkey.length();i++){
                recurse(monkey,s+monkey.charAt(i),l);
            }
        }
    }
}

class InputReader {
    BufferedReader in;
    StringTokenizer tokenizer=null;

    public InputReader(InputStream inputStream)
    {
        in=new BufferedReader(new InputStreamReader(inputStream));
    }
    public String next()
    {
        try{
            while (tokenizer==null||!tokenizer.hasMoreTokens())
            {
                tokenizer=new StringTokenizer(in.readLine());
            }
            return tokenizer.nextToken();
        }
        catch (IOException e)
        {
            return null;
        }
    }
    public int nextInt()
    {
        return Integer.parseInt(next());
    }
}

class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

    public void close() {
            writer.close();
        }
}

