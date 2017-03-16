#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<stack>
#include<map>

#define LOOP(t,T) for(t=0; t< (T); t++)
#define LOOPT(t,T) for(t=1; t<= (T); t++)

using namespace std;


int main(){
  int T, i, j, k,t, l, answer;
  string names;
  int n, runs, ansi;
  long anss[100000];
  int last[100000];
  cin >> T;   
  LOOP(t,T) {
    cout << "Case #" << t+1 << ": ";    
    
    cin>>names>>n;
    
    LOOP(i,names.length()){
      if (names[i]=='a'||names[i]=='e'||names[i]=='i'||names[i]=='o'||names[i]=='u')
	names[i]='0';
      else
	names[i]='1';
    }
    runs=0;
    i=0;
    //  cout<<names<<endl;
    LOOP(i,names.length()){
      last[i]=-1;
      if (names[i]=='1'){
	runs++;
	if (runs>=n){
	  last[i]=i;
	}
	else if (i>0)
	  last[i]=last[i-1];
      }
      else{
	runs=0;
	if (i>0)
	  last[i]=last[i-1];
      }
      //     cout<<"last["<<i<<"] ="<<last[i]<<endl;
    }
      
    runs=0;
    i=0;
    anss[0]=0;
    if(names[i]=='0'){
      runs=0;
    }
    else{
      if (n==1)
	anss[i]=1;
      runs++;
    }
      

    
    
    LOOPT(i,names.length()-1){
      if (names[i]=='0'){
	anss[i]=anss[i-1];
	runs=0;
      }
      else{
	runs++;
	if (runs<n){
	  anss[i]=anss[i-1];
	}
	if (runs>n){
	  anss[i]=anss[i-1]+1;
	}
	if (runs==n){
	  if(last[i-1]==-1){
	    anss[i]=anss[i-1]+(i-n+2);
	  }
	  else{
	    anss[i]=anss[i-1]+(i-last[i-1]);
	  }
	}
      }
      //   cout<<"anss["<<i<<"] = "<<anss[i]<<endl;
    }
    answer=0;
    LOOP(i,names.length())
      answer+=anss[i];
    cout<<answer<<endl;
  }
  return 0;
      
}
  

