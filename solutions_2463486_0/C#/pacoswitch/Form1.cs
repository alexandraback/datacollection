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
    static class StringExtensions
    {
        public static string Reverse(this string input)
        {
            char[] charArray = input.ToCharArray();
            Array.Reverse(charArray);
            return new string(charArray);
        }
    }
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
            fairandsquare();
            Cursor.Current = Cursors.Default;
            DateTime termina = System.DateTime.Now;
            TimeSpan diferencia = termina - inicia;
            this.label1.Text = diferencia.TotalSeconds.ToString() + " segundos";
        }
        private void fairandsquare()
        {
            int n = 10000000;
            long x;
            int c = 0;
            List<Tuple<int, long>> sq = new List<Tuple<int, long>>();
            for (int i = 1; i < n; i++)
            {
                string si, sx;
                si = i.ToString();
                if (si == si.Reverse())
                {
                    x = Math.BigMul(i, i);
                    sx = x.ToString();
                    if (sx == sx.Reverse())
                    {
                        sq.Add(new Tuple<int, long>(i, x));
                    }
                }
            }
            int T;
            T = this.readInt();
            for (int k = 0; k < T; k++)
            {
                long a, b;
                a = this.readLong();
                b = this.readLong();
                int contador = 0;
                for (int i = 0; i < sq.Count; i++)
                {
                    if (sq[i].Item2 >= a && sq[i].Item2 <= b)
                        contador++;
                }
                this.writeLine("Case #{0}: {1}", k + 1, contador);
            }
        }
        
    }
}
