using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Text;

namespace C_CoinJam
{
    public class ConvertBase
    {


        public static BigInteger ObterNumeroDecimal(string pNumero, int pBase)
        {
            BigInteger resultado = 0;
            
            for (int x = 0;  x < pNumero.Length; x++)
            {
                resultado += BigInteger.Pow(pBase, x) * BigInteger.Parse(pNumero.Substring(pNumero.Length - x - 1, 1));
            }
            return resultado;
        }

        public static string ToBinaryString(BigInteger pNumero)
        {
            var bytes = pNumero.ToByteArray();
            var idx = bytes.Length - 1;
            var base2 = new StringBuilder(bytes.Length * 8);
            var binary = Convert.ToString(bytes[idx], 2);
            if (binary[0] != '0' && pNumero.Sign == 1)
                base2.Append('0');
            base2.Append(binary);
            for (idx--; idx >= 0; idx--)
                base2.Append(Convert.ToString(bytes[idx], 2).PadLeft(8, '0'));
            while (base2[0] == '0')
                base2.Remove(0, 1);
            return base2.ToString();
        }
    }
}
