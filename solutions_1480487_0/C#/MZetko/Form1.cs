using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace TVShow
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private int T = 0;
        private int N = 0;
        private int[] S = new int[ 250 ];
        private long SSum = 0;
        private int Jmax1, Jmax2 = 0;
        List<string> results = new List<string>();

        private void Solve()
        {
            string sol = "Case #" + ( results.Count + 1 ).ToString() + ":";
            for ( int i = 0; i < N; i++ )
            {
                int max = Jmax1;
                if ( S[ i ] == max )
                    max = Jmax2;
                sol += " " + (( (SSum-S[i]) / (SSum*1.0*(N-1)) )*100).ToString();                
            }
            results.Add( sol );
        }

        private void Form1_Load( object sender, EventArgs e )
        {
            Application.CurrentCulture = new System.Globalization.CultureInfo( "en-US" );
            string[] lines = File.ReadAllLines( "input.in" );
            T = lines.Length - 1;

            for ( int i = 0; i < T; i++ )
            {
                SSum = 0;
                Jmax2 = 0;
                Jmax1 = 0;
                string line = lines[ i + 1 ];
                string[] lineParts = line.Split( ' ' );
                N = lineParts.Length - 1;
                for ( int j = 0; j < N; j++ )
                {
                    S[ j ] = int.Parse( lineParts[ j + 1 ] );
                    SSum += S[ j ];
                    if ( Jmax1 <= S[ j ] )
                    {
                        Jmax2 = Jmax1;
                        Jmax1 = S[ j ];
                    }
                    else
                    {
                        if ( Jmax2 < S[ j] )
                        {
                            Jmax2 = S[ j ];
                        }
                    }
                }
                Solve();
            }
            File.WriteAllLines( "output.out", results.ToArray() );
        }
    }
}
