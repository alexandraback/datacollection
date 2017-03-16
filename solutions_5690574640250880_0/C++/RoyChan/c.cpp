#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<vector<char> > vv;
bool impossible;

void trytry(int rr, int cc, int m){
    int j,k;
    while(true){
      if (rr==1){
        vector<char> v(cc,'.');
        for (j=0; j<m; j++) v[j]='*';
        v[cc-1] = 'c';
        vv.push_back(v);
        break;
      } 
      if (rr==2){
        if ((rr*cc-4<m || m%2==1) && m!=rr*cc-1){
          impossible = true;
        }
        else{
          vector<char> v(cc,'.');
          vector<char> v1(cc,'.');
          int a,b;
          a=b=0;
          while(m>0){
            v[a++]='*';
            m--;
            if (m>0){
              v1[b++]='*';
              m--;
            }
          }
          v1[cc-1] = 'c';
          vv.push_back(v);
          vv.push_back(v1);
        }
        break;
      }
      if (m>=cc){
        vector<char> v(cc,'*');
        vv.push_back(v);
        m-=cc;
        rr--;
      }
      else{
        if (cc-1==m){
          impossible=true;
          break;
        }
        vector<char> v(cc,'.');
        for (j=0; j<m; j++){
          v[j]='*';
        }
        vv.push_back(v);
        for (j=1; j<rr; j++){
          vector<char> v(cc,'.');
          if (j==rr-1) v[cc-1]='c';
          vv.push_back(v);
        }
       break;
      }
    }  
    return;
}

int main(){
  int t,r,c,m,i,j,k,rr,cc,m1,m2;
  cin>>t;
  for (i=1; i<=t; i++){
    vv.clear();
    impossible = false;
    if (i>1) cout << endl;
    cout << "Case #" << i << ":" << endl;
    cin>>r>>c>>m;
    for (j=0; j<r; j++){
      vector<char> v(c,'.');
      vv.push_back(v);
    } 
    if (r*c==m+1){
      for(j=0; j<r; j++){
        for (k=0; k<c; k++){
          vv[j][k]='*';
        }
      }
      vv[r-1][c-1]='c';
    }
    else{
      rr = min(r,c);
      cc = max(r,c);
      if (rr==1){
        if (r==1){
          for (j=0; j<m; j++) vv[0][j]='*';
          vv[0][c-1] = 'c';
        }
        else{
          for (j=0; j<m; j++) vv[j][0]='*';
          vv[r-1][0] = 'c';
        } 
      }
      else if (rr==2){
        if (r*c-4<m || m%2==1){
          impossible = true;
        }
        else{
          int a,b;
          a=b=0;
          if (r==2){
            while(m>0){
              vv[0][a]='*';
              vv[1][a++]='*';
              m-=2;
            }
          }
          else{  
            while(m>0){
              vv[a][0]='*';
              vv[a++][1]='*';
              m-=2;
            }
          }
          vv[r-1][c-1] = 'c';
        }
      }
      else if(r*c-4<m){
        impossible=true;
      }
      else{
        int mr,mc;
        mr=mc=0;
        for (j=0; j<r-2 &&m>0; j++){
          for (k=0; k<c-2 && m>0; k++){
            vv[j][k]='*';
            m--;
          }
        }
        if (m>0 && m%2==1){
          if (m+1<=(r-3)*2+(c-3)*2){
            mr=1;
            mc=1;
            m++;
            vv[r-3][c-3]='.';
          }
          else{
            impossible=true;
          }
        }
        if (!impossible){
          if (c<r){
            m1=min((r-2-mr)*2,m);
            m2 = m-m1;
          }
          else{
            m2=min((c-2-mc)*2,m);
            m1 = m-m2;
          }

          for (j=0; j<r && m1>0; j++){
            vv[j][c-2]='*';
            vv[j][c-1]='*';
            m1-=2;
          }
          for (j=0; j<c && m2>0; j++){
            vv[r-2][j]='*';
            vv[r-1][j]='*';
            m2-=2;
          }
          vv[r-1][c-1]='c';
        } 
      } 
    } 
    if (impossible) cout<< "Impossible";
    else{
      for (j=0; j<vv.size(); j++){
        if (j>0) cout << endl;
        for (k=0; k<vv[j].size(); k++){
          cout<<vv[j][k];
        }
      }
    }
  }
  return 0;
}
