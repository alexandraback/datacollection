package codejamround1c;

import java.io.*;
import java.util.Arrays;
import java.util.InputMismatchException;
 

class q2
{
    public static void main(String[] args) throws Exception
    {
    	BufferedReader br = new BufferedReader(new FileReader("blarge.txt"));
		PrintWriter printkaro = new PrintWriter("blargeout.txt");
		int t = Integer.parseInt(br.readLine());
        for( int ccc=1 ; ccc<=t ; ccc++ ) 
        {
        	String[] str = br.readLine().split(" ");
        	int b=Integer.parseInt(str[0]);
        	long m=Long.parseLong(str[1]);
        	if( Math.pow(2, b-2)<m )
        	{
        		printkaro.println("Case #"+ccc+": "+"IMPOSSIBLE");
        		continue;
        	}
        	char[][] myanswer = new char[b][b];
        	for( int i=0 ; i<b ; i++ )
        	{
        		for( int j=0 ; j<b ; j++ )
        		{
        			myanswer[i][j]='0';
        		}
        	}
        	for( int i=0 ; i<b-1 ; i++ )
        	{
        		for( int j=i+1 ; j<b-1 ; j++ )
        		{
        			myanswer[i][j]='1';
        		}
        	}
        	
        	String ss = Long.toBinaryString(m);
        	ss = new StringBuilder(ss).reverse().toString();
        	if( ss.length()==b-1 )
        	{
        		for( int i=0 ; i<b-1 ; i++ )
        		{
        			myanswer[i][b-1]='1';
        		}
        	}
        	else
        	{
        		for( int i=1 ; i-1<ss.length() ; i++ )
        		{
        			myanswer[i][b-1]=ss.charAt(i-1);
        		}
        	}
        	printkaro.println("Case #"+ccc+": "+"POSSIBLE");
        	for( int i=0 ; i<b ; i++ )
        	{
        		for( int j=0 ; j<b ; j++ )
        		{
        			printkaro.print(myanswer[i][j]);
        		}
        		printkaro.println();
        	}
        }
        printkaro.close();
        
    }
 
   
    
    private static class readkaro
    {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private SpaceCharFilter filter;
 
        public readkaro(InputStream stream)
        {
            this.stream = stream;
        }
 
        
        
        
        
        
        
        public int read()
        {
            if (numChars == -1)
                throw new InputMismatchException();
            if (curChar >= numChars)
            {
                curChar = 0;
                try
                {
                    numChars = stream.read(buf);
                } catch (IOException e)
                {
                    throw new InputMismatchException();
                }
                if (numChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }
 
        public int readInt()
        {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            int sgn = 1;
            if (c == '-')
            {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do
            {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }
 
        public String readString()
        {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            StringBuilder res = new StringBuilder();
            do
            {
                res.appendCodePoint(c);
                c = read();
            } while (!isSpaceChar(c));
            return res.toString();
        }
        public double readDouble() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            double res = 0;
            while (!isSpaceChar(c) && c != '.') {
                if (c == 'e' || c == 'E')
                    return res * Math.pow(10, readInt());
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            }
            if (c == '.') {
                c = read();
                double m = 1;
                while (!isSpaceChar(c)) {
                    if (c == 'e' || c == 'E')
                        return res * Math.pow(10, readInt());
                    if (c < '0' || c > '9')
                        throw new InputMismatchException();
                    m /= 10;
                    res += (c - '0') * m;
                    c = read();
                }
            }
            return res * sgn;
        }
        public long readLong() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }
        public boolean isSpaceChar(int c)
        {
            if (filter != null)
                return filter.isSpaceChar(c);
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }
 
        public String next()
        {
            return readString();
        }
 
        public interface SpaceCharFilter
        {
            public boolean isSpaceChar(int ch);
        }
    }
 
    private static class OutputWriter
    {
        private final PrintWriter writer;
 
        public OutputWriter(OutputStream outputStream)
        {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }
 
        public OutputWriter(Writer writer)
        {
            this.writer = new PrintWriter(writer);
        }
 
        public void print(Object... objects)
        {
            for (int i = 0; i < objects.length; i++)
            {
                if (i != 0)
                    writer.print(' ');
                writer.print(objects[i]);
            }
        }
 
        public void println(Object... objects)
        {
            print(objects);
            writer.println();
        }
 
        public void close()
        {
            writer.close();
        }
 
        public void flush()
        {
            writer.flush();
        }
     }
}