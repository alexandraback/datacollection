#include <iostream>
#include <vector>
#include <fstream>
#define int long long
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");

#define cin in
#define cout out


void main()
{
int tt;
    cin>>tt;
    for (int iii=0;iii<tt;iii++)
    {
        cout<<"Case #"<<iii+1<<": ";
        int a,b,k;
        cin>>a>>b>>k;
    /*a=41;
    b=594;
    k=5;*/
    vector<pair<int,int> > ba;
    vector<pair<int,int> > bb;
    vector<pair<int,int> > bk;
    long long prev=0;
    for (int i=41;i>=0;i--)
        if (a&(1ll<<i))
        {
            ba.push_back(make_pair(prev,prev+(1ll<<i)));
            prev+=(1ll<<i);
        }
        prev=0;
        for (int i=41;i>=0;i--)
            if (b&(1ll<<i))
            {
                bb.push_back(make_pair(prev,prev+(1ll<<i)));
                prev+=(1ll<<i);
            }
            prev=0;
            for (int i=41;i>=0;i--)
                if (k&(1ll<<i))
                {
                    bk.push_back(make_pair(prev,prev+(1ll<<i)));
                    prev+=(1ll<<i);
                }

    long long anssswer=0;
    for (int i=0;i<ba.size();i++)
        for (int j=0;j<bb.size();j++)
            for (int h=0;h<bk.size();h++)
            {
                int fa=0,fb=0,fk=0;
                int tmp=ba[i].second-ba[i].first;
                while(tmp>>=1)
                    fa++;
                tmp=bb[j].second-bb[j].first;
                while(tmp>>=1)
                    fb++;
                tmp=bk[h].second-bk[h].first;
                while(tmp>>=1)
                    fk++;
               //----------------------------------------------------------
                int currr=1;
                for (int pos=41;pos>=0;pos--)
                {
                    int ytfrd=0;
                    if (pos>=fk)
                    {
                        if (pos>=fa && pos>=fb)
                        {
                            if ( (((1ll<<pos)&(ba[i].first))&((1ll<<pos)&(bb[j].first)))!=((1ll<<pos)&(bk[h].first)))
                            {
                                currr=0;
                                break;
                            }
                        }
                        else
                        {
                            if (pos<fa && pos>=fb)
                            {
                                if (!((1ll<<pos)&(bb[j].first)))
                                {
                                    if ((1ll<<pos)&(bk[h].first))
                                    {
                                        currr=0;
                                        break;
                                    }
                                    else
                                        currr*=2;
                                }

                            }
                            if (pos>=fa && pos<fb)
                            {
                                if (!((1ll<<pos)&ba[i].first))
                                {
                                    if ((1ll<<pos)&bk[h].first)
                                    {
                                        currr=0;
                                        break;
                                    }
                                    else
                                        currr*=2;
                                }
                            }
                            if (pos<fa && pos<fb)
                            {
                                if (!((1ll<<pos)&bk[h].first))
                                    currr*=3;
                            }
                        }
                    }
                    else //pos<k
                    {
                        if (pos>=fa && pos>=fb)
                        {
                            ;
                        }
                        if (pos<fa && pos>=fb)
                        {
                            currr*=2;
                        }
                        if (pos>=fa && pos<fb)
                        {
                            currr*=2;
                        }
                        if (pos<fa && pos<fb)
                        {
                            currr*=4;
                        }
                    }
                }
                anssswer+=currr;
            }
    cout<<anssswer<<endl;
    }
        
}