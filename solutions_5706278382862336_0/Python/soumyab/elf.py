def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)

def power_of_two(Q):
    power = 0
    raised = 1

    while power <= 40:
        if raised == Q:
            return True
        power += 1
        raised = 2**power

    return False

def generation(P, Q):
    if P >= Q:
        return 0
    else:
        return 1 + generation(2*P, Q)

T = int(input())

format_string = "Case #{0}: {1}"

for i in range(T):
    PQ = input().split('/')
    P = int(PQ[0])
    Q = int(PQ[1])

    divisor = gcd(P, Q)

    P = P // divisor
    Q = Q // divisor

    if (power_of_two(Q)):
        ans = generation(P, Q)
    else:
        ans = "impossible"

    print(format_string.format(i+1, ans))
