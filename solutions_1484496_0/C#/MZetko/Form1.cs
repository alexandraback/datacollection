using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Sums
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        int T = 0;
        int N = 0;

        List<Tuple<long, long>> FoundSums = new List<Tuple<long, long>>();
        long[] S = new long[ 200 ];
        List<string> results = new List<string>();
        
        private void Solve()
        {
            FoundSums.Clear();
            for ( int i = 0; i < 1048575; i++ )
            {
                long sum = 0;
                string bin = Convert.ToString( i, 2 );
                while ( bin.Length < 20 )
                {
                    bin = "0" + bin;
                }
                for ( int j = 0; j < 20; j++ )
                {
                    sum += bin[ j ] == '1' ? S[ j ] : 0;
                }
                FoundSums.Add( new Tuple<long, long>( sum, i ) );
            }
            FoundSums.Sort( new Comparerr() );
            int icko = 0;
            for ( int i = 1; i < FoundSums.Count; i++ )
            {
                if ( FoundSums[ i - 1 ].Item1 == FoundSums[ i ].Item1 )
                {
                    icko = i;
                    break;
                }
            }
            if ( icko != 0 )
            {
                string bin1 = Convert.ToString( FoundSums[ icko - 1 ].Item2, 2 );
                while ( bin1.Length < 20 )
                {
                    bin1 = "0" + bin1;
                }
                string line = "";
                for ( int i = 0; i < 20; i++ )
                {
                    if ( bin1[ i ] == '1' )
                    {
                        line = line + S[ i ] + " ";
                    }
                }
                results.Add( line.Trim() );
                bin1 = Convert.ToString( FoundSums[ icko ].Item2, 2 );
                while ( bin1.Length < 20 )
                {
                    bin1 = "0" + bin1;
                }
                line = "";
                for ( int i = 0; i < 20; i++ )
                {
                    if ( bin1[ i ] == '1' )
                    {
                        line = line + S[ i ] + " ";
                    }
                }
                results.Add( line.Trim() );
            }
            else
            {
                results.Add( "Impossible" );
            }
        }

        private class Comparerr : Comparer<Tuple<long, long>>
        {

            public override int Compare( Tuple<long, long> x, Tuple<long, long> y )
            {
                return x.Item1.CompareTo( y.Item1 );
            }
        }

        private void Form1_Load( object sender, EventArgs e )
        {
            string[] lines = File.ReadAllLines( "input.in" );
            T = lines.Length - 1;
            for ( int i = 0; i < T; i++ )
            {
                string test = lines[ i + 1 ];
                string[] nums = test.Split();
                N = nums.Length - 1;
                for ( int j = 0; j < N; j++ )
                {
                    S[ j ] = int.Parse( nums[ j + 1 ] );
                }
                results.Add( "Case #" + ( i + 1 ) + ":" );
                Solve();
            }
            File.WriteAllLines( "output.out", results.ToArray() );
        }
    }
}
