#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

#define LOOP(t,T) for(t=0; t< (T); t++)

using namespace std;


int main(){
  long  j, k, i, l, n, t, M, N, len, index;
  long lay, num, C, PD, penalty, PG, T, p, score, flag;
  string temp, order,  current;
  vector <string> wlength;
  vector <string>  dictionary, dict;
  long S[50],P[50];
  long sum;
  char lane[50];
  long s[200];
  double  m[200], SC, sco,scoo;
  cin >> T;
  
  LOOP(t,T) {
    sum = 0;
    cin >> N ;
    LOOP(i,N){
      cin>>s[i];
      m[i]=0;
      sum = sum + s[i];
      // cout << lane[i] << " " << S[i] << " " << P[i]<<endl; 
    }
    SC=0;
    scoo=0;
    LOOP(i,N){
      if ((2.0*sum-s[i]*N*1.0)/(1.0*N*sum)<0){
	SC++;
	scoo = scoo+s[i];
      }  
    }
    scoo=sum - scoo;
    
    LOOP(i,N){
      if ((2.0*sum-s[i]*N*1.0)/(1.0*N*sum)>=0)
	m[i]=((sum*1.0+scoo*1.0)/(1.0*(N-SC))-s[i])*100.0/sum;
//((sum+scoo)*(N-SC)*1.0)/(1.0*(N-SC)*sum)*100.0;
    }
    cout.precision(8);
    cout << "Case #" << t+1 << ": ";    
    
    LOOP(i,N){
      cout<<m[i]<<" ";
    }
    cout<<endl;
  }
  return 0;
}

