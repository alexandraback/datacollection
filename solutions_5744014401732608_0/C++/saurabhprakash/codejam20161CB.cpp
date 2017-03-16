#include<bits/stdc++.h>

using namespace std;

bool a[51][51];
int b,m;
/*bool dfs(int ind,bool mark[]) {
    if(mark[ind])
        return true;
    mark[ind]=true;
    int i;
    for(i=0;i<b;i++) {
        if(a[ind][i]) {
            if(dfs(i,mark))
               return true;
        }
    }
    return false;
}
bool cycle(int i,int j) {
    bool mark[b];
    for(int k=0;k<b;k++)
        mark[k]=false;
    mark[i]=true;
    if(dfs(j,mark))
        return true;
    return false;
}*/
bool rec(int ind) {
    if(ind==b-1) {
        m--;
        /*cout<<"hi\n";
        for(int i=0;i<b;i++) {
            for(int j=0;j<b;j++)
                cout<<a[i][j];
            cout<<endl;
        }
        cout<<"hi\n";*/
        return true;
    }
    int i;
    bool flag=false;
    for(i=/*0*/ind+1;i<b && m;i++) {
        if(i==ind)
            continue;
        if(!a[ind][i]) {
            /*if(cycle(ind,i))
                continue;*/
            a[ind][i]=true;
            if(!rec(i))
                a[ind][i]=false;
            else
                flag=true;
        }
    }
    return flag;
}
int main() {

    freopen("C:\\Users\\Saurabh\\Desktop\\in.txt","r",stdin);
    freopen("C:\\Users\\Saurabh\\Desktop\\out.txt","w",stdout);

    int t,cas=1;
    cin>>t;
    while(t--) {
        int i,j;
        cin>>b>>m;
        for(i=0;i<b;i++)
            for(j=0;j<b;j++)
                a[i][j]=false;
        rec(0);
        cout<<"Case #"<<cas++<<": ";
        if(m)
            cout<<"IMPOSSIBLE\n";
        else {
            cout<<"POSSIBLE\n";
            for(i=0;i<b;i++) {
                for(j=0;j<b;j++)
                    cout<<a[i][j];
                cout<<endl;
            }
        }
    }

    return 0;
}

