#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
int T;
vector<int> cor;
int check_pal(int k){
    vector<int> v;
    while(k>0){
        v.push_back(k%10);
        k/=10;
    }
    int L = v.size();
    for(int i=0;i<L/2;i++){
        if( v[i] != v[L-i-1] ){
            return 0;
        }
    }
    return 1;
}
int Find(int k){
    int Size = cor.size();
    for(int i=0;i<Size;i++){
        if(cor[i] > k){
            return i;
        }
    }
    return Size;
}
int main(){
    for(int i=1;i*i<=1000;i++){
        if(check_pal(i*i)==1 && check_pal(i)){
            cor.push_back(i*i);
            fprintf(stderr,"%d\n",i*i);
        }
    }
    int T,m,n;
    scanf("%d",&T);
    for(int f = 1; f<=T ; f++){
        scanf("%d%d",&m,&n);
        printf("Case #%d: %d\n",f, Find(n) - Find(m-1));
    }
    return 0;
}
