#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;


int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-attempt0.out","w",stdout);
    std::string str;
    unsigned case_count = 0;
    unsigned N =0,S,p,t[100];

//    content cont[100] = {0};
    unsigned Condi = 0;
    cin >>  case_count;
    //cout << case_count;
    char buffer[200];
    char buffer2[200];
    map<char,char> googlerese;
    //map<char,char> inver;
    cin.getline(buffer,200);
    unsigned A,B;
    if(case_count==0) return 0;
    int table[8] = {1,10,100,1000,10000,100000,1000000,10000000};
    set<int> m;
    for(int c =1; c <= case_count ; c++)
    {
        cin >> A>> B ;
        int count = 0;
        int max_k = log10(A);
        for(int a =A; a <=B;a++){
            m.clear();
            for(int k = 1; k <= max_k;k++){
                int e0 = table[k];
                int e1 = table[max_k - k + 1];
                int b = a/e0 + (a%e0)*e1;

                if( b <= B && a<b )
                {
                    m.insert(b);
                }
            }
            count += m.size();
        }
        //cout << count<<endl;
       printf("Case #%u: %d\n",c,count);
    }

    return 0;
}
