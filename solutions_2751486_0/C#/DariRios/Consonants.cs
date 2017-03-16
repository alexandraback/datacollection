using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Round1C
{
    class Consonants
    {
        public static int CalculateN(String name, int n)
        {
            int numberOfN = 0;

            for (int i = name.Length; i >= n; i--)
            {
                for (int j = 0; j <= name.Length - i; j++)
                {
                    String subString = name.Substring(j, i);
                    if (IsValidSubString(subString,n))
                        ++numberOfN;
                }
            }

            return numberOfN;
        }

        public static bool IsValidSubString(String subString, int n)
        {
            int consonants = 0;
            for (int i = 0; i < subString.Length; ++i)
            {
                if (!IsVocal(subString[i]))
                {
                    ++consonants;
                    if (consonants >= n) return true;
                }
                else
                {
                    consonants = 0;
                }
            }

            return false;
        }

        public static bool IsVocal(char c)
        {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        }
    }
}
