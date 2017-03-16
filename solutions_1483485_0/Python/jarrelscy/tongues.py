trans = {}
trans['a']='y'
trans['b']='h'
trans['c']='e'
trans['d']='s'
trans['e']='o'
trans['f']='c'
trans['g']='v'
trans['h']='x'
trans['i']='d'
trans['j']='u'
trans['k']='i'
trans['l']='g'
trans['m']='l'
trans['n']='b'
trans['o']='k'
trans['p']='r'
trans['q']='z'
trans['r']='t'
trans['s']='n'
trans['t']='w'
trans['u']='j'
trans['v']='p'
trans['w']='f'
trans['x']='m'
trans['y']='a'
trans['z']='q'
trans[' ']=' '
trans['\n'] = ''
fp = open('A-small-attempt0.in', 'r')
fp2 = open('output.txt', 'w')
numCases = int(fp.readline())
print numCases
for c in range(numCases):
    inStr = fp.readline()
    outList = []
    for char in inStr:
        outList.append(trans[char])
    fp2.write("Case #"+str(c+1)+": " + "".join(outList)+"\n")

fp.close()
fp2.close()
