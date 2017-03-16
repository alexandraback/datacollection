def solve():
    n = len(a)

    perfect = False
    for ii in xrange(n):
        if not (a[ii] == '?' or b[ii] == '?' or  a[ii] == b[ii]):
            perfect = True
            break

    if perfect is False:
        for ii in xrange(n):
            if a[ii] == '?' and b[ii] == '?':
                a[ii] = 0
                b[ii] = 0
                continue
            if a[ii] == '?':
                a[ii] = b[ii] 
            elif b[ii] == '?':
                b[ii] = a[ii] 
        return a, b

    ii = 0
    fnd = False
    for ii in xrange(n):
        # print ii
        if not fnd:
            if a[ii] == b[ii]:
                if a[ii] == '?':
                    a[ii] = '0'
                    b[ii] = '0'
                continue

            if not (a[ii] == '?' or b[ii] == '?' ):
                fnd = True
                if int(a[ii]) > int(b[ii]):
                    gr = 'a'
                else:
                    gr = 'b'
                # print '%s continuing %s %s' %(ii,a[ii],b[ii])
                continue

            if a[ii] == '?':
                a[ii] = b[ii]
            else:
                assert b[ii] == '?'
                b[ii] = a[ii]

        else:

            if gr == 'a':
                if a[ii] == '?':
                    a[ii] = 0
                if b[ii] == '?':
                    b[ii] = 9
            else:
                assert gr == 'b'
                if a[ii] == '?':
                    a[ii] = 9
                if b[ii] == '?':
                    b[ii] = 0

        # ii+=1

    return a,b

T = int(raw_input())

for i in range(T):
  # N = int(raw_input())
  # s = raw_input()
  a, b = raw_input().split()
  a = [c for c in a]
  b = [c for c in b]
  # print a, b
  a,b = solve()
  a = ''.join(map(str,a))
  b = ''.join(map(str,b))
  print "Case #%d: %s %s"%(i+1,a,b)
  # print
