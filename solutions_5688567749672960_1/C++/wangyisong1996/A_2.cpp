#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

#define if if (
#define then )
#define do )
#define for for (
#define while while (
#define begin {
#define end }

inline void solve()
begin
	long long n;
	scanf("%lld",&n);
	long long ans=0;
	while 1 do begin
		char s[20];
		sprintf(s,"%lld",n);
		int len=strlen(s);
		if len==1 then break;
		int t=(len+1)/2;
		int i;
		for i=1;i<=t;i++ do begin
			s[len-i]='0';
		end;
		s[len-1]='1';
		long long m=atoi(s);
		if n<m then begin
			--n;
			++ans;
			continue;
		end;
		std::reverse(s,s+len);
		ans+=n-m;
		if m!=atoi(s) then ++ans;
		s[0]='0';
		m=atoi(s);
		ans+=m+1;
		s[0]='1';
		n=atoi(s)-m-1;
	end;
	ans+=n;
	printf("%lld\n",ans);
end;

int main()
begin
	int T;
	scanf("%d",&T);
	int i;
	for i=1;i<=T;i++ do begin
		printf("Case #%d: ",i);
		solve();
	end;
end