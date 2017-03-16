import sys

kids = []

class Kid:
    def __init__(self, num):
        self.num = num
        self.bff = -1
    
    def union(self, n):
        self.bff = n

t = int(sys.stdin.readline())

for case in xrange(1, t+1):
    print 'Case #' + str(case) + ':',
    num_kids = int(sys.stdin.readline())
    
    bff = [(int(x)-1) for x in sys.stdin.readline().split()]

    ans = 0
    for i in xrange(num_kids):
        done = []
        done.append(i)
        j = bff[i]
        while True:
            if j in done:
                break
            done.append(j)
            j = bff[j]

        if bff[done[-1]] != done[-2] and bff[done[-1]] != done[0]:
            # not a valid combination
            continue

        # if possible, stick another one at the end that's looking to sit next to the one at the end now
        while bff[done[-1]] == done[-2] and bff[i] != done[-1]:
            found_one = False
            for k in xrange(num_kids):
                if k in done:
                    continue
                if bff[k] == done[-1]:
                    #print 'appending', k, 'which is looking for', bff[k]
                    done.append(k)
                    found_one = True
            if not found_one:
                break
        
        while bff[done[-1]] != done[0]:
            found_pair = False
            for k in xrange(num_kids):
                if k in done:
                    continue
                if bff[bff[k]] == k:
                    done.append(k)
                    done.append(bff[k])
                    found_pair = True
            if not found_pair:
                break

        """while bff[done[-1]] != done[0]:
            found_one = False
            for k in xrange(num_kids):
                if k in done:
                    continue
                if bff[k] == done[0]:
                    print 'PREPENDING'
                    done = [k] + done
                    found_one = True
            if not found_one:
                break""" # doesn't make sense to have this, as it'll appear on that iteration anyway

        #print i, [x+1 for x in done]
        if len(done) > ans:
            ans = len(done)
            #print 'new best', done
    #print 'ANS', ans
    print ans
