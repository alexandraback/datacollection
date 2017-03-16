#include <stdio.h>


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
		bool isFilled = false;

		int X,R,C;
		scanf("%d %d %d", &X,&R,&C);
		
		int boxL,boxS,xS,xL;
		if(R<C){
			boxS = R;
			boxL = C;
		}
		else
		{
			boxS = C;
			boxL = R;
		}
		
		if(X>=7){
			printf("Case #%d: %s\n", test_case+1, "RICHARD");
			continue;
		}

		//check L type
		if(X%2 == 0) //even
		{
			xS = X/2;
			xL = xS+1;
		}
		else //odd
		{
			xL = xS = X/2 + 1;
		}

		if(xS > boxS || xL > boxL)
		{
			printf("Case #%d: %s\n", test_case+1, "RICHARD");
			continue;
		}
		if((X>=4) && (xS == boxS && xL + 1 >= boxL))
		{
			printf("Case #%d: %s\n", test_case+1, "RICHARD");
			continue;
		}
		if((X>=4) && (xS + 1 >= boxS && xL + 1 == boxL))
		{
			printf("Case #%d: %s\n", test_case+1, "RICHARD");
			continue;
		}
		//check I type
		if(X > boxL){
			printf("Case #%d: %s\n", test_case+1, "RICHARD");
			continue;
		}

		//cannot remaining cells
		if( ((R*C)%X) != 0){
			printf("Case #%d: %s\n", test_case+1, "RICHARD");
			continue;
		}
		printf("Case #%d: %s\n", test_case+1, "GABRIEL");
		
	}

	return 0;//Your program should return 0 on normal termination.
}


