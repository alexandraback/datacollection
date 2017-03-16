#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <locale>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main(void)
{
    ifstream cin ("A-large.in");
    ofstream cout ("A-large.out");
    long long int T,h,i,j,k;
    long long int A,N,ans;
    long long int mote[105];
    vector<long long int> temp;
    bool del=false;
    cin>>T;
    for(h=0;h<T;h++)
    {
        cin>>A>>N;
        ans=0;
        k=0;
        del=false;
        for(i=0;i<N;i++)    cin>>mote[i];
        sort(mote,mote+N);
        for(i=0;i<N;i++)
        {
            if(!del)
            {

                if(A>mote[i])   A+=mote[i];
                else if(A+A-1>mote[i])
                {
                    ans++;
                    A+=A-1+mote[i];
                }
                else
                {
                    j=i;
                    //ans++;

                    del=true;
                    i--;
                    if(A-1==0)  break;
                    //break;
                }
            }
            else
            {
                k=0;
                while(A<=mote[i])
                {
                    A+=A-1;
                    k++;
                }
                A+=mote[i];
                temp.push_back(k);
            }
        }
        if(del)
        {
            long long int mini,sum=0;
            long long int todelete=N-j;
            mini=N-j;
            for(i=0;i<temp.size();i++)
            {
                todelete--;
                sum+=temp[i];
                mini=min(mini,sum+todelete);
            }
            ans+=mini;
        }
        temp.clear();
        cout<<"Case #"<<h+1<<": "<<ans;
        cout<<"\n";
    }

    return 0;
}
