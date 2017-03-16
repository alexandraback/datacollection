#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<algorithm>
#include<iomanip>


using namespace std;

vector<double> t;

bool dsort(int a, int b){
  return t[a]>t[b];
}


int main(){

  int T; cin>>T;
  for (int tc=0;tc<T;++tc){
    int N; cin>>N;
    vector<int> s=vector<int>(N,0);
    t=vector<double>(N,0);
    double su=0;
    vector<int> ind=s;
    for (int i=0;i<N;++i){
      cin>>s[i];
      t[i]=(double) s[i];
      su+=t[i];
      ind[i]=i;
    }
    sort(ind.begin(),ind.end(),dsort);
    double n=(double) N;
    double d=2*su/n;
    vector<double> sv=t;
    double q=0;
    int h=0;
    for (int i=0;i<N;++i){
      if (t[ind[i]]<d){
	sv[ind[i]]=d-t[ind[i]];
      }
      else{
	sv[ind[i]]=0;
	q+=t[ind[i]];
	if (i+1!=N)
	  d=(2*su-q)/(N-1-i);
      }
    }
    cout<<"Case #"<<tc+1<<": ";
    for (int i=0;i<N-1;i++){
      cout<<setprecision(8)<<100*sv[i]/su<<" ";
    }
    cout<<setprecision(8)<<100*sv[N-1]/su<<endl;



   
  }

  return 0;
}
