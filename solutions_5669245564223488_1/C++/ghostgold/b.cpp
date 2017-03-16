#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
using namespace std;
#define ll long long 
const int MOD = 1000000007;
void work();
int main()
{
  int T;
  scanf("%d", &T);
  for(int i = 1; i <=T; i++){
    printf("Case #%d: ",i);
    work();
  }
}

bool start(string &ss, char c){
  return ss[0]==c;
}

bool end(string & ss, char c){
  return ss[ss.size()-1]==c;
}
bool pure(string &ss, char c){
  for(int i =0; i < ss.size();i++){
    if(ss[i]!=c)
      return false;
  }
  return true;
}

string car[1000];
int chuan[100][200];
int lo[100],up[100];
int n;

ll frac(int x){
  ll res = 1;
  for(int i = 1; i <=x; i++){
    res*=i;
    res%=MOD;
  }
  return res;
}
void work()
{
  int tot=0;
  bool used[200]= {false};
  memset(used,false,sizeof(used));
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> car[i];


  for(int i =0; i < n; i++){
    if(!used[i]){
      used[i]=true;
      tot++;
      chuan[tot][100]=i;
      int pt = 100;
      char c = car[i][car[i].size()-1];
      while(true){
	bool find = false;

	for(int j = 0; j < n; j++){
	  if(pure(car[j],c) && !used[j]){
	    chuan[tot][++pt] = j;
	    used[j] = true;
	  }
	}

	for(int j = 0; j < n; j++){
	  if(!used[j] && start(car[j],c)){
	    chuan[tot][++pt] = j;
	    find = true;
	    used[j]=true;
	    c = car[j][car[j].size()-1];
	    break;
	  }
	}
	if(!find)
	  break;
      }
      up[tot] = pt;
      c = car[i][0];
      pt = 100;
      while(true){
	bool find = false;
	cerr << c << endl;
	for(int j = 0; j < n; j++){
	  if(pure(car[j],'i'))
	    cerr << used[j] << endl;
	  if(pure(car[j],c) && !used[j]){
	    chuan[tot][--pt] = j;
	    used[j] = true;
	  }
	}
	for(int j = 0; j < n; j++){
	  if(!used[j] && end(car[j],c)){
	    chuan[tot][--pt] = j;
	    used[j] = true;
	    find = true;
	    c = car[j][0];
	    break;
	  }
	}
	if(!find)
	  break;
      }
      lo[tot] = pt;
    }
  }
  int count[200]={0};
  int color[200]={0};
  int change = 0;
  for(int i = 1; i <=tot; i++){
    string s = "";
    for(int j = lo[i]; j <= up[i]; j++)
       s=s+car[chuan[i][j]];
    for(int j = 0; j < s.size()-1;j++){
      color[s[j]]=1;
      /*      if(count[s[j]] == 1){
	cout << 0 << endl;
	return;
	}*/
      if(s[j] != s[j+1]){
	count[s[j]] = 1;
	change++;
      }
    }
    color[s[s.size()-1]]=1;
    count[s[s.size()-1]] = 1;
  }
  int totc = 0;
  for(int i = 'a'; i <= 'z';i++){
    totc+=color[i];
  }
 ll ans= frac(tot);
    for(int i =1; i <=tot; i++){
    for(int j = lo[i]; j <=up[i];j++){
      cerr << car[chuan[i][j]] << ' ';
    }
    cerr << endl;
    }
  if(change +tot!=totc){
    cerr << change <<' ' << tot <<' '<<totc << endl;
    cout << 0 << endl;
    return;
  }
 
  for(int i = 1;i <= tot; i++){
    for(int j =lo[i]; j <= up[i]; j++){
      int k = chuan[i][j];
      if(pure(car[k], car[k][0])){
	char c = car[k][0];
	int tt=0;
	while(j<=up[i] && pure(car[chuan[i][j]],c) ) {
	  cerr << chuan[i][j] << ' ';
	  j++;
	  tt++;
	}
	cerr << tt << endl;
	ans*= frac(tt);
      }
    }
  }
  cout << ans << endl;
  
}
