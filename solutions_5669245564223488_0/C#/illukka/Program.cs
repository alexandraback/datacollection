using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProblemB
{
    class InputOutput : IDisposable
    {
        const string input = "e:\\round1b\\B-small-attempt0.in";
        const string output = "e:\\round1b\\B-small-attempt0.out";

        List<string> lines;
        int currentLine;

        StreamWriter writer;

        public InputOutput()
        {
            using (StreamReader sr = new StreamReader(input))
            {
                String line = sr.ReadToEnd();
                lines = new List<string>(line.Split(new string[] { "\r\n", "\n" }, StringSplitOptions.RemoveEmptyEntries));
                currentLine = 0;
            }

            writer = new StreamWriter(output, false, Encoding.ASCII);
            writer.NewLine = "\n";
        }

        public string NextLine()
        {
            if (lines != null && currentLine >= 0 && currentLine < lines.Count)
            {
                return lines[currentLine++];
            }

            return null;
        }

        public static int AsInt(string line)
        {
            return Convert.ToInt32(line);
        }

        public static double AsDouble(string line)
        {
            return Convert.ToDouble(line, System.Globalization.CultureInfo.InvariantCulture);
        }

        public int Int()
        {
            return AsInt(NextLine());
        }

        public double Double()
        {
            return AsDouble(NextLine());
        }

        public List<int> Ints()
        {
            var line = NextLine();
            var list = line.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            var ret = new List<int>(list.Length);

            foreach (var item in list)
            {
                ret.Add(AsInt(item));
            }

            return ret;
        }

        public void Ints(out int i1, out int i2)
        {
            var line = NextLine();
            var list = line.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);

            i1 = 0;
            i2 = 0;

            if (list.Length > 0)
            {
                i1 = AsInt(list[0]);
            }

            if (list.Length > 1)
            {
                i2 = AsInt(list[1]);
            }
        }

        public void Ints(out int i1, out int i2, out int i3)
        {
            var line = NextLine();
            var list = line.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);

            i1 = 0;
            i2 = 0;
            i3 = 0;

            if (list.Length > 0)
            {
                i1 = AsInt(list[0]);
            }

            if (list.Length > 1)
            {
                i2 = AsInt(list[1]);
            }

            if (list.Length > 2)
            {
                i3 = AsInt(list[2]);
            }
        }

        public List<double> Doubles()
        {
            var line = NextLine();
            var list = line.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            var ret = new List<double>(list.Length);

            foreach (var item in list)
            {
                ret.Add(AsDouble(item));
            }

            return ret;
        }

        public List<string> Strings()
        {
            var line = NextLine();
            return new List<string>(line.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries));
        }

        public void Dispose()
        {
            if (writer != null)
            {
                writer.Close();
                writer.Dispose();
                writer = null;
            }
        }

        public void WriteLine(string line)
        {
            writer.WriteLine(line);
        }
    }

    class Car
    {
        public char start;
        public char end;

        public string id;
        public bool used;
    }

    class Program
    {
        static long vaihtoehtoja = 0;
        const long evil = 1000000007;

        static bool CanCombine1(List<Car> c1, Car c2)
        {
            Car last = c1.Last();

            if (last.end == c2.start)
            {
                for (int i = 0; i < c1.Count - 1; i++ )
                {
                    if(c1[i].end != c1[i + 1].start &&
                        c1[i].end == c2.start)
                    {
                        return false;
                    }
                }

                return true;
            }

            return false;
        }

        static bool CanCombine2(List<Car> c1, Car c2)
        {
            Car last = c1.Last();

            if (last.end == c2.start)
            {
                for (int i = 0; i < c1.Count - 1; i++)
                {
                    if (c1[i].end != c1[i + 1].start &&
                        c1[i].end == c2.start)
                    {
                        return false;
                    }
                }

                return true;
            }

            var let = c2.id.ToArray();

            foreach (var item in c1)
            {
                if (item.id.IndexOfAny(let) != -1)
                {
                    return false;
                }
            }

            return true;
        }

        static void PickNext(List<Car> cars, List<Car> set, int level)
        {
            if(level == cars.Count)
            {
                if(set[0].start != set[set.Count - 1].end)
                {
                    if (++vaihtoehtoja == evil)
                    {
                        vaihtoehtoja = 0;
                    }
                }

                return;
            }

            bool easyCombines = false;

            for (int i = 0; i < cars.Count; i++)
            {
                if (!cars[i].used && (set.Count == 0 ||
                    CanCombine1(set, cars[i])))
                {
                    easyCombines = true;
                    cars[i].used = true;
                    set.Add(cars[i]);
                    PickNext(cars, set, level + 1);
                    set.RemoveAt(set.Count - 1);
                    cars[i].used = false;
                }
            }

            if (!easyCombines)
            {
                for (int i = 0; i < cars.Count; i++)
                {
                    if (!cars[i].used && (set.Count == 0 ||
                        CanCombine2(set, cars[i])))
                    {
                        cars[i].used = true;
                        set.Add(cars[i]);
                        PickNext(cars, set, level + 1);
                        set.RemoveAt(set.Count - 1);
                        cars[i].used = false;
                    }
                }
            }
        }

        static void Main(string[] args)
        {
            

            using (var io = new InputOutput())
            {
                int tc = io.Int();

                for (int t = 0; t < tc; t++)
                {
                    int carcount = io.Int();
                    List<string> carid = io.Strings();
                    List<Car> carUsed = new List<Car>();
                    vaihtoehtoja = 0;

                    if(carcount == 0)
                    {
                        vaihtoehtoja = 0;
                    }
                    else if(carcount == 1)
                    {
                        vaihtoehtoja = 1;
                    }
                    else
                    {
                        foreach (var str in carid)
                        {
                            Car c = new Car();
                            c.id = str;
                            c.start = str[0];
                            c.end = str[str.Length - 1];
                            c.used = false;
                            carUsed.Add(c);
                        }

                        PickNext(carUsed, new List<Car>(), 0);
                    }
                    
                    string line = string.Format("Case #{0}: {1}", t + 1, vaihtoehtoja);
                    io.WriteLine(line);
                    Console.WriteLine(line);
                }
            }
        }
    }
}
