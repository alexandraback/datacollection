#include<iostream>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<cstdio>
using namespace std;

#define LL long long
#define PRIME 1000000007

LL factMod  (int k){
  LL an = 1;
  while (k>0){
    an*=k;
    an%=PRIME;
    k--;
  }
  return an;
}


int main (){
  int t;
  cin>>t;
  for (int te = 1; te <= t ; ++ te){
    int n;
    cin>>n;
    string str_[100];
    string str[100];
    for (int i=0;i<n;++i){
      cin>>str_[i];
      int sz = (int)str_[i].size();
      
      int cur = 0;
      for (int j=1;j<sz;++j){
	while (j < sz && (str_[i][cur] == str_[i][j]))j++;
	str[i].append(str_[i], cur, 1);
	cur = j;
      }
      str[i].append(str_[i], cur, 1);
    }
    
    int center_cnt [26] = {0};
    int right_cnt [26] = {0};
    int left_cnt [26] = {0};
    int single_cnt [26] = {0};

    for (int i=0;i<n;++i){
      if (str[i].size()==1){
	single_cnt [str[i][0] - 'a'] ++;
      }
      else{
	left_cnt [str[i][0] - 'a'] ++ ;
	right_cnt [str[i][str[i].size()-1] - 'a'] ++ ;
	for (int j=1;j<str[i].size()-1;++j){
	  center_cnt [str[i][j] - 'a'] ++;
	}
      }
    }



    bool flag = 1;
    for (int i=0;i<26;++i) {
      if (center_cnt[i] > 0 && ( (center_cnt[i] > 1) || (left_cnt[i] > 0) || (right_cnt[i] > 0)|| (single_cnt[i] > 0))){
	flag = 0;
	//	cerr<<"here1\n";
      }
      if ( (left_cnt[i] > 1) || (right_cnt[i] > 1) ){
	flag = 0;      
	cerr<<"here2\n";
      }
    }

    int in[100] ;
    int out[100] ;

    for (int i=0;i<n;++i){
      in[i] = -2;
      out[i] = -2;
      if (str[i].size() != 1 ){
	in[i] = -1;
	out[i] = -1;
      }
    }

    for (int i=0;i<n;++i){
      if (str[i].size() != 1 ){
	for (int j=0;j<n;++j){
	  if (str[j].size()!=1 && (str[i][str[i].size()-1] == str[j][0])){
	    if (i==j){
	      flag = 0;
	      cerr<<"here3\n";
	    }
	    else {
	      out[i] = j;
	      in[j] = i;
	      //	      break;
	    }
	  }
	}
      }
    }

    /*    for (int i=0;i<n;++i) {
      cout<<i<<" : "<<in[i]<<" "<<out[i]<<"\n";
      }*/

    for (int i=0;i<n;++i){
      int cur = i;
      if (out[cur] >= 0){
	cur = out[cur];
	while (out[cur] >= 0 && cur!=i)cur = out[cur];
	if (cur == i)flag = 0;
      }
    }

    int compMult = 0;
    for (int i=0;i<n;++i){
      if (str[i].size() != 1 && in[i] == -1)compMult ++;
    }

    //        if (te == 2)    for (int i=0;i<26;++i)cout<<i<<" : "<<single_cnt[i]<< " " <<center_cnt [i] << " "<<left_cnt[i]<<" "<<right_cnt [i] <<" \n";
    LL ans = 1;
    ans *= factMod (compMult);
    ans %= PRIME;
    for (int i=0;i<26;++i){
      ans *= factMod (single_cnt [i]);
      ans %= PRIME;
    }

    for (int i=0;i<26;++i){
      if (single_cnt [i] > 0){
	if ((left_cnt[i] == 0 ) && (right_cnt[i]  == 0)){
	  ans *= (compMult + 1);
	  ans %= PRIME;
	  compMult ++ ;
	}
      }
    }


    if (flag == 0){
      cout<<"Case #"<<te<<": "<<0<<"\n";
    }
    else {
      cout<<"Case #"<<te<<": "<<ans<<"\n";
    }
  }
  return 0;
}
