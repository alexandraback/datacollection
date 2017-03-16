#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int main(){
	int tc;
	int l=1;
	scanf("%d",&tc);
	while(tc--){
		string s;
		cin >> s;
		long int n;
		scanf("%ld",&n);
		int i;
		long int num=0;
	long long unsigned int count=0;
		int st=0;
		int shu;
		for(i=0;i < s.length();i++){
			if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
				num=0;
			}
			else{
				if(num==0){
					shu=i;
				}
				num++;
			}
			if(num >= n){
			//printf("st = %d ,shu=%d ,end= %d\n",st,shu,i);
			count=count+((shu-st)*(s.length()-i))+(s.length()-i);
			st=shu+1;
			num--;
			shu=shu+1;
			}
			}
			printf("Case #%d: %llu\n",l,count);
			l++;
			}
			return 0;
			}



