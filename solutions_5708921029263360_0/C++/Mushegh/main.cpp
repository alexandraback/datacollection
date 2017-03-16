#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;
int j,p,s,k,i,t;
int g,h,l;
int Q = 1;
pair <int, pair<int,int> > av[(1<<20)];
int zuy1[4][4],zuy2[4][4],zuy3[4][4];
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin>>t;
    while(t)
    {
        t--;
        cin>>j>>p>>s>>k;
        cout<<"Case #"<<Q<<": ";
        Q++;
        if(k >= s)
        {
            cout<<j*p*s<<endl;
            for(g=1;g<=j;g++)
                for(h=1;h<=p;h++)
                    for(l=1;l<=s;l++)
                    {
                        cout<<g<<" "<<h<<" "<<l<<endl;
                    }
        }
        else if(j<=3)
        {
            int v = j*p*s;
            int q = 0;
            for(g=1;g<=j;g++)
                for(h=1;h<=p;h++)
                    for(l=1;l<=s;l++)
                    {
                        av[q++] = make_pair(g,make_pair(h,l));
                    }
            int answ = 0;
            int msk = 0;
            for(int mask = 1;mask<(1<<v);mask++)
            {
                int sum = 0;
                for(g=1;g<=j;g++)
                    for(h=1;h<=p;h++) zuy1[g][h] = 0;
                for(g=1;g<=j;g++)
                    for(l=1;l<=s;l++) zuy2[g][l] = 0;
                for(h=1;h<=p;h++)
                    for(l=1;l<=s;l++) zuy3[h][l] = 0;
                bool z = false;
                for(i=0;i<v;i++)
                {
                    if((mask>>i)&1)
                    {
                        sum++;
                        g = av[i].first;
                        h = av[i].second.first;
                        l = av[i].second.second;
                        zuy1[g][h]++;
                        zuy2[g][l]++;
                        zuy3[h][l]++;
                        if(zuy1[g][h] > k) z = true;
                        if(zuy2[g][l] > k) z = true;
                        if(zuy3[h][l] > k) z = true;
                    }
                }
                if(!z)
                {
                    if(answ<sum)
                    {
                        answ = sum;
                        msk = mask;
                    }
                }
            }
            
            cout<<answ<<endl;
            for(i=0;i<v;i++)
                if((msk>>i)&1)
                {
                    cout<<av[i].first<<" "<<av[i].second.first<<" "<<av[i].second.second<<endl;
                }
        }
        else
        {
            if(k == 1)
            {
                cout<<9<<endl;
                cout<<"1 1 2"<<endl;
                cout<<"1 2 1"<<endl;
                cout<<"1 3 3"<<endl;
                cout<<"2 1 1"<<endl;
                cout<<"2 2 3"<<endl;
                cout<<"2 3 2"<<endl;
                cout<<"3 1 3"<<endl;
                cout<<"3 2 2"<<endl;
                cout<<"3 3 1"<<endl;
            }
            else
            {
                cout<<18<<endl;
                cout<<"1 1 1"<<endl;
                cout<<"1 1 3"<<endl;
                cout<<"1 2 1"<<endl;
                cout<<"1 2 2"<<endl;
                cout<<"1 3 2"<<endl;
                cout<<"1 3 3"<<endl;
                cout<<"2 1 1"<<endl;
                cout<<"2 1 2"<<endl;
                cout<<"2 2 2"<<endl;
                cout<<"2 2 3"<<endl;
                cout<<"2 3 1"<<endl;
                cout<<"2 3 3"<<endl;
                cout<<"3 1 2"<<endl;
                cout<<"3 1 3"<<endl;
                cout<<"3 2 1"<<endl;
                cout<<"3 2 3"<<endl;
                cout<<"3 3 1"<<endl;
                cout<<"3 3 2"<<endl;
            }
        }
    }
    return 0;
}
/*
 4
 1 1 1 10
 1 2 3 2
 1 1 3 2
 1 2 3 1
 */