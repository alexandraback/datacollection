#include<iostream>
using namespace std;

int countpal(int a,int m,int n){
  int radix=1,tempa=a;
  while(tempa>=10){
    radix*=10;
    tempa/=10;
  }
  //  cout<<"radix="<<radix<<"\n";
  int x=a,count=0;
  do{
    int now=x/10+(x%10*radix);
    if(now>a&&now<=n&&now>=m){
      //      cout<<"("<<a<<","<<now<<")\n";
      count++;
    }
    x=now;
    //    cout<<x<<"\n";
  }while(x!=a);
  return count;
}

int main(){
  int no_of_case,a,b;

  cin>>no_of_case;
  int k=1;
  while(no_of_case){
    no_of_case--;
    cin>>a>>b;
    int count=0;
    for(int i=a;i<=b;i++){
      count+=countpal(i,a,b);
    }
    cout<<"Case #"<<k<<": "<<count<<"\n";
    k++;
  }

  return 0;
}
