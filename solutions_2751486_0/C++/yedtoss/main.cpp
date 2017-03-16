#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <iomanip>
#include <sstream>
#include <cstring>
#include <cmath>
#include <deque>
#include <cassert>

using namespace std;

typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef long long int ll;
typedef deque<ll> vll;

typedef long long int lli;

bool voy(char c){

    if( c== 'o' || c=='a' || c=='e' || c=='i' || c=='u'){

        return true;
    }

    return false;
}

int main()
{
    int T;
    cin>>T;
    string name;
    int n;

    for(int c=1; c<=T; ++c){



        cin>>name>>n;

        lli res = 0;
        int i,j;
        int last = 0, next;
        int actu = 0;
        int L = name.size();

        for(i=0; i<name.size(); ++i){

            if(voy(name[i])){

                actu = 0;

            }
            else{



                actu = min(actu+1,n);


                if(actu == n){

                    res += (L-i) + (i - (n-1) - last)*(L-1-i+1);

                    last = i - (n-2);


                }
            }


        }

        cout<<"Case #"<<c<<": "<<res<<endl;




    }

    return 0;
}

