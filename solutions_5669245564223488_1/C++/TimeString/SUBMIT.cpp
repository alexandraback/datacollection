#include <stdio.h>
#include <string.h>

bool validint(int arr[]) {
	for (int i = 'a'; i <= 'z'; i++)
		if (arr[i] >= 2)
			return false;
	return true;
}

bool valid(char arr[]) {
	bool appear[256];
	for (int i = 'a'; i <= 'z'; i++)
		appear[i] = false;
	for (int i = 0; arr[i]; i++) {
		if (i == 0)
			appear[ (int)arr[0] ] = true;
		else {
			if (arr[i] != arr[i-1])
				if (appear[ (int)arr[i] ] == true)
					return false;
			appear[ (int)arr[i] ] = true;
		}
	}
	return true;
}

bool inside(char arr[], char a) {
	//printf("inside: %s %c\n", arr, a);
	for (int i = 0; arr[i]; i++)
		if (arr[i] == a)
			return true;
	return false;
}

int main(int argc, char *argv[]) {
	int ecase, ecount;
	int caseStart = -1, caseEnd = 9999999;
	scanf("%d", &ecase);

	if (argc > 1) {
		if (sscanf(argv[1], "%d", &caseStart) == 1) {
			if (argc > 2)
				sscanf(argv[2], "%d", &caseEnd);
		}
		if (caseEnd < caseStart)
			caseEnd = caseStart;
		if (caseEnd != 9999999 && caseEnd >= 1 && caseStart <= 0)
			caseStart = 1;
		if (caseStart > 0)
			fprintf(stderr, "....................DEBUG MODE ENABLED (FROM CASE %d to %d)\n", caseStart, caseEnd);
	}


	for (ecount = 1; ecount <= ecase; ecount++) {
		if (ecount < caseStart || ecount > caseEnd)
			continue;
	
		char input[200][200];
		int len[200];
		int en;

		scanf("%d", &en);
		for (int i = 0; i < en; i++) {
			scanf("%s", input[i]);
			len[i] = strlen(input[i]);
		} 

		bool abcba = false;
		for (int i = 0; i < en; i++)
			if (valid(input[i]) == false)
				abcba = true;
		if (abcba) {
			printf("Case #%d: 0\n", ecount);
			continue;
		}

		//printf("pass abcba\n");

		bool checked[256];
		for (int i = 0; i < 256; i++)
			checked[i] = false;

		bool midguy = false;
		for (int i = 0; i < en && midguy == false; i++) {
			int h = 0;
			int t = len[i] - 1;
			while (h < t && input[i][h] == input[i][h+1])
				h++;
			while (h < t && input[i][t] == input[i][t-1])
				t--;
			//printf("h--t = %d %d\n", h, t);
			for (int j = h + 1; j < t; j++) {
				for (int k = 0; k < en; k++) {
					if (k != i && checked[ (int)input[i][j] ] == false && inside(input[k], input[i][j]))
						midguy = true;
					checked[ (int)input[i][j] ] = true;
				}
			}
		}
		if (midguy) {
			printf("Case #%d: 0\n", ecount);
			continue;
		}

		//printf("pass midleguy\n");

		char next[1000];
		int hasin[1000], hasout[1000];
		int count[1000];
		bool singleset[1000];
		bool toremove[1000];
		for (int i = 'a'; i <= 'z'; i++) {
			next[i] = 0;
			hasin[i] = 0;
			hasout[i] = 0;
			count[i] = 0;
			toremove[i] = false;
			singleset[i] = false;
		}

		for (int i = 0; i < en; i++) {
			int aa = input[i][0];
			int bb = input[i][ len[i]-1 ];
			if (aa == bb) {
				count[aa]++;
				singleset[aa] = true;
			}
			else {
				next[aa] = bb;
				hasin[aa]++;
				hasout[bb]++;
				toremove[aa] = true;
				toremove[bb] = true;
			}
		}
		
		if ( !( validint(hasin) && validint(hasout) ) ) {
			printf("Case #%d: 0\n", ecount);
			continue;
		}
		
		//printf("pass valid int\n");
	
		int setnum = 0;
		bool error = false;
		for (int i = 'a'; i <= 'z'; i++) {
			if (hasin[i] == 1 && hasout[i] == 0) {
				setnum++;
				int t = i;
				toremove[i] = false;
				singleset[i] = false;
				while (next[t] != 0) {
					t = next[t];
					if (toremove[t] == false) {
						error = true;
						break;
					}
					toremove[t] = false;
					singleset[t] = false;
				}
			}
		}
		

		if (error) {
			printf("Case #%d: 0\n", ecount);
			continue;
		}

		//printf("pass connection\n");

		bool hastoremove = false;
		for (int i = 'a'; i <= 'z'; i++)
			if (toremove[i]) {
				hastoremove = true;
				//printf("re %c\n", i);
			}
		if (hastoremove) {
			printf("Case #%d: 0\n", ecount);
			continue;
		}
		
		//printf("pass all removed\n");

		long long ans = 1;
		for (int i = 'a'; i <= 'z'; i++) {
			while (count[i] > 0) {
				ans *= count[i];
				ans %= 1000000007;
				count[i]--;
			}
		}
		for (int i = 'a'; i <= 'z'; i++)
			if (singleset[i]) {
				setnum++;
			}
		while (setnum > 1) {
			ans *= setnum;
			ans %= 1000000007;
			setnum--;
		}
		printf("Case #%d: %lld\n", ecount, ans);

		if (caseStart > 0)
			fprintf(stderr, "....................CASE %d START\n", ecount);

		
		//printf("Case #%d: \n", ecount);
		

		if (caseStart > 0)
			fprintf(stderr, "....................CASE %d END\n", ecount);
	}

	return 0;
}
