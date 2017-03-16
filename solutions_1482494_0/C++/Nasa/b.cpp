#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;

//double p[1000],left1[1000];//,rightcorrect[1000],rightall[1000];

int x[2000][2],broken[2000];
typedef pair<int,int> D;

int main(){
    int u,t,n,i,j,c;
    D  v;
    int req,id;
    cin>>t;
    for (u=0; u<t; u++){
        priority_queue<D> q;
        priority_queue<D> q2;
        cin>>n;
        for (i=0; i<n; i++) cin>>x[i][0]>>x[i][1];
        for (i=0; i<n; i++) broken[i]=0;
        c=0;
        //for (i=0; i<n; i++) q2.push(make_pair(x[i][1],i));
        //for (i=0; i<n; i++) q.push(make_pair(x[i][1],-i-1));
        int ok=1,opt=0;
        while (ok){//!q.empty()){
            ok=0;
            while(!q.empty() && abs(q.top().first)<=c){
                //cout<<"q:"<<q.top().first<<","<<q.top().second<<endl;
                /*if (q.top().second<0){
                    id=-q.top().second-1;
                    if (broken[id]) continue;
                    broken[id]=1;
                    c+=2;
                    opt++;
                    ok=1;
                }
                else{*/
                //cout<<"--"<<q.top().second<<" "<<q.top().first<<endl;
                            q.pop();
                c++;
                ok=1;
                opt++;
                //}
            }
            for (i=0; i<n; i++){
                if (!broken[i] && x[i][1]<=c){
                    broken[i]=1;
                    ok=1;
                    c+=2;
                    opt++;
                    //break;
                }
            }
            if (!ok){
            int mn=-1;
            for (i=0; i<n; i++){
                if (broken[i]) continue;
                if (x[i][0]>c) continue;
                if (mn==-1 || x[mn][1]<x[i][1]) mn=i; // try <
            }
            if (mn>-1){
                       //cout<<c<<"=c, mn="<<mn<<"("<<x[mn][0]<<","<<x[mn][1]<<")"<<endl;
                       broken[mn]=1;
                       q.push(make_pair(-x[mn][0],mn));
                       q.push(make_pair(-x[mn][1],mn));
                       ok=1;
            }
            }
            /*
            if (!q2.empty()){
            v=q2.top(); q2.pop();
            req=abs(v.first);
            id=v.second;
            cout<<"("<<req<<"<="<<id<<endl;
            if (c>=req){ ok=1; c+=2; opt++;}
            else{
                ok=1;
                int mn=-1;
                //broken[i]=0;
                q.push(make_pair(-x[i][0],i));
                q.push(make_pair(-x[i][1],i));
            }
            }*/
        }
        cout<<"Case #"<<(u+1)<<": ";
        if (c==2*n) cout<<opt<<endl;
        else cout<<"Too Bad"<<endl;
    }
    return 0;
}
