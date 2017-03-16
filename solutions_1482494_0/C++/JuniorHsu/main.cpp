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
  input.open("B-small-attempt1.in",ios::in); output.open("B-small-0.out",ios::out);
  //input.open("B-large.in",ios::in); output.open("B-large-0.out",ios::out);
  
  
  int case_id,total_case,temp,ans,max;
  int n,l[1001][3],have;
  bool u[1001][3];
  
  input>>total_case;  
  
  int i,j,k;
  for(case_id=1;case_id<=total_case;case_id++)
  { 
	  input>>n;
	  for(i=1;i<=n;i++) {
		  input>>l[i][1]>>l[i][2];
		u[i][1]=false;
		u[i][2]=false;
	  }
  
		cout<<"!!!!!!!!!!"<<case_id<<endl;
	  ans=0;
	  have=0;
	  while(have<2*n){
		  for(i=1;i<=n;i++){
			  if(l[i][2]<=have && u[i][2]==false){
				  u[i][2]=true; 
				  					  cout<<"u"<<i<<","<<2<<endl;
				  have++;
				  
				  if(u[i][1]==false)
				  {
					  u[i][1]=true; 
					  have++;
					  cout<<"u"<<i<<","<<1<<endl;
				  }
				  i=0;
				  ans++;
			  }
		  }
		  
		  cout<<have<<endl;
		  max=-1;
		  for(i=1;i<=n;i++){
			  if(l[i][1]<=have && u[i][1]==false && l[i][2]>max){
				  max=l[i][2];
				  temp=i;
			  }
		  }
		  
		  if(max!=-1){
			  have++;
			  u[temp][1]=true;
			  ans++;
			  cout<<"u"<<temp<<","<<111<<endl;
		  }
		  
		  if(max==-1 && have!=2*n){
			  ans=-1;
			  break;
		  }
		  		  cout<<have<<endl;
	  }
		
		cout<<have<<endl<<endl;
	  output<<"Case #"<<case_id<<": ";
	  if(ans!=-1) output<<ans;
	  else output<<"Too Bad";
	  output<<endl;
  }
  

  return 0;
}
