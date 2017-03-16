#include <stdio.h>

int n=4;
char data[8][8];

bool cmp(char a, char b) { return a=='T' || b=='T' || a==b; }

bool ch1(int x) { return 
	cmp(data[x][0], data[x][1]) && 
	cmp(data[x][0], data[x][2]) && 
	cmp(data[x][0], data[x][3])&& 
	cmp(data[x][1], data[x][2])&& 
	cmp(data[x][1], data[x][3])&& 
	cmp(data[x][2], data[x][3]);
}

bool ch2(int y) { return 
	cmp(data[0][y], data[1][y]) && 
	cmp(data[0][y], data[2][y]) && 
	cmp(data[0][y], data[3][y]) && 
	cmp(data[1][y], data[2][y]) && 
	cmp(data[1][y], data[3][y]) && 
	cmp(data[2][y], data[3][y]);
}

bool ch3() { return 
	cmp(data[0][0], data[1][1]) && 
	cmp(data[0][0], data[2][2]) && 
	cmp(data[0][0], data[3][3]) && 
	cmp(data[1][1], data[2][2]) && 
	cmp(data[1][1], data[3][3]) && 
	cmp(data[2][2], data[3][3]);
}

bool ch4() { return 
	cmp(data[0][3], data[1][2]) && 
	cmp(data[0][3], data[2][1]) && 
	cmp(data[0][3], data[3][0]) && 
	cmp(data[1][2], data[2][1]) && 
	cmp(data[1][2], data[3][0]) && 
	cmp(data[2][1], data[3][0]);
}

int main()
{
	FILE *fp=fopen("a.in", "r");
	FILE *ofp =fopen("a.out", "w");

	int t, tt=0;
	fscanf (fp, "%d", &t);
	while (t--) {
		for (int i=0; i<n; i++)
			fscanf (fp, "%s", data[i]);

		fprintf(ofp, "Case #%d: ", ++tt);

		int ans=-1;
		int cnt=0;
		for (int i=0; i<n; i++)
			for (int j=0; j<n; j++) {
				if (data[i][j]!='.') cnt++;
				if (ch1(i) && data[i][j]!='T' && data[i][j]!='.') ans = data[i][j];
				if (ch2(j) && data[i][j]!='T' && data[i][j]!='.') ans = data[i][j];
			}
		if (ch3() && data[0][0]!='T' && data[0][0]!='.') ans=data[0][0];
		if (ch3() && data[1][1]!='T' && data[1][1]!='.') ans=data[1][1];
		if (ch4() && data[0][3]!='T' && data[0][3]!='.') ans=data[0][3];
		if (ch4() && data[1][2]!='T' && data[1][2]!='.') ans=data[1][2];

		if (ans==-1 && cnt==16)
			fprintf (ofp, "Draw\n");

		else if (ans==-1) fprintf (ofp, "Game has not completed\n");
		else fprintf (ofp, "%c won\n", ans);
	}

	return 0;
}
