using System.Collections.Generic;
using System.IO;

namespace FairAndSquare
{
    internal class Limit
    {
        public double MinLimit { get; set; }
        public double MaxLimit { get; set; }
    }

    internal class FileReader
    {
        public static List<Limit> GetLimits(string filename, out int testsCount)
        {
            var file = new StreamReader(filename);
            var line = file.ReadLine();
            int.TryParse(line, out testsCount);

            var result = new List<Limit>();

            string limitsString;
            while ((limitsString = file.ReadLine()) != null)
            {
                var limitSplit = limitsString.Split(' ');
                var limit = new Limit {MinLimit = double.Parse(limitSplit[0]), MaxLimit = double.Parse(limitSplit[1])};
                result.Add(limit);
            }

            file.Close();
            return result;
        }
    }
}
