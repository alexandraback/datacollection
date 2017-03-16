f = open('A-small-attempt1.in', 'r')
o = open('A-small-attempt1.out', 'w')

T = int(f.readline().strip())

vowels=['a','e','i','o','u']

for t in range(T):
    (givenString, n) = map(str, f.readline().strip().split(' '))
    n = int(n)
    stringL = list(givenString)
    critialIndex = []
    score = [0 for i in range(len(givenString))]
    for i in range (len(score)):
        if (stringL[i] not in vowels):
            score[i]= score[i-1]+1;
            if (score[i] >= n): critialIndex.append(i)
        else:
            score[i] =0
    minIndex = 0
    maxIndex = len(score)
    res = 0
    prevI = 0
    for i in critialIndex:
        left = i+1 - n - prevI
        right = len(givenString) - i -1
        res += (left + 1)*(right + 1)
        prevI = i+2-n
        #print(left,right)
    s = "Case #%d: %s\n" % (t+1, res)
    o.write(s)
    print(s)
o.close()