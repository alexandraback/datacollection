using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Boxes
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        long T = 0;
        long N, M = 0;
        ToyBox[] Line1 = new ToyBox[110];
        ToyBox[] Line2 = new ToyBox[ 110 ];
        TotalsSums[] toyOne, toyTwo, toyThree = null;

        List<string> Result = new List<string>();

        private void Solve( long ti )
        {
            for ( long i = 0; i < M; i++ )
            {
                if ( i != 0 )
                {
                    toyOne[ i ] = toyOne[ i - 1 ];
                    toyThree[ i ] = toyThree[ i - 1 ];
                    toyTwo[ i ] = toyTwo[ i - 1 ];
                    if ( Line2[ i ].Id == Line1[ 0 ].Id )
                    {
                        //first toy on the line
                        long added = Math.Min( toyOne[ i ].Left, Line2[ i ].Count );
                        Line2[ i ].Count -= added;
                        toyOne[ i ].Left = toyOne[ i ].Left - added;
                        toyOne[ i ].Total = toyOne[ i ].Total + added;
                    }
                    if ( toyTwo[ i ].Total < toyOne[ i ].Total )
                    {
                        toyTwo[ i ].Total = toyOne[ i ].Total;
                        toyTwo[ i ].Left = Line1[ 1 ].Count;
                    }
                    if ( toyThree[ i ].Total < toyTwo[ i ].Total )
                    {
                        toyThree[ i ].Total = toyTwo[ i ].Total;
                        toyThree[ i ].Left = Line1[ 2 ].Count;
                    }
                    if ( Line2[ i ].Id == Line1[ 1 ].Id )
                    {
                        long added = Math.Min( toyTwo[ i ].Left, Line2[ i ].Count );
                        Line2[ i ].Count -= added;
                        toyTwo[ i ].Left = toyTwo[ i ].Left - added;
                        toyTwo[ i ].Total = toyTwo[ i ].Total + added;                        
                    }
                    if ( toyTwo[ i ].Total < toyOne[ i ].Total )
                    {
                        toyTwo[ i ].Total = toyOne[ i ].Total;
                        toyTwo[ i ].Left = Line1[ 1 ].Count;
                    }
                    if ( toyThree[ i ].Total < toyTwo[ i ].Total )
                    {
                        toyThree[ i ].Total = toyTwo[ i ].Total;
                        toyThree[ i ].Left = Line1[ 2 ].Count;
                    }
                    if ( Line2[ i ].Id == Line1[ 2 ].Id )
                    {
                        long added = Math.Min( toyThree[ i ].Left, Line2[ i ].Count );
                        Line2[ i ].Count -= added;
                        toyThree[ i ].Left = toyThree[ i ].Left - added;
                        toyThree[ i ].Total = toyThree[ i ].Total + added;                    
                    }
                    if ( toyTwo[ i ].Total < toyOne[ i ].Total )
                    {
                        toyTwo[ i ].Total = toyOne[ i ].Total;
                        toyTwo[ i ].Left = Line1[ 1 ].Count;
                    }
                    if ( toyThree[ i ].Total < toyTwo[ i ].Total )
                    {
                        toyThree[ i ].Total = toyTwo[ i ].Total;
                        toyThree[ i ].Left = Line1[ 2 ].Count;
                    }
                }
                else
                {
                    if ( Line2[ i ].Id == Line1[ 0 ].Id )
                    {
                        //first toy on the line
                        long added = Math.Min( toyOne[ 0 ].Left, Line2[ 0 ].Count );
                        Line2[ i ].Count -= added;
                        toyOne[ 0 ].Left = toyOne[ 0 ].Left - added;
                        toyOne[ 0 ].Total = added;
                    }
                    if ( toyTwo[ i ].Total < toyOne[ i ].Total )
                    {
                        toyTwo[ i ].Total = toyOne[ i ].Total;
                        toyTwo[ i ].Left = Line1[ 1 ].Count;
                    }
                    if ( toyThree[ i ].Total < toyTwo[ i ].Total )
                    {
                        toyThree[ i ].Total = toyTwo[ i ].Total;
                        toyThree[ i ].Left = Line1[ 2 ].Count;
                    }
                    if ( Line2[ i ].Id == Line1[ 1 ].Id )
                    {
                        long added = Math.Min( toyTwo[ 0 ].Left, Line2[ 0 ].Count );
                        Line2[ i ].Count -= added;
                        toyTwo[ 0 ].Left = toyTwo[ 0 ].Left - added;
                        toyTwo[ 0 ].Total = added;
                    }
                    if ( toyTwo[ i ].Total < toyOne[ i ].Total )
                    {
                        toyTwo[ i ].Total = toyOne[ i ].Total;
                        toyTwo[ i ].Left = Line1[ 1 ].Count;
                    }
                    if ( toyThree[ i ].Total < toyTwo[ i ].Total )
                    {
                        toyThree[ i ].Total = toyTwo[ i ].Total;
                        toyThree[ i ].Left = Line1[ 2 ].Count;
                    }
                    if ( Line2[ i ].Id == Line1[ 2 ].Id )
                    {
                        long added = Math.Min( toyThree[ i ].Left, Line2[ i ].Count );
                        Line2[ i ].Count -= added;
                        toyThree[ 0 ].Left = toyThree[ 0 ].Left - added;
                        toyThree[ 0 ].Total = added;
                    }
                    if ( toyTwo[ i ].Total < toyOne[ i ].Total )
                    {
                        toyTwo[ i ].Total = toyOne[ i ].Total;
                        toyTwo[ i ].Left = Line1[ 1 ].Count;
                    }
                    if ( toyThree[ i ].Total < toyTwo[ i ].Total )
                    {
                        toyThree[ i ].Total = toyTwo[ i ].Total;
                        toyThree[ i ].Left = Line1[ 2 ].Count;
                    }
                }
            }
            long max = Math.Max( Math.Max( toyTwo[ M - 1 ].Total, toyThree[ M - 1 ].Total ), toyOne[ M - 1 ].Total );
            Result.Add( "Case #" + ( ti + 1 ) + ": " + max );
        }

        private void Form1_Load( object sender, EventArgs e )
        {
            string[] lines = File.ReadAllLines( "input.in" );
            T = long.Parse( lines[ 0 ] );
            long lineId = 0;
            for ( long ti = 0; ti < T; ti++ )
            {
                lineId++;
                string[] numThings = lines[ lineId ].Split( ' ' );
                N = long.Parse( numThings[ 0 ] );
                M = long.Parse( numThings[ 1 ] );
                lineId++;
                string[] firstLine = lines[ lineId ].Split( ' ' );
                for ( long i = 0; i < N; i++ )
                {
                    Line1[ i ].Count = long.Parse( firstLine[ i * 2 ] );
                    Line1[ i ].Id = long.Parse( firstLine[ i * 2 + 1 ] );
                }
                if ( N == 1 )
                {
                    Line1[ 1 ].Count = 0;
                    Line1[ 1 ].Id = 110;
                    Line1[ 2 ].Count = 0;
                    Line1[ 2 ].Id = 110;
                }
                if ( N == 2 )
                {
                    Line1[ 2 ].Count = 0;
                    Line1[ 2 ].Id = 110;
                }
                lineId++;
                string[] secondLine = lines[ lineId ].Split( ' ' );
                for ( long i = 0; i < M; i++ )
                {
                    Line2[ i ].Count = long.Parse( secondLine[ i * 2 ] );
                    Line2[ i ].Id = long.Parse( secondLine[ i * 2 + 1 ] );
                }
                toyOne = new TotalsSums[ 110 ];
                toyOne[ 0 ].Total = 0;
                toyOne[ 0 ].Left = Line1[ 0 ].Count;
                toyThree = new TotalsSums[ 110 ];
                toyThree[ 0 ].Total = 0;
                toyThree[ 0 ].Left = Line1[ 2 ].Count;
                toyTwo = new TotalsSums[ 110 ];
                toyTwo[ 0 ].Total = 0;
                toyTwo[ 0 ].Left = Line1[ 1 ].Count;
                Solve( ti );
            }
            File.WriteAllLines( "output.out", Result.ToArray() );
        }
    }

    public struct ToyBox
    {
        public long Id;
        public long Count;
    }

    public struct TotalsSums
    {
        public long Left;
        public long Total;
    }
}
