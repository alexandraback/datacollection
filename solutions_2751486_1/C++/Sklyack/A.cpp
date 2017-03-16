#include <cstdio>
#include <cstring>

const int MAXLEN=1000000;
const char vowel[5]={'a', 'e', 'i', 'o', 'u'};
char S[MAXLEN+1];

bool is_cons(char c)
{
	int i;
	for(i=0; i<5; ++i)
		if(c==vowel[i])
			return false;
	return true;
}

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T, t;
	int len, n, i, prev, cnt;
	long long ans;

	scanf("%d", &T);
	for(t=1; t<=T; ++t)
	{
		scanf("%s%d", S, &n);
		len=strlen(S);
		ans=cnt=0;
		prev=-1;
		for(i=0; i<len; ++i)
		{
			is_cons(S[i]) ? ++cnt : cnt=0;
			if(cnt>=n)
				prev=i-n+1;
			if(prev>=0)
				ans+=prev+1;
		}
		printf("Case #%d: %lld\n", t, ans);
	}
	return 0;
}
