import sys

def flip(s, i):
    return [not s[i - k] for k in range(i + 1)] + s[i + 1:]

def solve(S):
    a = [True if c == '+' else False for c in S]
    count = 0
    for i in range(len(a)):
        j = len(a) - i - 1
        if (not a[j]):
            # find last instance of '-'
            if (a[0]):
                # if char that would replace it is '-' then
                # flip it and as many as you can while you're at it 
                for k in range(len(a)):
                    if (not a[k]):
                        # find first instance of '-' and flip everything before it
                        # (which would necessarily be '+')
                        a = flip(a, k - 1)
                        count += 1
                        break
            a = flip(a, j)
            count += 1
        
    return count

fin = open(len(sys.argv) > 1 and sys.argv[1] or 'test.in', 'r')

T = int(fin.readline())

for t in range(1, T + 1):
    N = fin.readline().rstrip()
    print("Case #{0}: {1}".format(t, solve(N)))

fin.close()
