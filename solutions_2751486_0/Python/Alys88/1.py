"""
GCJ 2013
url
"""
import sys
vowel = {'a','e','i','o','u'}


def substrings(string):
    """
    Generator that gives all the substrings of a string
    no duplicates
    """
    yield ''
    for nb in range(1, len(string)):
        subs = set()
        for i in range(len(string) - nb + 1):
            yield(string[i:i+nb])
    yield string

def findNconsonnants(string, n):
    print(string, n)
    c = 0;
    for l in string:
        if l not in vowel:
            c += 1
            if c == n:
                return True
        else:
            c = 0
    return False


def value(name, n):
    nval = 0
    for s in substrings(name):
        if findNconsonnants(s, n):
            nval += 1
    return nval


def process(f, output):
    nb_of_cases = int(f.readline().rstrip())
    for N in range(1, nb_of_cases + 1):
        print('Case', N)

        #A = f.readline().rstrip()
        name, n = (x for x in f.readline().rstrip().split())
        n = int(n)
        #items = [int(x) for x in f.readline().rstrip().split()]

        answer = value(name, n)

        print('Answer:', answer)
        output.write('Case #{0}: {1}\n'.format(N, answer))


if __name__ == '__main__':
    if len(sys.argv) < 2:
        print("missing argument input_file")
        sys.exit(2)
    input_file = open(sys.argv[1])
    output_file = open(sys.argv[1] + '.out', 'w+')
    process(input_file, output_file)
