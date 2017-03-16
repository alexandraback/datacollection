#include <stdio.h>

char STR[10001];

char getCharacter(unsigned long long position, unsigned long long length)
{
	return STR[position%length];
}
char multiplyQuaternions(char a, char b)
{
	// i,j,k,1,!(-1), I(-i), J(-j), K(-k)
	switch(a)
	{
	case '1':
		return b;
		break;
	case 'i':
		if(b=='1') return 'i';
		if(b=='i') return '!';
		if(b=='j') return 'k';
		if(b=='k') return 'J';
		if(b=='!') return 'I';
		if(b=='I') return '1';
		if(b=='J') return 'K';
		if(b=='K') return 'j';
		break;
	case 'j':
		if(b=='1') return 'j';
		if(b=='i') return 'K';
		if(b=='j') return '!';
		if(b=='k') return 'i';
		if(b=='!') return 'J';
		if(b=='I') return 'k';
		if(b=='J') return '1';
		if(b=='K') return 'I';
		break;
	case 'k':
		if(b=='1') return 'k';
		if(b=='i') return 'j';
		if(b=='j') return 'I';
		if(b=='k') return '!';
		if(b=='!') return 'K';
		if(b=='I') return 'J';
		if(b=='J') return 'i';
		if(b=='K') return '1';
		break;
	case '!':
		if(b=='1') return '!';
		if(b=='i') return 'I';
		if(b=='j') return 'J';
		if(b=='k') return 'K';
		if(b=='!') return '1';
		if(b=='I') return 'i';
		if(b=='J') return 'j';
		if(b=='K') return 'k';
		break;
	case 'I':
		if(b=='1') return 'I';
		if(b=='i') return '1';
		if(b=='j') return 'K';
		if(b=='k') return 'j';
		if(b=='!') return 'i';
		if(b=='I') return '!';
		if(b=='J') return 'k';
		if(b=='K') return 'J';
		break;
	case 'J':
		if(b=='1') return 'J';
		if(b=='i') return 'k';
		if(b=='j') return '1';
		if(b=='k') return 'I';
		if(b=='!') return 'j';
		if(b=='I') return 'K';
		if(b=='J') return '!';
		if(b=='K') return 'i';
		break;
	case 'K':
		if(b=='1') return 'K';
		if(b=='i') return 'J';
		if(b=='j') return 'i';
		if(b=='k') return '1';
		if(b=='!') return 'k';
		if(b=='I') return 'j';
		if(b=='J') return 'I';
		if(b=='K') return '!';
		break;
	}

}
int main(void)
{
	int T, test_case;

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	/*
	   If you remove the statement below, your program's output may not be rocorded
	   when your program is terminated after the time limit.
	   For safety, please use setbuf(stdout, NULL); statement.
	 */
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for(test_case = 0; test_case < T; test_case++)
	{
		
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		/////////////////////////////////////////////////////////////////////////////////////////////
		long long L,X;
		scanf("%lld %lld",&L, &X);
		scanf("%s", STR);
		bool found = false;
		
		char first;
		char second;
		char third;

		long long alreadyFailedjIdx = 10000000000000001;
		long long alreadyFailedkIdx = 10000000000000001;
		

		first = '1';
		for(long long i=0; i<(L*X-2); i++)
		{
			first = multiplyQuaternions(first,getCharacter(i,L));
			if(first != 'i') continue;

			char second = '1';
			bool jFound = false;
			for(long long j=i+1; j<(L*X-1) && j ;j++)
			{
				second = multiplyQuaternions(second,getCharacter(j,L));
				if(second !='j') continue;
				jFound = true;
				third = '1';
				for(long long k = j+1; k < (L*X) && k<alreadyFailedkIdx; k++)
				{
					third = multiplyQuaternions(third, getCharacter(k,L));
				}
				if(third =='k'){
					found = true;
					break;
				}
				else{
					alreadyFailedkIdx = j+1;
				}
			}
			if(found) break;
		}

		// Print the answer to standard output(screen).

		if(found) printf("Case #%d: %s\n", test_case+1, "YES");
		else printf("Case #%d: %s\n", test_case+1, "NO");
	}

	return 0;//Your program should return 0 on normal termination.
}


