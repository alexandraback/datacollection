#include <stdio.h>
#include <stdlib.h>
#include <stack>

using namespace std;

int main(int argc, char *argv[])
{
	if(argc != 3)
		return 0;
	FILE *fp = fopen(argv[1], "r");
	FILE *ofp = fopen(argv[2], "w");

	int case_cnt;
	fscanf(fp, "%d\n", &case_cnt);

	for(int i = 1; i <= case_cnt; i++)
	{
		int class_cnt;
		fscanf(fp, "%d\n", &class_cnt);
		
//		printf("Case #%d:\n", i);

		bool to_test[class_cnt];
		bool visited[class_cnt];
		int base_cnt[class_cnt];
		int *base[class_cnt];
		for(int j = 0; j < class_cnt; j++)
		{
			to_test[j] = true;
			visited[j] = false;
			fscanf(fp, "%d", &base_cnt[j]);
			base[j] = new int[base_cnt[j]];
	//		printf("class %d:", j + 1);
			for(int k = 0; k < base_cnt[j]; k++)
			{
				fscanf(fp, "%d", &(base[j][k]));
	//			printf("%d ", base[j][k]);
			}
	//		printf("\n");
		}
	
		bool result = false;

		for(int j = 0; j < class_cnt; j++)
		{
			for(int m = 0; m < class_cnt; m++)
				visited[m] = false;

			if(to_test[j])
			{
				stack<int> stack;
				stack.push(j);
				while(!stack.empty() && !result)
				{
					int top = stack.top();
					to_test[top] = false;
			//		visited[top] = true;
					stack.pop();
					for(int k = 0; k < base_cnt[top]; k++)
					{
						if(visited[base[top][k] - 1])
						{
							result = true;
						}
						else
						{
							visited[base[top][k] - 1] = true;
							stack.push(base[top][k] - 1);
						}
					}
				}
				if(result)
				{
					break;
				}
			}
		}

		if(result)
			fprintf(ofp, "Case #%d: Yes\n", i);
		else
			fprintf(ofp, "Case #%d: No\n", i);

		for(int j = 0; j < class_cnt; j++)
			delete[] base[j];
	}

	fclose(fp);
	fclose(ofp);
	return 0;
}


