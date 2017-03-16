import array

testcases = int(raw_input())
for case in xrange(1,testcases+1):
    e,r,n = raw_input().split()
    e = int(e)
    r = int(r)
    n = int(n)
    v = map(int, raw_input().split())
    f = [ [0]*(e+1) ]
    for i in xrange(0,n):
        f.append([0]*(e+1))
        for j in xrange(0,e+1):
            if (i == 0):
                bump = 0
            else:
                bump = r
            values = [(f[i][jj] + v[i]*(min(jj+bump,e)-j)) for jj in xrange(max(0,j-bump),e+1)]
            #print "  %s" % values
            f[i+1][j] = max(values)
        #print f
    print "Case #%d: %d" % (case,max(f[n]))

'''
e,r,n = raw_input().split()
v = array.array('i', map(int, raw_input().split()))
f = [array.array('i', [])]
for i in xrange(0,e+1):
    f[0].append(0)
for i in xrange(0,n):
    for j in xrange(0,e+1):
        values = []
        for jj in xrange(max(0,j-r),e+1):
            values.append(f[i][jj] + v[i]*(max(jj+r,e)-j)
        f[i+1].append(max(values))
print max(f[n])
'''
