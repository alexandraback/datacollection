#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main() {
	int ca;
	char g;

	freopen( "in.txt", "r", stdin );
	freopen( "out.txt", "w", stdout );
	scanf("%d\n", &ca);
	for (int ci = 1; ci <= ca; ++ci) {
		printf("Case #%d: ", ci);
		do{
			scanf("%c",&g);
			switch(g){
				case 'a':printf("%c",'y');break;
				case 'b':printf("%c",'h');break;
				case 'c':printf("%c",'e');break;
				case 'd':printf("%c",'s');break;
				case 'e':printf("%c",'o');break;
				case 'f':printf("%c",'c');break;
				case 'g':printf("%c",'v');break;
				case 'h':printf("%c",'x');break;
				case 'i':printf("%c",'d');break;
				case 'j':printf("%c",'u');break;
				case 'k':printf("%c",'i');break;
				case 'l':printf("%c",'g');break;
				case 'm':printf("%c",'l');break;
				case 'n':printf("%c",'b');break;
				case 'o':printf("%c",'k');break;
				case 'p':printf("%c",'r');break;
				case 'q':printf("%c",'z');break;
				case 'r':printf("%c",'t');break;
				case 's':printf("%c",'n');break;
				case 't':printf("%c",'w');break;
				case 'u':printf("%c",'j');break;
				case 'v':printf("%c",'p');break;
				case 'w':printf("%c",'f');break;
				case 'x':printf("%c",'m');break;
				case 'y':printf("%c",'a');break;
				case 'z':printf("%c",'q');break;
				case ' ':printf("%c",' ');break;
				default:break;
			}
		}while(g !='\n');
		printf("%c",'\n');
	}
	return 0;
}