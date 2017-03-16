#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int main(int artc, char* argv[]) {

    int TIME;// number of test
    int answer;// Final answer
    int N;
    cin >> TIME;
    int ee[1000];
    int stat[1000];
    int star[2002];
    int l1[1000];
    int l2[1000];
    int tmp1,tmp2;
    int now;
    for (int t = 0 ; t < TIME; t++) {
	answer = 0;
	cin >> N;
	for (int i = 0 ; i < 2002;++i) {
	    star[i] = 0;
	}
	for (int i = 0 ; i < N; ++i) {
	    cin >> tmp1 >> tmp2;
	    l1[i] = tmp1;
	    l2[i] = tmp2;
	    star[tmp1]++;
	    star[tmp2]++;
	    ee[i] = tmp2*2002+tmp1;
	    stat[i] = 0;
	}
	int count = 0;
	int flag = 1;
	for (int i = 0 ; i < 2002; ++i) {
	    if (star[i]==0) continue;
	    if (count < i) {
		flag = 0;
		break;
	    }
	    else {
		count +=star[i];
	    }
	}
	if (flag==1) {
//	    sort(ee,ee+N);
	    sort(l2,l2+N);
	    answer = N;
	    count = 2*(N-1);
	    for (int i =N-1; i >=0; --i) {
		if (count < l2[i]) {
		    answer+=l2[i]-count;
		    count=l2[i];
		}
		count-=2;
	    }

	    //output
	    printf("Case #%d: %d\n",t+1, answer);
	}
	else {
	    printf("Case #%d: Too Bad\n",t+1);
	}

    }
    return 0;
}
