#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

int main()
{
  static string S[100000];
  queue<string> Q;
  Q.push("1");
  Q.push("2");
  Q.push("3");
  int K=0;
  while(!Q.empty()){
    string s=Q.front();
    Q.pop();
    string p=s;
    for(int i=0;i<s.size()-1;i++){
      p.push_back(s[s.size()-i-2]);
    }
    for(int i=0;i<=100;i++){
      S[K]+='0';
    }
    for(int i=0;i<p.size();i++){
      for(int j=0;j<p.size();j++){
	S[K][100-(i+j)]+=(p[i]-'0')*(p[j]-'0');
      }
    }
    K++;
    int g=0;
    for(int i=0;i<s.size();i++){
      g+=(s[i]-'0')*(s[i]-'0');
    }
    if(2*g<10){
      p=s;
      for(int i=0;i<s.size();i++){
	p.push_back(s[s.size()-i-1]);
      }
      for(int i=0;i<=100;i++){
	S[K]+='0';
      }
      for(int i=0;i<p.size();i++){
	for(int j=0;j<p.size();j++){
	  S[K][100-(i+j)]+=(p[i]-'0')*(p[j]-'0');
	}
      }
      K++;
    }
    if(s.size()==25){
      continue;
    }
    for(int k=0;k<3;k++){
      if(2*g+k*k<10){
	string N=s+(char)('0'+k);
	Q.push(N);
      }
    }
  }
  sort(S,S+K);
  /*for(int i=0;i<10;i++){
    printf("%s\n",S[i].c_str());
    }*/
  int t;
  scanf("%d",&t);
  for(int C=1;C<=t;C++){
    char A[200],B[200];
    scanf("%s%s",A,B);
    int a=strlen(A),b=strlen(B);
    string sa,sb;
    for(int i=100;i>=a;i--){
      sa+='0';
    }
    for(int i=0;i<a;i++){
      sa+=A[i];
    }
    for(int i=100;i>=b;i--){
      sb+='0';
    }
    for(int i=0;i<b;i++){
      sb+=B[i];
    }
    int Ans=(upper_bound(S,S+K,sb)-S)-(lower_bound(S,S+K,sa)-S);
    printf("Case #%d: %d\n",C,Ans);
  }
  return 0;
}

