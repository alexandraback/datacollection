import java.util.List;
import java.io.InputStreamReader;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.io.BufferedWriter;
import java.util.Hashtable;
import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.FileOutputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.io.Writer;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Lokesh Khandelwal
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			inputStream = new FileInputStream("C-small-1-attempt4.in");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("output.txt");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
        int t=in.nextInt();
        int test;
        int x,y,z;
        List<String> list[]=new List[126];
        for(int i=0;i<=125;i++)
            list[i]=new ArrayList<String>();
        out.printLine("Case #1:");
        for(x=1;x<=5;x++)
        {
            String s1=""+x;
            for(y=1;y<=5;y++)
            {
                String s2=s1+""+y;
                for(z=1;z<=5;z++)
                {
                    String s3=s2+""+z;
                    int pro=x*y*z;
                    list[pro].add(s3);
                }
            }
        }
        for(test=1;test<=t;test++)
        {
            int r=in.nextInt(),n=in.nextInt(),m=in.nextInt(),k=in.nextInt();
            for(int i=0;i<r;i++)
            {
                int a[]=new int[k];
                for(int j=0;j<k;j++)
                    a[j]=in.nextInt();
                Arrays.sort(a);
                Hashtable<String,Integer> answers=new Hashtable<String, Integer>();
                String ans="222";
                for(String s  : list[a[0]])
                    answers.put(s, 1);
                for(int j=1;j<k;j++)
                {
                   for(String s : list[a[j]])
                   {
                       ans=s;
                   }
                }
                int index=2;
                String b="";
                for(int j=0;j<3;j++)
                {
                    if(ans.charAt(j)=='1')
                    {
                        b+=index;
                        index++;
                    }
                    else b+=ans.charAt(j);
                }
                out.printLine(b);
            }

        }
    }
}

class InputReader
{
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

	public OutputWriter(Writer writer) {
		this.writer = new PrintWriter(writer);
	}

	public void print(Object...objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}

	public void printLine(Object...objects) {
		print(objects);
		writer.println();
	}

	public void close() {
		writer.close();
	}
}

