#include<iostream>
#include<algorithm>
#include<functional>
#include<sstream>
#include<set>
#include<map>
using namespace std;

#define MAXN 502

int T, N;
long long s[MAXN];
bool found;
long long ans;
int ans_i;

int main()
{
	freopen("C-small-attempt0 (1).in", "r", stdin);
	freopen("out.txt", "w", stdout);
	scanf("%d\n", &T);
	for(int te=1;te<=T;++te)
	{
		printf("Case #%d:\n", te);
		cin>>N;
		set<long long> sum;
		map<long long, long long> pre;
		for(int i=0;i<N;++i)
		{
			cin>>s[i];
		}
		sort(s,s+N);
		sum.insert(0);
		found = false;

		for(int i=0;i<N&&!found;++i)
		{
			set<long long> sum2;
			for(set<long long>::iterator sit = sum.begin();sit!=sum.end();++sit)
			{
				long long tmp = *sit + s[i];
				if(sum.find(tmp)!=sum.end())
				{
					//found
					found = true;
					ans = tmp;
					ans_i = i;
					break;
				}
				else
				{
					pre[tmp]=*sit;
					sum2.insert(tmp);
				}
			}
			sum.insert(sum2.begin(), sum2.end());
		}

		if(!found)
		{
			cout<<"Impossible\n";
		}
		else
		{
			long long tmp = ans;
			while(1)
			{
				if(pre[tmp]!=0)
				{
					cout<<tmp-pre[tmp]<<' ';
					tmp=pre[tmp];
				}
				else
				{
					cout<<tmp<<endl;
					break;
				}
			}

			tmp = ans - s[ans_i];
			
			if(tmp>0)
			{
				while(1)
				{
					if(pre[tmp]!=0)
					{
						cout<<tmp-pre[tmp]<<' ';
						tmp=pre[tmp];
					}
					else
					{
						cout<<tmp<<' ';
						break;
					}
				}
			}
			cout<<s[ans_i]<<endl;
		}
	}
	return 0;
}
