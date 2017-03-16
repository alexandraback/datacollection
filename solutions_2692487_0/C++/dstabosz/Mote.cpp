// Mote.cpp : main project file.

#include "stdafx.h"
#include <cstdio>
#include <set>
#include <cassert>

using namespace std;

using namespace System;

int debug = 0;

#define MAX_N 100

int main(array<System::String ^> ^args)
{
	int T, N, A;

	assert(scanf("%d", &T) == 1);

	for (int t = 1; t <= T; t++)
	{
		assert(scanf("%d %d", &A, &N) == 2);

        multiset<int> motes;
		int inserted = 0;

		for (int n = 0; n < N; n++)
		{
			int size;
			assert(scanf("%d", &size) == 1);
			motes.insert(size);
		}

		int n = 0;
		int remaining = N;
		bool done = false;

		for (multiset<int>::iterator iter = motes.begin();
			 iter != motes.end(); iter++)
		{
			int size = *iter;
		    int need = 0;

			if (debug)
			{
				printf("%d] size %d A %d\n", n, size, A);
			}

			if (A > size)
			{
				A += size;
//				printf("%d] Absorbed: A %d\n", n,  A);
			}
			else
			{
				while (A <= size)
				{
					need++;
					A = A + (A - 1);


//				    printf("%d] If aborb %d, A %d size %d\n", n, need, A, size);

					if (need == remaining)
					{
						break;
					}
				}

			if (need == remaining)
			{
//			  printf("Deleting remaining %d\n", remaining);
              inserted += need;
			  break;  // delete the rest
			}
			else
			{
			  inserted += need;  // insert motes
			  A += size;  // absorb
//			  printf("Adding %d, new size %d\n", need, A);
			}

			}


			n++;
		    remaining--;
		}

		printf("Case #%d: %d\n", t, inserted);
	}

    return 0;
}
