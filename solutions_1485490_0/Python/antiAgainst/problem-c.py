#!/usr/bin/python2

def dp(box, toy, n, m):
    f = {}
    for i in range(n + 1):
        f[(i, 0)] = 0
    for i in range(m + 1):
        f[(0, i)] = 0

    for i in range(1, n + 1):
        for j in range(1, m + 1):
            maxim = f[(i-1, j)]
            if f[(i, j-1)] > maxim:
                maxim = f[(i, j-1)]
            if box[i-1][0] == toy[j-1][0]:
                for p in range(i, 0, -1):
                    for q in range(j, 0, -1):
                        sum1 = 0
                        for iter in range(p, i+1):
                            if box[iter-1][0] == box[i-1][0]:
                                sum1 += box[iter-1][1]
                        sum2 = 0
                        for iter in range(q, j+1):
                            if toy[iter-1][0] == toy[j-1][0]:
                                sum2 += toy[iter-1][1]
                        minlen = min(sum1, sum2)
                        if f[(p-1, q-1)] + minlen > maxim:
                            maxim = f[(p-1, q-1)] + minlen
            f[(i, j)] = maxim
    return f[(n, m)]

if __name__ == "__main__":

    f = open('C-small-attempt0.in')
    tc = int(f.readline().strip())

    for t in range(tc):
        print "Case #%d:" % (t + 1),

        n, m = f.readline().split()
        n = int(n)
        m = int(m)

        box = []
        temp = f.readline().split()
        for i in range(n):
            box.append((int(temp[2*i+1]), int(temp[2*i])))
        toy = []
        temp = f.readline().split()
        for i in range(m):
            toy.append((int(temp[2*i+1]), int(temp[2*i])))
        
        print dp(box, toy, n, m)
