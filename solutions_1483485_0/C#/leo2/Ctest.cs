using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace test {
    public class Ctest {
        public void main(String FileName) {
            FileStream fs, fs2;
            StreamReader sr = null;
            StreamWriter sw = null;

            gmap gmap1 = new gmap();

            try {
                fs = new FileStream(FileName, FileMode.Open, FileAccess.Read, FileShare.ReadWrite);
                sr = new StreamReader(fs, Encoding.Default);
                fs2 = new FileStream("output.txt", FileMode.Create, FileAccess.ReadWrite, FileShare.Read);
                sw = new StreamWriter(fs2, Encoding.Default);

                //header
                string str = sr.ReadLine();

                int iSize = int.Parse(str);

                for (int ip = 0; ip < iSize; ip++) {
                    str = sr.ReadLine();

                    Console.Write("Case #" + (ip + 1) + ": ");
                    sw.Write("Case #" + (ip + 1) + ": ");
                    Console.WriteLine(gmap1.getText(str));
                    sw.WriteLine(gmap1.getText(str));
                }
            } catch (Exception ex) {
                Console.WriteLine(ex.Message);
            } finally {
                if (sr != null)
                    sr.Close();
                if (sw != null)
                    sw.Close();
            }
        }
    }

    public class gmap {
        private Dictionary<string, string> mMap = new Dictionary<string, string>();
        private Dictionary<string, string> mMapR = new Dictionary<string, string>();

        private void addMap(string str, string str2){
            for (int i = 0; i < str.Length; i++) {
                if (!mMap.ContainsKey(str.Substring(i, 1))) {
                    mMap.Add(str.Substring(i, 1), str2.Substring(i, 1));
                    mMapR.Add(str2.Substring(i, 1), str.Substring(i, 1));
                }
            }
        }

        public gmap() {
            addMap("ejp mysljylc kd kxveddknmc re jsicpdrysi", "our language is impossible to understand");
            addMap("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "there are twenty six factorial possibilities");
            addMap("de kr kd eoya kw aej tysr re ujdr lkgc jv", "so it is okay if you want to just give up");
            addMap("y", "a");
            addMap("e", "o");
            addMap("q", "z");
            addMap("z", "q");
        }

        public string getText(string str) {
            string sret = string.Empty;

            for (int i = 0; i < str.Length; i++) {
                if (!mMap.ContainsKey(str.Substring(i, 1))) {
                    sret += "*";
                } else {
                    sret += mMap[str.Substring(i, 1)];
                }
            }

            return sret;
        }

        public string getTextR(string str) {
            string sret = string.Empty;

            for (int i = 0; i < str.Length; i++) {
                if (!mMapR.ContainsKey(str.Substring(i, 1))) {
                    sret += "*";
                } else {
                    sret += mMapR[str.Substring(i, 1)];
                }
            }

            return sret;
        }
    }
}
