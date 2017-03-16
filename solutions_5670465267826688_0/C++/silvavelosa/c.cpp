#include<bits/stdc++.h>
using namespace std;
int nCases,act,al,rt,van;
long long int len,rep,mx;
string inp;
int mult (int a,int b)
{
    if (abs(a) == 1 || abs(b) == 1) return a*b;
    if (abs(a) == abs(b)) return -a/b;
    if ((abs(a)+1)%3 == abs(b)%3) return a/abs(a)*b/abs(b)*((abs(b)-1)%3+2);
    else return -a/abs(a)*b/abs(b)*((abs(a)-1)%3+2);
}
int main (void)
{
    //freopen("input.in","r",stdin);
    //freopen("output.out","w",stdout);
    cin>>nCases;
    for(int aCase = 1;aCase <=nCases;aCase++)
    {
        cin>>len>>rep;
        mx = min(rep,12+rep%4);
        cin>>inp;
        al = 1;
        van = 2;
        for(long long int i=0;i<len*mx;i++)
        {
            al = mult(al,inp[i%len]-'g');
            //cout<<al<<endl;

            if(al == van)
            {
                if(van < 4)
                    al = 1;
                van++;
            }
        }
        if(al == 4 && van == 5)
            cout<<"Case #"<<aCase<<": YES\n";
        else
            cout<<"Case #"<<aCase<<": NO\n";
    }
    return 0;
}
