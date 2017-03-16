#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

bool num[10];

int main(){
  freopen("a.in","r",stdin);
  freopen("a.out","w",stdout);

  int T;
  cin>>T;
  for(int tt=0; tt<T; tt++){
    printf("Case #%d: ",tt+1);
    int n;
    cin>>n;

    if (n==0)
      cout<<"INSOMNIA\n";
    else{

      int cnt=0;
      long long now=0;
      memset(num,0,sizeof num);
      for(;;){
        cnt++;
        now+=n;
        if (cnt>1e9){       
          cout<<"INSOMNIA\n";
          break;
        }
        stringstream O;
        O<<now;
        string s;
        O>>s;
        for(int i=0; i<s.size(); i++)
          num[s[i]-'0']=1;
        int ret=0;
        for(int i=0; i<10; i++)
          ret+=num[i];
        if (ret==10){
          cout<<now<<endl;
          break;
        }
      }

    }

  }

  return 0;
}
