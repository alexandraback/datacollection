using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace B_Cookies
{
    public class TestCase
    {
        public TestCase(Int32 pId, String linha)
        {
            var partes = linha.Split().Select(pX => Convert.ToDouble(pX, _cultura)).ToArray();
            C = partes[0];
            F = partes[1];
            X = partes[2];
            _id = pId;
        }

        private Double C, F, X;
        private Int32 _id;

        private static CultureInfo _cultura = CultureInfo.GetCultureInfo("en-US");

        public void Processar()
        {
            Resultado = String.Format("Case #{0}: {1}", _id, ProcessarInterno()); ;
        }

        public String ProcessarInterno()
        {
            Int32 fazendasLimite;
            if (Math.Abs(F) < 0.0000000001 || Math.Abs(C) < 0.0000000001)
                fazendasLimite = 0;
            else
            {
                fazendasLimite = Convert.ToInt32(Math.Floor(((F * X) - (2 * C)) / (F * C)));
                fazendasLimite = fazendasLimite < 0 ? 0 : fazendasLimite;
            }

            Double total = 0d;

            for (int y = 0; y < fazendasLimite; y++)
            {
                total += C / (2 + y * F);
            }
            total += X / (2 + fazendasLimite * F);
            return total.ToString("0.0000000", _cultura);
        }

        public String Resultado { get; set; }
    }
}
