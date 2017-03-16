#include<stdio.h>
#include<string.h>
#include<string>
#include<vector>
using namespace std;

vector<string> vc;

#define MAX 105

char s[MAX];
int vowel(char x){
	string ss="aeiou";
	
	for(int i=0;i<ss.length();i++) if(x==ss[i]) return 1;
	return 0;
}


int main(){
	int n,t,i,add,ans,k,j,l,p=0,len;
	
	freopen("A-small-attempt1.in","r",stdin);
	freopen("output","w",stdout);
	scanf("%d",&t);
	string str;
	while(t--){
		scanf("%s%d",s,&n);
		//printf("%s %d\n",s,n);
		str="";
		ans=0;
		len=strlen(s);
		for(i=0;i<len;i++){
			for(j=i+n-1;j<len;j++){
				str="";
				for(k=i;k<=j;k++){
					str+=s[k];
				}
				
				add=0;
				for(l=0;l<str.length();l++){
					if(!vowel(str[l])) add++;
					else{
						if(add>=n){ans++;/*printf("%s\n",str.c_str());*/add=0;break;}
						add=0;
					}
				}
				if(add>=n){ans++;/*printf("%s\n",str.c_str());*/}
			}
		}
		
		printf("Case #%d: %d\n",++p,ans);
	}
	return 0;
}
