#include <bits/stdc++.h>

using namespace std;

struct P{
    int i,j,k;
    bool operator == (P l){
        return l.i==i && l.j==j && l.k==k;
    }
    bool operator < (P l){
        if(l.i!=i || l.j!=j)
        return make_pair(l.i,l.j) < make_pair(i,j);
        return make_pair(l.j,l.k) < make_pair(j,k);
    }
};

int hash_f(int a,int b){
    return (a + b) * (a + b + 1) / 2 + a ;
}

int hash_g(int a,int b,int c){
    return (a*503 + b)*859 + c;
}
int main() {
    freopen("/home/mars/Documents/in.in","r",stdin);
    freopen("/home/mars/Documents/C.out","w",stdout);
    int T; scanf("%d", &T);
    for(int z=1;z<T+1;++z) {
        int ji,p,s,ka;
        map<int,int> mp1,mp2,mp3;
        cin >> ji >> p >> s >> ka;
        vector<P> v;
        map<int,int> mp;
        while(1){
            bool found=false;
            for(int i=1;i<=ji;++i){
                for(int j=1;j<=p;++j){
                    for(int k=1;k<=s;++k){
                        if(mp.count(hash_g(i,j,k)))
                            continue;
                        if(mp1[hash_f(i,j)]<ka && mp2[hash_f(i,k)]<ka && mp2[hash_f(j,k)]<ka){
                            found=true;
                            v.push_back(P{i,j,k});
                            mp1[hash_f(i,j)]++;
                            mp2[hash_f(i,k)]++;
                            mp3[hash_f(j,k)]++;
                            mp[hash_g(i,j,k)]=1;
                        }
                    }
                }
            }
            if(!found)
                break;
        }
        cout << "Case #" << z << ": ";
        cout<< (int)v.size() << endl;
        //sort( v.begin(), v.end() );
        v.erase( unique( v.begin(), v.end() ), v.end() );
        //for(auto it:v){
          //  cout << it->i;
        //}
        for(int i=0;i<(int)v.size();++i){
            cout << v[i].i << " " << v[i].j << " " << v[i].k << endl;
        }
    }
}
