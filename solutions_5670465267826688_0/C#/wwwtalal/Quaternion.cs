using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace P_C
{
    public class Quaternion
    {
        public int sign;
        public _.SymbolEnum symbol;

        public Quaternion()
        {
            
        }

        public Quaternion(int sign, string symbolStr)
        {
            this.sign = sign;
            switch (symbolStr)
            {
                case "o":
                    this.symbol = _.SymbolEnum.o;
                    break;
                case "i":
                    this.symbol = _.SymbolEnum.i;
                    break;
                case "j":
                    this.symbol = _.SymbolEnum.j;
                    break;
                case "k":
                    this.symbol = _.SymbolEnum.k;
                    break;
                default:
                    throw new Exception("Not a proper symbol");
                    break;
            }
        }
        public Quaternion(int sign, _.SymbolEnum symbol)
        {
            this.sign = sign;
            this.symbol = symbol;
        }
        /*
        public Quaternion multiply(Quaternion secondQuaternion)
        {
            var outPutSign = this.sign*secondQuaternion.sign;
            Quaternion outputQuaternion;
            switch (symbol)
            {
                    
            }
        }*/
    }

}
