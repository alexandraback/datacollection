#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>

using namespace std;


int main()
{
    int n_cases;
    cin >> n_cases;

    for (int cno=0; cno < n_cases; cno++)
    {
         cout << "Case #" << cno+1 << ": ";
        long b,m;
        cin >> b >> m;

        vector<long> ctr;
        long total=1;



        for ( long i=1; i < b-1; ++i)
        {
            long diff = m-total;
            long extra = diff < total ? diff : total;
            total +=extra;
            ctr.push_back( extra > 0 ? 2*extra-1 : 0);
            auto s = bitset< 64 >( extra).to_string();


            //cout << s << endl;
        }

         //ctr.push_back(2*total-1);
        //ctr.push_back( (2<<2)-1);

        //reverse( ctr.begin(), ctr.end());
       if (total < m)
       {
           cout << "IMPOSSIBLE\n";
       }
       else
       {
           cout << "POSSIBLE\n";
           cout << "0" + string(b-1, '1') << endl;
            for (long val : ctr)
            {
                auto s = bitset<64>( val).to_string().substr( 64 - b );
                //reverse( s.begin(), s.end());

                cout << s << endl;
            }
            cout << string(b, '0') << endl;
       }


    }
}