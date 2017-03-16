#include <iostream>
using namespace std;
char map[]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r',/**/'z','t','n','w','j','p','f','m','a','q'};
int main()
{
	freopen("1.in","r",stdin);
	freopen("C:\\1.txt","w",stdout);
	int n;
	cin>>n;
	
	char str[1000];
	gets(str);
	for(int i=0;i<n;i++){
		gets(str);
		for(int i=0;str[i]!=0;i++)
			if(str[i]>='a'&&str[i]<='z')
				str[i]=map[str[i]-'a'];
		printf("Case #%d: %s\n",i+1,str);
	}


}