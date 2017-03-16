from math import ceil

comps = { '+': '-', '-':'+' }

def rev(s,i):
    s[:i] = s[i-1::-1]
    # print s
    for ii in xrange(i):
        s[ii] = comps[s[ii]]

    return s

def solve(s):

    a = 0
    b = len(s)

    cnt = 0
    ccc=0

    while b>a:

        while b>a:
            if s[b-1]== '-':
                break
            b-=1

        if b==a:
            # print s
            break

        # print s, a , b

        if s[0] == '-':

            i = 1
            while i<b:
                if s[i]== '+':
                    break
                i+=1
            # print 'c=-, reversing with first %s'%i
            s = rev(s,i)
            cnt+=1

        else:

            i = 1
            while i<b:
                if s[i]== '-':
                    break
                i+=1
            # print 'c=+, reversing with first %s'%i
            s = rev(s,i)
            cnt+=1
            # print s
            # print 'Then reversing all %s'%b
            s = rev(s,b)
            cnt+=1

        # ccc+=1

    assert s.count('+') == N and s.count('-') == 0 and len(s) == N
    return cnt

T = int(raw_input())

for i in range(T):
    s = [c for c in raw_input()]
    N = len(s)
    print "Case #%d: %s"%(i+1,solve(s))


# N = 0
# for i,c in  enumerate(reversed(s)):
    # if c == '+':
        # N += 2**i



# a = '++-+--+'
# s = [c for c in a]
# print s
# s = rev(s,6)
# print s

# exit(1)
