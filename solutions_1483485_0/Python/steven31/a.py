import sys

dictionary = {
'a': 'y',
'b': 'h',
'c': 'e',
'd': 's',
'e': 'o',
'f': 'c',
'g': 'v',
'h': 'x',
'i': 'd',
'j': 'u',
'k': 'i',
'l': 'g',
'm': 'l',
'n': 'b',
'o': 'k',
'p': 'r',
'q': 'z',
'r': 't',
's': 'n',
't': 'w',
'u': 'j',
'v': 'p',
'w': 'f',
'x': 'm',
'y': 'a',
'z': 'q',
' ': ' '
}

def solve(line):
    res = ""
    for c in line:
        res += dictionary[c]
    return res

if __name__ == '__main__':
    fout = open("%s.out" % (sys.argv[0]), "w")
    num = int(sys.stdin.readline())
    for i in range(num):
        line = str(sys.stdin.readline()).strip()
        #print line
        res = solve(line)
        #print res
        fout.write("Case #%d: %s\n" % (i + 1, res))
    fout.close()