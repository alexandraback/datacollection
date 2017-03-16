#include<bits/stdc++.h>
using namespace std ;

int main(){

  freopen("A-large.in","r",stdin);
  freopen("A-large.out","w",stdout);
  int cases,caseno=1 ;
  cin >> cases ;
  while( cases -- ){
    string s ;
    cin >> s ;
    map<char,int>mp ;
    for( char ch = 'A' ; ch <= 'Z' ; ch ++ ){
      mp[ch] = 0 ;
    }
    for( int i = 0 ; i < s.size() ; i++ ){
      mp[s[i]]++ ;
    }
    //0
    int arr[10] ;
    memset( arr , 0 , sizeof arr ) ;

    if( mp['Z'] > 0 ){
      int k = mp['Z'] ;
      arr[0]=k ;
      for( int i = 0 ; i < k ; i++ ){
        mp['Z']--;
        mp['E']--;
        mp['R']--;
        mp['O']--;
      }
    }
    //2
    if( mp['W'] > 0 ){
      int k = mp['W'] ;
      arr[2]=k ;
      for( int i = 0 ; i < k ; i++ ){
        mp['T']--;
        mp['W']--;
        mp['O']--;
      }
    }
    //4
    if( mp['U'] > 0 ){
      int k = mp['U'] ;
      arr[4]=k ;
      for( int i = 0 ; i < k ; i++ ){
        mp['F']--;
        mp['O']--;
        mp['U']--;
        mp['R']--;
      }
    }
    //6
    if( mp['X'] > 0 ){
      int k = mp['X'] ;
      arr[6]=k ;
      for( int i = 0 ; i < k ; i++ ){
        mp['S']--;
        mp['I']--;
        mp['X']--;
      }
    }
    //8
    if( mp['G'] > 0 ){
      int k = mp['G'] ;
      arr[8]=k ;
      for( int i = 0 ; i < k ; i++ ){
        mp['E']--;
        mp['I']--;
        mp['G']--;
        mp['H']--;
        mp['T']--;
      }
    }
    //3
    if( mp['H'] > 0 ){
      int k = mp['H'] ;
      arr[3]=k ;
      for( int i = 0 ; i < k ; i++ ){
        mp['T']--;
        mp['H']--;
        mp['R']--;
        mp['E']--;
        mp['E']--;
      }
    }
    //1
    if( mp['O'] > 0 ){
      int k = mp['O'] ;
      arr[1]=k ;
      for( int i = 0 ; i < k ; i++ ){
        mp['O']--;
        mp['N']--;
        mp['E']--;
      }
    }
    //5
    if( mp['F'] > 0 ){
      int k = mp['F'] ;
      arr[5]=k ;
      for( int i = 0 ; i < k ; i++ ){
        mp['F']--;
        mp['I']--;
        mp['V']--;
        mp['E']--;
      }
    }
    //7
    if( mp['S'] > 0 ){
      int k = mp['S'] ;
      arr[7]=k ;
      for( int i = 0 ; i < k ; i++ ){
        mp['S']--;
        mp['E']--;
        mp['V']--;
        mp['E']--;
        mp['N']--;
      }
    }
    //9
    if( mp['N'] > 0 ){
      int k = mp['N']/2 ;
      arr[9]=k ;
      for( int i = 0 ; i < k ; i++ ){
        mp['N']--;
        mp['I']--;
        mp['N']--;
        mp['E']--;
      }
    }
    cout << "Case #" << caseno++ << ": " ;
    for( int i = 0 ; i < 10 ; i++ ){
      if( arr[i] > 0 ){
        for(int j = 0 ; j < arr[i] ; j++ ){
          cout << i ;
        }
      }
    }cout << "\n" ;

  }

  return 0 ;
}
