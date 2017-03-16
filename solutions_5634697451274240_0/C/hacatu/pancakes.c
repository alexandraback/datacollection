#define _POSIX_C_SOURCE 201604L//enable getline

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

int main(int argc, char **argv){
	if(argc != 2){
		fprintf(stderr, "\e[1;31mERROR: Please specify an input file.\e[0m\n");
		return 1;
	}
	FILE *f = fopen(argv[1], "r");
	if(!f){
		fprintf(stderr, "\e[1;31mERROR: Could not open file.\e[0m\n");
		return 1;
	}
	char *line = NULL;
	size_t line_len = 0;
	if(getline(&line, &line_len, f) == -1){
		fprintf(stderr, "\e[1;31mERROR: Could not read file.\e[0m\n");
		free(line);
		fclose(f);
		return 1;
	}
	char *end;
	uint64_t n = strtoll(line, &end, 10);
	if(end == line){
		fprintf(stderr, "\e[1;31mERROR: Could not read number.\e[0m\n");
		free(line);
		fclose(f);
		return 1;
	}
	for(uint64_t i = 1; i <= n; ++i){
		if(getline(&line, &line_len, f) == -1){
			fprintf(stderr, "\e[1;31mERROR: Could not read file.\e[0m\n");
			free(line);
			fclose(f);
			return 1;
		}
		if(!*line){
			printf("Case #%"PRIu64": 0\n", i);
		}
		char last = *line;
		uint64_t j = 1, changes = 0;
		while(line[j] == '+' || line[j] == '-'){
			if(line[j] != last){
				++changes;
				last = line[j];
			}
			++j;
		}
		if(line[j - 1] == '-'){
			++changes;
		}
		printf("Case #%"PRIu64": %"PRIu64"\n", i, changes);
	}
	fclose(f);
}