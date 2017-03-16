#include<iostream>
#include<cstdio>

using namespace std;

int main(int artc, char* argv[]) {
char chars[26];

chars['y'-'a']='a';
chars['n'-'a']='b';
chars['f'-'a']='c';
chars['i'-'a']='d';
chars['c'-'a']='e';
chars['w'-'a']='f';
chars['l'-'a']='g';
chars['b'-'a']='h';
chars['k'-'a']='i';
chars['u'-'a']='j';
chars['o'-'a']='k';
chars['m'-'a']='l';
chars['x'-'a']='m';
chars['s'-'a']='n';
chars['e'-'a']='o';
chars['v'-'a']='p';
chars['z'-'a']='q';
chars['p'-'a']='r';
chars['d'-'a']='s';
chars['r'-'a']='t';
chars['j'-'a']='u';
chars['g'-'a']='v';
chars['t'-'a']='w';
chars['h'-'a']='x';
chars['a'-'a']='y';
chars['q'-'a']='z';

    int TIME;// number of test
    int answer;// Final answer
    cin >> TIME;
    char input;
	    scanf("%c",&input);
    for (int t = 0 ; t < TIME; t++) {
	answer = 0;
	//output
	printf("Case #%d: ",t+1);
	while (1) {
	    scanf("%c",&input);
	    if (input < 'a' || input > 'z') {
		printf("%c",input);
	    }
	    else {
		printf("%c",chars[input-'a']);
	    }
	    if (input =='\n')
		break;
	}
    }
    return 0;
}
