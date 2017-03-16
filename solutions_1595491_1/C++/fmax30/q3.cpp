#include <iostream>

#include <string>
#include <cstdio>
#include <cstdlib>

#include <vector>

#include <cmath>
#include <algorithm>
#include <map>
using namespace std;
void Magic(vector<int> n,int magicno,int surprising,int t)
{
    vector<int> probableSurprising;
    int count=0;
    for (int i=0 ; i< n.size() ; i++)
    {


    int p = ceil(n[i]/(float)3);
    if ( (p <magicno) )
    probableSurprising.push_back(n[i]);
    else
    {
        count++;
  //      cout<<"Nice"<<p<<" "<<n[i]-2*p <<endl;
    }
//
//    int a,b,c;
//    a = p;
//    b=p;
//    c=b-2*p;

    }

    for ( int i=0 ; i < probableSurprising.size(); i++)
    {
        int x = probableSurprising[i];
        x = x-magicno;

        int y= x - x/2;
        x=x/2;
        if (probableSurprising[i]>0 && surprising > 0 && magicno-x<= 2 && (magicno - y)<=2 && (x-y)<=2 )
        {
  //          cout<<"Surprising"<<endl;
            count++;
            surprising--;
        }

    }

    cout<<"Case #"<<t+1<<": "<<count<<endl;
}
int main()
{
    freopen("B-large.in","r",stdin);
    freopen("output3.txt","w",stdout);

    int T=0;
    cin>>T;
    for ( int t=0 ; t < T ; t++)
    {
        int N,surp,magicNo;
        cin>>N;
        cin>>surp;
        cin>>magicNo;
        vector<int> L(N);
        for ( int i=0 ; i < N; i++)
        {
            cin>>L[i];
        }
        Magic(L,magicNo,surp,t);
    }

}
//1 0 2 2
//2/3 = 0 ,

//3 0 6 20 21 14
