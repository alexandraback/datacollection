using System.IO;
using System.Linq;
using System.Text;

namespace Consonants
{
    class Program
    {
        static void Main(string[] args)
        {
            var fileName = "c:\\temp\\1A\\B-small.in";
            using (var reader = new StreamReader(fileName))
            using (var writer = new StreamWriter(Path.ChangeExtension(fileName, "out")))
            {
                var count = int.Parse(reader.ReadLine());
                for (var caseID = 1; caseID <= count; caseID++)
                {
                    var row = reader.ReadLine().Split(' ');
                    var x = int.Parse(row[0]);
                    var y = int.Parse(row[1]);

                    var path = GetPathTo(x, y);

                    writer.WriteLine("Case #{0}: {1}", caseID, path);
                    writer.Flush();
                }
            }
        }

        private static object GetPathTo(int x, int y)
        {
            var b = new StringBuilder();

            for (; x > 0;x--) b.Append("WE");
            for (; x < 0; x++) b.Append("EW");
            for (; y > 0; y--) b.Append("SN");
            for (; y < 0; y++) b.Append("NS");

            return b.ToString();
        }
    }
}
