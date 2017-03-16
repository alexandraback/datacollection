import sys

stdin = sys.stdin.readlines()
cases = int(stdin.pop(0))
for i in xrange(cases):
    name = stdin.pop(0).split(' ')
    n = int(name.pop())
    name = name.pop()
    vowels = ['a', 'i', 'o', 'u', 'e']
    runs = []
    c = 0
    for j in xrange(len(name)-n+1):
        k = True
        for l in name[j:j+n]:
            if l in vowels:
                k = False
                break
        if k:
            runs.append(name[j:j+n])
    for j in xrange(len(name)):
        for run in runs:
            if run in name[j:]:
                c += 1
                break
        for k in xrange(1,len(name)):
            k = 0-k
            for run in runs:
                if run in name[j:k]:
                    c += 1
                    break
    print "Case #"+str(i+1)+": "+str(c)
