#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;
int main()
{
  int T;
  int N;
  vector <int> a;
  vector <int> b;
  vector <int> flag;
  int i,j,k;
  int stars;
  int count;
  int temp;  
  int sum;
  int sumprevious;
  int check;
  int max;
  int jone;
  cin >> T;
  for(i=0;i<T;i++){
    cin >> N;
    count =0;
    stars =0;    
    sum=0;
    sumprevious=-1;
    for(j=0;j<N;j++){
      cin >> temp;
      a.push_back(temp);
      cin >> temp;
      b.push_back(temp);
      flag.push_back(0);
    }
    while(sum > sumprevious){
      sumprevious = sum;      
      jone = N;
      check =0;
	for(j=0;j<N;j++){
	  if(flag[j]<2 && b[j] <=sum){
	    sum = sum+2 - flag[j];
	    flag[j]=2;	    
	    count = count+1;
	    check =1;
	  }
	}
	max=0;
	for(j=0;j<N;j++){
	  if(flag[j]<1 && a[j] <= sum && check ==0){
	    if(b[j]>max){
	      max = b[j];
	      jone = j;
	    }
	  }
	}
	if(jone < N){
	   flag[jone]=1;
	   sum = sum+1;
	   count = count+1;
	}
    }
    if(sum==2*N){
    cout << "Case #" << i+1 << ": "<< count << endl;
    }
    if(sum < 2*N){
      cout << "Case #" << i+1 << ": "<< "Too Bad" << endl;
    }
    a.clear();
    b.clear();
    flag.clear();
  }
  return 0;
}