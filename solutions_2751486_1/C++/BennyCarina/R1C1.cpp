#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<string>
using namespace std;



long long get(string &buf,int n){
	int l=buf.length(),tmp1=-1,tmp2=0;
	long long ans=0;
	for(int i=0;i<l;i++){
		if(buf[i]=='a' || buf[i]=='e' || buf[i]=='i' ||buf[i]=='o' ||buf[i]=='u'){
			tmp2=0;
			if(tmp1>-1){
			   ans+=tmp1+1;
			}
		}
		else{
			tmp2++;
			if(tmp2>=n){
			   tmp1=i-n+1;
			}
			if(tmp1>-1){
			    ans+=tmp1+1;
			}
		}
	}
	return ans;
}



int main(){
	freopen("input.in","r",stdin);
	freopen("output.txt","w",stdout);
	int T,n;
	long long ans;
	string read;
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>read;
		cin>>n;
                //solution
		ans=get(read,n);
		printf("Case #%d: %I64d\n",i,ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}