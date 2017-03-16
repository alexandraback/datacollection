def minify(stack):
    result = [stack[0]]
    for s in stack:
        if s != result[-1]:
            result.append(s)
    return result

t = int(input())
for ii in range(1, t+1):
    s = input()
    s = minify(s)
    n = len(s)
    if s[-1] == "+":
        n -= 1
    print("Case #{}:".format(ii), n)
