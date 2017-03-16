using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace Scratch
{
  public class Tongues
  {

    public static void Main()
    {
      string[] knowncipher = new []{
                               "ejp mysljylc kd kxveddknmc re jsicpdrysi",
                               "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
                               "de kr kd eoya kw aej tysr re ujdr lkgc jv",
                               "yeqz"
                             };
      string[] knownplain = new []{
                               "our language is impossible to understand",
                               "there are twenty six factorial possibilities",
                               "so it is okay if you want to just give up",
                               "aozq"
                             };
      Dictionary<char, char> map = new Dictionary<char, char>();
      for(int i=0;i<knowncipher.Length;i++)
      {
        for(int j=0;j<knowncipher[i].Length;j++)
        {
          map[knowncipher[i][j]]=knownplain[i][j];
        }
      }

      var reader = File.OpenText(@"C:\Users\raf.CRYPTOMATHIC\Downloads\A-small-attempt0 (1).in");
      var writer = File.CreateText(@"c:\temp\A-small-output.txt");
      int num = int.Parse(reader.ReadLine());
      for(int i=0;i<num;i++)
      {
        string cipher = reader.ReadLine();
        StringBuilder sb = new StringBuilder();
        for(int j=0;j<cipher.Length;j++)
        {
          sb.Append(map[cipher[j]]);
        }
        writer.WriteLine("Case #{0}: {1}", i+1, sb);
      }
      reader.Close();
      writer.Close();
    }
  }
}
