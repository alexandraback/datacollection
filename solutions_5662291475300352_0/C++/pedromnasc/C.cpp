#include <bits/stdc++.h>

#define MAX 1000010

using namespace std;

typedef long long int ll;

const ll INF = 1LL<<60;

struct Hike{
    int p;
    double v;

    Hike(int _a,double _b):p(_a),v(_b){
    }

    bool operator < (const Hike &aux)const{
        if(p!=aux.p) return p<aux.p;
        return v<aux.v;
    }

};

int T;
int N,D,H,M;

int main(void){
    freopen("C-small-1-attempt0.in","r",stdin);
    freopen("C.out","w",stdout);
    scanf("%d",&T);
    for(int caso=1;caso<=T;caso++){
        scanf("%d",&N);
        vector<Hike> v;
        set<int> imp;
        for(int i=0;i<N;i++){
            scanf("%d %d %d",&D,&H,&M);
            for(int j=0;j<H;j++){
                v.push_back( Hike(D,1.0/(M+j)) );
                if(D == 0) imp.insert(1.0/(M+j));
            }
        }
        int resp=2;
        sort(v.begin(),v.end());
        vector<double> t;

        for(int i=0;i<v.size();i++){
            t.push_back(v[i].v);
            t.push_back(v[i].v-1e-4);

            t.push_back(v[i].v-1e-2);
            t.push_back(v[i].v+1e-2);
            t.push_back(v[i].v-1e-6);
            t.push_back(v[i].v+1e-6);
            t.push_back(v[i].v-1e-3);
            t.push_back(v[i].v+1e-3);
            t.push_back(v[i].v-1e-5);
            t.push_back(v[i].v+1e-5);
            t.push_back(v[i].v+1e-4);

            t.push_back( 1/(1/v[i].v +1) );
            t.push_back( 1/(1/v[i].v -1) );
        }

        t.push_back(0.00001);

        t.push_back(100000);

        for(int i=0;i<t.size();i++){
            if(t[i]<0) continue;
            //if(i>0) break;
          //  printf("t:%f\n",t[i]);
            int cont=0;
            for(int j=0;j<v.size();j++){
                double aux= v[j].v/t[i] + 1.0*v[j].p/360 ;
              //  cout << "aux: " << aux << endl;
                if(aux <= 1 || aux>=2) cont++;
            }
           // if(cont == 0) printf("ii:%d\n",i);
            resp=min(resp,cont);
        }

        printf("Case #%d: %d\n",caso,resp);
    }
}

