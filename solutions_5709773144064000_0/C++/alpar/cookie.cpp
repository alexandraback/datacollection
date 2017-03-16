#include <stdio.h>
#include <iostream>

using namespace std;

FILE *inputFile, *outputFile;
int t;
double c, f, x;
double speed;

int main(int argc,char *argv[])
{
	inputFile = fopen(argv[1], "r");
	outputFile = fopen(argv[2], "w");

	fscanf(inputFile, "%d", &t);

	double lastTime, currentTime, timeLapsed = 0;
	for (int i = 0; i < t; i++)
	{
		fscanf(inputFile, "%lf %lf %lf", &c, &f, &x);

		speed = 2;
		currentTime = x / speed;
		lastTime = 1000000;
		timeLapsed = 0;
		while (currentTime < lastTime)
		{
			// counter++;
			lastTime = currentTime;

			timeLapsed += c / speed;
			speed += f;
			currentTime = timeLapsed + x / speed;
		}

		fprintf(outputFile, "Case #%d: %lf\n", i+1, lastTime);
	}

	fclose(inputFile);
	fclose(outputFile);
}