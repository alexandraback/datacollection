using System;
using System.IO;

public class FileUtil
{
    StreamReader inFile;
    string line;
    string[] currentLine;
    int currentIndex;

    StreamWriter outFile;

    Random random;

    public FileUtil(string input, string output)
    {
        random = new Random();

        currentLine = new string[0];
        currentIndex = 0;

        if (input != null)
        {
            inFile = new StreamReader(input);
        }
        if (output != null)
        {
            outFile = new StreamWriter(output);
        }
    }

    public uint readUnsignedInt()
    {
        return UInt32.Parse(readString());
    }

    public int readInt()
    {
        return Int32.Parse(readString());
    }

    public long readLong()
    {
        return Int64.Parse(readString());
    }

    public double readDouble()
    {
        return Double.Parse(readString());
    }

    public string readString()
    {
        ensureLine();
        return currentLine[currentIndex++];
    }

    public string readLine()
    {
        ensureLine();
        string result = line;

        currentIndex = currentLine.Length;

        return line;
    }

    private void ensureLine()
    {
        while (currentIndex >= currentLine.Length)
        {
            // use while in order to skip empty lines
            currentIndex = 0;
            line = inFile.ReadLine();

            if (line.Length == 0)
            {
                //empty line, increase the index to skip to the next line
                currentIndex++;
            }

            currentLine = line.Split(new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries);
        }
    }

    public void writeInt(int i)
    {
        outFile.Write(i.ToString() + " ");
    }

    public int writeRandomInt(int min, int max)
    {
        int value = (int)(random.NextDouble() * (max - min) + min);
        writeInt(value);

        return value;
    }

    public void writeLong(long l)
    {
        outFile.Write(l.ToString() + " ");
    }

    public long writeRandomLong(long min, long max)
    {
        long value = (long)(random.NextDouble() * (max - min) + min);
        writeLong(value);

        return value;
    }

    public void writeDouble(double d)
    {
        outFile.Write(String.Format("{0:0.00000000}", d) + " ");
    }

    public void writeString(string s)
    {
        outFile.Write(s + " ");
    }

    public void writeCase(int caseNumber)
    {
        writeString("Case #" + caseNumber.ToString() + ": ");
    }

    public void writeLine()
    {
        outFile.WriteLine();
    }

    public void writeStringLine(string s)
    {
        outFile.WriteLine(s);
    }

    public void writeDoubleLine(double d)
    {
        outFile.WriteLine(String.Format("{0:0.00000000}", d));
    }

    public void writeIntLine(int i)
    {
        outFile.WriteLine(i.ToString());
    }

    public int writeRandomIntLine(int min, int max)
    {
        int value = (int)(random.NextDouble() * (max - min) + min);
        writeIntLine(value);

        return value;
    }

    public void writeLongLine(long l)
    {
        outFile.WriteLine(l.ToString());
    }

    public long writeRandomLongLine(long min, long max)
    {
        long value = (long)(random.NextDouble() * (max - min) + min);
        writeLongLine(value);

        return value;
    }

    public void close()
    {
        if (inFile != null)
        {
            inFile.Close();
        }
        if (outFile != null)
        {
            outFile.Close();
        }
    }
}
