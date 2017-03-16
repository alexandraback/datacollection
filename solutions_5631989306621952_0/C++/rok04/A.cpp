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
	string ss;
	cin>>ss;
	string ans="";
	ans=ss[0];
	  if(ss.size()>=1)
	for(int i=1;i<ss.size();i++){
		  if(ss[i]>=ans[0]){
			     string temp;
					temp=ss[i];
				    temp+=ans;
					ans=temp;

	        }
			else
			{
				ans+=ss[i];

			}
}
   cout<<ans<<endl;


	}
}




