T = int(raw_input())
for t in range(1, T+1):
    word, n = raw_input().split()
    n = int(n)
    cons = []
    current = 0
    for i in word:
        if (i in ['a','e','i','o','u']):
            current = 0
        else:
            current+=1
        cons.append(current)
    #print word, n
    rec = [0] * len(cons)
    for i in range(len(cons)):
        val = cons[i]
        if (val >= n):
            rec[i] = rec[i-1] + (i - n) + 1 + 1
        else:
            if (i >= 2):
                rec[i] = rec[i-1] + (rec[i-1] - rec[i-2])
            elif (i > 0):
                rec[i] = rec[i-1] + rec[i-1]
            else:
                rec[i] = 0
    print "Case #"+ str(t) +": " + str(rec[len(cons) - 1])
