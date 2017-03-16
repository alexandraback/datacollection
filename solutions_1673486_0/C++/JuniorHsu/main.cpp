#include<iostream>
#include<cstdio>
#include<fstream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<sstream>
#include<string>
#include<iterator>
#include<time.h>
#include<iomanip>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define INF 100000000000000000LL

int main()
{
  fstream input,output;
  //input.open("test.in",ios::in); output.open("test.out",ios::out);
  input.open("A-small-attempt2.in",ios::in); output.open("A-small-0.out",ios::out);
  //input.open("A-large-0.in",ios::in); output.open("A-large-0.out",ios::out);
  
  
  int case_id,total_case,temp;
  ld a,b,p[100001],d[100001],u[100001],ans,cor,err;
  
  input>>total_case;  
  
  int i,j,k;
  for(case_id=1;case_id<=total_case;case_id++)
  { 
    input>>a>>b;
    for(i=1;i<=a;i++) input>>p[i];
    
    d[0]=1.0;
    u[0]=2.0+b;
    
    //d for success
    
    cor = a+b-1.0;
    
    for(i=1;i<=a;i++){
		d[i]=d[i-1]*p[i];
		
		u[i]= d[i]*(cor) + (1.0-d[i])*(cor+b+1.0);
		
		cor = cor - 2.0;
	}
    
    /*cout<<case_id<<endl;
    for(i=0;i<=a;i++)
    {
		cout<<i<<" "<<u[i]<<endl;
	}
	cout<<endl;*/
    
    ans = u[0];
    
    for(i=1;i<=a;i++){
		if(u[i]<ans) ans = u[i];
	}
    //output<<"Case #"<<case_id<<": ";
	//output<<ans;
	//output<<endl;
	
	printf("Case #%d: %.7Lf\n",case_id,ans);
  }
  

  return 0;
}
