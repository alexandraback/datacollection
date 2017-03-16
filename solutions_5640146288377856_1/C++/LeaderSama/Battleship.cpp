#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE* f = fopen("BattleshipLarge.txt", "r");
	FILE* output = fopen("output.txt", "w");

	int testcase;
	fscanf(f, "%d", &testcase);

	for (int j = 0; j < testcase; j++){
		int rowCount, colCount, width;
		fscanf(f,"%d %d %d", &rowCount,&colCount,&width);
		int tryCount = (colCount / width) * rowCount;
		int bonus = colCount % width;
		if (bonus != 0){
			//tryCount += 1;
			tryCount += width;
		}
		else{
			tryCount += width - 1;
		}
		fprintf(output, "Case #%d: %d\n", j+1,tryCount);
	}

	fclose(f);
	fclose(output);
	return 0;

}
