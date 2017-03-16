#include<stdio.h>
#include<string.h>
typedef long long int ll;
char str[100000];
int modulo = 1000000007 ;
int visited[26],input[26][26],dfsval;
ll fact[150];
int f(int c)
{
	return (int)(str[c]-'a');
}
void print_im(int x)
{
	printf("Case #%d: 0\n",x);
}
void dfs(int s)
{
	if ( dfsval==0 )	return;
	visited[s]=1;
	for(int i=0;i<26;i++){
		if(s==i)	continue;
		if(input[s][i]>0){
			if(visited[i]==1){
				dfsval=0;
			}
			dfs(i);
		}
	}
}
void dfs_un(int s)
{
//	printf("%c is visited\n",'a'+s);
	visited[s]=1;
	for(int i=0;i<26;i++){
                if(s==i)        continue;
                if(input[s][i]>0){
                        if(visited[i]==0)	dfs_un(i);
                }
		if(input[i][s]>0){
                        if(visited[i]==0)	dfs_un(i);
		}
        }
}
void solve(int ca)
{
	ll ans=1;
	int N;
	int edges[26],between[26],s,e,in[26],out[26];
	int len,x;
	memset(input,0,sizeof(input));
	memset(edges,0,sizeof(edges));
	memset(between,0,sizeof(between));
	memset(in,0,sizeof(in));
	memset(out,0,sizeof(out));
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		scanf("%s",str);
		len=strlen(str);
		if(len==1){
			edges[f(0)]++;
			input[f(0)][f(0)]++;
			continue;
		}
		s=0;
		e=len-1;
		while(str[s]==str[0]){
			s++;
			if(s==len)	break;
		}
		while(str[e]==str[len-1]){
			e--;
			if(e<0)	break;
		}	
		for(int i=s;i<=e;i++){
			x=i;
			while(str[i]==str[x]){
				x++;
				if(x>e)	break;
			}
			i=x-1;
			between[f(i)]++;
		}
		input[f(0)][f(len-1)]++;
		edges[f(0)]++;
		edges[f(len-1)]++;
	}
	//for(int i=0;i<5;i++)	printf("%d %d\n",between[i],edges[i]);
	for(int i=0;i<26;i++){
		if(between[i]>1 || (between[i]>0 && edges[i]>0) ){
		 	print_im(ca);
			return;
		}
	}
	for(int i=0;i<26;i++)	ans = (ans * fact[input[i][i]])%modulo;
	for(int i=0;i<26;i++){	
		dfsval=1;
		memset(visited,0,sizeof(visited));
		dfs(i);
		if(dfsval==0){
			print_im(ca);
			return;
		}
	}
	for(int i=0;i<26;i++){        
                for(int j=0;j<26;j++){  
                        if(i==j)        continue;
			if(input[i][j]>1){
				print_im(ca);
				return;
			}
                        if(input[i][j]) out[i]++,in[j]++;
                }
        }
        for(int i=0;i<26;i++){
                if(in[i]>1  || out[i]>1){
                        print_im(ca);
                        return;
                }
        }
	memset(visited,0,sizeof(visited));
	int comp=0;
	for(int i=0;i<26;i++){
		if(visited[i]==0){
			for(int j=0;j<26;j++){
				if(input[i][j]>0){
					//printf("%c\n",'a'+i);
					dfs_un(i);
					comp++;
					break;
				}
			}
		}
	}
	//printf("%lld ans bewfore\n",ans);
	ans= (ans*fact[comp])%modulo;
	//printf("%d %lld\n",comp,ans);
	printf("Case #%d: %lld\n",ca,ans);
	/*for(int i=0;i<26;i++){	
		for(int j=0;j<26;j++){	
			if(i==j)	continue;
			if(input[i][j])	degree[i]++,degree[j]++;
		}
	}
	for(int i=0;i<26;i++){
		if(degree[i]>1){
			print_im(ca);
			return;
		}
	}*/
	//Finding Total Components
}
int main()
{
	fact[0]=1;
	for(int i=1;i<=120;i++){
		fact[i]=(fact[i-1]*(ll)i);
		fact[i]%=modulo;
	}
	int test;
	scanf("%d",&test);
	for(int i=1;i<=test;i++){	
		solve(i);
	}
}
