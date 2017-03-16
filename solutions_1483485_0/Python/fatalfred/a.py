import sys
from exceptions import EOFError
TABLE = {' ': ' ', 'a': 'y', 'c': 'e', 'b': 'h', 'e': 'o', 
    'd': 's', 'g': 'v', 'f': 'c', 'i': 'd', 'h': 'x', 'k': 'i', 'j': 'u', 
    'm': 'l', 'l': 'g', 'o': 'k', 'n': 'b', 'p': 'r', 's': 'n', 'r': 't', 
    'u': 'j', 't': 'w', 'w': 'f', 'v': 'p', 'y': 'a', 'x': 'm', 'z': 'q',
    'q': 'z'}

def googlerese(line):
    output = []
    for g in line:
        output.append(TABLE[g])
    return ''.join(output)

if __name__ == '__main__':
    for i in range(input()):
        try:
            print "Case #{0}: {1}".format(i+1, googlerese(raw_input()))
        except EOFError:
            sys.exit()
