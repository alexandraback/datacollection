#include <iostream>
#include <cstdio>
#include <cstring>
#define MOD 1000000007LL
using namespace std;

char str[103][103];

long long inner[27];
long long lft[27];
long long rt[27];
long long both[27];
int to[27];
bool used[27];

int main(){
	freopen("I:\\gcj\\B-small-attempt0.in","r",stdin);
	freopen("I:\\gcj\\B-small-attempt0.out","w",stdout);
	int T,N,len,fromhead;
	cin>>T;
	for(int cs=1;cs<=T;++cs){
		int link=0;
		memset(inner,0,sizeof(inner));
		memset(lft,0,sizeof(lft));
		memset(rt,0,sizeof(rt));
		memset(both,0,sizeof(both));
		memset(used,0,sizeof(used));
		memset(to,-1,sizeof(to));
		cin>>N;
		for(int i=0;i<N;++i)
			scanf("%s",str[i]);
		for(int i=0;i<N;++i){
			len=strlen(str[i]);
			used[ str[i][0]-'a' ]=true;
			++lft[ str[i][0]-'a' ];
			fromhead=true;
			for(int j=1;j<len-1;++j){
				used[ str[i][j]-'a' ]=true;
				if(str[i][j]!=str[i][j-1]){
					fromhead=false;
					++link;
				}
				if( str[i][j]!=str[i][j+1]&&!fromhead )
					++inner[str[i][j]-'a'];
			}

			used[ str[i][len-1]-'a' ]=true;
			++rt[ str[i][len-1]-'a' ];

			if(str[i][len-1]==str[i][0]){
				if(fromhead){
					--lft[ str[i][0]-'a' ];
					--rt[ str[i][0]-'a' ];
					++both[ str[i][0]-'a' ];
				}else
					lft[str[i][0]-'a']=10;
			}else{
				to[ str[i][0]-'a' ]=str[i][len-1]-'a';
			}



			if(len>1&&str[i][len-1]!=str[i][len-2]){
				++link;
			}
		}

		bool myflag=true;
		for(int i=0;i<27;++i)
			if(inner[i]>1||lft[i]>1||rt[i]>1|| ( inner[i]&&(lft[i]||rt[i]) ))
				myflag=false;



		int visited[27];

		for(int i=0;i<27;++i){
			for(int i=0;i<27;++i)
				visited[i]=false;
			if(!visited[i]&&to[i]!=-1){
				visited[i]=true;
				int tmp=to[i];
				while(~tmp){
					if(visited[tmp]){
						myflag=false;
						goto hi;
					}
					visited[tmp]=true;
					tmp=to[tmp];
				}
			}
		}
		hi:

		int usesum=0;
		for(int i=0;i<27;++i)
			if(used[i])
				++usesum;

		cout<<"Case #"<<cs<<": ";
		if(myflag){
			long long res=1;

			int tmp=usesum-link;
			for(int i=1;i<=tmp;++i){
				res*=i;
				res%=MOD;
			}
			for(int i=0;i<27;++i)
				for(int j=1;j<=both[i];++j){
					res*=j;
					res%=MOD;
				}
			cout<<res<<endl;

		}else{
			cout<<0<<endl;
		}

	}
	return 0;
}
