using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

public class Input
{
    string data;
    public StringReader stringReader;

    public void loadString(string data)
    {
        this.data = data;
        init();
    }
    public void loadFile(string fileFullPath)
    {
        this.data = File.ReadAllText(fileFullPath);
        init();
    }
    private void init()
    {
        stringReader = new StringReader(data);
    }
    public string readLine()
    {
        string line;
        do
        {
            line = stringReader.ReadLine();
        } while (line != null && string.IsNullOrWhiteSpace(line.Trim()));

        return line;
    }
    public int readInt()
    {
        return Convert.ToInt32(readLine());
    }

    public long readLong()
    {
        return Convert.ToInt64(readLine());
    }

    public string[] readStrArr()
    {
        return readLine().Split(new[] {' '}, StringSplitOptions.RemoveEmptyEntries);
    }
    public int[] readIntArr()
    {
        var strArr = readStrArr();
        var list = new List<int>();
        foreach (var str in strArr)
        {
            list.Add(Convert.ToInt32(str));
        }
        return list.ToArray();
    }
    public long[] readLongArr()
    {
        var strArr = readStrArr();
        var list = new List<long>();
        foreach (var str in strArr)
        {
            list.Add(Convert.ToInt64(str));
        }
        return list.ToArray();
    }
}