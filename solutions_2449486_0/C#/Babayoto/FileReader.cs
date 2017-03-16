using System.Collections.Generic;
using System.IO;

namespace Lawnmower
{
    internal class FileReader
    {
        public static List<byte[,]> GetLawns(string filename, out int lawnsCount)
        {
            var file = new StreamReader(filename);
            var line = file.ReadLine();
            int.TryParse(line, out lawnsCount);

            var result = new List<byte[,]>();

            byte[,] currentLawn;
            while ((currentLawn = GetLawn(file)) != null)
            {
                result.Add(currentLawn);
            }

            file.Close();
            return result;
        }

        private static byte[,] GetLawn(StreamReader file)
        {
            var splitter = ' ';

            var dimensionsLine = file.ReadLine();

            if (string.IsNullOrEmpty(dimensionsLine))
                return null;

            var dimensionsStringSplit = dimensionsLine.Split(splitter);

            var rows = byte.Parse(dimensionsStringSplit[0]);
            var columns = byte.Parse(dimensionsStringSplit[1]);

            var currentLawn = new byte[columns, rows];

            for (int i = 0; i < rows; i++)
            {
                var rowSplit = file.ReadLine().Split(splitter);
               
                for (int j = 0; j < columns; j++)
                    currentLawn[j, i] = byte.Parse(rowSplit[j]);
            }
            return currentLawn;
        }
    }
}
