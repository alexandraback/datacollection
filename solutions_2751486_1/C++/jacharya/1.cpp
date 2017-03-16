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
  long T, i, j, k,t, l, answer, a, b;
  string names;
  long n, runs, ansi;
  int last[1000000];
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
    a=0;
    
    if(names[i]=='0'){
      runs=0;
    }
    else{
      if (n==1)
	a=1;
      runs++;
    }
    
    answer = a;
    LOOPT(i,names.length()-1){
      if (names[i]=='0'){
	runs=0;
      }
      else{
	runs++;
	if (runs>n){
	  a=a+1;
	}
	if (runs==n){
	  if(last[i-1]==-1){
	    a=a+(i-n+2);
	  }
	  else{
	    a=a+(i-last[i-1]);
	  }	  
	}
	
	//   cout<<"anss["<<i<<"] = "<<anss[i]<<endl;
      }
      answer+=a;
    }
    cout<<answer<<endl;
  }
  return 0;
  
}
  

