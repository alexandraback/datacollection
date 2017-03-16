#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<sstream>
using namespace std;
char ent[12345];
bool comp(char c, string s){
  stringstream ss;
  string tmp;
 ss << c;
 ss >> tmp;
  return c+s > s+c;
}
int main(){
  int tt=1;
  scanf("%d",&tt);
  for(int rr=1;rr<=tt;rr++){
    scanf(" %s",ent);
    string ret;
    for(int i=0;i<(int)strlen(ent);i++){
      if (comp(ent[i],ret)){
	ret = ent[i] + ret;
      }
      else{
	ret = ret + ent[i];
      }
    }
    printf("Case #%d: %s\n",rr,ret.c_str());
  }

  return 0;
}
