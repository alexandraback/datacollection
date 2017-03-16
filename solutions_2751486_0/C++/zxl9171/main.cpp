#include <iostream>
using namespace std;
int main()
{
    freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
    char a[101];
    int T;
    cin>>T;
    for (int i=1; i<=T; i++) {
        int n;
        cin>>a;
        cin>>n;
        char * start=a;
        char *end=a;
        int count=0;
        for (; *start!='\0'; start++) {
            for (end=start; *end!='\0'; end++) {
                int num=0;
                char *p=start;
                while (num<n&&p<=end) {
                    if (*p!='a'&&*p!='e'&&*p!='i'&&*p!='o'&&*p!='u') {
                        num++;
                    }
                    else num=0;
                    p++;
                }
                if (num==n) {
                    count++;
                }
            }
        }
        cout<<"Case #"<<i<<": "<<count<<endl;
        
    }
}