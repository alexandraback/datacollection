
def supScore(x):
    base = x/3
    if x%3 == 2:
        return (base, base, base+2)
    if x%3 == 1:
        if x==1:
            return (0, 0, 1)
        return (base-1, base+1, base+1)
    else:
        if x == 0:
            return (0, 0, 0)
        return (base-1, base, base+1)

def normScore(x):
    base = x/3
    if (x%3 == 2):
        return (base, base+1, base+1)
    if (x%3 == 1):
        return (base, base, base+1)
    else:
        return (base, base, base)

inp = '''
100
3 1 5 15 13 11
3 0 8 23 22 21
1 0 0 3
2 0 2 1 3
2 2 9 12 24
2 2 8 18 15
1 0 3 6
1 0 2 29
1 0 7 2
2 0 4 8 9
3 0 4 18 8 11
3 0 6 14 3 14
2 2 4 26 16
3 3 3 25 4 3
3 0 7 14 5 2
3 0 6 13 7 3
2 0 3 6 7
3 0 2 13 26 11
2 0 5 2 19
3 1 5 29 17 24
2 1 10 26 26
1 1 0 14
1 1 7 18
1 0 4 8
3 3 1 24 10 28
3 3 6 7 28 12
2 1 1 0 20
3 2 5 12 12 11
1 0 6 23
1 0 4 9
3 0 6 21 14 14
3 2 9 23 23 23
2 2 5 14 27
3 2 3 5 6 5
3 0 10 27 26 27
1 1 6 12
1 1 5 21
3 0 8 11 11 20
2 0 3 6 6
2 1 10 27 26
1 0 4 29
3 0 2 19 12 30
1 0 9 19
2 1 2 3 2
1 1 9 18
3 1 6 13 10 18
2 2 1 23 25
1 0 8 20
3 1 3 7 5 5
1 1 0 28
3 1 2 2 3 10
2 1 3 5 6
3 0 7 27 17 18
3 3 4 12 16 10
3 0 10 30 30 30
2 0 7 18 17
3 0 3 6 4 19
3 0 5 17 12 4
2 0 3 19 20
3 0 7 18 29 18
3 3 6 20 11 14
1 1 1 5
3 0 0 30 30 30
2 0 10 26 26
3 0 0 0 0 0
2 0 1 0 0
3 2 3 26 13 4
2 0 9 24 24
2 2 7 20 10
3 0 8 20 29 21
3 0 7 2 18 26
2 0 8 14 20
3 3 4 24 21 13
2 0 3 10 6
1 0 3 6
3 0 0 28 15 3
1 0 8 18
1 0 8 21
2 2 10 6 14
2 1 6 14 15
3 3 8 13 21 21
1 0 8 19
1 0 6 14
3 0 0 9 22 30
3 0 8 20 26 21
3 3 1 4 13 19
2 0 0 20 21
2 2 0 27 2
2 1 3 30 26
1 1 3 18
2 0 4 21 4
1 1 9 2
3 0 9 18 24 7
1 0 10 26
2 1 7 24 20
3 0 3 7 15 11
3 3 6 26 9 8
2 0 5 0 12
1 1 7 22
3 0 3 26 9 25
'''

lines = inp.strip().split('\n')

output = ''

for x in xrange(int(lines[0])):
    print 'on line', x+1
    line = lines[x+1].split()
    print line
    n = int(line[0])
    s = int(line[1])
    p = int(line[2])
    totalpoints = line[3:]
    print totalpoints
    googs = 0
    for result in totalpoints:
        print 'this p is: ', p
        print 'currently on result: ', result
        print 'with superscores left: ', s
        if max(normScore(int(result))) >= p:
            googs += 1
            print normScore(int(result))
        elif s > 0:
            print supScore(int(result))
            if max(supScore(int(result))) >= p:
                s -= 1
                googs += 1
                print supScore(int(result))

    output += 'Case #' + str(x+1) + ': ' + str(googs) + '\n'

print output
