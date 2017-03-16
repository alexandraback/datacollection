#include <iostream>
#include <sstream>
using namespace std;

bool isgood(int j, int p, int s, int jp[], int ps[], int js[], int J, int P, int S, int K){
    return (jp[j*P+p]<K && ps[p*S+s]<K && js[j*S+s]<K);
}

void fashion(int J,int P,int S,int K){
    int *jp,*ps,*js;
    jp= new int[J*P];
    for(int i = 0; i< J*P; i++){
        jp[i]=0;
    }
    ps = new int[P*S];
    for(int i = 0; i< P*S; i++){
        ps[i]=0;
    }
    js = new int[J*S];
    for(int i = 0; i< J*S; i++){
        js[i]=0;
    }
    stringstream cloths;
    int sum = 0;
    for(int _j=0; _j<J ; _j++){
        for(int _p=0; _p<P; _p++){
            for(int _s=0; _s<S; _s++){
                if(isgood(_j,_p,_s,jp,ps,js,J,P,S,K)){
                    sum+=1;
                    jp[_j*P+_p]+=1;
                    ps[_p*S+_s]+=1;
                    js[_j*S+_s]+=1;
                    cloths << _j+1 << " " << _p+1 << " " << _s+1 << endl;
                }
            }
        }
    }
    cout << sum << endl;
    cout << cloths.str();
}


int main() {
  int t,J,P,S,K;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    cin >> J >> P >> S >> K;
    cout << "Case #" << i << ": ";
    fashion(J,P,S,K);
  }
}
