using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

using System.Text.RegularExpressions;

namespace ContestBase
{
    public partial class Form1 : Form
    {
        public string[] partes;
        public string[] renglones;
        public int indice;
        public int indicerenglon;
        public Tuple<int, int>[] rangos;
        public Form1()
        {
            InitializeComponent();
        }
        //Con estas funciones leeremos de la entrada
        public void write(string format, params Object[] args)
        {
            this.toutput.AppendText(String.Format(format, args));
        }
        public void writeLine(string format, params Object[] args)
        {
            this.toutput.AppendText(String.Format(format, args));
            this.toutput.AppendText(Environment.NewLine);
        }
        public int readInt()
        {
            if (indice > rangos[indicerenglon].Item2)
                indicerenglon++;
            return int.Parse(this.partes[this.indice++]);
        }
        public long readLong()
        {
            if (indice > rangos[indicerenglon].Item2)
                indicerenglon++;
            return long.Parse(this.partes[this.indice++]);
        }
        public double readDouble()
        {
            if (indice > rangos[indicerenglon].Item2)
                indicerenglon++;
            return double.Parse(this.partes[this.indice++]);
        }
        public string readString()
        {
            if (indice > rangos[indicerenglon].Item2)
                indicerenglon++;
            return this.partes[this.indice++];
        }
        public string readRow()
        {
            indice = this.rangos[(indicerenglon+1)%this.rangos.Length].Item1;
            return this.renglones[this.indicerenglon++];
        }
        public void init()
        {
            this.toutput.Clear();
            this.renglones = this.tinput.Text.Split(new string[] { char.ConvertFromUtf32(13), char.ConvertFromUtf32(10) }, System.StringSplitOptions.RemoveEmptyEntries);
            this.partes = this.tinput.Text.Split(new string[] { " ", char.ConvertFromUtf32(13), char.ConvertFromUtf32(10) }, System.StringSplitOptions.RemoveEmptyEntries);
            this.rangos = new Tuple<int, int>[this.renglones.Length];
            int count = 0;
            for (int i = 0; i < this.renglones.Length; i++)
            {
                string[] _r = this.renglones[i].Split(new string[] { " ", char.ConvertFromUtf32(13), char.ConvertFromUtf32(10) }, System.StringSplitOptions.RemoveEmptyEntries);
                int originalcount = count;
                for (int j = 0; j < _r.Length; j++)
                {
                    count++;
                }
                this.rangos[i] = new Tuple<int, int>(originalcount, count - 1);
            }
            this.indice = 0;
            this.indicerenglon = 0;
        }
        private void buttongenera_Click(object sender, EventArgs e)
        {
            DateTime inicia = System.DateTime.Now;
            Cursor.Current = Cursors.WaitCursor;
            init();
            Lawnmower();
            Cursor.Current = Cursors.Default;
            DateTime termina = System.DateTime.Now;
            TimeSpan diferencia = termina - inicia;
            this.label1.Text = diferencia.TotalSeconds.ToString() + " segundos";
        }
        private void Lawnmower()
        {
            int T, N, M;
            T = this.readInt();
            for (int k = 0; k < T; k++)
            {
                N = this.readInt();
                M = this.readInt();
                
                int[] maximosN = new int[N];
                int[] maximosM = new int[M];
                int[,] jardin = new int[N, M];
                bool[,] dp = new bool[N, M];
                for (int i = 0; i < N; i++)
                {
                    for (int j = 0; j < M; j++)
                    {
                        jardin[i, j] = this.readInt();
                        dp[i, j] = false; 
                    }
                }
                /*if (N < 3 || M < 3)
                {
                    this.writeLine("Case #{0}: {1}", k + 1, "YES");
                    continue;
                }*/
                //vamos a leer de izquierda a derecha y de derecha a izquierda
                for (int i = 0; i < N; i++)
                {
                    //Tomamos la medida del primer metro cuadrado y empezamos a cortar el pasto
                    int medida = jardin[i, 0];
                    bool procesar = true;
                    for (int j = 0; j < M; j++)
                    { if (jardin[i, j] > medida) { procesar = false; break; } }
                    if (procesar)
                    {
                        for (int j = 0; j < M; j++)
                        {
                            //Si el metro cuadrado que cortamos es de la medida marcamos que ya esta cortado
                            dp[i, j] |= (jardin[i, j] == medida);
                            
                        }
                    }
                    medida = jardin[i, M-1];
                    procesar = true;
                    for (int j = M-1; j >= 0; j--)
                    { if (jardin[i, j] > medida) { procesar = false; break; } }
                    if (procesar)
                    {
                        for (int j = M - 1; j >= 0; j--)
                        {
                            //Si el metro cuadrado que cortamos es de la medida marcamos que ya esta cortado
                            dp[i, j] |= (jardin[i, j] == medida);
                            
                        }
                    }
                }
                //vamos a leer de arriba a abajo y de abajo a arriba
                for (int j = 0; j < M; j++)
                {
                    //Tomamos la medida del primer metro cuadrado y empezamos a cortar el pasto
                    int medida = jardin[0, j];
                    bool procesar = true;
                    for (int i = 0; i < N; i++)
                    { if (jardin[i, j] > medida) { procesar = false; break; } }
                    if (procesar)
                    {
                        for (int i = 0; i < N; i++)
                        {
                            //Si el metro cuadrado que cortamos es de la medida marcamos que ya esta cortado
                            dp[i, j] |= (jardin[i, j] == medida);
                            
                        }
                    }
                    procesar = true;
                    medida = jardin[N - 1, j];
                    for (int i = N - 1; i >= 0; i--)
                    { if (jardin[i, j] > medida) { procesar = false; break; } }
                    if (procesar)
                    {
                        for (int i = N - 1; i >= 0; i--)
                        {
                            //Si el metro cuadrado que cortamos es de la medida marcamos que ya esta cortado
                            dp[i, j] |= (jardin[i, j] == medida);
                            
                        }
                    }
                }
                bool sepuede = true;
                for (int i = 0; i < N; i++)
                {
                    for (int j = 0; j < M; j++)
                    {
                        if (!dp[i, j])
                        {
                            bool vertical = true;
                            bool horizontal = true;
                            //cuando este apagado calculamos si podemos pasar la maquina con esa altura horizontalmente y verticalmente
                            for (int c = 0; c < M; c++)
                            {
                                if (jardin[i, c] > jardin[i, j])
                                    horizontal = false;
                            }
                            for (int c = 0; c < N; c++)
                            {
                                if (jardin[c, j] > jardin[i, j])
                                    vertical = false;
                            }
                            sepuede = horizontal || vertical;
                            if (!sepuede)
                            {
                                i = N;
                                j = M;
                                break;
                            }
                        }
                    }
                }
                if (sepuede)
                    this.writeLine("Case #{0}: {1}", k + 1, "YES");
                else
                    this.writeLine("Case #{0}: {1}", k + 1, "NO");
            }
        }
        
    }
}
