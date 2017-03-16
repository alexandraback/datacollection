#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;


int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
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

    if(case_count==0) return 0;
    for(int c =1; c <= case_count ; c++)
    {
        cin >> N >> S >> p;
        int count = 0 ;
        for(int i = 0; i < N ;i++){
            cin >> t[i];
            if( (t[i]+2)/3 >= p )
                count++;
            else if( t[i]!=0&&(t[i]+4)/3 >= p && S != 0)
            {
                count++;
                S--;
            }
        }
        printf("Case #%u: %d\n",c,count);
    }

    return 0;
}
