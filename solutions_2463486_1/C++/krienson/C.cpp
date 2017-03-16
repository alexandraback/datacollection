#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
#include<map>
using namespace std;

#define PB push_back
#define MP make_pair
#define SL size()
#define LE length()
#define INFI 2000000000
#define X first
#define Y second
#define MIN(a,b) ((a)<(b)?(a):(b))
bool isPal(long long a){
     stringstream iss; iss<<a;
     string s = iss.str();
     int to = int(s.LE)/2, tam = int(s.LE);
     for(int i=0;i<to;i++) 
             if(s[i] != s[tam-1-i]) return false;
     return true;
}
int main(){
    map<long long,int> M;
    int K = 0;
    for(long long i=1;i<=10000000;i++){
        if(isPal(i) && isPal(i*i)){
             M[i*i] = K++;
             // cout<<i<<"->"<<i*i<<endl;
        }
    }
    int T; cin>>T;
    for(int kases = 1; kases <= T; kases++){
        int res = 0;
        long long A,B; cin>>A>>B;
        for(map<long long,int>::iterator it = M.begin(); it != M.end(); it++){
           if(it->first >= A && it->first <= B){
              res++;
           }
        }        
        cout<<"Case #"<<kases<<": "<<res<<endl;
    }
}
