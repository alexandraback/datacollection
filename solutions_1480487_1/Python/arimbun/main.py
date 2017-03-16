#!/usr/bin/python

f = open('A-large.in', 'r')
n = int(f.readline())

for i in range(1, n+1):
    arr = f.readline().split()
    p = int(arr[0])
    arr.remove(arr[0])
    summ = 0
    for j in arr:
        summ += int(j)

    a = 2.0 * float(summ) / float(p)
    print 'Case #' + str(i) + ':',
    fact = 0
    result = []
    for j in arr:
        prob = 100 * (float(a)-float(j))/float(summ)
        if prob < 0:
            fact -= prob
            p -= 1
            result.append(0)
    #print('%.6f' % round(prob, 6)),
        else:
            result.append(prob)
#print('%.6f' % round(prob, 6)),

    for k in result:
        #pass
        if k <= 0:
            print 0,
        else:
            print('%.6f' % round(k - (float(fact) / float(p)), 6)),
            
    print
