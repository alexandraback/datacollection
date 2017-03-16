#include <cstdlib>
#include <iostream>
#include <string.h>

using namespace std;

int icmp(const void* _pa, const void* _pb)
{
	int *pa = (int*)_pa;
	int *pb = (int*)_pb;

	if (pa[0] != pb[0])
	{
		return (pa[0] - pb[0]);
	}
	return (pa[1] - pb[1]);
}

int main(int argc, char *argv[])
{
	//int pair[300][2];

	int T, A, B;
	scanf("%d", &T);
	for (int cId = 1; cId <= T; cId++)
	{
		int nFound = 0;
		scanf("%d%d", &A, &B);
		for (int i = A; i <= B; i++)
		{
			char buf[20];
			int len = sprintf (buf, "%d%d", i, i) / 2;
			int test;
			int nGen = 0, gen[10];
			for (int j = 1; j < len; j++)
			{
				buf[len+len-j] = 0;
				sscanf(buf+len-j, "%d", &test);
				if (test > i && test >= A && test <= B)
				{
				   	int k;
 		 		    for (k = 0; k < nGen; k++)
 		 		    {
					 	if (gen[k] == test)
					 	   break;
					}
					if (k == nGen)
					{
                        gen[nGen++] = test;
					    nFound++;
					}
				}
			}
		}
		printf ("Case #%d: %d\n", cId, nFound);

//		if (nFound > 200)
//		{
//			qsort(pair, nFound, sizeof(int)*2, icmp);
//			for (int i = 0; i < nFound; i++)
//			{
//			 	char buf[10];
//			 	char buf2[10];
//			 	int len = sprintf (buf, "%d", pair[i][0]);
//			 	int s1 = -1, s2 = -1;
//			 	for (int j = 1; j < len; j++)
//			 	{
//				 	memcpy(buf2, buf+j, len-j);
//				 	memcpy(buf2+len-j, buf, j);
//				 	buf2[len] = 0;
//				 	int t;
//					sscanf(buf2, "%d", &t);
//					if (t == pair[i][1])
//					{
//					   	  s1 = len - j;
//					   	  break;
//                    }
//				}
//			 	len = sprintf (buf, "%d", pair[i][1]);
//			 	for (int j = 1; j < len; j++)
//			 	{
//				 	memcpy(buf2, buf+j, len-j);
//				 	memcpy(buf2+len-j, buf, j);
//				 	buf2[len] = 0;
//				 	int t;
//					sscanf(buf2, "%d", &t);
//					if (t == pair[i][0])
//					{
//					   	  s2 = len - j;
//					   	  break;
//                    }
//				}
//
//			 	printf ("%d %d %d %d\n", pair[i][0], pair[i][1], s1, s2);
//			}
//		}
	}

    //system("PAUSE");
    return EXIT_SUCCESS;
}
