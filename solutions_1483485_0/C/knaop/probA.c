#include <stdio.h>

char translate(char c) {
    switch (c) {
        case 'a': return 'y';
        case 'b': return 'h';
        case 'c': return 'e';
        case 'd': return 's';
        case 'e': return 'o';
        case 'f': return 'c';
        case 'g': return 'v';
        case 'h': return 'x';
        case 'i': return 'd';
        case 'j': return 'u';
        case 'k': return 'i';
        case 'l': return 'g';
        case 'm': return 'l';
        case 'n': return 'b';
        case 'o': return 'k';
        case 'p': return 'r';
        case 'q': return 'z';
        case 'r': return 't';
        case 's': return 'n';
        case 't': return 'w';
        case 'u': return 'j';
        case 'v': return 'p';
        case 'w': return 'f';
        case 'x': return 'm';
        case 'y': return 'a';
        case 'z': return 'q';
        default: return ' ';
    }
}


int main() {
    unsigned count;
    unsigned total;
    char c;
    scanf("%d", &total);
    count = 0;
    while (count <= total) {
        if ((c = getchar()) == '\n') {
            count += 1;
            if (count > total)
                return 0;
            if (count == 1)
                printf("Case #1: ");
            else 
                printf("\nCase #%d: ", count);
        }
        else if (c == EOF)
            return 0;
        else if (c == ' ')
            putchar(c);
        else
            putchar(translate(c));
    }
    return 0;
}

