#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<set>
#include <utility>

using namespace std;

#define inf         freopen("in.txt", "r", stdin);
#define outf        freopen("out.txt", "w", stdout);
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define mn          (long long)-9223372036854775807
#define mx          (long long) 9223372036854775807
#define mod          1000000009
#define LL           long long


//set<int>::iterator ii;



int main()
{
    ios::sync_with_stdio(false);

    inf;
    outf;

    int t, ca = 1;

    cin >> t;

    while( t-- )
    {
        int i, j, x, y, nn, m, arr[11111] = {0};

        string str;
        cin >> str;
        nn = str.size();
        cout << "Case #" << ca++ <<": " ;
        //cout << str << endl;
        for( i=0; i<nn; i++ )
        {
            x = str[i];
            arr[x]++;
        }


        while( true )
    {
       int z = 'Z', e = 'E', r = 'R', o = 'O', f = 'F';

       if( arr[z] == 0 || arr[e] == 0 || arr [r] == 0 || arr[o] == 0 )
        break;


       cout << 0;
       arr[z]--;  arr[e]--;  arr [r]--;  arr[o]--;

    }
        while( true )
    {
       int e = 'E', n = 'N', o = 'O' , f = 'U', w = 'W';

       if(  arr[e] == 0 || arr [n] == 0 || arr[o] == 0 )
        break;
       if( arr[o] == arr[f] )
        break;
       if( arr[o] == arr[w] )
        break;
       if( arr[o] == arr[w]+arr[f] )
        break;
       cout << 1;
       arr[e]--;  arr[n]--;  arr[o]--;

    }
        while( true )
    {
       int t = 'T', w = 'W', o = 'O';

       if(  arr[t] == 0 || arr [w] == 0 || arr[o] == 0 )
        break;

       cout << 2;
       arr[t]--;  arr[w]--;  arr[o]--;

    }

        while( true )
   {
       int z = 'T', e = 'H', r = 'R', o = 'E', cc = 'O';

       if( arr[z] == 0 || arr[e] == 0 || arr [r] == 0 || arr[o] <= 1 )
        break;
       if( arr[r] == arr[cc] )
        break;
       cout << 3;
       arr[z]--;  arr[e]--;  arr [r]--;  arr[o]--;

   }
        while( true )
   {
       int z = 'F', e = 'O', r = 'U', o = 'R';

       if( arr[z] == 0 || arr[e] == 0 || arr [r] == 0 || arr[o] == 0 )
        break;

       cout << 4;
       arr[z]--;  arr[e]--;  arr [r]--;  arr[o]--;

   }
        while( true )
   {
       int z = 'F', e = 'I', r = 'V', o = 'E';

       if( arr[z] == 0 || arr[e] == 0 || arr [r] == 0 || arr[o] == 0 )
        break;

       cout << 5;
       arr[z]--;  arr[e]--;  arr [r]--;  arr[o]--;

   }
        while( true )
   {
       int e = 'S', n = 'I', o = 'X';

       if(  arr[e] == 0 || arr [n] == 0 || arr[o] == 0 )
        break;

       cout << 6;
       arr[e]--;  arr[n]--;  arr[o]--;

   }
   while( true )
   {
       int z = 'S', e = 'E', r = 'V', o = 'N';

       if( arr[z] == 0 || arr[e] <= 1 || arr [r] == 0 || arr[o] == 0 )
        break;

       cout << 7;
       arr[z]--;  arr[e]--;  arr [r]--;  arr[o]--;

   }
   while( true )
   {
       int z = 'E', e = 'I', r = 'G', o = 'H', t = 'T';

       if( arr[z] == 0 || arr[e] == 0 || arr [r] == 0 || arr[o] == 0 || arr[t] == 0 )
        break;

       cout << 8;
       arr[z]--;  arr[e]--;  arr [r]--;  arr[o]--, arr[t]--;

   }
   while( true )
   {
       int t = 'N', w = 'I', o = 'E';

       if(  arr[t] <= 1 || arr [w] == 0 || arr[o] == 0 )
        break;

       cout << 9;
       arr[t]--;  arr[w]--;  arr[o]--;

   }

   cout << endl;

    }







    return 0;

}


//"ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"
