#include <cstdio>

using namespace std;

const bool learning = false;
const char key[] = "yhesocvxduiglbkrztnwjpfmaq";

/* Input for learning
y qee
a zoo
ejp mysljylc kd kxveddknmc re jsicpdrysi
our language is impossible to understand
rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
there are twenty six factorial possibilities
de kr kd eoya kw aej tysr re ujdr lkgc jv
so it is okay if you want to just give up

Only q remains unattributed
*/

int main() {
	if (learning) {
		char buffer[1024], buffer2[1024];
		char key[27] = "XXXXXXXXXXXXXXXXXXXXXXXXXX";
		
		while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
			if (fgets(buffer2, sizeof(buffer), stdin) == NULL)
				break;
				
			for (int i=0; buffer[i]!=0 and buffer2[i]!=0; i++) {
				if (buffer2[i] != ' ' and buffer2[i] != '\n')
					key[buffer[i] - 'a'] = buffer2[i];
			}
		}
		printf("Key: %s\n", key);
	}
	else {
		char buffer[1024];
		char *p;
		int i = 1;
		fgets(buffer, sizeof(buffer), stdin); // number... do not need it
		while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
			for (p=buffer; *p!='\0'; p++) {
				if ('a' <= *p and *p <='z')
					*p = key[*p - 'a'];
			}
			printf("Case #%d: %s", i++, buffer);
		}
	}
	return 0;
}
