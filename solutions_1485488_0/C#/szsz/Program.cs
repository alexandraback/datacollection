using System;
using System.Collections.Generic;
using System.Collections;
using System.Text;
using System.IO;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Formatters.Binary;



#region Hide
static public class Serializer
{
    static public void SerializeObject(string filename, object

objectToSerialize)
    {
        Stream stream = File.Open(filename, FileMode.Create);
        BinaryFormatter bFormatter = new BinaryFormatter();
        bFormatter.Serialize(stream, objectToSerialize);
        stream.Close();
    }

    static public object DeSerializeObject(string filename)
    {
        object objectToSerialize;
        Stream stream = File.Open(filename, FileMode.Open);
        BinaryFormatter bFormatter = new BinaryFormatter();
        objectToSerialize =
           (object)bFormatter.Deserialize(stream);
        stream.Close();
        return objectToSerialize;
    }
}

class Reader : System.IO.StreamReader
{


    public Reader(string path) : base(path) { }

    public int ReadInt()
    {
        if (this.EndOfStream)
            throw new Exception("end of stream");
        bool minus = false;
        while (!this.EndOfStream && !char.IsDigit((char)this.Peek()))
        {
            minus = this.Peek() == '-';
            this.Read();
        }
        int r = 0;
        while (!this.EndOfStream && char.IsDigit((char)this.Peek()))
        {
            r *= 10;
            r += this.Read() - '0';
        }
        if (minus)
            r *= -1;
        return r;
    }
    public long ReadLong()
    {
        if (this.EndOfStream)
            throw new Exception("end of stream");
        bool minus = false;
        while (!this.EndOfStream && !char.IsDigit((char)this.Peek()))
        {
            minus = this.Peek() == '-';
            this.Read();
        }
        long r = 0;
        while (!this.EndOfStream && char.IsDigit((char)this.Peek()))
        {
            r *= 10;
            r += this.Read() - '0';
        }
        if (minus)
            r *= -1;
        return r;
    }
    public char ReadChar()
    {
        if (this.EndOfStream)
            throw new Exception("end of stream");
        return (char)this.Read();
    }
    public string ReadWord()
    {
        if (this.EndOfStream)
            throw new Exception("end of stream");
        while (!this.EndOfStream && char.IsWhiteSpace((char)this.Peek()))
        {
            this.Read();
        }
        StringBuilder sb = new StringBuilder();

        while (!this.EndOfStream && !char.IsWhiteSpace((char)this.Peek()))
        {
            sb.Append((char)this.Read());
        }
        return sb.ToString();
    }
}
#endregion


class Program
{

    static void Main(string[] args)
    {
        Reader sr = new Reader("C:\\test\\in.in");
        StreamWriter sw = new StreamWriter("C:\\test\\out.out");
        sw.AutoFlush = true;
        int n = int.Parse(sr.ReadLine());
        Console.WriteLine(n);
        for (int i = 0; i < n; i++)
        {
            sw.WriteLine("Case #" + (i + 1).ToString() + ": " + Solution(sr));
            Console.WriteLine(i);
        }
        sw.Close();
        sr.Close();
        Console.WriteLine("Finished");
        Console.ReadLine();
    }


    static int N, M;
    static int[,] C;
    static int[,] F;
    static int H;
    const int Max = 100000000;
    static int[,] R;

    static void Read(Reader sr, int[,] X)
    {
        for (int i = 0; i < N; i++)
        {
            string[] t = sr.ReadLine().Split(' ');
            for (int j = 0; j < M; j++)
            {
                X[i, j] = int.Parse(t[j]);
            }
        }
    }


    static int TOE(int c, int f)//from here can enter
    {
        if (c - f < 50)
            return Max;
        return Math.Max(0, H - c + 50);
    }

    static int TOW(int f)// until here can kayak
    {
        return H - f - 20;
    }

    static int GAT(int x1, int y1, int x2, int y2, out int accesstime)// when can access 2
    {
        int c1 = C[x1, y1];
        int f1 = F[x1, y1];
        int c2 = C[x2, y2];
        int f2 = F[x2, y2];
        accesstime = Max;
        if (c2 - f2 < 50)
        {
            return Max;
        }
        if (c1 - f2 < 50)
        {
            return Max;
        }
        if (c2 - f1 < 50)
            return Max;

        accesstime = TOE(c2, f2);
        int tow = TOW(f1);
        int time = R[x1, y1];
        int startleave = Math.Max(time, accesstime);
        if (startleave <= tow)
            return startleave + 10;
        else
            return startleave + 100;
    }



    static void Search(int x1, int y1, int x2, int y2)
    {
        int at;
        int time = R[x1, y1];
        int next = GAT(x1, y1, x2, y2, out at);
        if (time == 0 && at == 0)
        {
            next = 0;
        }
        if (R[x2, y2] > next)
        {
            R[x2, y2] = next;
            Search(x2, y2);
        }
    }

    static void Search(int x, int y)
    {
        if (x > 0)
            Search(x, y, x - 1, y);
        if (y > 0)
            Search(x, y, x, y - 1);
        if (x < N - 1)
            Search(x, y, x + 1, y);
        if (y < M - 1)
            Search(x, y, x, y + 1);
    }


    static string Solution(Reader sr)
    {
        string[] t = sr.ReadLine().Split(' ');
        H = int.Parse(t[0]);
        N = int.Parse(t[1]);
        M = int.Parse(t[2]);
        C = new int[N, M];
        F = new int[N, M];
        R = new int[N, M];
        Read(sr, C);
        Read(sr, F);

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                R[i, j] = Max;
            }
        }
        R[0, 0] = 0;

        Search(0, 0);

        return ((double)R[N - 1, M - 1] / 10.0).ToString();
    }
}
