using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace Dijkstra
{
    public class Solucao : CodeJamBase
    {

        public const bool UseMultiThreading = true;
        public const bool UseStandardIO = false;
        public const string InputFile = @"3.in";
        public const string OutputFile = @"3.out";

        public Dictionary<char, Dictionary<char, char>> _matriz;

        public Solucao()
        {
            _matriz = new Dictionary<char, Dictionary<char, char>>();
            _matriz.Add('1', new Dictionary<char, char>
            {
                {'1', '1'},
                {'i', 'i'},
                {'j', 'j'},
                {'k', 'k'},
                {'a', 'a'},
                {'b', 'b'},
                {'c', 'c'},
                {'d', 'd'}
            });
            _matriz.Add('i', new Dictionary<char, char>
            {
                {'1', 'i'},
                {'i', 'a'},
                {'j', 'k'},
                {'k', 'c'},
                {'a', 'b'},
                {'b', '1'},
                {'c', 'd'},
                {'d', 'j'}
            });
            _matriz.Add('j', new Dictionary<char, char>
            {
                {'1', 'j'},
                {'i', 'd'},
                {'j', 'a'},
                {'k', 'i'},
                {'a', 'c'},
                {'b', 'k'},
                {'c', '1'},
                {'d', 'b'}
            });
            _matriz.Add('k', new Dictionary<char, char>
            {
                {'1', 'k'},
                {'i', 'j'},
                {'j', 'b'},
                {'k', 'a'},
                {'a', 'd'},
                {'b', 'c'},
                {'c', 'i'},
                {'d', '1'}
            });


            _matriz.Add('a', new Dictionary<char, char>
            {
                {'1', 'a'},
                {'i', 'b'},
                {'j', 'c'},
                {'k', 'd'},
                {'a', '1'},
                {'b', 'i'},
                {'c', 'j'},
                {'d', 'k'}
            });
            _matriz.Add('b', new Dictionary<char, char>
            {
                {'1', 'b'},
                {'i', '1'},
                {'j', 'd'},
                {'k', 'j'},
                {'a', 'i'},
                {'b', 'a'},
                {'c', 'k'},
                {'d', 'c'}
            });
            _matriz.Add('c', new Dictionary<char, char>
            {
                {'1', 'c'},
                {'i', 'k'},
                {'j', '1'},
                {'k', 'b'},
                {'a', 'j'},
                {'b', 'd'},
                {'c', 'a'},
                {'d', 'i'}
            });
            _matriz.Add('d', new Dictionary<char, char>
            {
                {'1', 'd'},
                {'i', 'c'},
                {'j', 'i'},
                {'k', '1'},
                {'a', 'k'},
                {'b', 'j'},
                {'c', 'b'},
                {'d', 'a'}
            });

        }

        private String _cadeia;
        private Int32 _qtd;
        private Boolean _resultado;



        public override void LerDados()
        {
            var numeros = ProximoInteiros();
            _qtd = numeros[1];
            _cadeia = ProximaLinha();
        }

        public override void Resolver()
        {
            if (_cadeia.Length * _qtd < 3)
                return;
            if (_cadeia.Distinct().Count() == 1)
                return;
            var total = Total();
            if (total != 'a')
                return;
            _resultado =  ResolverInterno(0, 0, 1);
        }

        public char Total()
        {
            Boolean inicio = true;
            var atual = '1';
            for (Int32 x = 0; x < _qtd; x++)
            {
                for (int y = 0; y < _cadeia.Length; y++)
                {
                    if (inicio)
                    {
                        atual = _cadeia[y];
                        inicio = false;
                    }
                    else
                    {
                        atual = _matriz[atual][_cadeia[y]];
                    }
                }
            }
            return atual;
        }

        public Boolean ResolverInterno(Int32 pX, Int32 pY, Int32 pNivel)
        {
            Boolean inicio = true;
            var atual = '1';
            if (pY == _cadeia.Length)
            {
                pY = 0;
                pX++;
            }
            for (Int32 x = 0; x < _qtd; x++)
            {
                for (int y = 0; y < _cadeia.Length; y++)
                {
                    if (inicio)
                    {
                        x = pX;
                        y = pY;
                        atual = _cadeia[y];
                        inicio = false;
                    }
                    else
                    {
                        atual = _matriz[atual][_cadeia[y]];
                    }

                    switch (pNivel)
                    {
                        case 1:
                            if (atual == 'i' && ResolverInterno(x, y + 1, pNivel + 1))
                                    return true;
                            break;
                        case 2:
                            if (atual == 'j')
                                return true;
                            break;

                    }
                }
            }
            return false;
        }


        public override void EscreverResposta()
        {
            Out.WriteLine(_resultado ? "YES" : "NO");

        }
    }
}
