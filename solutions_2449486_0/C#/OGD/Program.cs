using System.IO;

namespace goo2013 {
    class Program {
        static void Main(string[] args) {
            string path = @"C:\goo\B-small-attempt2.in";
            var reader = new StreamReader(path);
            var writer = new StreamWriter(@"C:\goo\out.txt");
            int N = int.Parse(reader.ReadLine());
            int k = 0;
            bool readsize = true;
            string s;
            int n = 0;
            int m = 0;
            int i = 0;
            int[,] a = new int[1, 1];
            while ((s = reader.ReadLine()) != null) {
                if (readsize) {
                    k++;
                    var field = s.Split(' ');
                    n = int.Parse(field[0]);
                    m = int.Parse(field[1]);
                    readsize = false;
                    i = 0;
                    a = new int[n, m];
                } else {
                    var items = s.Split(' ');
                    int j = 0;
                    foreach (string item in items) {
                        a[i, j++] = int.Parse(item);
                    }
                    i++;
                    if (i == n) {
                        readsize = true;
                        string q = Solve(a);
                        writer.WriteLine("Case #" + k + ": " + q);
                    }
                }
            }
            writer.Close();
        }

        private static string Solve(int[,] a) {
            for (int i = 0; i < a.GetLength(0); i++) {
                for (int j = 0; j < a.GetLength(1); j++) {
                    int target = a[i, j];
                    int pathfound = 2;
                    //for (int k = i - 1; k >= 0; k--) {
                    //    if (a[k, j] > target) {
                    //        pathfound--;
                    //        break;
                    //    }
                    //}
                    for (int k = 0; k < a.GetLength(0); k++) {
                        if (a[k, j] > target) {
                            pathfound--;
                            break;
                        }
                    }
                    //for (int k = j - 1; k >= 0; k--) {
                    //    if (a[i, k] > target) {
                    //        pathfound--;
                    //        break;
                    //    }
                    //}
                    for (int k = 0; k < a.GetLength(1); k++) {
                        if (a[i, k] > target) {
                            pathfound--;
                            break;
                        }
                    }
                    if (pathfound == 0) {
                        return "NO";
                    }
                }
            }
            return "YES";
        }
    }
}
