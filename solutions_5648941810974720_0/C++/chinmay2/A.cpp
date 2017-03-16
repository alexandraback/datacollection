#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;

#define MOD 1000000007

#define scan(x) scanf("%d", &x)
#define scan2(x, y) scanf("%d %d", &x, &y)
#define print(x) printf("%d\n", x)

#define scan_lli(x) scanf("%lld", &x)
#define print_lli(x) printf("%lld\n", x)

#define scanc(x) scanf("%c", &x)
#define printc(x) printf("%c", x)

#define scans(x) scanf("%s", x)
#define prints(x) fscanf(out, "%s\n", x)

#define for_up(v, s, e) for (int v=s; v<e; v++)
#define for_down(v, s, e) for (int v=s; v>=e; v--)

#define vi vector<int>
#define pii pair<int, int>
#define vpii vector< pair<int, int> >

#define pb push_back
#define mp make_pair

#define fs first
#define sc second

int in (char c) {
	return c - 'A';
}

int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
	
	//freopen("A-large.in", "r", stdin);
    //freopen("A-large.out", "w", stdout);
	
    int T;
    scan(T);

    for_up (t, 1, T+1) {
		string s;
		cin >> s;
		
		int alpha[26];
		memset(alpha, 0, sizeof(alpha));
		
		int l = s.length();
		for_up (i, 0, l) {
			alpha[s[i]-'A']++;
		}
		
		int n[10];
		memset(n, 0, sizeof(n));
		
		n[0] = alpha[in('Z')];
		alpha[in('O')] -= n[0];
		
		n[2] = alpha[in('W')];
		alpha[in('T')] -= n[2];
		alpha[in('O')] -= n[2];
		
		n[4] = alpha[in('U')];
		alpha[in('F')] -= n[4];
		alpha[in('O')] -= n[4];
		
		n[6] = alpha[in('X')];
		alpha[in('S')] -= n[6];
		alpha[in('I')] -= n[6];
		
		n[8] = alpha[in('G')];
		alpha[in('T')] -= n[8];
		alpha[in('I')] -= n[8];
		
		n[1] = alpha[in('O')];
		
		n[5] = alpha[in('F')];
		alpha[in('I')] -= n[5];
		
		n[3] = alpha[in('T')];
		
		n[7] = alpha[in('S')];
		
		n[9] = alpha[in('I')];
		
		printf("Case #%d: ", t);
		for_up (i, 0, 10) {
			for_up (j, 0, n[i]) {
				printf("%d", i);
			}
		}
		printf("\n");
	}
	
	//fclose(stdin);
	//fclose(stdout);

	return 0;
}

