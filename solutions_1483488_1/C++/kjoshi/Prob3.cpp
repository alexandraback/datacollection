#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <map>
#include <fstream>

using namespace std;

int main()
{
    freopen("C-large.in","r+",stdin);
    freopen("output3-large.out","w+",stdout);
    int T,it=1;
    cin>>T;
    while(it<=T)
    {
        map<pair<int,int>, bool > check;
        check.clear();
        int A,B,ans = 0,temp,len=1,mod,siz=0,j=0;
        cin>>A>>B;
        temp = B;
        while (temp/=10)
        {
            siz++;
        }
        len=pow(10,siz);
        for (int i = A; i <= B; i++)
        {
            mod = i;
            j=siz;
            while (j--)
            {
                mod = mod/10 + ((mod%10)*len);
                if ( mod > i && mod <= B && !check[make_pair(i,mod)])
                {
                    check[make_pair(i,mod)] = true;
                    ans++;
                }
            }

        }
        cout<<"Case #"<<it++<<": "<<ans<<endl;
    }
}

