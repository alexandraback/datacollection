#include <iostream>
#include <cstring>
using namespace std;

const char normalToGMapping[] = {'y','n','f','i','c','w','l','b','k','u','o','m','x','s','e','v','z','p','d','r','j','g','t','h','a','q'};
const char gToNormalMapping[] = {'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};

void convertGToNormal(char* text, const unsigned int length) {
    for (unsigned int i=0;i<length;++i) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = gToNormalMapping[text[i]-'a'];
        }
    }
}

#define MAX_LINE_LENGTH 100
void mainA() {
    unsigned int T;
    char buffer[MAX_LINE_LENGTH+1];

    cin >> T;
    cin.ignore();
    for (unsigned int i=0;i<T;++i) {
        cin.getline(buffer,MAX_LINE_LENGTH+1);
        convertGToNormal(buffer,strlen(buffer));
        cout << "Case #" << (i+1) << ": " << buffer << endl;
    }
}
