using System;
using System.Linq;

namespace C_Minesweeper
{
    public class Field
    {


        private Int32 R { get; set; }

        private Int32 C { get; set; }

        private Int32 M { get; set; }

        private Int32 _id { get; set; }

        private Int32 _totalCampos;

        public String Resultado { get; set; }

        public Char[][] Tabela;


        public Field(Int32 pId, String pLinha)
        {
            var partes = pLinha.Split().Select(pX => Convert.ToInt32(pX)).ToArray();
            R = partes[0];
            C = partes[1];
            M = partes[2];
            _totalCampos = C * R;
            _id = pId;
        }


        public void Processar()
        {
            Resultado = String.Format("Case #{0}:{1}{2}", _id, Environment.NewLine, ProcessarInterno());
        }

        private String ProcessarInterno()
        {
            if (M >= _totalCampos)
                return "Impossible";
            if (M + 1 == _totalCampos)
            {
                CriarTabela();
                Tabela[0][0] = 'c';
                return ImprimirTabela();
            }
            if (C == 1 || R == 1)
            {
                return MontarTabelaUmaLinha();
            }
            if (M + 2 == _totalCampos)
            {
                return "Impossible";
            }
            if (M == 0)
            {
                CriarTabela('.');
                Tabela[0][0] = 'c';
                return ImprimirTabela();
            }
            if (C == 2 || R == 2)
            {
                if ((_totalCampos - M) % 2 == 1)
                    return "Impossible";
            }
            if ((_totalCampos - M) < 9 && (_totalCampos - M) % 2 == 1)
                return "Impossible";
            return MontarTabelaGenerica();
        }

        private string MontarTabelaGenerica()
        {
            CriarTabela();
            Int32 brancos = 4;
            Tabela[0][0] = 'c';
            Tabela[0][1] = '.';
            Tabela[1][0] = '.';
            Tabela[1][1] = '.';
            var totalBrancos = _totalCampos - M;
            var totalPares = totalBrancos;
            if (totalPares % 2 == 1)
                totalPares--;
            var valido = true;
            while (valido && totalPares != brancos) // valido enquanto puder avançar
            {
                valido = false;
                for (int x = 2; x < R; x++) // Avançando na linha
                {
                    if (Tabela[x][0] == '*')
                    {
                        Tabela[x][0] = '.';
                        Tabela[x][1] = '.';
                        valido = true;
                        brancos += 2;
                        break;
                    }
                }
                if (totalPares != brancos)
                {
                    for (int x = 2; x < C; x++) // Avançando na coluna
                    {
                        if (Tabela[0][x] == '*')
                        {
                            Tabela[0][x] = '.';
                            Tabela[1][x] = '.';
                            valido = true;
                            brancos += 2;
                            break;
                        }
                    }
                }
            }

            for (int x = 2; x < R; x++)
            {
                for (int y = 2; y < C; y++)
                {
                    if (brancos == totalBrancos)
                        return ImprimirTabela();
                    Tabela[x][y] = '.';
                    brancos++;
                }
            }

            return ImprimirTabela();
        }

        private string MontarTabelaUmaLinha()
        {
            Int32 brancos = 0;
            CriarTabela();

            var totalBrancos = _totalCampos - M;

            for (int x = 0; x < R; x++)
            {
                for (int y = 0; y < C; y++)
                {
                    Tabela[x][y] = '.';
                    brancos++;
                    if (brancos == totalBrancos)
                        break;
                }
                if (brancos == totalBrancos)
                    break;
            }

            Tabela[0][0] = 'c';
            return ImprimirTabela();
        }

        private void CriarTabela(char pItem = '*')
        {
            Tabela = new char[R][];
            for (int x = 0; x < R; x++)
            {
                Tabela[x] = new char[C];
                for (int y = 0; y < C; y++)
                {
                    Tabela[x][y] = pItem;
                }
            }
        }

        private String ImprimirTabela()
        {
            return String.Join(Environment.NewLine, Tabela.Select(pX => String.Join(String.Empty, pX)));
        }
    }
}
