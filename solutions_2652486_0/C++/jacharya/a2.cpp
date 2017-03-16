#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

long pow(long a, long b);

long pow(long a, long b){
  long i=0, ans = 1;
  while(i<b){
    ans =ans*a;
    i++;
  }
  return ans;
}

int main(){
  long  j, k, i, l,m, A, B;
  long lay, num,maxm, C,N, M, R, K, T, S, p, a, flag;
  long stss[7], ans[10];
 
  cin >> T;
  j=0;
  k=0;
  
  for(i=0;i<T;i++){
    num=0;
    cout<<"Case #"<<i+1<<": \n";
    cin >>R>>N>>M>>K; 
    for (j=0;j<R;j++){
      for (k=0;k<K;k++)
	cin>>stss[k];
      
      maxm = 0;
      for (k=0;k<K;k++){
	if (maxm<stss[k])
	  maxm=stss[k];
      }
      num=0;
      while (maxm%3==0){
	ans[num]=3;
	maxm=maxm/3;
	num++;
      }
      
      while (maxm%5==0){
	ans[num]=5;
	maxm=maxm/5;
	num++;
      }
      
      if (num<3){
	//		cout<<"max and num are "<<maxm<<num<<"\n";
	l = 3-num;
	flag = 0;
	for (p=0;p<=l;p++){
	  if (pow(2,p)*pow(4,l-p)==maxm)
	    flag=p;
	}
	//		cout<<"p is "<<p<<"\n";
	
      }
      if (num<3){
	for (a=0;a<flag;a++)
	  ans[num+a]=2;
	for (a=flag;a<l;a++)
	  ans[num+a]=4;
      }
      
      for (a=0;a<3;a++)
	cout<<ans[a];
      cout<<"\n";
      
    }
    
  }	
  return 0;
}
