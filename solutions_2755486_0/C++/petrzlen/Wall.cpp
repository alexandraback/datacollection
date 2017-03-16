#include <iostream>
#include <vector>
#include <cstdio> 
#include <algorithm>
#include <set>
#include <string>
#include <map>

using namespace std;

#define REP(i, to) for(int i=0; i<to; i++)

typedef long long int LLI; 
typedef pair<int, int> PII; 

#define D 2500

int main()
{
  int T;
  cin >> T;
  REP(t, T){
    
    //history of attacks day -> strength -> (west, east) 
    map<int, vector<pair<int, PII> > > H; 
    
    int N; 
    cin >> N;
    REP(i, N){
      int di, ni, wi, ei, si, ddi, dpi, dsi;
      cin >> di >> ni >> wi >> ei >> si >> ddi >> dpi >> dsi;
      
      ei *= 2;
      wi *= 2; 
      ei += D;
      wi += D; 
      dpi *= 2; 
      
      REP(j, ni){
        H[di].push_back(pair<int, PII>(si, PII(wi, ei)));
        
        si += dsi; 
        ei += dpi;
        wi += dpi; 
        di += ddi; 
      }
    }
    
    int result=0; 
    vector<int> W(D*3, 0); 
    
    for(map<int, vector<pair<int, PII> > >::iterator iter = H.begin(); iter != H.end() ; iter++){
      vector<pair<int, PII> > A = iter->second; 
      //successfull attacks
      REP(a, A.size()){
        int s = A[a].first; 
        PII p = A[a].second; 
        //cout << iter->first << ": " << s << " (" << p.first << "," << p.second << ") W[west] = " << W[p.first] << endl;
        for(int w=p.first ; w<=p.second ; w++){
          if(W[w]<s) {
            result++;
            //cout << "success" << endl;
            break; 
          }
        }
      }
      //update
      REP(a, A.size()){
        int s = A[a].first; 
        PII p = A[a].second; 
        for(int w=p.first ; w<=p.second ; w++){
          W[w] = max(W[w], s); 
        }
      }
    }
  
    cout << "Case #"<<t+1<<": " << result << endl;
  }
  
	return 0;
}
