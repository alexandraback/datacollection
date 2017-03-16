#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#define INF 2000000000
using namespace std;

#define ALL(t) t.begin(),t.end()
#define MP(x, y) make_pair((x), (y))
#define Fill(a,c) memset(&a, c, sizeof(a))
int finmax(int &may, vector<int>num){
    int ret=0, cont=0;
    for(int i=0; i<num.size();i++){
        if(num[i]==may)
            cont++;
        if(num[i]<may)
            ret=max(ret, num[i]);
    }
    may=ret;
    return cont;
}

int main(){
    freopen("A-large.in","r",stdin);
    //freopen("A-small-attempt1.in","r",stdin);
    freopen("solution.out","w",stdout);
    int cas;
    cin>>cas;
    int may, sum, tam, aux;
    double aux2;
    for(int i=1; i<=cas; i++){
        vector<int> num;
        cin>>tam;
        sum=may=0;
        for(int j=0; j<tam; j++){
            cin>>aux;
            num.push_back(aux);
            sum+=aux;
            may=max(aux, may);
        }

        int ayud=-1;
        do{
            aux=sum;
            if(ayud>=0){
                ayud+=finmax(may, num);
            }else{
                ayud=0;
            }

            for(int j=0; j<tam; j++){
                if(num[j]<=may)
                    aux-=may-num[j];
            }
            //cout<<aux<<"  "<<may<<endl;
        }while(aux<0);
        aux2=aux*1.0/(tam-ayud);
        //cout<<aux<<"  "<<may<<endl;
        cout<<"Case #"<<i<<":";
        for(int j=0; j<tam; j++){
            if(num[j]<=may)
                printf(" %.6f",((aux2+may-num[j])*100.0/sum));
            else
                printf(" 0.000000");
        }
        cout<<endl;
    }

return 0;
}
