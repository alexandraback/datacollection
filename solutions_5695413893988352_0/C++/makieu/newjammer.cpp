#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

unsigned long long getval(string & s){
  unsigned long long v =0;
  for(unsigned int i=0;i<s.size();i++)
    v = v*10+(s[i]-'0');
  return v;
}
void fill( string& s1, string& s2, int pos, int diff){
  for(int i =0; i< s1.size() ;i++){
    if(s1[i]=='?' && s2[i]=='?'){
      if( i<pos || diff ==0){
        s1[i]=s2[i]='0';
      }else if(i==pos){
        if(diff ==1){
          s1[i]='1';
          s2[i]='0';
        }else if( diff ==-1){
          s1[i]='0';
          s2[i]='1';
        }
      }else if(i>pos){ 
        if(diff ==1){
          s1[i]='0';
          s2[i]='9';
        }else if( diff ==-1){
          s1[i]='9';
          s2[i]='0';
        }
      }
    }else if(s1[i]=='?'){
      if( i<pos || diff ==0){
        s1[i]=s2[i];
      }else if(i==pos){
        if(diff == 1){
          s1[i]=min((int)'9',s2[i]+1);
        }else if( diff ==-1){
          s1[i]=max((int)'0',s2[i]-1);
        }
      }else if(i>pos){ 
        if(diff ==1){
          s1[i]='0';
        }else if( diff ==-1){
          s1[i]='9';
        }
      }     
    }else if(s2[i]=='?'){
      if( i<pos || diff ==0){
        s2[i]=s1[i];
      }else if(i==pos){
        if(diff == 1){
          s2[i]=max((int)'0',s1[i]-1);
        }else if( diff ==-1){
          s2[i]=min((int)'9',s1[i]+1);
        }
      }else if(i>pos){ 
        if(diff ==1){
          s2[i]='9';
        }else if( diff ==-1){
          s2[i]='0';
        }
      }     
    }
  }
}

int main(){
  int nb;
  cin >>nb;
  for(int cases=0; cases<nb; cases++){
    cout << "Case #"<<cases+1<<": ";
    string jam, code;
    cin>>jam>>code; 
    unsigned long long bestval = 1000000000000000000;
    string bj, bc;
    for( int i=0;i<jam.size();i++){
      for(int diff =-1; diff<2 ;diff++){
        string tj(jam);
        string tc(code);
        fill( tj, tc, i, diff);
        unsigned long long sj = getval(tj);
        unsigned long long sc = getval(tc);
        unsigned long long absval =0;
        if( sj >sc) absval = sj-sc;
        else absval = sc-sj;
        if (absval< bestval){
          bestval = absval;
          bj = tj;
          bc = tc;
        } else if (absval == bestval && (tj<bj || (tj== bj && tc < bc))){
          bestval = absval;
          bj = tj;
          bc = tc;          
        }
      }     
    }
    cout<<bj <<" "<<bc<<endl;
  }
  return 0;
}
