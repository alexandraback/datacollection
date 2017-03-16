#include<iostream>
using namespace std;
int nosupc[]={0,1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,9,9,9,10,10,10};
int supc[]={0,1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,9,9,9,10,10,10,11,11,11};

int isnonsup(int n,int max){
  if(max<=1){
    return n>=max;
  }
  return (3*(max-1)+1)<=n;
  //  return nosupc[n]>=max;
}

int issup(int n,int max){
  if(max<=2)
    return supc[n]>=max;
  return (3*(max-2)+2)<=n;
  //  return supc[n]>=max;
}

int main(){
  int no_of_cases;
  cin>>no_of_cases;
  int k=1;
  while(no_of_cases){
    int count=0;
    no_of_cases--;
    int no,sup,max,score;

    cin>>no>>sup>>max;

    for(int i=0;i<no;i++){
      cin>>score;
      if(isnonsup(score,max)){
	count++;
	continue;
      }
      if(sup&&issup(score,max)){
	count++;
	sup--;
      }
    }
    cout<<"Case #"<<k<<": "<<count<<"\n";
    k++;
  }
  return 0;
}
