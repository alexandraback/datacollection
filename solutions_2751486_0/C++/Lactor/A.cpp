#include <stdio.h>
#define MAX 1000009
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

		int begin = 0;
		int end = 0;
		int cons = (word[0] != 'a' && word[0] != 'e' && word[0] != 'i' && word[0] != 'o' && word[0] != 'u');
		int total = 0;
		bool begincounts = true;
		while (end < size)
		{
			//printf("%d %d %d %d\n",begin, end, cons, total );
			while (cons < n)
			{
				end++;
				if( word[end] != 'a' && word[end] != 'e' && word[end] != 'i' && word[end] != 'o' && word[end] != 'u')
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

		fprintf(out, "Case #%d: %d\n", z+1, total);


	}

	return 0;
}