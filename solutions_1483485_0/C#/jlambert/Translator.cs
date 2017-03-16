using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections;

namespace CodeJamRoundOne
{
    public class Translator
    {
        public static string Translate(string stringToTranslate)
        {
            char[] charArray = stringToTranslate.ToCharArray();
            char[] newCharArray = new char[charArray.Length];
            for(int i = 0; i <charArray.Length;i++)
            {
                newCharArray[i] = translationArray[charArray[i]];
            }
            return new string(newCharArray);
        }

        public static Dictionary<char,char> translationArray = new Dictionary<char,char> 
                                                       {{'y','a'},
                                                        {'n','b'},
                                                        {'f','c'},
                                                        {'i','d'},
                                                        {'c','e'},
                                                        {'w','f'},
                                                        {'l','g'},
                                                        {'b','h'},
                                                        {'k','i'},
                                                        {'u','j'},
                                                        {'o','k'},
                                                        {'m','l'},
                                                        {'x','m'},
                                                        {'s','n'},
                                                        {'e','o'},
                                                        {'v','p'},
                                                        {'z','q'},
                                                        {'p','r'},
                                                        {'d','s'},
                                                        {'r','t'},
                                                        {'j','u'},
                                                        {'g','v'},
                                                        {'t','w'},
                                                        {'h','x'},
                                                        {'a','y'},
                                                        {'q','z'},
                                                        {' ',' '}};

    }
}
