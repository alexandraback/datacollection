using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

public class Output
{   
    int caseCount;
    StreamWriter streamWriter;
    
    bool save2file;

    public Output()
    {
        save2file = false;
        init();
    }
    public Output(string fileFullPath)
    {
        setSaveFile(fileFullPath);
    }

    public void setSaveFile(string fileFullPath)
    {
        save2file = true;
        streamWriter = new StreamWriter(fileFullPath, false);
        init();
    }
    private void init()
    {
        caseCount = 0;
    }
    public void writeLine(string caseData)
    {
        var line = string.Format("Case #{0}: {1}", ++caseCount, caseData);
        if (save2file)
            streamWriter.WriteLine(line);
        Console.WriteLine(line);
    }
    public void end()
    {
        if (save2file)
            streamWriter.Close();
        Console.WriteLine("Done.");
        Console.ReadKey();
    }
}