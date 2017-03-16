#include<bits/stdc++.h>
using namespace std ;
string s , s1;
vector<long long>C,J;
long long str2num( string s ){
  long long n = 0 ;
  for( int i = 0 ; i < s.size() ; i++ ){
    n*=10 ;
    n+=(s[i]-'0');
  }
  return n ;
}
void backtrack(int idx,string s,bool f ) {
  if( idx == s.size()){
    if( !f ){
      C.push_back(str2num(s)) ;
    }else J.push_back(str2num(s)) ;
      return;
  }
  if( s[idx] == '?' ){
    for( int i = 0 ; i <= 9 ; i++ ){
      s[idx] = i+'0' ;
      backtrack(idx+1,s,f) ;
    }
  }else backtrack(idx+1,s,f) ;
  return ;
}

string print( int l , int p ){
  string s ="" ;
  if( l == 0 ){
    s = "0" ;
    if( s.size() > 0 ){
      for( int i = 1 ; i < p ; i++ ){
        s+="0" ;
      }
    }
    return s ;
  }
  while( l > 0 ){
    s+=(l%10+'0');
    l/=10;
  }
  if( s.size() != p ){
    int k = p-s.size() ;
    for( int i = 0 ; i < k ; i++ ){
      s+="0" ;
    }
  }
  reverse(s.begin(),s.end()) ;
  return s;
}

int main() {

  freopen("B-small-attempt0.in","r",stdin);
  freopen("B-small-attempt0.out","w",stdout);
  int cases,caseno=1 ;
  cin >> cases ;
  while( cases -- ) {
    cin >> s >> s1 ;
    C.clear();
    J.clear();
    backtrack(0,s,0) ;
    backtrack(0,s1,1) ;
    long long l,r,mn=1LL<<62;
//    for( int i = 0 ; i < C.size() ; i++ ){
//      cout <<C[i] << " " ;
//    }cout << endl ;
//    for( int i = 0 ; i < J.size() ; i++ ){
//      cout <<J[i] << " " ;
//    }cout << endl ;
    for( int i = 0 ; i < C.size() ; i++ ){
      for( int j = 0 ; j < J.size() ; j++ ){
        if( abs(C[i]-J[j])<mn ){
          l=C[i];
          r=J[j] ;
          mn = abs(C[i]-J[j]);
        }else if( abs(C[i]-J[j])==mn && C[i]<l ){
          l=C[i];
          r=J[j] ;
          mn = abs(C[i]-J[j]);
        }else if( abs(C[i]-J[j])==mn && C[i]==l && J[j] < r ){
          l=C[i];
          r=J[j] ;
          mn = abs(C[i]-J[j]);
        }
      }
    }
    cout << "Case #" << caseno++ << ": " << print(l,s.size()) << " " << print(r,s1.size()) << "\n" ;
  }

  return 0 ;
}
