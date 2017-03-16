#include <stdio.h>
// 1 for '1'
// 2 for 'i';
// 3 for 'j';
// 4 for 'k';

int T;
int L;
__int64 X;
char ijk[10101];
int trans[10101];
int ok = 0;
int end;

int cross(int former, int latter);

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int t;
	int it, it2;

	scanf("%d",&T);

	for(t =1; t <= T; t++ )
	{

		scanf("%d %d",&L,&X);
		scanf("%s",ijk);
		
		switch(ijk[0])
		{
		case 'i':
			trans[0]= 2;
			break;
		case 'j':
			trans[0]= 3;
			break;
		case 'k':
			trans[0] = 4;
			break;
		default:
			printf("input error");
		}

		for(it = 1; it < L; it++)
		{
			switch(ijk[it])
			{
			case 'i':
				trans[it] = 2;
				break;
			case 'j':
				trans[it] = 3;
				break;
			case 'k':
				trans[it] = 4;
				break;
			default:
				printf("input error");
			}
			trans[it] = cross(trans[it-1],trans[it]);
		}
		end = trans[L-1];
		if(end == 1)
		{
			printf("Case #%d: NO\n",t);
			continue;
		}
		else if(end == -1)
		{
			if(X%2 == 0)
			{
				printf("Case #%d: NO\n",t);
				continue;
			}
		}
		else
		{
			if(X%4 != 2)
			{				
				printf("Case #%d: NO\n",t);
				continue;
			}
		}
		X = X < 10 ? X : 10;
		
		ok = 0;
		for( it2 = 0; it2 <X; it2 ++ )
		{
			for(it = 0; it < L; it ++ )
			{
				if(ok == 0 && trans[it] == 2)
					ok = 1;
				if(ok == 1 && trans[it] == 4)
				{
					ok = 2;
					break;
				}
				trans[it] = cross(end,trans[it]);
			}
			if(ok == 2)
				break;
		}
		if(ok != 2)
		{
			printf("Case #%d: NO\n",t);
			continue;
		}
		printf("Case #%d: YES\n",t);
	}
	return 0;
}

int cross(int former, int latter)
{
	int result = former * latter < 0 ? -1 : 1;
	former = former > 0 ? former : -former;
	latter = latter > 0 ? latter : -latter;

	if(latter == 1)
		return result * former;
	
	switch(former)
	{
	case 1:
		return result * latter;
	case 2:
		switch(latter)
		{
		case 2:
			return result * -1;
		case 3:
			return result * 4;
		case 4:
			return result * -3;
		default:
			printf("error\n");
		}

	case 3:
		switch(latter)
		{
		case 2:
			return result * -4;
		case 3:
			return result * -1;
		case 4:
			return result * 2;
		default:
			printf("error\n");
		}

	case 4:
		switch(latter)
		{
		case 2:
			return result * 3;
		case 3:
			return result * -2;
		case 4:
			return result * -1;
		default:
			printf("error\n");
		}

	default:
		printf("error\n");
	}
	return 0;
}