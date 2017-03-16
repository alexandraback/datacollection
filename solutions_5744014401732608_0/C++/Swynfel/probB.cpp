#include <iostream>
#include <vector>
using namespace std;

int test(bool sl[],int B){
    int *ways;
    ways = new int[B];
    ways[B-1]=1;
    for(int k=B-2;k>=0;k--){
        ways[k]=0;
        for(int i=k+1; i<B ; i++){
            ways[k]+=sl[k*B+i]*ways[i];
        }
    }
    return ways[0];
}

bool increment(bool sl[], int B){
    bool ok = false;
    for(int k=B-2;k>=0;k--){
        if(!ok){
            for(int i=k+1;i<B;i++){
                if(!ok){
                    if(sl[k*B+i]){
                        sl[k*B+i]=false;
                    }else{
                        sl[k*B+i]=true;
                        ok = true;
                        break;
                    }
                }
            }
        }
    }
    return ok;
}

void printtable(bool sl[],int B){
    for(int line=0; line<B;line++){
        for(int row=0; row<B;row++){
            if(sl[line*B+row]){
                cout << 1;
            }else{
                cout << 0;
            }
        }
        cout << endl;
    }
}

void slides(int B,int M){
    bool *sl;
    sl = new bool[B*B];
    for(int i=0 ; i< B*B ; i++){
        sl[i]=false;
    }
    int m = -1;
    bool cancontinue=true;
    m=test(sl,B);
    while(m!=M and cancontinue){
        cancontinue=increment(sl,B);
        m=test(sl,B);
    }
    if(m==M){
        cout << "POSSIBLE" << endl;
        printtable(sl,B);
    }else{
        cout << "IMPOSSIBLE" << endl;
    }
}

int main() {
  int t,B,M;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    cin >> B >> M;
    cout << "Case #" << i << ": ";
    slides(B,M);
  }
}
