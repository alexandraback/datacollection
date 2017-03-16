#include<bits/stdc++.h>
#define f(i,x,y) for (int i = int(x); i < int(y); i++)
#define fd(i,x,y) for(int i = int(x); i>= int(y); i--)
#define FOR(it,A) for(typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define vint vector<int>
#define ll long long
#define clr(A,x) memset(A, x, sizeof A)
#define pb push_back
#define pii pair<int,int>
#define fst first
#define snd second
#define ones(x) __builtin_popcount(x)
#define cua(x) (x)*(x)
#define oo 10000000
#define MAX 1000009
#define MOD 1000000007

using namespace std;
set<char> s1;
bool iscon(char c){
    if(!s1.count(c))
        return true;
    return false;
}

int main(){
    freopen("A-large.in","r",stdin);
    freopen("out.c","w",stdout);
    s1.insert('a');
    s1.insert('e');
    s1.insert('i');
    s1.insert('o');
    s1.insert('u');
    int TC,n,NC=1;
    string cad;
    char c[1000009];
    scanf("%d",&TC);
    while(TC--){
        //scanf("")
        scanf("%s %d",c,&n);
        cad = c;
        //bool posiciones[1000009];
        int anu = 0;
        ll ans = 0;
        f(i,0,cad.size()){
            //cout<<"-->"<<cad[i]<<endl;
            if(iscon(cad[i])){
                //cout<<"entra si es con "<<i<<endl;
                int ini = i, fin,cont = 0;
                f(j,i,cad.size()){
                    if(iscon(cad[j]))   cont++;
                    else    break;
                }
                fin = i+cont;
                //cout<<ini<<" "<<fin<<endl;
                i+=(cont-1);
                for(int j = ini;(j+n)<=fin;j++){
                    //cout<<"entra"<<endl;
                    int der = (j+1)-anu;
                    int izq = (cad.size()+1)- ((j+n-1)+2) + 1;
                    //cout<<der<<"--"<<izq<<endl;
                    ans+=(ll)((ll)der*(ll)izq);
                    anu = (j+1);
                }
            }
        }
        printf("Case #%d: %lld\n",NC++,ans);

    }


    return 0;
}

