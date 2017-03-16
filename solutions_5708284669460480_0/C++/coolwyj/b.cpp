#define _CRT_SECURE_NO_DEPRECATE
//#include <stdio.h>
//#include <iostream>
//#include <string.h>
//#include <map>
//using namespace std;
//map <char,int> mp;
//int nxt[105];
//char pat[105];
//char bet[105];
//
//void getNext(char pat[],int nxt[])
//{
//    int plen = strlen(pat);
//    int j=0,k=-1;
//    nxt[0] = -1;
//    while(j < plen)
//    {
//        if(k == -1 || pat[k] == pat[j])
//        {
//            ++k;    ++j;
//            nxt[j] = k;
//            /*
//             * nxt数组的优化，因为当pat[j]!=pat[k]时，如果pat[nxt[j]] == pat[j]那么必然失配
//             * 但是在利用nxt数组求最长公共前后缀时不要加此优化
//            if(pat[k] != pat[j])
//                nxt[j] = k;
//            else
//                nxt[j] = nxt[k]
//             */
//        }
//        else//相当于在前缀中递归寻找更小的前缀看是否可以匹配
//            k = nxt[k];
//    }
//}
//
//int main() {
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
//    int T,cas=1;
//	scanf("%d", &T);
//    while (T --) {
//		mp.clear();
//		int k,s,l;
//		scanf("%d%d%d",&k,&l,&s);
//		scanf("%s",bet);
//		for(int i=0;i<k;++i)
//		{
//			mp[bet[i]]++;
//		}
//		scanf("%s",pat);
//		bool isok = true;
//		for(int i=0;i<l;++i)
//		{
//			if(mp.find(pat[i]) == mp.end())
//				isok = false;
//		}
//		printf("Case #%d: ",cas++);
//		if(!isok)
//		{
//			printf("%.7f\n",0);
//		}
//		else
//		{
//			getNext(pat,nxt);
//			int mx = nxt[l-1];
//			int rep = (s-l) / (l-mx-1);
//			double expect = 0.0;
//			for(int i=0;i<l;++i)
//			{
//				expect += 1.0*mp[bat[i]] / k;
//			}
//			if(s == l)
//				printf("%.7f\n",(double)rep - expect);
//			else
//			{
//				double tmp = 0.0;
//				for(int i=l-mx;i<l;++i)
//				{
//					tmp += 1.0*mp[pat[i]] / k;
//				}
//				expect += tmp*rep;
//				printf("%.7f\n",(double)rep-expect);
//			}
//		}
//    }
//	fclose(stdout);
//	fclose(stdin);
//    return 0;
//}

#include<iostream>
#include<cstdio>
#include<queue>
#include<string>
using namespace std;
const int N=10;
char key[N];
char tar[N];
queue<string> q;
void gao(int k,int l,int s){
	q.push("");
	int ans=0;
	double _max=0;
	while(!q.empty()){
		string now=q.front();
		//cout<<now<<endl;
		q.pop();
		int len=now.length();
		if(len==s){
			int tmp=0;
			for(int i=0;i<=len-l;++i){
				int flag=1;
				for(int j=0;j<l;++j){
					if(now[i+j]!=tar[j]){
						flag=0;
						break;
					}
				}
				tmp+=flag;	
			}
			_max=max(double(tmp),_max);
			ans+=tmp;
		}
		//cout<<ans<<endl;
		if(len<s){
			for(int i=0;i<k;++i){
				q.push(now+key[i]);
			}
		}
	}
	double d=1;
	for(int i=0;i<s;++i){
		d*=k;
	}
	printf("%.7f\n",_max-(double)ans/d);
}
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int T;
	scanf("%d",&T);
	int cas=0;
	while(T--){
		int k,l,s;
		scanf("%d%d%d",&k,&l,&s);
		scanf("%s%s",key,tar);
		printf("Case #%d: ",++cas);
		gao(k,l,s);
	}
	fclose(stdout);
	fclose(stdin);
	return 0;
}