using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace P_C
{
    public class Multiplicative
    {
        private Dictionary<string, _.SymbolEnum> symbolDictionary;
        private Dictionary<string, int> signDictionary;
        public Multiplicative()
        {
            symbolDictionary = new Dictionary<string, _.SymbolEnum>();
            signDictionary = new Dictionary<string, int>();

            symbolDictionary.Add("oo", _.SymbolEnum.o);
            symbolDictionary.Add("oi", _.SymbolEnum.i);
            symbolDictionary.Add("oj", _.SymbolEnum.j);
            symbolDictionary.Add("ok", _.SymbolEnum.k);

            symbolDictionary.Add("io", _.SymbolEnum.i);
            symbolDictionary.Add("ii", _.SymbolEnum.o);
            symbolDictionary.Add("ij", _.SymbolEnum.k);
            symbolDictionary.Add("ik", _.SymbolEnum.j);

            symbolDictionary.Add("jo", _.SymbolEnum.j);
            symbolDictionary.Add("ji", _.SymbolEnum.k);
            symbolDictionary.Add("jj", _.SymbolEnum.o);
            symbolDictionary.Add("jk", _.SymbolEnum.i);

            symbolDictionary.Add("ko", _.SymbolEnum.k);
            symbolDictionary.Add("ki", _.SymbolEnum.j);
            symbolDictionary.Add("kj", _.SymbolEnum.i);
            symbolDictionary.Add("kk", _.SymbolEnum.o);


            signDictionary.Add("oo", 1);
            signDictionary.Add("oi", 1);
            signDictionary.Add("oj", 1);
            signDictionary.Add("ok", 1);
                                     
            signDictionary.Add("io", 1);
            signDictionary.Add("ii", -1);
            signDictionary.Add("ij", 1);
            signDictionary.Add("ik", -1);
                                     
            signDictionary.Add("jo", 1);
            signDictionary.Add("ji", -1);
            signDictionary.Add("jj", -1);
            signDictionary.Add("jk", 1);
                                     
            signDictionary.Add("ko", 1);
            signDictionary.Add("ki", 1);
            signDictionary.Add("kj", -1);
            signDictionary.Add("kk", -1);
        }
        public Quaternion multiply(Quaternion quaternion1, Quaternion quaternion2)
        {
            Quaternion resultQuaternion = new Quaternion();
            var key = string.Format("{0}{1}", quaternion1.symbol.ToString(), quaternion2.symbol.ToString());
           
            resultQuaternion.sign = quaternion1.sign * quaternion2.sign * signDictionary[key];
            resultQuaternion.symbol = symbolDictionary[key];

            return resultQuaternion;
        }

    }
}
