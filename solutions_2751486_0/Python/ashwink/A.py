import sys

f = open(sys.argv[1], 'r')
T = int(f.readline())
for case in range(0, T):
    line = f.readline().split()
    L = str(line[0])
    n = int(line[1])
    
    count = 0
    for i in range(0, len(L)):
        for j in range(i + 1, len(L) + 1):
            consonants = 0
            for k in range(i, j):
                if L[k] not in ['a', 'e', 'i', 'o', 'u']:
                    consonants += 1
                    if consonants >= n:
                        count += 1
                        break
                else:
                    consonants = 0

    print "Case #%d: %d" % (case + 1, count)
    sys.stdout.flush()
