# Header
import sys

# Binary representation
def br(n):
    t = ""
    if n > 0:
        t = br(n/2)
        if n&1 > 0:
            t = t + "1"
        else:
            t = t + "0"
    return t

# Test case
tc = input()
for cs in range(1, tc+1):
    print "Case #" + str(cs) + ":"

    # N and J
    N, J = raw_input().split()
    N = int(N)
    J = int(J)

    # Brute force
    cnt = 0
    for i in range(0, 1000):
        bit = (1<<(N-1)) + (i<<1) + 1;
        base = 2
        ans = []
        while base < 11:
            tmp = bit
            val = 0
            mul = 1
            while tmp > 0:
                if tmp&1 > 0:
                    val += mul
                mul *= base
                tmp >>= 1
            div = 2
            while div * div <= val:
                if val%div == 0:
                    break
                if div == 500000:
                    break
                div += 1
            if div * div > val:
                break
            if div == 500000:
                break
            ans.append(div)
            base += 1
        if base == 11:
            sys.stdout.write(br(bit))
            for x in ans:
                sys.stdout.write(' ')
                sys.stdout.write(str(x))
            sys.stdout.write('\n')
            cnt += 1
        if cnt == J:
            break
