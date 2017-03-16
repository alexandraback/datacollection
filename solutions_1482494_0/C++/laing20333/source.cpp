#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <limits.h>
#include <cmath>
#include <stdio.h>
#include <cstdio>
#include <memory.h>
#include <sstream>
#include <vector>


using namespace std;

bool cmp (const pair<int,int> &a, const pair<int,int> &b)
{
    if (a.first != b.first)
        return a.first < b.first;

    return a.second > b.second;
}


int main()
{

    //freopen("input.txt","r",stdin);
    freopen("B-small-attempt5.in","r",stdin);
    freopen("ans.txt","w",stdout);
    int ntest;
    while(cin>>ntest){
        int tt;
        for(tt=0; tt<ntest; tt++){
            printf("Case #%d: ",tt+1);
            int nlevel;
            cin>>nlevel;
            vector<pair<int,int> >v;
            int s1,s2;
            int i,k,m;
            pair<int,int>p;
            for(i=0; i<nlevel; i++){
                cin>>p.first>>p.second;

                v.push_back(p);

                //cout<<v[i][0]<<" "<<v[i][1]<<endl;
            }
            sort(v.begin(),v.end(),cmp);
/*
            for(i=0; i<nlevel; i++){
                cout<<v[i].first<<" "<<v[i].second<<endl;
            }
*/
            int star=0;
            if(v[0].second==0){
                star=2;
                v.erase(v.begin());
                nlevel--;
            }
            else if(v[0].first==0){
                star=1;
                v[0].first=-1;
            }
            else {
                cout<<"Too Bad"<<endl;
                continue;
            }
            int ans=1;
            int isok=1;
            while(1){
                //cout<<v.size()<<endl;
                if(v.empty())
                    break;
                int istwo=0;
                isok=0;
                for(i=0;i<nlevel;i++){
                    if(star>=v[i].second){
                        int tmp=v[i].second;
                        int index=i;
                        while(v[index].second==tmp&&index<v.size()){
                            index++;
                        }
                        index--;
                        if(v[index].first!=-1){
                            star+=2;
                        }
                        else {
                            star+=1;
                        }
                        v.erase(v.begin()+index);
                        nlevel--;
                        ans++;
                        istwo=1;
                        isok=1;
                        break;
                    }
                }
                if(v.empty()){
                    break;
                }
                else if(istwo){
                    continue;
                }
                for(i=0;i<nlevel;i++){
                    if(v[i].first!=-1&&star>=v[i].first){
                        v[i].first=-1;
                        star+=1;
                        ans++;
                        isok=1;
                        break;
                    }
                }
                if(v.empty()){
                    break;
                }
                if(!isok){
                    cout<<"Too Bad"<<endl;
                    break;
                }
            }
            if(isok)
                cout<<ans<<endl;
            /*
            for(i=0; i<nlevel; i++){
                cout<<v[i].first<<" "<<v[i].second<<endl;
            }
            */

        }
    }


    return 0;
}
