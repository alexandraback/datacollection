using System.Collections.Generic;
using System.IO;

namespace StoreCredit
{
    internal class FileReader
    {
        public static List<char[,]> GetDescks(string filename, int desckSize, out int desckCount)
        {
            var file = new StreamReader(filename);
            var line = file.ReadLine();
            int.TryParse(line, out desckCount);

            var result = new List<char[,]>();

            char[,] currentDesck;
            while ((currentDesck = GetDesck(file, desckSize)) != null)
            {
                result.Add(currentDesck);
                file.ReadLine();
            }

            file.Close();
            return result;
        }

        private static char[,] GetDesck(StreamReader file, int size)
        {
            var currentDesck = new char[size, size];

            for (int i = 0; i < size; i++)
            {
                var line = file.ReadLine();
                if (string.IsNullOrEmpty(line) || line.Length != size)
                    return null;
                for (int j = 0; j < size; j++)
                    currentDesck[i, j] = line[j];
            }
            return currentDesck;
        }
    }
}
