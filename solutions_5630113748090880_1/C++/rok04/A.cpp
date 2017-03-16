#include<bits/stdc++.h>
using namespace std;
  bool consoleinput=false;




int main()
{
   if(consoleinput==false){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
}
int t;
cin>>t;
for(int tt=1;tt<=t;tt++){
	   cout<<"Case #"<<tt<<": "    ;
       int n;
	   cin>>n;
int hash[2600]={0};
	   int arr[100][100];
	      for(int i=0;i<2*n-1;i++)
		  { for(int j=0;j<n;j++)
			 {
cin>>arr[i][j];
		    hash[arr[i][j]]++; }


		  }

			for(int i=0;i<=2500;i++)
			{
				if(hash[i]%2){
				cout<<i<<" ";}
			}
  cout<<endl;


	}
}







