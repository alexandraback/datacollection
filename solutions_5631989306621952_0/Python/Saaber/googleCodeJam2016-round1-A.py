fin = open('inputFile.in', 'r')
fout = open('outputFile.out', 'w')
T = int(fin.readline().strip())

def FUN(s):
    word = s[0]
    for i in xrange(1, len(s)):
        if s[i] >= word[0]:
            word = s[i] + word
        else:
            word = word +s[i]
    return word

for t in xrange(T):
    line = fin.readline().strip()
    #args = [int(arg) for arg in line.split() if arg != '' and arg != '\n']
    res = FUN(line)
    fout.write('Case #'+str(t+1)+': '+res+'\n')


fin.close()
fout.close()
