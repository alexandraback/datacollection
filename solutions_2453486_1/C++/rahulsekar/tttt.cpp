#include<iostream>
#include<string>
#include<vector>
using namespace std;

int check_rows( vector<string> s, string ch )
{
    vector<string> comp;
    comp.push_back( ch + ch + ch + ch );
    comp.push_back( ch + ch + ch + "T" );
    comp.push_back( ch + ch + "T" + ch );
    comp.push_back( ch + "T" + ch + ch );    
    comp.push_back( "T" + ch + ch + ch );    
        
    int sz = s.size();
    for( int i =0 ; i < sz; ++i )
         for( int j = 0; j < 5; ++j )
              if( s[i] == comp[j] )
                  return ( 1 );
    return( 0 );                  
};
vector<string> transpose( vector<string> s )
{
               for( int i =0 ; i < 4; ++i )
         for( int j = i+1; j < 4; ++j )
         {
              char t = s[i][j];
              s[i][j] = s[j][i];
              s[j][i] = t;
         }         
   return s;
};
int check( vector<string> s, string ch )
{
    if( check_rows( s, ch ) ) return 1;
    if( check_rows( transpose( s ), ch ) ) return 1;
    vector<string> diag;
    diag.push_back( string( 1, s[0][0] ) + string( 1, s[1][1] ) + string( 1, s[2][2] ) + string( 1, s[3][3] ) );
    diag.push_back( string( 1, s[3][0] ) + string( 1, s[2][1] ) + string( 1, s[1][2] ) + string( 1, s[0][3] ) );
//    cout<<"\n" << diag[0] << " " << diag[1] << endl;
    if( check_rows( diag, ch ) ) return 1;
    return 0;
}
int main()
{
 int n;
    cin>>n;
    int t =1;
    while( t<=n )
    {
           vector<string> s;
           string tt;
           cin>>tt;
           s.push_back(tt);
           cin>>tt;
           s.push_back(tt);
           cin>>tt;
           s.push_back(tt);
           cin>>tt;
           s.push_back(tt);
           cout<<"Case #" << t << ": ";
           if( check(s, "X" ) ) cout<< "X won\n";
           else if( check( s, "O" ) ) cout<< "O won\n";
           else
           {
           int i;
           for( i = 0; i < 4; ++i )
           for( int j = 0; j < 4; ++j )
                if( s[i][j] == '.' )
                           cout<< "Game has not completed\n", i =100,j=100;
           if( i !=101 )
           cout<<"Draw\n";
           }
           t++;
           
    }
    return 0;
}
