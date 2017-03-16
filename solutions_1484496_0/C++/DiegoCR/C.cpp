#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

long long arr[1000];
long long sol1[1000];
long long sol2[1000];

map<long long,long long> marca;
map<long long,long long>::iterator it;

int main(){
    
    int nc,cont=0,n;
    long long tot,aux,auxt;
    bool ok;
    //freopen("C1.in","r",stdin);
    //freopen("C.out","w",stdout);
    cin>>nc;
    while(nc--){
      cont++;
      marca.clear();
      cin>>n;
      for(int i=0;i<n;i++){
        cin>>arr[i];
        }
      sort(arr,arr+n);
      marca[0] = -1;
      ok = false;
      for(int i=0;i<n;i++){
        for(it = marca.begin();it!=marca.end();it++){
          //cout<<(*it).first<<" "<<(*it).second<<endl;
          if((*it).second == 0) break;
          if((*it).second == arr[i]) continue;
          aux = marca[(*it).first + arr[i]];
          if(aux != 0){
            ok = true;
            cout<<"Case #"<<cont<<":"<<endl;
            tot = (*it).first + arr[i];
            auxt = tot;
            while(aux != -1){
              cout<<aux;
              tot -= aux;
              aux = marca[tot];
              if(aux != -1) cout<<" ";
              }
            cout<<endl;
            cout<<arr[i];
            tot = auxt - arr[i];
            aux = marca[tot];
            while(aux != -1){
              cout<<" "<<aux;
              tot -= aux;
              aux = marca[tot];
              }
            cout<<endl;
            }
           else{
             marca[(*it).first + arr[i]] = arr[i];
             } 
          if(ok) break;
          }
        if(ok) break;
        }
      if(!ok){
        cout<<"Case #"<<cont<<":"<<endl;
        cout<<"impossible"<<endl;
        }
      }
    }
