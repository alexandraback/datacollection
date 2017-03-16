#include <stdio.h>
#define MAX 1000100
int main()
{
	
	FILE *in;
	FILE *out;
	in = fopen("A.in", "r");
	out = fopen("A.out", "w");


	int T;
	fscanf(in, "%d", &T);
	for(int z = 0; z<T; z++)
	{
		char word[MAX];
		int n;
		fscanf(in, "%s %d", word, &n);

		int size = 0;
		while(word[size] != '\0')
		{
			size++;
		}
		printf("%d\n", size);	
		long int begin = 0;
		long int end = 0;
		long int cons = (word[0] != 'a' && word[0] != 'e' && word[0] != 'i' && word[0] != 'o' && word[0] != 'u');
		long long int total = 0;
		bool begincounts = true;
		while (end < size)
		{
			//printf("%d %d %d %lld\n",begin, end, cons, total );
			while (end < size && cons < n)
			{
				end++;
				if( end < size && (word[end] != 'a' && word[end] != 'e' && word[end] != 'i' && word[end] != 'o' && word[end] != 'u'))
					cons++;
				else{
					cons = 0;
					begincounts = false;
				}
			}
			if (end <size)
				total+=(size-end);
			if(begincounts && (word[begin] != 'a' && word[begin] != 'e' && word[begin] != 'i' && word[begin] != 'o' && word[begin] != 'u') )
				cons--;
			begin++;
			if( end - begin < n)
				begincounts = true;
			
		}

		fprintf(out, "Case #%d: %lld\n", z+1, total);


	}

	return 0;
}