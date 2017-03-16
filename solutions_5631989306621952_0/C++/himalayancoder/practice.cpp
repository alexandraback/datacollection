#include<bits/stdc++.h>
#define ll   long long

#define md 1000000007

using namespace std;
string st;
string ans;
void find(int s,int e,int f){
	if(e<s)
		return;
	if(f==1){
	for(int i=s;i<=e;i++)
		ans+=st[i];
	return;
	}
	char c=st[s];
	int id=s;
	for(int i=s+1;i<=e;i++){
		if(st[i]>=c){
			c=st[i];
			id=i;
		}
	}
	ans+=st[id];
	find(s,id-1,f);
	find(id+1,e,1);
}
int main()
{
	ios_base::sync_with_stdio(0);
   #ifndef ONLINE_JUDGE
            freopen("input.txt","r",stdin);
            freopen("output.txt","w",stdout);    
    #endif
      int test;
      cin>>test;
     for(int tst=1;tst<=test;tst++){
     	cout<<"Case #"<<tst<<": ";
     	cin>>st;
     	ans="";
     	find(0,st.length()-1,0);
     	
     	cout<<ans<<endl;
     	
     }
    return 0;  
}
