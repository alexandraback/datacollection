using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Diamonds
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        int T = 0;
        int N = 0;
        int[,] M = new int[ 1100, 1100 ];
        bool[] Divisors = new bool[1100];
        bool[] Visited = new bool[ 1100 ];

        List<string> Results = new List<string>();
        bool found = false;
        private void Visit( int i )
        {
            if ( !Visited[ i ] )
            {
                Visited[ i ] = true;
                for ( int j = 0; j < M[ i, 0 ] && ( !found ); j++ )
                {
                    Visit( M[ i, j + 1 ] );
                }
            }
            else
            {
                found = true;
            }
        }


        private void Cleanup()
        {
            for ( int i = 0; i < N; i++ )
            {
                Visited[ i ] = false;
            }
        }

        private bool Solve()
        {
            found = false;
            for ( int i = 0; i < N && (!found); i++ )
            {
                if ( Divisors[ i ] )
                {
                    Cleanup();
                    for ( int j = 0; j < M[ i, 0 ] && ( !found ); j++ )
                    {
                        Visit( M[ i, j + 1 ] );
                    }
                }
            }
            return found;
        }

        private void Form1_Load( object sender, EventArgs e )
        {
            string[] lines = File.ReadAllLines( "input.in" );
            for ( int i = 0; i < M.GetLength(0); i++ )
            {
                for ( int j = 0; j < M.GetLength(1); j++ )
                {
                    M[ i, j ] = 0;
                }
                Divisors[ i ] = false;
            }
            T = int.Parse( lines[ 0 ] );
            int lineId = 0;
            for ( int ti = 0; ti < T; ti++ )
            {
                lineId++;
                N = int.Parse( lines[ lineId ] );
                for ( int ni = 0; ni < N; ni++ )
                {
                    lineId++;
                    string[] parts = lines[ lineId ].Split( ' ' );
                    M[ ni, 0 ] = int.Parse( parts[ 0 ] );                        
                    for ( int j = 1; j < parts.Length; j++ )
                    {
                        M[ ni, j ] = int.Parse( parts[ j ] )-1;                        
                    }
                    if ( parts.Length > 2 )
                    {
                        Divisors[ ni ] = true;
                    }
                    else
                    {
                        Divisors[ ni ] = false;
                    }
                }
                if ( Solve() )
                {
                    Results.Add( "Case #" + ( ti + 1 ) + ": Yes" );
                }
                else
                {
                    Results.Add( "Case #" + ( ti + 1 ) + ": No" );                    
                }
            }
            File.WriteAllLines( "output.out", Results.ToArray() );
        }
    }
}
