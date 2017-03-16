#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

#define LOOP(t,T) for(t=0; t< (T); t++)

using namespace std;


int main(){
  long  j, k, i, l,m, n, t, M, N, len, index;
  long lay, num, C, PD, penalty, PG, T, p, score, temp, flag;
  string order,  current;
  vector <string> wlength;
  vector <string>  dictionary, dict;
  long dist[50];
  vector <long> sums, sumsold;
  char lane[50];
  cin >> T;
  
  LOOP(t,T) {
    sums.clear();
    cin >> N ;
    LOOP(i,N){
      cin>>dist[i];
      //      cout << lane[i] << " " << S[i] << " " << P[i]<<endl; 
    }
    //    cout<<" hehe "<<endl;
    for (j=0;j<1048576;j++){
      k = j;
      temp = 0;
      for (l=0;l<20;l++){
	temp = temp + (k%2)*dist[l];
	k=k/2;
      }
      sums.push_back(temp);
    }
    sumsold=sums;

    //cout<< "Size of sums is "<<(int) sums.size()<<endl;
    sort (sums.begin(), sums.end());
    flag = 0;
    for (j=0;j<1048575;j++){
      if (sums[j]==sums[j+1]){
	score = sums[j];
	flag = 1;
	break;
      }
    }
    // cout<<"score is " <<score<<endl;
    index=0;
    if (flag ==1){
      cout << "Case #" << t+1 <<": "<< endl;    
      for (j=0;j<1048576&&index<2;j++){
	if (sumsold[j]==score){
	  k=j;
	  //	  cout<<"k is "<<k<<endl;
	  for (l=0;l<20;l++){
	    if (k%2==1){
	      cout<<dist[l]<<" ";
	    }
	      k=k/2;
	  }
	  index++;
	  cout<<endl;
	}
      }  
    }
    if (flag==0){
      cout << "Case #" << t+1 <<": "<<"\nImpossible"<<endl;
    }    
  }
  return 0;
}

