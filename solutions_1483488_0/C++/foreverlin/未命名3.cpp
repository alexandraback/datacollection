#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<cstdlib>
#include<cmath>
#include<sstream>
#include<numeric>
using namespace std;
int s1[1000],s2[1000],next[1000];
//即a[0,next[i]-1]=b[i-next[i]+1,i] 
void init(int *s,int len,int *next){
	int i,j;
	for(next[j=0]=0,i=1;i<len;i++){
		while(j>0&&s[j]!=s[i])j=next[j-1];
		if(s[i]==s[j])j++;
		next[i]=j;
		}
	}
int kmp(int *a,int *b,int lena,int lenb,int *next){//a模式串，b主串,返回匹配个数
	init(a,lena,next);
	int i,j=0,c=0;
    for(i=0;i<lenb;i++){              
        while(j>0&&a[j]!=b[i])j=next[j-1];                  
        if(a[j]==b[i])j++;
        if(j==lena){j=next[j-1];c++;}//找到匹配了                          
        }
    return c; 	
	} 
bool check(int n,int m){
	int l1=0,l2=0;
	for(int x=n;x;x/=10)s1[l1++]=x%10;
	for(int x=m;x;x/=10)s2[l2++]=x%10;
	for(int i=0;i<l2;i++)s2[i+l2]=s2[i];
	return kmp(s1,s2,l1,l2*2,next);
	}
int main(){
	int T,A,B;
	freopen("C-small-attempt0.in","r",stdin);
	freopen("out.txt","w",stdout);
	cin>>T;
	for(int ca=1;ca<=T;ca++){
		cin>>A>>B;
		int c=0;
		for(int i=A;i<=B;i++){
			for(int j=i+1;j<=B;j++){
				if(check(i,j))c++;
				}
			}
		cout<<"Case #"<<ca<<": "<<c<<endl;
		}
    return 0;
    }
