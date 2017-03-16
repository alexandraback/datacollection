#include <cstdlib>
#include <cstdio>
#include <queue>

using namespace std;

char mult(char a,char b) {
	if (a=='1') {
		return b;
	}
	if (a=='-') {
		if (b=='1') {
			return '-';
		}
		if (b=='-') {
			return '1';
		}
		if (b=='i') {
			return 'I';
		}
		if (b=='I') {
			return 'i';
		}
		if (b=='j') {
			return 'J';
		}
		if (b=='J') {
			return 'j';
		}
		if (b=='k') {
			return 'K';
		}
		if (b=='K') {
			return 'k';
		}
	}
	if (a=='i') {
		if (b=='1') {
			return 'i';
		}
		if (b=='-') {
			return 'I';
		}
		if (b=='i') {
			return '-';
		}
		if (b=='I') {
			return '1';
		}
		if (b=='j') {
			return 'k';
		}
		if (b=='J') {
			return 'K';
		}
		if (b=='k') {
			return 'J';
		}
		if (b=='K') {
			return 'j';
		}
	}
	if (a=='I') {
		if (b=='1') {
			return 'I';
		}
		if (b=='-') {
			return 'i';
		}
		if (b=='i') {
			return '1';
		}
		if (b=='I') {
			return '-';
		}
		if (b=='j') {
			return 'K';
		}
		if (b=='J') {
			return 'k';
		}
		if (b=='k') {
			return 'j';
		}
		if (b=='K') {
			return 'J';
		}
	}
	if (a=='j') {
		if (b=='1') {
			return 'j';
		}
		if (b=='-') {
			return 'J';
		}
		if (b=='i') {
			return 'K';
		}
		if (b=='I') {
			return 'k';
		}
		if (b=='j') {
			return '-';
		}
		if (b=='J') {
			return '1';
		}
		if (b=='k') {
			return 'i';
		}
		if (b=='K') {
			return 'I';
		}
	}
	if (a=='J') {
		if (b=='1') {
			return 'J';
		}
		if (b=='-') {
			return 'j';
		}
		if (b=='i') {
			return 'k';
		}
		if (b=='I') {
			return 'K';
		}
		if (b=='j') {
			return '1';
		}
		if (b=='J') {
			return '-';
		}
		if (b=='k') {
			return 'I';
		}
		if (b=='K') {
			return 'i';
		}
	}
	if (a=='k') {
		if (b=='1') {
			return 'k';
		}
		if (b=='-') {
			return 'K';
		}
		if (b=='i') {
			return 'j';
		}
		if (b=='I') {
			return 'J';
		}
		if (b=='j') {
			return 'I';
		}
		if (b=='J') {
			return 'i';
		}
		if (b=='k') {
			return '-';
		}
		if (b=='K') {
			return '1';
		}
	}
	if (a=='K') {
		if (b=='1') {
			return 'K';
		}
		if (b=='-') {
			return 'k';
		}
		if (b=='i') {
			return 'J';
		}
		if (b=='I') {
			return 'j';
		}
		if (b=='j') {
			return 'i';
		}
		if (b=='J') {
			return 'I';
		}
		if (b=='k') {
			return '1';
		}
		if (b=='K') {
			return '-';
		}
	}
	printf("bullshit");
	return 0;
}

int main() {
	int t;
	scanf("%d",&t);
	for (int r=1;r<=t;r++) {
		int l,x;
		deque <char> signs;
		scanf("%d %d",&l,&x);
		char tmp;
		char first[10000];
		scanf("%c",&tmp);
		for (int i=0;i<l;i++) {
			scanf("%c",first+i);
		}
		if (x%4==0) {
			printf("Case #%d: NO\n",r);
			continue;
		}
		if (x>8) {
			x=x%4+8;
		}
		for (int i=0;i<x;i++) {
			for (int j=0;j<l;j++) {
				signs.push_back(first[j]);
			}
		}
		int phase=1;
		while (true) {
			char first,second;
			first=signs.front();
			signs.pop_front();
			if (signs.empty()) {
				if (phase==3&&first=='k') {
					phase++;
					first='1';
				}
				if (phase==4&&first=='1') {
					printf("Case #%d: YES\n",r);
				} else {
					printf("Case #%d: NO\n",r);
				}
				break;
			}
			if (phase==1&&first=='i') {
				//printf("Phase 2\n");
				phase++;
				continue;
			}
			if (phase==2&&first=='j') {
				//printf("Phase 3\n");
				phase++;
				continue;
			}
			if (phase==3&&first=='k') {
				//printf("Phase 4\n");
				phase++;
				continue;
			}
			second=signs.front();
			signs.pop_front();
			signs.push_front(mult(first,second));
		}
	}
	return 0;
}
