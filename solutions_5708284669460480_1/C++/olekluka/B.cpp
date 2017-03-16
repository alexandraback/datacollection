//Aleksander Łukasiewicz
#include<cstdio>
using namespace std;

const double EPS = 10e-7;

int counter[300];
char keyboard[1000], target[1000], word[1000];

int t;
double res;
int maks;
int k, len, s;

int prefiskosufiks(){
  for(int ret = len-1; ret >= 0; ret--){
    bool esc = true;
    for(int i=0; i<ret && esc; i++)
      if(target[i] != target[len-ret+1+i])
	esc = false;
    
    if(esc)
      return ret;
  }
}

int value(){
  int ret = 0;
  for(int i=0; i < s - len + 1; i++){
    bool esc = true;
    for(int j=0; j<len && esc; j++)
      if(word[i+j] != target[j])
	esc = false;
      
    if(esc)
      ret++;
  }
  
  return ret;
}

void generate(int ind, double prob){
  if(ind >= s){
    int val = value();
    res += (double)val*prob;
    if(maks < val)
      maks = val;
  }
  else{
    if(prob < EPS)
      return;
    for(int i='A'; i<='Z'; i++){
	if(counter[i] == 0)
	  continue;
	word[ind] = (char)i;
	generate(ind+1, prob*((double)counter[i])/((double)k));
    }
  }
}

int main(){
  scanf("%d", &t);
  for(int pp=1; pp<=t; pp++){
    for(int i=0; i<300; i++) counter[i] = 0;
    scanf("%d %d %d", &k, &len, &s);
    scanf("%s", keyboard);
    scanf("%s", target);
    
    for(int i=0; i<k; i++)
      counter[ keyboard[i] ]++;
    
    res = 0.0;
    maks = 0;
    
    generate(0, 1.0);
    maks = (s-prefiskosufiks())/(len - prefiskosufiks());
    printf("Case #%d: %.9lf\n", pp, (double)maks - res);
  }

return 0;
}