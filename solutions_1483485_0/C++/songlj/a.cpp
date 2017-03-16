#include <iostream>
#include <stdio.h>
#include <string.h>
//#include <time.h>
//#include <stdlib.h>
//#include <math.h>
//#include <queue>
//#include <vector>
//#include <stack>
//#include <set>
//#include <map>
//#include <algorithm>
//#include <sstream>
using namespace std;

const int maxn=105;

char s[maxn];
char a[maxn];

int main() {
	strcpy(a,"yhesocvxduiglbkrztnwjpfmaq");
	int T,kase=0;
	cin>>T;
	gets(s);
	while (T--) {
		gets(s);
		printf("Case #%d: ",++kase);
		for (int i=0;s[i];i++)
			if (s[i]==' ') cout<<" ";
			else cout<<a[s[i]-'a'];
		cout<<endl;
	}
        return 0;
}

