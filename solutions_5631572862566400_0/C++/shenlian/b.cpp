#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <map>
#include <limits.h>
#include <stdlib.h>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;
const int num = 1e5 + 5;
int N,M,k=0,ek = 0,cnt;
map<string,int> id_mp;
string name[num];
bool vis[num];
int fa[num],h[num],hq[num],ans[num];
struct node{
    int next;
    int to;
    int lca;
}e[num],q[num<<1];

int get_fa(int u){
    if(u != fa[u]) fa[u] = get_fa(fa[u]);
    return fa[u];
}

void create(string &per1 , string &per2){
    if(id_mp.count(per1) == 0){
        id_mp[per1] = k;
        h[k] = -1;
        name[k++] = per1;
    }
    if(id_mp.count(per2) == 0){ 
        id_mp[per2] = k;
        h[k] = -1;
        name[k++] = per2;
    }
    int fid = id_mp[per1],sid = id_mp[per2];
    e[ek].to = sid;
    e[ek].next = h[fid];
    h[fid] = ek++;
}

void addquery(int id1 , int id2){
    q[k].to = id2;
    q[k].next = hq[id1];
    hq[id1] = k++;
}

void LCA(int u){
    fa[u] = u;
    vis[u] = true;
    int k;
    for( k = h[u] ; k != -1; k = e[k].next){
        if(!vis[e[k].to]){
            LCA(e[k].to);
            fa[e[k].to] = u;
        }
    }
    for( k = hq[u] ; k != -1 ; k = q[k].next){
        if(vis[q[k].to]){
            ans[k>>1] = get_fa(q[k].to);         
        }
    }
}

int main(){
    cin>>N;
    string per1,per2;
    memset(hq,-1,num*sizeof(int));
    for(int i = 0 ; i < N ; i++)
    {   
        cin>>per1>>per2;
        create(per1,per2);
    }
    cin>>M;
    k = 0;
    for(int i = 0 ; i < M ; i++){
        cin>>per1>>per2;
        int id1 = id_mp[per1], id2 = id_mp[per2];
        addquery(id1,id2);
        addquery(id2,id1);
    }
    LCA(0);
    k = 0;
    for(int i = 0 ; i < M ; i++){
        cout<<name[ans[i]]<<endl;
    }
    return 0;
}