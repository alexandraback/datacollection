import sys

args = sys.argv

if len(args) < 2:
    print 'small or large?'
    exit()

inp = args[1]

out = open(inp + '_OUT', 'w')

# No change before this

T = input()

for i in range(1, T+1):
    arr = map(int, raw_input().split())
    N = arr[0]
    S = arr[1]
    p = arr[2]
    A = arr[3:]
    
    count = 0
    for a in A:
        if a == 0:
            if p == 0:
                count += 1
            continue
        rem = a % 3
        if rem == 0:
            best = a/3
        else:
            best = a/3 + 1
#        print a, rem, best, p
        if best >= p:
            count += 1
        elif rem != 1 and S > 0 and best == p - 1:
            count += 1
            S -= 1
    res = 'Case #' + str(i) + ': ' + str(count)
    print res
    out.write(res + '\n')

# No change after this

out.close()
