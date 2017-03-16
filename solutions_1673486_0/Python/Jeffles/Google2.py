#4
#3 1 5 15 13 11
#3 0 8 23 22 21
#2 1 1 8 0
#6 2 8 29 20 8 18 18 21
#Case #1: 3
#Case #2: 2
#Case #3: 1
#Case #4: 3


f = open('input', 'r')
fw = open('output', 'w')
len = f.readline()
#print len.rstrip()
i=0
for x in range(int(len)):
    i+=1
    line = f.readline()
    line = line.rstrip()
    x = line.split()
    A= int(x[0])  # num of character
    B = int(x[1])  # total length
    line = f.readline()
    line = line.rstrip()
    x = line.split()
    enterAndRedo = B +2
    allBackspace = A+B+1
    best = min(allBackspace, enterAndRedo)
   # print best, allBackspace, enterAndRedo
    odds = 1
    num=0
    for j in x:
        num+=1
        j = float(j)
        odds *=j
        expected = (A-num + B -num+1 ) * odds + (A-num + B -num +B+2) * (1-odds)
        #print "What?"
        #print best, expected, i, A, B, num, odds
        if expected < best and num < A:
            best = expected

    keepGoing = ((B -A + 1) * odds) +( ((B-A)+B+2) * (1-odds) )
    if keepGoing < best:
        best = keepGoing


    #print A, B, x
    #print best
    #print 'Case #'+str(i)+': '+line
    print 'Case #'+str(i)+': '+str(best)+'\n'
    fw.write( 'Case #'+str(i)+': '+str(best)+'\n')
