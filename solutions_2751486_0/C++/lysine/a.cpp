#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long

using namespace std;

int cs,n,len,a[1000010];
string str;
char v[] = {'a','e','i','o','u'};

int main(){
  cin>>cs;
  rep(ii,cs){
    ll ret = 0;
    int l=0,r=0,cnt=0,fst=-1;
    cin>>str>>n;len = str.size();
    rep(i,len){
      a[i] = 1;
      rep(j,5)if(str[i]==v[j])a[i]=0;
    }
    while(l<len){
      while(cnt<n && r<len){
	if(a[r]==0){fst=r;cnt=0;}
	else cnt++;
	r++;
      }
      if(cnt<n && r==len)break;

      ret += (ll)len-r+1;
      if(l==fst+1){
	cnt--;
	fst++;
      }
      l++;
    }
    cout<<"Case #"<<ii+1<<": "<<ret<<endl;
  }

}
