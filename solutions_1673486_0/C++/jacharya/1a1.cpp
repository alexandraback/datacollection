#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;


int main(){
  long  j, k, i, l,m, n, t, M, N, len, index;
  long A, B, lay, num, C, PD, penalty, PG, T, S, p, score, flag;
  //  string temp, order,  current;
  double pr, temans;
  vector <double> prob, answ, corr;
  vector <string>  dictionary, dict;
  cin >> T;   


  for(t = 0; t<T; t++) {
    cin >> A >> B;
    //   cout<<"haha here A B "<<A <<B<<endl;
    prob.clear();
    answ.clear();
    corr.clear();
    temans=1.0;
    corr.push_back(0);
    for (i = 0;i<A;i++){
      cin>>pr;
      prob.push_back(pr);
      temans=pr*temans;
      corr.push_back(temans);
      //     cout<<"corr is "<<corr[i]<<endl;
    }
    for (i=0;i<=A;i++){
      answ.push_back((double)(A-i)*1.0+1.0*((double)(B+1-i)+(1-corr[i])*(double)(B+1)));
    }
    answ.push_back(B+2);
 
    sort(answ.begin(),answ.end());
    cout.precision(8);
    cout << "Case #" << t+1 << ": ";    
    cout<<answ[0]<<endl;
  }
  return 0;
}

