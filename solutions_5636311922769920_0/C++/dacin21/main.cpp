#include <bits/stdc++.h>
using namespace std;

const int BASE = 1e9;
const int LOGBASE = 9;
struct bigInt{ // As output can be as large as 100^100 = 10^200
  vector<unsigned int> data;//base 10^9;
  bigInt(int a){
    data.resize(1, a);
  }

  void print(){
    int i;
    for(i=(int)data.size()-1;i>0&&data[i]==0;--i);//strip leading zeros
    cout << data[i];
    for(--i;i>=0;--i){
      assert(data[i] < BASE);
      cout << setw(LOGBASE) << setfill('0') << data[i];
    }
    cout << " " << flush;
  }
  void add(int a){//adds a small integer
    data.push_back(0);
    data[0]+=a;
    for(int i=0;data[i]>=BASE;++i){
      data[i]-=BASE;
      ++data[i+1];
    }
    if(data.back()==0)data.pop_back();
  }
  void mul(int a){
    long long cur = 0;
    data.push_back(0);
    for(int i=0;i<(int)data.size();++i){
      cur+=(long long)data[i]*a;
      data[i]=cur%BASE;
      cur/=BASE;
    }
    if(data.back()==0)data.pop_back();
  }


};

void encode(int K, int C, int begin){//encode C digits in base K
    bigInt ret(0);
    for(int j=0;j<C;++j, ++begin){
        begin=min(begin, K-1); // prevent invalid encoding due to overflow
        ret.mul(K);
        ret.add(begin);
    }
    ret.add(1);
    ret.print();
}
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int T, C, S, K;
    cin >> T;
    for(int i = 1;i<=T;++i){
        cin >> K >> C >> S;
        cout << "Case #" <<i<<": ";
        if(S*C < K){
            cout << "IMPOSSIBLE\n";
            continue;
        }
        for(int i=0;i<K;i+=C){
            encode(K, C, i);
        }
        cout << endl;
    }
    return 0;
}
