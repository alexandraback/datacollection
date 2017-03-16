def flip(stack, n):
    return [not x for x in stack[n-1::-1]] + stack[n:]


def solve(stack):
    if all(stack):
        return 0
    ns = []
    if not stack[0]:
        m = 0
        for m in range(len(stack), 0, -1):
            if not stack[m-1]:
                break
        ns.append(solve(flip(stack(m))))

    m = 0
    for m in range(len(stack), 0, -1):
        if not stack[m-1]:
            break


t = int(input())
for ii in range(1, t+1):
    s = list(input())
    s = [x == "+" for x in s]

    print(s)
