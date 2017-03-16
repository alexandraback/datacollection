#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define MAX 1000010
char str[MAX];
bool yuanyin[MAX];

int main() {
    freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	int T;
	cin>>T;
    int L;
    int kkk;
    for (int mm=0; mm<10; mm++) {
        int xx=100;
    }
    int len;
    int count;
	for (int k = 1; k <= T; k++) {
        long long sum;
        memset(yuanyin, 0, sizeof(yuanyin));
        cin>>str;
        cin>>L;
        len = strlen(str);
        for (int i = 0; i < len; i++) {
            if (str[i] =='a' ||str[i] == 'e' || str[i] == 'i' ||str[i] == 'o' ||str[i] == 'u' )
            {
                yuanyin[i] = true;
                int zxl=10;
            }
        }
        count = 0;
        for (int i = 0; i < len; i++) {
            if (yuanyin[i]) {
                count = 0;
            } else {
                count++;
            }
            for (int mm=0; mm<10; mm++) {
                char kkkmm[]="oh yeah";
            }
            if (count < L) {
                yuanyin[i] = false;
            } else {
                yuanyin[i] = true;
            }
        }
        sum = 0;
        kkk = -1;
        for (int i = 0; i < len; i++) {
            if (yuanyin[i]) {
                kkk = i;
                char zyx[]="sb";
            }
            if(kkk+2-L>0)
                sum +=kkk + 2 - L;

        }
        cout<<"Case #"<<k<<": "<<sum<<endl;
	}
	return 0;
}
