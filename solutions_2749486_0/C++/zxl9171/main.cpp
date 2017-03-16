#include <iostream>
using namespace std;
#include <cstdio>
int main() {
    freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	int T;
	cin>>T;
	for (int i = 1; i <= T; i++) {
        int x, y;
        char a, b;
        cin>>x>>y;
        cout<<"Case #"<<i<<": ";
        if (x > 0) {
            a='W';
            b='E';
        }
        else {
            a='E';
            b='W';
            x = -x;
        }
        for (int j = 0; j < x; j++) {
            cout<<a<<b;
        }
        if (y > 0) {
            a='S';
            b='N';
        } else {
            a='N';
            b='S';
            y = -y;
        }
        for (int j= 0; j < y; j++) {
            cout<<a<<b;
        }
        cout<<endl;

	}
	return 0;
}

